#pragma once

#include "RE/B/BSTempEffect.h"
#include "RE/N/NiPointer.h"

namespace RE
{
	class NiAVObject;

	class __declspec(novtable) BSTempEffectWeaponBlood :
		public BSTempEffect  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BSTempEffectWeaponBlood };
		static constexpr auto VTABLE{ VTABLE::BSTempEffectWeaponBlood };
		static constexpr auto Ni_RTTI{ Ni_RTTI::BSTempEffect };
		static constexpr auto TYPE{ TEMP_EFFECT_TYPE::kWeaponBlood };

		~BSTempEffectWeaponBlood() override;

		static void ClearEffectForWeapon(NiAVObject* a_weapon3D)
		{
			using func_t = decltype(&BSTempEffectWeaponBlood::ClearEffectForWeapon);
			REL::Relocation<func_t> func{ ID::BSTempEffectWeaponBlood::ClearEffectForWeapon };
			return func(a_weapon3D);
		}

		// members
		NiPointer<NiAVObject> weapon;        // 30
		float                 fBloodAmount;  // 38
	};
	static_assert(sizeof(BSTempEffectWeaponBlood) == 0x40);
}
