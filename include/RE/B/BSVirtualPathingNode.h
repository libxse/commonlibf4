#pragma once

#include "RE/B/BSPathingLocation.h"
#include "RE/B/BSTSmartPointer.h"
#include "RE/M/MovementMessage.h"
#include "RE/N/NiPoint3.h"

namespace RE
{
	class BSVirtualPathingNode
	{
	public:
		// members
		BSPathingLocation                                                  location;      // 000
		BSTSmartPointer<MovementMessage, BSTSmartPointerIntrusiveRefCount> actionAtNode;  // 030
	};
	static_assert(sizeof(BSVirtualPathingNode) == 0x38);
}
