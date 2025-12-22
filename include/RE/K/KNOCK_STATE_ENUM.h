#pragma once

namespace RE
{
	enum class KNOCK_STATE_ENUM : std::uint32_t
	{
		kNormal = 0x0,
		kExplode = 0x1,
		kExplodeLeadIn = 0x2,
		kOut = 0x3,
		kOutLeadIn = 0x4,
		kQueued = 0x5,
		kGetUp = 0x6,
		kDown = 0x7,
		kWaitForTaskQueue = 0x8
	};
}
