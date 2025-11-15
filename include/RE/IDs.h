#pragma once

namespace RE::ID
{
	namespace ActiveEffect
	{
		inline constexpr REL::ID CheckDisplacementSpellOnTarget{ 0 };  // 1415178 - inlined
	}

	namespace Actor
	{
		inline constexpr REL::ID AddPerk{ 2230121 };
		inline constexpr REL::ID CanUseIdle{ 2229592 };
		inline constexpr REL::ID ClearAttackStates{ 2229773 };
		inline constexpr REL::ID EndInterruptPackage{ 2229892 };
		inline constexpr REL::ID ExitCover{ 2231166 };
		inline constexpr REL::ID GetAimVector{ 2230378 };
		inline constexpr REL::ID GetClosestBone{ 2230051 };
		inline constexpr REL::ID GetCollisionFilter{ 2277949 };
		inline constexpr REL::ID GetCombatStyle{ 2231053 };
		inline constexpr REL::ID SetCurrentAmmoCount{ 2229952 };
		inline constexpr REL::ID GetCurrentCollisionGroup{ 2229993 };
		inline constexpr REL::ID GetCurrentFireLocation{ 2231167 };
		inline constexpr REL::ID GetDesiredSpeed{ 2230410 };
		inline constexpr REL::ID GetHostileToActor{ 2229968 };
		inline constexpr REL::ID GetMountHandle{ 2231230 };
		inline constexpr REL::ID GetLevel{ 2229734 };
		inline constexpr REL::ID GetPerkRank{ 2230125 };
		inline constexpr REL::ID GetSex{ 2229674 };
		inline constexpr REL::ID HandleDefaultAnimationSwitch{ 2229780 };
		inline constexpr REL::ID HandleItemEquip{ 2229781 };
		inline constexpr REL::ID InitiateDoNothingPackage{ 2229807 };
		inline constexpr REL::ID IsCrippled{ 2230998 };
		inline constexpr REL::ID IsFollowing{ 2230013 };
		inline constexpr REL::ID IsJumping{ 2229640 };
		inline constexpr REL::ID IsPathValid{ 2230279 };
		inline constexpr REL::ID IsPathing{ 2234312 };
		inline constexpr REL::ID IsPathingComplete{ 2230274 };
		inline constexpr REL::ID IsQuadruped{ 2229614 };
		inline constexpr REL::ID IsSneaking{ 2207655 };
		inline constexpr REL::ID Move{ 2229934 };
		inline constexpr REL::ID PerformAction{ 2231177 };
		inline constexpr REL::ID RemovePerk{ 2230122 };
		inline constexpr REL::ID Reset3D{ 2229913 };
		inline constexpr REL::ID RewardExperience{ 2230428 };
		inline constexpr REL::ID SetGunState{ 2231175 };
		inline constexpr REL::ID SetHeading{ 2229625 };
		inline constexpr REL::ID TrespassAlarm{ 2229834 };
		inline constexpr REL::ID UpdateVoiceTimer{ 2230178 };
		inline constexpr REL::ID GetBodyPartData{ 2229571 };
		inline constexpr REL::ID GetEquippedItem{ 2231089 };
		inline constexpr REL::ID GetCrimeTrackingFaction{ 2229787 };
		inline constexpr REL::ID ForceDetect{ 2230194 };
		inline constexpr REL::ID GetDesirability{ 2229946 };
		inline constexpr REL::ID CalcArmorRating1{ 2230008 };
		inline constexpr REL::ID CalcArmorRating2{ 2230009 };
		inline constexpr REL::ID UnequipObject{ 2230479 };
		inline constexpr REL::ID UpdateSoundCallBack{ 2229974 };
		inline constexpr REL::ID GetFactionRank{ 2230100 };
		inline constexpr REL::ID IsAngryWithPlayer{ 2229998 };
		inline constexpr REL::ID RedressIfNeeded{ 2230394 };
		inline constexpr REL::ID UpdateSprinting{ 2230498 };
		inline constexpr REL::ID Jump{ 2229650 };
		inline constexpr REL::ID GetMobilityCrippled{ 2230996 };
		inline constexpr REL::ID SPECIALModifiedCallback{ 2231020 };
		inline constexpr REL::ID StopInteractingQuick{ 2231227 };
	}

	namespace ActorEquipManager
	{
		inline constexpr REL::ID Singleton{ 2690994 };
		inline constexpr REL::ID EquipObject{ 2231392 };
		inline constexpr REL::ID UnequipObject{ 2231395 };
		inline constexpr REL::ID UnequipItem{ 2231399 };
	}

	namespace ActorUtils
	{
		namespace ArmorRatingVisitorBase
		{
			inline constexpr REL::ID _operator{ 2227206 };
			inline constexpr REL::ID ctor{ 2227205 };
		}

		inline constexpr REL::ID GetEquippedArmorDamageResistance{ 2227189 };
	}

	namespace ActorValue
	{
		inline constexpr REL::ID Singleton{ 2189587 };
	}

	namespace AIFormulas
	{
		inline constexpr REL::ID GetBarterValue{ 2208969 };
	}

	namespace AIProcess
	{
		inline constexpr REL::ID GetCurrentAmmo{ 2232300 };
		inline constexpr REL::ID GetCommandType{ 2231825 };
		inline constexpr REL::ID GetOccupiedFurniture{ 2232401 };
		inline constexpr REL::ID IsWeaponSubgraphFinishedLoading{ 2231757 };
		inline constexpr REL::ID KnockExplosion{ 2232384 };
		inline constexpr REL::ID ProcessGreet{ 2231808 };
		inline constexpr REL::ID RequestLoadAnimationsForWeaponChange{ 2231758 };
		inline constexpr REL::ID SetActorsDetectionEvent{ 2231738 };
		inline constexpr REL::ID SetCurrentAmmo{ 2232302 };
		inline constexpr REL::ID SetCommandType{ 2231826 };
		inline constexpr REL::ID SetEquippedItem{ 2231627 };
		inline constexpr REL::ID SetupSpecialIdle{ 2231704 };
		inline constexpr REL::ID SetWeaponBonesCulled{ 2232535 };
		inline constexpr REL::ID StopCurrentIdle{ 2231705 };
		inline constexpr REL::ID SetRunOncePackage{ 2232344 };
		inline constexpr REL::ID AddToProcedureIndexRunning{ 2718412 };
		inline constexpr REL::ID ComputeLastTimeProcessed{ 2231541 };
	}

	namespace AnimationSystemUtils
	{
		inline constexpr REL::ID WillEventChangeState{ 2214271 };
	}

	namespace ApplyChangesFunctor
	{
		inline constexpr REL::ID WriteDataImpl{ 2223194 };
	}

	namespace ApplyColorUpdateEvent
	{
		inline constexpr REL::ID GetEventSource{ 2707340 };
	}

	namespace BarterMenu
	{
		inline constexpr REL::ID ClearTradingData{ 2222700 };
		inline constexpr REL::ID CompleteTrade{ 2222701 };
		inline constexpr REL::ID GetCapsOwedByPlayer{ 2222714 };
	}

	namespace BGSAnimationSystemUtils
	{
		inline constexpr REL::ID GetActiveSyncInfo{ 2214289 };
		inline constexpr REL::ID InitializeActorInstant{ 2236393 };
		inline constexpr REL::ID IsActiveGraphInTransition{ 2214305 };
	}

	namespace BGSAttachParentArray
	{
		inline constexpr REL::ID SetParentGroupNumber{ 2189125 };
	}

	namespace BGSCraftItemEvent
	{
		inline constexpr REL::ID EventIndex{ 2663409 };
	}

	namespace BGSCreatedObjectManager
	{
		inline constexpr REL::ID Singleton{ 2697789 };
		inline constexpr REL::ID DecrementRef{ 2228455 };
		inline constexpr REL::ID IncrementRef{ 2228454 };
	}

	namespace BGSDefaultObject
	{
		inline constexpr REL::ID Singleton{ 2690473 };
		inline constexpr REL::ID ctor{ 2197003 };
	}

	namespace BGSDefaultObjectManager
	{
		inline constexpr REL::ID Singleton{ 2192850 };
	}

	namespace BGSDynamicPersistenceManager
	{
		inline constexpr REL::ID Singleton{ 2689026 };
		inline constexpr REL::ID PromoteReference{ 2193819 };
		inline constexpr REL::ID DemoteReference{ 2193820 };
	}

	namespace BGSEntryPoint
	{
		inline constexpr REL::ID HandleEntryPoint{ 2206243 };
	}

	namespace BGSHackTerminal
	{
		inline constexpr REL::ID EventIndex{ 2663434 };
	}

	namespace BGSInventoryInterface
	{
		inline constexpr REL::ID Singleton{ 2689299 };
		inline constexpr REL::ID RequestInventoryItem{ 2194009 };
		inline constexpr REL::ID ForceMergeStacks{ 2194032 };
	}

	namespace BGSInventoryItem
	{
		inline constexpr REL::ID FindAndWriteStackData{ 2194123 };
		inline constexpr REL::ID GetDisplayFullName1{ 2194079 };
		inline constexpr REL::ID GetDisplayFullName2{ 2194080 };
		inline constexpr REL::ID GetInstanceData{ 2194072 };
		inline constexpr REL::ID GetInventoryValue{ 2194099 };
		inline constexpr REL::ID GetExtraDataAt{ 2194092 };
		inline constexpr REL::ID MergeStacks{ 2194109 };
		inline constexpr REL::ID IsEquipped{ 2194086 };
		inline constexpr REL::ID GetStackCount{ 2194107 };
		inline constexpr REL::ID IsQuestObject{ 2194076 };
		inline constexpr REL::ID GetTotalWeight{ 2194074 };
	}

	namespace BGSInventoryItemUtils
	{
		inline constexpr REL::ID GetInventoryValue{ 2194127 };
	}

	namespace BGSInventoryList
	{
		inline constexpr REL::ID FindAndWriteStackDataForItem{ 2194179 };
		inline constexpr REL::ID BuildFromContainer{ 2194158 };
		inline constexpr REL::ID ctor{ 2194153 };
		inline constexpr REL::ID AddItem{ 2194159 };
	}

