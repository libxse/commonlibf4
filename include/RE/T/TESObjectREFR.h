#pragma once

#include "RE/A/ActorValueOwner.h"
#include "RE/B/BGSEquipIndex.h"
#include "RE/B/BGSInventoryItem.h"
#include "RE/B/BGSInventoryList.h"
#include "RE/B/BGSObjectInstance.h"
#include "RE/B/BSFixedString.h"
#include "RE/B/BSHandleRefObject.h"
#include "RE/B/BSPointerHandle.h"
#include "RE/B/BSStringT.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTEvent.h"
#include "RE/B/BSTSmartPointer.h"
#include "RE/I/IAnimationGraphManagerHolder.h"
#include "RE/I/IKeywordFormBase.h"
#include "RE/I/ITEM_REMOVE_REASON.h"
#include "RE/M/MapMarkerData.h"
#include "RE/N/NiPoint.h"
#include "RE/O/OBJ_REFR.h"
#include "RE/T/TESForm.h"

namespace RE
{
	enum class BIPED_OBJECT;
	enum class IO_TASK_PRIORITY;
	enum class RESET_3D_FLAGS;
	class ActorCause;
	class BGSAnimationSequencer;
	class BGSBehaviorRootData;
	class BGSDecalGroup;
	class BipedAnim;
	class BSActiveGraphIfInactiveEvent;
	class BSAnimationGraphEvent;
	class BSAnimationUpdateData;
	class BSFaceGenNiNode;
	class DialogueResponse;
	class ExtraDataList;
	class hknpBodyId;
	class hkVector4f;
	class INSTANCE_FILTER;
	class LOADED_REF_DATA;
	class MagicCaster;
	class MagicTarget;
	class ModelReferenceEffect;
	class NiAVObject;
	class NiNode;
	class NiTransform;
	class REFR_LOCK;
	class ShaderReferenceEffect;
	class TargetEntry;
	class TESModel;
	class TrapData;
	class TrapEntry;

	namespace ActorValueEvents
	{
		class ActorValueChangedEvent;
	}

	namespace BGSInventoryListEvent
	{
		class Event;
	}

	namespace MagicSystem
	{
		enum class CastingSource;
	}

	class __declspec(novtable) TESObjectREFR :
		public TESForm,                                                  // 000
		public BSHandleRefObject,                                        // 020
		public BSTEventSink<BSActiveGraphIfInactiveEvent>,               // 030
		public BSTEventSink<BSAnimationGraphEvent>,                      // 038
		public BSTEventSink<BGSInventoryListEvent::Event>,               // 040
		public IAnimationGraphManagerHolder,                             // 048
		public IKeywordFormBase,                                         // 050
		public ActorValueOwner,                                          // 058
		public BSTEventSource<ActorValueEvents::ActorValueChangedEvent>  // 060
	{
	public:
		static constexpr auto RTTI{ RTTI::TESObjectREFR };
		static constexpr auto VTABLE{ VTABLE::TESObjectREFR };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kREFR };

		class RemoveItemData
		{
		public:
			RemoveItemData(TESForm* a_form, std::int32_t a_count) :
				RemoveItemData(a_form->As<TESBoundObject>(), a_count)
			{}

			RemoveItemData(TESBoundObject* a_object, std::int32_t a_count) :
				object(a_object), count(a_count)
			{}

			// members
			BSTSmallArray<std::uint32_t, 4> stackData;                            // 00
			TESBoundObject*                 object{ nullptr };                    // 20
			std::int32_t                    count{ 0 };                           // 28
			ITEM_REMOVE_REASON              reason{ ITEM_REMOVE_REASON::kNone };  // 2C
			TESObjectREFR*                  a_otherContainer{ nullptr };          // 30
			const NiPoint3*                 dropLoc{ nullptr };                   // 38
			const NiPoint3*                 rotate{ nullptr };                    // 40
		};
		static_assert(sizeof(RemoveItemData) == 0x48);

		F4_HEAP_REDEFINE_NEW(TESObjectREFR);

