#pragma once

#include "RE/B/BSNavmeshTriangleEdgePortal.h"

namespace RE
{
	enum class EDGE_EXTRA_INFO_TYPE;

	class BSNavmeshEdgeExtraInfo
	{
	public:
		// members
		REX::TEnumSet<EDGE_EXTRA_INFO_TYPE, std::int32_t> type;    // 0
		BSNavmeshTriangleEdgePortal                       portal;  // 4
	};
	static_assert(sizeof(BSNavmeshEdgeExtraInfo) == 0xC);
}
