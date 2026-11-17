#pragma once

#include "RE/B/BSShadowLight.h"

namespace RE
{
	class __declspec(novtable) BSShadowParabolicLight :
	    public BSShadowLight  // 000
	{
	public:
		static constexpr auto RTTI{ RTTI::BSShadowParabolicLight };
		static constexpr auto VTABLE{ VTABLE::BSShadowParabolicLight };

		void Render(std::uint32_t a_mask)
		{
			using func_t = decltype(&BSShadowParabolicLight::Render);
			static REL::Relocation<func_t> func{ ID::BSShadowParabolicLight::Render };
			func(this, a_mask);
		}
	};
	static_assert(sizeof(BSShadowParabolicLight) == 0x200);
}
