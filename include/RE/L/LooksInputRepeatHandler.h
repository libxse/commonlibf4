#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/B/BSInputEventUser.h"

namespace RE
{
	class __declspec(novtable) LooksInputRepeatHandler :
		public BSInputEventUser
	{
	public:
		// members
		float          repeatTimerArray[3];        // 0x10
		float          longRepeatRate;             // 0x1C
		float          shortRepeatRate;            // 0x20
		BSFixedString* lastEventArray[3];          // 0x28
		bool           processInputEventArray[3];  // 0x40
		bool           sculptMode;                 // 0x43
		bool           featureMode;                // 0x44
		bool           bumpersRepeat;              // 0x45
	};
	static_assert(sizeof(LooksInputRepeatHandler) == 0x48);
}
