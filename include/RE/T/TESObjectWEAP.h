#pragma once

#include "RE/B/BGSAttachParentArray.h"
#include "RE/B/BGSBlockBashData.h"
#include "RE/B/BGSDestructibleObjectForm.h"
#include "RE/B/BGSEquipType.h"
#include "RE/B/BGSInstanceNamingRulesForm.h"
#include "RE/B/BGSKeywordForm.h"
#include "RE/B/BGSMessageIcon.h"
#include "RE/B/BGSModelMaterialSwap.h"
#include "RE/B/BGSPickupPutdownSounds.h"
#include "RE/B/BGSPreloadable.h"
#include "RE/B/BGSTypedFormValuePair.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTTuple.h"
#include "RE/M/MELEE_ATTACK_SPEED.h"
#include "RE/T/TESBoundObject.h"
#include "RE/T/TESDescription.h"
#include "RE/T/TESEnchantableForm.h"
#include "RE/T/TESFullName.h"
#include "RE/T/TESIcon.h"
#include "RE/W/WEAPON_FLAGS.h"
#include "RE/W/WEAPON_TYPE.h"

namespace RE
{
	enum class SOUND_LEVEL;
	enum class STAGGER_MAGNITUDE;
	enum class WEAPON_RUMBLE_PATTERN;
	enum class WEAPONHITBEHAVIOR;

	class __declspec(novtable) TESObjectWEAP :
		public TESBoundObject,             // 000
		public TESFullName,                // 068
		public BGSModelMaterialSwap,       // 078
		public TESIcon,                    // 0B8
		public TESEnchantableForm,         // 0C8
		public BGSDestructibleObjectForm,  // 0E0
		public BGSEquipType,               // 0F0
		public BGSPreloadable,             // 100
		public BGSMessageIcon,             // 108
		public BGSPickupPutdownSounds,     // 120
		public BGSBlockBashData,           // 138
		public BGSKeywordForm,             // 150
		public TESDescription,             // 170
		public BGSInstanceNamingRulesForm  // 188
	{
	public:
		static constexpr auto RTTI{ RTTI::TESObjectWEAP };
		static constexpr auto VTABLE{ VTABLE::TESObjectWEAP };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kWEAP };

		class RangedData
		{
		public:
			// members
			BGSProjectile*                                     overrideProjectile;              // 00
			float                                              fireSeconds;                     // 08
			float                                              firingRumbleLeftMotorStrength;   // 0C
			float                                              firingRumbleRightMotorStrength;  // 10
			float                                              firingRumbleDuration;            // 14
			float                                              reloadSeconds;                   // 18
			float                                              boltChargeSeconds;               // 1C
			float                                              sightedTransitionSeconds;        // 20
			std::uint32_t                                      rumblePeriod;                    // 24
			REX::TEnumSet<WEAPON_RUMBLE_PATTERN, std::int32_t> rumblePattern;                   // 28
			std::int8_t                                        numProjectiles;                  // 2C
		};
		static_assert(sizeof(RangedData) == 0x30);

		class __declspec(novtable) InstanceData :
			public TBO_InstanceData  // 000
		{
		public:
			static constexpr auto RTTI{ RTTI::TESObjectWEAP__InstanceData };
			static constexpr auto VTABLE{ VTABLE::TESObjectWEAP__InstanceData };

			// members
			BGSSoundDescriptorForm*                                         attackSound;            // 010
			BGSSoundDescriptorForm*                                         attackSound2D;          // 018
			BGSSoundDescriptorForm*                                         attackLoop;             // 020
			BGSSoundDescriptorForm*                                         attackFailSound;        // 028
			BGSSoundDescriptorForm*                                         idleSound;              // 030
			BGSSoundDescriptorForm*                                         equipSound;             // 038
			BGSSoundDescriptorForm*                                         unEquipSound;           // 040
			BGSSoundDescriptorForm*                                         fastEquipSound;         // 048
			BGSBlockBashData*                                               blockBashData;          // 050
			BGSImpactDataSet*                                               impactDataSet;          // 058
			TESLevItem*                                                     npcAddAmmoList;         // 060
			TESAmmo*                                                        ammo;                   // 068
			BGSEquipSlot*                                                   equipSlot;              // 070
			SpellItem*                                                      effect;                 // 078
			BGSKeywordForm*                                                 keywords;               // 080
			BGSAimModel*                                                    aimModel;               // 088
			BGSZoomData*                                                    zoomData;               // 090
			RangedData*                                                     rangedData;             // 098
			BSTArray<EnchantmentItem*>*                                     enchantments;           // 0A0
			BSTArray<BGSMaterialSwap*>*                                     materialSwaps;          // 0A8
			BSTArray<BSTTuple<TESForm*, BGSTypedFormValuePair::SharedVal>>* damageTypes;            // 0B0
			BSTArray<BSTTuple<TESForm*, BGSTypedFormValuePair::SharedVal>>* actorValues;            // 0B8
			float                                                           attackSeconds;          // 0C0
			float                                                           reloadSpeed;            // 0C4
			float                                                           speed;                  // 0C8
			float                                                           reach;                  // 0CC
			float                                                           minRange;               // 0D0
			float                                                           maxRange;               // 0D4
			float                                                           attackDelaySec;         // 0D8
			float                                                           damageToWeaponMult;     // 0DC
			float                                                           outOfRangeDamageMult;   // 0E0
			float                                                           secondaryDamage;        // 0E4
			float                                                           criticalChargeBonus;    // 0E8
			float                                                           weight;                 // 0EC
			float                                                           soundLevelMult;         // 0F0
			float                                                           attackActionPointCost;  // 0F4
			float                                                           fullPowerSeconds;       // 0F8
			float                                                           minPowerPerShot;        // 0FC
			float                                                           colorRemappingIndex;    // 100
			float                                                           criticalDamageMult;     // 104
			REX::TEnumSet<STAGGER_MAGNITUDE, std::int32_t>                  staggerValue;           // 108
			std::uint32_t                                                   value;                  // 10C
			REX::TEnumSet<WEAPON_FLAGS, std::uint32_t>                      flags;                  // 110
			REX::TEnumSet<SOUND_LEVEL, std::int32_t>                        soundLevel;             // 114
			REX::TEnumSet<WEAPONHITBEHAVIOR, std::int32_t>                  hitBehavior;            // 118
			ActorValueInfo*                                                 skill;                  // 120
			ActorValueInfo*                                                 resistance;             // 128
			std::uint16_t                                                   ammoCapacity;           // 130
			std::uint16_t                                                   attackDamage;           // 132
			std::uint16_t                                                   rank;                   // 134
			std::int8_t                                                     accuracyBonus;          // 136
			REX::TEnumSet<WEAPON_TYPE, std::uint8_t>                        type;                   // 137
		};
		static_assert(sizeof(InstanceData) == 0x138);

