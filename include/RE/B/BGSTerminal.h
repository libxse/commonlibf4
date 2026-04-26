#pragma once

#include "RE/B/BGSLocalizedString.h"
#include "RE/B/BSTArray.h"
#include "RE/T/TESCondition.h"
#include "RE/T/TESFurniture.h"

namespace RE
{
	enum class LOCK_LEVEL;
	class TESTexture;

	class __declspec(novtable) BGSTerminal :
		public TESFurniture  // 000
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSTerminal };
		static constexpr auto VTABLE{ VTABLE::BGSTerminal };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kTERM };

		class BodyTextItem
		{
		public:
			// members
			BGSLocalizedString itemText;    // 00
			TESCondition       conditions;  // 08
		};
		static_assert(sizeof(BodyTextItem) == 0x10);

		class MenuItem
		{
		public:
			enum class Flag
			{
				kBackToTop = 0x0,
				kRedraw = 0x1,
				kSubmenu = 0x2,
				kText = 0x3,
				kImage = 0x4,
				kHolotape = 0x5
			};

			union USelectionResult
			{
				BGSTerminal*        subMenu;
				BGSLocalizedString* displayText;
				TESTexture*         displayImage;
				BGSNote*            holotape;
			};
			static_assert(sizeof(USelectionResult) == 0x8);

			// members
			BGSLocalizedString               itemText;         // 00
			BGSLocalizedString               responseText;     // 08
			USelectionResult                 selectionResult;  // 10
			TESCondition                     conditions;       // 18
			std::uint16_t                    id;               // 20
			REX::TEnumSet<Flag, std::int8_t> flags;            // 22
		};
		static_assert(sizeof(MenuItem) == 0x28);

		LOCK_LEVEL GetHackDifficultyLockLevel(TESObjectREFR* a_refr)
		{
			using func_t = decltype(&BGSTerminal::GetHackDifficultyLockLevel);
			static REL::Relocation<func_t> func{ ID::BGSTerminal::GetHackDifficultyLockLevel };
			return func(this, a_refr);
		}

		static bool IsTerminalRefInUse(TESObjectREFR* a_refr)
		{
			using func_t = decltype(&BGSTerminal::IsTerminalRefInUse);
			static REL::Relocation<func_t> func{ ID::BGSTerminal::IsTerminalRefInUse };
			return func(a_refr);
		}

		static void Show(TESObjectREFR* a_refr)
		{
			using func_t = decltype(&BGSTerminal::Show);
			static REL::Relocation<func_t> func{ ID::BGSTerminal::Show };
			return func(a_refr);
		}

		// members
		BSTArray<BodyTextItem> bodyTextItems;       // 1A0
		BSTArray<MenuItem>     menuItems;           // 1B8
		BGSLocalizedString     headerTextOverride;  // 1D0
		BGSLocalizedString     welcomeText;         // 1D8
	};
	static_assert(sizeof(BGSTerminal) == 0x1E0);
}
