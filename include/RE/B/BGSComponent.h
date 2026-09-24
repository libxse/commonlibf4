#pragma once

#include "RE/B/BGSCraftingUseSound.h"
#include "RE/T/TESBoundObject.h"
#include "RE/T/TESFullName.h"
#include "RE/T/TESValueForm.h"

namespace RE
{
	class __declspec(novtable) BGSComponent :
		public TESBoundObject,      // 00
		public TESFullName,         // 68
		public TESValueForm,        // 78
		public BGSCraftingUseSound  // 88
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSComponent };
		static constexpr auto VTABLE{ VTABLE::BGSComponent };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kCMPO };
		static constexpr auto TYPE_ID{ BSScript::kComponent };

		// members
		TESObjectMISC* scrapItem;       // 98
		TESGlobal*     modScrapScalar;  // A0
	};
	static_assert(sizeof(BGSComponent) == 0xA8);
}