	namespace BGSKeyword
	{
		inline constexpr REL::ID TypedKeywords{ 2692038 };
	}

	namespace BGSKeywordForm
	{
		inline constexpr REL::ID AddKeyword{ 2192766 };
		inline constexpr REL::ID RemoveKeyword{ 2192767 };
	}

	namespace BGSListForm
	{
		inline constexpr REL::ID AddScriptAddedForm{ 2203262 };
	}

	namespace BGSLoadGameBuffer
	{
		inline constexpr REL::ID LoadDataEndian{ 2228270 };
	}

	namespace BGSLocalizedStringDL
	{
		inline constexpr REL::ID GetText{ 2194238 };
	}

	namespace BGSMessage
	{
		inline constexpr REL::ID AddButton{ 0 };
		inline constexpr REL::ID GetConvertedDescription{ 2203353 };
	}

	namespace BGSMod
	{
		namespace Attachment
		{
			namespace Mod
			{
				inline constexpr REL::ID FindModsForLooseMod{ 2197524 };
				inline constexpr REL::ID GetData{ 0 };  // 33658 - inlined?
				inline constexpr REL::ID GetLooseMod{ 2197514 };
				inline constexpr REL::ID SetLooseMod{ 2197558 };
			}

			inline constexpr REL::ID GetAllLooseMods{ 2661620 };
		}

		namespace Container
		{
			inline constexpr REL::ID GetData{ 2189206 };
		}

		namespace Template
		{
			namespace Items
			{
				inline constexpr REL::ID CreateInstanceDataForObjectAndExtra{ 2189244 };
			}
		}
	}

	namespace BGSNumericIDIndex
	{
		inline constexpr REL::ID GetNumericID{ 2228199 };
		inline constexpr REL::ID SetNumericID{ 2228200 };
	}

	namespace BGSObjectInstance
	{
		inline constexpr REL::ID ctor{ 2197563 };
	}

	namespace BGSObjectInstanceExtra
	{
		inline constexpr REL::ID ctor{ 2189015 };
		inline constexpr REL::ID AttachModToReference{ 2189033 };
		inline constexpr REL::ID HasMod{ 2189026 };
		inline constexpr REL::ID AddMod{ 2189025 };
		inline constexpr REL::ID RemoveInvalidMods{ 2189028 };
		inline constexpr REL::ID RemoveMod{ 2189027 };
		inline constexpr REL::ID GetNumMods{ 2189019 };
	}

	namespace BGSOpenCloseForm
	{
		inline constexpr REL::ID AutoCloseRef{ 2192797 };
		inline constexpr REL::ID GetOpenState{ 2192799 };
		inline constexpr REL::ID HasOnlyOpenCloseAnims{ 2192796 };
		inline constexpr REL::ID IsAnimating{ 2192801 };
		inline constexpr REL::ID IsOpenCloseEvent{ 2192795 };
		inline constexpr REL::ID IsOpenCloseForm{ 2192790 };
		inline constexpr REL::ID SetOpenState{ 2192798 };
	}

	namespace BGSPerkRankArray
	{
		inline constexpr REL::ID AllocatePerkRankArray{ 2192837 };
		inline constexpr REL::ID ClearPerks{ 2192836 };
	}

	namespace BGSPickLockEvent
	{
		inline constexpr REL::ID EventIndex{ 2663410 };
		inline constexpr REL::ID ctor{ 2214021 };
	}

	namespace BGSProjectile
	{
		inline constexpr REL::ID CollidesWithSmallTransparentLayer{ 2197620 };
	}

	namespace BGSQuestInstanceText
	{
		inline constexpr REL::ID ParseString{ 2206630 };
	}

	namespace BGSSaveLoadFileEntry
	{
		inline constexpr REL::ID DeleteGame{ 2227855 };
		inline constexpr REL::ID LoadData{ 2227871 };
	}

	namespace BGSSaveGameBuffer
	{
		inline constexpr REL::ID SaveDataEndian{ 2228319 };
	}

	namespace BGSSaveLoadManager
	{
		inline constexpr REL::ID Singleton{ 2697802 };
		inline constexpr REL::ID BuildSaveGameList{ 2228053 };
		inline constexpr REL::ID GetSaveDirectoryPath{ 2228028 };
		inline constexpr REL::ID QueueSaveLoadTask{ 2228080 };
	}

	namespace BGSScene
	{
		inline constexpr REL::ID ResetAllSceneActions{ 2206864 };
		inline constexpr REL::ID SetSceneActive{ 2206845 };
	}

	namespace BGSSceneActionNPCResponseDialogue
	{
		inline constexpr REL::ID GetCurrentTopicInfo{ 2196825 };
		inline constexpr REL::ID UpdateAction1{ 2196817 };
		inline constexpr REL::ID UpdateAction2{ 2196800 };
	}

	namespace BGSSceneActionPlayerDialogue
	{
		inline constexpr REL::ID GetCurrentTopicInfo{ 2196825 };
	}

	namespace BGSStoryEventManager
	{
		inline constexpr REL::ID Singleton{ 2693504 };
		inline constexpr REL::ID AddEvent{ 2214088 };
	}

	namespace BGSSynchronizedAnimationManager
	{
		inline constexpr REL::ID Singleton{ 2690996 };
		inline constexpr REL::ID IsReferenceInSynchronizedScene{ 2214437 };
	}

	namespace BGSTerminal
	{
		inline constexpr REL::ID GetHackDifficultyLockLevel{ 2197777 };
		inline constexpr REL::ID IsTerminalRefInUse{ 2197779 };
		inline constexpr REL::ID Show{ 2197776 };
		inline constexpr REL::ID Activate{ 2197778 };
	}

	namespace bhkCharacterController
	{
		inline constexpr REL::ID Jump{ 2278191 };
	}

	namespace bhkNPCollisionObject
	{
		inline constexpr REL::ID CopyMembers{ 2277907 };
		inline constexpr REL::ID GetBody{ 2277926 };
		inline constexpr REL::ID GetBodyId{ 2277928 };
		inline constexpr REL::ID GetShape{ 2277929 };
		inline constexpr REL::ID GetTransform{ 2277944 };
		inline constexpr REL::ID SetMotionType{ 2277913 };
		inline constexpr REL::ID SetTransform{ 2277945 };
		inline constexpr REL::ID Getbhk{ 2277919 };
	}

	namespace bhkPhysicsSystem
	{
		inline constexpr REL::ID ctor{ 2278008 };
		inline constexpr REL::ID AddToWorld{ 2278019 };
		inline constexpr REL::ID CopyMembers{ 2278007 };
	}

	namespace bhkPickData
	{
		inline constexpr REL::ID ctor{ 2230668 };
		inline constexpr REL::ID SetStartEnd{ 2236622 };
		inline constexpr REL::ID Reset{ 2277761 };
		inline constexpr REL::ID HasHit{ 2277770 };
		inline constexpr REL::ID GetHitFraction{ 2277772 };
		inline constexpr REL::ID GetAllCollectorRayHitSize{ 2277765 };
		inline constexpr REL::ID GetAllCollectorRayHitAt{ 2277766 };
		inline constexpr REL::ID SortAllCollectorHits{ 2277767 };
		inline constexpr REL::ID GetNiAVObject{ 2277764 };
		inline constexpr REL::ID GetBody{ 2277762 };
	}

	namespace bhkUtilFunctions
	{
		inline constexpr REL::ID FindFirstCollisionObject{ 2278093 };
	}

	namespace bhkWorld
	{
		inline constexpr REL::ID AddPhysicsSystem{ 2277752 };
		inline constexpr REL::ID RemovePhysicsSystem{ 2277753 };
		inline constexpr REL::ID RemoveObjects{ 2277721 };
	}

	namespace BIPOBJECT
	{
		inline constexpr REL::ID dtor{ 2194330 };
	}

	namespace BSAudioManager
	{
		inline constexpr REL::ID Singleton{ 2703058 };
		inline constexpr REL::ID GetSoundHandleByName{ 2267105 };
		inline constexpr REL::ID GetSoundHandleByFile{ 2267103 };
	}

	namespace BSAwardsSystemUtility
	{
		inline constexpr REL::ID Singleton{ 2255115 };
	}

	namespace BSGFxDisplayObject
	{
		inline constexpr REL::ID RemoveChild{ 2287327 };
	}

	namespace BSGFxObject
	{
		inline constexpr REL::ID AcquireFlashObjectByMemberName{ 2287014 };
		inline constexpr REL::ID AcquireFlashObjectByPath{ 2287015 };
	}

	namespace BSGFxShaderFXTarget
	{
		inline constexpr REL::ID ProcessEvent{ 2287033 };
		inline constexpr REL::ID AppendShaderFXInfos{ 2287021 };
		inline constexpr REL::ID CreateAndSetFiltersToColor1{ 2287028 };
		inline constexpr REL::ID CreateAndSetFiltersToColor2{ 2287029 };
		inline constexpr REL::ID CreateAndSetFiltersToHUD{ 2287027 };
		inline constexpr REL::ID EnableShadedBackground{ 2287022 };
	}

	namespace BSGraphics
	{
		namespace Renderer
		{
			inline constexpr REL::ID IncRef{ 2276869 };
			inline constexpr REL::ID DecRef{ 2276870 };
			inline constexpr REL::ID Begin{ 2276833 };
			inline constexpr REL::ID End{ 2276834 };
			inline constexpr REL::ID Lock{ 2276828 };
			inline constexpr REL::ID Unlock{ 2276829 };
		}

		namespace RenderTargetManager
		{
			inline constexpr REL::ID Singleton{ 2666735 };
			inline constexpr REL::ID SetEnableDynamicResolution{ 2277197 };
		}

		namespace State
		{
			inline constexpr REL::ID Singleton{ 2704621 };
		}

		namespace Utility
		{
			inline constexpr REL::ID ConvertHALFToNiPoint3Stream{ 2277113 };
			inline constexpr REL::ID ConvertNiPoint3ToHALFStream{ 2277114 };
			inline constexpr REL::ID PackVertexData{ 2277106 };
			inline constexpr REL::ID UnpackVertexData{ 2277129 };
		}

