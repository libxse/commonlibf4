#pragma once

namespace RE
{
	class CombatRange
	{
		float minRange;  // 00
		float maxRange;  // 04
	};
	static_assert(sizeof(CombatRange) == 0x8);
}
