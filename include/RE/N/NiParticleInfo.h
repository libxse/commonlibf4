#pragma once

#include "RE/N/NiPoint.h"

namespace RE
{
	class NiParticleInfo
	{
	public:
		// members
		NiPoint3      velocity;          // 00
		float         age;               // 0C
		float         lifeSpan;          // 10
		float         lastUpdate;        // 14
		std::uint16_t generation;        // 18
		std::uint16_t code;              // 1A
		std::int16_t  subTexFrame;       // 1C
		std::uint16_t subTexFrameCount;  // 1E
	};
	static_assert(sizeof(NiParticleInfo) == 0x20);
}
