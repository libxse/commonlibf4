#pragma once

#include "RE/A/AITimeStamp.h"
#include "RE/A/AITimer.h"
#include "RE/B/bhkCollisionQueryResultHandle.h"

namespace RE
{
	class GunStateData
	{
	public:
		// members
		bhkCollisionQueryResultHandle collisionRequest;          // 00
		AITimer                       updateTimer;               // 08
		AITimeStamp                   gunStateChangedTimeStamp;  // 10
	};
	static_assert(sizeof(GunStateData) == 0x18);
}
