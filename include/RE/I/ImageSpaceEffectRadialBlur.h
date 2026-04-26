#pragma once

#include "RE/I/ImageSpaceEffect.h"

namespace RE
{
	class __declspec(novtable) ImageSpaceEffectRadialBlur :
		public ImageSpaceEffect  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::ImageSpaceEffectRadialBlur };
		static constexpr auto VTABLE{ VTABLE::ImageSpaceEffectRadialBlur };

		virtual ~ImageSpaceEffectRadialBlur();  // 00

		// override (ImageSpaceEffect)
		virtual void Setup(ImageSpaceManager* a_manager, ImageSpaceEffectParam* a_param) override;  // 03
		virtual bool IsActive() override;                                                           // 08
		virtual bool UpdateParams(ImageSpaceEffectParam* a_param) override;                         // 09

		inline static bool* GetDisable()
		{
			static REL::Relocation<bool*> value{ ID::ImageSpaceEffectRadialBlur::Disable };
			return value.get();
		}
	};
	static_assert(sizeof(ImageSpaceEffectRadialBlur) == 0xB0);
}
