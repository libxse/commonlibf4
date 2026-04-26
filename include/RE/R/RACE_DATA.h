#pragma once

#include "RE/N/NiPoint.h"

namespace RE
{
	enum class BIPED_OBJECT;
	enum class RACE_SIZE;

	class RACE_DATA
	{
	public:
		// members
		float                                     height[2];                    // 000
		NiPoint3                                  weight[2];                    // 008
		std::int32_t                              flags;                        // 020
		float                                     accelerate;                   // 024
		float                                     decelerate;                   // 028
		REX::TEnumSet<RACE_SIZE, std::int32_t>    raceSize;                     // 02C
		REX::TEnumSet<BIPED_OBJECT, std::int32_t> headObject;                   // 030
		REX::TEnumSet<BIPED_OBJECT, std::int32_t> hairObject;                   // 034
		REX::TEnumSet<BIPED_OBJECT, std::int32_t> beardObject;                  // 038
		float                                     injuredHealthPercent;         // 03C
		REX::TEnumSet<BIPED_OBJECT, std::int32_t> shieldObject;                 // 040
		REX::TEnumSet<BIPED_OBJECT, std::int32_t> bodyObject;                   // 044
		float                                     aimAngleTolerance;            // 048
		float                                     flightRadius;                 // 04C
		float                                     angleAccelerate;              // 050
		float                                     angleTolerance;               // 054
		std::uint32_t                             flags2;                       // 058
		NiPoint3                                  mountOffset;                  // 05C
		NiPoint3                                  dismountOffset;               // 068
		NiPoint3                                  mountCameraOffset;            // 074
		REX::TEnumSet<BIPED_OBJECT, std::int32_t> pipboyObject;                 // 080
		std::int16_t                              xpValue;                      // 084
		BGSExplosion*                             onCrippleExplosion;           // 088
		BGSDebris*                                onCrippleGenericDebris;       // 090
		BGSImpactDataSet*                         onCrippleImpactDataSet;       // 098
		float                                     onCrippleGenericDebrisScale;  // 0A0
		std::int8_t                               onCrippleGenericDebrisCount;  // 0A4
		std::int8_t                               onCrippleDecalCount;          // 0A5
		BGSExplosion*                             dismemberExplosion;           // 0A8
		BGSDebris*                                dismemberGenericDebris;       // 0B0
		BGSImpactDataSet*                         dismemberImpactDataSet;       // 0B8
		float                                     dismemberGenericDebrisScale;  // 0C0
		std::int8_t                               dismemberGenericDebrisCount;  // 0C4
		std::int8_t                               dismemberDecalCount;          // 0C5
		BGSExplosion*                             explosion;                    // 0C8
		BGSDebris*                                explosionGenericDebris;       // 0D0
		BGSImpactDataSet*                         explosionImpactDataSet;       // 0D8
		float                                     explosionGenericDebrisScale;  // 0E0
		std::int8_t                               explosionGenericDebrisCount;  // 0E4
		std::int8_t                               explosionDecalCount;          // 0E5
		BGSExplosion*                             subsegmentExplosion;          // 0E8
		float                                     maxPitch;                     // 0F0
		float                                     maxRoll;                      // 0F4
		float                                     defaultHeadHeight;            // 0F8
	};
	static_assert(sizeof(RACE_DATA) == 0x100);
}
