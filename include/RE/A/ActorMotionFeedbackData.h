#pragma once

#include "RE/N/NiPoint.h"

namespace RE
{
	class ActorMotionFeedbackData
	{
	public:
		// members
		NiPoint3 desiredWorldDelta;  // 00
		NiPoint3 actualWorldDelta;   // 0C
		float    previousSpeed;      // 18
		float    previousDirection;  // 1C
		float    currentHeading;     // 20
	};
	static_assert(sizeof(ActorMotionFeedbackData) == 0x24);
}
