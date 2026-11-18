#pragma once

#include "RE/B/BSShader.h"

namespace RE
{
	class __declspec(novtable) BSBloodSplatterShader :
	    public BSShader  // 000
	{
	public:
		static constexpr auto RTTI{ RTTI::BSBloodSplatterShader };
		static constexpr auto VTABLE{ VTABLE::BSBloodSplatterShader };

		// members
		std::byte pad190[0x8];  // 190
	};
	static_assert(sizeof(BSBloodSplatterShader) == 0x198);
}
