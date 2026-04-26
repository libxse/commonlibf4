#pragma once

#include "RE/B/BSScaleformExternalTexture.h"
#include "RE/B/BSSoundHandle.h"
#include "RE/B/BSTHashMap.h"
#include "RE/B/BSTSmartPointer.h"
#include "RE/G/GameMenuBase.h"
#include "RE/N/NiPointer.h"

namespace RE
{
	class NiAVObject;

	namespace REFREventCallbacks
	{
		class IEventCallback;
	}

	class __declspec(novtable) TerminalMenu :
		public GameMenuBase  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::TerminalMenu };
		static constexpr auto VTABLE{ VTABLE::TerminalMenu };
		static constexpr auto MENU_NAME{ "TerminalMenu"sv };

		enum class Mode
		{
			kInit = 0x0,
			kHack = 0x1,
			kLogin = 0x2,
			kList = 0x3,
			kText = 0x4,
			kImage = 0x5,
			kHolotape = 0x6,
			kWaitingForPapyrus = 0x7,
		};

		class ListItem
		{
		public:
			// members
			const BGSTerminal::MenuItem* menuItem;  // 00
			const BGSTerminal*           terminal;  // 08
		};
		static_assert(sizeof(ListItem) == 0x10);

		virtual ~TerminalMenu();  // 00

		// override (GameMenuBase)
		virtual void               Call(const Params&) override;                                     // 01
		virtual void               MapCodeObjectFunctions() override;                                // 02
		virtual UI_MESSAGE_RESULTS ProcessMessage(UIMessage& a_message) override;                    // 03
		virtual void               AdvanceMovie(float a_timeDelta, std::uint64_t a_time) override;   // 04
		virtual bool               CanHandleWhenDisabled(const ButtonEvent* a_event) override;       // 0E
		virtual bool               OnButtonEventRelease(const BSFixedString& a_eventName) override;  // 0F

		// override (BSInputEventUser)
		virtual bool ShouldHandleEvent(const InputEvent* a_event) override;  // 01
		virtual void OnButtonEvent(const ButtonEvent* a_event) override;     // 08

		// members
		Scaleform::GFx::Value                               menuElements[6];             // 0E0
		BSTArray<ListItem>                                  menuItemList;                // 1A0
		BSTArray<NiPointer<NiAVObject>>                     culledObjects;               // 1B8
		BSTArray<BGSTerminal*>                              history;                     // 1D0
		BSTHashMap<void*, std::uint32_t>                    lastSelectionMap;            // 1E8
		BSTSmartPointer<REFREventCallbacks::IEventCallback> terminalRunResultsCallback;  // 218
		BSScaleformExternalTexture                          displayImage;                // 220
		BSSoundHandle                                       charScrollLoop;              // 238
		REX::TEnumSet<Mode, std::uint32_t>                  mode;                        // 240
		std::uint64_t                                       soundMark;                   // 248
		std::uint64_t                                       responseTextTimeout;         // 250
		std::uint64_t                                       loginTextTimeout;            // 258
		bool                                                autoEjectHolotapeOnExit;     // 260
		bool                                                cancelPressRegistered;       // 261
		bool                                                autoLoadHolotape;            // 262
	};
	static_assert(sizeof(TerminalMenu) == 0x268);
}
