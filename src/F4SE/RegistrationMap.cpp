#include "F4SE/RegistrationMap.h"

namespace F4SE
{
	namespace Impl
	{
		template <class Filter>
		EventFilter<Filter>::RegistrationMapBase::RegistrationMapBase(const std::string_view& a_eventName) :
			_regs(),
			_eventName(a_eventName),
			_lock()
		{}

		template <class Filter>
		EventFilter<Filter>::RegistrationMapBase::RegistrationMapBase(const RegistrationMapBase& a_rhs) :
			_regs(),
			_eventName(a_rhs._eventName),
			_lock()
		{
			a_rhs._lock.lock();
			_regs = a_rhs._regs;
			a_rhs._lock.unlock();

			if (auto game = RE::GameVM::GetSingleton()) {
				if (auto vm = game->GetVM()) {
					for (auto& reg : _regs) {
						for (auto& handle : reg.second) {
							vm->GetObjectHandlePolicy().PersistHandle(handle);
						}
					}
				}
			}
		}

		template <class Filter>
		EventFilter<Filter>::RegistrationMapBase::RegistrationMapBase(RegistrationMapBase&& a_rhs) :
			_regs(),
			_eventName(a_rhs._eventName),
			_lock()
		{
			Locker locker(a_rhs._lock);
			_regs = std::move(a_rhs._regs);
			a_rhs._regs.clear();
		}

		template <class Filter>
		EventFilter<Filter>::RegistrationMapBase::~RegistrationMapBase()
		{
			if (auto game = RE::GameVM::GetSingleton()) {
				if (auto vm = game->GetVM()) {
					for (auto& reg : _regs) {
						for (auto& handle : reg.second) {
							vm->GetObjectHandlePolicy().ReleaseHandle(handle);
						}
					}
				}
			}
		}

		template <class Filter>
		typename EventFilter<Filter>::RegistrationMapBase& EventFilter<Filter>::RegistrationMapBase::operator=(const RegistrationMapBase& a_rhs)
		{
			if (this == &a_rhs) {
				return *this;
			}

			Locker lhsLocker(_lock);
			Clear();

			{
				Locker rhsLocker(a_rhs._lock);
				_regs = a_rhs._regs;
				_eventName = a_rhs._eventName;
			}

			if (auto game = RE::GameVM::GetSingleton()) {
				if (auto vm = game->GetVM()) {
					for (auto& reg : _regs) {
						for (auto& handle : reg.second) {
							vm->GetObjectHandlePolicy().PersistHandle(handle);
						}
					}
				}
			}

			return *this;
		}

		template <class Filter>
		typename EventFilter<Filter>::RegistrationMapBase& EventFilter<Filter>::RegistrationMapBase::operator=(RegistrationMapBase&& a_rhs)
		{
			if (this == &a_rhs) {
				return *this;
			}

			Locker lhsLocker(_lock);
			Locker rhsLocker(a_rhs._lock);

			Clear();

			_eventName = a_rhs._eventName;

			_regs = std::move(a_rhs._regs);
			a_rhs._regs.clear();

			return *this;
		}

		template <class Filter>
		bool EventFilter<Filter>::RegistrationMapBase::Register(const RE::TESForm* a_form, Filter a_filter)
		{
			assert(a_form);
			return Register(a_form, std::move(a_filter), static_cast<std::uint32_t>(a_form->GetFormType()));
		}

		template <class Filter>
		bool EventFilter<Filter>::RegistrationMapBase::Register(const RE::BGSBaseAlias* a_alias, Filter a_filter)
		{
			assert(a_alias);
			return Register(a_alias, std::move(a_filter), a_alias->GetVMTypeID());
		}

		template <class Filter>
		bool EventFilter<Filter>::RegistrationMapBase::Register(const RE::ActiveEffect* a_activeEffect, Filter a_filter)
		{
			assert(a_activeEffect);
			return Register(a_activeEffect, std::move(a_filter), RE::ActiveEffect::TYPE_ID);
		}

		template <class Filter>
		bool EventFilter<Filter>::RegistrationMapBase::Unregister(const RE::TESForm* a_form, Filter a_filter)
		{
			assert(a_form);
			return Unregister(a_form, std::move(a_filter), static_cast<std::uint32_t>(a_form->GetFormType()));
		}

		template <class Filter>
		bool EventFilter<Filter>::RegistrationMapBase::Unregister(const RE::BGSBaseAlias* a_alias, Filter a_filter)
		{
			assert(a_alias);
			return Unregister(a_alias, std::move(a_filter), a_alias->GetVMTypeID());
		}

