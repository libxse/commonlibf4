#pragma once

#include "RE/B/BSLightingShaderMaterialBase.h"

namespace RE
{
	class __declspec(novtable) BSLightingShaderMaterialSkinTint :
		public BSLightingShaderMaterialBase  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BSLightingShaderMaterialSkinTint };
		static constexpr auto VTABLE{ VTABLE::BSLightingShaderMaterialSkinTint };

		NiColorA kTintColor;  // C0
	};
	static_assert(sizeof(BSLightingShaderMaterialSkinTint) == 0xD0);
}