		inline constexpr REL::ID GetRendererData{ 2704429 };
		inline constexpr REL::ID GetCurrentRendererWindow{ 2704431 };
	}

	namespace BSIdleInputWatcher
	{
		inline constexpr REL::ID Singleton{ 2693716 };
	}

	namespace BSInputDeviceManager
	{
		inline constexpr REL::ID Singleton{ 2694300 };
	}

	namespace BSInputEnableLayer
	{
		inline constexpr REL::ID DecRef{ 2268272 };
	}

	namespace BSInputEnableManager
	{
		inline constexpr REL::ID Singleton{ 2689007 };
		inline constexpr REL::ID AllocateNewLayer{ 2268244 };
		inline constexpr REL::ID EnableUserEvent{ 2268263 };
		inline constexpr REL::ID EnableOtherEvent{ 2268265 };
	}

	namespace BSModelDB
	{
		inline constexpr REL::ID Demand1{ 2275153 };
		inline constexpr REL::ID Demand2{ 2275154 };
	}

	namespace BSPointerHandle
	{
		namespace BSPointerHandleManagerInterface
		{
			inline constexpr REL::ID CreateHandle{ 2188375 };
			inline constexpr REL::ID GetHandle{ 2188676 };
			inline constexpr REL::ID GetSmartPointer{ 2188681 };
		}
	}

	namespace BSRandom
	{
		inline constexpr REL::ID UnsignedInt{ 2267950 };
		inline constexpr REL::ID Float{ 2267953 };
		inline constexpr REL::ID Float0To1{ 2267954 };
	}

	namespace BSResource_Archive2_AsyncReaderStream
	{
		inline constexpr REL::ID DoOpen{ 2269387 };
		inline constexpr REL::ID DoClose{ 2269380 };
		inline constexpr REL::ID DoClone{ 2269379 };
		inline constexpr REL::ID DoStartRead{ 2269395 };
		inline constexpr REL::ID DoStartPacketAlignedBufferedRead{ 2269394 };
		inline constexpr REL::ID DoWait{ 2269399 };
	}

	namespace BSResource_Archive2_ReaderStream
	{
		inline constexpr REL::ID DoOpen{ 2269280 };
		inline constexpr REL::ID DoClose{ 2269285 };
		inline constexpr REL::ID DoGetKey{ 2269288 };
		inline constexpr REL::ID DoClone{ 2269279 };
		inline constexpr REL::ID DoRead{ 2269281 };
		inline constexpr REL::ID DoSeek{ 2269282 };
		inline constexpr REL::ID DoPrefetchAll{ 2269390 };
		inline constexpr REL::ID DoCreateAsync{ 2269287 };
	}

	namespace BSResource_EntryDBBaseUtil
	{
		inline constexpr REL::ID ReleaseEntryAction{ 2269463 };
	}

	namespace BSResource_GlobalLocations
	{
		inline constexpr REL::ID Singleton{ 2703394 };
	}

	namespace BSResource_GlobalPaths
	{
		inline constexpr REL::ID Singleton{ 2703393 };
	}

	namespace BSResource
	{
		inline constexpr REL::ID RegisterLocation{ 2269481 };
		inline constexpr REL::ID GetOrCreateStream{ 2269490 };

		namespace ID
		{
			inline constexpr REL::ID GenerateFromPath{ 2269259 };
		}
	}

	namespace BSResourceNiBinaryStream
	{
		inline constexpr REL::ID Seek{ 2269834 };
		inline constexpr REL::ID DoRead{ 2269839 };
		inline constexpr REL::ID DoWrite{ 2269840 };
		inline constexpr REL::ID GetBufferInfo{ 2269836 };
		inline constexpr REL::ID Ctor{ 2269830 };
		inline constexpr REL::ID Dtor{ 2269832 };
		inline constexpr REL::ID BinaryStreamWithRescan{ 0 };
	}

	namespace BSScaleformManager
	{
		inline constexpr REL::ID Singleton{ 2689600 };
		inline constexpr REL::ID LoadMovie{ 2287422 };
		inline constexpr REL::ID GetMovieFilename{ 2287428 };
		inline constexpr REL::ID InitMovieViewport{ 2287430 };
		inline constexpr REL::ID FileUncacheOnMenuOpen{ 2667999 };
		inline constexpr REL::ID IsNameValid{ 2287425 };
	}

	namespace BSScaleformRenderer
	{
		inline constexpr REL::ID Initialize{ 2284938 };
	}

	namespace BSScaleformTranslator
	{
		inline constexpr REL::ID AddTranslations{ 2295298 };
	}

	namespace BSScript_Array
	{
		inline constexpr REL::ID ctor{ 2314915 };
	}

	namespace BSScript_ArrayWrapper
	{
		inline constexpr REL::ID ReplaceArray{ 2250435 };
	}

	namespace BSScript_Internal_NativeFunctionBase
	{
		inline constexpr REL::ID Call{ 2314780 };
	}

	namespace BSScript_Internal_Stack
	{
		inline constexpr REL::ID GetPageForFrame{ 2314680 };
		inline constexpr REL::ID GetStackFrameVariable{ 2314681 };
	}

	namespace BSScript_Object
	{
		inline constexpr REL::ID DecRef{ 2314437 };
		inline constexpr REL::ID GetHandle{ 2314431 };
		inline constexpr REL::ID IncRef{ 2314436 };
	}

	namespace BSScript_ObjectTypeInfo
	{
		inline constexpr REL::ID dtor{ 2314513 };
	}

	namespace BSScript_ObjectBindPolicy
	{
		inline constexpr REL::ID BindObject{ 2314370 };
		inline constexpr REL::ID UnbindObject{ 2314372 };
	}

	namespace BSScriptUtil
	{
		inline constexpr REL::ID BaseObjectName{ 2702269 };
	}

	namespace BSShaderProperty
	{
		inline constexpr REL::ID SetMaterial{ 2316285 };
	}

	namespace BSShaderTextureSet
	{
		inline constexpr REL::ID CreateObject{ 2316324 };
	}

	namespace BSSoundHandle
	{
		inline constexpr REL::ID FadeInPlay{ 2267075 };
		inline constexpr REL::ID FadeOutAndRelease{ 2267076 };
	}

	namespace BSSpinLock
	{
		namespace BSReadWriteLock
		{
			inline constexpr REL::ID lock_read{ 2267897 };
			inline constexpr REL::ID lock_write{ 2267898 };
			inline constexpr REL::ID try_lock_read{ 2267901 };
			inline constexpr REL::ID try_lock_write{ 2267902 };
		}

		inline constexpr REL::ID lock{ 2192245 };
		inline constexpr REL::ID try_lock{ 2267902 };
	}

	namespace BSStringPool
	{
		namespace Entry
		{
			inline constexpr REL::ID Release{ 2268720 };
		}

		inline constexpr REL::ID GetEntry_char{ 2268729 };
		inline constexpr REL::ID GetEntry_wchar{ 2268730 };
	}

	namespace BSStringT
	{
		inline constexpr REL::ID Set{ 2189084 };
	}

	namespace BSSystemFileStreamer
	{
		inline constexpr REL::ID UncacheAll{ 2268797 };
	}

	namespace BSTempEffectDebris
	{
		inline constexpr REL::ID ctor{ 2212059 };
	}

	namespace BSTEvent
	{
		namespace BSTGlobalEvent
		{
			inline constexpr REL::ID Singleton{ 2688814 };
		}
	}

	namespace BSThreadEvent
	{
		inline constexpr REL::ID InitSDM{ 2268180 };
	}

	namespace BSTimer
	{
		inline constexpr REL::ID Singleton{ 2703179 };
		inline constexpr REL::ID QGlobalTimeMultiplier{ 2666307 };
		inline constexpr REL::ID QGlobalTimeMultiplierTarget{ 2666308 };
		inline constexpr REL::ID SetGlobalTimeMultiplier{ 2267970 };
	}

	namespace BSUIMessageData
	{
		inline constexpr REL::ID SendUIBoolMessage{ 2284981 };
		inline constexpr REL::ID SendUIStringMessage{ 2284977 };
		inline constexpr REL::ID SendUIPtrMessage{ 2284982 };
		inline constexpr REL::ID SendUIStringUIntMessage{ 2284979 };
	}

	namespace BSUtilities
	{
		inline constexpr REL::ID ConvertFloatToHalf{ 2212098 };
		inline constexpr REL::ID ConvertHalfToFloat{ 2195843 };
		inline constexpr REL::ID GetObjectByName{ 2274841 };
	}

	namespace Calendar
	{
		inline constexpr REL::ID Singleton{ 2689092 };
		inline constexpr REL::ID GetDaysPassed{ 2228563 };
	}

	namespace CanDisplayNextHUDMessage
	{
		inline constexpr REL::ID GetEventSource{ 2695041 };
	}

	namespace CellAttachDetachEvent
	{
		inline constexpr REL::ID GetEventSource{ 2192250 };
	}

	namespace ColorUpdateEvent
	{
		inline constexpr REL::ID GetEventSource{ 2695540 };
	}

	namespace CombatBehaviorFindObject
	{
		inline constexpr REL::ID EvaluateArmor{ 2241004 };
	}

	namespace CombatFormulas
	{
		inline constexpr REL::ID GetWeaponDisplayAccuracy{ 2209049 };
		inline constexpr REL::ID GetWeaponDisplayDamage{ 2209046 };
		inline constexpr REL::ID GetWeaponDisplayRange{ 2209047 };
		inline constexpr REL::ID GetWeaponDisplayRateOfFire{ 2209048 };
		inline constexpr REL::ID CalcTargetedLimbDamage{ 2209033 };
		inline constexpr REL::ID CalcWeaponDamage{ 2209001 };
		inline constexpr REL::ID GetNumCrippledAttackConditions{ 2209041 };
		inline constexpr REL::ID CalcScopeSteadyActionPointDrain{ 2209045 };
	}

	namespace CombatUtilities
	{
		inline constexpr REL::ID CalculateProjectileLOS1{ 2240617 };
		inline constexpr REL::ID CalculateProjectileLOS2{ 2240616 };
		inline constexpr REL::ID CalculateProjectileTrajectory{ 2240611 };
		inline constexpr REL::ID WorldGravity{ 2700340 };
	}

