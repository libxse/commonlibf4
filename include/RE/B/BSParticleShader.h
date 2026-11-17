#pragma once

#include "RE/B/BSShader.h"

namespace RE
{
	class __declspec(novtable) BSParticleShader :
	    public BSShader  // 000
	{
	public:
		static constexpr auto RTTI{ RTTI::BSParticleShader };
		static constexpr auto VTABLE{ VTABLE::BSParticleShader };

		// members
		std::byte pad190[0x8];  // 190
	};
	static_assert(sizeof(BSParticleShader) == 0x198);
}
