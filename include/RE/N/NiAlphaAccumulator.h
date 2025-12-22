#pragma once

#include "RE/N/NiBackToFrontAccumulator.h"

namespace RE
{
	class __declspec(novtable) NiAlphaAccumulator :
		public NiBackToFrontAccumulator  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::NiAlphaAccumulator };
		static constexpr auto VTABLE{ VTABLE::NiAlphaAccumulator };
		static constexpr auto Ni_RTTI{ Ni_RTTI::NiAlphaAccumulator };

		// members
		bool observeNoSortHint;   // 50
		bool sortByClosestPoint;  // 51
		bool interfaceSort;       // 52
	};
	static_assert(sizeof(NiAlphaAccumulator) == 0x58);
}