	namespace ComparisonQualifiers
	{
		inline constexpr REL::ID ContainerQualifier{ 2190674 };
		inline constexpr REL::ID UIQualifier{ 2190675 };
	}

	namespace Console
	{
		inline constexpr REL::ID ExecuteCommand{ 2248537 };
		inline constexpr REL::ID GetCurrentPickIndex{ 2701382 };
		inline constexpr REL::ID GetPickRef{ 2701395 };
		inline constexpr REL::ID GetPickRefs{ 2701391 };
		inline constexpr REL::ID SetCurrentPickREFR{ 2248551 };
	}

	namespace ConsoleLog
	{
		inline constexpr REL::ID Singleton{ 2690148 };
		inline constexpr REL::ID AddString{ 2248593 };
		inline constexpr REL::ID Print{ 2248591 };
	}

	namespace ContainerMenu
	{
		inline constexpr REL::ID TakeAllItems{ 2248619 };
	}

	namespace ContainerMenuBase
	{
		namespace ItemSorter
		{
			inline constexpr REL::ID IncrementSort{ 2222848 };
		}
	}

	namespace ControlMap
	{
		inline constexpr REL::ID Singleton{ 2692014 };
		inline constexpr REL::ID PopInputContext{ 2268336 };
		inline constexpr REL::ID PushInputContext{ 2268335 };
		inline constexpr REL::ID RemapButton{ 2268330 };
		inline constexpr REL::ID SaveRemappings{ 0 };
		inline constexpr REL::ID SetTextEntryMode{ 2268339 };
	}

	namespace CurrentRadiationSourceCount
	{
		inline constexpr REL::ID GetEventSource{ 2696196 };
	}

	namespace DEFAULT_OBJECT_DATA
	{
		inline constexpr REL::ID GetDefaultObjectData{ 838886 };
	}

	namespace DialogueCameraState
	{
		inline constexpr REL::ID UpdateActorsAndAction{ 2214898 };
	}

	namespace DialogueMenuUtils
	{
		inline constexpr REL::ID OpenMenu{ 2249658 };
		inline constexpr REL::ID CloseMenu{ 2249659 };
		inline constexpr REL::ID ShowSpeechChallengeAnim{ 2249665 };
	}

	namespace DoBeforeNewOrLoadCompletedEvent
	{
		inline constexpr REL::ID GetEventSource{ 2695542 };
	}

	namespace EffectItem
	{
		inline constexpr REL::ID GetDescription{ 2189612 };
	}

	namespace EquippedWeaponData
	{
		inline constexpr REL::ID SetupFireSounds{ 2232275 };
	}

	namespace ExamineMenu
	{
		inline constexpr REL::ID BuildWeaponScrappingArray{ 2223077 };
		inline constexpr REL::ID GetSelectedIndex{ 2223022 };
		inline constexpr REL::ID ShowConfirmMenu{ 2223081 };
		inline constexpr REL::ID ConsumeSelectedItems{ 2223052 };
		inline constexpr REL::ID BuildConfirmed{ 2223013 };
		inline constexpr REL::ID GetBuildConfirmQuestion{ 2223057 };
	}

	namespace ExteriorCellSingleton
	{
		inline constexpr REL::ID Singleton{ 2689084 };
	}

	namespace ExtraDataList
	{
		inline constexpr REL::ID CreateInstanceData{ 2190185 };
		inline constexpr REL::ID GetLegendaryMod{ 2190180 };
		inline constexpr REL::ID SetBendableSplineInfo{ 2190623 };
		inline constexpr REL::ID SetDisplayNameFromInstanceData{ 2190179 };
		inline constexpr REL::ID SetOverrideName{ 2190167 };
		inline constexpr REL::ID SetStartingWorldOrCell{ 2191213 };
		inline constexpr REL::ID GetHealthPerc{ 2190226 };
		inline constexpr REL::ID SetHealthPerc{ 2190124 };
		inline constexpr REL::ID ClearFavorite{ 2190191 };
		inline constexpr REL::ID IsFavorite{ 2190189 };
		inline constexpr REL::ID IsDamaged{ 2190224 };
		inline constexpr REL::ID CompareList{ 2190098 };
		inline constexpr REL::ID SetFavorite{ 2190188 };
		inline constexpr REL::ID GetPrimitive{ 2190427 };
	}

	namespace ExtraTextDisplayData
	{
		inline constexpr REL::ID GetDisplayName{ 2191318 };
	}

	namespace FavoritesManager
	{
		inline constexpr REL::ID Singleton{ 2694399 };
		inline constexpr REL::ID IsComponentFavorite{ 2248752 };
		inline constexpr REL::ID UseQuickkeyItem{ 2248744 };
		inline constexpr REL::ID HandleEvent{ 2248740 };
		inline constexpr REL::ID Call{ 2248766 };
	}

	namespace FlatScreenModel
	{
		inline constexpr REL::ID Singleton{ 2694427 };
	}

	namespace GameMenuBase
	{
		inline constexpr REL::ID SetIsTopButtonBar{ 2223204 };
		inline constexpr REL::ID OnMenuDisplayStateChanged{ 2223205 };
		inline constexpr REL::ID CacheShaderFXQuadsForRenderer_Impl{ 2223200 };
		inline constexpr REL::ID TransferCachedShaderFXQuadsForRenderer{ 2223201 };
		inline constexpr REL::ID SetViewportRect{ 2223202 };
		inline constexpr REL::ID AppendShaderFXInfos{ 2223203 };
		inline constexpr REL::ID SetUpButtonBar{ 2223197 };
	}

	namespace GamePlayFormulas
	{
		inline constexpr REL::ID CanHackGateCheck{ 2209069 };
		inline constexpr REL::ID CanPickLockGateCheck{ 2209066 };
		inline constexpr REL::ID GetExperienceReward{ 2209076 };
		inline constexpr REL::ID GetLockXPReward{ 2209070 };
		inline constexpr REL::ID CalculateItemHealthDamageBonus{ 2209087 };
		inline constexpr REL::ID CalcSpringingActionPoints{ 2209071 };
		inline constexpr REL::ID GetSweetSpotAngle{ 2209082 };
		inline constexpr REL::ID GetPartialPickAngle{ 2209083 };
		inline constexpr REL::ID GetPickBreakSeconds{ 2209084 };
		inline constexpr REL::ID GetHackingWordCount{ 2209067 };
		inline constexpr REL::ID CalculateItemValue{ 2209074 };
	}

	namespace GameScript
	{
		namespace HandlePolicy
		{
			inline constexpr REL::ID DropSaveLoadRemapData{ 2249995 };
			inline constexpr REL::ID GetInventoryObjFromHandle{ 2249989 };
			inline constexpr REL::ID UpdatePersistence{ 2249991 };
		}

		namespace ObjectBindPolicy
		{
			inline constexpr REL::ID EndSaveLoad{ 2250482 };
		}

		namespace GameVM
		{
			inline constexpr REL::ID Singleton{ 2689134 };
			inline constexpr REL::ID QueuePostRenderCall{ 2251314 };
			inline constexpr REL::ID RegisterForAllGameEvents{ 2251353 };
			inline constexpr REL::ID SendEventToObjectAndRelated{ 2251344 };
		}

		inline constexpr REL::ID LogFormError{ 2251028 };
		inline constexpr REL::ID BindCObject{ 2249771 };
	}

	namespace GameUIModel
	{
		inline constexpr REL::ID Singleton{ 2695523 };
		inline constexpr REL::ID UpdateDataModels{ 2220905 };
	}

	namespace GridCellArray
	{
		inline constexpr REL::ID Get{ 2194566 };
	}

	namespace HolotapeMenu
	{
		inline constexpr REL::ID ShowHolotapeInPipboy{ 2224028 };
		inline constexpr REL::ID ShowHolotapeInTerminal{ 2224029 };
	}

	namespace HUDExperienceMeter
	{
		inline constexpr REL::ID UpdateDisplayObject{ 2220382 };
	}

	namespace HUDMenuUtils
	{
		inline constexpr REL::ID GetGameplayHUDColor{ 2248840 };
		inline constexpr REL::ID GetGameplayHUDBackgroundColor{ 2248845 };
		inline constexpr REL::ID WorldPtToScreenPt3{ 2222464 };
	}

	namespace HUDModeEvent
	{
		inline constexpr REL::ID GetEventSource{ 2694697 };
	}

	namespace IAnimationGraphManagerHolder
	{
		inline constexpr REL::ID SetGraphVariableBool{ 2214543 };
		inline constexpr REL::ID SetGraphVariableFloat{ 2214545 };
		inline constexpr REL::ID SetGraphVariableInt{ 2214544 };
		inline constexpr REL::ID RevertAnimationGraphManager{ 2214541 };
	}

	namespace IFormFactory
	{
		inline constexpr REL::ID Factories{ 2689177 };
	}

	namespace ImageSpaceEffectFullScreenBlur
	{
		inline constexpr REL::ID Disable{ 2713225 };
	}

	namespace ImageSpaceEffectGetHit
	{
		inline constexpr REL::ID Disable{ 2713237 };
	}

	namespace ImageSpaceEffectHDR
	{
		inline constexpr REL::ID UsePipboyScreenMask{ 2678029 };
	}

	namespace ImageSpaceEffectPipboyScreen
	{
		inline constexpr REL::ID PowerArmorPipboy{ 2713203 };
	}

	namespace ImageSpaceEffectRadialBlur
	{
		inline constexpr REL::ID Disable{ 2713225 };
	}

	namespace ImageSpaceEffectTemporalAA
	{
		inline constexpr REL::ID MaskS{ 2713052 };
	}

	namespace ImageSpaceManager
	{
		inline constexpr REL::ID Singleton{ 2712627 };
	}

	namespace ImageSpaceModifierInstance
	{
		inline constexpr REL::ID Stop{ 2199897 };
	}

	namespace ImageSpaceModifierInstanceDOF
	{
		inline constexpr REL::ID Trigger{ 2199922 };
	}