		template <class Filter>
		bool EventFilter<Filter>::RegistrationMapBase::Unregister(const RE::ActiveEffect* a_activeEffect, Filter a_filter)
		{
			assert(a_activeEffect);
			return Unregister(a_activeEffect, std::move(a_filter), RE::ActiveEffect::TYPE_ID);
		}

		template <class Filter>
		void EventFilter<Filter>::RegistrationMapBase::UnregisterAll(const RE::TESForm* a_form)
		{
			assert(a_form);
			UnregisterAll(a_form, static_cast<std::uint32_t>(a_form->GetFormType()));
		}

		template <class Filter>
		void EventFilter<Filter>::RegistrationMapBase::UnregisterAll(const RE::BGSBaseAlias* a_alias)
		{
			assert(a_alias);
			UnregisterAll(a_alias, a_alias->GetVMTypeID());
		}

		template <class Filter>
		void EventFilter<Filter>::RegistrationMapBase::UnregisterAll(const RE::ActiveEffect* a_activeEffect)
		{
			assert(a_activeEffect);
			UnregisterAll(a_activeEffect, RE::ActiveEffect::TYPE_ID);
		}

		template <class Filter>
		void EventFilter<Filter>::RegistrationMapBase::UnregisterAll(RE::VMHandle a_handle)
		{
			auto game = RE::GameVM::GetSingleton();
			auto vm = game->GetVM();
			if (!vm) {
				REX::ERROR("Failed to get VM!"sv);
				return;
			}

			Locker locker(_lock);
			for (auto& reg : _regs) {
				if (auto result = reg.second.erase(a_handle); result != 0) {
					vm->GetObjectHandlePolicy().ReleaseHandle(a_handle);
				}
			}
		}

		template <class Filter>
		void EventFilter<Filter>::RegistrationMapBase::Clear()
		{
			Locker locker(_lock);
			if (auto game = RE::GameVM::GetSingleton()) {
				if (auto vm = game->GetVM()) {
					for (auto& reg : _regs) {
						for (auto& handle : reg.second) {
							vm->GetObjectHandlePolicy().ReleaseHandle(handle);
						}
					}
				}
			}
			_regs.clear();
		}

		template <class Filter>
		bool EventFilter<Filter>::RegistrationMapBase::Save(SerializationInterface* a_intfc, std::uint32_t a_type, std::uint32_t a_version)
		{
			assert(a_intfc);
			if (!a_intfc->OpenRecord(a_type, a_version)) {
				REX::ERROR("Failed to open record!"sv);
				return false;
			}

			return Save(a_intfc);
		}

		template <class Filter>
		bool EventFilter<Filter>::RegistrationMapBase::SaveFilter(SerializationInterface* a_intfc, Filter a_filter)
		{
			if constexpr (std::is_same_v<std::string, Filter>) {
				std::size_t length = a_filter.length() + 1;
				if (!a_intfc->WriteRecordData(length) || !a_intfc->WriteRecordData(a_filter.c_str(), static_cast<std::uint32_t>(length))) {
					return false;
				}
				return true;
			} else {
				return a_intfc->WriteRecordData(a_filter);
			}
		}

		template <class Filter>
		bool EventFilter<Filter>::RegistrationMapBase::Save(SerializationInterface* a_intfc)
		{
			assert(a_intfc);
			Locker            locker(_lock);
			const std::size_t numRegs = _regs.size();
			if (!a_intfc->WriteRecordData(numRegs)) {
				REX::ERROR("Failed to save reg count ({})!"sv, numRegs);
				return false;
			}

			for (auto& reg : _regs) {
				if (!SaveFilter(a_intfc, reg.first)) {
					return false;
				}
				std::size_t numHandles = reg.second.size();
				if (!a_intfc->WriteRecordData(numHandles)) {
					REX::ERROR("Failed to save handle count ({})!"sv, numHandles);
					return false;
				}
				for (auto& handle : reg.second) {
					if (!a_intfc->WriteRecordData(handle)) {
						REX::ERROR("Failed to save handle ({})"sv, handle);
						return false;
					}
				}
			}

			return true;
		}

