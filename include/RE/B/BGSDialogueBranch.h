#pragma once

#include "RE/T/TESForm.h"

namespace RE
{
	enum class DIALOGUE_TYPE;

	class __declspec(novtable) BGSDialogueBranch :
		public TESForm  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSDialogueBranch };
		static constexpr auto VTABLE{ VTABLE::BGSDialogueBranch };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kDLBR };

		enum class Flag
		{
			kTopLevel = 0x0,
			kBlocking = 0x1,
			kExclusive = 0x2
		};

		// members
		std::uint32_t                             flags;          // 20
		TESQuest*                                 quest;          // 28
		TESTopic*                                 startingTopic;  // 30
		REX::EnumSet<DIALOGUE_TYPE, std::int32_t> type;           // 38
	};
	static_assert(sizeof(BGSDialogueBranch) == 0x40);
}
