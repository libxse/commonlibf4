#pragma once

#include "RE/B/BGSKeywordForm.h"
#include "RE/B/BGSModelMaterialSwap.h"
#include "RE/T/TESBoundObject.h"

namespace RE
{
	class __declspec(novtable) BGSArtObject :
		public TESBoundObject,       // 00
		public BGSKeywordForm,       // 68
		public BGSModelMaterialSwap  // 88
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSArtObject };
		static constexpr auto VTABLE{ VTABLE::BGSArtObject };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kARTO };

		enum class ArtType
		{
			kMagicCastingArt = 0x0,
			kMagicHitEffect = 0x1,
			kMagicEnchantEffect = 0x2,

			kTotal = 0x3
		};

		class Data
		{
		public:
			// members
			REX::TEnumSet<ArtType, std::int32_t> artType;  // 0
		};
		static_assert(sizeof(Data) == 0x4);

		// members
		Data data;  // C8
	};
	static_assert(sizeof(BGSArtObject) == 0xD0);
}
