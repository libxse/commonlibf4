#pragma once

#include "RE/B/BSIMusicTrack.h"
#include "RE/B/BSTArray.h"

namespace RE
{
	class __declspec(novtable) BSIMusicType
	{
	public:
		static constexpr auto RTTI{ RTTI::BSIMusicType };
		static constexpr auto VTABLE{ VTABLE::BSIMusicType };

		// add
		virtual void DoUpdate() = 0;                                                                  // 00
		virtual void DoPlay() = 0;                                                                    // 01
		virtual void DoPause() = 0;                                                                   // 02
		virtual void DoFinish(bool a_immediate) = 0;                                                  // 03
		virtual void DoApplyDuckingAttenuation([[maybe_unused]] std::uint16_t a_ducking) { return; }  // 04
		virtual void DoClearDucking() { return; }                                                     // 05
		virtual void DoPrepare() { return; }                                                          // 06

		virtual ~BSIMusicType();  // 07

		// members
		std::uint32_t                                            flags;              // 08
		std::int8_t                                              priority;           // 0C
		std::int8_t                                              padding;            // 0D
		std::uint16_t                                            ducksOtherMusicBy;  // 0E
		float                                                    fadeTime;           // 10
		std::uint32_t                                            currentTrackIndex;  // 14
		BSTArray<std::uint32_t>                                  trackHistory;       // 18
		BSTArray<BSIMusicTrack*>                                 tracks;             // 30
		REX::TEnumSet<BSIMusicTrack::MUSIC_STATUS, std::int32_t> typeStatus;         // 48
	};
	static_assert(sizeof(BSIMusicType) == 0x50);
}
