#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/M/MemoryManager.h"
#include "RE/U/UI_MESSAGE_TYPE.h"

namespace RE
{
	class IUIMessageData;

	class __declspec(novtable) UIMessage
	{
	public:
		static constexpr auto RTTI{ RTTI::UIMessage };
		static constexpr auto VTABLE{ VTABLE::UIMessage };

		virtual ~UIMessage() = default;  // 00

		virtual IUIMessageData*       QData() { return nullptr; }        // 02
		virtual const IUIMessageData* QData() const { return nullptr; }  // 01

		F4_HEAP_REDEFINE_NEW(UIMessage);

		// members
		BSFixedString                                menu;                             // 08
		REX::TEnumSet<UI_MESSAGE_TYPE, std::int32_t> type{ UI_MESSAGE_TYPE::kTotal };  // 10
	};
	static_assert(sizeof(UIMessage) == 0x18);
}
