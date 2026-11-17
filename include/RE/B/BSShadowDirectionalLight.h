#pragma once

#include "RE/B/BSShadowLight.h"

namespace RE
{
	class __declspec(novtable) BSShadowDirectionalLight :
	    public BSShadowLight  // 000
	{
	public:
		static constexpr auto RTTI{ RTTI::BSShadowDirectionalLight };
		static constexpr auto VTABLE{ VTABLE::BSShadowDirectionalLight };

		void Render(std::uint32_t a_mask)
		{
			using func_t = decltype(&BSShadowDirectionalLight::Render);
			static REL::Relocation<func_t> func{ ID::BSShadowDirectionalLight::Render };
			func(this, a_mask);
		}

		// members
		std::byte pad200[0x50];       // 200
		float     splitDistances[4];  // 250
		std::byte pad260[0x80];       // 260
	};
	static_assert(sizeof(BSShadowDirectionalLight) == 0x2E0);
}
