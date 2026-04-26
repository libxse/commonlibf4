#pragma once

#include "RE/B/BSPointerHandle.h"

namespace RE
{
	namespace BGSInventoryListEvent
	{
		enum class Type
		{
			kAddStack,
			kChangedStack,
			kAddNewItem,
			kRemoveItem,
			kClear,
			UpdateWeight
		};

		class Event
		{
		public:
			// members
			REX::TEnumSet<Type, std::uint16_t> changeType;   // 00
			ObjectRefHandle                    owner;        // 04
			TESBoundObject*                    objAffected;  // 08
			std::uint32_t                      count;        // 10
			std::uint32_t                      stackID;      // 14
		};
		static_assert(sizeof(Event) == 0x18);
	}
}
