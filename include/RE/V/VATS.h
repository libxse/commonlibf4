#pragma once

#include "RE/B/BSSpinLock.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTEvent.h"
#include "RE/B/BSTSingleton.h"
#include "RE/B/BSTSmartPointer.h"
#include "RE/N/NiPointer.h"

namespace RE
{
	class BSLight;
	class ProjectileBeginUpdateEvent;
	class TESDeathEvent;
	class TESHitEvent;
	class VATSCameraContext;
	class VATSCommand;
	class WeaponFiredEvent;

	class __declspec(novtable) VATS :
		public BSTEventSink<WeaponFiredEvent>,            // 00
		public BSTEventSink<ProjectileBeginUpdateEvent>,  // 08
		public BSTEventSink<TESHitEvent>,                 // 10
		public BSTEventSink<TESDeathEvent>,               // 18
		public BSTSingletonSDM<VATS>                      // 20
	{
	public:
		static constexpr auto RTTI{ RTTI::VATS };
		static constexpr auto VTABLE{ VTABLE::VATS };

		enum class VATS_MODE_ENUM
		{
			kNone = 0x0,
			kPlayback = 0x1
		};

		virtual ~VATS();  // 00

		// override
		virtual BSEventNotifyControl ProcessEvent(const WeaponFiredEvent& a_event, BSTEventSource<WeaponFiredEvent>* a_source) override;                      // 01
		virtual BSEventNotifyControl ProcessEvent(const ProjectileBeginUpdateEvent& a_event, BSTEventSource<ProjectileBeginUpdateEvent>* a_source) override;  // 02
		virtual BSEventNotifyControl ProcessEvent(const TESHitEvent& a_event, BSTEventSource<TESHitEvent>* a_source) override;                                // 03
		virtual BSEventNotifyControl ProcessEvent(const TESDeathEvent& a_event, BSTEventSource<TESDeathEvent>* a_source) override;                            // 04

		[[nodiscard]] static VATS* GetSingleton()
		{
			static REL::Relocation<VATS**> singleton{ ID::VATS::Singleton };
			return *singleton;
		}

		// members
		BSTArray<BSTSmartPointer<VATSCommand>>       commands;                 // 28
		REX::TEnumSet<VATS_MODE_ENUM, std::uint32_t> mode;                     // 40
		VATSCameraContext*                           cameraContext;            // 48
		float                                        castingAfterKillDelay;    // 50
		NiPointer<Projectile>                        firstProjectile;          // 58
		NiPointer<Projectile>                        lastProjectile;           // 60
		float                                        fakeShotCounter;          // 68
		TESIdleForm*                                 meleeAttack;              // 70
		NiPointer<BSLight>                           VATSLight;                // 78
		std::int32_t                                 killCount;                // 80
		float                                        magicTimeSlowdown;        // 84
		float                                        playerMagicTimeSlowdown;  // 88
		NiPointer<TESObjectREFR>                     VATSTarget;               // 90
		NiPointer<Actor>                             VATSAttacker;             // 98
		NiPointer<Actor>                             stranger;                 // A0
		NiPointer<Projectile>                        predictionProjectile;     // A8
		BSTSmartPointer<VATSCommand>                 reloadCommand;            // B0
		BSTSmartPointer<VATSCommand>                 sightedCommand;           // B8
		float                                        VATSPlaybackTimer;        // C0
		float                                        VATSCommandTimer;         // C4
		bool                                         projectileNearTarget;     // C8
		bool                                         applyCritical;            // C9
		bool                                         firstAttackExecuted;      // CA
		bool                                         firstAttackFired;         // CB
		bool                                         readyForShutdown;         // CC
		bool                                         wantsStranger;            // CD
		BSSpinLock                                   spinLock;                 // D0
	};
	static_assert(sizeof(VATS) == 0xD8);
}
