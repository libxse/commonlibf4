#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/B/BSIntrusiveRefCounted.h"
#include "RE/B/BSTArray.h"
#include "RE/N/NiAlphaProperty.h"
#include "RE/N/NiColor.h"
#include "RE/N/NiPoint.h"
#include "RE/N/NiPointer.h"

namespace RE
{
	class BSEffectShaderPropertyColorController;
	class BSEffectShaderPropertyFloatController;
	class BSLightingShaderPropertyColorController;
	class BSLightingShaderPropertyFloatController;
	class BSLightingShaderPropertyUShortController;
	class BSNiAlphaPropertyTestRefController;
	class BSShaderTextureSet;

	namespace BSGraphics
	{
		enum class TextureAddressMode;
	}

	class BSShaderData :
		public BSIntrusiveRefCounted  // 000
	{
	public:
		enum class LightingShaderEnum
		{
			kStandard = 0x0,
			kWater = 0x1,
			kEffect = 0x2,
			kSky = 0x3,
			kTallGrass = 0x4
		};

		// members
		REX::EnumSet<LightingShaderEnum, std::int32_t>             lightingShader;                                 // 004
		bool                                                       specularEnabled;                                // 008
		NiColor                                                    specularColor;                                  // 00C
		float                                                      specularMult;                                   // 018
		NiColor                                                    emittanceColor;                                 // 01C
		float                                                      emittanceColorScale;                            // 028
		float                                                      lightingInfluence;                              // 02C
		std::int8_t                                                envmapMinLOD;                                   // 030
		float                                                      smoothness;                                     // 034
		float                                                      fresnelPower_ShaderDataEntry;                   // 038
		float                                                      wetnessControl_SpecScale_ShaderDataEntry;       // 03C
		float                                                      wetnessControl_SpecPowerScale_ShaderDataEntry;  // 040
		float                                                      wetnessControl_SpecMin_ShaderDataEntry;         // 044
		float                                                      wetnessControl_EnvMapScale_ShaderDataEntry;     // 048
		float                                                      wetnessControl_FresnelPower_ShaderDataEntry;    // 04C
		float                                                      wetnessControl_Metalness_ShaderDataEntry;       // 050
		bool                                                       betnessControl_ScreenSpaceReflections;          // 054
		BSFixedString                                              rootMaterialPath;                               // 058
		float                                                      alpha;                                          // 060
		float                                                      emittanceMult;                                  // 064
		float                                                      lookupScale;                                    // 068
		bool                                                       emitEnabled;                                    // 06C
		BSFixedString                                              materialPath;                                   // 070
		bool                                                       alphaBlend;                                     // 078
		REX::EnumSet<NiAlphaProperty::AlphaFunction, std::int32_t> alphaSrcBlendMode;                              // 07C
		REX::EnumSet<NiAlphaProperty::AlphaFunction, std::int32_t> alphaDestBlendMode;                             // 080
		bool                                                       alphaTest;                                      // 084
		REX::EnumSet<NiAlphaProperty::TestFunction, std::int32_t>  alphaTestFunction;                              // 088
		std::int8_t                                                alphaTestRef;                                   // 08C
		bool                                                       enableEditorAlphaRef;                           // 08D
		bool                                                       vertexColors;                                   // 08E
		bool                                                       vertexAlpha;                                    // 08F
		bool                                                       modelSpaceNormals;                              // 090
		bool                                                       decal;                                          // 091
		bool                                                       externalEmittance;                              // 092
		bool                                                       hideSecret;                                     // 093
		bool                                                       noFade;                                         // 094
		bool                                                       dismemberment;                                  // 095
		bool                                                       facegen;                                        // 096
		bool                                                       skinTint;                                       // 097
		bool                                                       hair;                                           // 098
		bool                                                       twoSided;                                       // 099
		bool                                                       tree;                                           // 09A
		bool                                                       bloodEnabled;                                   // 09B
		bool                                                       uniqueAlphaProperty;                            // 09C
		bool                                                       effectLightingEnabled;                          // 09D
		bool                                                       castShadows;                                    // 09E
		bool                                                       receiveShadows;                                 // 09F
		bool                                                       dissolveFade;                                   // 0A0
		bool                                                       glowmap;                                        // 0A1
		bool                                                       assumeShadowmask;                               // 0A2
		bool                                                       screenSpaceReflections;                         // 0A3
		bool                                                       nonOccluder;                                    // 0A4
		bool                                                       skewSpecularAlpha;                              // 0A5
		bool                                                       tessellate;                                     // 0A6
		bool                                                       backLighting;                                   // 0A7
		bool                                                       subSurfaceLighting;                             // 0A8
		bool                                                       rimLighting;                                    // 0A9
		float                                                      subSurfaceRolloff;                              // 0AC
		float                                                      rimPower;                                       // 0B0
		float                                                      backLightPower;                                 // 0B4
		bool                                                       anisoLighting;                                  // 0B8
		bool                                                       zBufferWrite;                                   // 0B8
		bool                                                       zBufferTest;                                    // 0BA
		bool                                                       refraction;                                     // 0BB
		float                                                      refractionPower;                                // 0BC
		bool                                                       refractionFalloff;                              // 0C0
		BSTArray<BSLightingShaderPropertyFloatController*>         lightingFloatControllers;                       // 0C8
		BSTArray<BSLightingShaderPropertyUShortController*>        lightingUShortControllers;                      // 0E0
		BSTArray<BSLightingShaderPropertyColorController*>         lightingColorControllers;                       // 0F8
		BSTArray<BSEffectShaderPropertyFloatController*>           effectFloatControllers;                         // 110
		BSTArray<BSEffectShaderPropertyColorController*>           effectColorControllers;                         // 128
		BSNiAlphaPropertyTestRefController*                        alphaRefTestController;                         // 140
		bool                                                       parallax;                                       // 148
		bool                                                       parallaxOcclusion;                              // 149
		bool                                                       multiLayerParallax;                             // 14A
		float                                                      parallaxOcclusionHeightScale;                   // 14C
		float                                                      parallaxOcclusionMaxPasses;                     // 150
		float                                                      parallaxLayerThickness;                         // 154
		float                                                      parallaxRefractionScale;                        // 158
		float                                                      parallaxInnerLayerUScale;                       // 15C
		float                                                      parallaxInnerLayerVScale;                       // 160
		float                                                      displacementTextureBias;                        // 164
		float                                                      displacementTextureScale;                       // 168
		float                                                      tessellationPNScale;                            // 16C
		float                                                      tessellationFadeDistance;                       // 170
		float                                                      tessellationBaseFactor;                         // 174
		bool                                                       tessellationNeedsDominantUVs;                   // 178
		bool                                                       tessellationNeedsCrackFreeNormals;              // 179
		bool                                                       environmentMapping;                             // 17A
		bool                                                       environmentMappingEye;                          // 17B
		bool                                                       environmentMappingWindow;                       // 17C
		float                                                      environmentMappingMaskScale;                    // 180
		std::int32_t                                               skyTYpe;                                        // 184
		bool                                                       reflectionsEnabled;                             // 188
		bool                                                       silhouetteReflectionsEnabled;                   // 189
		bool                                                       refractionsEnabled;                             // 18A
		bool                                                       depthEnabled;                                   // 18B
		bool                                                       vertexUVEnabled;                                // 18C
		bool                                                       vertexAlphaDepthEnabled;                        // 18D
		bool                                                       foggingEnabled;                                 // 18E
		bool                                                       falloffEnabled;                                 // 18F
		bool                                                       rgbFalloffEnabled;                              // 190
		NiColorA                                                   falloffData;                                    // 194
		bool                                                       softEnabled;                                    // 1A4
		float                                                      softDepth;                                      // 1A8
		NiPoint2                                                   uvOffset;                                       // 1AC
		NiPoint2                                                   uvScale;                                        // 1B4
		bool                                                       grayscaleToPaletteColor;                        // 1BC
		bool                                                       grayscaleToPaletteAlpha;                        // 1BD
		NiColor                                                    hairTintColor;                                  // 1C0
		NiPointer<BSShaderTextureSet>                              textureSet;                                     // 1D0
		REX::EnumSet<BSGraphics::TextureAddressMode, std::int32_t> clampMode;                                      // 1D8
	};
	static_assert(sizeof(BSShaderData) == 0x1E0);
}