		// add
		virtual void                              Predestroy();                                                                                                                                                                                                                    // 4A
		virtual void                              PreModelLoaderQueueing() { return; }                                                                                                                                                                                             // 4B
		virtual BGSLocation*                      GetEditorLocation() const;                                                                                                                                                                                                       // 4C
		virtual bool                              GetEditorLocation(NiPoint3& a_originalLocation, NiPoint3& a_originalAngle, TESForm*& a_locationFormOut, TESForm* a_locationForm);                                                                                                // 4D
		virtual bool                              IsTalking() const;                                                                                                                                                                                                               // 4E
		virtual void                              ForceEditorLocation(BGSLocation* a_location);                                                                                                                                                                                    // 4F
		virtual void                              Update3DPosition(bool a_warp);                                                                                                                                                                                                   // 50
		virtual void                              UpdateSoundCallBack(bool a_endSceneAction);                                                                                                                                                                                      // 51
		virtual bool                              SetDialoguewithPlayer(bool a_flag, bool a_forceGreet, TESTopicInfo* a_topicInfo);                                                                                                                                                // 52
		virtual void                              AddDynamicIdleCRC([[maybe_unused]] std::uint32_t a_crc) { return; }                                                                                                                                                              // 53
		virtual void                              GetPreviousDynamicIdleCRCS(std::uint32_t* a_crcs, std::uint32_t a_requestSize) const;                                                                                                                                            // 54
		virtual bool                              GetFullLODRef() const;                                                                                                                                                                                                           // 55
		virtual void                              SetFullLODRef(bool a_val);                                                                                                                                                                                                       // 56
		virtual BGSAnimationSequencer*            GetSequencer() const;                                                                                                                                                                                                            // 57
		virtual bool                              QCanUpdateSync() const { return true; }                                                                                                                                                                                          // 58
		virtual bool                              GetAllowPromoteToPersistent() const { return true; }                                                                                                                                                                             // 59
		virtual bool                              DoesFloat() const { return false; }                                                                                                                                                                                              // 5A
		virtual TESPackage*                       CheckForCurrentAliasPackage() { return nullptr; }                                                                                                                                                                                // 5B
		virtual BGSScene*                         GetCurrentScene() const;                                                                                                                                                                                                         // 5C
		virtual void                              SetCurrentScene(BGSScene* a_scene);                                                                                                                                                                                              // 5D
		virtual bool                              UpdateInDialogue(DialogueResponse* a_response, bool);                                                                                                                                                                            // 5E
		virtual BGSDialogueBranch*                GetExclusiveBranch() const;                                                                                                                                                                                                      // 5F
		virtual void                              SetExclusiveBranch(BGSDialogueBranch* a_exclusiveBranch);                                                                                                                                                                        // 60
		virtual void                              StopCurrentDialogue(bool a_force);                                                                                                                                                                                               // 61
		virtual void                              FadeCurrentDialogue();                                                                                                                                                                                                           // 62
		virtual void                              PauseCurrentDialogue();                                                                                                                                                                                                          // 63
		virtual void                              ResumeCurrentDialogue();                                                                                                                                                                                                         // 64
		virtual void                              SetActorCause(ActorCause* a_actorCause);                                                                                                                                                                                         // 65
		virtual ActorCause*                       GetActorCause() const;                                                                                                                                                                                                           // 66
		virtual float                             GetActorWidthOrRefDiameter() const;                                                                                                                                                                                              // 67
		virtual float                             GetActorHeightOrRefBound() const;                                                                                                                                                                                                // 68
		virtual NiPoint3                          GetStartingAngle();                                                                                                                                                                                                              // 69
		virtual NiPoint3                          GetStartingLocation();                                                                                                                                                                                                           // 6A
		virtual void                              SetStartingPosition(const NiPoint3& a_position);                                                                                                                                                                                 // 6B
		virtual void                              UpdateRefLight(float a_delta);                                                                                                                                                                                                   // 6C
		virtual ObjectRefHandle                   RemoveItem(RemoveItemData& a_data);                                                                                                                                                                                              // 6D
		virtual void                              AddWornOutfitImpl([[maybe_unused]] BGSOutfit* a_outfit, [[maybe_unused]] bool a_queueItem) { return; }                                                                                                                           // 6E
		virtual bool                              AddWornItem(TESBoundObject* a_object, BSTSmartPointer<ExtraDataList> a_extra, std::int32_t a_number, bool a_forceEquip, BGSEquipIndex a_equipIndex);                                                                             // 6F
		virtual void                              DoTrap([[maybe_unused]] TrapEntry* a_trap, [[maybe_unused]] TargetEntry* a_target) { return; }                                                                                                                                   // 71
		virtual void                              DoTrap([[maybe_unused]] TrapData& a_trapData) { return; }                                                                                                                                                                        // 70
		virtual void                              SetEquipStateLocked(TESBoundObject* a_object, bool a_lock);                                                                                                                                                                      // 72
		virtual void                              SendContainerChangedEvent(const TESObjectREFR* a_oldContainer, const TESObjectREFR* apNewContainer, const TESBoundObject* a_baseObject, std::int32_t a_count, std::uint32_t a_referenceFormID, std::uint16_t a_uniqueID) const;  // 73
		virtual void                              UnequipArmorFromSlot([[maybe_unused]] BIPED_OBJECT a_bipedObject, [[maybe_unused]] bool a_markAsReequippable) { return; }                                                                                                        // 74
		virtual void                              RemoveAllObjectsWorn();                                                                                                                                                                                                          // 75
		virtual void                              PostRemoveWornObject(const BGSObjectInstance& a_object, const BGSEquipSlot* a_equipSlot);                                                                                                                                        // 76
		virtual void                              Set3DUpdateFlag([[maybe_unused]] RESET_3D_FLAGS a_flag) { return; }                                                                                                                                                              // 77
		virtual void                              ClearAll3DUpdateFlags() { return; }                                                                                                                                                                                              // 78
		virtual float                             AdjustItemWeight([[maybe_unused]] TESBoundObject& a_object, [[maybe_unused]] const BGSInventoryItem::Stack& a_stack, float a_weight, [[maybe_unused]] bool* a_shouldModifyWholeStackOut) { return a_weight; }                    // 79
		virtual void                              AddObjectToContainer(TESBoundObject* a_obj, BSTSmartPointer<ExtraDataList> a_extra, std::int32_t a_count, TESObjectREFR* a_oldContainer, ITEM_REMOVE_REASON a_reason);                                                           // 7A
		virtual NiPoint3                          GetLookingAtLocation() const;                                                                                                                                                                                                    // 7B
		virtual MagicCaster*                      GetMagicCaster(MagicSystem::CastingSource a_source);                                                                                                                                                                             // 7C
		virtual MagicTarget*                      GetMagicTarget();                                                                                                                                                                                                                // 7D
		virtual bool                              IsChild() const { return false; }                                                                                                                                                                                                // 7E
		virtual TESActorBase*                     GetTemplateActorBase() { return nullptr; }                                                                                                                                                                                       // 7F
		virtual void                              SetTemplateActorBase(TESActorBase*) { return; }                                                                                                                                                                                  // 80
		virtual BSFaceGenNiNode*                  GetFaceNodeSkinned() { return nullptr; }                                                                                                                                                                                         // 81
		virtual BSFaceGenNiNode*                  GetFaceNode() { return GetFaceNodeSkinned(); }                                                                                                                                                                                   // 82
		virtual bool                              ClampToGround();                                                                                                                                                                                                                 // 83
		virtual bool                              DetachHavok(NiAVObject* a_obj3D);                                                                                                                                                                                                // 84
		virtual void                              InitHavok();                                                                                                                                                                                                                     // 85
		virtual NiAVObject*                       Load3D(bool a_backgroundLoading);                                                                                                                                                                                                // 86
		virtual void                              Release3DRelatedData();                                                                                                                                                                                                          // 87
		virtual void                              Set3D(NiAVObject* a_object, bool a_queue3DTasks);                                                                                                                                                                                // 88
		virtual bool                              ShouldBackgroundClone() const;                                                                                                                                                                                                   // 89
		virtual bool                              IsReadyForAttach([[maybe_unused]] const IO_TASK_PRIORITY& a_priority) const { return true; }                                                                                                                                     // 8A
		virtual NiAVObject*                       Get3D() const;                                                                                                                                                                                                                   // 8C
		virtual NiAVObject*                       Get3D([[maybe_unused]] bool a_firstPerson) const { return Get3D(); }                                                                                                                                                             // 8B
		virtual NiAVObject*                       GetFullyLoaded3D() const;                                                                                                                                                                                                        // 8D
		virtual bool                              Is3rdPersonVisible() const { return true; }                                                                                                                                                                                      // 8E
		virtual bool                              PopulateGraphProjectsToLoad(const NiAVObject* a_obj3D, BSScrapArray<BSStaticStringT<260>>& a_projectFilenames) const;                                                                                                            // 8F
		virtual TESModel*                         GetTESModel() const;                                                                                                                                                                                                             // 90
		virtual TESRace*                          GetVisualsRace() const;                                                                                                                                                                                                          // 91
		virtual void                              GetPhysicsTransform(NiTransform& a_outTransform) const;                                                                                                                                                                          // 92
		virtual NiPoint3                          GetBoundMin() const;                                                                                                                                                                                                             // 93
		virtual NiPoint3                          GetBoundMax() const;                                                                                                                                                                                                             // 94
		virtual bool                              GetBehaviorRootNameOverrides([[maybe_unused]] BSScrapArray<BSFixedString>& a_behaviorRoots) const { return false; }                                                                                                              // 95
		virtual bool                              GetBehaviorRootNameReplacement([[maybe_unused]] BSFixedString& a_rootNameReplacement) const { return false; }                                                                                                                    // 96
		virtual bool                              GetBehaviorRootData(bool a_onlyCollectActiveRoots, BSScrapArray<BGSBehaviorRootData>& a_behaviorRoots) const;                                                                                                                    // 97
		virtual void                              OnHeadInitialized() { return; }                                                                                                                                                                                                  // 98
		virtual bool                              InitNonNPCAnimation(NiNode& a_nodeForAnim);                                                                                                                                                                                      // 99
		virtual bool                              CheckAndFixSkinAndBoneOrder(NiNode& a_nodeToTest);                                                                                                                                                                               // 9A
		virtual void                              ModifyAnimationUpdateData([[maybe_unused]] BSAnimationUpdateData& a_updateData) { return; }                                                                                                                                      // 9B
		virtual bool                              ShouldSaveAnimationOnUnloading() const;                                                                                                                                                                                          // 9C
		virtual bool                              ShouldSaveAnimationOnSaving() const;                                                                                                                                                                                             // 9D
		virtual bool                              ShouldPerformRevert() const { return true; }                                                                                                                                                                                     // 9E
		virtual void                              UpdateAnimation(float a_delta);                                                                                                                                                                                                  // 9F
		virtual void                              CollectPickNodes() { return; }                                                                                                                                                                                                   // A0
		virtual const BSTSmartPointer<BipedAnim>& GetBiped() const;                                                                                                                                                                                                                // A2
		virtual const BSTSmartPointer<BipedAnim>& GetBiped(bool a_firstPerson) const;                                                                                                                                                                                              // A1
		virtual const BSTSmartPointer<BipedAnim>& GetCurrentBiped() const { return GetBiped(); }                                                                                                                                                                                   // A3
		virtual void                              SetBiped([[maybe_unused]] const BSTSmartPointer<BipedAnim>& a_biped) { return; }                                                                                                                                                 // A4
		virtual void                              AttachWeapon(const BGSObjectInstanceT<TESObjectWEAP>& a_weapon, BGSEquipIndex a_equipIndex);                                                                                                                                     // A5
		virtual void                              RemoveWeapon([[maybe_unused]] const BGSObjectInstanceT<TESObjectWEAP>& a_weapon, [[maybe_unused]] BGSEquipIndex a_equipIndex, [[maybe_unused]] bool a_queue3DTasks) { return; }                                                  // A6
		virtual void                              CreateInventoryList(const TESContainer* a_container);                                                                                                                                                                            // A7
		virtual void                              DestroyInventoryList();                                                                                                                                                                                                          // A8
		virtual void                              SetRunsInLow(bool) { return; }                                                                                                                                                                                                   // A9
		virtual void                              SetObjectReference(TESBoundObject* a_object);                                                                                                                                                                                    // AA
		virtual void                              MoveHavok(bool a_forceRec);                                                                                                                                                                                                      // AB
		virtual void                              GetLinearVelocity(NiPoint3& a_velocity) const;                                                                                                                                                                                   // AC
		virtual void                              ApplyMovementDelta(float a_timeDelta, const NiPoint3A& a_delta, const NiPoint3& a_angleDelta);                                                                                                                                   // AD
		virtual void                              SetActionComplete([[maybe_unused]] bool a_value) { return; }                                                                                                                                                                     // AE
		virtual void                              SetMovementComplete(bool) { return; }                                                                                                                                                                                            // AF
		virtual void                              Disable();                                                                                                                                                                                                                       // B0
		virtual void                              ResetInventory(bool a_leveledOnly);                                                                                                                                                                                              // B1
		virtual NiAVObject*                       GetCurrent3D() const { return Get3D(); }                                                                                                                                                                                         // B2
		virtual Explosion*                        IsExplosion() { return nullptr; }                                                                                                                                                                                                // B4
		virtual const Explosion*                  IsExplosion() const { return nullptr; }                                                                                                                                                                                          // B3
		virtual Projectile*                       IsProjectile() { return nullptr; }                                                                                                                                                                                               // B6
		virtual const Projectile*                 IsProjectile() const { return nullptr; }                                                                                                                                                                                         // B5
		virtual bool                              OnAddCellPerformQueueReference([[maybe_unused]] TESObjectCELL& a_cell) const { return true; }                                                                                                                                    // B7
		virtual void                              DoMoveToHigh() { return; }                                                                                                                                                                                                       // B8
		virtual void                              TryMoveToMiddleLow() { return; }                                                                                                                                                                                                 // B9
		virtual bool                              TryChangeSkyCellActorsProcessLevel() { return false; }                                                                                                                                                                           // BA
		virtual void                              SetDisplayGeometry(bool) { return; }                                                                                                                                                                                             // BB
		virtual void                              TryUpdateActorLastSeenTime() { return; }                                                                                                                                                                                         // BC
		virtual void                              SaveGameTest();                                                                                                                                                                                                                  // BD
		virtual TESObjectCELL*                    GetSaveParentCell() const;                                                                                                                                                                                                       // BE
		virtual void                              SetParentCell(TESObjectCELL* a_cell);                                                                                                                                                                                            // BF
		virtual bool                              IsDead(bool a_notEssential) const;                                                                                                                                                                                               // C0
		virtual bool                              ProcessInWater(hknpBodyId a_bodyID, float a_waterHeight, float a_deltaTime);                                                                                                                                                     // C1
		virtual bool                              ApplyCurrent([[maybe_unused]] float a_deltaTime, [[maybe_unused]] const hkVector4f& a_linVel, const hkVector4f&) { return false; }                                                                                               // C2
		virtual BGSDecalGroup*                    GetDecalGroup() const;                                                                                                                                                                                                           // C3
		virtual void                              InitDefaultWornImpl(bool a_weapon, bool a_allowChanges);                                                                                                                                                                         // C4
		virtual bool                              HasKeywordHelper(const BGSKeyword* a_keyword, const TBO_InstanceData* a_data) const;                                                                                                                                             // C5

