#pragma once

#include "RE/B/BSSoundHandle.h"

namespace RE
{
	class BGSAwakeSoundData
	{
	public:
		enum class eState : std::uint32_t
		{
			kPlaying = 0x0,
			kPaused = 0x1,
			kStopped = 0x2,

			kTotal = 0x3
		};

		BSSoundHandle             sound;        // 00
		std::uint32_t             soundFormID;  // 08
		float                     volume;       // 0C
		BGSAwakeSoundData::eState state;        // 10
	};
	static_assert(sizeof(BGSAwakeSoundData) == 0x14);
}
