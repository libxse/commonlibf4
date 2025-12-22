#pragma once

#include "RE/A/ActionInput.h"
#include "RE/B/BSInputEventReceiver.h"
#include "RE/B/BSPointerHandle.h"
#include "RE/B/BSSpinLock.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTEvent.h"
#include "RE/B/BSTSingleton.h"
#include "RE/H/HeldStateHandler.h"
#include "RE/I/IMovementPlayerControls.h"
#include "RE/P/PlayerInputHandler.h"

namespace RE
{
	enum class DEFAULT_OBJECT;
	class ActivateHandler;
	class AttackBlockHandler;
	class AutoMoveHandler;
	class GrabRotationHandler;
	class JumpHandler;
	class LookHandler;
	class MeleeThrowHandler;
	class MenuModeChangeEvent;
	class MenuOpenCloseEvent;
	class MovementHandler;
	class QuickContainerStateEvent;
	class ReadyWeaponHandler;
	class RunHandler;
	class SneakHandler;
	class SprintHandler;
	class TogglePOVHandler;
	class ToggleRunHandler;
	class UserEventEnabledEvent;
	class TESFurnitureEvent;

	class __declspec(novtable) PlayerControls :
		public BSInputEventReceiver,                    // 000
		public BSTEventSink<MenuOpenCloseEvent>,        // 010
		public BSTEventSink<MenuModeChangeEvent>,       // 018
		public BSTEventSink<TESFurnitureEvent>,         // 020
		public BSTEventSink<UserEventEnabledEvent>,     // 028
		public IMovementPlayerControls,                 // 030
		public BSTEventSink<QuickContainerStateEvent>,  // 038
		public BSTSingletonSDM<PlayerControls>          // 040
	{
	public:
		static constexpr auto RTTI{ RTTI::PlayerControls };
		static constexpr auto VTABLE{ VTABLE::PlayerControls };

		enum class LERP_GRAPH
		{
			kMovementThird = 0x0,
			kMovementFirst = 0x1,
			kLooking = 0x2
		};

		static PlayerControls* GetSingleton()
		{
			static REL::Relocation<PlayerControls**> singleton{ ID::PlayerControls::Singleton };
			return *singleton;
		}

		bool DoAction(DEFAULT_OBJECT a_action, ActionInput::ACTIONPRIORITY a_priority)
		{
			using func_t = decltype(&PlayerControls::DoAction);
			static REL::Relocation<func_t> func{ ID::PlayerControls::DoAction };
			return func(this, a_action, a_priority);
		}

		void RegisterHandler(PlayerInputHandler* a_handler) { DoRegisterHandler(a_handler, false); }
		void RegisterHandler(HeldStateHandler* a_handler) { DoRegisterHandler(a_handler, true); }

		// members
		PlayerControlsData            data;                    // 044
		BSTArray<PlayerInputHandler*> handlers;                // 090
		BSTArray<HeldStateHandler*>   heldStateHandlers;       // 0A8
		std::uint32_t                 topGraphPoint[3];        // 0C0
		float                         graphPoints[3][10][2];   // 0CC
		BSTArray<ActorHandle>         actionInterestedActors;  // 1C0
		BSSpinLock                    actorArraySpinLock;      // 1D8
		MovementHandler*              movementHandler;         // 1E0
		LookHandler*                  lookHandler;             // 1E8
		SprintHandler*                sprintHandler;           // 1F0
		ReadyWeaponHandler*           readyWeaponHandler;      // 1F8
		AutoMoveHandler*              autoMoveHandler;         // 200
		ToggleRunHandler*             toggleRunHandler;        // 208
		ActivateHandler*              activateHandler;         // 210
		JumpHandler*                  jumpHandler;             // 218
		AttackBlockHandler*           attackHandler;           // 220
		RunHandler*                   runHandler;              // 228
		SneakHandler*                 sneakHandler;            // 230
		TogglePOVHandler*             togglePOVHandler;        // 238
		MeleeThrowHandler*            meleeThrowHandler;       // 240
		GrabRotationHandler*          grabRotationHandler;     // 248
		bool                          notifyingHandlers;       // 250
		bool                          blockPlayerInput;        // 251
		float                         cameraAutoRotationX;     // 254
		float                         cameraAutoRotationY;     // 258

	private:
		void DoRegisterHandler(PlayerInputHandler* a_handler, bool a_isHeldStateHandler)
		{
			using func_t = decltype(&PlayerControls::DoRegisterHandler);
			static REL::Relocation<func_t> func{ ID::PlayerControls::DoRegisterHandler };
			return func(this, a_handler, a_isHeldStateHandler);
		}
	};
	static_assert(sizeof(PlayerControls) == 0x260);
}
