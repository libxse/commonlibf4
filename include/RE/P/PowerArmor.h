#pragma once

#include "RE/P/PlayerCharacter.h"
#include "RE/S/Setting.h"

namespace RE
{
	class BGSInventoryItem;

	namespace PowerArmor
	{
		[[nodiscard]] inline bool ActorInPowerArmor(const Actor& a_actor)
		{
			using func_t = decltype(&ActorInPowerArmor);
			static REL::Relocation<func_t> func{ ID::PowerArmor::ActorInPowerArmor };
			return func(a_actor);
		}

		[[nodiscard]] inline bool PlayerInPowerArmor()
		{
			auto PlayerCharacter = PlayerCharacter::GetSingleton();
			return PlayerCharacter ? ActorInPowerArmor(*PlayerCharacter) : false;
		}

		[[nodiscard]] inline BGSKeyword* GetArmorKeyword()
		{
			using func_t = decltype(&GetArmorKeyword);
			static REL::Relocation<func_t> func{ ID::PowerArmor::GetArmorKeyword };
			return func();
		}

		[[nodiscard]] inline BGSKeyword* GetBatteryKeyword()
		{
			using func_t = decltype(&GetBatteryKeyword);
			static REL::Relocation<func_t> func{ ID::PowerArmor::GetBatteryKeyword };
			return func();
		}

		[[nodiscard]] inline TESAmmo* GetDefaultBatteryObject()
		{
			using func_t = decltype(&GetDefaultBatteryObject);
			static REL::Relocation<func_t> func{ ID::PowerArmor::GetDefaultBatteryObject };
			return func();
		}

		[[nodiscard]] inline bool IsPowerArmorBattery(const TESBoundObject* a_itemData)
		{
			using func_t = decltype(&IsPowerArmorBattery);
			static REL::Relocation<func_t> func{ ID::PowerArmor::IsPowerArmorBattery };
			return func(a_itemData);
		}

		inline void SyncFurnitureVisualsToInventory(TESObjectREFR* a_furniture, bool a_force3DUpdate, BGSInventoryItem* a_tempItemToAdd, bool a_hideCore)
		{
			using func_t = decltype(&SyncFurnitureVisualsToInventory);
			static REL::Relocation<func_t> func{ ID::PowerArmor::SyncFurnitureVisualsToInventory };
			return func(a_furniture, a_force3DUpdate, a_tempItemToAdd, a_hideCore);
		}

		[[nodiscard]] inline SettingT<GameSettingCollection>* GetNewBatteryCapacity()
		{
			static REL::Relocation<SettingT<GameSettingCollection>*> value{ ID::PowerArmor::fNewBatteryCapacity };
			return value.get();
		}
	}
}
