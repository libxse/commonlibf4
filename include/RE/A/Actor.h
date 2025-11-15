#pragma once

#include "RE/A/ACTOR_VISIBILITY_MASK.h"
#include "RE/A/AIProcess.h"
#include "RE/A/AITimeStamp.h"
#include "RE/A/ActorState.h"
#include "RE/A/ActorValueStorage.h"
#include "RE/B/BGSEquipIndex.h"
#include "RE/B/BSFixedString.h"
#include "RE/B/BSPointerHandle.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTEvent.h"
#include "RE/B/BSTSmartPointer.h"
#include "RE/C/CFilter.h"
#include "RE/I/IPostAnimationChannelUpdateFunctor.h"
#include "RE/M/MagicTarget.h"
#include "RE/M/Modifiers.h"
#include "RE/N/NiPoint.h"
#include "RE/N/NiTFlags.h"
#include "RE/O/ObjectEquipParams.h"
#include "RE/S/SEX.h"
#include "RE/T/TESObjectREFR.h"

namespace RE
{
	enum class ACTOR_CRITICAL_STAGE;
	enum class ACTOR_LIFE_STATE;
	enum class ACTOR_LOS_LOCATION;
	enum class GUN_STATE;
	enum class POWER_ATTACK_TYPE;

	template <class>
	class BSPointerHandleSmartPointer;

	class ActorCPMEvent;
	class ActorMagicCaster;
	class ActorMotionFeedbackData;
	class ActorMotionFeedbackOutput;
	class ActorMover;
	class bhkCharacterController;
	class bhkCharacterMoveFinishEvent;
	class bhkCharacterStateChangeEvent;
	class bhkNonSupportContactEvent;
	class BSMovementDataChangedEvent;
	class BSSubGraphActivationUpdate;
	class BSTransformDeltaEvent;
	class CastPowerItem;
	class CombatController;
	class CombatGroup;
	class MovementControllerNPC;
	class MovementMessageActorCollision;
	class MovementMessageNewPath;
	class MovementMessageUpdateRequestImmediate;
	class PackageLocation;
	class PerkEntryVisitor;
	class Perks;

	namespace MagicSystem
	{
		enum class CannotCastReason;
	}

	namespace PerkValueEvents
	{
		class PerkEntryUpdatedEvent;
		class PerkValueChangedEvent;
	}

	class __declspec(novtable) Actor :
		public TESObjectREFR,                                           // 000
		public MagicTarget,                                             // 110
		public ActorState,                                              // 128
		public BSTEventSink<BSMovementDataChangedEvent>,                // 138
		public BSTEventSink<BSTransformDeltaEvent>,                     // 140
		public BSTEventSink<BSSubGraphActivationUpdate>,                // 148
		public BSTEventSink<bhkCharacterMoveFinishEvent>,               // 150
		public BSTEventSink<bhkNonSupportContactEvent>,                 // 158
		public BSTEventSink<bhkCharacterStateChangeEvent>,              // 160
		public IPostAnimationChannelUpdateFunctor,                      // 168
		public BSTEventSource<MovementMessageUpdateRequestImmediate>,   // 170
		public BSTEventSource<PerkValueEvents::PerkValueChangedEvent>,  // 1C8
		public BSTEventSource<PerkValueEvents::PerkEntryUpdatedEvent>,  // 220
		public BSTEventSource<ActorCPMEvent>                            // 278
	{
	public:
		static constexpr auto RTTI{ RTTI::Actor };
		static constexpr auto VTABLE{ VTABLE::Actor };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kACHR };

		enum class BOOL_FLAGS
		{
			kNone = 0,
			kScenePackage = 1 << 0,
			kIsAMount = 1 << 1,
			kIsMountPointClear = 1 << 2,
			kIsGettingOnOffMount = 1 << 3,
			kInRandomScene = 1 << 4,
			kNoBleedoutRecovery = 1 << 5,
			kInBleedoutAnimation = 1 << 6,
			kCanDoFavor = 1 << 7,
			kShouldAnimGraphUpdate = 1 << 8,
			kCanSpeakToEssentialDown = 1 << 9,
			kBribedByPlayer = 1 << 10,
			kAngryWithPlayer = 1 << 11,
			kIsTresspassing = 1 << 12,
			kCanSpeak = 1 << 13,
			kIsInKillMove = 1 << 14,
			kAttackOnSight = 1 << 15,
			kIsCommandedActor = 1 << 16,
			kForceOneAnimGraphUpdate = 1 << 17,
			kEssential = 1 << 18,
			kProtected = 1 << 19,
			kAttackingDisabled = 1 << 20,
			kCastingDisabled = 1 << 21,
			kSceneHeadtrackRotation = 1 << 22,
			kForceIncMinBoneUpdate = 1 << 23,
			kCrimeSearch = 1 << 24,
			kMovingIntoLoadedArea = 1 << 25,
			kDoNotShowOnStealthMeter = 1 << 26,
			kMovementBlocked = 1 << 27,
			kAllowInstantFurniturePopInPlayerCell = 1 << 28,
			kForceAnimGraphUpdate = 1 << 29,
			kCheckAddEffectDualCast = 1 << 30,
			kUnderwater = 1 << 31,
		};

