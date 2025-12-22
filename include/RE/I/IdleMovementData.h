#pragma once

#include "RE/N/NiPoint.h"

namespace RE
{
	class IdleMovementData
	{
	public:
		// members
		NiPoint3A translation;                    // 00
		NiPoint3A rotation;                       // 10
		NiPoint3A startVelocity;                  // 20
		NiPoint3A endVelocity;                    // 30
		NiPoint3A startRotSpeed;                  // 40
		NiPoint3A endRotSpeed;                    // 50
		NiPoint3A averageRotSpeed;                // 60
		NiPoint3A translationUntilAllowRotation;  // 70
		NiPoint3A velocityAtAllowRotation;        // 80
		NiPoint3A rotSpeedAtAllowRotation;        // 90
		float     duration;                       // A0
		float     tweenStart;                     // A4
		float     tweenEnd;                       // A8
		float     rotationTweenStart;             // AC
		float     rotationTweenEnd;               // B0
		float     syncAnimTimes[4];               // B4
		bool      usesAllowRotation;              // C4
	};
	static_assert(sizeof(IdleMovementData) == 0xD0);
}
