#pragma once

#include "RE/B/BSPointerHandle.h"
#include "RE/B/BSTArray.h"
#include "RE/I/IDLE_REPLAY_DELAY.h"
#include "RE/M/MovementLargeDelta.h"
#include "RE/N/NiBillboardNode.h"
#include "RE/N/NiPoint.h"
#include "RE/N/NonMorphFaceManagement.h"
#include "RE/R/ReanimateData.h"
#include "RE/T/TESShout.h"

namespace RE
{
	class ActorKnowledge;
	class AvoidAreaStruct;
	class DialogueItem;
	class IAIWorldLocation;
	class PathingRequest;
	class QueuedDialogueType;
	class StandardDetectionListener;

	enum class PLAYER_ACTION;

	class HighProcessData
	{
	public:
		enum class VOICE_STATE
		{
			kNone = 0,
			kRequest = 1,
			kStart = 2,
			kContinue = 3,
			kPrecast = 4,
			kPostcast = 5,
			kFail = 6
		};

		enum class FADE_STATE
		{
			kNormal = 0,
			kIn = 1,
			kOut = 2,
			kTeleportIn = 3,
			kTeleportOut = 4,
			kOutDisable = 5,
			kOutDelete = 6
		};

		enum class BUMP_TYPE
		{
			kNone = static_cast<std::underlying_type_t<BUMP_TYPE>>(-1),
			kSmall = 0,
			kBig = 1
		};

