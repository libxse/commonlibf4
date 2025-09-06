#pragma once

#include "RE/B/BGSDirectionalAmbientLightingColors.h"
#include "RE/B/BSSimpleList.h"
#include "RE/B/BSTArray.h"
#include "RE/T/TESForm.h"
#include "RE/T/TESModel.h"
#include "RE/T/TESTexture1024.h"

namespace RE
{
	class BGSReferenceEffect;
	class BGSShaderParticleGeometryData;

	class __declspec(novtable) TESWeather :
		public TESForm  // 000
	{
	public:
		static constexpr auto RTTI{ RTTI::TESWeather };
		static constexpr auto VTABLE{ VTABLE::TESWeather };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kWTHR };

		enum class ColorTime
		{
			kSunrise = 0x0,
			kDay = 0x1,
			kSunset = 0x2,
			kNight = 0x3,
			kEarlySunrise = 0x4,
			kLateSunrise = 0x5,
			kEarlySunset = 0x6,
			kLateSunset = 0x7,
			kCount = 0x8
		};

		enum class SpellContext
		{
			kApplyOnLightning = 0x0,
			kApplyWhenActive = 0x1
		};

		enum class SoundType
		{
			kDefault = 0x0,
			kPrecipitation = 0x1,
			kWind = 0x2,
			kThunder = 0x3
		};

		enum class WeatherData
		{
			kWindSpeed = 0x0,
			kCloudSpeedY = 0x1,
			kCloudSpeedX = 0x2,
			kTransDelta = 0x3,
			kSunGlare = 0x4,
			kSunDamage = 0x5,
			kBeginPrecip = 0x6,
			kEndPrecip = 0x7,
			kBeginThunder = 0x8,
			kEndThunder = 0x9,
			kThunderFreq = 0xA,
			kFlags = 0xB,
			kLightningR = 0xC,
			kLightningG = 0xD,
			kLightningB = 0xE,
			kBeginEffect = 0xF,
			kEndEffect = 0x10,
			kWindDir = 0x11,
			kWindDirRange = 0x12,
			kWindTurbulence = 0x13,
			kCount = 0x14
		};

		enum class WeatherDataFlags
		{
			kPleasant = 0x1,
			kCloudy = 0x2,
			kRainy = 0x4,
			kSnow = 0x8,
			kPermAurora = 0x10,
			kAuroraFollowsSun = 0x20,
			kRainOcclusion = 0x40,
			kHudRain = 0x80
		};

		class SpellData
		{
		public:
			// members
			MagicItem* spell;      // 00
			float      threshold;  // 08
		};
		static_assert(sizeof(SpellData) == 0x10);

		class WeatherSound
		{
		public:
			// members
			BGSSoundDescriptorForm*               soundForm;  // 00
			REX::EnumSet<SoundType, std::int32_t> type;       // 08
		};
		static_assert(sizeof(WeatherSound) == 0x10);

		class WeatherSoundList :
			public BSSimpleList<WeatherSound*>
		{
		public:
		};
		static_assert(sizeof(WeatherSoundList) == 0x10);

		// members
		REX::EnumSet<SpellContext, std::int32_t> context;                              // 020
		TESTexture1024                           cloudTexture[32];                     // 028
		std::int8_t                              cloudLayerSpeedY[32];                 // 228
		std::int8_t                              cloudLayerSpeedX[32];                 // 248
		std::uint32_t                            cloudColorData[32][8];                // 268
		float                                    cloudAlpha[32][8];                    // 668
		std::uint32_t                            cloudLayerDisabledBits;               // A68
		std::int8_t                              weatherData[20];                      // A6C
		float                                    fogData[18];                          // A80
		std::uint32_t                            colorData[19][8];                     // AC8
		float                                    fogColorScales[4][8];                 // D28
		SpellData                                weatherSpellData[2];                  // DA8
		WeatherSoundList                         soundList;                            // DC8
		BSTArray<TESObjectSTAT*>                 skyStatics;                           // DD8
		std::uint32_t                            numCloudLayers;                       // DF0
		TESImageSpace*                           imageSpace[8];                        // DF8
		BGSGodRays*                              godRays[8];                           // E38
		BGSDirectionalAmbientLightingColors      directionalAmbientLightingColors[8];  // E78
		TESModel                                 aurora;                               // F78
		BGSLensFlare*                            sunGlareLensFlare;                    // FA8
		float                                    volatilityMult;                       // FB0
		float                                    visibilityMult;                       // FB4
		BGSShaderParticleGeometryData*           precipitationData;                    // FB8
		BGSReferenceEffect*                      referenceEffect;                      // FC0
	};
	static_assert(sizeof(TESWeather) == 0xFC8);
}
