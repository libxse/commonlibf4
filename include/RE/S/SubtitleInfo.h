#pragma once

#include "RE/S/SUBTITLE_PRIORITY.h"

namespace RE
{
	class SubtitleInfo
	{
	public:
		// members
		ObjectRefHandle              speaker;         // 00
		BSFixedStringCS              subtitleText;    // 08
		TESTopicInfo*                topicInfo;       // 10
		REX::Enum<SUBTITLE_PRIORITY> priority;        // 18
		float                        distFromPlayer;  // 1C
	};
	static_assert(sizeof(SubtitleInfo) == 0x20);
}
