#pragma once

#include "RE/N/NiPoint.h"

namespace RE
{
	class PlayerCoverData
	{
	public:
		enum class PEEK_STATE;

		// members
		NiPoint3                                coverLocation;  // 00
		NiPoint3                                peekLocation;   // 0C
		float                                   peekTimer;      // 18
		float                                   updateTimer;    // 2C
		float                                   blockedTimer;   // 20
		REX::TEnumSet<PEEK_STATE, std::int32_t> peekState;      // 24
		bool                                    gunBlocked;     // 28
	};
	static_assert(sizeof(PlayerCoverData) == 0x2C);
}
