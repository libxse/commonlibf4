#pragma once

#include "RE/B/BSPointerHandle.h"
#include "RE/H/hkVector4f.h"

namespace RE
{
	class TrapData
	{
	public:
		// members
		ObjectRefHandle trap;            // 00
		float           damage;          // 04
		float           leveledDamage;   // 08
		float           minVelocity;     // 0C
		float           pushBack;        // 10
		float           deathPushback;   // 14
		float           stagger;         // 18
		bool            continuous;      // 1C
		hkVector4f      pushbackVector;  // 20
		hkVector4f      hitLocation;     // 30
		std::uint32_t   material;        // 40
	};
	static_assert(sizeof(TrapData) == 0x50);
}
