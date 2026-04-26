#pragma once

#include "RE/B/BSTArray.h"
#include "RE/H/HUDModeType.h"

namespace RE
{
	enum class POWER_ARMOR_HUD_VISIBILITY_RULE;

	class HUDModes
	{
	public:
		// members
		BSTArray<HUDModeType>                                         validHUDModes;                // 00
		REX::TEnumSet<POWER_ARMOR_HUD_VISIBILITY_RULE, std::uint32_t> powerArmorHUDVisibilityRule;  // 18
		bool                                                          canBeVisible;                 // 1C
	};
	static_assert(sizeof(HUDModes) == 0x20);
}
