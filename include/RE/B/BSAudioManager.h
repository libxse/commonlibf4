#pragma once

#include "RE/B/BSAudioCallbacks.h"
#include "RE/B/BSAudioInit.h"
#include "RE/B/BSISoundDescriptor.h"
#include "RE/B/BSSoundHandle.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTHashMap.h"
#include "RE/N/NiPoint.h"
#include "RE/N/NiPointer.h"

namespace RE
{
	class BSAudioManagerThread;
	class BSGameSound;
	class BSISoundOutputModel;
	class BSMultisound;
	class BSSoundInfo;
	class NiAVObject;
	class SoundMessageList;
	class SoundMessageStack;

	class BSAudioManager
	{
	public:
		class SyncedPlaybackManager
		{
		public:
			// members
			BSTArray<BSTSmallArray<std::uint32_t, 2>*> syncFamilies;  // 00
		};
		static_assert(sizeof(SyncedPlaybackManager) == 0x18);

		[[nodiscard]] static BSAudioManager* GetSingleton()
		{
			static REL::Relocation<BSAudioManager**> singleton{ ID::BSAudioManager::Singleton };
			return *singleton;
		}

		void GetSoundHandleByName(BSSoundHandle& a_handle, const char* a_soundName, float a_distance, std::uint32_t a_usageFlags, BSISoundDescriptor::ExtraResolutionData* a_data)
		{
			using func_t = decltype(&BSAudioManager::GetSoundHandleByName);
			static REL::Relocation<func_t> func{ ID::BSAudioManager::GetSoundHandleByName };
			return func(this, a_handle, a_soundName, a_distance, a_usageFlags, a_data);
		}

		void GetSoundHandleByFile(BSSoundHandle& a_handle, const BSResource::ID& a_file, std::uint32_t a_usageFlags, std::uint8_t a_priority)
		{
			using func_t = decltype(&BSAudioManager::GetSoundHandleByFile);
			static REL::Relocation<func_t> func{ ID::BSAudioManager::GetSoundHandleByFile };
			return func(this, a_handle, a_file, a_usageFlags, a_priority);
		}

		// members
		std::int32_t                                              messageListIndex;            // 000
		std::int32_t                                              messageProcessingListIndex;  // 004
		SoundMessageList*                                         messages[2];                 // 008
		SoundMessageStack*                                        freeMessages;                // 018
		SoundMessageStack*                                        garbageMessages;             // 020
		BSTHashMap<std::uint32_t, BSGameSound*>                   soundMap;                    // 028
		BSTHashMap<std::uint32_t, BSSoundInfo*>                   soundStateMap;               // 058
		BSTHashMap<std::uint32_t, NiPointer<NiAVObject>>          movingRefrMap;               // 088
		BSTHashMap<const NiAVObject*, const BSISoundOutputModel*> outputOverrideMap;           // 0B8
		BSTHashMap<const BSISoundOutputModel*, float>             opmFrequencyOverrideMap;     // 0E8
		BSTHashMap<std::uint32_t, BSMultisound*>                  multisoundMap;               // 118
		BSTHashMap<const NiAVObject*, NiPoint3>                   locationOverrideMap;         // 148
		SyncedPlaybackManager                                     syncManager;                 // 178
		void*                                                     cachedSoundList;             // 190 - BSTList<BSGameSound*>
		std::uint32_t                                             currentCacheSize;            // 198
		std::uint32_t                                             audioThreadID;               // 19C
		BSAudioManagerThread*                                     updateThread;                // 1A0
		std::uint32_t                                             audioThreadSleepTime;        // 1A8
		std::uint32_t                                             audioHWThread;               // 1AC
		BSAudioInit                                               initSettings;                // 1B0
		std::uint32_t                                             audioCacheSize;              // 200
		std::uint32_t                                             maxAudioCacheSize;           // 204
		std::uint32_t                                             maxSizeForCachedSound;       // 208
		std::uint32_t                                             stateFlags;                  // 20C
		float                                                     masterVolume;                // 210
		std::uint8_t                                              asyncPriorityThreshold;      // 214
		float                                                     invSpeedInUnitsPerMS;        // 218
		BSAudioCallbacks                                          audioCallbacks;              // 220
	};
	static_assert(sizeof(BSAudioManager) == 0x238);
}
