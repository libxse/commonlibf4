#pragma once

#include "RE/N/NiPoint.h"

namespace RE
{
	class MovementVector
	{
	public:
		// members
		NiPoint3A eulerAngles;  // 00
		float     speed;        // 10
	};
	static_assert(sizeof(MovementVector) == 0x20);
}
