#pragma once

#include "RE/B/BSActorPathingMessageQueue.h"
#include "RE/B/BSPointerHandle.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTSmartPointer.h"
#include "RE/T/TESCondition.h"
#include "RE/T/TeleportPath.h"

namespace RE
{
	class BGSKeyword;

	class TESQuestTarget
	{
	public:
		class REF_DATA
		{
		public:
			TeleportPath                                teleportPath;        // 00
			ObjectRefHandle                             reference;           // 50
			BSTSmartPointer<BSActorPathingMessageQueue> pathMessageQueue;    // 58
			bool                                        forceRebuildQueued;  // 60
		};

		std::uint8_t                        flags;        // 00
		TESCondition                        conditions;   // 08
		std::uint32_t                       targetAlias;  // 10
		BGSKeyword*                         keyword;      // 18
		BSTArray<TESQuestTarget::REF_DATA*> target;       // 20
	};
	static_assert(sizeof(TESQuestTarget) == 0x38);
}
