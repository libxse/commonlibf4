#pragma once

#include "RE/B/BGSActorEvent.h"

namespace RE
{
	class BGSActorCellEvent :
		public BGSActorEvent
	{
	public:
		enum class CellFlag
		{
			kEnter = 0x0,
			kLeave = 0x1
		};

		// members
		std::uint32_t                          cellID;  // 04
		REX::TEnumSet<CellFlag, std::uint32_t> flags;   // 08
	};
	static_assert(sizeof(BGSActorCellEvent) == 0xC);
}
