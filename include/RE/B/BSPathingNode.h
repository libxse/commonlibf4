#pragma once

#include "RE/B/BSPathingLocation.h"
#include "RE/B/BSTSmartPointer.h"
#include "RE/M/MovementMessage.h"
#include "RE/N/NiPoint3.h"

namespace RE
{
	class BSPathingNode
	{
	public:
		BSPathingLocation                                                  location;      // 000
		BSTSmartPointer<MovementMessage, BSTSmartPointerIntrusiveRefCount> actionAtNode;  // 030
		NiPoint3                                                           tangent;       // 038
	};
	static_assert(sizeof(BSPathingNode) == 0x48);
}