		bool ActivateRef(TESObjectREFR* a_actionRef, TESBoundObject* a_objectToGet, std::int32_t a_count, bool a_defaultProcessingOnly, bool a_fromScript, bool a_looping)
		{
			using func_t = decltype(&TESObjectREFR::ActivateRef);
			static REL::Relocation<func_t> func{ ID::TESObjectREFR::ActivateRef };
			return func(this, a_actionRef, a_objectToGet, a_count, a_defaultProcessingOnly, a_fromScript, a_looping);
		}

		void AddInventoryItem(TESBoundObject* a_object, BSTSmartPointer<ExtraDataList> a_extra, std::uint32_t a_count, TESObjectREFR* a_oldContainer, const INSTANCE_FILTER* a_filter, TESObjectREFR* a_overrideRef)
		{
			using func_t = decltype(&TESObjectREFR::AddInventoryItem);
			static REL::Relocation<func_t> func{ ID::TESObjectREFR::AddInventoryItem };
			return func(this, a_object, a_extra, a_count, a_oldContainer, a_filter, a_overrideRef);
		}

		void AddKeyword(BGSKeyword* kwd)
		{
			using func_t = decltype(&TESObjectREFR::AddKeyword);
			static REL::Relocation<func_t> func{ ID::TESObjectREFR::AddKeyword };
			return func(this, kwd);
		}

