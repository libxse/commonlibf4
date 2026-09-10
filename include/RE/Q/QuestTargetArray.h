#pragma once

#include "RE/B/BSTArray.h"

namespace RE
{
	class TESQuestTarget;

	class QuestTargetArray :
		public BSTArray<TESQuestTarget*>
	{
	public:
		// members
		std::uint64_t nextRepath;  // 018
	};
	static_assert(sizeof(QuestTargetArray) == 0x20);
}
