#pragma once

#include "RE/B/BSTEvent.h"

namespace RE
{
	class TESWaitStopEvent
	{
	public:
		[[nodiscard]] static BSTEventSource<TESWaitStopEvent>* GetEventSource()
		{
			using func_t = decltype(&TESWaitStopEvent::GetEventSource);
			static REL::Relocation<func_t> func{ ID::TESWaitStopEvent::GetEventSource };
			return func();
		}

		// members
		bool interrupted;  // 00
	};
	static_assert(sizeof(TESWaitStopEvent) == 0x01);
}