		void AddLockChange()
		{
			using func_t = decltype(&TESObjectREFR::AddLockChange);
			static REL::Relocation<func_t> func{ ID::TESObjectREFR::AddLockChange };
			return func(this);
		}

		ModelReferenceEffect* ApplyArtObject(
			BGSArtObject*  a_art,
			float          a_time = -1.0f,
			TESObjectREFR* a_facingRef = nullptr,
			bool           a_attachToCamera = false,
			bool           a_inheritRotation = false,
			NiAVObject*    a_3D = nullptr,
			bool           a_interfaceEffect = false)
		{
			using func_t = decltype(&TESObjectREFR::ApplyArtObject);
			static REL::Relocation<func_t> func{ ID::TESObjectREFR::ApplyArtObject };
			return func(this, a_art, a_time, a_facingRef, a_attachToCamera, a_inheritRotation, a_3D, a_interfaceEffect);
		}

		ShaderReferenceEffect* ApplyEffectShader(
			TESEffectShader* a_art,
			float            a_time = -1.0f,
			TESObjectREFR*   a_facingRef = nullptr,
			bool             a_attachToCamera = false,
			bool             a_inheritRotation = false,
			NiAVObject*      a_3D = nullptr,
			bool             a_interfaceEffect = false)
		{
			using func_t = decltype(&TESObjectREFR::ApplyEffectShader);
			static REL::Relocation<func_t> func{ ID::TESObjectREFR::ApplyEffectShader };
			return func(this, a_art, a_time, a_facingRef, a_attachToCamera, a_inheritRotation, a_3D, a_interfaceEffect);
		}

