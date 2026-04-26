#pragma once

#include "RE/T/TESForm.h"

namespace RE
{
	class __declspec(novtable) BGSReferenceEffect :
		public TESForm  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSReferenceEffect };
		static constexpr auto VTABLE{ VTABLE::BGSReferenceEffect };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kRFCT };

		enum class Flag
		{
			kNone = 0,
			kFaceTarget = 1 << 0,
			kAttachToCamera = 1 << 1,
			kInheritRotation = 1 << 2
		};

		class Data
		{
		public:
			// members
			BGSArtObject*                      artObject;     // 00
			TESEffectShader*                   effectShader;  // 08
			REX::TEnumSet<Flag, std::uint32_t> flags;         // 10
		};
		static_assert(sizeof(Data) == 0x18);

		// members
		Data data;  // 20
	};
	static_assert(sizeof(BGSReferenceEffect) == 0x38);
}
