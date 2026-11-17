#pragma once

#include "RE/B/BSShader.h"

namespace RE
{
	class __declspec(novtable) BSLightingShader :
	    public BSShader  // 000
	{
	public:
		static constexpr auto RTTI{ RTTI::BSLightingShader };
		static constexpr auto VTABLE{ VTABLE::BSLightingShader };

		// members
		std::byte pad190[0x40];  // 190
	};
	static_assert(sizeof(BSLightingShader) == 0x1D0);
}
