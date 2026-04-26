#pragma once

#include "RE/D/_D3DBLEND.h"
#include "RE/D/_D3DBLENDOP.h"
#include "RE/D/_D3DCMPFUNC.h"

namespace RE
{
	class EffectShaderData
	{
	public:
		// members
		REX::TEnumSet<_D3DBLEND, std::int32_t>   textureBlendModeSource;      // 00
		REX::TEnumSet<_D3DBLENDOP, std::int32_t> textureBlendOperation;       // 04
		REX::TEnumSet<_D3DCMPFUNC, std::int32_t> textureZTestFunction;        // 08
		std::uint32_t                            fillColor1;                  // 0C
		float                                    fillAlphaFadeInTime;         // 10
		float                                    fillAlphaFullTime;           // 14
		float                                    fillAlphaFadeOutTime;        // 18
		float                                    fillAlphaPersistentPercent;  // 1C
		float                                    fillAlphaPulseAmplitude;     // 20
		float                                    fillAlphaPulseFrequency;     // 24
		float                                    fillTextureUAnimSpeed;       // 28
		float                                    fillTextureVAnimSpeed;       // 2C
		float                                    edgeExponentValue;           // 30
		std::uint32_t                            edgeColor;                   // 34
		float                                    edgeAlphaFadeInTime;         // 38
		float                                    edgeAlphaFullTime;           // 3C
		float                                    edgeAlphaFadeOutTime;        // 40
		float                                    edgeAlphaPersistentPercent;  // 44
		float                                    edgeAlphaPulseAmplitude;     // 48
		float                                    edgeAlphaPulseFrequency;     // 4C
		float                                    fillAlphaFullPercent;        // 50
		float                                    edgeAlphaFullPercent;        // 54
		REX::TEnumSet<_D3DBLEND, std::int32_t>   textureBlendModeDest;        // 58
		float                                    alphaTestStartTime;          // 5C
		float                                    alphaTestEndTime;            // 60
		float                                    alphaTestStartValue;         // 64
		float                                    alphaTestEndValue;           // 68
		BGSSoundDescriptorForm*                  ambientSound;                // 70
		std::uint32_t                            fillColor2;                  // 78
		std::uint32_t                            fillColor3;                  // 7C
		float                                    fillColorScaleA[3];          // 80
		float                                    fillColorTimeA[3];           // 8C
		std::uint32_t                            flags;                       // 98
		float                                    fillTextureUScale;           // 9C
		float                                    fillTextureVScale;           // A0
		std::int8_t                              boneDepth;                   // A4
	};
	static_assert(sizeof(EffectShaderData) == 0xA8);
}
