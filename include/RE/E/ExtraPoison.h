#pragma once

#include "RE/B/BSExtraData.h"

namespace RE
{
	class AlchemyItem;

	class __declspec(novtable) ExtraPoison :
		public BSExtraData  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::ExtraPoison };
		static constexpr auto VTABLE{ VTABLE::ExtraPoison };
		static constexpr auto TYPE{ EXTRA_DATA_TYPE::kPoison };

		// members
		std::uint32_t count;   // 18
		AlchemyItem*  poison;  // 20
	};
	static_assert(sizeof(ExtraPoison) == 0x28);
}