		template <class Filter>
		bool EventFilter<Filter>::RegistrationMapBase::LoadFilter(SerializationInterface* a_intfc, Filter& a_filter)
		{
			if constexpr (std::is_same_v<std::string, Filter>) {
				std::size_t length = 0;
				if (!a_intfc->ReadRecordData(length)) {
					return false;
				}
				a_filter.reserve(length);
				return a_intfc->ReadRecordData(a_filter.data(), static_cast<std::uint32_t>(length));
			} else if constexpr (std::is_same_v<std::uint32_t, Filter>) {
				if (!a_intfc->ReadRecordData(a_filter)) {
					return false;
				}
				return a_intfc->ResolveFormID(a_filter);
			} else {
				return a_intfc->ReadRecordData(a_filter);
			}
		}

		template <class Filter>
		bool EventFilter<Filter>::RegistrationMapBase::Load(SerializationInterface* a_intfc)
		{
			assert(a_intfc);
			std::size_t numRegs;
			a_intfc->ReadRecordData(numRegs);

			Locker locker(_lock);
			_regs.clear();

			Filter       filter{};
			std::size_t  numHandles;
			RE::VMHandle handle;

			for (std::size_t i = 0; i < numRegs; ++i) {
				bool loadedFilter = LoadFilter(a_intfc, filter);
				a_intfc->ReadRecordData(numHandles);
				for (std::size_t j = 0; j < numHandles; ++j) {
					a_intfc->ReadRecordData(handle);
					if (auto resolvedHandle = a_intfc->ResolveHandle(handle); resolvedHandle && loadedFilter) {
						_regs[filter].insert(*resolvedHandle);
					}
				}
			}

			return true;
		}

		template <class Filter>
		void EventFilter<Filter>::RegistrationMapBase::Revert(SerializationInterface*)
		{
			Clear();
		}

		template <class Filter>
		bool EventFilter<Filter>::RegistrationMapBase::Register(const void* a_object, Filter a_filter, RE::VMTypeID a_typeID)
		{
			assert(a_object);
			auto game = RE::GameVM::GetSingleton();
			auto vm = game->GetVM();
			if (!vm) {
				REX::ERROR("Failed to get VM!"sv);
				return false;
			}

			const auto invalidHandle = vm->GetObjectHandlePolicy().EmptyHandle();
			auto       handle = vm->GetObjectHandlePolicy().GetHandleForObject(a_typeID, a_object);
			if (handle == invalidHandle) {
				REX::ERROR("Failed to create handle!"sv);
				return false;
			}

			_lock.lock();
			auto result = _regs[a_filter].insert(handle);
			_lock.unlock();

			if (result.second) {
				vm->GetObjectHandlePolicy().PersistHandle(handle);
			}

			return result.second;
		}

		template <class Filter>
		bool EventFilter<Filter>::RegistrationMapBase::Unregister(const void* a_object, Filter a_filter, RE::VMTypeID a_typeID)
		{
			assert(a_object);
			auto game = RE::GameVM::GetSingleton();
			auto vm = game->GetVM();
			if (!vm) {
				REX::ERROR("Failed to get VM!"sv);
				return false;
			}

			const auto invalidHandle = vm->GetObjectHandlePolicy().EmptyHandle();
			const auto handle = vm->GetObjectHandlePolicy().GetHandleForObject(a_typeID, a_object);
			if (handle == invalidHandle) {
				REX::ERROR("Failed to create handle!"sv);
				return false;
			}

			Locker locker(_lock);
			if (auto it = _regs.find(a_filter); it != _regs.end()) {
				if (auto result = it->second.erase(handle); result != 0) {
					vm->GetObjectHandlePolicy().ReleaseHandle(handle);
					return true;
				}
			}

			return false;
		}

		template <class Filter>
		void EventFilter<Filter>::RegistrationMapBase::UnregisterAll(const void* a_object, RE::VMTypeID a_typeID)
		{
			assert(a_object);
			auto game = RE::GameVM::GetSingleton();
			auto vm = game->GetVM();
			if (!vm) {
				REX::ERROR("Failed to get VM!"sv);
				return;
			}

			const auto invalidHandle = vm->GetObjectHandlePolicy().EmptyHandle();
			const auto handle = vm->GetObjectHandlePolicy().GetHandleForObject(a_typeID, a_object);
			if (handle == invalidHandle) {
				REX::ERROR("Failed to create handle!"sv);
				return;
			}

			Locker locker(_lock);
			for (auto& reg : _regs) {
				if (auto result = reg.second.erase(handle); result != 0) {
					vm->GetObjectHandlePolicy().ReleaseHandle(handle);
				}
			}
		}
	}
}
