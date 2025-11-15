#pragma once

#include "RE/A/AITimeStamp.h"
#include "RE/B/BSPointerHandle.h"
#include "RE/N/NiPoint.h"

namespace RE
{
	class DetectionEvent
	{
	public:
		// members
		std::uint32_t   actionValue;  // 00
		NiPoint3        location;     // 04
		AITimeStamp     timeStamp;    // 10
		ObjectRefHandle ref;          // 14
	};
	static_assert(sizeof(DetectionEvent) == 0x18);
}
