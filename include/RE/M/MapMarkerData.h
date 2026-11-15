#pragma once

#include "RE/M/MARKER_TYPE.h"
#include "RE/T/TESFullName.h"

namespace RE
{
	class __declspec(novtable) MapMarkerData :
		public TESFullName  // 00
	{
	public:
		const char* GetLocationName()
		{
			using func_t = decltype(&MapMarkerData::GetLocationName);
			static REL::Relocation<func_t> func{ ID::MapMarkerData::GetLocationName };
			return func(this);
		}

		// members
		std::uint8_t                           flags;          // 10
		std::uint8_t                           originalFlags;  // 11
		REX::TEnum<MARKER_TYPE, std::uint16_t> type;           // 12
	};
	static_assert(sizeof(MapMarkerData) == 0x18);
}