		// members
		NonMorphFaceManagement::InstanceData                               nonMorphChannelsInstance;       // 000
		GunStateData                                                       gunState;                       // 008
		BSTSmallArray<IDLE_REPLAY_DELAY, 1>                                replayDelay;                    // 020
		REX::TEnum<VOICE_STATE, std::uint32_t>                             voiceState;                     // 040
		TESShout*                                                          currentShout;                   // 048
		REX::TEnum<TESShout::VariationID, std::uint32_t>                   currentShoutVariation;          // 04C
		float                                                              voiceTimeElapsed;               // 050
		float                                                              voiceRecoveryTime;              // 054
		float                                                              healthRegenDelay;               // 058
		float                                                              conditionRegenDelay;            // 05C
		float                                                              staminaRegenDelay;              // 060
		float                                                              apRegenDelay;                   // 064
		float                                                              radsRegenDelay;                 // 068
		const IAIWorldLocation*                                            sandBoxLocation;                // 070
		BSTArray<ActorHandle>                                              lastSpokenToArray;              // 078
		BGSAnimationSequencer                                              animSequencer;                  // 090
		NiPoint3                                                           pathingCurrentMovementSpeed;    // 0C8
		NiPoint3                                                           pathingCurrentRotationSpeed;    // 0D4
		NiPoint3                                                           pathingDesiredPosition;         // 0E0
		NiPoint3                                                           pathingDesiredOrientation;      // 0EC
		NiPoint3                                                           pathingDesiredMovementSpeed;    // 0F8
		NiPoint3                                                           pathingDesiredRotationSpeed;    // 104
		MovementLargeDelta::IdleSelectionData                              pathingIdleSelectionEnums;      // 110
		ActorMovementData                                                  movementOutput;                 // 120
		float                                                              motionFeedbackTimer;            // 170
		float                                                              lastBumpDirection;              // 174
		ObjectRefHandle                                                    lastExtDoorActivated;           // 178
		float                                                              activationHeight;               // 17C
		ReanimateData                                                      myReanimateData;                // 180
		std::uint32_t                                                      CRCA[3];                        // 190
		Movement::TypeData                                                 currentMovementType;            // 1A0
		REX::TEnum<FADE_STATE, std::uint32_t>                              fadeState;                      // 220
		float                                                              fadeAlpha;                      // 224
		TESObjectREFR*                                                     teleportFadeRef;                // 228
		float                                                              elevatorFadeTimer;              // 230
		ObjectRefHandle                                                    headTrackingTargets[6];         // 234
		bool                                                               headTrackingTargetFlags[6];     // 24C
		float                                                              headTrackTargetTimer;           // 254
		NiPoint3                                                           headTrackTargetOffset;          // 258
		float                                                              headTrackHoldOffsetHoldTimer;   // 264
		float                                                              headTrackTargetOffsetTimer;     // 268
		std::uint32_t                                                      eyeTrackHandle;                 // 26C
		ObjectRefHandle                                                    lastTarget;                     // 270
		ObjectRefHandle                                                    pathLookAtTarget;               // 274
		BSPathingLocation                                                  cachedPathingLocation;          // 278
		BSNavmesh*                                                         cachedPathingLocationNavmesh;   // 2A8
		BSSpinLock                                                         cachedPathingLocationLock;      // 2B0
		float                                                              prevTailPitchChange;            // 2B8
		float                                                              cachedActorHeight;              // 2BC
		AITimeStamp                                                        bumpTimer;                      // 2C0
		AITimeStamp                                                        bumpReactionTimer;              // 2C4
		REX::TEnum<BUMP_TYPE, std::uint32_t>                               bumped;                         // 2C8
		float                                                              takeBackTimer;                  // 2CC
		AvoidAreaStruct*                                                   avoidAreas;                     // 2D0
		float                                                              avoidWaitTimer;                 // 2D8
		REX::TEnum<PLAYER_ACTION, std::uint32_t>                           playerActionReactionType;       // 2DC
		BSFixedStringCS                                                    strVoiceSubtitle;               // 2E0
		BSTArray<BSTTuple<std::uint32_t, NiPointer<ActorKnowledge>>>       knowledgeArray;                 // 2E8
		BSReadWriteLock                                                    knowledgeLock;                  // 300
		BSTArray<QueuedDialogueType*>                                      queueofGreetingsArray;          // 308
		NiPointer<BGSAttackData>                                           attackData;                     // 320
		NiPoint3                                                           locationOffsetByWaterPoint;     // 328
		BGSSoundOutput*                                                    outputModel;                    // 338
		std::uint32_t                                                      activateTopicID;                // 340
		float                                                              distanceSqFromPlayer;           // 344
		NiPoint3                                                           deathForceDirection;            // 348
		float                                                              deathForce;                     // 354
		float                                                              staggerDirection;               // 358
		float                                                              staggerMagnitude;               // 35C
		float                                                              lastAngleToCamera;              // 360
		float                                                              talkTimer;                      // 364
		float                                                              detectListTimer;                // 368
		float                                                              idleChatterTimer;               // 36C
		float                                                              clearTalkToListTimer;           // 370
		float                                                              maxAlpha;                       // 374
		float                                                              packageEvalTimer;               // 378
		float                                                              useItemTimer;                   // 37C
		float                                                              procedureEvalTimer;             // 380
		float                                                              checkToTalkTimer;               // 384
		std::uint32_t                                                      randomEventID;                  // 388
		NiNode*                                                            node;                           // 390
		float                                                              delayTimer;                     // 398
		float                                                              distanceMoved;                  // 39C
		float                                                              turnTime;                       // 3A0
		float                                                              evaluateAcquireTimer;           // 3A4
		std::int16_t                                                       lastDetection;                  // 3A8
		NiPoint3                                                           leftWeaponLastPos;              // 3AC
		NiPoint3                                                           rightWeaponLastPos;             // 3B8
		ObjectRefHandle                                                    greetActor;                     // 3C4
		float                                                              soundDelay;                     // 3C8
		BSSoundHandle                                                      soundHandle[2];                 // 3CC
		float                                                              greetingTimer;                  // 3DC
		float                                                              exclusiveTimer;                 // 3E0
		float                                                              idleTimer;                      // 3E4
		float                                                              detectGreetTimer;               // 3E8
		float                                                              breathTimer;                    // 3EC
		float                                                              voiceTimer;                     // 3F0
		float                                                              dyingTimer;                     // 3F4
		float                                                              awarePlayerTimer;               // 3F8
		float                                                              helloTimer;                     // 3FC
		TESTopicInfo*                                                      lastGreeting;                   // 400
		TESTopicInfo*                                                      nextGreeting;                   // 408
		TESIdleForm*                                                       idleToPlay;                     // 410
		TESIdleForm*                                                       talkIdle;                       // 418
		BSFixedString                                                      loadingDynamicIdleFilename;     // 420
		ObjectRefHandle                                                    idleTarget;                     // 428
		TESPackage*                                                        commandPackage;                 // 430
		DialogueItem*                                                      greetTopic;                     // 438
		ActorHandle                                                        dialogTarget;                   // 440
		void*                                                              faceGenGeomHandle;              // 448
		float                                                              scriptPackageEndTime;           // 450
		const ActorValueInfo*                                              lastCrippleValue;               // 458
		float                                                              healthBarAlphaValue;            // 460
		NiPointer<NiBillboardNode>                                         healthBarNode;                  // 468
		float                                                              actorHealthPercentage;          // 470
		float                                                              healthBarEmittanceValue;        // 474
		std::int32_t                                                       numberGuardsPursuing;           // 478
		float                                                              reEquipArmorTimer;              // 47C
		BSSimpleList<SpellItem*>*                                          leveledSpellList;               // 480
		float                                                              detectionModifier;              // 488
		float                                                              detectionModifierTimer;         // 48C
		float                                                              lightLevel;                     // 490
		float                                                              sceneHeadTrackTimer;            // 494
		float                                                              pCapVoiceFailsafeTimer;         // 498
		AITimeStamp                                                        lightLevelTimeStamp;            // 49C
		void*                                                              lipSynchAnim;                   // 4A0
		float                                                              lipTime;                        // 4A8
		float                                                              activateDoorFailedTimer;        // 4AC
		std::uint32_t                                                      detectionCounter;               // 4B0
		DetectionEvent*                                                    actorsGeneratedDetectionEvent;  // 4B8
		NiPointer<StandardDetectionListener>                               detectionListener;              // 4C0
		AITimer                                                            updateDetectionTimer;           // 4C8
		BSTSmartPointer<PathingRequest>                                    pathingRequest;                 // 4D0
		BSTSmallArray<DEFAULT_OBJECT, 2>                                   queuedActions;                  // 4D8
		BSTArray<AnimationSpeedInformationTypes::AnimationStateAdjustment> queuedAdjustments;              // 4F0
		BSTArray<AnimationSpeedInformationTypes::AnimationStateAdjustment> lastQueuedAdjustments;          // 508
		NiPoint3                                                           animationDelta;                 // 520
		NiPoint3                                                           animationAngleMod;              // 52C
		float                                                              animationUpdateDeltaTime;       // 538
		float                                                              absorbVisualTimer;              // 53C
		float                                                              hitReactionTimer;               // 540
		float                                                              holdFaceTimer;                  // 544
		float                                                              tryTalkIdleTimer;               // 548
		std::uint16_t                                                      tryTalk;                        // 54C
		Crime*                                                             crimeToReactTo;                 // 550
		std::uint8_t                                                       lastTurnDir;                    // 558
		std::uint8_t                                                       lastTurn;                       // 559
		std::uint8_t                                                       tracerCounter;                  // 55A
		REX::TEnum<COMMAND_TYPE, std::uint32_t>                            commandType;                    // 55C
		TESForm*                                                           retrieveTarget;                 // 560
		ActorHandle                                                        queuedDialogueTarget;           // 568
		bool                                                               processGreetSayTo;              // 56C
		bool                                                               checkDeadTalk;                  // 56D
		bool                                                               skippedUpdate;                  // 56E
		bool                                                               automaticFireAtLeastOne;        // 56F
		bool                                                               greetingFlag;                   // 570
		bool                                                               pickNewIdle;                    // 571
		bool                                                               skipVoiceEndIdleStop;           // 572
		bool                                                               weaponAlertDrawn;               // 573
		bool                                                               dialoguewithPlayer;             // 574
		bool                                                               inCommandState;                 // 575
		bool                                                               inWorkShopCommandState;         // 576
		bool                                                               continuingPackageforPC;         // 577
		bool                                                               activateAnim;                   // 578
		bool                                                               stop;                           // 579
		bool                                                               unequippedArmorToSwim;          // 57A
		bool                                                               allowForceReadyWeapon;          // 57B
		bool                                                               activateReady;                  // 57C
		bool                                                               dualCasting;                    // 57D
		bool                                                               plantedExplosive;               // 57E
		bool                                                               approachingAutoTeleportDoor;    // 57F
		bool                                                               allowDeathForce;                // 580
		bool                                                               arrested;                       // 581
		bool                                                               forceGreeting;                  // 582
		bool                                                               queuedActivation;               // 583
		bool                                                               isDoingSayTo;                   // 584
		bool                                                               hiding;                         // 585
		bool                                                               stopShoutAudioManually;         // 586
		bool                                                               farGeometry;                    // 587
		bool                                                               procedureDoesEquip;             // 588
		bool                                                               forceRotate;                    // 589
		bool                                                               speakingDeathLine;              // 58A
		bool                                                               fistsDrawn;                     // 58B
		bool                                                               freezeGraphLocomotionChannels;  // 58C
		bool                                                               freezeGraphLocomotionEvents;    // 58D
		bool                                                               lastGraphAllowRotation;         // 58E
		bool                                                               lastGraphDriven;                // 58F
		bool                                                               activateDoor;                   // 590
		bool                                                               startedDialogue;                // 591
		bool                                                               startingAggroRadius;            // 592
		bool                                                               playerActivated;                // 593
		bool                                                               itemEquipQueued;                // 594
		bool                                                               doingCommand;                   // 595
		bool                                                               pCapLineFired;                  // 596
		bool                                                               updateMovmentTypeCacheQueued;   // 597
		bool                                                               hasGreetingIdleChatterTicket;   // 598
		bool                                                               processingForceEquip;           // 599
		bool                                                               pCapLinePlaying;                // 59A
		bool                                                               faceGenLoadPending;             // 59B
		bool                                                               donotInterruptAnimation;        // 59C
		bool                                                               dialogueInterruptQueued;        // 59D
		bool                                                               pCapLineFailed;                 // 59E
		bool                                                               pathingRequestQuickTurn;        // 59F
	};
	static_assert(sizeof(HighProcessData) == 0x5A0);
}