		enum class DETECTION_PRIORITY
		{
			kNone = 0x0,
			kVeryLow = 0x1,
			kLow = 0x2,
			kNormal = 0x3,
			kHigh = 0x4,
			kCritical = 0x5,
		};

		// add
		virtual void                 PlayPickUpSound(TESBoundObject* a_boundObj, bool a_pickUp, bool a_use);                                                                                                             // 0C6
		virtual float                GetHeading() const { return data.angle.z; }                                                                                                                                         // 0C7
		virtual void                 SetAvoidanceDisabled([[maybe_unused]] bool a_tf) { return; }                                                                                                                        // 0C8
		virtual void                 DrawWeaponMagicHands(bool a_draw);                                                                                                                                                  // 0C9
		virtual void                 SetPosition(const NiPoint3& a_pos, bool a_updateCharController);                                                                                                                    // 0CA
		virtual void                 KillDying();                                                                                                                                                                        // 0CB
		virtual void                 Resurrect(bool a_resetInventory, bool a_attach3D);                                                                                                                                  // 0CC
		virtual bool                 PutActorInChairBedQuick(TESObjectREFR* a_furniture, std::uint32_t a_index);                                                                                                         // 0CD
		virtual bool                 PutActorOnMountQuick();                                                                                                                                                             // 0CE
		virtual void                 Update(float a_delta);                                                                                                                                                              // 0CF
		virtual void                 UpdateNoAI(float);                                                                                                                                                                  // 0D0
		virtual void                 UpdateMotionDrivenState();                                                                                                                                                          // 0D1
		virtual void                 UpdateCharacterControllerSimulationSettings(bhkCharacterController& a_charController);                                                                                              // 0D2
		virtual void                 PotentiallyFixRagdollState();                                                                                                                                                       // 0D3
		virtual void                 UpdateNonRenderSafe(float);                                                                                                                                                         // 0D4
		virtual bool                 ShouldHandleEquipNow() const;                                                                                                                                                       // 0D5
		virtual void                 SetCrimeGoldValue(TESFaction* a_faction, bool a_violent, std::uint32_t a_value);                                                                                                    // 0D6
		virtual std::uint32_t        ModCrimeGoldValue(TESFaction* a_faction, bool a_violent, std::int32_t a_value);                                                                                                     // 0D7
		virtual void                 RemoveCrimeGoldValue(TESFaction* a_faction, bool a_violent, std::int32_t a_value);                                                                                                  // 0D8
		virtual std::uint32_t        GetCrimeGoldValue(const TESFaction* a_faction) const;                                                                                                                               // 0D9
		virtual void                 GoToPrison([[maybe_unused]] TESFaction* a_faction, [[maybe_unused]] bool a_removeItems, [[maybe_unused]] bool a_realJail) { return; }                                               // 0DA
		virtual void                 ServePrisonTime() { return; }                                                                                                                                                       // 0DB
		virtual void                 PayFine([[maybe_unused]] TESFaction* a_faction, [[maybe_unused]] bool a_movetoMarker, [[maybe_unused]] bool a_removeStolenItems) { return; }                                        // 0DC
		virtual float                GetCurrentEyeLevel() const;                                                                                                                                                         // 0DD
		virtual void                 SetInDialoguewithPlayer(bool a_flag);                                                                                                                                               // 0DE
		virtual bool                 GetCannibal() { return false; }                                                                                                                                                     // 0DF
		virtual void                 SetCannibal(bool) { return; }                                                                                                                                                       // 0E0
		virtual bool                 GetVampireFeed() { return false; }                                                                                                                                                  // 0E1
		virtual void                 SetVampireFeed(bool) { return; }                                                                                                                                                    // 0E2
		virtual void                 InitiateVampireFeedPackage(Actor* a_target, TESObjectREFR* a_furniture);                                                                                                            // 0E3
		virtual void                 InitiateCannibalPackage(Actor* a_target);                                                                                                                                           // 0E4
		virtual float                GetEyeHeading() const;                                                                                                                                                              // 0E5
		virtual void                 GetEyeAngles(float& a_eyeHeading, float& a_eyeLooking) const;                                                                                                                       // 0E6
		virtual void                 GetEyeVector(NiPoint3& a_origin, NiPoint3& a_direction, bool a_includeCameraOffset) const;                                                                                          // 0E7
		virtual void                 SetRefraction(bool a_enable, float a_refractionPower);                                                                                                                              // 0E8
		virtual float                GetAcrobatics() const { return 1.0F; }                                                                                                                                              // 0E9
		virtual bool                 Get3DUpdateFlag(RESET_3D_FLAGS a_flag) const;                                                                                                                                       // 0EA
		virtual ObjectRefHandle      DropObject(const BGSObjectInstance& a_object, BSTSmallArray<std::uint32_t, 4>* a_stackData, std::int32_t a_number, const NiPoint3* a_point, const NiPoint3* a_rotate);              // 0EB
		virtual void                 PickUpObject(TESObjectREFR* a_objREFR, std::int32_t a_count, bool a_playPickUpSounds);                                                                                              // 0EC
		virtual void                 AttachArrow(const BSTSmartPointer<BipedAnim>& a_biped, BGSEquipIndex a_equipIndex);                                                                                                 // 0ED
		virtual void                 DetachArrow(const BSTSmartPointer<BipedAnim>& a_biped, BGSEquipIndex a_equipIndex);                                                                                                 // 0EE
		virtual bool                 ReloadWeapon(const BGSObjectInstanceT<TESObjectWEAP>& a_weapon, BGSEquipIndex a_equipIndex);                                                                                        // 0EF
		virtual std::uint32_t        UseAmmo(const BGSObjectInstanceT<TESObjectWEAP>& a_weapon, BGSEquipIndex a_equipIndex, std::uint32_t a_shotCount);                                                                  // 0F0
		virtual bool                 CalculateCachedOwnerIsInCombatantFaction() const;                                                                                                                                   // 0F1
		virtual CombatGroup*         GetCombatGroup() const;                                                                                                                                                             // 0F2
		virtual void                 SetCombatGroup(CombatGroup* a_group);                                                                                                                                               // 0F3
		virtual bool                 CheckValidTarget(TESObjectREFR& a_ref) const;                                                                                                                                       // 0F4
		virtual bool                 InitiateDialogue(Actor* a_target, PackageLocation* a_packLoc, PackageLocation* a_packSecondLoc);                                                                                    // 0F5
		virtual void                 EndDialogue();                                                                                                                                                                      // 0F6
		virtual Actor*               SetUpTalkingActivatorActor(Actor* a_target, Actor*& a_talkingactivator);                                                                                                            // 0F7
		virtual void                 InitiateFlee(TESObjectREFR* a_fleeRef, bool a_runonce, bool a_knows, bool a_combatMode, TESObjectCELL* a_cell, TESObjectREFR* a_ref, float a_fleeFromDist, float a_fleeToDist);     // 0F8
		virtual void                 InitiateGetUpPackage();                                                                                                                                                             // 0F9
		virtual void                 PutCreatedPackage(TESPackage* a_pack, bool a_tempPack, bool a_isACreatedPackage, bool a_allowFromFurniture);                                                                        // 0FA
		virtual void                 UpdateAlpha();                                                                                                                                                                      // 0FB
		virtual void                 SetAlpha(float a_newAlpha);                                                                                                                                                         // 0FC
		virtual float                GetAlpha();                                                                                                                                                                         // 0FD
		virtual bool                 IsInCombat() const;                                                                                                                                                                 // 0FE
		virtual void                 UpdateCombat();                                                                                                                                                                     // 0FF
		virtual void                 StopCombat();                                                                                                                                                                       // 100
		virtual bool                 GetUsesAttackPercents() { return false; }                                                                                                                                           // 101
		virtual std::uint8_t         GetPowerAttackPercent(POWER_ATTACK_TYPE) { return 0; }                                                                                                                              // 102
		virtual void                 WeaponSwingCallBack(BGSEquipIndex a_equipIndex);                                                                                                                                    // 103
		virtual void                 SetActorStartingPosition();                                                                                                                                                         // 104
		virtual void                 SetLifeState(ACTOR_LIFE_STATE a_lifeState);                                                                                                                                         // 105
		virtual bool                 HasBeenAttacked();                                                                                                                                                                  // 106
		virtual void                 SetBeenAttacked(bool a_flag);                                                                                                                                                       // 107
		virtual void                 UseSkill(ActorValueInfo*, float, TESForm*) { return; }                                                                                                                              // 108
		virtual bool                 IsAtPoint(const NiPoint3& a_point, float a_radius, bool a_expandRadius, bool a_alwaysTestHeight);                                                                                   // 109
		virtual bool                 IsInFaction(const TESFaction* a_faction) const;                                                                                                                                     // 10A
		virtual bool                 HasPerkEntries(std::uint8_t a_entryPoint) const;                                                                                                                                    // 10B
		virtual void                 ForEachPerkEntry(std::uint8_t a_entryPoint, PerkEntryVisitor& a_visitor) const;                                                                                                     // 10C
		virtual void                 ApplyPerksFromBase();                                                                                                                                                               // 10D
		virtual void                 StartPowerAttackCoolDown() { return; }                                                                                                                                              // 10E
		virtual bool                 IsPowerAttackCoolingDown() const { return false; }                                                                                                                                  // 10F
		virtual void                 HandleHealthDamage(Actor* a_attacker, float a_damage);                                                                                                                              // 110
		virtual bool                 QSpeakingDone() const;                                                                                                                                                              // 111
		virtual void                 SetSpeakingDone(bool a_done);                                                                                                                                                       // 112
		virtual NiPoint3             CalculateLOSLocation(ACTOR_LOS_LOCATION a_location) const;                                                                                                                          // 113
		virtual void                 CreateMovementController();                                                                                                                                                         // 114
		virtual bool                 ShouldPivotToFaceCamera() const { return false; }                                                                                                                                   // 115
		virtual BGSKeyword*          GetSpeakingAnimArchType() { return speakingAnimArchType; }                                                                                                                          // 116
		virtual void                 KillImpl(Actor* a_attacker, float a_damage, bool a_sendEvent, bool a_ragdollInstant);                                                                                               // 117
		virtual void                 DoReparentWeapon(const TESObjectWEAP* a_weapon, BGSEquipIndex a_equipIndex, bool a_weaponDrawn);                                                                                    // 118
		virtual bool                 DrinkPotion(AlchemyItem* a_potion, std::uint32_t a_stackID);                                                                                                                        // 119
		virtual bool                 CheckCast(MagicItem* a_spell, bool a_dualCast, MagicSystem::CannotCastReason* a_reason);                                                                                            // 11A
		virtual void                 CheckTempModifiers() { return; }                                                                                                                                                    // 11B
		virtual void                 SetLastRiddenMount([[maybe_unused]] ActorHandle a_mount) { return; }                                                                                                                // 11C
		virtual ActorHandle          QLastRiddenMount() const;                                                                                                                                                           // 11D
		virtual bool                 CalculateCachedOwnerIsUndead() const;                                                                                                                                               // 11E
		virtual bool                 CalculateCachedOwnerIsNPC() const;                                                                                                                                                  // 11F
		virtual bool                 SetSneaking(bool a_sneaking);                                                                                                                                                       // 120
		virtual void                 ResetHavokPhysics();                                                                                                                                                                // 121
		virtual bool                 ShouldDoCharacterUpdate() const { return true; }                                                                                                                                    // 122
		virtual bool                 GetAnimationCanBeInterpolated() const;                                                                                                                                              // 123
		virtual const BSFixedString& GetResponseString() const;                                                                                                                                                          // 124
		virtual void                 ModifyMovementData(float a_delta, NiPoint3& a_moveDelta, NiPoint3& a_angleDelta);                                                                                                   // 125
		virtual void                 UpdateCombatControllerSettings();                                                                                                                                                   // 126
		virtual void                 UpdateFadeSettings(bhkCharacterController* a_charController);                                                                                                                       // 127
		virtual bool                 ComputeMotionFeedbackSpeedAndDirection(const ActorMotionFeedbackData& a_data, float a_delta, ActorMotionFeedbackOutput& a_retData);                                                 // 128
		virtual bool                 UpdateFeedbackGraphSpeedAndDirection(const ActorMotionFeedbackOutput& a_data);                                                                                                      // 129
		virtual void                 UpdateActor3DPosition();                                                                                                                                                            // 12A
		virtual void                 PrecacheData();                                                                                                                                                                     // 12B
		virtual void                 WornArmorChanged(const BGSObjectInstance& a_object);                                                                                                                                // 12C
		virtual void                 ProcessTracking(float a_delta, NiAVObject* a_ob3D);                                                                                                                                 // 12D
		virtual void                 CreateActorMover();                                                                                                                                                                 // 12E
		virtual void                 DestroyActorMover();                                                                                                                                                                // 12F
		virtual bool                 ShouldRespondToActorCollision(const MovementMessageActorCollision&, const BSPointerHandleSmartPointer<BSPointerHandleManagerInterface<Actor, HandleManager>>& a_otherActor) const;  // 130
		virtual float                CheckClampDamageModifier(ActorValueInfo& a_info, float a_delta);                                                                                                                    // 131
		virtual void                 ValidateNewPath([[maybe_unused]] const MovementMessageNewPath& a_newPathMessage) { return; }                                                                                        // 132

