#pragma once

#include "RE/B/BSExternalAudioIO.h"

namespace RE
{
	class LipSynchAnim
	{
	public:
		// members
		std::uint32_t                   numFrames;          // 00
		std::int32_t                    startingFrame;      // 04
		std::uint32_t                   numPhonemeTargets;  // 08
		float**                         p_phonemes;         // 10
		float**                         modifiers;          // 18
		float*                          phonemes;           // 20
		bool                            hasGestures;        // 28
		std::uint32_t                   versionNumber;      // 2C
		BSExternalAudioIO::ExternalLoad voiceData;          // 30;
	};
	static_assert(sizeof(LipSynchAnim) == 0x48);
}