	namespace ImageSpaceModifierInstanceForm
	{
		inline constexpr REL::ID Trigger1{ 2199906 };
		inline constexpr REL::ID Trigger2{ 2199907 };
		inline constexpr REL::ID Stop1{ 2199909 };
		inline constexpr REL::ID Stop2{ 2199910 };
	}

	namespace IMenu
	{
		inline constexpr REL::ID ShouldHandleEvent{ 2287392 };
		inline constexpr REL::ID PassesRenderConditionText{ 2287379 };
		inline constexpr REL::ID OnSetSafeRect{ 2287375 };
		inline constexpr REL::ID ProcessScaleformEvent{ 2287395 };
		inline constexpr REL::ID RefreshPlatform{ 2287374 };
	}

	namespace Interface3D
	{
		inline constexpr REL::ID Create{ 2222519 };
		inline constexpr REL::ID GetByName{ 2222524 };
		inline constexpr REL::ID MainScreen_AddPointLight{ 2222531 };
		inline constexpr REL::ID MainScreen_AddSpotLight{ 2222532 };
		inline constexpr REL::ID MainScreen_ClearLights{ 2222533 };
		inline constexpr REL::ID MainScreen_SetScreenAttached3D{ 2222528 };
		inline constexpr REL::ID MainScreen_SetWorldAttached3D{ 2222529 };
		inline constexpr REL::ID Offscreen_AddLight{ 2222543 };
		inline constexpr REL::ID Offscreen_Clear3D{ 2222542 };
		inline constexpr REL::ID Offscreen_ClearLights{ 2222545 };
		inline constexpr REL::ID Offscreen_GetRenderTargetHeight{ 2222538 };
		inline constexpr REL::ID Offscreen_GetRenderTargetWidth{ 2222537 };
		inline constexpr REL::ID Offscreen_Set3D{ 2222541 };
		inline constexpr REL::ID Offscreen_SetDebugMode{ 2222549 };
		inline constexpr REL::ID Offscreen_SetDirectionalLight{ 2222544 };
		inline constexpr REL::ID Enable{ 2222522 };
		inline constexpr REL::ID Disable{ 2222523 };
		inline constexpr REL::ID DisableAll{ 2222521 };
		inline constexpr REL::ID Release{ 2222520 };
		inline constexpr REL::ID SetViewport{ 2222552 };
	}

	namespace Inventory3DManager
	{
		inline constexpr REL::ID Begin3D{ 2249084 };
		inline constexpr REL::ID ClearModel{ 2249113 };
		inline constexpr REL::ID DisableRendering{ 2249099 };
		inline constexpr REL::ID EnableRendering{ 2249098 };
		inline constexpr REL::ID End3D{ 2249086 };
		inline constexpr REL::ID SetModelScale{ 2249097 };
		inline constexpr REL::ID SetModelScreenPosition{ 2249096 };
	}

	namespace InventoryItemDisplayData
	{
		inline constexpr REL::ID ctor{ 2222612 };
	}

	namespace InventoryUserUIUtils
	{
		inline constexpr REL::ID AddItemCardInfoEntry{ 2222648 };
		inline constexpr REL::ID PopulateItemCardInfo_Helper{ 2222625 };
	}

	namespace ItemCrafted
	{
		inline constexpr REL::ID NotifyOfItemCrafted{ 2232809 };
		inline constexpr REL::ID RegisterSink{ 2232807 };
		inline constexpr REL::ID UnregisterSink{ 2232808 };
	}

	namespace LevelIncrease
	{
		inline constexpr REL::ID GetEventSource{ 2233736 };
	}

	namespace LoadingMenu
	{
		inline constexpr REL::ID StartTestingLoadMenu{ 2249224 };
		inline constexpr REL::ID PopulateLoadScreens{ 2249232 };
	}

	namespace LockpickingMenu
	{
		inline constexpr REL::ID OpenLockpickingMenu{ 2249263 };
	}

	namespace LocksPicked
	{
		inline constexpr REL::ID GetEventSource{ 2249292 };
	}

	namespace MagicTarget
	{
		inline constexpr REL::ID IsTakingHealthDamageFromActiveEffect{ 2226397 };
		inline constexpr REL::ID IsTakingRadDamageFromActiveEffect{ 2226398 };
	}

	namespace Main
	{
		inline constexpr REL::ID Singleton{ 2698043 };
		inline constexpr REL::ID WorldRootCamera{ 2228956 };
		inline constexpr REL::ID WorldRootNode{ 2698065 };
		inline constexpr REL::ID QGameSystemsShouldUpdate{ 2698031 };
		inline constexpr REL::ID QGameDataLoaded{ 2698032 };
		inline constexpr REL::ID SetCameraFOV{ 2228973 };
	}

	namespace MemoryManager
	{
		namespace AutoScrapBuffer
		{
			inline constexpr REL::ID ctor{ 2267865 };
			inline constexpr REL::ID dtor{ 2267867 };
		}

		inline constexpr REL::ID Singleton{ 2193197 };
		inline constexpr REL::ID Allocate{ 2267872 };
		inline constexpr REL::ID Deallocate{ 2267874 };
		inline constexpr REL::ID GetThreadScrapHeap{ 2267850 };
		inline constexpr REL::ID Reallocate{ 2267873 };
		inline constexpr REL::ID RegisterMemoryManager{ 2228356 };
	}

	namespace MenuControls
	{
		inline constexpr REL::ID Singleton{ 2689089 };
	}

	namespace MenuCursor
	{
		inline constexpr REL::ID Singleton{ 2696546 };
		inline constexpr REL::ID CenterCursor{ 2287473 };
		inline constexpr REL::ID RegisterCursor{ 2287475 };
		inline constexpr REL::ID SetCursorConstraintsRaw{ 2287480 };
		inline constexpr REL::ID UnregisterCursor{ 2287486 };
		inline constexpr REL::ID PipboyConstraintTLX{ 280077 };
		inline constexpr REL::ID PipboyConstraintTLY{ 938173 };
		inline constexpr REL::ID PipboyConstraintWidth{ 13663 };
		inline constexpr REL::ID PipboyConstraintHeight{ 672503 };
		inline constexpr REL::ID PipboyConstraintTLX_PowerArmor{ 1330184 };
		inline constexpr REL::ID PipboyConstraintTLY_PowerArmor{ 406096 };
		inline constexpr REL::ID PipboyConstraintWidth_PowerArmor{ 1064265 };
		inline constexpr REL::ID PipboyConstraintHeight_PowerArmor{ 140195 };
	}

	namespace MenuTopicManager
	{
		inline constexpr REL::ID Singleton{ 2689089 };
	}

	namespace MessageBoxMenu
	{
		inline constexpr REL::ID ShowMessage{ 2249469 };
	}

	namespace MessageMenuManager
	{
		inline constexpr REL::ID Singleton{ 2689087 };
		inline constexpr REL::ID Create{ 2249456 };
	}

	namespace Moon
	{
		inline constexpr REL::ID Init{ 2208804 };
	}

	namespace NiAlphaProperty
	{
		inline constexpr REL::ID SetDestBlendMode{ 0 };
		inline constexpr REL::ID SetSrcBlendMode{ 0 };
		inline constexpr REL::ID SetTestMode{ 0 };
		inline constexpr REL::ID SetAlphaBlending{ 0 };
		inline constexpr REL::ID SetAlphaTesting{ 0 };
	}

	namespace NiCamera
	{
		inline constexpr REL::ID BoundInFrustum{ 2194525 };
		inline constexpr REL::ID WorldPtToScreenPt3{ 2270344 };
		inline constexpr REL::ID ViewPointToRay{ 2270338 };
	}

	namespace NiControllerManager
	{
		inline constexpr REL::ID GetNiControllerManager{ 2271798 };
		inline constexpr REL::ID GetSequenceByName{ 2192808 };
	}

	namespace NiControllerSequence
	{
		inline constexpr REL::ID Activate{ 2271861 };
	}

	namespace NiMatrix3
	{
		inline constexpr REL::ID ToEulerAnglesXYZ1{ 2269806 };
		inline constexpr REL::ID ToEulerAnglesXZY2{ 2269807 };
		inline constexpr REL::ID ToEulerAnglesYXZ3{ 2269808 };
		inline constexpr REL::ID ToEulerAnglesYZX4{ 2269809 };
		inline constexpr REL::ID ToEulerAnglesZYX5{ 2269810 };
		inline constexpr REL::ID ToEulerAnglesZXY6{ 2269824 };
		inline constexpr REL::ID FromEulerAnglesXYZ1{ 2269813 };
		inline constexpr REL::ID FromEulerAnglesXZY2{ 2269814 };
		inline constexpr REL::ID FromEulerAnglesYXZ3{ 2269815 };
		inline constexpr REL::ID FromEulerAnglesYZX4{ 2269816 };
		inline constexpr REL::ID FromEulerAnglesZYX5{ 2269817 };
		inline constexpr REL::ID FromEulerAnglesZXY6{ 2269825 };
	}

	namespace NiNode
	{
		inline constexpr REL::ID ChildrenVTable{ 390064 };
	}

	namespace NiPoint
	{
		namespace NiPoint3
		{
			inline constexpr REL::ID GetZAngleFromVector{ 2269788 };
		}
	}

	namespace NiRefObject
	{
		inline constexpr REL::ID Objects{ 2703471 };
	}

	namespace NiTexture
	{
		inline constexpr REL::ID SetAllowDegrade{ 2270148 };
	}

	namespace nsStatsMenuUtils
	{
		inline constexpr REL::ID GetEffectDisplayInfo{ 2224586 };
	}

	namespace PerkPointIncreaseEvent
	{
		inline constexpr REL::ID GetEventSource{ 2697359 };
	}

	namespace PerkUtilities
	{
		inline constexpr REL::ID RemoveGrenadeTrajectory{ 2233303 };
	}

	namespace PipboyDataManager
	{
		inline constexpr REL::ID Singleton{ 2689086 };
	}

	namespace PipboyInventoryData
	{
		inline constexpr REL::ID RepopulateItemCardsOnSection{ 2225279 };
		inline constexpr REL::ID PopulateItemCardInfo{ 2225266 };
		inline constexpr REL::ID AddItemCardInfoEntry{ 2225267 };
		inline constexpr REL::ID BaseAddItemCardInfoEntry{ 2225270 };
		inline constexpr REL::ID InitializeItem{ 2225264 };
	}