		void AddPerk(BGSPerk* a_perk, std::uint8_t a_rank = 0)
		{
			using func_t = decltype(&Actor::AddPerk);
			static REL::Relocation<func_t> func{ ID::Actor::AddPerk };
			return func(this, a_perk, a_rank);
		}

		bool CanUseIdle(TESIdleForm* a_idle) const
		{
			using func_t = decltype(&Actor::CanUseIdle);
			static REL::Relocation<func_t> func{ ID::Actor::CanUseIdle };
			return func(this, a_idle);
		}

		void ClearAttackStates()
		{
			using func_t = decltype(&Actor::ClearAttackStates);
			static REL::Relocation<func_t> func{ ID::Actor::ClearAttackStates };
			return func(this);
		}

		void EndInterruptPackage(bool a_notRunOnceDialogue)
		{
			using func_t = decltype(&Actor::EndInterruptPackage);
			static REL::Relocation<func_t> func{ ID::Actor::EndInterruptPackage };
			return func(this, a_notRunOnceDialogue);
		}

		void ExitCover()
		{
			using func_t = decltype(&Actor::ExitCover);
			static REL::Relocation<func_t> func{ ID::Actor::ExitCover };
			return func(this);
		}

		void GetAimVector(NiPoint3& a_aimVector)
		{
			using func_t = decltype(&Actor::GetAimVector);
			static REL::Relocation<func_t> func{ ID::Actor::GetAimVector };
			return func(this, a_aimVector);
		}