		void Enable(bool a_resetInventory)
		{
			using func_t = decltype(&TESObjectREFR::Enable);
			static REL::Relocation<func_t> func{ ID::TESObjectREFR::Enable };
			return func(this, a_resetInventory);
		}

		static TESObjectREFR* FindReferenceFor3D(const NiAVObject* a_opbject3D)
		{
			using func_t = decltype(&TESObjectREFR::FindReferenceFor3D);
			static REL::Relocation<func_t> func{ ID::TESObjectREFR::FindReferenceFor3D };
			return func(a_opbject3D);
		}

		void FindAndWriteStackDataForInventoryItem(
			TESBoundObject*                            a_object,
			BGSInventoryItem::StackDataCompareFunctor& a_compareFunc,
			BGSInventoryItem::StackDataWriteFunctor&   a_writeFunc,
			bool (*a_objCompFn)(TESBoundObject*, TESBoundObject*) = BGSInventoryList::StandardObjectCompareCallbackFn,
			bool a_alwaysContinue = false)
		{
			if (inventoryList) {
				inventoryList->FindAndWriteStackDataForItem(a_object, a_compareFunc, a_writeFunc, a_objCompFn, a_alwaysContinue);
			}
		}

		[[nodiscard]] BGSLocation* GetCurrentLocation() const
		{
			using func_t = decltype(&TESObjectREFR::GetCurrentLocation);
			static REL::Relocation<func_t> func{ ID::TESObjectREFR::GetCurrentLocation };
			return func(this);
		}

