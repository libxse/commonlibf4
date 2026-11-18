#pragma once

#include "RE/B/BSShader.h"

namespace RE
{
	class __declspec(novtable) BSWaterShader :
	    public BSShader  // 000
	{
	public:
		static constexpr auto RTTI{ RTTI::BSWaterShader };
		static constexpr auto VTABLE{ VTABLE::BSWaterShader };

		// members
		std::byte pad190[0x8];  // 190
	};
	static_assert(sizeof(BSWaterShader) == 0x198);
}
