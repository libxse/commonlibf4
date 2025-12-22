#pragma once

#include "RE/N/NiPoint.h"

namespace RE
{
	class BSPathingFaceTarget
	{
	public:
		enum class FACE_TARGET_TYPE : std::uint32_t
		{
			kNone = 0x0,
			kAngle = 0x1,
			kPoint = 0x2,
			kPointHeading = 0x3
		};

		// members
		BSPathingFaceTarget::FACE_TARGET_TYPE type;               // 00
		NiPoint3                              point;              // 04
		float                                 angle;              // 10
		float                                 angleTolernaceCCW;  // 14
		float                                 angleToleranceCW;   // 18
	};
	static_assert(sizeof(BSPathingFaceTarget) == 0x1C);
}
