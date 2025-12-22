#pragma once

#include "RE/B/BSNavmeshTriHandle.h"
#include "RE/N/NiPoint.h"

namespace RE
{
	class BSNavmeshTriLocation :
		public BSNavmeshTriHandle  // 00
	{
		// members
		NiPoint3 location;  // 10
	};
	static_assert(sizeof(BSNavmeshTriLocation) == 0x20);
}
