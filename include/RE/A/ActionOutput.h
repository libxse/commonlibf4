#pragma once

#include "RE/B/BSFixedString.h"

namespace RE
{
	class TESIdleForm;

	class ActionOutput
	{
	public:
		static constexpr auto RTTI{ RTTI::ActionOutput };

		enum class ACTION_RESULTS : std::uint32_t
		{
			kNotAllowed = 0xFFFFFFFF
		};

		// members
		BSFixedString      animEvent;        // 00
		BSFixedString      targetAnimEvent;  // 08
		std::int32_t       result;           // 10
		TESIdleForm*       sequence;         // 18
		const TESIdleForm* animObjIdle;      // 20
		std::uint32_t      sequenceIndex;    // 28;
	};
	static_assert(sizeof(ActionOutput) == 0x30);
}
