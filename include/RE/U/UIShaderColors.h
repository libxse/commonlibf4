#pragma once

#include "RE/N/NiColor.h"
#include "RE/N/NiRect.h"

namespace RE
{
	class UIShaderColors
	{
	public:
		enum class Flags
		{
			kBackgroundQuad = 1u << 0,
			kColorMultiplier = 1u << 1,
			kVerticalGradient = 1u << 2,
			kUseAlphaForDropshadow = 1u << 3
		};

		// members
		NiRect<float>                       backgroundQuad;    // 00
		NiColorA                            backgroundColor;   // 10
		NiColorA                            colorMultipliers;  // 20
		float                               colorBrightness;   // 30
		REX::TEnumSet<Flags, std::uint32_t> enabledStates;     // 34
	};
	static_assert(sizeof(UIShaderColors) == 0x38);
}
