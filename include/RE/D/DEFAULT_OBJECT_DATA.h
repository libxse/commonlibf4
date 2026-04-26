#pragma once

#include "RE/D/DEFAULT_OBJECT_TYPE.h"
#include "RE/E/ENUM_FORM_ID.h"

namespace RE
{
	class DEFAULT_OBJECT_DATA
	{
	public:
		[[nodiscard]] static std::span<DEFAULT_OBJECT_DATA, 394> GetDefaultObjectData()
		{
			static REL::Relocation<DEFAULT_OBJECT_DATA(*)[394]> data{ ID::DEFAULT_OBJECT_DATA::GetDefaultObjectData };
			return { *data };
		}

		// members
		const char*                                      name;           // 00
		REX::TEnumSet<ENUM_FORM_ID, std::uint8_t>        type;           // 08
		std::uint32_t                                    uniqueID;       // 0C
		REX::TEnumSet<DEFAULT_OBJECT_TYPE, std::int32_t> doType;         // 10
		const char*                                      newObjectName;  // 18
	};
	static_assert(sizeof(DEFAULT_OBJECT_DATA) == 0x20);
}
