#pragma once

#include "RE/B/BSPackedTaskQueue.h"
#include "RE/B/BSPointerHandle.h"
#include "RE/B/BSSaveDataSystemUtilityImage.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTEvent.h"
#include "RE/B/BSTTuple.h"
#include "RE/N/NiPointer.h"
#include "RE/S/ScrapHeap.h"

namespace RE
{
	class NiCamera;
	class SceneGraph;
	class TESPageCache;
	class PositionPlayerEvent;

	class Main :
		public BSTEventSink<PositionPlayerEvent>
	{
	public:
		virtual ~Main();  // 00

		[[nodiscard]] static Main* GetSingleton()
		{
			static REL::Relocation<Main**> singleton{ ID::Main::Singleton };
			return *singleton;
		}

		// override
		virtual BSEventNotifyControl ProcessEvent(const PositionPlayerEvent& a_event, BSTEventSource<PositionPlayerEvent>* a_source) override;  // 01

		[[nodiscard]] static NiCamera* WorldRootCamera()
		{
			using func_t = decltype(&Main::WorldRootCamera);
			static REL::Relocation<func_t> func{ ID::Main::WorldRootCamera };
			return func();
		}

		[[nodiscard]] static SceneGraph* WorldRootNode()
		{
			static REL::Relocation<NiPointer<SceneGraph>*> nodePtr{ ID::Main::WorldRootCamera };
			return nodePtr->get();
		}

		[[nodiscard]] static bool QGameSystemsShouldUpdate()
		{
			static REL::Relocation<bool*> singleton{ ID::Main::QGameSystemsShouldUpdate };
			return *singleton;
		}

		[[nodiscard]] static bool QGameDataLoaded()
		{
			static REL::Relocation<bool*> singleton{ ID::Main::QGameDataLoaded };
			return *singleton;
		}

		void SetCameraFOV(float a_fov)
		{
			using func_t = decltype(&Main::SetCameraFOV);
			static REL::Relocation<func_t> func{ ID::Main::SetCameraFOV };
			return func(this, a_fov);
		}

		// members
		BSTArray<BSTTuple<float, ActorHandle>> sortedVisibleHighActors;      // 08
		std::uint32_t                          localMapRenderDelay;          // 20
		bool                                   quitGame;                     // 24
		bool                                   resetGame;                    // 25
		bool                                   fullReset;                    // 26
		bool                                   gameActive;                   // 27
		bool                                   onIdle;                       // 28
		bool                                   reloadContent;                // 29
		bool                                   freezeTime;                   // 2A
		bool                                   freezeNextFrame;              // 2B
		REX::W32::HWND                         hwnd;                         // 30
		void*                                  instance;                     // 38
		std::uint32_t                          threadID;                     // 40
		ScrapHeap                              packedTaskHeap;               // 48
		BSPackedTaskQueue                      taskQueue;                    // D8
		ScrapHeap                              secondaryPackedTaskHeap;      // 108
		BSPackedTaskQueue                      secondaryTaskQueue;           // 198
		TESPageCache*                          pageCache;                    // 1C8
		bool                                   inMenuMode;                   // 1D0
		bool                                   inDialog;                     // 1D1
		bool                                   renderingMenuBG;              // 1D2
		bool                                   signOutPending;               // 1D3
		BSSaveDataSystemUtilityImage           saveDataBackgroundImages[3];  // 1D8
		BSSaveDataSystemUtilityImage           saveDataIconImages[3];        // 220
	};
	static_assert(sizeof(Main) == 0x268);
}
