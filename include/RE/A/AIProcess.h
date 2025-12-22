#pragma once

#include "RE/A/AITimer.h"
#include "RE/A/ActorPackage.h"
#include "RE/B/BGSEquipIndex.h"
#include "RE/B/BGSObjectInstance.h"
#include "RE/B/BSPointerHandle.h"
#include "RE/B/BSSimpleList.h"
#include "RE/D/DEFAULT_OBJECT.h"
#include "RE/N/NiPoint.h"

namespace RE
{
	enum class COMMAND_TYPE;
	enum class DIALOGUE_SUBTYPE;
	enum class DIALOGUE_TYPE;
	enum class WEAPON_CULL_TYPE;
	class CachedValues;
	class HighProcessData;
	class MiddleHighProcessData;
	class MiddleLowProcessData;
	class ObjectstoAcquire;

	class AIProcess
	{
	public:
		enum class FADE_STATE
		{
			kNormal = 0x0,
			kIn = 0x1,
			kOut = 0x2,
			kTeleportIn = 0x3,
			kTeleportOut = 0x4,
			kOutDisable = 0x5,
			kOutDelete = 0x6
		};

		enum class HEAD_TRACK_TYPE
		{
			kDefault = 0x0,
			kAction = 0x1,
			kCombat = 0x2,
			kDialog = 0x3,
			kScript = 0x4,
			kProcedure = 0x5,
			kTotal = 0x6
		};

		[[nodiscard]] TESAmmo* GetCurrentAmmo(BGSEquipIndex a_equipIndex) const
		{
			using func_t = decltype(&AIProcess::GetCurrentAmmo);
			static REL::Relocation<func_t> func{ ID::AIProcess::GetCurrentAmmo };
			return func(this, a_equipIndex);
		}

		COMMAND_TYPE GetCommandType()
		{
			using func_t = decltype(&AIProcess::GetCommandType);
			static REL::Relocation<func_t> func{ ID::AIProcess::GetCommandType };
			return func(this);
		}

		[[nodiscard]] ObjectRefHandle GetOccupiedFurniture()
		{
			using func_t = decltype(&AIProcess::GetOccupiedFurniture);
			static REL::Relocation<func_t> func{ ID::AIProcess::GetOccupiedFurniture };
			return func(this);
		}

		bool IsWeaponSubgraphFinishedLoading(const Actor& a_actor)
		{
			using func_t = decltype(&AIProcess::IsWeaponSubgraphFinishedLoading);
			static REL::Relocation<func_t> func{ ID::AIProcess::IsWeaponSubgraphFinishedLoading };
			return func(this, a_actor);
		}

		void KnockExplosion(Actor* a_actor, const NiPoint3& a_location, float a_magnitude)
		{
			using func_t = decltype(&AIProcess::KnockExplosion);
			static REL::Relocation<func_t> func{ ID::AIProcess::KnockExplosion };
			return func(this, a_actor, a_location, a_magnitude);
		}

		bool PlayIdle(Actor& a_actor, TESIdleForm* a_idle, TESObjectREFR* a_target)
		{
			return SetupSpecialIdle(a_actor, DEFAULT_OBJECT::kActionIdle, a_idle, true, a_target);
		}

		bool ProcessGreet(Actor* a_actor, DIALOGUE_TYPE a_type, DIALOGUE_SUBTYPE a_subType, TESObjectREFR* a_target, BGSDialogueBranch* a_branch, bool a_forceSub, bool a_stop, bool a_que, bool a_sayCallback)
		{
			using func_t = decltype(&AIProcess::ProcessGreet);
			static REL::Relocation<func_t> func{ ID::AIProcess::ProcessGreet };
			return func(this, a_actor, a_type, a_subType, a_target, a_branch, a_forceSub, a_stop, a_que, a_sayCallback);
		}

		bool RequestLoadAnimationsForWeaponChange(Actor& a_actor)
		{
			using func_t = decltype(&AIProcess::RequestLoadAnimationsForWeaponChange);
			static REL::Relocation<func_t> func{ ID::AIProcess::RequestLoadAnimationsForWeaponChange };
			return func(this, a_actor);
		}

		void SetActorsDetectionEvent(Actor* a_actor, const NiPoint3& a_location, std::int32_t a_soundLevel, TESObjectREFR* a_refr)
		{
			using func_t = decltype(&AIProcess::SetActorsDetectionEvent);
			static REL::Relocation<func_t> func{ ID::AIProcess::SetActorsDetectionEvent };
			return func(this, a_actor, a_location, a_soundLevel, a_refr);
		}

		void SetCurrentAmmo(BGSEquipIndex a_equipIndex, TESAmmo* a_ammo)
		{
			using func_t = decltype(&AIProcess::SetCurrentAmmo);
			static REL::Relocation<func_t> func{ ID::AIProcess::SetCurrentAmmo };
			return func(this, a_equipIndex, a_ammo);
		}

