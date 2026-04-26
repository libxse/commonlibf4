#pragma once

#include "RE/B/BGSModelMaterialSwap.h"
#include "RE/B/BSFixedString.h"
#include "RE/B/BSTArray.h"
#include "RE/T/TESCondition.h"
#include "RE/T/TESForm.h"
#include "RE/T/TESFullName.h"
#include "RE/T/TESModel.h"
#include "RE/T/TESModelTri.h"

namespace RE
{
	class __declspec(novtable) BGSHeadPart :
		public TESForm,              // 000
		public TESFullName,          // 020
		public BGSModelMaterialSwap  // 030
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSHeadPart };
		static constexpr auto VTABLE{ VTABLE::BGSHeadPart };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kHDPT };

		enum class Flag
		{
			kPlayable = 1u << 0,
			kCantBeFemale = 1u << 1,
			kCantBeMale = 1u << 2,
			kExtraPart = 1u << 3,
			kUseSolidTint = 1u << 4,
			kUseBodyTexture = 1u << 5
		};

		enum class HeadPartType
		{
			kMisc = 0x0,
			kFace = 0x1,
			kEyes = 0x2,
			kHair = 0x3,
			kFacialHair = 0x4,
			kScar = 0x5,
			kEyebrows = 0x6,
			kMeatcaps = 0x7,
			kTeeth = 0x8,
			kHeadRear = 0x9
		};

		enum class MorphIndex
		{
			kRaceMorph = 0x0,
			kDefaultMorph = 0x1,
			kChargenMorph = 0x2
		};

		[[nodiscard]] bool IsExtraPart() const noexcept { return flags.all(Flag::kExtraPart); }

		// members
		REX::TEnumSet<Flag, std::uint8_t>         flags;              // 070
		REX::TEnumSet<HeadPartType, std::int32_t> type;               // 074
		BSTArray<BGSHeadPart*>                    extraParts;         // 078
		BGSTextureSet*                            textureSet;         // 090
		TESModel                                  ChargenModel;       // 098
		TESModelTri                               morphs[3];          // 0C8
		BGSColorForm*                             colorForm;          // 158
		BGSListForm*                              validRaces;         // 160
		TESCondition                              chargenConditions;  // 168
		BSFixedString                             formEditorID;       // 170
	};
	static_assert(sizeof(BGSHeadPart) == 0x178);
}
