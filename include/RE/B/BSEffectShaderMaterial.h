#pragma once

#include "RE/B/BSShaderMaterial.h"

namespace RE
{
    class __declspec(novtable) BSEffectShaderMaterial :
        public BSShaderMaterial  // 00
    {
    public:
        static constexpr auto RTTI{ RTTI::BSEffectShaderMaterial };
        static constexpr auto VTABLE{ VTABLE::BSEffectShaderMaterial };

		// members
        float                   falloffStartAngle;          // 38
        float                   falloffStopAngle;           // 3C
        float                   falloffStartOpacity;        // 40
        float                   falloffStopOpacity;         // 44
        NiColorA                baseColor;                  // 48 - Alpha is Material Alpha
        NiPointer<NiTexture>    baseTexture;                // 58
        NiPointer<NiTexture>    grayscaleTexture;           // 60
        NiPointer<NiTexture>    environmentMapTexture;      // 68
        NiPointer<NiTexture>    environmentMapMaskTexture;  // 70
        NiPointer<NiTexture>    normalTexture;              // 78
        float                   softDepth;                  // 80
        float                   baseColorScale;             // 84
        BSFixedString           baseTextureName;            // 88
        BSFixedString           grayscaleTextureName;       // 90
        BSFixedString           envMapTextureName;          // 98
        BSFixedString           envMapMaskTextureName;      // A0
        BSFixedString           normalTextureName;          // A8
        union
        {
            float               environmentMaskScale;       // B0
            float               refractionPower;            // B0 - Needs kShaderFlags_Refraction
        };
        std::uint8_t            uTextureClampMode;          // B4
        std::uint8_t            uLightingInfluence;         // B5 - divided by 255
        std::uint8_t            uEnvironmentMapMinLOD;      // B6
        std::uint8_t            unkB7;                      // B7
    };
    static_assert(sizeof(BSEffectShaderMaterial) == 0xB8);
}
