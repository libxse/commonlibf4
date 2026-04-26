#pragma once

namespace RE
{
	class CellAttachDetachEvent
	{
	public:
		enum class EVENT_TYPE : std::int32_t
		{
			kPreAttach = 0x0,
			kPostAttach = 0x1,
			kPreDetach = 0x2,
			kPostDetach = 0x3
		};

		// members
		TESObjectCELL*                          cell;  // 00
		REX::TEnumSet<EVENT_TYPE, std::int32_t> type;  // 08
	};
	static_assert(sizeof(CellAttachDetachEvent) == 0x10);
}
