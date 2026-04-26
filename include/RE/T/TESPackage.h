#pragma once

#include "RE/P/PACKAGE_DATA.h"
#include "RE/P/PackageEventAction.h"
#include "RE/P/PackageSchedule.h"
#include "RE/T/TESCondition.h"
#include "RE/T/TESForm.h"

namespace RE
{
	enum class PACKAGE_PROCEDURE_TYPE;
	class BGSIdleCollection;
	class PackageLocation;
	class PackageTarget;
	class TESPackageData;

	class __declspec(novtable) TESPackage :
		public TESForm  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::TESPackage };
		static constexpr auto VTABLE{ VTABLE::TESPackage };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kPACK };

		// add
		virtual bool IsActorAtLocation(Actor* a_ctor, bool a_ignoredistance, float a_extraRadius, bool a_infurniture);                                      // 4A
		virtual bool IsActorAtSecondLocation(Actor* a_mobileObject, Actor* a_packageowner, bool a_ignoredistance, float a_otherRadius, bool bInfurniture);  // 4B
		virtual bool IsActorAtRefTarget(Actor* a_mobileObject, std::int32_t a_extraRadius);                                                                 // 4C
		virtual bool IsTargetAtLocation(Actor* a_actor, std::int32_t a_extraRadius);                                                                        // 4D
		virtual bool IsPackageOwner(Actor*) { return true; }                                                                                                // 4E

		// members
		PACKAGE_DATA                                        data;            // 20
		TESPackageData*                                     packData;        // 30
		PackageLocation*                                    packLoc;         // 38
		PackageTarget*                                      packTarg;        // 40
		BGSIdleCollection*                                  idleCollection;  // 48
		PackageSchedule                                     packSched;       // 50
		TESCondition                                        packConditions;  // 60
		TESCombatStyle*                                     combatStyle;     // 68
		TESQuest*                                           ownerQuest;      // 70
		PackageEventAction                                  onBegin;         // 78
		PackageEventAction                                  onEnd;           // 90
		PackageEventAction                                  onChange;        // A8
		REX::TEnumSet<PACKAGE_PROCEDURE_TYPE, std::int32_t> procedureType;   // C0
		std::uint32_t                                       refCount;        // C4
	};
	static_assert(sizeof(TESPackage) == 0xC8);
}
