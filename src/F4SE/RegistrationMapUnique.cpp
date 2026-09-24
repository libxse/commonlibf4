#include "F4SE/RegistrationMapUnique.h"

namespace F4SE
{
	namespace Impl
	{
		template <class Filter>
		EventFilterUnique<Filter>::RegistrationMapUniqueBase::RegistrationMapUniqueBase(const std::string_view& a_eventName) :
			_regs(),
			_eventName(a_eventName),
			_lock()
		{}

		template <class Filter>
		EventFilterUnique<Filter>::RegistrationMapUniqueBase::RegistrationMapUniqueBase(const RegistrationMapUniqueBase& a_rhs) :
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
						for (auto& keyHandles : reg.second) {
							for (auto& handle : keyHandles.second) {
								vm->GetObjectHandlePolicy().PersistHandle(handle);
							}
						}
					}
				}
			}
		}

		template <class Filter>
		EventFilterUnique<Filter>::RegistrationMapUniqueBase::RegistrationMapUniqueBase(RegistrationMapUniqueBase&& a_rhs) noexcept :
			_regs(),
			_eventName(a_rhs._eventName),
			_lock()
		{
			Locker locker(a_rhs._lock);
			_regs = std::move(a_rhs._regs);
			a_rhs._regs.clear();
		}

		template <class Filter>
		EventFilterUnique<Filter>::RegistrationMapUniqueBase::~RegistrationMapUniqueBase()
		{
			if (auto game = RE::GameVM::GetSingleton()) {
				if (auto vm = game->GetVM()) {
					for (auto& reg : _regs) {
						for (auto& keyHandles : reg.second) {
							for (auto& handle : keyHandles.second) {
								vm->GetObjectHandlePolicy().ReleaseHandle(handle);
							}
						}
					}
				}
			}
		}

		template <class Filter>
		typename EventFilterUnique<Filter>::RegistrationMapUniqueBase& EventFilterUnique<Filter>::RegistrationMapUniqueBase::operator=(const RegistrationMapUniqueBase& a_rhs)
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
						for (auto& keyHandles : reg.second) {
							for (auto& handle : keyHandles.second) {
								vm->GetObjectHandlePolicy().PersistHandle(handle);
							}
						}
					}
				}
			}

			return *this;
		}

		template <class Filter>
		typename EventFilterUnique<Filter>::RegistrationMapUniqueBase& EventFilterUnique<Filter>::RegistrationMapUniqueBase::operator=(RegistrationMapUniqueBase&& a_rhs) noexcept
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
		bool EventFilterUnique<Filter>::RegistrationMapUniqueBase::Register(RE::TESForm* a_form, const Filter& a_filter, bool a_matchFilter)
		{
			assert(a_form);
			const auto reference = a_form->As<RE::TESObjectREFR>();
			const auto formID = reference ? reference->GetFormID() : 0;

			if (formID != 0) {
				return Register(a_form, formID, { a_filter, a_matchFilter }, static_cast<std::uint32_t>(a_form->GetFormType()));
			}

			return false;
		}

		template <class Filter>
		bool EventFilterUnique<Filter>::RegistrationMapUniqueBase::Register(RE::ActiveEffect* a_activeEffect, const Filter& a_filter, bool a_matchFilter)
		{
			assert(a_activeEffect);
			const auto target = a_activeEffect->GetTargetActor();
			const auto formID = target ? target->GetFormID() : 0;

			if (formID != 0) {
				return Register(a_activeEffect, formID, { a_filter, a_matchFilter }, RE::ActiveEffect::TYPE_ID);
			}

			return false;
		}

		template <class Filter>
		bool EventFilterUnique<Filter>::RegistrationMapUniqueBase::Register(RE::BGSRefAlias* a_alias, const Filter& a_filter, bool a_matchFilter)
		{
			assert(a_alias);
			const auto target = a_alias->GetActorReference();
			const auto formID = target ? target->GetFormID() : 0;

			if (formID != 0) {
				return Register(a_alias, formID, { a_filter, a_matchFilter }, RE::BGSRefAlias::TYPE_ID);
			}

			return false;
		}

		template <class Filter>
		bool EventFilterUnique<Filter>::RegistrationMapUniqueBase::Unregister(RE::TESForm* a_form, const Filter& a_filter, bool a_matchFilter)
		{
			assert(a_form);
			const auto reference = a_form->As<RE::TESObjectREFR>();
			const auto formID = reference ? reference->GetFormID() : 0;

			if (formID != 0) {
				return Unregister(a_form, formID, { a_filter, a_matchFilter }, static_cast<std::uint32_t>(a_form->GetFormType()));
			}

			return false;
		}

		template <class Filter>
		bool EventFilterUnique<Filter>::RegistrationMapUniqueBase::Unregister(RE::ActiveEffect* a_activeEffect, const Filter& a_filter, bool a_matchFilter)
		{
			assert(a_activeEffect);
			const auto target = a_activeEffect->GetTargetActor();
			const auto formID = target ? target->GetFormID() : 0;

			if (formID != 0) {
				return Unregister(a_activeEffect, formID, { a_filter, a_matchFilter }, RE::ActiveEffect::TYPE_ID);
			}

			return false;
		}

		template <class Filter>
		bool EventFilterUnique<Filter>::RegistrationMapUniqueBase::Unregister(RE::BGSRefAlias* a_alias, const Filter& a_filter, bool a_matchFilter)
		{
			assert(a_alias);
			const auto target = a_alias->GetActorReference();
			const auto formID = target ? target->GetFormID() : 0;

			if (formID != 0) {
				return Unregister(a_alias, formID, { a_filter, a_matchFilter }, RE::BGSRefAlias::TYPE_ID);
			}

			return false;
		}

		template <class Filter>
		void EventFilterUnique<Filter>::RegistrationMapUniqueBase::UnregisterAll(const RE::TESForm* a_form)
		{
			assert(a_form);
			const auto reference = a_form->As<RE::TESObjectREFR>();
			const auto formID = reference ? reference->GetFormID() : 0;

			if (formID != 0) {
				UnregisterAll(a_form, formID, static_cast<std::uint32_t>(a_form->GetFormType()));
			}
		}

		template <class Filter>
		void EventFilterUnique<Filter>::RegistrationMapUniqueBase::UnregisterAll(RE::ActiveEffect* a_activeEffect)
		{
			assert(a_activeEffect);
			const auto target = a_activeEffect->GetTargetActor();
			const auto formID = target ? target->GetFormID() : 0;

			if (formID != 0) {
				UnregisterAll(a_activeEffect, formID, RE::ActiveEffect::TYPE_ID);
			}
		}

		template <class Filter>
		void EventFilterUnique<Filter>::RegistrationMapUniqueBase::UnregisterAll(RE::BGSRefAlias* a_alias)
		{
			assert(a_alias);
			const auto target = a_alias->GetActorReference();
			const auto formID = target ? target->GetFormID() : 0;

			if (formID != 0) {
				UnregisterAll(a_alias, formID, RE::BGSRefAlias::TYPE_ID);
			}
		}

		template <class Filter>
		void EventFilterUnique<Filter>::RegistrationMapUniqueBase::UnregisterAll(RE::VMHandle a_handle)
		{
			auto game = RE::GameVM::GetSingleton();
			auto vm = game->GetVM();
			if (!vm) {
				REX::ERROR("Failed to get VM!"sv);
				return;
			}

			Locker locker(_lock);
			for (auto& reg : _regs) {
				for (auto& keyHandle : reg.second) {
					if (auto result = keyHandle.second.erase(a_handle); result != 0) {
						vm->GetObjectHandlePolicy().ReleaseHandle(a_handle);
					}
				}
			}
		}

		template <class Filter>
		void EventFilterUnique<Filter>::RegistrationMapUniqueBase::UnregisterAll(RE::TESFormID a_uniqueID)
		{
			auto game = RE::GameVM::GetSingleton();
			auto vm = game->GetVM();
			if (!vm) {
				REX::ERROR("Failed to get VM!"sv);
				return;
			}

			Locker locker(_lock);
			auto   it = _regs.find(a_uniqueID);
			if (it != _regs.end()) {
				for (auto& keyHandles : it->second) {
					for (auto& handle : keyHandles.second) {
						vm->GetObjectHandlePolicy().ReleaseHandle(handle);
					}
				}
				_regs.erase(it);
			}
		}

		template <class Filter>
		void EventFilterUnique<Filter>::RegistrationMapUniqueBase::Clear()
		{
			Locker locker(_lock);
			if (auto game = RE::GameVM::GetSingleton()) {
				if (auto vm = game->GetVM()) {
					for (auto& reg : _regs) {
						for (auto& keyHandle : reg.second) {
							for (auto& handle : keyHandle.second) {
								vm->GetObjectHandlePolicy().ReleaseHandle(handle);
							}
						}
					}
				}
			}
			_regs.clear();
		}

		template <class Filter>
		bool EventFilterUnique<Filter>::RegistrationMapUniqueBase::Save(SerializationInterface* a_intfc, std::uint32_t a_type, std::uint32_t a_version)
		{
			assert(a_intfc);
			if (!a_intfc->OpenRecord(a_type, a_version)) {
				REX::ERROR("Failed to open record!"sv);
				return false;
			}

			return Save(a_intfc);
		}

		template <class Filter>
		bool EventFilterUnique<Filter>::RegistrationMapUniqueBase::Save(SerializationInterface* a_intfc)
		{
			assert(a_intfc);
			Locker            locker(_lock);
			const std::size_t numRegs = _regs.size();
			if (!a_intfc->WriteRecordData(numRegs)) {
				REX::ERROR("Failed to save reg count ({})!"sv, numRegs);
				return false;
			}
			for (auto& reg : _regs) {
				if (!a_intfc->WriteRecordData(reg.first)) {
					REX::ERROR("Failed to save handle formID ({:08X})"sv, reg.first);
					return false;
				}
				std::size_t numUniqueHandle = reg.second.size();
				if (!a_intfc->WriteRecordData(numUniqueHandle)) {
					REX::ERROR("Failed to save handle count ({})!"sv, numUniqueHandle);
					return false;
				}
				for (auto& [key, handles] : reg.second) {
					auto [eventFilter, match] = key;
					if (!eventFilter.Save(a_intfc)) {
						REX::ERROR("Failed to save event filters!"sv);
						return false;
					}
					if (!a_intfc->WriteRecordData(match)) {
						REX::ERROR("Failed to save reg key as bool ({})!"sv, match);
						return false;
					}
					std::size_t numHandles = handles.size();
					if (!a_intfc->WriteRecordData(numHandles)) {
						REX::ERROR("Failed to save handle count ({})!"sv, numHandles);
						return false;
					}
					for (auto& handle : handles) {
						if (!a_intfc->WriteRecordData(handle)) {
							REX::ERROR("Failed to save handle ({})"sv, handle);
							return false;
						}
					}
				}
			}

			return true;
		}

		template <class Filter>
		bool EventFilterUnique<Filter>::RegistrationMapUniqueBase::Load(SerializationInterface* a_intfc)
		{
			assert(a_intfc);
			std::size_t numRegs;
			a_intfc->ReadRecordData(numRegs);

			Locker locker(_lock);
			_regs.clear();

			Filter        filter{};
			bool          match;
			RE::TESFormID formID;
			std::size_t   numKeyHandle;
			std::size_t   numHandles;
			RE::VMHandle  handle;

			for (std::size_t i = 0; i < numRegs; ++i) {
				a_intfc->ReadRecordData(formID);
				auto resolvedFormID = a_intfc->ResolveFormID(formID);
				a_intfc->ReadRecordData(numKeyHandle);
				for (std::size_t j = 0; j < numKeyHandle; ++j) {
					filter.Load(a_intfc);
					a_intfc->ReadRecordData(match);
					EventFilter curKey = { filter, match };
					a_intfc->ReadRecordData(numHandles);
					for (std::size_t k = 0; k < numHandles; ++k) {
						a_intfc->ReadRecordData(handle);
						if (auto resolvedHandle = a_intfc->ResolveHandle(handle); resolvedFormID && resolvedHandle) {
							_regs[*resolvedFormID][curKey].insert(*resolvedHandle);
						}
					}
				}
			}

			return true;
		}

		template <class Filter>
		void EventFilterUnique<Filter>::RegistrationMapUniqueBase::Revert(SerializationInterface*)
		{
			Clear();
		}

		template <class Filter>
		bool EventFilterUnique<Filter>::RegistrationMapUniqueBase::Register(const void* a_object, RE::TESFormID a_formID, EventFilter a_filter, RE::VMTypeID a_typeID)
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
			auto result = _regs[a_formID][a_filter].insert(handle);
			_lock.unlock();

			if (result.second) {
				vm->GetObjectHandlePolicy().PersistHandle(handle);
			}

			return result.second;
		}

		template <class Filter>
		bool EventFilterUnique<Filter>::RegistrationMapUniqueBase::Unregister(const void* a_object, RE::TESFormID a_formID, EventFilter a_filter, RE::VMTypeID a_typeID)
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
			if (auto formIt = _regs.find(a_formID); formIt != _regs.end()) {
				if (auto keyIt = formIt->second.find(a_filter); keyIt != formIt->second.end()) {
					if (auto result = keyIt->second.erase(handle); result != 0) {
						vm->GetObjectHandlePolicy().ReleaseHandle(handle);
						return true;
					}
				}
			}

			return false;
		}

		template <class Filter>
		void EventFilterUnique<Filter>::RegistrationMapUniqueBase::UnregisterAll(const void* a_object, RE::TESFormID a_formID, RE::VMTypeID a_typeID)
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
			if (auto it = _regs.find(a_formID); it != _regs.end()) {
				for (auto& keyHandles : it->second) {
					if (auto result = keyHandles.second.erase(handle); result != 0) {
						vm->GetObjectHandlePolicy().ReleaseHandle(handle);
					}
				}
			}
		}
	}
}
