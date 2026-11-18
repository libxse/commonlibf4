#pragma once

#include "RE/B/BSShader.h"

namespace RE
{
	class BSLight;

	class __declspec(novtable) BSDFLightShader :
	    public BSShader  // 000
	{
	public:
		static constexpr auto RTTI{ RTTI::BSDFLightShader };
		static constexpr auto VTABLE{ VTABLE::BSDFLightShader };

		bool SetupPointLightGeometry(BSLight* a_light, std::uint32_t a_technique, bool a_setState)
		{
			using func_t = decltype(&BSDFLightShader::SetupPointLightGeometry);
			static REL::Relocation<func_t> func{ ID::BSDFLightShader::SetupPointLightGeometry };
			return func(this, a_light, a_technique, a_setState);
		}

		// members
		std::byte pad190[0x28];  // 190
	};
	static_assert(sizeof(BSDFLightShader) == 0x1B8);
}
