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

		// members
		TESModel       nightSky;        // 20
		TESWeatherList weatherList;     // 50
		TESTexture     skyObjects[2];   // 60
		std::uint8_t   sunriseBegin;    // 80
		std::uint8_t   sunriseEnd;      // 81
		std::uint8_t   sunsetBegin;     // 82
		std::uint8_t   sunsetEnd;       // 83
		std::byte      pad84;           // 84
		std::uint8_t   phaseLength: 6;  // 85
		std::uint8_t   secunda: 1;      // 85
		std::uint8_t   masser: 1;       // 85
	};
	static_assert(sizeof(TESClimate) == 0x88);
}
