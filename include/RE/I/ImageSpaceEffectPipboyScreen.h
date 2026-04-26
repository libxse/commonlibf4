#pragma once

#include "RE/I/ImageSpaceEffect.h"
#include "RE/N/NiPointer.h"

namespace RE
{
	class NiTexture;

	class __declspec(novtable) ImageSpaceEffectPipboyScreen :
		public ImageSpaceEffect  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::ImageSpaceEffectPipboyScreen };
		static constexpr auto VTABLE{ VTABLE::ImageSpaceEffectPipboyScreen };

		virtual ~ImageSpaceEffectPipboyScreen();  // 00

		// override (ImageSpaceEffect)
		virtual void Setup(ImageSpaceManager* a_manager, ImageSpaceEffectParam* a_param) override;  // 03
		virtual void ReturnTextures() override;                                                     // 06
		virtual bool UpdateParams(ImageSpaceEffectParam* a_param) override;                         // 09

		inline static bool* GetPowerArmorPipboy()
		{
			static REL::Relocation<bool*> value{ ID::ImageSpaceEffectPipboyScreen::PowerArmorPipboy };
			return value.get();
		}

		// members
		NiPointer<NiTexture> scanlineTexture;  // B0
		NiPointer<NiTexture> vScanTexture;     // B8
	};
	static_assert(sizeof(ImageSpaceEffectPipboyScreen) == 0xC0);
}
