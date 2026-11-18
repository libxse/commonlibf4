#pragma once

#include "RE/B/BSGraphics.h"
#include "RE/B/BSReloadShaderI.h"
#include "RE/B/BSShaderTechniqueIDMap.h"
#include "RE/N/NiRefObject.h"

namespace RE
{
	class BSGeometry;
	class BSRenderPass;
	class BSShaderMaterial;

	class __declspec(novtable) BSShader :
		public NiRefObject,     // 000
		public BSReloadShaderI  // 010
	{
	public:
		static constexpr auto RTTI{ RTTI::BSShader };
		static constexpr auto VTABLE{ VTABLE::BSShader };

		struct BuildCommandBufferParam
		{
		public:
			// members
			BSGeometry*                                 geometry;             // 00
			std::uint32_t                               vertexRegisters;      // 08, float4 count
			std::uint32_t                               pixelRegisters;       // 0C, float4 count
			std::byte                                   pad10[0x08];          // 10
			std::uint32_t                               lodMode;              // 18
			std::byte                                   pad1C[0x04];          // 1C
			const float*                                vertexConstants;      // 20
			float*                                      pixelConstants;       // 28
			std::byte                                   pad30[0x10];          // 30
			BSGraphics::VertexShader*                   vertexShader;         // 40
			REX::TEnum<BSGraphics::AlphaBlendMode>      alphaBlendMode;       // 48
			REX::TEnum<BSGraphics::AlphaBlendWriteMode> alphaBlendWriteMode;  // 4C
			std::byte                                   pad50[0x18];          // 50
		};
		static_assert(sizeof(BuildCommandBufferParam) == 0x68);

		// add
		virtual bool          SetupTechnique(std::uint32_t a_currentPass) = 0;                                            // 02
		virtual void          RestoreTechnique(std::uint32_t a_currentPass) = 0;                                          // 03
		virtual void          SetupMaterial([[maybe_unused]] const BSShaderMaterial* a_material) { return; }              // 04
		virtual void          RestoreMaterial([[maybe_unused]] const BSShaderMaterial* a_material) { return; }            // 05
		virtual void          SetupMaterialSecondary([[maybe_unused]] const BSShaderMaterial* a_material) { return; }     // 06
		virtual void          SetupGeometry(BSRenderPass* a_currentPass) = 0;                                             // 07
		virtual void          RestoreGeometry(BSRenderPass* a_currentPass) = 0;                                           // 08
		virtual void          GetTechniqueName(std::uint32_t a_techniqueID, char* a_buffer, std::uint32_t a_bufferSize);  // 09
		virtual void          RecreateRendererData() { return; }                                                          // 0A
		virtual void          ReloadShaders(bool a_clear);                                                                // 0B
		virtual std::uint32_t GetBonesVertexConstant() const { return 0; }                                                // 0C

		[[nodiscard]] std::byte* BuildCommandBuffer(BuildCommandBufferParam& a_param)
		{
			using func_t = decltype(&BSShader::BuildCommandBuffer);
			static REL::Relocation<func_t> func{ ID::BSShader::BuildCommandBuffer };
			return func(this, a_param);
		}

		bool BeginTechnique(std::uint32_t a_vertexShaderID, std::uint32_t a_hullShaderID, std::uint32_t a_domainShaderID, std::uint32_t a_pixelShaderID)
		{
			using func_t = decltype(&BSShader::BeginTechnique);
			static REL::Relocation<func_t> func{ ID::BSShader::BeginTechnique };
			return func(this, a_vertexShaderID, a_hullShaderID, a_domainShaderID, a_pixelShaderID);
		}

		// members
		std::int32_t                                                shaderType;      // 018
		std::byte                                                   pad01C[0x7C];    // 01C
		BSShaderTechniqueIDMap::MapType<BSGraphics::VertexShader*>  vertexShaders;   // 098
		BSShaderTechniqueIDMap::MapType<BSGraphics::HullShader*>    hullShaders;     // 0C8
		BSShaderTechniqueIDMap::MapType<BSGraphics::DomainShader*>  domainShaders;   // 0F8
		BSShaderTechniqueIDMap::MapType<BSGraphics::PixelShader*>   pixelShaders;    // 128
		BSShaderTechniqueIDMap::MapType<BSGraphics::ComputeShader*> computeShaders;  // 158
		const char*                                                 fxpFilename;     // 188
	};
	static_assert(sizeof(BSShader) == 0x190);
}
