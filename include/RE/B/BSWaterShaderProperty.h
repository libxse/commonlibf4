#pragma once

#include "RE/B/BSShaderProperty.h"

namespace RE
{
	class __declspec(novtable) BSWaterShaderProperty :
	    public BSShaderProperty  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BSWaterShaderProperty };
		static constexpr auto VTABLE{ VTABLE::BSWaterShaderProperty };
		static constexpr auto Ni_RTTI{ Ni_RTTI::BSWaterShaderProperty };

		// members
		std::uint32_t waterFlags;   // 70
		std::byte     pad74[0x4C];  // 74
	};
	static_assert(offsetof(BSWaterShaderProperty, waterFlags) == 0x70);
	static_assert(sizeof(BSWaterShaderProperty) == 0xC0);
}
