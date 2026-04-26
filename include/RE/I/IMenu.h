#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/B/BSInputEventUser.h"
#include "RE/B/BSTAtomicValue.h"
#include "RE/B/ButtonEvent.h"
#include "RE/N/NiRect.h"
#include "RE/S/SWFToCodeFunctionHandler.h"
#include "RE/U/UIMessage.h"
#include "RE/U/UI_DEPTH_PRIORITY.h"
#include "RE/U/UI_MENU_FLAGS.h"
#include "RE/U/UI_MESSAGE_RESULTS.h"
#include "RE/U/UI_MESSAGE_TYPE.h"
#include "RE/U/UserEvents.h"
#include "Scaleform/M/MemoryHeap.h"
#include "Scaleform/P/Ptr.h"
#include "Scaleform/T/ThreadId.h"

namespace RE
{
	enum class MENU_RENDER_CONTEXT;

	class IMenu :
		public SWFToCodeFunctionHandler,  // 00
		public BSInputEventUser           // 10
	{
	public:
		static constexpr auto RTTI{ RTTI::IMenu };
		static constexpr auto VTABLE{ VTABLE::IMenu };

		using SWFToCodeFunctionHandler::operator new;
		using SWFToCodeFunctionHandler::operator delete;

		// NOLINTNEXTLINE(modernize-use-override)
		virtual ~IMenu()  // 00
		{
			if (uiMovie) {
				const auto id = Scaleform::GetCurrentThreadId();
				uiMovie->SetCaptureThread(id);

				const auto heap = uiMovie->GetHeap();
				if (heap) {
					heap->AssignToCurrentThread();
				}
			}
		}

		// override (BSInputEventUser)
		bool ShouldHandleEvent(const InputEvent* a_event) override  // 01
		{
			using func_t = decltype(&IMenu::ShouldHandleEvent);
			static REL::Relocation<func_t> func{ ID::IMenu::ShouldHandleEvent };
			return func(this, a_event);
		}

		void OnButtonEvent(const ButtonEvent* a_event) override  // 08
		{
			if (menuObj.IsObject()) {
				auto strUserEvent = a_event->QUserEvent();
				if (a_event->disabled && CanHandleWhenDisabled(a_event)) {
					strUserEvent = a_event->QRawUserEvent();
				}

				if (inputEventHandlingEnabled && menuObj.HasMember("ProcessUserEvent")) {
					Scaleform::GFx::Value args[2];
					args[0] = strUserEvent.c_str();
					args[1] = a_event->QJustPressed();
					menuObj.Invoke("ProcessUserEvent", nullptr, args, 2);
				}
			}
		}

		// add
		virtual UI_MESSAGE_RESULTS ProcessMessage(UIMessage& a_message)  // 03
		{
			switch (*a_message.type) {
				case UI_MESSAGE_TYPE::kShow:
				case UI_MESSAGE_TYPE::kHide:
					return UI_MESSAGE_RESULTS::kHandled;
				case UI_MESSAGE_TYPE::kScaleformEvent:
					return ProcessScaleformEvent(uiMovie.get(), a_message.QData());
				case UI_MESSAGE_TYPE::kUpdateController:
					RefreshPlatform();
					return UI_MESSAGE_RESULTS::kPassOn;
				default:
					return UI_MESSAGE_RESULTS::kPassOn;
			}
		}

		virtual void AdvanceMovie(float a_timeDelta, [[maybe_unused]] std::uint64_t a_time)  // 04
		{
			if (uiMovie) {
				DoAdvanceMovie(a_timeDelta);
				hasDoneFirstAdvanceMovie = true;
			}
		}

		virtual void PreDisplay() { return; }   // 05
		virtual void PostDisplay() { return; }  // 06

		virtual bool PassesRenderConditionText(MENU_RENDER_CONTEXT a_reason, const BSFixedString& a_customRendererName) const  // 07
		{
			using func_t = decltype(&IMenu::PassesRenderConditionText);
			static REL::Relocation<func_t> func{ ID::IMenu::PassesRenderConditionText };
			return func(this, a_reason, a_customRendererName);
		}

		virtual void SetIsTopButtonBar([[maybe_unused]] bool a_isTopButtonBar) { return; }  // 08

		virtual void OnMenuStackChanged(const BSFixedString& a_topMenuName, bool a_passesTopMenuTest)  // 09
		{
			const bool topMenuTest = a_passesTopMenuTest || (a_topMenuName == "PauseMenu"sv && RendersUnderPauseMenu());
			if (passesTopMenuTest != topMenuTest) {
				passesTopMenuTest = topMenuTest;
				OnMenuDisplayStateChanged();
			}
		}

		virtual void OnMenuDisplayStateChanged() { return; }  // 0A

		virtual void OnAddedToMenuStack()  // 0B
		{
			menuFlags.set(UI_MENU_FLAGS::kOnStack);
			OnMenuDisplayStateChanged();
		}

		virtual void OnRemovedFromMenuStack()  // 0C
		{
			menuFlags.reset(UI_MENU_FLAGS::kOnStack);
			OnMenuDisplayStateChanged();
		}

		virtual bool CanAdvanceMovie(bool a_pauseMenuShowing)  // 0D
		{
			return !a_pauseMenuShowing || depthPriority > UI_DEPTH_PRIORITY::kGameMessage || AdvancesUnderPauseMenu();
		}

		virtual bool CanHandleWhenDisabled([[maybe_unused]] const ButtonEvent* a_event) { return false; }                      // 0E
		virtual bool OnButtonEventRelease([[maybe_unused]] const BSFixedString& a_eventName) { return false; }                 // 0F
		virtual bool CacheShaderFXQuadsForRenderer_Impl() { return false; }                                                    // 10
		virtual void TransferCachedShaderFXQuadsForRenderer([[maybe_unused]] const BSFixedString& a_rendererName) { return; }  // 11
		virtual void SetViewportRect([[maybe_unused]] const NiRect<float>& a_viewportRect) { return; }                         // 12

		[[nodiscard]] bool AdvancesUnderPauseMenu() const noexcept { return menuFlags.all(UI_MENU_FLAGS::kAdvancesUnderPauseMenu); }
		[[nodiscard]] bool AssignsCursorToRenderer() const noexcept { return menuFlags.all(UI_MENU_FLAGS::kAssignCursorToRenderer); }

		void DoAdvanceMovie(float a_timeDelta)
		{
			++advanceWithoutRenderCount;
			uiMovie->Advance(a_timeDelta);
		}

		void OnSetSafeRect()
		{
			using func_t = decltype(&IMenu::OnSetSafeRect);
			static REL::Relocation<func_t> func{ ID::IMenu::OnSetSafeRect };
			return func(this);
		}

		[[nodiscard]] bool OnStack() const noexcept { return menuFlags.all(UI_MENU_FLAGS::kOnStack); }

		UI_MESSAGE_RESULTS ProcessScaleformEvent(Scaleform::GFx::Movie* a_movie, const IUIMessageData* a_data)
		{
			using func_t = decltype(&IMenu::ProcessScaleformEvent);
			static REL::Relocation<func_t> func{ ID::IMenu::ProcessScaleformEvent };
			return func(this, a_movie, a_data);
		}

		void RefreshPlatform()
		{
			using func_t = decltype(&IMenu::RefreshPlatform);
			static REL::Relocation<func_t> func{ ID::IMenu::RefreshPlatform };
			return func(this);
		}

		[[nodiscard]] bool RendersUnderPauseMenu() const noexcept { return menuFlags.all(UI_MENU_FLAGS::kRendersUnderPauseMenu); }

		[[nodiscard]] constexpr bool IsMenuDisplayEnabled() const noexcept { return passesTopMenuTest && menuCanBeVisible; }

		void SetMenuCodeObject(Scaleform::GFx::Movie& a_movie, std::string_view a_menuObjPath)
		{
			a_movie.GetVariable(std::addressof(menuObj), a_menuObjPath.data());
			RegisterCodeObject(a_movie, menuObj);
		}

		void UpdateFlag(UI_MENU_FLAGS a_flag, bool a_set) noexcept
		{
			if (a_set) {
				menuFlags.set(a_flag);
			} else {
				menuFlags.reset(a_flag);
			}
		}

		[[nodiscard]] bool UsesCursor() const noexcept { return menuFlags.all(UI_MENU_FLAGS::kUsesCursor); }

		// members
		Scaleform::GFx::Value                                     menuObj;                                              // 20
		Scaleform::Ptr<Scaleform::GFx::Movie>                     uiMovie;                                              // 40
		BSFixedString                                             customRendererName;                                   // 48
		BSFixedString                                             menuName;                                             // 50
		REX::TEnumSet<UI_MENU_FLAGS, std::uint32_t>               menuFlags;                                            // 58
		BSTAtomicValue<std::uint32_t>                             advanceWithoutRenderCount{ 0 };                       // 5C
		bool                                                      passesTopMenuTest{ true };                            // 60
		bool                                                      menuCanBeVisible{ true };                             // 61
		bool                                                      hasQuadsForCumstomRenderer{ false };                  // 62
		bool                                                      hasDoneFirstAdvanceMovie{ false };                    // 63
		UI_DEPTH_PRIORITY                                         depthPriority{ UI_DEPTH_PRIORITY::kStandard };        // 64
		REX::TEnumSet<UserEvents::INPUT_CONTEXT_ID, std::int32_t> inputContext{ UserEvents::INPUT_CONTEXT_ID::kNone };  // 68
	};
	static_assert(sizeof(IMenu) == 0x70);
}
