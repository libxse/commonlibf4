#pragma once

#include "RE/N/NiMatrix3.h"
#include "RE/N/NiPoint.h"
#include "RE/N/NiPointer.h"
#include "RE/P/Projectile.h"

namespace RE
{
	enum class ImpactResult;
	class bhkNPCollisionObject;

	class __declspec(novtable) MissileProjectile :
		public Projectile  // 000
	{
	public:
		static constexpr auto RTTI{ RTTI::MissileProjectile };
		static constexpr auto VTABLE{ VTABLE::MissileProjectile };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kPMIS };

		// add
		virtual bool ShouldReorient() const;  // EA

		// members
		NiMatrix3                                 dismemberedLimbRotation;  // 270
		NiPoint3                                  dismemberedLimbOffset;    // 2A0
		NiPointer<bhkNPCollisionObject>           modelCollision;           // 2B0
		REX::TEnumSet<ImpactResult, std::int32_t> impactResult;             // 2B8
		bool                                      waitingToInitialize3D;    // 2BC
		bool                                      deferProcessImpale;       // 2BD
	};
	static_assert(sizeof(MissileProjectile) == 0x2C0);
}
