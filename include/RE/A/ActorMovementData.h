#pragma once

#include "RE/M/MovementData.h"
#include "RE/M/MovementTweenerOutputData.h"

namespace RE
{
	class ActorMovementData
	{
	public:
		// members
		MovementData              handlerData;  // 00
		MovementTweenerOutputData tweenerData;  // 30
	};
	static_assert(sizeof(ActorMovementData) == 0x50);
}
