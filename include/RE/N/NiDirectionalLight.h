#pragma once

#include "RE/N/NiLight.h"
#include "RE/N/NiPoint3.h"

namespace RE
{
	class __declspec(novtable) NiDirectionalLight :
	    public NiLight  // 000
	{
	public:
		static constexpr auto RTTI{ RTTI::NiDirectionalLight };
		static constexpr auto VTABLE{ VTABLE::NiDirectionalLight };
		static constexpr auto Ni_RTTI{ Ni_RTTI::NiDirectionalLight };

		// members
		NiPoint3  direction;     // 170
		std::byte pad17C[0x14];  // 17C
	};
	static_assert(sizeof(NiDirectionalLight) == 0x190);
}
