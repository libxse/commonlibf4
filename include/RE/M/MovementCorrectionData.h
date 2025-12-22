#pragma once

#include "RE/N/NiPoint.h"

namespace RE
{
	class MovementCorrectionData
	{
	public:
		// members
		NiPoint3 targetLocation;             // 00
		NiPoint3 targetRotation;             // 0C
		NiPoint3 translationCorrection;      // 18
		NiPoint3 rotationCorrection;         // 24
		NiPoint3 startVelocity;              // 30
		NiPoint3 endVelocity;                // 3C
		NiPoint3 startRotSpeed;              // 48
		NiPoint3 endRotSpeed;                // 54
		float    correctionStartTime;        // 60
		float    correctionEndTime;          // 64
		float    correctionStartRotateTime;  // 68
		float    correctionEndRotateTime;    // 6C
		float    totalTime;                  // 70
	};
	static_assert(sizeof(MovementCorrectionData) == 0x74);
}
