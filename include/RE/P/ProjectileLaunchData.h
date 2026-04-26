#pragma once

#include "RE/B/BGSBodyPartDefs.h"
#include "RE/B/BGSEquipIndex.h"
#include "RE/B/BGSObjectInstance.h"
#include "RE/N/NiPoint.h"

namespace RE
{
	class CombatController;

	namespace MagicSystem
	{
		enum class CastingSource;
	}

	class ProjectileLaunchData
	{
	public:
		// members
		NiPoint3                                                 origin;                   // 00
		NiPoint3                                                 contactNormal;            // 0C
		BGSProjectile*                                           projectileBase;           // 18
		TESObjectREFR*                                           shooter;                  // 20
		CombatController*                                        shooterCombatController;  // 28
		BGSObjectInstanceT<TESObjectWEAP>                        fromWeapon;               // 30
		TESAmmo*                                                 fromAmmo;                 // 40
		BGSEquipIndex                                            equipIndex;               // 48
		float                                                    zAngle;                   // 4C
		float                                                    xAngle;                   // 50
		float                                                    yAngle;                   // 54
		TESObjectREFR*                                           homingTarget;             // 58
		TESObjectCELL*                                           parentCell;               // 60
		MagicItem*                                               spell;                    // 68
		REX::TEnumSet<MagicSystem::CastingSource, std::int32_t>  castingSource;            // 70
		AlchemyItem*                                             poison;                   // 78
		std::int32_t                                             area;                     // 80
		float                                                    power;                    // 84
		float                                                    scale;                    // 88
		float                                                    coneOfFireRadiusMult;     // 8C
		REX::TEnumSet<BGSBodyPartDefs::LIMB_ENUM, std::uint32_t> targetLimb;               // 90
		bool                                                     alwaysHit;                // 94
		bool                                                     noDamageOutsideCombat;    // 95
		bool                                                     autoAim;                  // 96
		bool                                                     useOrigin;                // 97
		bool                                                     deferInitialization;      // 98
		bool                                                     tracer;                   // 99
		bool                                                     forceConeOfFire;          // 9A
		bool                                                     intentionalMiss;          // 9B
		bool                                                     allow3D;                  // 9C
		bool                                                     penetrates;               // 9D
		bool                                                     ignoreNearCollisions;     // 9E
	};
	static_assert(sizeof(ProjectileLaunchData) == 0xA0);
}
