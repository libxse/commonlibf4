#pragma once

#include "RE/B/BSStringT.h"
#include "RE/N/NiPoint.h"
#include "RE/N/NiPointer.h"
#include "RE/T/TESForm.h"

namespace RE
{
	class NiColorInterpolator;
	class NiFloatInterpolator;

	class __declspec(novtable) TESImageSpaceModifier :
		public TESForm  // 000
	{
	public:
		static constexpr auto RTTI{ RTTI::TESImageSpaceModifier };
		static constexpr auto VTABLE{ VTABLE::TESImageSpaceModifier };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kIMAD };

		enum class ImageSpaceModifierOperations
		{
			kMult = 0x0,
			kAdd = 0x1,
		};

		class ImageSpaceModifierData
		{
		public:
			// members
			bool          animatable;                           // 00
			float         duration;                             // 04
			std::uint32_t keySize[21][2];                       // 08
			std::uint32_t tintColorKeySize;                     // B0
			std::uint32_t blurKeySize;                          // B4
			std::uint32_t doubleKeySize;                        // B8
			std::uint32_t radialBlurStrengthKeySize;            // BC
			std::uint32_t radialBlurRampupKeySize;              // C0
			std::uint32_t radialBlurStartKeySize;               // C4
			bool          useTargetForRadialBlur;               // C8
			NiPoint2      radialBlurCenter;                     // CC
			std::uint32_t depthOfFieldStrengthKeySize;          // D4
			std::uint32_t depthOfFieldDistanceKeySize;          // D8
			std::uint32_t depthOfFieldRangeKeySize;             // DC
			bool          useTargetForDepthOfField;             // E0
			std::int8_t   depthOfFieldMode;                     // E1
			std::uint32_t radialBlurRampDownKeySize;            // E4
			std::uint32_t radialBlurDownStartKeySize;           // E8
			std::uint32_t fadeColorKeySize;                     // EC
			std::uint32_t motionBlurStrengthKeySize;            // F0
			std::uint32_t depthOfFieldVignetteRadiusKeySize;    // F4
			std::uint32_t depthOfFieldVignetteStrengthKeySize;  // F8
		};
		static_assert(sizeof(ImageSpaceModifierData) == 0xFC);

		// members
		ImageSpaceModifierData         data;                                      // 020
		NiPointer<NiFloatInterpolator> interpolator[21][2];                       // 120
		NiPointer<NiFloatInterpolator> blurInterpolator;                          // 270
		NiPointer<NiFloatInterpolator> doubleInterpolator;                        // 278
		NiPointer<NiColorInterpolator> tintColorInterpolator;                     // 280
		NiPointer<NiColorInterpolator> fadeColorInterpolator;                     // 288
		NiPointer<NiFloatInterpolator> radialBlurStrengthInterpolator;            // 290
		NiPointer<NiFloatInterpolator> radialBlurRampupInterpolator;              // 298
		NiPointer<NiFloatInterpolator> radialBlurStartInterpolator;               // 2A0
		NiPointer<NiFloatInterpolator> radialBlurRampDownInterpolator;            // 2A8
		NiPointer<NiFloatInterpolator> radialBlurDownStartInterpolator;           // 2B0
		NiPointer<NiFloatInterpolator> depthOfFieldStrengthInterpolator;          // 2B8
		NiPointer<NiFloatInterpolator> depthOfFieldDistanceInterpolator;          // 2C0
		NiPointer<NiFloatInterpolator> depthOfFieldRangeInterpolator;             // 2C8
		NiPointer<NiFloatInterpolator> depthOfFieldVignetteRadiusInterpolator;    // 2D0
		NiPointer<NiFloatInterpolator> depthOfFieldVignetteStrengthInterpolator;  // 2D8
		NiPointer<NiFloatInterpolator> motionBlurStrengthInterpolator;            // 2E0
		BSString                       formEditorID;                              // 2E8
	};
	static_assert(sizeof(TESImageSpaceModifier) == 0x2F8);
}