		[[nodiscard]] const char* GetDisplayFullName()
		{
			using func_t = decltype(&TESObjectREFR::GetDisplayFullName);
			static REL::Relocation<func_t> func{ ID::TESObjectREFR::GetDisplayFullName };
			return func(this);
		}

		bool GetEditorDead() const
		{
			using func_t = decltype(&TESObjectREFR::GetEditorDead);
			static REL::Relocation<func_t> func{ ID::TESObjectREFR::GetEditorDead };
			return func(this);
		}

		[[nodiscard]] TESBoundObject* GetObjectReference() const noexcept { return data.objectReference; }

		[[nodiscard]] TESForm* GetOwner()
		{
			using func_t = decltype(&TESObjectREFR::GetOwner);
			static REL::Relocation<func_t> func{ ID::TESObjectREFR::GetOwner };
			return func(this);
		}

		[[nodiscard]] TESObjectCELL* GetParentCell() const noexcept { return parentCell; }

		[[nodiscard]] NiPoint3 GetPosition() const noexcept { return data.location; }

		[[nodiscard]] float GetPositionX() const noexcept { return data.location.x; }

		[[nodiscard]] float GetPositionY() const noexcept { return data.location.y; }

		[[nodiscard]] float GetPositionZ() const noexcept { return data.location.z; }

