#include "F4SE/API.h"

#include "F4SE/Interfaces.h"
#include "REL/FHookStore.h"
#include "REL/Trampoline.h"
#include "REX/TSingleton.h"
#include "REX/W32/OLE32.h"
#include "REX/W32/SHELL32.h"

#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/msvc_sink.h>
#include <spdlog/sinks/rotating_file_sink.h>
#include <spdlog/spdlog.h>

namespace F4SE
{
	namespace Impl
	{
		struct API :
			public REX::TSingleton<API>
		{
			void Init(InitInfo, const F4SE::QueryInterface* a_intfc);
			void InitLog();
			void InitTrampoline();
			void InitHook(REL::EHookStep a_step);

			InitInfo info;

			std::string  pluginName{};
			std::string  pluginAuthor{};
			REL::Version pluginVersion{};

			REL::Version                            f4seVersion{};
			PluginHandle                            pluginHandle{ static_cast<PluginHandle>(-1) };
			std::uint32_t                           releaseIndex{ 0 };
			std::function<const void*(const char*)> pluginInfoAccessor;
			std::string_view                        saveFolderName{};

			MessagingInterface*     messagingInterface{ nullptr };
			ScaleformInterface*     scaleformInterface{ nullptr };
			PapyrusInterface*       papyrusInterface{ nullptr };
			SerializationInterface* serializationInterface{ nullptr };
			TaskInterface*          taskInterface{ nullptr };
			ObjectInterface*        objectInterface{ nullptr };
			TrampolineInterface*    trampolineInterface{ nullptr };
		};

		void API::Init(InitInfo a_info, const F4SE::QueryInterface* a_intfc)
		{
			info = a_info;

			static std::once_flag once;
			std::call_once(once, [&]() {
				if (const auto data = PluginVersionData::GetSingleton()) {
					pluginName = data->GetPluginName();
					pluginAuthor = data->GetAuthorName();
					pluginVersion = data->GetPluginVersion();
				} else {
					std::vector<char> buf(REX::W32::MAX_PATH, '\0');
					const auto        size = REX::W32::GetModuleFileNameA(REX::W32::GetCurrentModule(), buf.data(), REX::W32::MAX_PATH);
					if (size) {
						std::filesystem::path p(buf.begin(), buf.begin() + size);
						pluginName = p.stem().string();
					}
				}

				f4seVersion = a_intfc->F4SEVersion();
				pluginHandle = a_intfc->GetPluginHandle();
				releaseIndex = a_intfc->GetReleaseIndex();
				pluginInfoAccessor = reinterpret_cast<const Impl::F4SEInterface*>(a_intfc)->GetPluginInfo;
				// GetSaveFolderName added in F4SE 0.7.1 (NG). OG F4SE 0.6.x doesn't have it.
				if (f4seVersion >= REL::Version{ 0, 7, 1, 0 }) {
					saveFolderName = a_intfc->GetSaveFolderName();
				}
			});
		}

		void API::InitLog()
		{
			if (info.log) {
				static std::once_flag once;
				std::call_once(once, [&]() {
					if (saveFolderName.empty())
						saveFolderName = "Fallout4";

					wchar_t*                                                       knownBuffer{ nullptr };
					const auto                                                     knownResult = REX::W32::SHGetKnownFolderPath(REX::W32::FOLDERID_Documents, REX::W32::KF_FLAG_DEFAULT, nullptr, std::addressof(knownBuffer));
					std::unique_ptr<wchar_t[], decltype(&REX::W32::CoTaskMemFree)> knownPath(knownBuffer, REX::W32::CoTaskMemFree);
					if (!knownPath || knownResult != 0) {
						REX::ERROR("failed to get known folder path");
						return;
					}

					std::filesystem::path path = knownPath.get();
					path /= std::format("My Games/{}/F4SE/{}.log", GetSaveFolderName(), info.logName ? info.logName : GetPluginName());

					std::vector<spdlog::sink_ptr> sinks{
						std::make_shared<spdlog::sinks::msvc_sink_mt>()
					};

					if (info.logRotate > 0) {
						constexpr auto maxSize = std::numeric_limits<std::size_t>::max();
						sinks.push_back(std::make_shared<spdlog::sinks::rotating_file_sink_mt>(path.string(), maxSize, info.logRotate, true));
					} else {
						sinks.push_back(std::make_shared<spdlog::sinks::basic_file_sink_mt>(path.string(), true));
					}

					auto logger = std::make_shared<spdlog::logger>("global", sinks.begin(), sinks.end());
					logger->set_level(static_cast<spdlog::level::level_enum>(info.logLevel));
					logger->flush_on(static_cast<spdlog::level::level_enum>(info.logLevel));

					spdlog::set_default_logger(std::move(logger));
					spdlog::set_pattern(info.logPattern ? info.logPattern : "[%T.%e] [%=5t] [%L] %v");

					REX::INFO("{} v{}", GetPluginName(), GetPluginVersion());
				});
			}
		}

