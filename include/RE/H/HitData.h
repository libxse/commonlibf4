#pragma once

#include "RE/B/BGSBodyPartDefs.h"
#include "RE/B/BGSEquipIndex.h"
#include "RE/B/BGSObjectInstance.h"
#include "RE/B/BGSTypedFormValuePair.h"
#include "RE/B/BSPointerHandle.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTSmartPointer.h"
#include "RE/B/BSTTuple.h"
#include "RE/D/DamageImpactData.h"
#include "RE/N/NiPointer.h"

namespace RE
{
	enum class STAGGER_MAGNITUDE;
	class BGSAttackData;
	class VATSCommand;

	class HitData
	{
	public:
		enum class Flag
		{
			kBlocked = 1 << 0,
			kBlockWithWeapon = 1 << 1,
			kBlockCandidate = 1 << 2,
			kCritical = 1 << 3,
			kCriticalOnDeath = 1 << 4,
			kFatal = 1 << 5,
			kDismemberLimb = 1 << 6,
			kExplodeLimb = 1 << 7,
			kCrippleLimb = 1 << 8,
			kDisarm = 1 << 9,
			kDisableWeapon = 1 << 10,
			kSneakAttack = 1 << 11,
			kIgnoreCritical = 1 << 12,
			kPredictDamage = 1 << 13,
			kPredictBaseDamage = 1 << 14,
			kBash = 1 << 15,
			kTimedBash = 1 << 16,
			kPowerAttack = 1 << 17,
			kMeleeAttack = 1 << 18,
			kRicochet = 1 << 19,
			kExplosion = 1 << 20
		};

		// members
		DamageImpactData                                                impactData;              // 00
		ActorHandle                                                     aggressor;               // 40
		ActorHandle                                                     target;                  // 44
		ObjectRefHandle                                                 sourceRef;               // 48
		NiPointer<BGSAttackData>                                        attackData;              // 50
		BGSObjectInstanceT<TESObjectWEAP>                               weapon;                  // 58
		SpellItem*                                                      criticalEffect;          // 68
		SpellItem*                                                      hitEffect;               // 70
		BSTSmartPointer<VATSCommand>                                    VATSCommand;             // 78
		const TESAmmo*                                                  ammo;                    // 80
		BSTArray<BSTTuple<TESForm*, BGSTypedFormValuePair::SharedVal>>* damageTypes;             // 88
		float                                                           healthDamage;            // 90
		float                                                           totalDamage;             // 94
		float                                                           physicalDamage;          // 98
		float                                                           targetedLimbDamage;      // 9C
		float                                                           percentBlocked;          // A0
		float                                                           resistedPhysicalDamage;  // A4
		float                                                           resistedTypedDamage;     // A8
		REX::TEnumSet<STAGGER_MAGNITUDE, std::uint32_t>                 stagger;                 // AC
		float                                                           sneakAttackBonus;        // B0
		float                                                           bonusHealthDamageMult;   // B4
		float                                                           pushBack;                // B8
		float                                                           reflectedDamage;         // BC
		float                                                           criticalDamageMult;      // C0
		REX::TEnumSet<Flag, std::uint32_t>                              flags;                   // C4
		BGSEquipIndex                                                   equipIndex;              // C8
		std::uint32_t                                                   material;                // D0
		REX::TEnumSet<BGSBodyPartDefs::LIMB_ENUM, std::uint32_t>        damageLimb;              // D4
	};
	static_assert(sizeof(HitData) == 0xE0);
}
