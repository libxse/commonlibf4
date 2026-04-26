#pragma once

#include "RE/N/NiPoint.h"

namespace RE
{
	class BSLensFlareSpriteData
	{
	public:
		enum class Flags
		{
			kRotates = 0x1,
			kShrinks = 0x2
		};

		// members
		NiColor                             color;        // 00
		float                               width;        // 0C
		float                               height;       // 10
		float                               position;     // 14
		float                               angularFade;  // 18
		float                               opacity;      // 1C;
		REX::TEnumSet<Flags, std::uint32_t> flags;        // 20
	};
	static_assert(sizeof(BSLensFlareSpriteData) == 0x24);
}
