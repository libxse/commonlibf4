#pragma once

#include "RE/B/BSShader.h"

namespace RE
{
	class BSRenderPass;

	class __declspec(novtable) BSDFPrePassShader :
	    public BSShader  // 000
	{
	public:
		static constexpr auto RTTI{ RTTI::BSDFPrePassShader };
		static constexpr auto VTABLE{ VTABLE::BSDFPrePassShader };

		[[nodiscard]] static constexpr std::uint32_t GetPixelShaderID(std::uint32_t a_technique) noexcept
		{
			return a_technique & 0xFFFFEFE7u;
		}

		[[nodiscard]] std::byte* CreateCommandBuffer(BSRenderPass* a_pass)
		{
			using func_t = decltype(&BSDFPrePassShader::CreateCommandBuffer);
			static REL::Relocation<func_t> func{ ID::BSDFPrePassShader::CreateCommandBuffer };
			return func(this, a_pass);
		}

		// members
		std::byte pad190[0x8];  // 190
	};
	static_assert(sizeof(BSDFPrePassShader) == 0x198);
}
