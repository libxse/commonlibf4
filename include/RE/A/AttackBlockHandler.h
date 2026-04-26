#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/H/HeldStateHandler.h"
#include "RE/S/Setting.h"

namespace RE
{
	class AttackBlockHandler :
		public HeldStateHandler
	{
	public:
		static constexpr auto RTTI{ RTTI::AttackBlockHandler };
		static constexpr auto VTABLE{ VTABLE::AttackBlockHandler };

		enum class POWER_ATTACK_STATE
		{
			kNone = 0,
			kLeft,
			kRight,
			kDual,
		};

		// members
		std::uint64_t                                    dualAttackStartTime;         // 28
		BSFixedString                                    debounceEvent;               // 30
		REX::TEnumSet<POWER_ATTACK_STATE, std::uint32_t> checkForPowerAttack;         // 38
		std::uint32_t                                    numPowerAttacks;             // 3C
		SettingT<INISettingCollection>*                  initialDelay;                // 40
		SettingT<INISettingCollection>*                  subsequentDelay;             // 48
		float                                            attackTimer;                 // 50
		std::uint64_t                                    rightAttackTimestamp;        // 58
		float                                            rightAttackHeldSeconds;      // 60
		float                                            rightAttackLastHeldSeconds;  // 64
		float                                            rightAttackLatchEngage;      // 68
		float                                            rightAttackLatchRelease;     // 6C
		bool                                             debounce;                    // 70
		bool                                             castAttemptMade;             // 71
		bool                                             leftAttackButtonHeld;        // 72
		bool                                             rightAttackButtonHeld;       // 73
		bool                                             rightAttackQueued;           // 74
		bool                                             rightAttackPrevFrame;        // 75
		bool                                             setAttackTimer;              // 76
		bool                                             checkPostMeleeActions;       // 77
		bool                                             checkPostThrowActions;       // 78
	};
	static_assert(sizeof(AttackBlockHandler) == 0x80);
}
