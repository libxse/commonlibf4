#pragma once

#include "RE/N/NiPoint.h"

namespace RE
{
	enum class SOUND_LEVEL;
	enum class STAGGER_MAGNITUDE;

	class BGSExplosionData
	{
	public:
		// members
		TESObjectLIGH*                                 light;                  // 00
		BGSSoundDescriptorForm*                        sound1;                 // 08
		BGSSoundDescriptorForm*                        sound2;                 // 10
		BGSImpactDataSet*                              impactDataSet;          // 18
		TESBoundObject*                                impactPlacedObject;     // 20
		BGSProjectile*                                 spawnProjectile;        // 28
		NiPoint3                                       projectileVector;       // 30
		float                                          projectileSpread;       // 3C
		std::uint32_t                                  projectileCount;        // 40
		float                                          force;                  // 44
		float                                          damage;                 // 48
		float                                          innerRadius;            // 4C
		float                                          outerRadius;            // 50
		float                                          imageSpaceRadius;       // 54
		float                                          verticalOffsetMult;     // 58
		std::uint32_t                                  flags;                  // 5C
		REX::TEnumSet<SOUND_LEVEL, std::int32_t>       soundLevel;             // 60
		float                                          placedObjectFadeDelay;  // 64
		REX::TEnumSet<STAGGER_MAGNITUDE, std::int32_t> staggerMagnitude;       // 68
	};
	static_assert(sizeof(BGSExplosionData) == 0x70);
}
