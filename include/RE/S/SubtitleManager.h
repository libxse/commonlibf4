#pragma once

#include "RE/B/BSPointerHandle.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTEvent.h"
#include "RE/B/BSTSingleton.h"
#include "RE/H/HUDSubtitleDisplayEvent.h"
#include "RE/S/SubtitleInfo.h"

namespace RE
{
	class SubtitleManager :
		public BSTSingletonSDM<SubtitleManager>  // 00
	{
	public:
		[[nodiscard]] static SubtitleManager* GetSingleton()
		{
			static REL::Relocation<SubtitleManager**> singleton{ ID::SubtitleManager::Singleton };
			return *singleton;
		}

		[[nodiscard]] static BSReadWriteLock& GetRWLock()
		{
			static REL::Relocation<BSReadWriteLock*> rwLock{ ID::SubtitleManager::RWLock };
			return *rwLock;
		}

		// members
		BSTArray<SubtitleInfo, BSTArrayHeapAllocator> subtitlePriorityArray;  // 08
		ObjectRefHandle                               currentSpeaker;         // 20
		BSTValueEventSource<HUDSubtitleDisplayEvent>  subtitleDisplayData;    // 28
	};
	static_assert(sizeof(SubtitleManager) == 0x50);
}
