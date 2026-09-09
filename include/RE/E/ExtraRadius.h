#pragma once

#include "RE/B/BSExtraData.h"

namespace RE
{
	class __declspec(novtable) ExtraRadius :
		public BSExtraData  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::ExtraRadius };
		static constexpr auto VTABLE{ VTABLE::ExtraRadius };
		static constexpr auto TYPE{ EXTRA_DATA_TYPE::kRadius };

		// members
		float radius;  // 18
	};
	static_assert(sizeof(ExtraRadius) == 0x20);
}
