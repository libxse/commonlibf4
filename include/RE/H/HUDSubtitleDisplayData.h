#pragma once

#include "RE/B/BSFixedString.h"

namespace RE
{
	class HUDSubtitleDisplayData
	{
	public:
		bool operator==(const HUDSubtitleDisplayData& a_rhs) { return speakerName == a_rhs.speakerName && subtitleText == a_rhs.subtitleText; }

		bool operator!=(const HUDSubtitleDisplayData& a_rhs) { return !operator==(a_rhs); }

		// members
		BSFixedStringCS speakerName;   // 00
		BSFixedStringCS subtitleText;  // 08
	};
	static_assert(sizeof(HUDSubtitleDisplayData) == 0x10);
}
