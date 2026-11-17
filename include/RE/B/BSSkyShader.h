#pragma once

#include "RE/B/BSShader.h"

namespace RE
{
	class __declspec(novtable) BSSkyShader :
	    public BSShader  // 000
	{
	public:
		static constexpr auto RTTI{ RTTI::BSSkyShader };
		static constexpr auto VTABLE{ VTABLE::BSSkyShader };

		// members
		std::byte pad190[0x8];  // 190
	};
	static_assert(sizeof(BSSkyShader) == 0x198);
}
