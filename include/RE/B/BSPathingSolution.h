#pragma once

#include "RE/B/BSPathingNode.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSVirtualPathingNode.h"

namespace RE
{
	class BSPathingSolution :
		public BSIntrusiveRefCounted  // 00
	{
	public:
		// members
		BSTSmallArray<BSVirtualPathingNode, 2> virtualPathingNodes;          // 008
		std::int32_t                           firstLoadedVirtualNodeIndex;  // 088
		std::int32_t                           lastLoadedVirtualNodeIndex;   // 08C
		BSTArray<BSPathingNode>                currentPathingNodes;          // 090
		float                                  goalRadius;                   // 0A8
		bool                                   incompletePath;               // 0AC
		bool                                   requestGoalUnused;            // 0AD
	};
	static_assert(sizeof(BSPathingSolution) == 0xB0);
}
