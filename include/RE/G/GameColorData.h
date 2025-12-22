#pragma once

#include "RE/N/NiColor.h"

namespace RE
{
	class GameColorData
	{
	public:
		// members
		NiColor gameplayHUDColor;            // 00
		NiColor playerSetColor;              // 0C
		NiColor powerArmorHUDColor;          // 18
		NiColor HUDWarningColor;             // 24
		NiColor HUDAltWarningColor;          // 30
		NiColor playerSetBackgroundColor;    // 3C
		NiColor powerArmorBackgroundColor;   // 48
		NiColor gameplayHUDBackgroundColor;  // 54
	};
	static_assert(sizeof(GameColorData) == 0x60);
}
