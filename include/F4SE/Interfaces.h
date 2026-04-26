#pragma once

#include "REL/Relocation.h"

#define F4SEAPI __cdecl

namespace RE
{
	namespace BSScript
	{
		class IVirtualMachine;
	}
}

namespace Scaleform
{
	namespace GFx
	{
		class Movie;
		class Value;
	}
}

namespace F4SE
{
	using PluginHandle = std::uint32_t;

	class DelayFunctorManager;
	class ObjectRegistry;
	class PersistentObjectStorage;

	namespace Impl
	{
		struct F4SEInterface
		{
			std::uint32_t f4seVersion;
			std::uint32_t runtimeVersion;
			std::uint32_t editorVersion;
			std::uint32_t isEditor;
			void*(F4SEAPI* QueryInterface)(std::uint32_t);
			std::uint32_t(F4SEAPI* GetPluginHandle)(void);
			std::uint32_t(F4SEAPI* GetReleaseIndex)(void);
			const void*(F4SEAPI* GetPluginInfo)(const char*);  // 0.6.22+
			const char*(F4SEAPI* GetSaveFolderName)(void);     // 0.7.1+
		};

		struct F4SEMessagingInterface
		{
			std::uint32_t interfaceVersion;
			bool(F4SEAPI* RegisterListener)(std::uint32_t, const char*, void*);
			bool(F4SEAPI* Dispatch)(std::uint32_t, std::uint32_t, void*, std::uint32_t, const char*);
			void*(F4SEAPI* GetEventDispatcher)(std::uint32_t);
		};

		struct F4SEScaleformInterface
		{
			std::uint32_t interfaceVersion;
			bool(F4SEAPI* Register)(const char*, void*);
		};

		struct F4SESerializationInterface
		{
			std::uint32_t version;
			void(F4SEAPI* SetUniqueID)(std::uint32_t, std::uint32_t);
			void(F4SEAPI* SetRevertCallback)(std::uint32_t, void*);
			void(F4SEAPI* SetSaveCallback)(std::uint32_t, void*);
			void(F4SEAPI* SetLoadCallback)(std::uint32_t, void*);
			void(F4SEAPI* SetFormDeleteCallback)(std::uint32_t, void*);
			bool(F4SEAPI* WriteRecord)(std::uint32_t, std::uint32_t, const void*, std::uint32_t);
			bool(F4SEAPI* OpenRecord)(std::uint32_t, std::uint32_t);
			bool(F4SEAPI* WriteRecordData)(const void*, std::uint32_t);
			bool(F4SEAPI* GetNextRecordInfo)(std::uint32_t*, std::uint32_t*, std::uint32_t*);
			std::uint32_t(F4SEAPI* ReadRecordData)(void*, std::uint32_t);
			bool(F4SEAPI* ResolveHandle)(std::uint64_t, std::uint64_t*);
			bool(F4SEAPI* ResolveFormID)(std::uint32_t, std::uint32_t*);
		};

		struct F4SEPapyrusInterface
		{
			std::uint32_t interfaceVersion;
			bool(F4SEAPI* Register)(void*);
			void(F4SEAPI* GetExternalEventRegistrations)(const char*, void*, void*);
		};

		struct F4SETaskInterface
		{
			std::uint32_t interfaceVersion;
			void(F4SEAPI* AddTask)(void*);
			void(F4SEAPI* AddUITask)(void*);
			void(F4SEAPI* AddTaskPermanent)(void*);
		};

		struct F4SEObjectInterface
		{
			std::uint32_t interfaceVersion;
			DelayFunctorManager&(F4SEAPI* GetDelayFunctorManager)(void);
			ObjectRegistry&(F4SEAPI* GetObjectRegistry)(void);
			PersistentObjectStorage&(F4SEAPI* GetPersistentObjectStorage)(void);
		};

		struct F4SETrampolineInterface
		{
			std::uint32_t interfaceVersion;
			void*(F4SEAPI* AllocateFromBranchPool)(std::uint32_t, std::size_t);
			void*(F4SEAPI* AllocateFromLocalPool)(std::uint32_t, std::size_t);
		};
	}

	class QueryInterface
	{
	protected:
		[[nodiscard]] decltype(auto) GetProxy() const noexcept
		{
			return reinterpret_cast<const Impl::F4SEInterface&>(*this);
		}

