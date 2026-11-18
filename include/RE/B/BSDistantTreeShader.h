#pragma once

#include "RE/B/BSShader.h"

namespace RE
{
	class __declspec(novtable) BSDistantTreeShader :
	    public BSShader  // 000
	{
	public:
		static constexpr auto RTTI{ RTTI::BSDistantTreeShader };
		static constexpr auto VTABLE{ VTABLE::BSDistantTreeShader };

		// members
		std::byte pad190[0x8];  // 190
	};
	static_assert(sizeof(BSDistantTreeShader) == 0x198);
}