	namespace PipboyInventoryMenu
	{
		inline constexpr REL::ID UpdateData{ 2224143 };
		inline constexpr REL::ID SetQuickkey{ 2224159 };
	}

	namespace PipboyInventoryUtils
	{
		inline constexpr REL::ID DoSlotsOverlap{ 2225230 };
		inline constexpr REL::ID FillDamageTypeInfo{ 2225234 };
		inline constexpr REL::ID FillResistTypeInfo{ 2225235 };
	}

	namespace PipboyLightEvent
	{
		inline constexpr REL::ID GetEventSource{ 2696280 };
	}

	namespace PipboyLogMenu
	{
		inline constexpr REL::ID UpdateData{ 2224052 };
	}

	namespace PipboyManager
	{
		inline constexpr REL::ID Singleton{ 2691945 };
		inline constexpr REL::ID AddMenuToPipboy{ 2225453 };
		inline constexpr REL::ID ClosedownPipboy{ 2225480 };
		inline constexpr REL::ID EnablePipboyShader{ 2225484 };
		inline constexpr REL::ID InitPipboy{ 2225479 };
		inline constexpr REL::ID LowerPipboy{ 2225454 };
		inline constexpr REL::ID OnPipboyCloseAnim{ 2225457 };
		inline constexpr REL::ID OnPipboyCloseAnimFailed{ 2225459 };
		inline constexpr REL::ID OnPipboyClosed{ 2225458 };
		inline constexpr REL::ID OnPipboyOpenAnim{ 2225448 };
		inline constexpr REL::ID OnPipboyOpenAnimFailed{ 2225449 };
		inline constexpr REL::ID OnPipboyOpened{ 2225450 };
		inline constexpr REL::ID PlayItemAnimOnClose{ 2225461 };
		inline constexpr REL::ID PlayPipboyCloseAnim{ 2225456 };
		inline constexpr REL::ID PlayPipboyGenericOpenAnim{ 2225447 };
		inline constexpr REL::ID PlayPipboyLoadHolotapeAnim{ 2225446 };
		inline constexpr REL::ID PlayPipboyOpenAnim{ 2225444 };
		inline constexpr REL::ID PlayPipboyOpenTerminalAnim{ 2225445 };
		inline constexpr REL::ID ProcessLoweringReason{ 2225486 };
		inline constexpr REL::ID QPipboyActive{ 2225460 };
		inline constexpr REL::ID RaisePipboy{ 2225455 };
		inline constexpr REL::ID RefreshPipboyRenderSurface{ 2225478 };
		inline constexpr REL::ID StartAnimationGraphListening{ 2225490 };
		inline constexpr REL::ID StopAnimationGraphListening{ 2225491 };
		inline constexpr REL::ID UpdateCursorConstraint{ 2225488 };
	}

	namespace PipboyMapMenu
	{
		inline constexpr REL::ID UpdateData{ 2224074 };
	}

	namespace PipboyMenu
	{
		inline constexpr REL::ID RefreshMapMarkers{ 2224187 };
	}

	namespace PipboyObject
	{
		inline constexpr REL::ID AddMember{ 2225699 };
	}

	namespace PipboyPerksMenu
	{
		inline constexpr REL::ID UpdateData{ 2224224 };
	}

	namespace PipboyPlayerInfoMenu
	{
		inline constexpr REL::ID UpdateData{ 2224248 };
	}

	namespace PipboyPrimitiveValue
	{
		namespace uint32
		{
			inline constexpr REL::ID ctor{ 2225324 };
		}

		namespace boolean
		{
			inline constexpr REL::ID ctor{ 2225327 };
		}
	}

	namespace PipboyQuestMenu
	{
		inline constexpr REL::ID UpdateData{ 2224231 };
	}

	namespace PipboyRadioMenu
	{
		inline constexpr REL::ID UpdateData{ 2224242 };
	}

	namespace PipboySpecialMenu
	{
		inline constexpr REL::ID UpdateData{ 2224256 };
	}

	namespace PipboyStatsMenu
	{
		inline constexpr REL::ID UpdateData{ 2224261 };
		inline constexpr REL::ID UpdateActiveEffects{ 2224262 };
	}

	namespace PipboySubMenu
	{
		inline constexpr REL::ID ProcessEvent{ 2224270 };
	}

	namespace PipboyValue
	{
		inline constexpr REL::ID ctor{ 2225915 };
	}

	namespace PipboyWorkshopMenu
	{
		inline constexpr REL::ID UpdateData{ 2224273 };
	}

	namespace PlayerCamera
	{
		inline constexpr REL::ID Singleton{ 2688801 };
		inline constexpr REL::ID PopState{ 2248424 };
		inline constexpr REL::ID PushState{ 2248422 };
		inline constexpr REL::ID ToggleFreeCameraMode{ 2248368 };
		inline constexpr REL::ID SetState{ 2214742 };
		inline constexpr REL::ID StartFurnitureMode{ 2248373 };
		inline constexpr REL::ID StartPipboyMode{ 2248358 };
		inline constexpr REL::ID StopPipboyMode{ 2248359 };
		inline constexpr REL::ID QCameraEquals{ 2248421 };
	}

	namespace PlayerCharacter
	{
		namespace ScopedInventoryChangeMessageContext
		{
			inline constexpr REL::ID ctor{ 2233292 };
			inline constexpr REL::ID dtor{ 2233293 };
		}

		inline constexpr REL::ID Singleton{ 2690919 };
		inline constexpr REL::ID GetPlayerHandle{ 2698072 };
		inline constexpr REL::ID GetDifficultyLevel{ 2233056 };
		inline constexpr REL::ID IsGodMode{ 2232986 };
		inline constexpr REL::ID IsHolotapePlaying{ 2233206 };
		inline constexpr REL::ID IsImmortal{ 2232988 };
		inline constexpr REL::ID IsPipboyLightOn{ 2233202 };
		inline constexpr REL::ID PauseHolotape{ 2233208 };
		inline constexpr REL::ID PlayHolotape{ 2233207 };
		inline constexpr REL::ID QueueFastTravel{ 2232918 };
		inline constexpr REL::ID RemoveLastUsedPowerArmor{ 2233024 };
		inline constexpr REL::ID SelectPerk{ 2232926 };
		inline constexpr REL::ID SetAIControlledPackage{ 2233087 };
		inline constexpr REL::ID SetEscaping{ 2233142 };
		inline constexpr REL::ID SetVATSCriticalCount{ 2233219 };
		inline constexpr REL::ID ShowPipboyLight{ 2233203 };
		inline constexpr REL::ID SetLastDialogueInput{ 2233190 };
		inline constexpr REL::ID ClearPrison{ 2233196 };
		inline constexpr REL::ID ReloadWeapon{ 2232907 };
		inline constexpr REL::ID SetPerkCount{ 2233187 };
		inline constexpr REL::ID HasLOSToTarget{ 2233004 };
		inline constexpr REL::ID TryUnlockObject{ 2233040 };
	}

	namespace PlayerControls
	{
		inline constexpr REL::ID Singleton{ 2692013 };
		inline constexpr REL::ID DoAction{ 2234796 };
		inline constexpr REL::ID DoRegisterHandler{ 2234822 };
	}

	namespace PlayerCrosshairModeEvent
	{
		inline constexpr REL::ID GetEventSource{ 2694517 };
	}

	namespace PowerArmor
	{
		inline constexpr REL::ID ActorInPowerArmor{ 2219437 };
		inline constexpr REL::ID GetArmorKeyword{ 2194743 };
		inline constexpr REL::ID GetBatteryKeyword{ 2194740 };
		inline constexpr REL::ID GetDefaultBatteryObject{ 2194761 };
		inline constexpr REL::ID IsPowerArmorBattery{ 2219422 };
		inline constexpr REL::ID SyncFurnitureVisualsToInventory{ 2219453 };
		inline constexpr REL::ID fNewBatteryCapacity{ 1353498 };
	}

	namespace PowerArmorGeometry
	{
		inline constexpr REL::ID Singleton{ 2694441 };
		inline constexpr REL::ID HidePipboyPAGeometry{ 2248877 };
		inline constexpr REL::ID ShowPipboyPAGeometry{ 2248876 };
	}

	namespace PowerArmorLightData
	{
		inline constexpr REL::ID GetEventSource{ 2701547 };
	}

	namespace PowerArmorModMenu
	{
		inline constexpr REL::ID ShowBuildFailureMessage{ 2224322 };
	}

	namespace ProcessLists
	{
		inline constexpr REL::ID Singleton{ 2688869 };
		inline constexpr REL::ID AreHostileActorsNear{ 2234105 };
		inline constexpr REL::ID IsActorTargetingREFinPackage{ 2234033 };
		inline constexpr REL::ID RequestHighestDetectionLevelAgainstActor{ 2234111 };
	}

	namespace REFR_LOCK
	{
		inline constexpr REL::ID GetLockLevel{ 2191018 };
		inline constexpr REL::ID SetLocked{ 2191020 };
		inline constexpr REL::ID IsBroken{ 2191021 };
	}

	namespace SavefileMetadata
	{
		inline constexpr REL::ID FillDataFromFileName{ 2228156 };
	}

	namespace ScrapHeap
	{
		inline constexpr REL::ID Allocate{ 2267983 };
		inline constexpr REL::ID Deallocate{ 2267984 };
	}

	namespace SCRIPT_FUNCTION
	{
		inline constexpr REL::ID ConsoleFunctions{ 901511 };
		inline constexpr REL::ID ScriptFunctions{ 75173 };
		inline constexpr REL::ID CompileFunction{ 2204343 };
	}

	namespace Script
	{
		inline constexpr REL::ID ParseParameters{ 2204298 };
		inline constexpr REL::ID CompileAndRun{ 2204287 };
		inline constexpr REL::ID GetProcessScripts{ 2204310 };
		inline constexpr REL::ID SetProcessScripts{ 2204309 };
	}

	namespace SendHUDMessage
	{
		inline constexpr REL::ID PopHUDMode{ 2222444 };
		inline constexpr REL::ID PushHUDMode{ 2222443 };
		inline constexpr REL::ID SetPowerArmorMode{ 2222459 };
		inline constexpr REL::ID ShowHUDMessage{ 2222440 };
	}

