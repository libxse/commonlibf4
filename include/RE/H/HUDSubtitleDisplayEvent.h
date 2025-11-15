#pragma once

#include "RE/B/BSTEvent.h"
#include "RE/H/HUDSubtitleDisplayData.h"

namespace RE
{
	class HUDSubtitleDisplayEvent :
		public BSTValueEvent<HUDSubtitleDisplayData>  // 00
	{
	public:
	};
	static_assert(sizeof(HUDSubtitleDisplayEvent) == 0x18);
}
