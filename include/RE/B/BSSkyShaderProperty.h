#pragma once

#include "RE/B/BSShaderProperty.h"
#include "RE/N/NiColor.h"

namespace RE
{
	class __declspec(novtable) BSSkyShaderProperty :
	    public BSShaderProperty  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BSSkyShaderProperty };
		static constexpr auto VTABLE{ VTABLE::BSSkyShaderProperty };
		static constexpr auto Ni_RTTI{ Ni_RTTI::BSSkyShaderProperty };

		// members
		NiColorA  kBlendColor;  // 70
		std::byte pad80[0x30];  // 80
	};
	static_assert(offsetof(BSSkyShaderProperty, kBlendColor) == 0x70);
	static_assert(sizeof(BSSkyShaderProperty) == 0xB0);
}