	private:
		[[nodiscard]] constexpr static REL::Version MakeVersion(std::uint32_t a_version) noexcept
		{
			return {
				static_cast<std::uint16_t>((a_version >> 8 * 3) & 0x0FF),
				static_cast<std::uint16_t>((a_version >> 8 * 2) & 0x0FF),
				static_cast<std::uint16_t>((a_version >> 8 / 2) & 0xFFF),
				static_cast<std::uint16_t>((a_version >> 8 * 0) & 0x00F)
			};
		}

	public:
		[[nodiscard]] REL::Version     EditorVersion() const noexcept { return MakeVersion(GetProxy().editorVersion); }
		[[nodiscard]] REL::Version     F4SEVersion() const noexcept { return MakeVersion(GetProxy().f4seVersion); }
		[[nodiscard]] PluginHandle     GetPluginHandle() const { return GetProxy().GetPluginHandle(); }
		[[nodiscard]] std::uint32_t    GetReleaseIndex() const { return GetProxy().GetReleaseIndex(); }
		[[nodiscard]] std::string_view GetSaveFolderName() const { return GetProxy().GetSaveFolderName(); }
		[[nodiscard]] bool             IsEditor() const noexcept { return GetProxy().isEditor != 0; }
		[[nodiscard]] REL::Version     RuntimeVersion() const noexcept { return MakeVersion(GetProxy().runtimeVersion); }
	};

	class PreLoadInterface :
		public QueryInterface
	{
	public:
		enum : std::uint32_t
		{
			kInvalid = 0,
			kTrampoline = 7
		};

		[[nodiscard]] void* QueryInterface(std::uint32_t a_id) const { return GetProxy().QueryInterface(a_id); }

		template <class T>
		T* QueryInterface(std::uint32_t a_id) const noexcept
		{
			auto result = static_cast<T*>(QueryInterface(a_id));
			if (result && result->Version() > T::kVersion)
				REX::ERROR("interface definition is out of date");

			return result;
		}
	};

	class LoadInterface :
		public QueryInterface
	{
	public:
		enum : std::uint32_t
		{
			kInvalid = 0,
			kMessaging = 1,
			kScaleform = 2,
			kPapyrus = 3,
			kSerialization = 4,
			kTask = 5,
			kObject = 6,
			kTrampoline = 7
		};

		[[nodiscard]] void* QueryInterface(std::uint32_t a_id) const { return GetProxy().QueryInterface(a_id); }

		template <class T>
		T* QueryInterface(std::uint32_t a_id) const noexcept
		{
			auto result = static_cast<T*>(QueryInterface(a_id));
			if (result && result->Version() > T::kVersion)
				REX::ERROR("interface definition is out of date");

			return result;
		}
	};

	class MessagingInterface
	{
	private:
		[[nodiscard]] decltype(auto) GetProxy() const noexcept
		{
			return reinterpret_cast<const Impl::F4SEMessagingInterface&>(*this);
		}

	public:
		enum : std::uint32_t
		{
			kVersion = 1
		};

		enum : std::uint32_t
		{
			kPostLoad,
			kPostPostLoad,
			kPreLoadGame,
			kPostLoadGame,
			kPreSaveGame,
			kPostSaveGame,
			kDeleteGame,
			kInputLoaded,
			kNewGame,
			kGameLoaded,
			kGameDataReady
		};

		struct Message
		{
			const char*   sender;
			std::uint32_t type;
			std::uint32_t dataLen;
			void*         data;
		};

		using EventCallback = void F4SEAPI(Message* a_msg);

		[[nodiscard]] std::uint32_t Version() const noexcept { return GetProxy().interfaceVersion; }

		bool RegisterListener(EventCallback* a_handler) const { return RegisterListener(a_handler, "F4SE"sv); }
		bool RegisterListener(EventCallback* a_handler, std::string_view a_sender) const;
		bool Dispatch(std::uint32_t a_messageType, void* a_data, std::uint32_t a_dataLen, const char* a_receiver) const;

		[[nodiscard]] void* GetEventDispatcher(std::uint32_t a_dispatcherID) const
		{
			return GetProxy().GetEventDispatcher(a_dispatcherID);
		}
	};

	class ScaleformInterface
	{
	private:
		[[nodiscard]] decltype(auto) GetProxy() const noexcept
		{
			return reinterpret_cast<const Impl::F4SEScaleformInterface&>(*this);
		}

