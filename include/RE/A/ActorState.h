#pragma once

#include "RE/I/IMovementState.h"
#include "RE/W/WEAPON_STATE.h"

namespace RE
{
	enum class GUN_STATE;
	enum class INTERACTING_STATE;
	enum class SIT_SLEEP_STATE;

	class __declspec(novtable) ActorState :
		public IMovementState  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::ActorState };
		static constexpr auto VTABLE{ VTABLE::ActorState };

		// add
		virtual bool            SetWeaponMagicDrawn(bool a_drawn);                // 21
		virtual bool            SetWeaponState(WEAPON_STATE a_state);             // 22
		virtual bool            DoSetSitSleepState(SIT_SLEEP_STATE a_state) = 0;  // 23
		virtual SIT_SLEEP_STATE DoGetSitSleepState() const = 0;                   // 24
		virtual bool            SetInIronSightsImpl(bool a_sighted) = 0;          // 25
		virtual void            SetReloadingImpl(bool a_reloading);               // 26

		[[nodiscard]] bool GetWeaponMagicDrawn() const noexcept { return weaponState >= WEAPON_STATE::kDrawn; }
		[[nodiscard]] bool IsSwimming() const noexcept { return DoGetMoveModeBits(0x400); }

		// members
		std::uint32_t     moveMode: 14;            // 08:00
		std::uint32_t     flyState: 3;             // 08:14
		std::uint32_t     lifeState: 4;            // 08:17
		std::uint32_t     knockState: 4;           // 08:21
		std::uint32_t     meleeAttackState: 3;     // 08:25
		std::uint32_t     talkingToPlayer: 1;      // 08:28
		std::uint32_t     forceRun: 1;             // 08:29
		std::uint32_t     forceSneak: 1;           // 08:30
		std::uint32_t     headTracking: 1;         // 08:31
		std::uint32_t     reanimating: 1;          // 0C:00
		WEAPON_STATE      weaponState: 3;          // 0C:01
		std::uint32_t     wantBlocking: 1;         // 0C:04
		std::uint32_t     flightBlocked: 1;        // 0C:05
		std::uint32_t     recoil: 2;               // 0C:06
		std::uint32_t     allowFlying: 1;          // 0C:08
		std::uint32_t     staggered: 1;            // 0C:09
		std::uint32_t     inWrongProcessLevel: 1;  // 0C:10
		std::uint32_t     stance: 3;               // 0C:11
		GUN_STATE         gunState: 4;             // 0C:14
		INTERACTING_STATE interactingState: 2;     // 0C:18
		std::uint32_t     headTrackRotation: 1;    // 0C:20
		std::uint32_t     inSyncAnim: 1;           // 0C:21

	private:
		bool DoGetMoveModeBits(std::uint16_t a_bits) const { return (a_bits & moveMode & 0x3FFF) == a_bits; }
	};
	static_assert(sizeof(ActorState) == 0x10);
}
