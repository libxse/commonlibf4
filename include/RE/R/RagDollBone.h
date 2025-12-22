#pragma once

#include "RE/N/NiPoint.h"

namespace RE
{
	class RagDollBone
	{
	public:
		// members
		char     boneID;   // 00
		NiPoint3 bonePos;  // 04
		NiPoint3 boneRot;  // 10
	};
	static_assert(sizeof(RagDollBone) == 0x1C);
}
