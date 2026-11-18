#pragma once

#include "RE/B/BSShaderMaterial.h"
#include "RE/B/BSSpinLock.h"
#include "RE/N/NiColor.h"
#include "RE/N/NiPointer.h"

namespace RE
{
	class BSLightingShaderMaterialEnvmap;
	class BSShaderData;
	class BSTextureSet;
	class NiTexture;
	class NiStream;

	namespace BSGraphics
	{
		enum class TextureAddressMode;
	}

	class __declspec(novtable) BSLightingShaderMaterialBase :
		public BSShaderMaterial  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BSLightingShaderMaterialBase };
		static constexpr auto VTABLE{ VTABLE::BSLightingShaderMaterialBase };

		// add
		virtual const BSLightingShaderMaterialEnvmap* IsLightingShaderMaterialEnvmap();                                          // 09
		virtual void                                  ClearTextures();                                                           // 0A
		virtual std::uint32_t                         GetTextures(NiTexture** a_textures, std::uint32_t a_arraySize);            // 0B
		virtual void                                  SaveBinary(NiStream* a_stream);                                            // 0C
		virtual void                                  LoadBinary(NiStream* a_stream);                                            // 0D
		virtual void                                  OnPrefetchTextures(void* a_outHandles, const BSTextureSet* a_textureSet);  // 0E - TextureDB::Handle
		virtual void                                  OnLoadTextureSet1(const BSTextureSet* a_textureSet, void* a_inHandles);    // 0F - TextureDB::Handle
		virtual void                                  OnLoadTextureSet2(const BSTextureSet* a_textureSet);                       // 10
		virtual void                                  DoReceiveValuesFromRootMaterial(const BSShaderData& a_rootData);           // 11

		void OnLoadTextureSet(const BSTextureSet* a_textureSet, void* a_inHandles)  // TextureDB::Handle
		{
			return OnLoadTextureSet1(a_textureSet, a_inHandles);
		}

		void OnLoadTextureSet(const BSTextureSet* a_textureSet)
		{
			return OnLoadTextureSet2(a_textureSet);
		}

		// members
		NiColor                        specularColor;                  // 38
		NiPointer<NiTexture>           diffuseTexture;                 // 48
		NiPointer<NiTexture>           normalTexture;                  // 50
		NiPointer<NiTexture>           rimSoftLightingTexture;         // 58
		NiPointer<NiTexture>           smoothnessSpecMaskTexture;      // 60
		NiPointer<NiTexture>           lookupTexture;                  // 68
		BSGraphics::TextureAddressMode textureClampMode;               // 70
		NiPointer<BSTextureSet>        textureSet;                     // 78
		float                          materialAlpha;                  // 80
		float                          refractionPower;                // 84
		float                          smoothness;                     // 88
		float                          specularColorScale;             // 8C
		float                          fresnelPower;                   // 90
		float                          wetnessControl_SpecScale;       // 94
		float                          wetnessControl_SpecPowerScale;  // 98
		float                          wetnessControl_SpecMin;         // 9C
		float                          wetnessControl_EnvMapScale;     // A0
		float                          wetnessControl_FresnelPower;    // A4
		float                          wetnessControl_Metalness;       // A8
		float                          subSurfaceLightRolloff;         // AC
		float                          rimLightPower;                  // B0
		float                          backLightPower;                 // B4
		float                          lookupScale;                    // B8
		BSNonReentrantSpinLock         loadTextureSetLock;             // BC
	};
	static_assert(sizeof(BSLightingShaderMaterialBase) == 0xC0);
	static_assert(offsetof(BSLightingShaderMaterialBase, diffuseTexture) == 0x48);
	static_assert(offsetof(BSLightingShaderMaterialBase, smoothnessSpecMaskTexture) == 0x60);
	static_assert(offsetof(BSLightingShaderMaterialBase, textureClampMode) == 0x70);
	static_assert(offsetof(BSLightingShaderMaterialBase, loadTextureSetLock) == 0xBC);
}