		[[nodiscard]] std::int64_t GetGoldAmount()
		{
			using func_t = decltype(&TESObjectREFR::GetGoldAmount);
			static REL::Relocation<func_t> func{ ID::TESObjectREFR::GetGoldAmount };
			return func(this);
		}

		[[nodiscard]] ObjectRefHandle GetHandle()
		{
			using func_t = decltype(&TESObjectREFR::GetHandle);
			static REL::Relocation<func_t> func{ ID::TESObjectREFR::GetHandle };
			return func(this);
		}

		[[nodiscard]] bool GetHasOwner()
		{
			using func_t = decltype(&TESObjectREFR::GetHasOwner);
			static REL::Relocation<func_t> func{ ID::TESObjectREFR::GetHasOwner };
			return func(this);
		}

		[[nodiscard]] std::uint32_t GetInventoryObjectCount(const TESBoundObject* a_object)
		{
			using func_t = decltype(&TESObjectREFR::GetInventoryObjectCount);
			static REL::Relocation<func_t> func{ ID::TESObjectREFR::GetInventoryObjectCount };
			return func(this, a_object);
		}

		[[nodiscard]] TESObjectREFR* GetLinkedRef(BGSKeyword* a_keyword)
		{
			using func_t = decltype(&TESObjectREFR::GetLinkedRef);
			static REL::Relocation<func_t> func{ ID::TESObjectREFR::GetLinkedRef };
			return func(this, a_keyword);
		}

		[[nodiscard]] REFR_LOCK* GetLock()
		{
			using func_t = decltype(&TESObjectREFR::GetLock);
			static REL::Relocation<func_t> func{ ID::TESObjectREFR::GetLock };
			return func(this);
		}

		[[nodiscard]] float GetWeightInContainer()
		{
			using func_t = decltype(&TESObjectREFR::GetWeightInContainer);
			static REL::Relocation<func_t> func{ ID::TESObjectREFR::GetWeightInContainer };
			return func(this);
		}

		BaseFormComponent* HasContainer()
		{
			using func_t = decltype(&TESObjectREFR::HasContainer);
			static REL::Relocation<func_t> func{ ID::TESObjectREFR::HasContainer };
			return func(this);
		}

		[[nodiscard]] bool IsAnOwner(Actor* a_testOwner, bool a_useFaction, bool a_requiresOwner)
		{
			using func_t = decltype(&TESObjectREFR::IsAnOwner);
			static REL::Relocation<func_t> func{ ID::TESObjectREFR::IsAnOwner };
			return func(this, a_testOwner, a_useFaction, a_requiresOwner);
		}

		[[nodiscard]] bool IsCrimeToActivate()
		{
			using func_t = decltype(&TESObjectREFR::IsCrimeToActivate);
			static REL::Relocation<func_t> func{ ID::TESObjectREFR::IsCrimeToActivate };
			return func(this);
		}

		[[nodiscard]] bool IsInWater()
		{
			return this->GetRelevantWaterHeight() > this->data.location.z;
		}

		[[nodiscard]] bool IsLeveledCreature()
		{
			using func_t = decltype(&TESObjectREFR::IsLeveledCreature);
			static REL::Relocation<func_t> func{ ID::TESObjectREFR::IsLeveledCreature };
			return func(this);
		}

		void MarkAsDeleted()
		{
			using func_t = decltype(&TESObjectREFR::MarkAsDeleted);
			static REL::Relocation<func_t> func{ ID::TESObjectREFR::MarkAsDeleted };
			return func(this);
		}

		void MoveRefToNewSpace(TESObjectCELL* a_interior, TESWorldSpace* a_world)
		{
			using func_t = decltype(&TESObjectREFR::MoveRefToNewSpace);
			static REL::Relocation<func_t> func{ ID::TESObjectREFR::MoveRefToNewSpace };
			return func(this, a_interior, a_world);
		}

		void RemoveKeyword(BGSKeyword* a_keyworld)
		{
			using func_t = decltype(&TESObjectREFR::RemoveKeyword);
			static REL::Relocation<func_t> func{ ID::TESObjectREFR::RemoveKeyword };
			return func(this, a_keyworld);
		}

