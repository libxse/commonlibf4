#pragma once

namespace RE
{
	enum class COVER_TYPE : std::uint32_t
	{
		kNone = 0x0,
		kLedge = 0x1,
		kCrouch = 0x2,
		kPartial = 0x2,
		kVeryLow = 0x4,
		kNarrow = 0x3,
		kLow = 0x4,
		kFull = 0x4,
		kMid = 0x5,
		kHigh = 0x6,
		kTypeCount = 0x7,
		kTypeMask = 0xFFFFFF,
		kDirectionLeft = 0x40000000,
		kDirectionRight = 0x80000000,
		kDirectionMask = 0xC0000000
	};
}
