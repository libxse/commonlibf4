#include "F4SE/Interfaces.h"

#include "F4SE/API.h"

#include "REX/W32/KERNEL32.h"

namespace F4SE
{
	bool MessagingInterface::RegisterListener(EventCallback* a_handler, std::string_view a_sender) const
	{
		const auto success = GetProxy().RegisterListener(GetPluginHandle(), a_sender.data(), reinterpret_cast<void*>(a_handler));
		if (!success) {
			REX::ERROR("failed to register listener for {}", a_sender);
		}
		return success;
	}

	bool MessagingInterface::Dispatch(std::uint32_t a_messageType, void* a_data, std::uint32_t a_dataLen, const char* a_receiver) const
	{
		const auto success = GetProxy().Dispatch(GetPluginHandle(), a_messageType, a_data, a_dataLen, a_receiver);
		if (!success) {
			REX::ERROR("failed to dispatch to {}", (a_receiver ? a_receiver : "all listeners"));
		}
		return success;
	}

	bool ScaleformInterface::Register(std::string_view a_name, RegisterCallback* a_callback) const
	{
		const auto success = GetProxy().Register(a_name.data(), reinterpret_cast<void*>(a_callback));
		if (!success) {
			REX::ERROR("failed to register {}", a_name);
		}
		return success;
	}

	void SerializationInterface::SetUniqueID(std::uint32_t a_uid) const
	{
		GetProxy().SetUniqueID(GetPluginHandle(), a_uid);
	}

	void SerializationInterface::SetRevertCallback(EventCallback* a_callback) const
	{
		GetProxy().SetRevertCallback(GetPluginHandle(), reinterpret_cast<void*>(a_callback));
	}

	void SerializationInterface::SetSaveCallback(EventCallback* a_callback) const
	{
		GetProxy().SetSaveCallback(GetPluginHandle(), reinterpret_cast<void*>(a_callback));
	}

	void SerializationInterface::SetLoadCallback(EventCallback* a_callback) const
	{
		GetProxy().SetLoadCallback(GetPluginHandle(), reinterpret_cast<void*>(a_callback));
	}

	void SerializationInterface::SetFormDeleteCallback(FormDeleteCallback* a_callback) const
	{
		GetProxy().SetFormDeleteCallback(GetPluginHandle(), reinterpret_cast<void*>(a_callback));
	}

	bool SerializationInterface::WriteRecord(std::uint32_t a_type, std::uint32_t a_version, const void* a_buf, std::uint32_t a_length) const
	{
		const auto success = GetProxy().WriteRecord(a_type, a_version, a_buf, a_length);
		if (!success) {
			REX::ERROR("failed to write record");
		}
		return success;
	}

	bool SerializationInterface::OpenRecord(std::uint32_t a_type, std::uint32_t a_version) const
	{
		const auto success = GetProxy().OpenRecord(a_type, a_version);
		if (!success) {
			REX::ERROR("failed to open record");
		}
		return success;
	}

	bool SerializationInterface::WriteRecordData(const void* a_buf, std::uint32_t a_length) const
	{
		const auto success = GetProxy().WriteRecordData(a_buf, a_length);
		if (!success) {
			REX::ERROR("failed to write record data");
		}
		return success;
	}

	bool SerializationInterface::GetNextRecordInfo(std::uint32_t& a_type, std::uint32_t& a_version, std::uint32_t& a_length) const
	{
		return GetProxy().GetNextRecordInfo(std::addressof(a_type), std::addressof(a_version), std::addressof(a_length));
	}

	std::uint32_t SerializationInterface::ReadRecordData(void* a_buf, std::uint32_t a_length) const
	{
		const auto read = GetProxy().ReadRecordData(a_buf, a_length);
		if (read != a_length) {
			REX::ERROR("failed to read full record data {}B of {}B", read, a_length);
		}
		return read;
	}

	bool PapyrusInterface::Register(RegisterFunctions* a_callback) const
	{
		const auto success = GetProxy().Register(reinterpret_cast<void*>(a_callback));
		if (!success) {
			REX::ERROR("failed to register callback");
		}
		return success;
	}

	void* TrampolineInterface::AllocateFromBranchPool(std::size_t a_size) const
	{
		const auto mem = GetProxy().AllocateFromBranchPool(GetPluginHandle(), a_size);
		if (!mem) {
			REX::ERROR("failed to allocate from branch pool");
		}
		return mem;
	}

	void* TrampolineInterface::AllocateFromLocalPool(std::size_t a_size) const
	{
		const auto mem = GetProxy().AllocateFromLocalPool(GetPluginHandle(), a_size);
		if (!mem) {
			REX::ERROR("failed to allocate from local pool");
		}
		return mem;
	}

	const PluginVersionData* PluginVersionData::GetSingleton() noexcept
	{
		return reinterpret_cast<const PluginVersionData*>(REX::W32::GetProcAddress(REX::W32::GetCurrentModule(), "F4SEPlugin_Version"));
	}
}
