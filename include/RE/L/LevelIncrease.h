#pragma once

#include "RE/B/BSTEvent.h"

namespace RE
{
	namespace LevelIncrease
	{
		class Event
		{
		public:
			// members
			std::uint32_t newLevel;  // 00
		};
		static_assert(sizeof(Event) == 0x4);

		[[nodiscard]] static inline BSTEventSource<LevelIncrease::Event>* GetEventSource()
		{
			using func_t = decltype(&LevelIncrease::GetEventSource);
			static REL::Relocation<func_t> func{ ID::LevelIncrease::GetEventSource };
			return func();
		}
	}
}
