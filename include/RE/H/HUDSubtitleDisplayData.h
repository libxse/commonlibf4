#pragma once

#include "RE/B/BSFixedString.h"

namespace RE
{
	class HUDSubtitleDisplayData
	{
	public:
		// members
		BSFixedStringCS speakerName;   // 00
		BSFixedStringCS subtitleText;  // 08
	};
	static_assert(sizeof(HUDSubtitleDisplayData) == 0x10);
}
