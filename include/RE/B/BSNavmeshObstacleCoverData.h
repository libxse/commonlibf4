#pragma once

#include "RE/B/BSNavmeshCoverEdge.h"
#include "RE/B/BSTArray.h"
#include "RE/N/NiRefObject.h"

namespace RE
{
	class __declspec(novtable) BSNavmeshObstacleCoverData :
		public NiRefObject  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BSNavmeshObstacleCoverData };
		static constexpr auto VTABLE{ VTABLE::BSNavmeshObstacleCoverData };

		// members
		BSTArray<BSNavmeshCoverEdge> coverEdgeArray;  // 10
		std::uint32_t                flags;           // 28
	};
	static_assert(sizeof(BSNavmeshObstacleCoverData) == 0x30);
}