	namespace Setting
	{
		namespace INISettingCollection
		{
			inline constexpr REL::ID Singleton{ 2704108 };
		}

		namespace INIPrefSettingCollection
		{
			inline constexpr REL::ID Singleton{ 2703234 };
		}

		namespace GameSettingCollection
		{
			inline constexpr REL::ID Singleton{ 2690301 };
			inline constexpr REL::ID InitCollection{ 2188690 };
		}
	}

	namespace SitWaitMenu
	{
		inline constexpr REL::ID OnEnterFurniture{ 2249503 };
		inline constexpr REL::ID OnExitFurniture{ 2249504 };
	}

	namespace Sky
	{
		inline constexpr REL::ID Singleton{ 2192448 };
		inline constexpr REL::ID ForceWeather{ 2208861 };
		inline constexpr REL::ID ResetWeather{ 2208860 };
	}

	namespace SplineUtils
	{
		inline constexpr REL::ID DisconnectSpline{ 2195074 };
		inline constexpr REL::ID ConnectSpline{ 2195073 };
	}

	namespace SubtitleManager
	{
		inline constexpr REL::ID Singleton{ 2689088 };
		inline constexpr REL::ID RWLock{ 2701704 };
	}

	namespace SWFToCodeFunctionHandler
	{
		inline constexpr REL::ID MapCodeMethodToASFunction{ 2287419 };
		inline constexpr REL::ID RegisterCodeObject{ 2287415 };
	}

	namespace TaskQueueInterface
	{
		inline constexpr REL::ID Singleton{ 2698331 };
		inline constexpr REL::ID QueueClosePipboy{ 2229289 };
		inline constexpr REL::ID QueueRebuildBendableSpline{ 2229302 };
		inline constexpr REL::ID QueueShow1stPerson{ 2229268 };
		inline constexpr REL::ID QueueShowPipboy{ 2229288 };
		inline constexpr REL::ID QueueUpdate3D{ 2229234 };
		inline constexpr REL::ID QueueWeaponFire{ 2229186 };
	}

	namespace TerminalHacked
	{
		inline constexpr REL::ID GetEventSource{ 2233751 };
	}

	namespace TES
	{
		inline constexpr REL::ID Singleton{ 2698044 };
	}

	namespace TESActivateEvent
	{
		inline constexpr REL::ID GetEventSource{ 2201819 };
	}

	namespace TESActorBaseData
	{
		inline constexpr REL::ID GetLevel{ 2192891 };
	}

	namespace TESAmmo
	{
		inline constexpr REL::ID GetReloadsWithAmmoRef{ 2197864 };
	}

	namespace TESAudio
	{
		namespace ScriptedMusicState
		{
			inline constexpr REL::ID Singleton{ 2691985 };
			inline constexpr REL::ID Remove{ 2226976 };
		}
	}

	namespace TESBoundObject
	{
		inline constexpr REL::ID ApplyMods{ 2198325 };
	}

	namespace TESCellAttachDetachEvent
	{
		inline constexpr REL::ID GetEventSource{ 2201823 };
	}

	namespace TESCellFullyLoadedEvent
	{
		inline constexpr REL::ID GetEventSource{ 2201824 };
	}

	namespace TESCondition
	{
		inline constexpr REL::ID IsTrue{ 2211989 };
		inline constexpr REL::ID IsTrueForAllButFunction{ 0 };  // 1182457 - inlined
		inline constexpr REL::ID ClearAllConditionItems{ 2211988 };
	}

	namespace TESConditionItem
	{
		inline constexpr REL::ID GetComparisonValue{ 2212007 };
		inline constexpr REL::ID IsTrue1{ 2212008 };
		inline constexpr REL::ID IsTrue2{ 2212009 };
	}

	namespace TESContainerChangedEvent
	{
		inline constexpr REL::ID GetEventSource{ 2201832 };
	}

	namespace TESDataHandler
	{
		inline constexpr REL::ID Singleton{ 2688883 };
		inline constexpr REL::ID AddFormToDataHandler{ 2192271 };
		inline constexpr REL::ID CheckModsLoaded{ 2192323 };
		inline constexpr REL::ID CreateReferenceAtLocation{ 2192301 };
		inline constexpr REL::ID IsFormIDInuse{ 2192351 };
	}

	namespace TESDeathEvent
	{
		inline constexpr REL::ID GetEventSource{ 2201833 };
	}

	namespace TESDescription
	{
		inline constexpr REL::ID GetDescription{ 2193019 };
	}

	namespace TESEnterSneakingEvent
	{
		inline constexpr REL::ID GetEventSource{ 2201837 };
	}

	namespace TESFile
	{
		inline constexpr REL::ID CloseTES{ 2192491 };
		inline constexpr REL::ID GetChunkData{ 2192538 };
		inline constexpr REL::ID GetTESChunk{ 2192536 };
		inline constexpr REL::ID NextChunk{ 2192537 };
		inline constexpr REL::ID NextForm{ 2192527 };
		inline constexpr REL::ID NextGroup{ 2192522 };
		inline constexpr REL::ID OpenTES{ 2192490 };
	}

	namespace TESForm
	{
		inline constexpr REL::ID FormSortFunc{ 0 };  // 705530 - inlined?
		inline constexpr REL::ID AddCompileIndex{ 2193152 };
		inline constexpr REL::ID AllForms{ 2689178 };
		inline constexpr REL::ID AllFormsMapLock{ 2689189 };
		inline constexpr REL::ID AllFormsByEditorID{ 2689179 };
		inline constexpr REL::ID AllFormsEditorIDMapLock{ 2689190 };
		inline constexpr REL::ID GetFile{ 2193103 };
		inline constexpr REL::ID GetFormByNumericID{ 2193092 };
		inline constexpr REL::ID GetFormEnumString{ 1529598 };
		inline constexpr REL::ID GetFormTypeFromString{ 2193108 };
		inline constexpr REL::ID SetTemporary{ 2193125 };
	}

	namespace TESFormDeleteEvent
	{
		inline constexpr REL::ID GetEventSource{ 2201842 };
	}

	namespace TESFullName
	{
		inline constexpr REL::ID SparseFullNameMap{ 2661402 };
	}

	namespace TESFurniture
	{
		inline constexpr REL::ID GetContainer{ 2198043 };
	}

	namespace TESFurnitureEvent
	{
		inline constexpr REL::ID GetEventSource{ 2201844 };
	}

	namespace TESHarvestEvent
	{
		inline constexpr REL::ID GetEventSource{ 2193351 };
	}

	namespace TESHealthForm
	{
		inline constexpr REL::ID GetFormHealth{ 2193227 };
	}

	namespace TESHitEvent
	{
		inline constexpr REL::ID GetEventSource{ 2201886 };
	}

	namespace TESInitScriptEvent
	{
		inline constexpr REL::ID GetEventSource{ 2201846 };
	}

	namespace TESLeveledList
	{
		inline constexpr REL::ID AddLeveledObject{ 2193258 };
		inline constexpr REL::ID AddScriptAddedLeveledObject{ 2193269 };
		inline constexpr REL::ID CalculateCurrentFormList{ 2193259 };
		inline constexpr REL::ID CalculateCurrentFormListForRef{ 2193260 };
		inline constexpr REL::ID GetUseAll{ 2193253 };
	}

	namespace TESLoadGameEvent
	{
		inline constexpr REL::ID GetEventSource{ 2201848 };
	}

	namespace TESMagicEffectApplyEvent
	{
		inline constexpr REL::ID GetEventSource{ 2201851 };
	}

	namespace TESNPC
	{
		inline constexpr REL::ID AlternateHeadPartListMap{ 2662368 };
		inline constexpr REL::ID GetSex{ 2207107 };
		inline constexpr REL::ID GetFacialBoneMorphIntensity{ 2207416 };
		inline constexpr REL::ID SetHairColor{ 2207426 };
		inline constexpr REL::ID GetShortName{ 2207405 };
	}

	namespace TESObjectARMO
	{
		inline constexpr REL::ID Protects{ 2198535 };
	}

	namespace TESObjectCELL
	{
		inline constexpr REL::ID GetbhkWorld{ 2200260 };
		inline constexpr REL::ID GetCantWaitHere{ 2200287 };
		inline constexpr REL::ID GetDataX{ 2200213 };
		inline constexpr REL::ID GetDataY{ 2200214 };
		inline constexpr REL::ID GetEncounterZone{ 2200242 };
		inline constexpr REL::ID GetLocation{ 2200179 };
		inline constexpr REL::ID GetOwner{ 2200236 };
		inline constexpr REL::ID GetRegionList{ 2200265 };
		inline constexpr REL::ID Pick{ 2200263 };
		inline constexpr REL::ID SetCullCellMarkers{ 2192259 };
		inline constexpr REL::ID UpdateAllRefsLoaded{ 2200415 };
		inline constexpr REL::ID AttatchReference3D{ 2200620 };
		inline constexpr REL::ID RemoveReference{ 2200299 };
		inline constexpr REL::ID UpdateAllDecals{ 2200643 };
		inline constexpr REL::ID DefaultWater{ 2691845 };
	}

	namespace TESObjectLoadedEvent
	{
		inline constexpr REL::ID GetEventSource{ 2201853 };
	}

