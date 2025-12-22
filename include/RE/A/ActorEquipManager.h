#pragma once

#include "RE/B/BSTEvent.h"
#include "RE/B/BSTSingleton.h"

namespace RE
{
	class BGSEquipSlot;
	class BGSObjectInstance;
	class EquippedItem;

	namespace ActorEquipManagerEvent
	{
		class Event;
	}

	class ActorEquipManager :
		public BSTSingletonSDM<ActorEquipManager>,            // 00
		public BSTEventSource<ActorEquipManagerEvent::Event>  // 08
	{
	public:
		enum class CanEquipResult
		{
			kSuccess = 0x0,
			kInvalidItem = 0x1,
			kNoModEquip = 0x2,
			kPAWhileNotInPA = 0x3,
			kNonPAWhileInPA = 0x4,
			kEquipStateLocked = 0x5,
			kItemBroken = 0x6,
			kNoEquipKeyword = 0x7
		};

		[[nodiscard]] static ActorEquipManager* GetSingleton()
		{
			static REL::Relocation<ActorEquipManager**> singleton{ ID::ActorEquipManager::Singleton };
			return *singleton;
		}

		bool EquipObject(
			Actor*                   a_actor,
			const BGSObjectInstance& a_object,
			std::uint32_t            a_stackID,
			std::uint32_t            a_number,
			const BGSEquipSlot*      a_slot,
			bool                     a_queueEquip,
			bool                     a_forceEquip,
			bool                     a_playSounds,
			bool                     a_applyNow,
			bool                     a_locked)
		{
			using func_t = decltype(&ActorEquipManager::EquipObject);
			static REL::Relocation<func_t> func{ ID::ActorEquipManager::EquipObject };
			return func(this, a_actor, a_object, a_stackID, a_number, a_slot, a_queueEquip, a_forceEquip, a_playSounds, a_applyNow, a_locked);
		}

		bool UnequipObject(
			Actor*                   a_actor,
			const BGSObjectInstance* a_object,
			std::uint32_t            a_number,
			const BGSEquipSlot*      a_slot,
			std::uint32_t            a_stackID,
			bool                     a_queueEquip,
			bool                     a_forceEquip,
			bool                     a_playSounds,
			bool                     a_applyNow,
			const BGSEquipSlot*      a_slotBeingReplaced)
		{
			using func_t = decltype(&ActorEquipManager::UnequipObject);
			static REL::Relocation<func_t> func{ ID::ActorEquipManager::UnequipObject };
			return func(this, a_actor, a_object, a_number, a_slot, a_stackID, a_queueEquip, a_forceEquip, a_playSounds, a_applyNow, a_slotBeingReplaced);
		}

		void UnequipItem(Actor* a_actor, const EquippedItem* a_equippedItem, bool a_queueEquip)
		{
			using func_t = decltype(&ActorEquipManager::UnequipItem);
			static REL::Relocation<func_t> func{ ID::ActorEquipManager::UnequipItem };
			return func(this, a_actor, a_equippedItem, a_queueEquip);
		}
	};
	static_assert(sizeof(ActorEquipManager) == 0x60);
}
