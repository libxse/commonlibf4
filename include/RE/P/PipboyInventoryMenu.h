#pragma once

#include "RE/P/PipboySubMenu.h"

namespace RE
{
	class __declspec(novtable) PipboyInventoryMenu :
		public PipboySubMenu  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::PipboyInventoryMenu };
		static constexpr auto VTABLE{ VTABLE::PipboyInventoryMenu };

		// override (PipboySubMenu)
		void UpdateData() override
		{
			using func_t = decltype(&PipboyInventoryMenu::UpdateData);
			static REL::Relocation<func_t> func{ ID::PipboyInventoryMenu::UpdateData };
			return func(this);
		}

		void SetQuickkey(int a_selectedIndex, int a_quickkeyIndex)
		{
			using func_t = decltype(&PipboyInventoryMenu::SetQuickkey);
			static REL::Relocation<func_t> func{ ID::PipboyInventoryMenu::SetQuickkey };
			return func(this, a_selectedIndex, a_quickkeyIndex);
		}

		void SortItems(unsigned int a_filterIndex)
		{
			using func_t = decltype(&PipboyInventoryMenu::SortItems);
			static REL::Relocation<func_t> func{ ID::PipboyInventoryMenu::SortItems };
			return func(this, a_filterIndex);
		}
	};
	static_assert(sizeof(PipboyInventoryMenu) == 0x18);
}
