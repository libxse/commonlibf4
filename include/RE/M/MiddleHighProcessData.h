#pragma once

#include "RE/A/AITimeStamp.h"
#include "RE/A/ActiveEffectList.h"
#include "RE/A/ActorPackage.h"
#include "RE/B/BSFixedString.h"
#include "RE/B/BSPointerHandle.h"
#include "RE/B/BSSimpleList.h"
#include "RE/B/BSSpinLock.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTEvent.h"
#include "RE/B/BSTSmartPointer.h"
#include "RE/B/BSTTuple.h"
#include "RE/N/NiPoint.h"
#include "RE/N/NiPointer.h"
#include "RE/S/SubgraphHandle.h"
#include "RE/S/SubgraphIdentifier.h"

namespace RE
{
	enum class PACKAGE_OBJECT_TYPE;
	class ActorInventoryEvent;
	class AIPerkData;
	class bhkCharacterController;
	class bhkNPCollisionObject;
	class bhkRagdollPenetrationUtil;
	class BSAnimationGraphManager;
	class BSAnimationGraphVariableCache;
	class BSClothExtraData;
	class BSFaceGenAnimationData;
	class BSFaceGenNiNode;
	class BSLightingShaderProperty;
	class CommandedActorData;
	class DeferredHideLimb;
	class EquippedItem;
	class HitData;
	class IAnimationStanceData;
	class NiAVObject;
	class NiNode;
	class QueuedFile;
	class QueuedItem;
	class SubGraphIdleRootData;

	namespace MagicSystem
	{
		enum class WardState;
	}