		NiAVObject* GetClosestBone(NiPoint3 a_impactLocation, NiPoint3 a_movementDirection)
		{
			using func_t = decltype(&Actor::GetClosestBone);
			static REL::Relocation<func_t> func{ ID::Actor::GetClosestBone };
			return func(this, a_impactLocation, a_movementDirection);
		}

		CFilter GetCollisionFilter()
		{
			using func_t = decltype(&Actor::GetCollisionFilter);
			static REL::Relocation<func_t> func{ ID::Actor::GetCollisionFilter };
			return func(this);
		}

		TESCombatStyle* GetCombatStyle()
		{
			using func_t = decltype(&Actor::GetCombatStyle);
			static REL::Relocation<func_t> func{ ID::Actor::GetCombatStyle };
			return func(this);
		}

		[[nodiscard]] TESAmmo* GetCurrentAmmo(BGSEquipIndex a_equipIndex) const
		{
			return currentProcess ? currentProcess->GetCurrentAmmo(a_equipIndex) : nullptr;
		}

		void SetCurrentAmmoCount(BGSEquipIndex a_equipIndex, std::uint32_t a_count)
		{
			using func_t = decltype(&Actor::SetCurrentAmmoCount);
			static REL::Relocation<func_t> func{ ID::Actor::SetCurrentAmmoCount };
			return func(this, a_equipIndex, a_count);
		}

