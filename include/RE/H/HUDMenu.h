#pragma once

#include "RE/B/BSTEvent.h"
#include "RE/G/GameMenuBase.h"

namespace RE
{
	class HUDComponentBase;
	class RequestHUDModesEvent;
	class UserEventEnabledEvent;

	class __declspec(novtable) HUDMenu :
		public GameMenuBase,                         // 000
		public BSTEventSink<UserEventEnabledEvent>,  // 0E0
		public BSTEventSink<RequestHUDModesEvent>    // 0E8
	{
	public:
		static constexpr auto RTTI{ RTTI::HUDMenu };
		static constexpr auto VTABLE{ VTABLE::HUDMenu };
		static constexpr auto MENU_NAME{ "HUDMenu"sv };

		enum class ShowMenuState
		{
			kConstructed = 0x0,
			kShown = 0x1,
			kHidden = 0x2,
			kReshowOnDestructor = 0x3
		};

		void SetHUDColor()
		{
			using func_t = decltype(&HUDMenu::SetHUDColor);
			REL::Relocation<func_t> func{ ID::HUDMenu::SetHUDColor };
			return func(this);
		}

		// members
		BSTSmallArray<std::unique_ptr<HUDComponentBase>, 32> hudObjects;        // 0F0
		BSTArray<HUDModeType>                                hudModes;          // 200
		REX::TEnumSet<ShowMenuState, std::uint32_t>          hudShowMenuState;  // 218
	};
	static_assert(sizeof(HUDMenu) == 0x220);
}