	class MiddleHighProcessData
	{
	public:
		// members
		BSTEventSource<ActorInventoryEvent>                 inventoryEventSource;                           // 000
		NiPointer<bhkNPCollisionObject>                     poseBound;                                      // 058
		ActorPackage                                        runOncePackage;                                 // 060
		BSTArray<ActorHandle>                               deadDetectList;                                 // 090
		BSSimpleList<TESObjectREFR*>                        refListChairBed;                                // 0A8
		NiPoint3                                            rotation;                                       // 0B8
		NiPoint3                                            rotationSpeed;                                  // 0C4
		NiPoint3                                            actorMountPosition;                             // 0D0
		NiPoint3                                            furniturePathPoint;                             // 0DC
		NiPoint3                                            lastSeenPosition;                               // 0E8
		ActorHandle                                         bleedoutAttacker;                               // 0F4
		REX::TEnumSet<MagicSystem::WardState, std::int32_t> wardState;                                      // 0F8
		BSTSmartPointer<void*>                              animResponse;                                   // 100 - BSResponse<BSFixedString, Actor, BSFixedString, DoNothingUnhandledPolicy>
		BSTArray<CommandedActorData>                        commandedActors;                                // 108
		NiNode*                                             damageRootNode[26];                             // 120
		NiNode*                                             weaponBone;                                     // 1F0
		NiAVObject*                                         headNode;                                       // 1F8
		NiAVObject*                                         torsoNode;                                      // 200
		NiAVObject*                                         faceTargetSourceNode;                           // 208
		BSFaceGenNiNode*                                    faceNodeSkinned;                                // 210
		NiPointer<BSLightingShaderProperty>                 lightingProperty;                               // 218
		QueuedItem*                                         listItemstoEquipUnequip;                        // 220
		HitData*                                            lastHitData;                                    // 228
		DeferredHideLimb*                                   headDeferredHideLimb;                           // 230
		ActiveEffectList                                    activeEffects;                                  // 238
		BSTSmartPointer<BSAnimationGraphManager>            animationGraphManager;                          // 258
		BSAnimationGraphVariableCache*                      animationVariableCache;                         // 260
		BSTArray<SubGraphIdleRootData>                      subGraphIdleManagerRoots;                       // 268
		BSSpinLock                                          equippedItemsLock;                              // 280
		BSTArray<EquippedItem>                              equippedItems;                                  // 288
		BSTArray<BSClothExtraData*>                         clothExtraDataCache;                            // 2A0
		BSTArray<BSTSmallArray<SubgraphHandle, 2>>          subGraphHandles;                                // 2B8
		BSTSmallArray<SubgraphIdentifier, 2>                currentDefaultSubGraphID;                       // 2D0
		BSTSmallArray<SubgraphIdentifier, 2>                requestedDefaultSubGraphID;                     // 2F0
		BSTSmallArray<SubgraphIdentifier, 2>                currentWeaponSubGraphID;                        // 310
		BSTSmallArray<SubgraphIdentifier, 2>                requestedWeaponSubGraphID;                      // 330
		BSTSmartPointer<IAnimationStanceData>               stanceData;                                     // 350
		BSTArray<BSTTuple<std::uint32_t, void*>>            nodeLocationArray;                              // 358 - AnimationStanceNodeLocationData<NiPoint3>
		float                                               stanceHeightArray[6][2];                        // 370
		float                                               headHeightOffset;                               // 3A0
		ObjectRefHandle                                     currentFurniture;                               // 3A4
		ObjectRefHandle                                     occupiedFurniture;                              // 3A8
		TESIdleForm*                                        currentIdle;                                    // 3B0
		ActorHandle                                         commandingActor;                                // 3B8
		const TESIdleForm*                                  furnitureIdle;                                  // 3C0
		BSFaceGenAnimationData*                             faceAnimationData;                              // 3C8
		MagicItem*                                          currentPackageSpell;                            // 3D0
		TESObjectWEAP*                                      lastBoundWeapon;                                // 3D8
		NiPointer<bhkCharacterController>                   charController;                                 // 3E0
		BSTSmartPointer<bhkRagdollPenetrationUtil>          penetrationDetectUtil;                          // 3E8
		NiPointer<QueuedFile>                               bodyPartPreload;                                // 3F0
		TESIdleForm*                                        lastIdlePlayed;                                 // 3F8
		AIPerkData*                                         perkData;                                       // 400
		NiPoint3                                            lookAtLocation;                                 // 408
		float                                               pursueTimer;                                    // 414
		float                                               furnitureAngle;                                 // 418
		float                                               furnitureEntryFootstepDeltaTarget;              // 41C
		float                                               packageIdleTimer;                               // 420
		float                                               equippedWeight;                                 // 424
		float                                               desiredSpeed;                                   // 428
		float                                               animationSpeed;                                 // 42C
		float                                               bleedoutTimer;                                  // 430
		float                                               bleedoutRate;                                   // 434
		float                                               bleedoutMaxHealth;                              // 438
		float                                               maxWardPower;                                   // 43C
		float                                               animGraphEventTimeout;                          // 440
		float                                               torchEvalTimer;                                 // 444
		float                                               alphaMult;                                      // 448
		float                                               scriptRefractPower;                             // 44C
		float                                               sleepingTimer;                                  // 450
		float                                               deferredKillTimer;                              // 454
		float                                               killMoveTimer;                                  // 458
		float                                               staggerTimer;                                   // 45C
		float                                               mountDismountSafetyTimer;                       // 460
		AITimeStamp                                         rangeWaypointIdleTimer;                         // 464
		std::int32_t                                        packageIdleNumber;                              // 468
		std::int32_t                                        reservationSlot;                                // 46C
		SubgraphIdentifier                                  currentFurnitureSubgraphID;                     // 470
		std::uint32_t                                       currentFurnitureMarkerID;                       // 478
		std::uint32_t                                       occupiedFurnitureMarkerID;                      // 47C
		std::uint64_t                                       nextExtraArrow3DUpdate;                         // 480
		std::uint32_t                                       deferredKill;                                   // 488
		std::uint32_t                                       flareFlags;                                     // 48C
		REX::TEnumSet<PACKAGE_OBJECT_TYPE, std::int32_t>    useItem;                                        // 490
		std::int16_t                                        animActionSuccess;                              // 494
		std::uint16_t                                       update3DModel;                                  // 496
		std::int8_t                                         weaponCullCounter;                              // 498
		std::int8_t                                         archetypeChangeType;                            // 499
		bool                                                animWeaponCull;                                 // 49A
		bool                                                aimingTarget;                                   // 49B
		bool                                                doneClothesChange;                              // 49C
		bool                                                pickPackIdle;                                   // 49D
		bool                                                doneOnce;                                       // 49E
		bool                                                refreshFlareFlags;                              // 49F
		bool                                                pickPocketed;                                   // 4A0
		bool                                                summonedCreature;                               // 4A1
		bool                                                forceNextUpdate;                                // 4A2
		bool                                                playedBeginIdles;                               // 4A3
		bool                                                playedEndIdles;                                 // 4A4
		bool                                                quickPlacement;                                 // 4A5
		bool                                                beenAttacked;                                   // 4A6
		bool                                                alwaysHit;                                      // 4A7
		bool                                                doNoDamage;                                     // 4A8
		bool                                                soulTrapped;                                    // 4A9
		bool                                                lookAt;                                         // 4AA
		bool                                                eating;                                         // 4AB
		bool                                                calcLight;                                      // 4AC
		bool                                                preventCombat;                                  // 4AD
		bool                                                dyingFromBleedout;                              // 4AE
		bool                                                fleeing;                                        // 4AF
		bool                                                instantGetOut;                                  // 4B0
		bool                                                hostileGuard;                                   // 4B1
		bool                                                stopIdleFailed;                                 // 4B2
		bool                                                killQueued;                                     // 4B3
		bool                                                ragdollInstant;                                 // 4B4
		bool                                                scriptDeferredKill;                             // 4B5
		bool                                                furnitureEntryLeftFootFirst;                    // 4B6
		bool                                                furnitureAnimationPlayed;                       // 4B7
		bool                                                queuedInstantInteractionAnimation;              // 4B8
		bool                                                queuedModifyInitialAnimationPose;               // 4B9
		bool                                                avoidPlayer;                                    // 4BA
		bool                                                usingPathingFaceTargetWhileTrackingOutOfRange;  // 4BB
	};
	static_assert(sizeof(MiddleHighProcessData) == 0x4C0);
}
