#pragma once

#include "RE/N/NiPoint.h"

namespace RE
{
	class TESForm;

	class WORLD_LOCATION
	{
	public:
		// members
		TESForm* locationForm;  // 00
		NiPoint3 locPt;         // 08
		float    zRot;          // 14
	};
	static_assert(sizeof(WORLD_LOCATION) == 0x18);
}
