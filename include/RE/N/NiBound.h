#pragma once

#include "RE/N/NiPoint.h"

namespace RE
{
	class NiBound
	{
	public:
		// members
		NiPoint3 center;  // 00
		union
		{
			float        fRadius;
			std::int32_t iRadius{ 0 };
		};  // 0C
	};
	static_assert(sizeof(NiBound) == 0x10);
}
