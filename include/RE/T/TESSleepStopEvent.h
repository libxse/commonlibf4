#pragma once

#include "RE/B/BSTEvent.h"
#include "RE/N/NiPointer.h"

namespace RE
{
	class TESSleepStopEvent
	{
	public:
		[[nodiscard]] static BSTEventSource<TESSleepStopEvent>* GetEventSource()
		{
			using func_t = decltype(&TESSleepStopEvent::GetEventSource);
			static REL::Relocation<func_t> func{ ID::TESSleepStopEvent::GetEventSource };
			return func();
		}

		// members
		bool                     interrupted;  // 00
		NiPointer<TESObjectREFR> bedRef;       // 08
	};
	static_assert(sizeof(TESSleepStopEvent) == 0x10);
}
