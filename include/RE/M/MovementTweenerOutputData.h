#pragma once

#include "RE/N/NiPoint.h"

namespace RE
{
	class MovementTweenerOutputData
	{
	public:
		// members
		NiPoint3 velocity;       // 00
		NiPoint3 rotationSpeed;  // 0C
	};
	static_assert(sizeof(MovementTweenerOutputData) == 0x18);
}