	public:
		enum : std::uint32_t
		{
			kVersion = 1
		};

		using RegisterCallback = bool F4SEAPI(Scaleform::GFx::Movie* a_view, Scaleform::GFx::Value* a_value);

		[[nodiscard]] std::uint32_t Version() const noexcept { return GetProxy().interfaceVersion; }

		bool Register(std::string_view a_name, RegisterCallback* a_callback) const;
	};

	class SerializationInterface
	{
	private:
		[[nodiscard]] decltype(auto) GetProxy() const noexcept
		{
			return reinterpret_cast<const Impl::F4SESerializationInterface&>(*this);
		}

	public:
		enum : std::uint32_t
		{
			kVersion = 1,
		};

		using EventCallback = void      F4SEAPI(const SerializationInterface* a_intfc);
		using FormDeleteCallback = void F4SEAPI(std::uint64_t a_handle);

		[[nodiscard]] std::uint32_t Version() const noexcept { return GetProxy().version; }

		void SetUniqueID(std::uint32_t a_uid) const;
		void SetRevertCallback(EventCallback* a_callback) const;
		void SetSaveCallback(EventCallback* a_callback) const;
		void SetLoadCallback(EventCallback* a_callback) const;
		void SetFormDeleteCallback(FormDeleteCallback* a_callback) const;

		bool WriteRecord(std::uint32_t a_type, std::uint32_t a_version, const void* a_buf, std::uint32_t a_length) const;
		bool OpenRecord(std::uint32_t a_type, std::uint32_t a_version) const;
		bool WriteRecordData(const void* a_buf, std::uint32_t a_length) const;

		template <class T, std::enable_if_t<std::negation_v<std::is_pointer<T>>, int> = 0>
		bool WriteRecordData(const T& a_buf) const
		{
			return WriteRecordData(std::addressof(a_buf), sizeof(T));
		}

		template <class T, std::size_t N, std::enable_if_t<std::is_array_v<T>, int> = 0>
		bool WriteRecordData(const T (&a_buf)[N]) const
		{
			return WriteRecordData(std::addressof(a_buf), sizeof(T) * N);
		}

		bool GetNextRecordInfo(std::uint32_t& a_type, std::uint32_t& a_version, std::uint32_t& a_length) const;

		std::uint32_t ReadRecordData(void* a_buf, std::uint32_t a_length) const;

		template <class T, std::enable_if_t<std::negation_v<std::is_pointer<T>>, int> = 0>
		std::uint32_t ReadRecordData(T& a_buf) const
		{
			return ReadRecordData(std::addressof(a_buf), sizeof(T));
		}

		template <class T, std::enable_if_t<std::negation_v<std::is_pointer<T>>, int> = 0>
		std::uint32_t ReadRecordDataEx(std::uint32_t& a_length, T& a_buf) const
		{
			a_length -= sizeof(T);
			return ReadRecordData(std::addressof(a_buf), sizeof(T));
		}

		template <class T, std::size_t N, std::enable_if_t<std::is_array_v<T>, int> = 0>
		std::uint32_t ReadRecordData(T (&a_buf)[N]) const
		{
			return ReadRecordData(std::addressof(a_buf), sizeof(T) * N);
		}

		template <class T, std::size_t N, std::enable_if_t<std::is_array_v<T>, int> = 0>
		std::uint32_t ReadRecordDataEx(std::uint32_t& a_length, T (&a_buf)[N]) const
		{
			a_length -= sizeof(T);
			return ReadRecordData(std::addressof(a_buf), sizeof(T) * N);
		}

		[[nodiscard]] std::optional<std::uint64_t> ResolveHandle(std::uint64_t a_handle) const
		{
			std::uint64_t result{ 0 };
			if (GetProxy().ResolveHandle(a_handle, std::addressof(result))) {
				return result;
			} else {
				return std::nullopt;
			}
		}

		[[nodiscard]] std::optional<std::uint32_t> ResolveFormID(std::uint32_t a_formID) const
		{
			std::uint32_t result{ 0 };
			if (GetProxy().ResolveFormID(a_formID, std::addressof(result))) {
				return result;
			} else {
				return std::nullopt;
			}
		}
	};

	class PapyrusInterface
	{
	private:
		[[nodiscard]] decltype(auto) GetProxy() const noexcept
		{
			return reinterpret_cast<const Impl::F4SEPapyrusInterface&>(*this);
		}

