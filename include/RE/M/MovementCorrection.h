#pragma once

#include "RE/N/NiPoint.h"

namespace RE
{
	class MovementCorrection
	{
	public:
		enum class CORRECTION_TYPE : std::uint32_t
		{
			kNone = 0x0,
			kTargetPosVelAndIdle = 0x1,
			kFixedDelta = 0x2,
			kUpdateToFaceTarget = 0x3
		};

		// members
		MovementCorrection::CORRECTION_TYPE correctionType;             // 00
		NiPoint3                            parameters[10];             // 04
		float                               correctionStartTime;        // 7C
		float                               correctionEndTime;          // 80
		float                               correctionStartRotateTime;  // 84
		float                               correctionEndRotateTime;    // 88
		float                               totalTime;                  // 8C
	};
	static_assert(sizeof(MovementCorrection) == 0x90);
}
