#pragma once

#include "RE/C/CFilter.h"
#include "RE/H/hkPadSpu.h"
#include "RE/H/hkVector4f.h"
#include "RE/H/hknpBodyId.h"
#include "RE/H/hknpCollisionQueryType.h"
#include "RE/H/hknpMaterialId.h"

namespace RE
{
	class hknpCollisionResult
	{
	public:
		class BodyInfo
		{
		public:
			// members
			hknpBodyId              bodyId;                    // 00
			hknpMaterialId          shapeMaterialId;           // 04
			hkPadSpu<std::uint32_t> shapeKey;                  // 08
			hkPadSpu<CFilter>       shapeCollisionFilterInfo;  // 0C
			hkPadSpu<std::uint64_t> shapeUserData;             // 10
		};
		static_assert(sizeof(BodyInfo) == 0x18);

		// members
		hkVector4f                   position;       // 00
		hkVector4f                   normal;         // 10
		hkPadSpu<float>              fraction;       // 20
		BodyInfo                     queryBodyInfo;  // 28
		BodyInfo                     hitBodyInfo;    // 40
		hknpCollisionQueryType::Enum queryType;      // 58
		hkPadSpu<std::uint32_t>      hitResult;      // 5C
	};
	static_assert(sizeof(hknpCollisionResult) == 0x60);
}
