#pragma once

#include "RE/N/NiPoint3.h"

namespace RE
{
	namespace NVGodrays
	{
		// Filled by Sky::GetGodraysSettings.
		struct MediumSettings
		{
			NiPoint3 airScatter;      // 00
			NiPoint3 forwardScatter;  // 0C
			NiPoint3 backScatter;     // 18
			float    phaseForward;    // 24
			float    phaseBackward;   // 28
		};
		static_assert(sizeof(MediumSettings) == 0x2C);

		struct PostprocessSettings
		{
			float intensity;  // 00
		};

		[[nodiscard]] inline bool IsEnabled()
		{
			using func_t = decltype(&IsEnabled);
			static REL::Relocation<func_t> func{ ID::NVGodrays::IsEnabled };
			return func();
		}
	}
}
