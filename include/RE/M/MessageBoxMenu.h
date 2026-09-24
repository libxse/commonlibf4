#pragma once

#include "RE/B/BSTEvent.h"
#include "RE/G/GameMenuBase.h"

namespace RE
{
	class MenuModeChangeEvent;
	class MessageBoxData;

	class __declspec(novtable) MessageBoxMenu :
		public GameMenuBase,                      // 00
		public BSTEventSink<MenuModeChangeEvent>  // E0
	{
	public:
		static constexpr auto RTTI{ RTTI::MessageBoxMenu };
		static constexpr auto VTABLE{ VTABLE::MessageBoxMenu };
		static constexpr auto MENU_NAME{ "MessageBoxMenu"sv };

		// override
		virtual void               Call(const Params&) override;         // 01
		virtual void               MapCodeObjectFunctions() override;    // 02
		virtual UI_MESSAGE_RESULTS ProcessMessage(UIMessage&) override;  // 03

		void ShowMessage()
		{
			using func_t = decltype(&MessageBoxMenu::ShowMessage);
			static REL::Relocation<func_t> func{ ID::MessageBoxMenu::ShowMessage };
			return func(this);
		}

		// members
		bool            hasCancelButton;    // E8
		MessageBoxData* currentMessage;     // F0
		std::int32_t    cancelButtonIndex;  // F8
	};
	static_assert(sizeof(MessageBoxMenu) == 0x100);
}
