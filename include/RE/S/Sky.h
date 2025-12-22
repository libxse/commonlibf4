#pragma once

#include "RE/B/BSPointerHandle.h"
#include "RE/B/BSSimpleList.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTTuple.h"
#include "RE/N/NiColor.h"
#include "RE/N/NiPointer.h"
#include "RE/S/SkyEffectController.h"

namespace RE
{
	class Atmosphere;
	class BSMultiBoundNode;
	class Clouds;
	class ImageSpaceModifierInstanceForm;
	class Moon;
	class NiNode;
	class NiTexture;
	class Precipitation;
	class ReferenceEffect;
	class SkySound;
	class Stars;
	class Sun;

	class __declspec(novtable) Sky
	{
	public:
		static constexpr auto RTTI{ RTTI::Sky };
		static constexpr auto VTABLE{ VTABLE::Sky };

		enum class Mode
		{
			kNone = 0x0,
			kInterior = 0x1,
			kSkyDomeOnly = 0x2,
			kFull = 0x3,

			kTotal = 0x4
		};

		enum class Flags
		{
			kNone = 0,
			kFastTravel = 1 << 4,
			kHideSky = 1 << 7,
			kUpdateSunriseBegin = 1 << 9,
			kUpdateSunriseEnd = 1 << 10,
			kUpdateSunsetBegin = 1 << 11,
			kUpdateSunsetEnd = 1 << 12,
			kUpdateColorsSunriseBegin = 1 << 13,
			kUpdateColorsSunsetEnd = 1 << 14,
			kUpdateWind = 1 << 20,
			kReleaseWeatherOverride = 1 << 21
		};

		enum class WeatherStateOperation
		{
			kSave = 0x0,
			kRestore = 0x1,
			kClear = 0x2
		};

		enum class FogDistance
		{
			kNear = 0x0,
			kFar = 0x1,
			kWaterNear = 0x2,
			kWaterFar = 0x3,
			kHeightMid = 0x4,
			kHeightRange = 0x5,
			kFarHeightMid = 0x6,
			kFarHeightRange = 0x7
		};

		class SkyStaticRefData
		{
		public:
			// members
			BSTTuple<ObjectRefHandle, std::uint8_t> data;  // 00
		};
		static_assert(sizeof(SkyStaticRefData) == 0x8);

		virtual ~Sky();  // 00

		[[nodiscard]] static Sky* GetSingleton()
		{
			using func_t = decltype(&Sky::GetSingleton);
			static REL::Relocation<func_t> func{ ID::Sky::Singleton };
			return func();
		}

		void ForceWeather(TESWeather* a_weather, bool a_override)
		{
			using func_t = decltype(&Sky::ForceWeather);
			static REL::Relocation<func_t> func{ ID::Sky::ForceWeather };
			return func(this, a_weather, a_override);
		}

		void ReleaseWeatherOverride()
		{
			if (overrideWeather) {
				flags.set(Flags::kReleaseWeatherOverride);
				overrideWeather = nullptr;
			}
		}

		void ResetWeather()
		{
			using func_t = decltype(&Sky::ResetWeather);
			static REL::Relocation<func_t> func{ ID::Sky::ResetWeather };
			return func(this);
		}

		// members
		NiPointer<BSMultiBoundNode>        root;                             // 008
		NiPointer<NiNode>                  moonsRoot;                        // 010
		NiPointer<NiNode>                  auroraRoot;                       // 018
		void*                              aurora3d;                         // 020 - BSModelDB::Handle
		BGSLightingTemplate*               extLightingOverride;              // 028
		ObjectRefHandle                    currentRoom;                      // 030
		ObjectRefHandle                    previousRoom;                     // 034
		float                              lightingTransition;               // 038
		float                              lightingTransitionTimer;          // 03C
		TESClimate*                        currentClimate;                   // 040
		TESWeather*                        currentWeather;                   // 048
		TESWeather*                        lastWeather;                      // 050
		TESWeather*                        defaultWeather;                   // 058
		TESWeather*                        overrideWeather;                  // 060
		TESRegion*                         currentRegion;                    // 068
		Atmosphere*                        atmosphere;                       // 070
		Stars*                             stars;                            // 078
		Sun*                               sun;                              // 080
		Clouds*                            clouds;                           // 088
		Moon*                              masser;                           // 090
		Moon*                              secunda;                          // 098
		Precipitation*                     precip;                           // 0A0
		NiColor                            skyColor[19];                     // 0A8
		NiColor                            prevSkyColorA[19];                // 18C
		NiColor                            prevDirAmbColorsA[3][2];          // 270
		NiColorA                           prevSpecTintFres;                 // 2B8
		TESImageSpace*                     prevImageSpace;                   // 2C8
		float                              prevFogDistancesA[8];             // 2D0
		float                              prevFogHeight;                    // 2F0
		float                              prevFogPower;                     // 2F4
		float                              prevFogClamp;                     // 2F8
		float                              prevFogHighDensityScale;          // 2FC
		float                              lastExtWetness;                   // 300
		NiColor                            waterFogColor;                    // 304
		NiColor                            sunSpecularColor;                 // 310
		float                              windSpeed;                        // 31C
		float                              windAngle;                        // 320
		float                              windTurbulence;                   // 324
		float                              fogDistances[8];                  // 328
		float                              fogHeight;                        // 348
		float                              fogPower;                         // 34C
		float                              fogClamp;                         // 350
		float                              fogHighDensityScale;              // 354
		float                              currentGameHour;                  // 358
		float                              lastWeatherUpdate;                // 35C
		float                              currentWeatherPct;                // 360
		float                              lastWindDirection;                // 364
		float                              lastWindDirectionRange;           // 368
		REX::EnumSet<Mode, std::uint32_t>  mode;                             // 36C
		BSSimpleList<SkySound*>*           skySoundList;                     // 370
		float                              flash;                            // 378
		std::uint64_t                      flashTime;                        // 380
		std::uint32_t                      lastMoonPhaseUpdate;              // 388
		float                              windowReflectionTimer;            // 38C
		float                              accelBeginPct;                    // 390
		REX::EnumSet<Flags, std::uint32_t> flags;                            // 394
		ImageSpaceModifierInstanceForm*    currentWeatherImageSpaceMod;      // 398
		ImageSpaceModifierInstanceForm*    currentWeatherImageSpaceMod2;     // 3A0
		ImageSpaceModifierInstanceForm*    lastWeatherImageSpaceMod;         // 3A8
		ImageSpaceModifierInstanceForm*    lastWeatherImageSpaceMod2;        // 3B0
		NiColor                            directionalAmbientColorsA[3][2];  // 3B8
		NiColor                            ambientSpecularTint;              // 400
		float                              ambientSpecularFresnel;           // 40C
		float                              auroraInStart;                    // 410
		float                              auroraIn;                         // 414
		float                              auroraOutStart;                   // 418
		float                              auroraOut;                        // 41C
		NiPointer<ReferenceEffect>         currentReferenceEffect;           // 420
		NiPointer<ReferenceEffect>         lastReferenceEffect;              // 428
		SkyEffectController                effectController;                 // 430
		BSTArray<NiPointer<NiTexture>>     storedCloudTextures;              // 438
		BSTArray<NiPointer<NiTexture>>     storedWorldMapCloudTextures;      // 450
		BSTArray<SkyStaticRefData>         skyStaticRefData;                 // 468
	};
	static_assert(sizeof(Sky) == 0x480);
}
