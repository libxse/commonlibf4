#pragma once

#include "RE/R/REGION_DATA_ID.h"

namespace RE
{
	class REGION_DATA_BASE
	{
	public:
		// members
		REGION_DATA_ID dataTypeID;  // 00
		bool           override;    // 04
		std::uint8_t   priority;    // 05
	};
	static_assert(sizeof(REGION_DATA_BASE) == 0x8);
}
