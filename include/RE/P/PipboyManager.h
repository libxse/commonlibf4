#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/B/BSInputEventUser.h"
#include "RE/B/BSPointerHandle.h"
#include "RE/B/BSSoundHandle.h"
#include "RE/B/BSTEvent.h"
#include "RE/B/BSTPoint.h"
#include "RE/B/BSTSingleton.h"
#include "RE/I/Inventory3DManager.h"
#include "RE/I/InventoryInterface.h"
#include "RE/I/IsPipboyActiveEvent.h"
#include "RE/N/NiPointer.h"
#include "RE/N/NiRect.h"
#include "RE/P/PipboyRadioController.h"

namespace RE
{
	class BSTriShape;
	class IMenu;
	class BSAnimationGraphEvent;

	class __declspec(novtable) PipboyManager :
		public BSTEventSink<BSAnimationGraphEvent>,  // 00
		public BSInputEventUser,                     // 08
		public BSTSingletonSDM<PipboyManager>        // 18
	{
	public:
		static constexpr auto RTTI{ RTTI::PipboyManager };
		static constexpr auto VTABLE{ VTABLE::PipboyManager };

		enum class LOWER_REASON
		{
			kNone = 0x0,
			kBook = 0x1,
			kPerkGrid = 0x2,
			kInspect = 0x3
		};

		enum class PipboyScreenEffectTriggerType
		{
			kPipboyOpen = 0x0,
			kTabChange = 0x1,
			kCategoryChange = 0x2,
			kSmallTransition = 0x3,
			kMapChange = 0x4
		};

		virtual ~PipboyManager();  // 00

		// override
		virtual BSEventNotifyControl ProcessEvent(const BSAnimationGraphEvent& a_event, BSTEventSource<BSAnimationGraphEvent>* a_source) override;  // 01
		virtual bool                 ShouldHandleEvent(const InputEvent*) override;                                                                 // 02
		virtual void                 OnButtonEvent(const ButtonEvent*) override;                                                                    // 09
		virtual void                 OnMouseMoveEvent(const MouseMoveEvent*) override;                                                              // 07
		virtual void                 OnThumbstickEvent(const ThumbstickEvent*) override;                                                            // 05

		[[nodiscard]] static PipboyManager* GetSingleton()
		{
			static REL::Relocation<PipboyManager**> singleton{ ID::PipboyManager::Singleton };
			return *singleton;
		}

		void AddMenuToPipboy(IMenu& a_menu, const NiRect<float>& a_standVP, const NiRect<float>& a_powerVP)
		{
			using func_t = decltype(&PipboyManager::AddMenuToPipboy);
			static REL::Relocation<func_t> func{ ID::PipboyManager::AddMenuToPipboy };
			func(this, a_menu, a_standVP, a_powerVP);
		}

		void ClosedownPipboy()
		{
			using func_t = decltype(&PipboyManager::ClosedownPipboy);
			static REL::Relocation<func_t> func{ ID::PipboyManager::ClosedownPipboy };
			func(this);
		}

		void EnablePipboyShader()
		{
			using func_t = decltype(&PipboyManager::EnablePipboyShader);
			static REL::Relocation<func_t> func{ ID::PipboyManager::EnablePipboyShader };
			func(this);
		}

		void InitPipboy()
		{
			using func_t = decltype(&PipboyManager::InitPipboy);
			static REL::Relocation<func_t> func{ ID::PipboyManager::InitPipboy };
			func(this);
		}

		void LowerPipboy(LOWER_REASON a_reason)
		{
			using func_t = decltype(&PipboyManager::LowerPipboy);
			static REL::Relocation<func_t> func{ ID::PipboyManager::LowerPipboy };
			func(this, a_reason);
		}

		void OnPipboyCloseAnim()
		{
			using func_t = decltype(&PipboyManager::OnPipboyCloseAnim);
			static REL::Relocation<func_t> func{ ID::PipboyManager::OnPipboyCloseAnim };
			func(this);
		}

		void OnPipboyCloseAnimFailed()
		{
			using func_t = decltype(&PipboyManager::OnPipboyCloseAnimFailed);
			static REL::Relocation<func_t> func{ ID::PipboyManager::OnPipboyCloseAnimFailed };
			func(this);
		}

		void OnPipboyClosed()
		{
			using func_t = decltype(&PipboyManager::OnPipboyClosed);
			static REL::Relocation<func_t> func{ ID::PipboyManager::OnPipboyClosed };
			func(this);
		}

		void OnPipboyOpenAnim()
		{
			using func_t = decltype(&PipboyManager::OnPipboyOpenAnim);
			static REL::Relocation<func_t> func{ ID::PipboyManager::OnPipboyOpenAnim };
			func(this);
		}

		void OnPipboyOpenAnimFailed()
		{
			using func_t = decltype(&PipboyManager::OnPipboyOpenAnimFailed);
			static REL::Relocation<func_t> func{ ID::PipboyManager::OnPipboyOpenAnimFailed };
			func(this);
		}

		void OnPipboyOpened()
		{
			using func_t = decltype(&PipboyManager::OnPipboyOpened);
			static REL::Relocation<func_t> func{ ID::PipboyManager::OnPipboyOpened };
			func(this);
		}

		void PlayItemAnimOnClose()
		{
			using func_t = decltype(&PipboyManager::PlayItemAnimOnClose);
			static REL::Relocation<func_t> func{ ID::PipboyManager::PlayItemAnimOnClose };
			func(this);
		}

		void PlayPipboyCloseAnim(bool a_noAnim)
		{
			using func_t = decltype(&PipboyManager::PlayPipboyCloseAnim);
			static REL::Relocation<func_t> func{ ID::PipboyManager::PlayPipboyCloseAnim };
			func(this, a_noAnim);
		}

		void PlayPipboyGenericOpenAnim(const BSFixedString& a_menu, const BSFixedString& a_anim, bool a_noAnim)
		{
			using func_t = decltype(&PipboyManager::PlayPipboyGenericOpenAnim);
			static REL::Relocation<func_t> func{ ID::PipboyManager::PlayPipboyGenericOpenAnim };
			func(this, a_menu, a_anim, a_noAnim);
		}

		void PlayPipboyLoadHolotapeAnim(BGSNote* a_holotape, bool a_noAnim)
		{
			using func_t = decltype(&PipboyManager::PlayPipboyLoadHolotapeAnim);
			static REL::Relocation<func_t> func{ ID::PipboyManager::PlayPipboyLoadHolotapeAnim };
			func(this, a_holotape, a_noAnim);
		}

		void PlayPipboyOpenAnim(const BSFixedString& a_menuName)
		{
			using func_t = decltype(&PipboyManager::PlayPipboyOpenAnim);
			static REL::Relocation<func_t> func{ ID::PipboyManager::PlayPipboyOpenAnim };
			func(this, a_menuName);
		}

		void PlayPipboyOpenTerminalAnim(BGSTerminal* a_terminal)
		{
			using func_t = decltype(&PipboyManager::PlayPipboyOpenTerminalAnim);
			static REL::Relocation<func_t> func{ ID::PipboyManager::PlayPipboyOpenTerminalAnim };
			func(this, a_terminal);
		}

		void ProcessLoweringReason()
		{
			using func_t = decltype(&PipboyManager::ProcessLoweringReason);
			static REL::Relocation<func_t> func{ ID::PipboyManager::ProcessLoweringReason };
			func(this);
		}

		bool QPipboyActive()
		{
			using func_t = decltype(&PipboyManager::QPipboyActive);
			static REL::Relocation<func_t> func{ ID::PipboyManager::QPipboyActive };
			return func(this);
		}

		void RaisePipboy()
		{
			using func_t = decltype(&PipboyManager::RaisePipboy);
			static REL::Relocation<func_t> func{ ID::PipboyManager::RaisePipboy };
			func(this);
		}

		void RefreshPipboyRenderSurface()
		{
			using func_t = decltype(&PipboyManager::RefreshPipboyRenderSurface);
			static REL::Relocation<func_t> func{ ID::PipboyManager::RefreshPipboyRenderSurface };
			func(this);
		}

		void StartAnimationGraphListening()
		{
			using func_t = decltype(&PipboyManager::StartAnimationGraphListening);
			static REL::Relocation<func_t> func{ ID::PipboyManager::StartAnimationGraphListening };
			func(this);
		}

		void StopAnimationGraphListening()
		{
			using func_t = decltype(&PipboyManager::StopAnimationGraphListening);
			static REL::Relocation<func_t> func{ ID::PipboyManager::StopAnimationGraphListening };
			func(this);
		}

		void UpdateCursorConstraint(bool a_enable)
		{
			using func_t = decltype(&PipboyManager::UpdateCursorConstraint);
			static REL::Relocation<func_t> func{ ID::PipboyManager::UpdateCursorConstraint };
			func(this, a_enable);
		}

		// members
		BSSoundHandle                             pipboyHumSound;          // 01C
		BSTPoint2<float>                          inputVector;             // 024
		BSTPoint2<float>                          newInput;                // 02C
		NiPointer<BSTriShape>                     debugModeGeom;           // 038
		Inventory3DManager                        inv3DModelManager;       // 040
		BGSNote*                                  holotapeToLoad;          // 180
		BGSTerminal*                              terminalToLoad;          // 188
		BSFixedString                             menuToOpen;              // 190
		BSFixedString                             openAnimEvent;           // 198
		BSFixedString                             closeAnimEvent;          // 1A0
		REX::TEnumSet<LOWER_REASON, std::int32_t> loweringReason;          // 1A8
		PipboyRadioController                     radioController;         // 1AC
		TESBoundObject*                           itemAnimOnClose;         // 1B0
		ObjectRefHandle                           fastTravelLocation;      // 1B8
		InventoryInterface::Handle                inspectRequestItem;      // 1BC
		std::uint32_t                             inspectRequestStack;     // 1C0
		bool                                      pipboyExamineMode;       // 1C4
		bool                                      pipboyExamineDirtyFlag;  // 1C5
		bool                                      pipboyOpening;           // 1C6
		bool                                      pipboyClosing;           // 1C7
		BSTValueEventSource<IsPipboyActiveEvent>  pipboyActive;            // 1C8
		bool                                      ignoreOpeningFlag;       // 1E0
		bool                                      autoSaveOnClose;         // 1E1
		bool                                      pipboyMenuCloseQueued;   // 1E2
		bool                                      pipboyRaising;           // 1E3
		bool                                      wasMotionBlurActive;     // 1E4
		bool                                      wasPipboyLightActive;    // 1E5
	};
	static_assert(sizeof(PipboyManager) == 0x1F0);
}
