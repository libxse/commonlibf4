#pragma once

#include "RE/N/NiAccumulator.h"
#include "RE/N/NiTPointerList.h"

namespace RE
{
	class BSGeometry;

	class __declspec(novtable) NiBackToFrontAccumulator :
		public NiAccumulator  // 000
	{
	public:
		static constexpr auto RTTI{ RTTI::NiBackToFrontAccumulator };
		static constexpr auto VTABLE{ VTABLE::NiBackToFrontAccumulator };
		static constexpr auto Ni_RTTI{ Ni_RTTI::NiBackToFrontAccumulator };

		// members
		NiTPointerList<BSGeometry*> items;     // 18
		std::int32_t                numItems;  // 30
		std::int32_t                maxItems;  // 34
		BSGeometry**                pkItems;   // 38
		float*                      depths;    // 40
		std::int32_t                currItem;  // 48
	};
	static_assert(sizeof(NiBackToFrontAccumulator) == 0x50);
}