		std::uint32_t GetCurrentCollisionGroup()
		{
			using func_t = decltype(&Actor::GetCurrentCollisionGroup);
			static REL::Relocation<func_t> func{ ID::Actor::GetCurrentCollisionGroup };
			return func(this);
		}

		bool GetCurrentFireLocation(BGSEquipIndex a_index, NiPoint3& a_fireLocation)
		{
			using func_t = decltype(&Actor::GetCurrentFireLocation);
			static REL::Relocation<func_t> func{ ID::Actor::GetCurrentFireLocation };
			return func(this, a_index, a_fireLocation);
		}

		float GetDesiredSpeed()
		{
			using func_t = decltype(&Actor::GetDesiredSpeed);
			static REL::Relocation<func_t> func{ ID::Actor::GetDesiredSpeed };
			return func(this);
		}

		[[nodiscard]] bool GetHostileToActor(Actor* a_actor)
		{
			using func_t = decltype(&Actor::GetHostileToActor);
			static REL::Relocation<func_t> func{ ID::Actor::GetHostileToActor };
			return func(this, a_actor);
		}

		[[nodiscard]] ActorHandle GetMountHandle()
		{
			using func_t = decltype(&Actor::GetMountHandle);
			static REL::Relocation<func_t> func{ ID::Actor::GetMountHandle };
			return func(this);
		}

