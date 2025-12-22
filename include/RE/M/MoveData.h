#pragma once

#include "RE/N/NiPoint.h"

namespace RE
{
	class MoveData
	{
	public:
		// members
		NiPoint3A angle;                   // 00
		NiPoint3A displacement;            // 10
		float     time;                    // 20
		float     currMoveSpeed;           // 24
		bool      visible;                 // 28
		bool      deferMove;               // 29
		bool      forceAllowZTranslation;  // 2A
	};
	static_assert(sizeof(MoveData) == 0x30);
}
