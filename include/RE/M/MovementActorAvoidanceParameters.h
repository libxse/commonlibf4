#pragma once

#include "RE/B/BSTArray.h"

namespace RE
{
	class MovementActorAvoidanceParameters
	{
	public:
		// members
		BSTSmallArray<std::uint32_t, 1> actors;  // 000
		std::uint32_t                   flags;   // 018
	};
	static_assert(sizeof(MovementActorAvoidanceParameters) == 0x20);
}
