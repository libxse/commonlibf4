#pragma once

#include "RE/T/TESForm.h"
#include "RE/T/TESModel.h"
#include "RE/T/TESTexture.h"
#include "RE/T/TESWeatherList.h"

namespace RE
{
	class __declspec(novtable) TESClimate :
		public TESForm  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::TESClimate };
		static constexpr auto VTABLE{ VTABLE::TESClimate };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kCLMT };

		enum class MiscData
		{
			kVolatility = 0x4,
			kMoonData = 0x5,
			kNumSliders = 0x6
		};

		enum class TextureType
		{
			kSun = 0x0,
			kGlare = 0x1,
			kCount = 0x2
		};

		enum class TransTime
		{
			kSunriseBegin = 0x0,
			kSunriseEnd = 0x1,
			kSunsetBegin = 0x2,
			kSunsetEnd = 0x3,
			kCount = 0x4
		};

		enum class SpellContext
		{
			kApplyOnLightning = 0x0,
			kApplyWhenActive = 0x1
		};

		// members
		TESModel       nightSky;       // 20
		TESWeatherList weatherList;    // 50
		TESTexture     skyObjects[2];  // 60
		std::int8_t    data[6];        // 80
	};
	static_assert(sizeof(TESClimate) == 0x88);
}
