#pragma once

#include "RE/B/BSInputEventReceiver.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTSingleton.h"
#include "RE/S/ScreenshotHandler.h"

namespace RE
{
	class BSInputEventUser;
	class CameraZoomHandler;
	class ClickHandler;
	class DisconnectHandler;
	class GFxConvertHandler;
	class MenuOpenHandler;
	class PipboyHandler;
	class QuickSaveLoadHandler;

	class MenuControls :
		public BSInputEventReceiver,          // 00
		public BSTSingletonSDM<MenuControls>  // 10
	{
	public:
		[[nodiscard]] static MenuControls* GetSingleton()
		{
			static REL::Relocation<MenuControls**> singleton{ ID::MenuControls::Singleton };
			return *singleton;
		}

		void ForcePauseGame() const
		{
			using func_t = decltype(&MenuControls::ForcePauseGame);
			static REL::Relocation<func_t> func{ ID::MenuControls::ForcePauseGame };
			func(this);
		}

		void ForceResumeGame() const
		{
			using func_t = decltype(&MenuControls::ForceResumeGame);
			static REL::Relocation<func_t> func{ ID::MenuControls::ForceResumeGame };
			func(this);
		}

		[[nodiscard]] bool IsScreenshotQueued()
		{
			using func_t = decltype(&MenuControls::IsScreenshotQueued);
			static REL::Relocation<func_t> func{ ID::MenuControls::IsScreenshotQueued };
			return func(this);
		}

		bool QueueScreenshot() const
		{
			if (!screenshotHandler || screenshotHandler->screenshotQueued) {
				return false;
			}

			screenshotHandler->screenshotQueued = true;

			return true;
		}

		void RegisterHandler(BSInputEventUser* a_handler)
		{
			using func_t = decltype(&MenuControls::RegisterHandler);
			static REL::Relocation<func_t> func{ ID::MenuControls::RegisterHandler };
			func(this, a_handler);
		}

		void UnregisterHandler(BSInputEventUser* a_handler)
		{
			using func_t = decltype(&MenuControls::UnregisterHandler);
			static REL::Relocation<func_t> func{ ID::MenuControls::UnregisterHandler };
			func(this, a_handler);
		}

		// members
		BSTArray<BSInputEventUser*> handlers;              // 18
		GFxConvertHandler*          convertHandler;        // 30
		DisconnectHandler*          disconnectHandler;     // 38
		ClickHandler*               clickHandler;          // 40
		QuickSaveLoadHandler*       quickSaveLoadHandler;  // 48
		MenuOpenHandler*            menuOpenHandler;       // 50
		ScreenshotHandler*          screenshotHandler;     // 58
		CameraZoomHandler*          cameraZoomHandler;     // 60
		PipboyHandler*              pipboyHandler;         // 68
	};
	static_assert(sizeof(MenuControls) == 0x70);
}
