#pragma once

#include "RE/I/ImageSpaceEffect.h"

namespace RE
{
	class __declspec(novtable) ImageSpaceEffectHDR :
		public ImageSpaceEffect  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::ImageSpaceEffectHDR };
		static constexpr auto VTABLE{ VTABLE::ImageSpaceEffectHDR };

		virtual ~ImageSpaceEffectHDR();  // 00

		// override (ImageSpaceEffect)
		virtual void Render(BSTriShape* a_geometry, ImageSpaceEffectParam* a_param) override;       // 01
		virtual void Setup(ImageSpaceManager* a_manager, ImageSpaceEffectParam* a_param) override;  // 03
		virtual void Shutdown() override;                                                           // 04
		virtual bool UpdateParams(ImageSpaceEffectParam* a_param) override;                         // 09

		inline static bool* GetUsePipboyScreenMask()
		{
			static REL::Relocation<bool*> value{ ID::ImageSpaceEffectHDR::UsePipboyScreenMask };
			return value.get();
		}
	};
	static_assert(sizeof(ImageSpaceEffectHDR) == 0xB0);
}
