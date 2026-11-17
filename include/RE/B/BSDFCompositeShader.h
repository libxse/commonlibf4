#pragma once

#include "RE/B/BSShader.h"

namespace RE
{
	class __declspec(novtable) BSDFCompositeShader :
	    public BSShader  // 000
	{
	public:
		static constexpr auto RTTI{ RTTI::BSDFCompositeShader };
		static constexpr auto VTABLE{ VTABLE::BSDFCompositeShader };

		// members
		std::byte pad190[0x10];  // 190
	};
	static_assert(sizeof(BSDFCompositeShader) == 0x1A0);
}
