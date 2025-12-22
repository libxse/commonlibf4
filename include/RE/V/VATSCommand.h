#pragma once

#include "RE/A/ActionPoints.h"
#include "RE/B/BGSBodyPartDefs.h"
#include "RE/B/BSIntrusiveRefCounted.h"
#include "RE/B/BSPointerHandle.h"
#include "RE/H/HitData.h"
#include "RE/N/NiAVObject.h"
#include "RE/N/NiPointer.h"

namespace RE
{
	class SpellItem;

	class VATSCommand :
		public BSIntrusiveRefCounted  // 000
	{
	public:
		// members
		ActionPoints::Action       action;              // 004
		ObjectRefHandle            target;              // 008
		BGSBodyPartDefs::LIMB_ENUM limb;                // 00C
		NiPointer<NiAVObject>      aimAtObj;            // 010
		HitData                    hitdata;             // 20
		SpellItem*                 meleeImpactEffect;   // 100
		float                      actionPointCost;     // 108
		float                      minActionTime;       // 10C
		float                      actionExecuteDelay;  // 110
		float                      fakeShotFrequency;   // 114
		float                      damageMult;          //118
		std::uint32_t              loadedAmmoCount;     // 11C
		std::uint8_t               fireShots;           // 120
		struct
		{
			std::uint8_t stranger: 1;
			std::uint8_t paralyzingPalm: 1;
			std::uint8_t leftHandCast: 1;
			std::uint8_t executeAction: 1;
			std::uint8_t actionExecuteSuccess: 1;
			std::uint8_t nextShotCausesCritical: 1;
			std::uint8_t spendCriticalCharge: 1;
			std::uint8_t attackChanceHit: 1;
		} flags1;  // 121
		struct
		{
			std::uint8_t shotFired: 1;
			std::uint8_t criticalAttack: 1;
			std::uint8_t syncedAnim: 1;
			std::uint8_t attemptChain: 1;
			std::uint8_t allowWarp: 1;
			std::uint8_t meleeSneakAttack: 1;
		} flags2;  // 122
	};
	static_assert(sizeof(VATSCommand) == 0x130);
}
