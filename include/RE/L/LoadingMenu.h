#pragma once

#include "RE/B/BSModelDB.h"
#include "RE/B/BSSoundHandle.h"
#include "RE/G/GameMenuBase.h"
#include "RE/I/ImageSpaceLUTData.h"
#include "RE/N/NiMatrix3.h"
#include "RE/N/NiPoint.h"

namespace RE
{
	class BGSModelMaterialSwap;
	class NiAVObject;

	class __declspec(novtable) LoadingMenu :
		public GameMenuBase  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::LoadingMenu };
		static constexpr auto VTABLE{ VTABLE::LoadingMenu };
		static constexpr auto MENU_NAME{ "LoadingMenu"sv };

		virtual ~LoadingMenu();  // 00

		// override (GameMenuBase)
		virtual void               Call(const Params&) override;                                     // 01
		virtual void               MapCodeObjectFunctions() override;                                // 02
		virtual UI_MESSAGE_RESULTS ProcessMessage(UIMessage& a_message) override;                    // 03
		virtual void               AdvanceMovie(float a_timeDelta, std::uint64_t a_time) override;   // 04
		virtual bool               OnButtonEventRelease(const BSFixedString& a_eventName) override;  // 0F

		// override (BSInputEventUser)
		virtual bool ShouldHandleEvent(const InputEvent*) override;       // 01
		virtual void OnThumbstickEvent(const ThumbstickEvent*) override;  // 04
		virtual void OnButtonEvent(const ButtonEvent*) override;          // 08

		static void StartTestingLoadMenu()
		{
			using func_t = decltype(&LoadingMenu::StartTestingLoadMenu);
			static REL::Relocation<func_t> func{ ID::LoadingMenu::StartTestingLoadMenu };
			return func();
		}

		void PopulateLoadScreens()
		{
			using func_t = decltype(&LoadingMenu::PopulateLoadScreens);
			static REL::Relocation<func_t> func{ ID::LoadingMenu::PopulateLoadScreens };
			return func(this);
		}

		// members
		BGSLocation*             loadLocation;                      // 0E0
		TESLoadScreen*           artScreen;                         // 0E8
		std::byte                upgrader[0x10];                    // 0F0 - TODO
		BSTArray<TESLoadScreen*> validScreens;                      // 100
		void*                    foregroundModel;                   // 118 - BDModelDB::Handle
		NiAVObject*              zoomTarget;                        // 120
		ImageSpaceLUTData        LUT;                               // 128
		std::uint32_t            numNonDefaultScreens;              // 198
		float                    modelAggregateRotation;            // 19C
		float                    modelMinAggregateRotation;         // 1A0
		float                    modelMaxAggregateRotation;         // 1A4
		float                    frameTimeDelta;                    // 1A8
		float                    currentZoom;                       // 1AC
		float                    minZoom;                           // 1B0
		float                    maxZoom;                           // 1B4
		float                    horizontalBound;                   // 1B8
		float                    verticalBound;                     // 1BC
		float                    verticalBoundOffset;               // 1BC
		alignas(0x10) NiMatrix3 initialRotation;                    // 1D0
		NiPoint2                    calcedPanMaxima;                // 200
		NiPoint2                    calcedPanMinima;                // 208
		std::uint64_t               lastAdvanceMovieTime;           // 210
		std::uint64_t               lastUserInteractTime;           // 218
		std::uint64_t               lastPanTime;                    // 220
		std::uint64_t               lastRotationTime;               // 228
		std::uint64_t               lastZoomTime;                   // 230
		BSSoundHandle               rotationSoundLoop;              // 238
		BSSoundHandle               zoomSoundLoop;                  // 240
		const BGSModelMaterialSwap* modelMaterialSwap;              // 248
		NiPoint3                    modelInitialRotation;           // 250
		NiPoint3                    modelTranslationOffset;         // 25C
		float                       modelScale;                     // 268
		std::uint32_t               numFrames;                      // 26C
		bool                        loadingIntoInterior;            // 270
		bool                        menuAdded;                      // 271
		bool                        leftButtonDown;                 // 272
		bool                        rightButtonDown;                // 273
		bool                        allowRotation;                  // 274
		bool                        autoRotate;                     // 275
		bool                        autoRotateInvert;               // 276
		bool                        holoMode;                       // 277
		bool                        loadScreenShown;                // 278
		bool                        leftStickReady;                 // 279
		bool                        rightStickReady;                // 27A
		bool                        leftStickWasPreviouslyActive;   // 27B
		bool                        rightStickWasPreviouslyActive;  // 27C
		bool                        modelRequested;                 // 27D
		bool                        PCKeysDebounced;                // 27E
	};
	static_assert(sizeof(LoadingMenu) == 0x280);
}
