#pragma once

#include "RE/B/BSTArray.h"

namespace RE
{
	class DialogueResponse;
	class TESObjectREFR;
	class TESQuest;
	class TESTopic;
	class TESTopicInfo;

	class DialogueItem
	{
	public:
		~DialogueItem();

		DialogueResponse* GetCurrentResponse()
		{
			return currentResponse < responses.size() ? responses[currentResponse] : nullptr;
		}

		// members
		BSTArray<DialogueResponse*> responses{};                                        // 00
		TESTopicInfo*               info{};                                             // 18
		TESTopic*                   topic{};                                            // 20
		TESQuest*                   quest{};                                            // 28
		TESObjectREFR*              speaker{};                                          // 30
		std::uint32_t               currentResponse{ static_cast<std::uint32_t>(-1) };  // 38
		bool                        endResponse{ false };                               // 3C
		bool                        canSkip{ false };                                   // 3D
		bool                        subtitle{ false };                                  // 3E
	};
	static_assert(sizeof(DialogueItem) == 0x40);
}
