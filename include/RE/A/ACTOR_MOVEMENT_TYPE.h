#pragma once

namespace RE
{
	enum class ACTOR_MOVEMENT_TYPE : std::uint32_t
	{
		kWalk = 0x0,
		kRun = 0x1,
		kSneak = 0x2,
		kBleedout = 0x3,
		kSwim = 0x4
	};
}
