#pragma once

#include "RE/N/NiPoint3.h"

namespace RE
{
	class BSPathingSearchAreaRestrictions
	{
	public:
		NiPoint3 center;  // 00
		float    radius;  // 0C
	};
	static_assert(sizeof(BSPathingSearchAreaRestrictions) == 0x10);
}
