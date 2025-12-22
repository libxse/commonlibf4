#pragma once

#include "RE/R/REGION_DATA_ID.h"

namespace RE
{
	class REGION_DATA_BASE;
	class TESRegion;

	class __declspec(novtable) TESRegionData
	{
	public:
		static constexpr auto RTTI{ RTTI::TESRegionData };
		static constexpr auto VTABLE{ VTABLE::TESRegionData };

		virtual ~TESRegionData();  // 00

		// add
		virtual bool           LoadRegionData(REGION_DATA_BASE* a_data);                                     // 01
		virtual void           Initialize(TESRegion* a_formal);                                              // 02
		virtual REGION_DATA_ID GetID();                                                                      // 03
		virtual TESRegionData* Copy();                                                                       // 04
		virtual TESRegionData* Blend();                                                                      // 04
		virtual void           BlendInto(const TESRegionData* a_regionData, std::uint32_t a_totalBlending);  // 05
		virtual bool           Validate();                                                                   // 06

		// members
		bool         override;  // 08
		bool         ignore;    // 09
		std::uint8_t priority;  // 0A
	};
	static_assert(sizeof(TESRegionData) == 0x10);
}
