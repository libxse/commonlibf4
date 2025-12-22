#pragma once

namespace RE
{
	class ActionPoints
	{
	public:
		enum class Action
		{
			kUnarmed = 0x0,
			kOneHandMelee = 0x1,
			kTwoHandMelee = 0x2,
			kMagic = 0x3,
			kRanged = 0x4,
			kReload = 0x5,
			kSwitchWeapon = 0x6,
			kToggleWeaponDrawn = 0x7,
			kHeal = 0x8,
			kPlayerVATSDeath = 0x9,
			kPlayerDialogue = 0xA,
			kSightedEnter = 0xB,

			kTotal = 0xC
		};
	};
	static_assert(std::is_empty_v<ActionPoints>);
}
