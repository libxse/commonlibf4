#pragma once

namespace RE
{
	class BSPathingSearchParameters
	{
	public:
		enum Flags : std::uint16_t
		{
			kAllowIncompletePath = 0x1,
			kGoDirectIfPathingFails = 0x2,
			kIgnoreSmoothingIfFails = 0x4,
			kUsePrefferedPath = 0x8,
			kRequiresHavok = 0x10,
			kAvoidPreferredPath = 0x20,
			kMustQueue = 0x40,
			kCanShortcut = 0x80,
			kAllowUnattachedCell = 0x100,
			kProcessSynchronously = 0x200,
			kResolveGoalToClosest = 0x400
		};

		float                               preferredCostFactor;     // 00
		float                               tangentSmoothingFactor;  // 04
		std::uint16_t                       retryCount;              // 08
		REX::TEnumSet<Flags, std::uint16_t> flags;                   // 0A
	};
	static_assert(sizeof(BSPathingSearchParameters) == 0x0C);
}
