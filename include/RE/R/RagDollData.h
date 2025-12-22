#pragma once

#include "RE/N/NiPoint.h"

namespace RE
{
	class RagDollBone;

	class RagDollData
	{
	public:
		// members
		std::uint8_t boneCount;  // 00
		RagDollBone* boneArray;  // 08
		NiPoint3     bip01Rot;   // 10
	};
	static_assert(sizeof(RagDollData) == 0x20);
}