		[[nodiscard]] std::int16_t GetLevel()
		{
			using func_t = decltype(&Actor::GetLevel);
			static REL::Relocation<func_t> func{ ID::Actor::GetLevel };
			return func(this);
		}

		[[nodiscard]] TESNPC* GetNPC() const noexcept;

		[[nodiscard]] std::uint8_t GetPerkRank(BGSPerk* a_perk)
		{
			using func_t = decltype(&Actor::GetPerkRank);
			static REL::Relocation<func_t> func{ ID::Actor::GetPerkRank };
			return func(this, a_perk);
		}

		SEX GetSex()
		{
			using func_t = decltype(&Actor::GetSex);
			static REL::Relocation<func_t> func{ ID::Actor::GetSex };
			return func(this);
		}

		void HandleDefaultAnimationSwitch()
		{
			using func_t = decltype(&Actor::HandleDefaultAnimationSwitch);
			static REL::Relocation<func_t> func{ ID::Actor::HandleDefaultAnimationSwitch };
			return func(this);
		}

		void HandleItemEquip(bool bCullBone)
		{
			using func_t = decltype(&Actor::HandleItemEquip);
			static REL::Relocation<func_t> func{ ID::Actor::HandleItemEquip };
			return func(this, bCullBone);
		}

		void InitiateDoNothingPackage()
		{
			using func_t = decltype(&Actor::InitiateDoNothingPackage);
			static REL::Relocation<func_t> func{ ID::Actor::InitiateDoNothingPackage };
			return func(this);
		}

		bool IsCrippled()
		{
			using func_t = decltype(&Actor::IsCrippled);
			static REL::Relocation<func_t> func{ ID::Actor::IsCrippled };
			return func(this);
		}

		bool IsFollowing()
		{
			using func_t = decltype(&Actor::IsFollowing);
			static REL::Relocation<func_t> func{ ID::Actor::IsFollowing };
			return func(this);
		}

		[[nodiscard]] bool IsJumping()
		{
			using func_t = decltype(&Actor::IsJumping);
			static REL::Relocation<func_t> func{ ID::Actor::IsJumping };
			return func(this);
		}

		bool IsPathValid()
		{
			using func_t = decltype(&Actor::IsPathValid);
			static REL::Relocation<func_t> func{ ID::Actor::IsPathValid };
			return func(this);
		}

		bool IsPathing()
		{
			using func_t = decltype(&Actor::IsPathing);
			static REL::Relocation<func_t> func{ ID::Actor::IsPathing };
			return func(this);
		}

		bool IsPathingComplete()
		{
			using func_t = decltype(&Actor::IsPathingComplete);
			static REL::Relocation<func_t> func{ ID::Actor::IsPathingComplete };
			return func(this);
		}

		bool IsQuadruped()
		{
			using func_t = decltype(&Actor::IsQuadruped);
			static REL::Relocation<func_t> func{ ID::Actor::IsQuadruped };
			return func(this);
		}

		bool IsSneaking()
		{
			using func_t = decltype(&Actor::IsSneaking);
			static REL::Relocation<func_t> func{ ID::Actor::IsSneaking };
			return func(this);
		}

		bool IsVisible() const
		{
			constexpr auto all = std::to_underlying(ACTOR_VISIBILITY_MASK::kAll);
			return ((visFlags & all) & 0xF) == all;
		}

