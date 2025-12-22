#pragma once

#include "RE/B/BSFixedString.h"

namespace RE
{
	class BGSKeyword;
	class BGSSoundDescriptorForm;
	class TESIdleForm;

	class DialogueResponse
	{
	public:
		// members
		BSFixedStringCS         text;              // 00
		BGSKeyword*             animFaceArchType;  // 08
		std::uint16_t           percent;           // 10
		BSFixedString           voice;             // 18
		TESIdleForm*            speakerIdle;       // 20
		TESIdleForm*            listenIdle;        // 28
		BGSSoundDescriptorForm* voiceSound;        // 30
		bool                    useEmotion;        // 38
		bool                    soundLip;          // 39
		bool                    endOnSceneEnd;     // 3A
	};
	static_assert(sizeof(DialogueResponse) == 0x40);
}
