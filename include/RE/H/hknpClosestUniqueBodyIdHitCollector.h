#pragma once

#include "RE/H/hkVector4f.h"
#include "RE/H/hknpUniqueBodyIdHitCollector.h"

namespace RE
{
	class __declspec(novtable) hknpClosestUniqueBodyIdHitCollector :
		public hknpUniqueBodyIdHitCollector  // 000
	{
	public:
		static constexpr auto RTTI{ RTTI::hknpClosestUniqueBodyIdHitCollector };
		static constexpr auto VTABLE{ VTABLE::hknpClosestUniqueBodyIdHitCollector };

		// members
		hkVector4f center;  // 400
	};
	static_assert(sizeof(hknpClosestUniqueBodyIdHitCollector) == 0x410);
}
