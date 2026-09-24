#pragma once

#include "RE/B/BGSBodyPartDefs.h"
#include "RE/B/BGSObjectInstance.h"
#include "RE/B/BSPointerHandle.h"
#include "RE/B/BSSimpleList.h"
#include "RE/B/BSSoundHandle.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTSmartPointer.h"
#include "RE/H/hknpClosestUniqueBodyIdHitCollector.h"
#include "RE/N/NiPoint3.h"
#include "RE/N/NiPointer.h"
#include "RE/T/TESObjectREFR.h"

namespace RE
{
	class Actor;
	class ActorCause;
	class NiLight;
	class NonActorMagicCaster;

	class __declspec(novtable) Explosion :
		public TESObjectREFR  // 000
	{
	public:
		static constexpr auto RTTI{ RTTI::Explosion };
		static constexpr auto VTABLE{ VTABLE::Explosion };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kREFR };

		enum class Flags
		{
			kDecalsPlaced = 0x1,
			kTargetsFound = 0x2,
			kTargetsProcessed = 0x4,
			kForcesApplied = 0x8,
			kIgnoreIsSwap = 0x10,
			kUnderwater = 0x20,
			kInitialized = 0x40,
			kNonHostile = 0x80,
			kWaterTestDone = 0x100,
			kSoundTestDone = 0x200
		};

		class ExplodedLimb
		{
		public:
			// members
			REX::TEnumSet<BGSBodyPartDefs::LIMB_ENUM, std::int32_t> limb;           // 00
			ActorValueInfo*                                         limbCondition;  // 08
			float                                                   distance;       // 10
		};
		static_assert(sizeof(ExplodedLimb) == 0x18);

		class ExplosionTarget
		{
		public:
			enum class Flags
			{
				kHitWeakPoint = 0x1,
				kMobile = 0x2,
				kProcessed = 0x4,
				kProcessedLimbs = 0x8
			};

			// members
			ObjectRefHandle                     ref;                     // 00
			REX::TEnumSet<Flags, std::uint32_t> flags;                   // 04
			float                               hitFromExplosionSqrLen;  // 08
			BSTArray<ExplodedLimb>              limbArray;               // 10
		};
		static_assert(sizeof(ExplosionTarget) == 0x28);

		// add
		virtual void Initialize();           // C6
		virtual void Update(float a_delta);  // C7
		virtual void FindTargets();          // C8

		// Whoever set the blast off, or null when the owner has gone away or is
		// not an actor. This is the aggressor the engine credits an explosion's
		// blows to.
		[[nodiscard]] Actor* GetActorOwner()
		{
			using func_t = decltype(&Explosion::GetActorOwner);
			static REL::Relocation<func_t> func{ ID::Explosion::GetActorOwner };
			return func(this);
		}

		// What the blast is worth. Worked out from the explosion record's damage
		// and this explosion's damageMult the first time anything asks, then kept
		// in calculatedDamage and handed back unchanged after that.
		//
		// Every question the engine asks about a live blast is answered from
		// here, from whether it is worth looking for targets at all to what each
		// of them loses. The item card is the one thing that does not come
		// through it, because a weapon being looked at has set nothing off, so
		// CombatFormulas::GetWeaponDisplayDamage reads the explosion record
		// instead and the two arrive at the same number by different routes.
		[[nodiscard]] float GetDamage()
		{
			using func_t = decltype(&Explosion::GetDamage);
			static REL::Relocation<func_t> func{ ID::Explosion::GetDamage };
			return func(this);
		}

		// Deals the blast to each target FindTargets gathered that is not
		// kProcessed yet, marks it so, and marks the explosion
		// kTargetsProcessed. An actor is struck with a blow filled in from the
		// explosion, unless the explosion is kNonHostile, and has the
		// explosion's object effect cast on it. Anything else takes the blast's
		// damage.
		void ProcessTargets()
		{
			using func_t = decltype(&Explosion::ProcessTargets);
			static REL::Relocation<func_t> func{ ID::Explosion::ProcessTargets };
			return func(this);
		}

		// members
		hknpClosestUniqueBodyIdHitCollector collector;           // 110
		void*                               explosionDBHandle;   // 520 - TODO
		float                               age;                 // 528
		float                               obj3Dlifetime;       // 52C
		float                               audioLifetime;       // 530
		float                               buildTime;           // 534
		float                               innerRadius;         // 538
		float                               outerRadius;         // 53C
		float                               imageSpaceRadius;    // 540
		float                               damageMult;          // 544
		BSSimpleList<ExplosionTarget*>      targetList;          // 548
		BSTSmallArray<BSSoundHandle, 4>     soundHandles;        // 558
		NiPointer<NiLight>                  light;               // 588
		ObjectRefHandle                     owner;               // 590
		ObjectRefHandle                     explodedRef;         // 594
		ObjectRefHandle                     createdRef;          // 598
		BSTSmartPointer<ActorCause>         actorCause;          // 5A0
		NonActorMagicCaster*                caster;              // 5A8
		BGSObjectInstanceT<TESObjectWEAP>   weaponSource;        // 5B0
		std::int32_t                        frameCount;          // 5C0
		NiPoint3A                           closestPoint;        // 5D0
		NiPoint3A                           closestPointNormal;  // 5E0
		float                               calculatedDamage;    // 5F0
		float                               scale;               // 5F4
		REX::TEnumSet<Flags, std::uint32_t> flags;               // 5F8
	};
	static_assert(sizeof(Explosion) == 0x600);
}
