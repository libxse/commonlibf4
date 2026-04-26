#pragma once

namespace RE
{
	enum EXTRA_DATA_TYPE : std::int32_t
	{
		kNone,                          // BSExtraData
		kHavok,                         //
		kCell3D,                        //
		kWaterType,                     // ExtraCellWaterType
		kRegionList,                    //
		kSeenData,                      //
		kEditorID,                      // ExtraEditorID
		kCellMusicType,                 //
		kSkyRegion,                     //
		kCellMidLowProcess,             //
		kCellDetachTime,                //
		kPersistentCell,                //
		kKeywords,                      //
		kAction,                        //
		kStartingPosition,              //
		kAnim,                          //
		kHavokAnim,                     //
		kBiped,                         //
		kUsedMarkers,                   //
		kDistantData,                   //
		kRagdollData,                   // ExtraRagDollData
		kCellPrevisRefs,                //
		kInitActions,                   //
		kEssentialProtected,            //
		kPackagesStartLoc,              //
		kPackage,                       //
		kTresPassPackage,               // ExtraTresPassPackage
		kRunOncePackages,               //
		kReferenceHandle,               // ExtraReferenceHandles
		kFollower,                      //
		kLevCreaMod,                    //
		kGhost,                         //
		kOriginalReference,             //
		kOwnership,                     //
		kGlobal,                        //
		kRank,                          //
		kCount,                         //
		kHealth,                        // ExtraHealth
		kRangeDistOverride,             //
		kTimeLeft,                      //
		kCharge,                        //
		kLight,                         // ExtraLight
		kLock,                          // ExtraLock
		kTeleport,                      // ExtraTeleport
		kMapMarker,                     //
		kLeveledCreature,               // ExtraLeveledCreature
		kLevelItem,                     //
		kScale,                         //
		kSeed,                          //
		kMagicCaster,                   //
		kMagicTarget,                   //
		kMasterFileCell,                //
		kPlayerCrimeList,               //
		kObjectInstance,                // BGSObjectInstanceExtra
		kEnableStateParent,             //
		kEnableStateChildren,           //
		kItemDropper,                   //
		kDroppedItemList,               //
		kTeleportMarker,                //
		kInactivePowerArmor,            //
		kSavedHavokData,                //
		kCannotWear,                    //
		kPoison,                        //
		kMagicLight,                    //
		kLastFinishedSequence,          //
		kSavedAnimation,                //
		kNorthRotation,                 //
		kSpawnCount,                    //
		kFriendHits,                    //
		kHeadTrackTarget,               //
		kBoundArmor,                    //
		kRefractionProperty,            //
		kStartingWorldOrCell,           // ExtraStartingWorldOrCell
		kFavorite,                      // ExtraFavorite
		kEditorRef3DData,               //
		kEditorRefMoveData,             //
		kInfoGeneralTopic,              //
		kNoRumors,                      //
		kSound,                         //
		kTerminalState,                 //
		kLinkedRef,                     //
		kLinkedRefChildren,             //
		kActivateRef,                   //
		kActivateRefChildren,           //
		kTalkToPlayer,                  //
		kObjectHealth,                  //
		kImageSpace,                    //
		kNavmeshPortal,                 //
		kModelSwap,                     //
		kRadius,                        //
		kRadiation,                     //
		kFactionChanges,                // ExtraFactionChanges
		kDismemberedLimbs,              //
		kActorCause,                    //
		kMultibound,                    //
		kMultiboundData,                //
		kMultiboundRef,                 //
		kReflectedRefs,                 //
		kReflectorRefs,                 //
		kEmittanceSource,               //
		kRadioData,                     // ExtraRadioData
		kCombatStyle,                   //
		kLinkColorPair,                 //
		kPrimitive,                     //
		kOpenCloseActivateRef,          //
		kAnimNoteReceiver,              //
		kAmmo,                          // ExtraAmmo
		kPatrolRefData,                 //
		kPackageData,                   //
		kOcclusionShape,                //
		kCollisionData,                 //
		kSayOnceADayTopicInfo,          //
		kEncounterZone,                 //
		kSayToTopicInfo,                //
		kOcclusionPlaneRefData,         //
		kPortalRefData,                 //
		kPortal,                        //
		kRoom,                          //
		kGodRays,                       //
		kRoomRefData,                   //
		kGuardedRefData,                //
		kCreatureAwakeSound,            //
		kWaterZoneMap,                  //
		kHorse,                         //
		kIgnoredBySandbox,              //
		kCellAcousticSpace,             //
		kReservedMarkers,               //
		kCellTransCount,                //
		kWaterLightRefs,                //
		kLitWaterRefs,                  //
		kRadioRepeater,                 // ExtraRadioRepeater
		kActivateLoopSound,             //
		kPatrolRefInUseData,            //
		kAshpileRef,                    //
		kCreatureMovementSound,         //
		kFollowerSwimBreadcrumbs,       //
		kAliasInstanceArray,            // ExtraAliasInstanceArray
		kLocation,                      // ExtraLocation
		kMasterLocation,                //
		kLocationRefType,               //
		kPromotedRef,                   //
		kAnimSequencer,                 //
		kOutfitItem,                    //
		kEditorLocation,                //
		kLeveledItemBase,               //
		kLightData,                     // ExtraLightData
		kScene,                         //
		kBadPosition,                   //
		kHeadTrackingWeight,            //
		kFromAlias,                     //
		kShouldWear,                    //
		kFavorCost,                     //
		kAttachArrows3D,                //
		kTextDisplayData,               // ExtraTextDisplayData
		kAlphaCutoff,                   //
		kEnchantment,                   //
		kSoul,                          //
		kForcedTarget,                  //
		kSoundOutput,                   //
		kUniqueID,                      // ExtraUniqueID
		kFlags,                         //
		kRefrPath,                      //
		kDecalGroup,                    //
		kLockList,                      //
		kForcedLandingMarker,           //
		kLargeRefOwnerCells,            //
		kCellWaterEnvMap,               //
		kCellGrassData,                 //
		kTeleportName,                  //
		kActorInteraction,              //
		kWaterData,                     //
		kWaterCurrentZoneData,          //
		kAttachRef,                     //
		kAttachRefChildren,             //
		kGroupConstraint,               //
		kScriptedAnimDependence,        //
		kCachedScale,                   //
		kRaceData,                      //
		kGIDBuffer,                     //
		kMissingRefIDs,                 //
		kBendableSplineParams,          //
		kReferenceGroup,                //
		kLayer,                         //
		kMovementController,            //
		kReferenceCharacterController,  //
		kMaterialSwap,                  // ExtraMaterialSwap
		kInstanceData,                  // ExtraInstanceData
		kPowerArmor,                    //
		kAcousticParent,                //
		kInputEnableLayer,              //
		kProjectedDecalRef,             //
		kWorkshop,                      // Workshop::ExtraData
		kRadioReceiver,                 // ExtraRadioReceiver
		kCulledBone,                    //
		kActorValueStorage,             //
		kDirectAtTarget,                //
		kActivateText,                  //
		kCellCombinedRefs,              //
		kObjectBreakable,               //
		kSavedDynamicIdles,             //
		kIgnoredAttractKeywords,        //
		kModRank,                       //
		kInteriorLODWorldspace,         //
		kActorBoneScaleMap,             //
		kActorFXPickNodes,              //
		kPowerArmorPreload,             //
		kAnimGraphPreload,              //
		kAnimSounds,                    //
		kPowerLinks,                    // ExtraPowerLinks
		kSavedUnrecoverableSubgraphs,   //
		kRefWeaponSounds,               //
		kRefInvestedGold,               //
		kRefFurnitureEntryData,         //
		kVoiceType,                     //

		kTotal
	};
}