		bhkCharacterController* Move(float a_deltaTime, NiPoint3 a_deltaPos, bool a_defer)
		{
			using func_t = decltype(&Actor::Move);
			static REL::Relocation<func_t> func{ ID::Actor::Move };
			return func(this, a_deltaTime, a_deltaPos, a_defer);
		}

		bool PerformAction(BGSAction* a_action, TESObjectREFR* a_target)
		{
			using func_t = decltype(&Actor::PerformAction);
			static REL::Relocation<func_t> func{ ID::Actor::PerformAction };
			return func(this, a_action, a_target);
		}

		void RemovePerk(BGSPerk* a_perk)
		{
			using func_t = decltype(&Actor::RemovePerk);
			static REL::Relocation<func_t> func{ ID::Actor::RemovePerk };
			return func(this, a_perk);
		}

		void Reset3D(bool a_reloadAll, std::uint32_t a_additionalFlags, bool a_queueReset, std::uint32_t a_excludeFlags)
		{
			using func_t = decltype(&Actor::Reset3D);
			static REL::Relocation<func_t> func{ ID::Actor::Reset3D };
			return func(this, a_reloadAll, a_additionalFlags, a_queueReset, a_excludeFlags);
		}

		void RewardExperience(float a_amount, bool a_direct, TESObjectREFR* a_actionTarget, TESObjectREFR* a_killWeapon)
		{
			using func_t = decltype(&Actor::RewardExperience);
			static REL::Relocation<func_t> func{ ID::Actor::RewardExperience };
			return func(this, a_amount, a_direct, a_actionTarget, a_killWeapon);
		}

		void SetCurrentAmmo(BGSEquipIndex a_equipIndex, TESAmmo* a_ammo)
		{
			if (currentProcess) {
				currentProcess->SetCurrentAmmo(a_equipIndex, a_ammo);
			}
		}

		void SetGunState(GUN_STATE a_gunState, bool a_val = true)
		{
			using func_t = decltype(&Actor::SetGunState);
			static REL::Relocation<func_t> func{ ID::Actor::SetGunState };
			return func(this, a_gunState, a_val);
		}

		void SetHeading(float a_angle)
		{
			using func_t = decltype(&Actor::SetHeading);
			static REL::Relocation<func_t> func{ ID::Actor::SetHeading };
			return func(this, a_angle);
		}

		void TrespassAlarm(TESObjectREFR* a_refr, TESForm* a_owner, std::int32_t a_crime)
		{
			using func_t = decltype(&Actor::TrespassAlarm);
			static REL::Relocation<func_t> func{ ID::Actor::TrespassAlarm };
			return func(this, a_refr, a_owner, a_crime);
		}

		void UpdateVoiceTimer(bool a_force)
		{
			using func_t = decltype(&Actor::UpdateVoiceTimer);
			static REL::Relocation<func_t> func{ ID::Actor::UpdateVoiceTimer };
			return func(this, a_force);
		}

		BGSBodyPartData* GetBodyPartData()
		{
			using func_t = decltype(&Actor::GetBodyPartData);
			static REL::Relocation<func_t> func{ ID::Actor::GetBodyPartData };
			return func(this);
		}

		BGSObjectInstance* GetEquippedItem(BGSObjectInstance* a_result, BGSEquipIndex a_equipIndex)
		{
			using func_t = decltype(&Actor::GetEquippedItem);
			static REL::Relocation<func_t> func{ ID::Actor::GetEquippedItem };
			return func(this, a_result, a_equipIndex);
		}

		TESFaction* GetCrimeTrackingFaction()
		{
			using func_t = decltype(&Actor::GetCrimeTrackingFaction);
			static REL::Relocation<func_t> func{ ID::Actor::GetCrimeTrackingFaction };
			return func(this);
		}

		void ForceDetect(Actor* a_target, bool a_forceLOS, float a_time)
		{
			using func_t = decltype(&Actor::ForceDetect);
			static REL::Relocation<func_t> func{ ID::Actor::ForceDetect };
			return func(this, a_target, a_forceLOS, a_time);
		}

		void UnequipObject(TESBoundObject* a_object, ObjectEquipParams a_params)
		{
			using func_t = decltype(&Actor::UnequipObject);
			static REL::Relocation<func_t> func{ ID::Actor::UnequipObject };
			return func(this, a_object, a_params);
		}

