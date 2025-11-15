#pragma once

#include "RE/H/hkPtrAndInt.h"

namespace RE
{
	class hkSlot
	{
	public:
		static constexpr auto RTTI{ RTTI::hkSlot };
		static constexpr auto VTABLE{ VTABLE::hkSlot };

		// add
		virtual ~hkSlot();                                             // 00
		virtual std::uint32_t matchMethod(const void*, std::int32_t);  // 01

		// members
		hkPtrAndInt<hkSlot, std::uint32_t, 3> next;    // 08
		void*                                 object;  // 10
	};
	static_assert(sizeof(hkSlot) == 0x18);
}
