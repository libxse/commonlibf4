#pragma once

#include "RE/N/NiPoint.h"

namespace RE
{
	class BSPathingAvoidNode
	{
	public:
		enum class AVOID_NODE_TYPE : std::uint32_t
		{
			kSphere = 0x0,
			kCylinder = 0x1,
			kSphereActor = 0x2,
			kSphereTarget = 0x3,
			kSphereThreat = 0x4,
			kSphereObstacle = 0x5
		};

		// members
		NiPoint3                            point1;  // 00
		NiPoint3                            point2;  // 0C
		float                               radius;  // 18
		float                               cost;    // 1C
		BSPathingAvoidNode::AVOID_NODE_TYPE type;    // 20
	};
	static_assert(sizeof(BSPathingAvoidNode) == 0x24);
}
