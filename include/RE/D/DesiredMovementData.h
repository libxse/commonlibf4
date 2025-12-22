#pragma once

#include "RE/N/NiPoint.h"

namespace RE
{
	class DesiredMovementData
	{
	public:
		// members
		NiPoint3A position;       // 00
		NiPoint3A orientation;    // 10
		NiPoint3A movementSpeed;  // 20
		NiPoint3A rotationSpeed;  // 30
	};
	static_assert(sizeof(DesiredMovementData) == 0x40);
}
