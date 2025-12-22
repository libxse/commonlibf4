#pragma once

#include "RE/P/POWER_ARMOR_HUD_VISIBILITY_RULE.h"

namespace RE
{
	class HUDModeType;

	class HUDModeInitParams
	{
	public:
		// members
		const HUDModeType*              validHUDModes;                // 00
		std::uint32_t                   numHUDModes;                  // 08
		POWER_ARMOR_HUD_VISIBILITY_RULE powerArmorHUDVisibilityRule;  // 0C
	};
	static_assert(sizeof(HUDModeInitParams) == 0x10);
}
