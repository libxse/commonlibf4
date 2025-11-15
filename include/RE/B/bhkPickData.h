#pragma once

#include "RE/H/hkRefPtr.h"
#include "RE/H/hknpRayCastQuery.h"
#include "RE/H/hknpRayCastQueryResult.h"
#include "RE/M/MemoryManager.h"
#include "RE/N/NiPoint.h"

namespace RE
{
	class hknpBody;
	class hknpBSWorld;
	class hknpCollisionQueryCollector;
	class NiAVObject;

	class bhkPickData
	{
	public:
		enum class COLLECTOR_TYPE;

		bhkPickData()
		{
			typedef bhkPickData*           func_t(bhkPickData*);
			static REL::Relocation<func_t> func{ ID::bhkPickData::ctor };
			func(this);
		}

		void SetStartEnd(const NiPoint3& start, const NiPoint3& end)
		{
			using func_t = decltype(&bhkPickData::SetStartEnd);
			static REL::Relocation<func_t> func{ ID::bhkPickData::SetStartEnd };
			return func(this, start, end);
		}

		void Reset()
		{
			using func_t = decltype(&bhkPickData::Reset);
			static REL::Relocation<func_t> func{ ID::bhkPickData::Reset };
			return func(this);
		}

		bool HasHit() const
		{
			using func_t = decltype(&bhkPickData::HasHit);
			static REL::Relocation<func_t> func{ ID::bhkPickData::HasHit };
			return func(this);
		}

		float GetHitFraction() const
		{
			using func_t = decltype(&bhkPickData::GetHitFraction);
			static REL::Relocation<func_t> func{ ID::bhkPickData::GetHitFraction };
			return func(this);
		}

		std::int32_t GetAllCollectorRayHitSize()
		{
			using func_t = decltype(&bhkPickData::GetAllCollectorRayHitSize);
			static REL::Relocation<func_t> func{ ID::bhkPickData::GetAllCollectorRayHitSize };
			return func(this);
		}

		bool GetAllCollectorRayHitAt(std::uint32_t i, hknpCollisionResult& res)
		{
			using func_t = decltype(&bhkPickData::GetAllCollectorRayHitAt);
			static REL::Relocation<func_t> func{ ID::bhkPickData::GetAllCollectorRayHitAt };
			return func(this, i, res);
		}

		void SortAllCollectorHits()
		{
			using func_t = decltype(&bhkPickData::SortAllCollectorHits);
			static REL::Relocation<func_t> func{ ID::bhkPickData::SortAllCollectorHits };
			return func(this);
		}

		NiAVObject* GetNiAVObject()
		{
			using func_t = decltype(&bhkPickData::GetNiAVObject);
			static REL::Relocation<func_t> func{ ID::bhkPickData::GetNiAVObject };
			return func(this);
		}

		hknpBody* GetBody()
		{
			using func_t = decltype(&bhkPickData::GetBody);
			static REL::Relocation<func_t> func{ ID::bhkPickData::GetBody };
			return func(this);
		}

		F4_HEAP_REDEFINE_NEW(bhkPickData);

		// members
		hknpRayCastQuery             castQuery;            // 00
		hknpRayCastQueryResult       result;               // 60
		hkRefPtr<hknpBSWorld>        castWorld;            // C0
		std::uint64_t                customCollideLayers;  // C8
		hknpCollisionQueryCollector* collector;            // D0
		COLLECTOR_TYPE               collectorType;        // D8
		bool                         incrementPickTime;    // DC
		bool                         allowFailedPicks;     // DD
		bool                         pickFailed;           // DE
	};
	static_assert(sizeof(bhkPickData) == 0xE0);
};