	namespace TESObjectREFR
	{
		inline constexpr REL::ID ActivateRef{ 2201147 };
		inline constexpr REL::ID AddInventoryItem{ 2200949 };
		inline constexpr REL::ID AddKeyword{ 2200860 };
		inline constexpr REL::ID AddLockChange{ 2200731 };
		inline constexpr REL::ID ApplyArtObject{ 2205200 };
		inline constexpr REL::ID ApplyEffectShader{ 2205201 };
		inline constexpr REL::ID Enable{ 2201150 };
		inline constexpr REL::ID FindReferenceFor3D{ 2201082 };
		inline constexpr REL::ID GetCurrentLocation{ 2201163 };
		inline constexpr REL::ID GetDisplayFullName{ 2201126 };
		inline constexpr REL::ID GetEditorDead{ 2200781 };
		inline constexpr REL::ID GetOwner{ 2202616 };
		inline constexpr REL::ID GetGoldAmount{ 2200923 };
		inline constexpr REL::ID GetHandle{ 2201196 };
		inline constexpr REL::ID GetHasOwner{ 2202622 };
		inline constexpr REL::ID GetInventoryObjectCount{ 2200939 };
		inline constexpr REL::ID GetLinkedRef{ 2202683 };
		inline constexpr REL::ID GetLock{ 2202648 };
		inline constexpr REL::ID GetWeightInContainer{ 2201001 };
		inline constexpr REL::ID HasContainer{ 2201022 };
		inline constexpr REL::ID IsAnOwner{ 2202635 };
		inline constexpr REL::ID IsCrimeToActivate{ 2201180 };
		inline constexpr REL::ID IsLeveledCreature{ 2202655 };
		inline constexpr REL::ID MarkAsDeleted{ 2201156 };
		inline constexpr REL::ID MoveRefToNewSpace{ 2201149 };
		inline constexpr REL::ID RemoveKeyword{ 2200861 };
		inline constexpr REL::ID SetAngleOnReference{ 2201134 };
		inline constexpr REL::ID SetLinkedRef{ 2202684 };
		inline constexpr REL::ID SetLocationOnReference{ 2201138 };
		inline constexpr REL::ID SetWantsDelete{ 2201199 };
		inline constexpr REL::ID RebuildBendableSpline{ 2201119 };
		inline constexpr REL::ID GetItemCount{ 2200996 };
		inline constexpr REL::ID UpdateReference3D{ 2201071 };
		inline constexpr REL::ID GetObjectCenter{ 2201092 };
		inline constexpr REL::ID SetScale{ 2200893 };
		inline constexpr REL::ID IsMarker{ 2201157 };
		inline constexpr REL::ID IsDecalRef{ 2200794 };
		inline constexpr REL::ID UpdateDynamicNavmesh{ 2201206 };
		inline constexpr REL::ID GetMapMarkerData{ 2202644 };
		inline constexpr REL::ID GetRelevantWaterHeight{ 2201189 };
	}

	namespace TESObjectWEAP
	{
		inline constexpr REL::ID GetMeleeAttackSpeed{ 2198957 };
		inline constexpr REL::ID GetMeleeAttackSpeedLabel{ 2198959 };
		inline constexpr REL::ID Fire{ 2198960 };
	}

	namespace TESQuest
	{
		inline constexpr REL::ID SetStage{ 2207743 };
		inline constexpr REL::ID GetAliasedRef{ 2207810 };
	}

	namespace TESResponse
	{
		inline constexpr REL::ID GetResponseText{ 2208288 };
		inline constexpr REL::ID GetSpeakerIdle{ 2208293 };
	}

	namespace TESSpellList
	{
		inline constexpr REL::ID AddSpell{ 2193395 };
	}

	namespace TESSwitchRaceCompleteEvent
	{
		inline constexpr REL::ID GetEventSource{ 2201874 };
	}

	namespace TESTopicInfo
	{
		inline constexpr REL::ID GetParentInfoGroup{ 2208435 };
		inline constexpr REL::ID GetChallengeLevel{ 2208441 };
		inline constexpr REL::ID GetSuccessLevel{ 2208444 };
		inline constexpr REL::ID StartSceneOnEnd{ 2208466 };
		inline constexpr REL::ID GetScene{ 2208453 };
		inline constexpr REL::ID StartScene{ 2208469 };
		inline constexpr REL::ID GetSpeaker{ 2208449 };
	}

	namespace TESValueForm
	{
		inline constexpr REL::ID GetFormValue{ 2193435 };
	}

	namespace TESWaterDisplacement
	{
		inline constexpr REL::ID SetStencilBit{ 2213923 };
	}

	namespace TESWeightForm
	{
		inline constexpr REL::ID GetFormWeight{ 2193446 };
	}

	namespace TESWorldSpace
	{
		inline constexpr REL::ID DefaultWater{ 2691845 };
		inline constexpr REL::ID GetSkyCell{ 2202924 };
	}

	namespace UI
	{
		inline constexpr REL::ID Singleton{ 2689028 };
		inline constexpr REL::ID CustomRendererHasQuads{ 2284757 };
		inline constexpr REL::ID GetMenuMapRWLock{ 2707105 };
		inline constexpr REL::ID RefreshCursor{ 2284772 };
		inline constexpr REL::ID RegisterMenu{ 2284766 };
		inline constexpr REL::ID UpdateControllerType{ 2284768 };
	}

	namespace UIAdvanceMenusFunctionCompleteEvent
	{
		inline constexpr REL::ID GetEventSource{ 2694428 };
	}

	namespace UIMessageQueue
	{
		inline constexpr REL::ID Singleton{ 2689091 };
		inline constexpr REL::ID AddMessage{ 2284929 };
	}

	namespace UIUtils
	{
		inline constexpr REL::ID GetComparisonItems{ 0 };  // 593818 - inlined?
		inline constexpr REL::ID PlayPipboySound{ 2249706 };
		inline constexpr REL::ID PlayMenuSound{ 2249707 };
		inline constexpr REL::ID UpdateGamepadDependentButtonCodes{ 2249714 };
		inline constexpr REL::ID ShowCraftingMenu{ 2249718 };
		inline constexpr REL::ID HasRequiredInventoryForCraftingMenu{ 2249717 };
	}

	namespace VATS
	{
		inline constexpr REL::ID Singleton{ 2690444 };
		inline constexpr REL::ID CanActivateCriticals{ 2237208 };
	}

	namespace WorkbenchMenuBase
	{
		inline constexpr REL::ID UpdateOptimizedAutoBuildInv{ 2224955 };
		inline constexpr REL::ID QCurrentModChoiceData{ 2224958 };
		inline constexpr REL::ID ShowBuildFailureMessage{ 2224959 };
	}

	namespace Workshop
	{
		namespace PlacementItemData
		{
			inline constexpr REL::ID Set{ 2195643 };
		}

		namespace WorkshopMenuNode
		{
			inline constexpr REL::ID FindAndSetSelectedNode{ 2195022 };
		}

		inline constexpr REL::ID FindNearestValidWorkshop{ 2194970 };
		inline constexpr REL::ID FreeBuild{ 2194924 };
		inline constexpr REL::ID GetSelectedWorkshopMenuNode{ 2195024 };
		inline constexpr REL::ID InitializePlacementReference{ 0 };  // 1577199 - inlined
		inline constexpr REL::ID IsLocationWithinBuildableArea{ 2194956 };
		inline constexpr REL::ID PlaceCurrentReference{ 2195155 };
		inline constexpr REL::ID RegisterForItemDestroyed{ 2194930 };
		inline constexpr REL::ID RegisterForItemMoved{ 2194932 };
		inline constexpr REL::ID RegisterForItemPlaced{ 2194926 };
		inline constexpr REL::ID RegisterForWorkshopModeEvent{ 2194946 };
		inline constexpr REL::ID RequestExitWorkshop{ 2195135 };
		inline constexpr REL::ID ScrapReference{ 2195125 };
		inline constexpr REL::ID SetSelectedEditItem{ 2195119 };
		inline constexpr REL::ID StartWorkshop{ 2195134 };
		inline constexpr REL::ID ToggleEditMode{ 2195130 };
		inline constexpr REL::ID UnregisterForItemDestroyed{ 2194931 };
		inline constexpr REL::ID UnregisterForItemMoved{ 2194933 };
		inline constexpr REL::ID UnregisterForItemPlaced{ 2194927 };
		inline constexpr REL::ID UnregisterForWorkshopModeEvent{ 2194947 };
		inline constexpr REL::ID UpdateActiveEdit{ 2195210 };
		inline constexpr REL::ID WorkshopCanShowRecipe{ 2195115 };
		inline constexpr REL::ID CurrentPlacementItemData{ 2689973 };
		inline constexpr REL::ID CurrentRow{ 2689868 };
		inline constexpr REL::ID PlacementItem{ 2689906 };
	}

	namespace WorkshopMenu
	{
		inline constexpr REL::ID CheckAndSetItemForPlacement{ 2224991 };
		inline constexpr REL::ID UpdateButtonText{ 2224992 };
	}

	inline constexpr REL::ID NiFree{ 2268539 };
	inline constexpr REL::ID NiMalloc{ 2268535 };
	inline constexpr REL::ID RTDynamicCast{ 2725673 };
	inline constexpr REL::ID IsPlayerInDialogue{ 2188686 };
}

namespace Scaleform::ID
{
	namespace GFx::ASStringManager
	{
		inline constexpr REL::ID CreateStringNode{ 2290014 };
	}

	namespace GFx::Loader
	{
		inline constexpr REL::ID CreateMovie{ 2284723 };
	}

	namespace GFx::Movie
	{
		inline constexpr REL::ID Release{ 2287230 };
	}

	namespace GFx::Value
	{
		inline constexpr REL::ID ObjectAddRef{ 2286228 };
		inline constexpr REL::ID ObjectRelease{ 2286229 };
		inline constexpr REL::ID HasMember{ 2286078 };
		inline constexpr REL::ID GetArraySize{ 2285791 };
		inline constexpr REL::ID GetMember{ 2285936 };
		inline constexpr REL::ID GetElement{ 2285881 };
		inline constexpr REL::ID SetElement{ 2286575 };
		inline constexpr REL::ID SetMember{ 2286589 };
		inline constexpr REL::ID Invoke{ 2286101 };
		inline constexpr REL::ID PushBack{ 2286424 };
		inline constexpr REL::ID RemoveElements{ 2286475 };
		inline constexpr REL::ID VisitMembers{ 2286786 };
		inline constexpr REL::ID GetDisplayInfo{ 2285873 };
	}

	namespace Memory
	{
		inline constexpr REL::ID SetGlobalHeap{ 2707353 };
		inline constexpr REL::ID GetGlobalHeap{ 2707353 };
	}

	namespace SysAlloc
	{
		inline constexpr REL::ID InitHeapEngine{ 2284532 };
		inline constexpr REL::ID ShutdownHeapEngine{ 2284536 };
	}
}
