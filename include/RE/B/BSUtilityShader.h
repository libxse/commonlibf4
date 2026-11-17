#pragma once

#include "RE/B/BSShader.h"

namespace RE
{
	class BSRenderPass;

	class __declspec(novtable) BSUtilityShader :
		public BSShader  // 000
	{
	public:
		static constexpr auto RTTI{ RTTI::BSUtilityShader };
		static constexpr auto VTABLE{ VTABLE::BSUtilityShader };

		enum class Flags : std::uint32_t
		{
			kVertexColors = 1u << 0,
			kTexture = 1u << 1,
			kSkinned = 1u << 2,
			kNormals = 1u << 3,
			kBinormalTangent = 1u << 4,
			kLandscape = 1u << 5,
			kAlphaTest = 1u << 7,
			kRenderShadowMap = 1u << 14,
			kRenderShadowMapClamped = 1u << 15,
			kCombined = 1u << 21,
			kInstanced = 1u << 23,
			kTreeAnim = 1u << 26,
			kAdditionalAlphaMask = 1u << 28
		};

		[[nodiscard]] static BSUtilityShader*& GetSingleton()
		{
			static REL::Relocation<BSUtilityShader**> singleton{ ID::BSUtilityShader::Singleton };
			return *singleton;
		}

		[[nodiscard]] std::byte* CreateCommandBuffer(BSRenderPass* a_pass)
		{
			using func_t = decltype(&BSUtilityShader::CreateCommandBuffer);
			static REL::Relocation<func_t> func{ ID::BSUtilityShader::CreateCommandBuffer };
			return func(this, a_pass);
		}

		// members
		std::uint32_t currentTechniqueID;  // 190
		std::uint32_t currentDecl;         // 194
	};
	static_assert(sizeof(BSUtilityShader) == 0x198);
}
