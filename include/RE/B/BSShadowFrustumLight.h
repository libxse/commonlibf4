#pragma once

#include "RE/B/BSShadowLight.h"

namespace RE
{
	class __declspec(novtable) BSShadowFrustumLight :
	    public BSShadowLight  // 000
	{
	public:
		static constexpr auto RTTI{ RTTI::BSShadowFrustumLight };
		static constexpr auto VTABLE{ VTABLE::BSShadowFrustumLight };

		void Render(std::uint32_t a_mask)
		{
			using func_t = decltype(&BSShadowFrustumLight::Render);
			static REL::Relocation<func_t> func{ ID::BSShadowFrustumLight::Render };
			func(this, a_mask);
		}

		// members
		std::byte pad200[0x10];  // 200
	};
	static_assert(sizeof(BSShadowFrustumLight) == 0x210);
}