	public:
		enum : std::uint32_t
		{
			kVersion = 2
		};

		using RegisterFunctions = bool F4SEAPI(RE::BSScript::IVirtualMachine* a_vm);
		using RegistrantFunctor = void F4SEAPI(std::uint64_t a_handle, const char* a_scriptName, const char* a_callbackName, void* a_data);

		[[nodiscard]] std::uint32_t Version() const noexcept { return GetProxy().interfaceVersion; }

		bool Register(RegisterFunctions* a_callback) const;

		void GetExternalEventRegistrations(std::string_view a_eventName, void* a_data, RegistrantFunctor* a_functor) const
		{
			GetProxy().GetExternalEventRegistrations(a_eventName.data(), a_data, reinterpret_cast<void*>(a_functor));
		}
	};

	class ITaskDelegate
	{
	public:
		virtual ~ITaskDelegate() noexcept = default;
		virtual void Run() = 0;
	};

	class TaskInterface
	{
	private:
		[[nodiscard]] decltype(auto) GetProxy() const noexcept
		{
			return reinterpret_cast<const Impl::F4SETaskInterface&>(*this);
		}

		class TaskDelegate :
			public ITaskDelegate
		{
		public:
			explicit TaskDelegate(std::function<void()> a_task) noexcept :
				_impl(std::move(a_task))
			{}

			void Run() override { _impl(); }

		private:
			std::function<void()> _impl;
		};

	public:
		enum
		{
			kVersion = 2
		};

		[[nodiscard]] std::uint32_t Version() const noexcept { return GetProxy().interfaceVersion; }

		void AddTask(ITaskDelegate* a_task) const { GetProxy().AddTask(a_task); }
		void AddTask(std::function<void()> a_task) const { AddTask(new TaskDelegate(std::move(a_task))); }
		void AddUITask(ITaskDelegate* a_task) const { GetProxy().AddUITask(a_task); }
		void AddUITask(std::function<void()> a_task) const { AddUITask(new TaskDelegate(std::move(a_task))); }
		void AddTaskPermanent(ITaskDelegate* a_task) const { GetProxy().AddTaskPermanent(a_task); }
		void AddTaskPermanent(std::function<void()> a_task) const { AddTaskPermanent(new TaskDelegate(std::move(a_task))); }
	};

	class ObjectInterface
	{
	private:
		[[nodiscard]] decltype(auto) GetProxy() const noexcept
		{
			return reinterpret_cast<const Impl::F4SEObjectInterface&>(*this);
		}

	public:
		enum
		{
			kVersion = 1
		};

		[[nodiscard]] std::uint32_t            Version() const noexcept { return GetProxy().interfaceVersion; }
		[[nodiscard]] DelayFunctorManager&     GetDelayFunctorManager() const { return GetProxy().GetDelayFunctorManager(); }
		[[nodiscard]] ObjectRegistry&          GetObjectRegistry() const { return GetProxy().GetObjectRegistry(); }
		[[nodiscard]] PersistentObjectStorage& GetPersistentObjectStorage() const { return GetProxy().GetPersistentObjectStorage(); }
	};

	class TrampolineInterface
	{
	private:
		[[nodiscard]] decltype(auto) GetProxy() const noexcept
		{
			return reinterpret_cast<const Impl::F4SETrampolineInterface&>(*this);
		}

	public:
		enum
		{
			kVersion = 1
		};

		[[nodiscard]] std::uint32_t Version() const noexcept { return GetProxy().interfaceVersion; }
		[[nodiscard]] void*         AllocateFromBranchPool(std::size_t a_size) const;
		[[nodiscard]] void*         AllocateFromLocalPool(std::size_t a_size) const;
	};

	struct PluginInfo
	{
		enum : std::uint32_t
		{
			kVersion = 1
		};

		std::uint32_t infoVersion;
		const char*   name;
		std::uint32_t version;
	};

	struct PluginVersionData
	{
		enum Version : std::uint32_t
		{
			kVersion = 1
		};

		constexpr void PluginVersion(const REL::Version a_version) noexcept { pluginVersion = a_version.pack(); }

		[[nodiscard]] constexpr REL::Version GetPluginVersion() const noexcept { return REL::Version::unpack(pluginVersion); }

		constexpr void PluginName(const std::string_view a_plugin) noexcept { SetCharBuffer(a_plugin, std::span{ pluginName }); }

