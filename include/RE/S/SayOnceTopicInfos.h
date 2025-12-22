#pragma once

namespace RE
{
	class TESTopicInfo;

	class SayOnceTopicInfos
	{
	public:
		// members
		TESTopicInfo* info;       // 00
		std::int32_t  dateStamp;  // 08
		float         hourStamp;  // 0C
	};
	static_assert(sizeof(SayOnceTopicInfos) == 0x10);
}
