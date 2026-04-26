#pragma once

#include "RE/I/ImageSpaceEffect.h"
#include "RE/I/ImageSpaceTexture.h"

namespace RE
{
	class __declspec(novtable) ImageSpaceEffectGetHit :
		public ImageSpaceEffect  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::ImageSpaceEffectGetHit };
		static constexpr auto VTABLE{ VTABLE::ImageSpaceEffectGetHit };

		virtual ~ImageSpaceEffectGetHit();  // 00

		// override (ImageSpaceEffect)
		virtual void Render(BSTriShape* a_geometry, ImageSpaceEffectParam* a_param) override;       // 01
		virtual void Setup(ImageSpaceManager* a_manager, ImageSpaceEffectParam* a_param) override;  // 03
		virtual void BorrowTextures(ImageSpaceEffectParam* a_param) override;                       // 05
		virtual void ReturnTextures() override;                                                     // 06
		virtual bool IsActive() override;                                                           // 08
		virtual bool UpdateParams(ImageSpaceEffectParam* a_param) override;                         // 09

		inline static bool* GetDisable()
		{
			static REL::Relocation<bool*> value{ ID::ImageSpaceEffectGetHit::Disable };
			return value.get();
		}

		// members
		float*            data;       // B0
		ImageSpaceTexture buffer[2];  // B8
	};
	static_assert(sizeof(ImageSpaceEffectGetHit) == 0x108);
}
