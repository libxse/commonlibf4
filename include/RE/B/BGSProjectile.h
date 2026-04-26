#pragma once

#include "RE/B/BGSDestructibleObjectForm.h"
#include "RE/B/BGSPreloadable.h"
#include "RE/B/BGSProjectileData.h"
#include "RE/T/TESBoundObject.h"
#include "RE/T/TESFullName.h"
#include "RE/T/TESModel.h"

namespace RE
{
	enum class SOUND_LEVEL;

	class __declspec(novtable) BGSProjectile :
		public TESBoundObject,            // 000
		public TESFullName,               // 068
		public TESModel,                  // 078
		public BGSPreloadable,            // 0A8
		public BGSDestructibleObjectForm  // 0B0
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSProjectile };
		static constexpr auto VTABLE{ VTABLE::BGSProjectile };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kPROJ };

		enum class BGSProjectileFlags
		{
			kHitscan = 0x1,
			kExplosion = 0x2,
			kExplosionAltTrigger = 0x4,
			kMuzzleFlash = 0x8,
			kBounceOnImpact = 0x10,
			kCanTurnOff = 0x20,
			kCanPickup = 0x40,
			kSupersonic = 0x80,
			kPinsLimbs = 0x100,
			kPassSMTransparent = 0x200,
			kDisableCombatAimCorrection = 0x400,
			kPenetratesGeometry = 0x800,
			kContinuousUpdate = 0x1000,
			kSeeksTarget = 0x2000,
			kFirstMotionBit = 0x10,
			kMotionMissile = 0x10000,
			kMotionGrenade = 0x20000,
			kMotionBeam = 0x40000,
			kMotionFlamethrower = 0x80000,
			kMotionCone = 0x100000,
			kMotionBarrier = 0x200000,
			kMotionArrow = 0x400000,
			kMotionTypes = 0x7F0000
		};

		bool CollidesWithSmallTransparentLayer()
		{
			using func_t = decltype(&BGSProjectile::CollidesWithSmallTransparentLayer);
			static REL::Relocation<func_t> func{ ID::BGSProjectile::CollidesWithSmallTransparentLayer };
			return func(this);
		}

		// members
		BGSProjectileData                        data;              // 0C0
		TESModel                                 muzzleFlashModel;  // 150
		REX::TEnumSet<SOUND_LEVEL, std::int32_t> soundLevel;        // 180
	};
	static_assert(sizeof(BGSProjectile) == 0x188);
}
