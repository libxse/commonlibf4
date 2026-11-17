#pragma once

namespace RE
{
	class BSGeometry;
	class BSLight;
	class BSShader;
	class BSShaderProperty;

	class BSRenderPass
	{
	private:
		BSRenderPass() = delete;
		BSRenderPass(const BSRenderPass&) = delete;
		BSRenderPass(BSRenderPass&&) = delete;
		~BSRenderPass() = delete;

		BSRenderPass& operator=(const BSRenderPass&) = delete;
		BSRenderPass& operator=(BSRenderPass&&) = delete;

	public:
		[[nodiscard]] BSShaderProperty*       GetShaderProperty() noexcept { return shaderProperty; }
		[[nodiscard]] const BSShaderProperty* GetShaderProperty() const noexcept { return shaderProperty; }

		[[nodiscard]] BSGeometry*       GetGeometry() noexcept { return geometry; }
		[[nodiscard]] const BSGeometry* GetGeometry() const noexcept { return geometry; }

		// members
		std::byte*        commandBuffer;   // 00
		BSShader*         shader;          // 08
		BSShaderProperty* shaderProperty;  // 10
		BSGeometry*       geometry;        // 18
		std::byte         pad20[0x10];     // 20
		BSLight**         sceneLights;     // 30
		BSRenderPass*     propertyNext;    // 38
		BSRenderPass*     batchNext;       // 40
		std::uint32_t     passEnum;        // 48
		std::uint8_t      passType;        // 4C
		std::byte         pad4D;           // 4D
		std::uint8_t      lodMode;         // 4E
		std::byte         pad4F;           // 4F
		std::uint8_t      numLights;       // 50
		std::byte         pad51[0x07];     // 51
	};
	static_assert(sizeof(BSRenderPass) == 0x58);
}