		void UpdateSprinting()
		{
			using func_t = decltype(&Actor::UpdateSprinting);
			static REL::Relocation<func_t> func{ ID::Actor::UpdateSprinting };
			return func(this);
		}

		std::uint8_t GetMobilityCrippled()
		{
			using func_t = decltype(&Actor::GetMobilityCrippled);
			static REL::Relocation<func_t> func{ ID::Actor::GetMobilityCrippled };
			return func(this);
		}

		void SPECIALModifiedCallback(const ActorValueInfo* a_info, float a_originalValue, float a_delta)
		{
			using func_t = decltype(&Actor::SPECIALModifiedCallback);
			static REL::Relocation<func_t> func{ ID::Actor::SPECIALModifiedCallback };
			return func(this, a_info, a_originalValue, a_delta);
		}

		void StopInteractingQuick(bool a_instance, bool a_moveActor, bool a_update3D)
		{
			using func_t = decltype(&Actor::StopInteractingQuick);
			static REL::Relocation<func_t> func{ ID::Actor::StopInteractingQuick };
			return func(this, a_instance, a_moveActor, a_update3D);
		}

		// members
		NiTFlags<std::uint32_t, Actor>                   niFlags;                      // 2D0
		float                                            updateTargetTimer;            // 2D4
		NiPoint3                                         editorLocCoord;               // 2D8
		NiPoint3                                         editorLocRot;                 // 2E4
		TESForm*                                         editorLocForm;                // 2F0
		BGSLocation*                                     editorLocation;               // 2F8
		AIProcess*                                       currentProcess;               // 300
		ActorMover*                                      actorMover;                   // 308
		BGSKeyword*                                      speakingAnimArchType;         // 310
		BSTSmartPointer<MovementControllerNPC>           movementController;           // 318
		TESPackage*                                      initialPackage;               // 320
		CombatController*                                combatController;             // 328
		TESFaction*                                      vendorFaction;                // 330
		ActorValueStorage                                avStorage;                    // 338
		BGSDialogueBranch*                               exclusiveBranch;              // 370
		REX::EnumSet<ACTOR_CRITICAL_STAGE, std::int32_t> criticalStage;                // 378
		ObjectRefHandle                                  dialogueItemTarget;           // 37C
		ActorHandle                                      currentCombatTarget;          // 380
		ActorHandle                                      myKiller;                     // 384
		float                                            checkMyDeadBodyTimer;         // 388
		float                                            voiceTimer;                   // 38C
		float                                            voiceLengthTotal;             // 390
		float                                            underWaterTimer;              // 394
		std::int32_t                                     thiefCrimeStamp;              // 398
		std::int32_t                                     actionValue;                  // 39C
		float                                            timeronAction;                // 3A0
		AITimeStamp                                      calculateVendorFactionTimer;  // 3A4
		std::uint32_t                                    intimidateBribeDayStamp;      // 3A8
		float                                            equippedWeight;               // 3AC
		BSTSmallArray<SpellItem*>                        addedSpells;                  // 3B0
		ActorMagicCaster*                                magicCasters[4];              // 3C8
		MagicItem*                                       selectedSpell[4];             // 3E8
		CastPowerItem*                                   castPowerItems;               // 408
		TESForm*                                         selectedPower;                // 410
		TESRace*                                         race;                         // 418
		Perks*                                           perks;                        // 420
		BSTSmartPointer<BipedAnim>                       biped;                        // 428
		BSNonReentrantSpinLock                           addingToOrRemovingFromScene;  // 430
		BSReadWriteLock                                  perkArrayLock;                // 434
		REX::EnumSet<BOOL_FLAGS, std::uint32_t>          boolFlags;                    // 43C
		std::uint32_t                                    moreFlags;                    // 440
		Modifiers                                        healthModifiers;              // 444
		Modifiers                                        actionPointsModifiers;        // 450
		Modifiers                                        staminaModifiers;             // 45C
		Modifiers                                        radsModifiers;                // 468
		float                                            lastUpdate;                   // 474
		std::uint32_t                                    lastSeenTime;                 // 478
		float                                            armorRating;                  // 47C
		float                                            armorBaseFactorSum;           // 480
		std::uint32_t                                    visFlags: 4;                  // 484:00
		std::int8_t                                      raceSwitchPending: 1;         // 488:0
		std::int8_t                                      soundCallBackSet;             // 489
		bool                                             trespassing;                  // 48A
	};
	static_assert(sizeof(Actor) == 0x490);
}
