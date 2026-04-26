#pragma once

namespace RE
{
	class QUEST_STAGE_DATA
	{
	public:
		enum class Flags
		{
			kDone = 0x1,
			kStartUp = 0x2,
			kShutDown = 0x4,
			kKeepInstance = 0x8
		};

		// members
		std::uint16_t                                        index;  // 00
		REX::TEnumSet<QUEST_STAGE_DATA::Flags, std::uint8_t> flags;  // 02
	};
	static_assert(sizeof(QUEST_STAGE_DATA) == 0x4);
}