		class __declspec(novtable) Data :
			public InstanceData  // 000
		{
		public:
			static constexpr auto RTTI{ RTTI::TESObjectWEAP__Data };
			static constexpr auto VTABLE{ VTABLE::TESObjectWEAP__Data };
		};
		static_assert(sizeof(Data) == 0x138);

		[[nodiscard]] MELEE_ATTACK_SPEED GetMeleeAttackSpeed()
		{
			using func_t = decltype(&TESObjectWEAP::GetMeleeAttackSpeed);
			static REL::Relocation<func_t> func{ ID::TESObjectWEAP::GetMeleeAttackSpeed };
			return func(this);
		}

		[[nodiscard]] static const char* GetMeleeAttackSpeedLabel(MELEE_ATTACK_SPEED a_speed)
		{
			using func_t = decltype(&TESObjectWEAP::GetMeleeAttackSpeedLabel);
			static REL::Relocation<func_t> func{ ID::TESObjectWEAP::GetMeleeAttackSpeedLabel };
			return func(a_speed);
		}

		bool IsMeleeWeapon() const
		{
			return weaponData.type.any(
				WEAPON_TYPE::kOneHandSword,
				WEAPON_TYPE::kOneHandDagger,
				WEAPON_TYPE::kOneHandAxe,
				WEAPON_TYPE::kOneHandMace,
				WEAPON_TYPE::kTwoHandSword,
				WEAPON_TYPE::kTwoHandAxe);
		}

		bool IsGunWeapon() const
		{
			return weaponData.type.any(
				WEAPON_TYPE::kGun);
		}

		bool IsThrownWeapon() const
		{
			return weaponData.type.any(
				WEAPON_TYPE::kGrenade,
				WEAPON_TYPE::kMine);
		}

		bool IsOneHandedWeapon() const
		{
			return weaponData.type.any(
				WEAPON_TYPE::kOneHandSword,
				WEAPON_TYPE::kOneHandDagger,
				WEAPON_TYPE::kOneHandAxe,
				WEAPON_TYPE::kOneHandMace);
		}

		bool IsTwoHandedWeapon() const
		{
			return weaponData.type.any(
				WEAPON_TYPE::kTwoHandSword,
				WEAPON_TYPE::kTwoHandAxe);
		}

		bool IsRangedWeapon() const
		{
			return weaponData.type.any(
				WEAPON_TYPE::kBow,
				WEAPON_TYPE::kStaff,
				WEAPON_TYPE::kGun,
				WEAPON_TYPE::kGrenade,
				WEAPON_TYPE::kMine);
		}

		bool IsBoundWeapon() const
		{
			return weaponData.flags.all(
				WEAPON_FLAGS::kBoundWeapon);
		}

		bool IsEmbeddedWeapon() const
		{
			return weaponData.flags.all(
				WEAPON_FLAGS::kEmbeddedWeapon);
		}

		// members
		TESObjectWEAP::Data      weaponData;         // 198
		BGSModelMaterialSwap*    firstPersonModel;   // 2D0
		TESObjectWEAP*           weaponTemplate;     // 2D8
		BGSMod::Attachment::Mod* embeddedWeaponMod;  // 2E0
		BGSAttachParentArray     attachParents;      // 2E8
	};
	static_assert(sizeof(TESObjectWEAP) == 0x300);
}
