#pragma once

#include "RE/H/hkArray.h"
#include "RE/H/hknpCollisionQueryCollector.h"
#include "RE/H/hknpCollisionResult.h"

namespace RE
{
	class __declspec(novtable) hknpAllHitsCollector :
		public hknpCollisionQueryCollector  // 000
	{
	public:
		static constexpr auto RTTI{ RTTI::hknpAllHitsCollector };
		static constexpr auto VTABLE{ VTABLE::hknpAllHitsCollector };

		hknpAllHitsCollector()
		{
			REX::EMPLACE_VTABLE<hknpAllHitsCollector>(this);
			hits.data = (hknpCollisionResult*)((uintptr_t)this + 0x30);
			hits.capacityAndFlags = 0x8000000A;
		}

		// override (hknpCollisionQueryCollector)
		void                       Reset() override;                             // 01
		void                       AddHit(const hknpCollisionResult&) override;  // 02
		bool                       HasHit() const override;                      // 03
		std::int32_t               GetNumHits() const override;                  // 04
		const hknpCollisionResult* GetHits() const override;                     // 05

		// members
		hkInplaceArray<hknpCollisionResult, 10> hits;  // 020
	};
	static_assert(sizeof(hknpAllHitsCollector) == 0x3F0);
}