		[[nodiscard]] constexpr std::string_view GetPluginName() const noexcept { return std::string_view{ pluginName }; }

		constexpr void AuthorName(const std::string_view a_name) noexcept { SetCharBuffer(a_name, std::span{ author }); }

		[[nodiscard]] constexpr std::string_view GetAuthorName() const noexcept { return std::string_view{ author }; }

		constexpr void UsesSigScanning(const bool a_value) noexcept { SetOrClearBit(addressIndependence, 1 << 0, a_value); }

		// 1 << 2 is for address library for 1.11.137 and later
		constexpr void UsesAddressLibrary(const bool a_value) noexcept { SetOrClearBit(addressIndependence, 1 << 2, a_value); }

		constexpr void HasNoStructUse(const bool a_value) noexcept { SetOrClearBit(structureIndependence, 1 << 0, a_value); }

		// 1 << 2 is for runtime 1.11.137 and later
		constexpr void IsLayoutDependent(const bool a_value) noexcept { SetOrClearBit(structureIndependence, 1 << 2, a_value); }

		constexpr void CompatibleVersions(std::initializer_list<REL::Version> a_versions) noexcept
		{
			// must be zero-terminated
			assert(a_versions.size() < std::size(compatibleVersions) - 1);
			std::ranges::transform(a_versions, std::begin(compatibleVersions), [](const REL::Version& a_version) noexcept {
				return a_version.pack();
			});
		}

		constexpr void MinimumRequiredXSEVersion(const REL::Version a_version) noexcept { xseMinimum = a_version.pack(); }

		[[nodiscard]] static const PluginVersionData* GetSingleton() noexcept;

		const std::uint32_t dataVersion{ kVersion };
		std::uint32_t       pluginVersion = 0;
		char                pluginName[256] = {};
		char                author[256] = {};
		std::uint32_t       addressIndependence;
		std::uint32_t       structureIndependence;
		std::uint32_t       compatibleVersions[16] = {};
		std::uint32_t       xseMinimum = 0;
		const std::uint32_t reservedNonBreaking = 0;
		const std::uint32_t reservedBreaking = 0;
		const std::uint8_t  reserved[512] = {};

	private:
		static constexpr void SetCharBuffer(std::string_view a_src, std::span<char> a_dst) noexcept
		{
			assert(a_src.size() < a_dst.size());
			std::ranges::fill(a_dst, '\0');
			std::ranges::copy(a_src, a_dst.begin());
		}

		static constexpr void SetOrClearBit(std::uint32_t& a_data, const std::uint32_t a_bit, const bool a_set) noexcept
		{
			if (a_set)
				a_data |= a_bit;
			else
				a_data &= ~a_bit;
		}
	};

	static_assert(offsetof(PluginVersionData, dataVersion) == 0x000);
	static_assert(offsetof(PluginVersionData, pluginVersion) == 0x004);
	static_assert(offsetof(PluginVersionData, pluginName) == 0x008);
	static_assert(offsetof(PluginVersionData, author) == 0x108);
	static_assert(offsetof(PluginVersionData, addressIndependence) == 0x208);
	static_assert(offsetof(PluginVersionData, structureIndependence) == 0x20C);
	static_assert(offsetof(PluginVersionData, compatibleVersions) == 0x210);
	static_assert(offsetof(PluginVersionData, xseMinimum) == 0x250);
	static_assert(offsetof(PluginVersionData, reservedNonBreaking) == 0x254);
	static_assert(offsetof(PluginVersionData, reservedBreaking) == 0x258);
	static_assert(offsetof(PluginVersionData, reserved) == 0x25C);
	static_assert(sizeof(PluginVersionData) == 0x45C);
}

#define F4SE_EXPORT extern "C" [[maybe_unused]] __declspec(dllexport)
#define F4SE_PLUGIN_PRELOAD(...) F4SE_EXPORT bool F4SEPlugin_Preload(__VA_ARGS__)
#define F4SE_PLUGIN_LOAD(...) F4SE_EXPORT bool F4SEPlugin_Load(__VA_ARGS__)
#define F4SE_PLUGIN_VERSION F4SE_EXPORT constinit F4SE::PluginVersionData F4SEPlugin_Version
#define F4SEPluginPreload F4SE_PLUGIN_PRELOAD
#define F4SEPluginLoad F4SE_PLUGIN_LOAD
#define F4SEPluginVersion F4SE_PLUGIN_VERSION
