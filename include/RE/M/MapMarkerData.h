#pragma once

#include "RE/M/MARKER_TYPE.h"
#include "RE/T/TESFullName.h"

namespace RE
{
	class __declspec(novtable) MapMarkerData :
		public TESFullName  // 00
	{
		const char* GetLocationName()
		{
			using func_t = decltype(&MapMarkerData::GetLocationName);
			static REL::Relocation<func_t> func{ ID::MapMarkerData::GetLocationName };
			return func(this);
		}

		std::uint8_t flags;          // 10
		std::uint8_t originalFlags;  // 11
		MARKER_TYPE  type;           // 12
	};
	static_assert(sizeof(MapMarkerData) == 0x18);
}
