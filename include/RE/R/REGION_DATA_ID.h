#pragma once

namespace RE
{
	enum class REGION_DATA_ID : std::uint32_t
	{
		kNone = 0x0,
		kGeneralID = 0x1,
		kObjectsID = 0x2,
		kWeatherID = 0x3,
		kMapID = 0x4,
		kLandscapeID = 0x5,
		kGrassID = 0x6,
		kSoundID = 0x7,

		kTotal = 0x8
	};
}
