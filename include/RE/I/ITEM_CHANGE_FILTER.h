#pragma once

namespace RE
{
	enum class ITEM_CHANGE_FILTER : std::uint32_t
	{
		kNone = 0x0,
		kFavorites = 0x1,
		kWeapons = 0x2,
		kApparel = 0x4,
		kAid = 0x8,
		kScrolls = 0x10,
		kFood = 0x20,
		kIngredients = 0x40,
		kBooks = 0x80,
		kKeys = 0x100,
		kMisc = 0x200,
		kJunk = 0x400,
		kMods = 0x800,
		kAmmo = 0x1000,
		kHolotapes = 0x2000,
		kTotal = 0xE,
		kAll = 0x3FFF
	};
}
