#pragma once

#include "RE/I/ImageSpaceEffect.h"

namespace RE
{
	class __declspec(novtable) ImageSpaceEffectScalableAmbientObscuranceCS :
	    public ImageSpaceEffect  // 000
	{
	public:
		static constexpr auto RTTI{ RTTI::ImageSpaceEffectScalableAmbientObscuranceCS };
		static constexpr auto VTABLE{ VTABLE::ImageSpaceEffectScalableAmbientObscuranceCS };

		~ImageSpaceEffectScalableAmbientObscuranceCS() override;  // 00

		// members
		std::byte pad0B0[0x70];    // 0B0
		bool      saoEnabled;      // 120
		bool      saoToggleState;  // 121
		std::byte pad122[0x6];     // 122
	};
	static_assert(offsetof(ImageSpaceEffectScalableAmbientObscuranceCS, saoEnabled) == 0x120);
	static_assert(offsetof(ImageSpaceEffectScalableAmbientObscuranceCS, saoToggleState) == 0x121);
	static_assert(sizeof(ImageSpaceEffectScalableAmbientObscuranceCS) == 0x128);
}
