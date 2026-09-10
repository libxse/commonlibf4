#pragma once

#include "RE/B/BSPathingLockData.h"
#include "RE/B/BSTSmartPointer.h"

namespace RE
{
	class BSPathingActorAttributes
	{
	public:
		enum ACTOR_SHAPE_TYPE : std::uint32_t
		{
			kPoint = 0x0,
			kBiped = 0x1,
			kQuadruped = 0x2
		};

		enum LOCK_HANDLING_TYPE : std::uint32_t
		{
			kIgnore = 0x4,
			kCantOpen = 0x8,
			kUseLockData = 0xC
		};

		enum ATTRIBUTE : std::uint32_t
		{
			kWaitIfPlayerWaits = 0x80
		};

		enum TRAVERSAL_TYPE : std::uint32_t
		{
			kCanWalk = 0x1,
			kCanSwim = 0x2,
			kCanFly = 0x4,
			kCanFloat = 0x8,
			kIsLarge = 0x10,
			kCanJump = 0x20
		};

		// members
		float                              radius;          // 00
		float                              height;          // 04
		float                              floatHeight;     // 08
		BSTSmartPointer<BSPathingLockData> lockData;        // 10
		std::uint32_t                      data;            // 18
		std::uint8_t                       traversalFlags;  // 1C
	};
	static_assert(sizeof(BSPathingActorAttributes) == 0x20);
}
