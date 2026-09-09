#pragma once

#include "RE/B/BSIntrusiveRefCounted.h"
#include "RE/B/BSTArray.h"

namespace RE
{
	template <class T, class Allocator = BSTArrayHeapAllocator>
	class alignas(0x8) BSTArrayRefCounted :
		public BSTArray<T, Allocator>,  // 00
		public BSIntrusiveRefCounted    // 18
	{
	public:
	};
}
