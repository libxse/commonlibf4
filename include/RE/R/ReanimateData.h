#pragma once

#include "RE/B/BSPointerHandle.h"

namespace RE
{
	class MagicItem;

	class ReanimateData
	{
	public:
		// members
		ActorHandle caster;          // 00
		MagicItem*  reanimateSpell;  // 08
	};
	static_assert(sizeof(ReanimateData) == 0x10);
}
