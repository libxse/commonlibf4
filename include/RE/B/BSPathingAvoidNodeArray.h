#pragma once

#include "RE/B/BSPathingAvoidNode.h"
#include "RE/B/BSTArrayRefCounted.h"

namespace RE
{
	class BSPathingAvoidNodeArray :
		public BSTArrayRefCounted<BSPathingAvoidNode, BSTArrayHeapAllocator>  // 00
	{
	public:
	};
	static_assert(sizeof(BSPathingAvoidNodeArray) == 0x20);
}