		void SetCommandType(COMMAND_TYPE a_type)
		{
			using func_t = decltype(&AIProcess::SetCommandType);
			static REL::Relocation<func_t> func{ ID::AIProcess::SetCommandType };
			return func(this, a_type);
		}

		void SetEquippedItem(Actor* a_actor, const BGSObjectInstance& a_instance, const BGSEquipSlot* a_slot)
		{
			using func_t = decltype(&AIProcess::SetEquippedItem);
			static REL::Relocation<func_t> func{ ID::AIProcess::SetEquippedItem };
			return func(this, a_actor, a_instance, a_slot);
		}

		bool SetupSpecialIdle(Actor& a_actor, DEFAULT_OBJECT a_defaultObject, TESIdleForm* a_idle, bool a_testConditions, TESObjectREFR* a_targetOverride)
		{
			using func_t = decltype(&AIProcess::SetupSpecialIdle);
			static REL::Relocation<func_t> func{ ID::AIProcess::SetupSpecialIdle };
			return func(this, a_actor, a_defaultObject, a_idle, a_testConditions, a_targetOverride);
		}

		bool SetWeaponBonesCulled(const Actor& a_actor, bool a_stateToSet, WEAPON_CULL_TYPE a_weaponCullType)
		{
			using func_t = decltype(&AIProcess::SetWeaponBonesCulled);
			static REL::Relocation<func_t> func{ ID::AIProcess::SetWeaponBonesCulled };
			return func(this, a_actor, a_stateToSet, a_weaponCullType);
		}

		void StopCurrentIdle(Actor* a_actor, bool a_instant, bool a_killFlavor)
		{
			using func_t = decltype(&AIProcess::StopCurrentIdle);
			static REL::Relocation<func_t> func{ ID::AIProcess::StopCurrentIdle };
			return func(this, a_actor, a_instant, a_killFlavor);
		}

		void SetRunOncePackage(TESPackage* a_package, Actor* a_actor)
		{
			using func_t = decltype(&AIProcess::SetRunOncePackage);
			static REL::Relocation<func_t> func{ ID::AIProcess::SetRunOncePackage };
			return func(this, a_package, a_actor);
		}

		void AddToProcedureIndexRunning(Actor* a_actor, std::int32_t a_number)
		{
			using func_t = decltype(&AIProcess::AddToProcedureIndexRunning);
			static REL::Relocation<func_t> func{ ID::AIProcess::AddToProcedureIndexRunning };
			return func(this, a_actor, a_number);
		}

		void ComputeLastTimeProcessed()
		{
			using func_t = decltype(&AIProcess::ComputeLastTimeProcessed);
			static REL::Relocation<func_t> func{ ID::AIProcess::ComputeLastTimeProcessed };
			return func(this);
		}

		// members
		MiddleLowProcessData*           middleLow;                   // 00
		MiddleHighProcessData*          middleHigh;                  // 08
		HighProcessData*                high;                        // 10
		ActorPackage                    currentPackage;              // 18
		float                           hourLastProcessed;           // 48
		float                           timeAdjustmentsMade;         // 4C
		std::uint32_t                   dateLastProcessed;           // 50
		CachedValues*                   cachedValues;                // 58
		std::int32_t                    numberItemsActivate;         // 60
		BSSimpleList<ObjectstoAcquire*> objectList;                  // 68
		BSSimpleList<TESObjectREFR*>    genericLocationsList;        // 78
		ObjectstoAcquire*               acquireObject;               // 88
		ObjectstoAcquire*               savedAcquireObject;          // 90
		float                           essentialDownTimer;          // 98
		float                           deathTime;                   // 9C
		float                           trackedDamage;               // A0
		TESBoundObject*                 itemBeingUsed;               // A8
		AITimer                         combatDelayTimer;            // B0
		ObjectRefHandle                 followTarget;                // B8
		ObjectRefHandle                 target;                      // BC
		ObjectRefHandle                 genericLocation;             // C0
		ObjectRefHandle                 genericSecondLocation;       // C4
		BGSListForm*                    targetFormList;              // C8
		std::uint32_t                   currentSpeakingTopicID;      // D0
		ObjectRefHandle                 patrolLocation;              // D4
		ObjectRefHandle                 idleTarget;                  // D8
		std::int16_t                    formListNumb;                // DC
		std::uint8_t                    lowProcessFlags;             // DE
		std::uint8_t                    processLevel;                // DF
		bool                            skippedTimeStampForPathing;  // E0
		bool                            ignoringCombat;              // E1
		bool                            endAlarmOnActor;             // E2
		bool                            escortingPlayer;             // E3
		bool                            updateEditorDeadModel;       // E4
		bool                            editorDeadActive;            // E5
		bool                            initializingPosition;        // E6
	};
	static_assert(sizeof(AIProcess) == 0xE8);
}
