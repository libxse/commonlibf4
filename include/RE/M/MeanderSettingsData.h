#pragma once

#include "RE/N/NiPoint2.h"

namespace RE
{
	class MeanderSettingsData
	{
	public:
		enum MeanderType : std::uint32_t
		{
			kNone = 0x0,
			kStartLeft = 0x1,
			kStartRight = 0x2
		};

		// members
		MeanderType type;             // 00
		NiPoint2    amplituteRange;   // 04
		NiPoint2    wavelengthRange;  // 0C
	};
	static_assert(sizeof(MeanderSettingsData) == 0x14);
}
