#pragma once

#include "RE/I/ImageSpaceEffect.h"

namespace RE
{
	class __declspec(novtable) ImageSpaceEffectTemporalAA :
		public ImageSpaceEffect  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::ImageSpaceEffectTemporalAA };
		static constexpr auto VTABLE{ VTABLE::ImageSpaceEffectTemporalAA };

		virtual ~ImageSpaceEffectTemporalAA();  // 00

		// override (ImageSpaceEffect)
		virtual void Render(BSTriShape* a_geometry, ImageSpaceEffectParam* a_param) override;       // 01
		virtual void Setup(ImageSpaceManager* a_manager, ImageSpaceEffectParam* a_param) override;  // 03
		virtual bool IsActive() override;                                                           // 08
		virtual bool UpdateParams(ImageSpaceEffectParam* a_param) override;                         // 09

		inline static std::uint32_t* GetMaskS()
		{
			static REL::Relocation<std::uint32_t*> value{ ID::ImageSpaceEffectTemporalAA::MaskS };
			return value.get();
		}

		// members
		float previousInvTexSizeX;         // B0
		float previousInvTexSizeY;         // B4
		float previousDynamicWidthRatio;   // B8
		float previousDynamicHeightRatio;  // BC
	};
	static_assert(sizeof(ImageSpaceEffectTemporalAA) == 0xC0);
}
