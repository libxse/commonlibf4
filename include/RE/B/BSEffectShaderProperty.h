#pragma once

#include "RE/B/BSShaderProperty.h"
#include "RE/N/NiColor.h"

namespace RE
{
	class BSParticleShaderCubeEmitter;

	class __declspec(novtable) BSEffectShaderProperty :
		public BSShaderProperty  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BSEffectShaderProperty };
		static constexpr auto VTABLE{ VTABLE::BSEffectShaderProperty };
		static constexpr auto Ni_RTTI{ Ni_RTTI::BSEffectShaderProperty };

		F4_HEAP_REDEFINE_NEW(BSEffectShaderProperty);

		// members
		BSParticleShaderCubeEmitter* envCubeEmitter;     // 70
		NiColor*                     externalEmitColor;  // 78
		std::uint32_t                baseTextureIndex;   // 80
		float                        unk84;              // 84
	};
	static_assert(sizeof(BSEffectShaderProperty) == 0x88);
}
