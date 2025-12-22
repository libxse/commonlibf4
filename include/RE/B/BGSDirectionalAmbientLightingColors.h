#pragma once

namespace RE
{
	class BGSDirectionalAmbientLightingColors
	{
	public:
		enum class ColorIndex : std::uint32_t
		{
			kXPos = 0x0,
			kXNeg = 0x1,
			kYPos = 0x2,
			kYNeg = 0x3,
			kZPos = 0x4,
			kZNeg = 0x5,
			kAxisCount = 0x6,
			kSpecularTint = 0x6,
			kColorCount = 0x7
		};

		// members
		std::uint32_t colorValues[7];  // 00
		float         fresnelPower;    // 1C
	};
	static_assert(sizeof(BGSDirectionalAmbientLightingColors) == 0x20);
}