		void SetAngleOnReference(const NiPoint3& a_point)
		{
			using func_t = decltype(&TESObjectREFR::SetAngleOnReference);
			static REL::Relocation<func_t> func{ ID::TESObjectREFR::SetAngleOnReference };
			return func(this, a_point);
		}

		void SetLinkedRef(Actor* a_actor, BGSKeyword* a_keyword)
		{
			using func_t = decltype(&TESObjectREFR::SetLinkedRef);
			static REL::Relocation<func_t> func{ ID::TESObjectREFR::SetLinkedRef };
			return func(this, a_actor, a_keyword);
		}

		void SetLocationOnReference(const NiPoint3& a_point)
		{
			using func_t = decltype(&TESObjectREFR::SetLocationOnReference);
			static REL::Relocation<func_t> func{ ID::TESObjectREFR::SetLocationOnReference };
			return func(this, a_point);
		}

		void SetWantsDelete(bool a_delete)
		{
			using func_t = decltype(&TESObjectREFR::SetWantsDelete);
			static REL::Relocation<func_t> func{ ID::TESObjectREFR::SetWantsDelete };
			return func(this, a_delete);
		}

		void RebuildBendableSpline(bool rebuildCollision, NiAVObject* target)
		{
			using func_t = decltype(&TESObjectREFR::RebuildBendableSpline);
			static REL::Relocation<func_t> func{ ID::TESObjectREFR::RebuildBendableSpline };
			return func(this, rebuildCollision, target);
		}

		bool GetItemCount(uint32_t& count, TESForm* item, bool countComponent)
		{
			using func_t = decltype(&TESObjectREFR::GetItemCount);
			static REL::Relocation<func_t> func{ ID::TESObjectREFR::GetItemCount };
			return func(this, count, item, countComponent);
		}

		void UpdateReference3D()
		{
			using func_t = decltype(&TESObjectREFR::UpdateReference3D);
			static REL::Relocation<func_t> func{ ID::TESObjectREFR::UpdateReference3D };
			return func(this);
		}

		void GetObjectCenter(NiPoint3& center)
		{
			using func_t = decltype(&TESObjectREFR::GetObjectCenter);
			static REL::Relocation<func_t> func{ ID::TESObjectREFR::GetObjectCenter };
			return func(this, center);
		}

		void SetScale(float scale)
		{
			using func_t = decltype(&TESObjectREFR::SetScale);
			static REL::Relocation<func_t> func{ ID::TESObjectREFR::SetScale };
			return func(this, scale);
		}

		bool IsMarker()
		{
			using func_t = decltype(&TESObjectREFR::IsMarker);
			static REL::Relocation<func_t> func{ ID::TESObjectREFR::IsMarker };
			return func(this);
		}

		bool IsDecalRef()
		{
			using func_t = decltype(&TESObjectREFR::IsDecalRef);
			static REL::Relocation<func_t> func{ ID::TESObjectREFR::IsDecalRef };
			return func(this);
		}

		void UpdateDynamicNavmesh(bool a_active)
		{
			using func_t = decltype(&TESObjectREFR::UpdateDynamicNavmesh);
			static REL::Relocation<func_t> func{ ID::TESObjectREFR::UpdateDynamicNavmesh };
			return func(this, a_active);
		}

		MapMarkerData* GetMapMarkerData()
		{
			using func_t = decltype(&TESObjectREFR::GetMapMarkerData);
			static REL::Relocation<func_t> func{ ID::TESObjectREFR::GetMapMarkerData };
			return func(this);
		}

		float GetRelevantWaterHeight()
		{
			using func_t = decltype(&TESObjectREFR::GetRelevantWaterHeight);
			static REL::Relocation<func_t> func{ ID::TESObjectREFR::GetRelevantWaterHeight };
			return func(this);
		}

		// members
		TESObjectCELL*                 parentCell;     // 0B8
		OBJ_REFR                       data;           // 0C0
		LOADED_REF_DATA*               loadedData;     // 0F0
		BGSInventoryList*              inventoryList;  // 0F8
		BSTSmartPointer<ExtraDataList> extraList;      // 100
		std::uint16_t                  refScale;       // 018
		std::int8_t                    modelState;     // 10A
		bool                           predestroyed;   // 10B
	};
	static_assert(sizeof(TESObjectREFR) == 0x110);
}