		void API::InitTrampoline()
		{
			if (info.trampoline) {
				static std::once_flag once;
				std::call_once(once, [&]() {
					if (!info.trampolineSize) {
						const auto hookStore = REL::FHookStore::GetSingleton();
						info.trampolineSize += hookStore->GetSizeTrampoline();
					}

					auto& trampoline = REL::GetTrampoline();
					if (const auto intfc = GetTrampolineInterface()) {
						if (const auto mem = intfc->AllocateFromBranchPool(info.trampolineSize))
							trampoline.set_trampoline(mem, info.trampolineSize);
						else
							trampoline.create(info.trampolineSize);
					}
				});
			}
		}

		void API::InitHook(REL::EHookStep a_step)
		{
			if (info.hook) {
				const auto hookStore = REL::FHookStore::GetSingleton();
				hookStore->Init();
				hookStore->Enable(a_step);
			}
		}
	}

	void Init(const PreLoadInterface* a_intfc, InitInfo a_info) noexcept
	{
		static std::once_flag once;
		std::call_once(once, [&]() {
			auto api = Impl::API::GetSingleton();
			api->Init(a_info, a_intfc);
			api->InitLog();

			api->trampolineInterface = a_intfc->QueryInterface<TrampolineInterface>(PreLoadInterface::kTrampoline);

			api->InitTrampoline();
			api->InitHook(REL::EHookStep::PreLoad);
		});
	}

	void Init(const LoadInterface* a_intfc, InitInfo a_info) noexcept
	{
		static std::once_flag once;
		std::call_once(once, [&]() {
			auto api = Impl::API::GetSingleton();
			api->Init(a_info, a_intfc);
			api->InitLog();

			api->messagingInterface = a_intfc->QueryInterface<MessagingInterface>(LoadInterface::kMessaging);
			api->scaleformInterface = a_intfc->QueryInterface<ScaleformInterface>(LoadInterface::kScaleform);
			api->papyrusInterface = a_intfc->QueryInterface<PapyrusInterface>(LoadInterface::kPapyrus);
			api->serializationInterface = a_intfc->QueryInterface<SerializationInterface>(LoadInterface::kSerialization);
			api->taskInterface = a_intfc->QueryInterface<TaskInterface>(LoadInterface::kTask);
			api->objectInterface = a_intfc->QueryInterface<ObjectInterface>(LoadInterface::kObject);
			api->trampolineInterface = a_intfc->QueryInterface<TrampolineInterface>(LoadInterface::kTrampoline);

			api->InitTrampoline();
			api->InitHook(REL::EHookStep::Load);
		});
	}

	REL::Version GetF4SEVersion() noexcept
	{
		return Impl::API::GetSingleton()->f4seVersion;
	}

	std::string_view GetPluginName() noexcept
	{
		return Impl::API::GetSingleton()->pluginName;
	}

	std::string_view GetPluginAuthor() noexcept
	{
		return Impl::API::GetSingleton()->pluginAuthor;
	}

	REL::Version GetPluginVersion() noexcept
	{
		return Impl::API::GetSingleton()->pluginVersion;
	}

	PluginHandle GetPluginHandle() noexcept
	{
		return Impl::API::GetSingleton()->pluginHandle;
	}

	const PluginInfo* GetPluginInfo(std::string_view a_plugin) noexcept
	{
		if (const auto& accessor = Impl::API::GetSingleton()->pluginInfoAccessor) {
			if (const auto result = accessor(a_plugin.data())) {
				return static_cast<const PluginInfo*>(result);
			}
		}

		REX::ERROR("failed to get plugin info for {}", a_plugin);

		return nullptr;
	}

	std::uint32_t GetReleaseIndex() noexcept
	{
		return Impl::API::GetSingleton()->releaseIndex;
	}

	std::string_view GetSaveFolderName() noexcept
	{
		return Impl::API::GetSingleton()->saveFolderName;
	}

	const MessagingInterface* GetMessagingInterface() noexcept
	{
		return Impl::API::GetSingleton()->messagingInterface;
	}

	const ScaleformInterface* GetScaleformInterface() noexcept
	{
		return Impl::API::GetSingleton()->scaleformInterface;
	}

	const PapyrusInterface* GetPapyrusInterface() noexcept
	{
		return Impl::API::GetSingleton()->papyrusInterface;
	}

	const SerializationInterface* GetSerializationInterface() noexcept
	{
		return Impl::API::GetSingleton()->serializationInterface;
	}

	const TaskInterface* GetTaskInterface() noexcept
	{
		return Impl::API::GetSingleton()->taskInterface;
	}

	const ObjectInterface* GetObjectInterface() noexcept
	{
		return Impl::API::GetSingleton()->objectInterface;
	}

	const TrampolineInterface* GetTrampolineInterface() noexcept
	{
		return Impl::API::GetSingleton()->trampolineInterface;
	}
}

namespace F4SE
{
	void Init(const LoadInterface* a_intfc, const bool a_log) noexcept
	{
		Init(a_intfc, { .log = a_log });
	}

	void AllocTrampoline(std::size_t a_size) noexcept
	{
		auto api = Impl::API::GetSingleton();
		api->info.trampoline = true;
		api->info.trampolineSize = a_size;
		api->InitTrampoline();
	}
}
