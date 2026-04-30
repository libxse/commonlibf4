#pragma once

namespace RE::ID
{
	namespace ActiveEffect
	{
		inline constexpr REL::ID CheckDisplacementSpellOnTarget{ 1415178, 0 };  // Inlined in NG/AE
	}

	namespace Actor
	{
		inline constexpr REL::ID AddPerk{ 187096, 2230121 };
		inline constexpr REL::ID CanUseIdle{ 1223707, 2229592 };
		inline constexpr REL::ID ClearAttackStates{ 1525555, 2229773 };
		inline constexpr REL::ID EndInterruptPackage{ 575188, 2229892 };
		inline constexpr REL::ID ExitCover{ 770035, 2231166 };
		inline constexpr REL::ID GetAimVector{ 554863, 2230378 };
		inline constexpr REL::ID GetClosestBone{ 1180004, 2230051 };
		inline constexpr REL::ID GetCollisionFilter{ 1474995, 2277949 };
		inline constexpr REL::ID GetCombatStyle{ 1270929, 2231053 };
		inline constexpr REL::ID SetCurrentAmmoCount{ 725546, 2229952 };
		inline constexpr REL::ID GetCurrentCollisionGroup{ 410500, 2229993 };
		inline constexpr REL::ID GetCurrentFireLocation{ 663107, 2231167 };
		inline constexpr REL::ID GetDesiredSpeed{ 106892, 2230410 };
		inline constexpr REL::ID GetGhost{ 1298473, 2229668 };
		inline constexpr REL::ID GetHostileToActor{ 1148686, 2229968 };
		inline constexpr REL::ID GetMountHandle{ 313362, 2231230 };
		inline constexpr REL::ID GetLevel{ 661617, 2229734 };
		inline constexpr REL::ID GetPerkRank{ 1368313, 2230125 };
		inline constexpr REL::ID GetSex{ 1216256, 2229674 }; // Check
		inline constexpr REL::ID HandleDefaultAnimationSwitch{ 1163130, 2229780 };
		inline constexpr REL::ID HandleItemEquip{ 164912, 2229781 };
		inline constexpr REL::ID HasObjects{ 861256, 2229961 };
		inline constexpr REL::ID InitiateDoNothingPackage{ 89993, 2229807 };
		inline constexpr REL::ID IsCrippled{ 1238666, 2230998 };
		inline constexpr REL::ID IsFollowing{ 629579, 2230013 };
		inline constexpr REL::ID IsJumping{ 1041558, 2229640 };
		inline constexpr REL::ID IsPathValid{ 1522194, 2230279 };
		inline constexpr REL::ID IsPathing{ 989661, 2234312 };
		inline constexpr REL::ID IsPathingComplete{ 817283, 2230274 };
		inline constexpr REL::ID IsQuadruped{ 1552322, 2229614 };
		inline constexpr REL::ID IsSneaking{ 1173627, 2207655 };
		inline constexpr REL::ID Move{ 737625, 2229934 };
		inline constexpr REL::ID PerformAction{ 1057231, 2231177 };
		inline constexpr REL::ID RemovePerk{ 1316475, 2230122 };
		inline constexpr REL::ID Reset3D{ 302888, 2229913 };
		inline constexpr REL::ID RewardExperience{ 262786, 2230428 };
		inline constexpr REL::ID SetGunState{ 977675, 2231175 };
		inline constexpr REL::ID SetHeading{ 353571, 2229625 };
		inline constexpr REL::ID TrespassAlarm{ 1109888, 2229834 };
		inline constexpr REL::ID UpdateVoiceTimer{ 1160883, 2230178 };
		inline constexpr REL::ID GetBodyPartData{ 1485196, 2229571 };
		inline constexpr REL::ID GetEquippedItem{ 1318331, 2231089 };
		inline constexpr REL::ID GetCrimeTrackingFaction{ 1108024, 2229787 };
		inline constexpr REL::ID ForceDetect{ 131995, 2230194 };
		inline constexpr REL::ID GetDesirability{ 1325769, 2229946 }; // Check
		inline constexpr REL::ID CalcArmorRating1{ 843406, 2230008 }; // Check
		inline constexpr REL::ID CalcArmorRating2{ 843406, 2230009 }; // Check
		inline constexpr REL::ID UnequipObject{ 1363509, 2230479 };
		inline constexpr REL::ID UpdateSoundCallBack{ 632367, 2229974 }; // Check
		inline constexpr REL::ID GetFactionRank{ 761698, 2230100 }; // Check
		inline constexpr REL::ID IsAngryWithPlayer{ 1433187, 2229998 }; // Check
		inline constexpr REL::ID RedressIfNeeded{ 323782, 2230394 }; // Check
		inline constexpr REL::ID UpdateSprinting{ 385539, 2230498 };
		inline constexpr REL::ID Jump{ 1394576, 2229650 };
		inline constexpr REL::ID GetMobilityCrippled{ 281477, 2230996 };
		inline constexpr REL::ID SPECIALModifiedCallback{ 234305, 2231020 };
		inline constexpr REL::ID StopInteractingQuick{ 129904, 2231227 };
	}

	namespace ActorEquipManager
	{
		inline constexpr REL::ID Singleton{ 1174340, 2690994, 4798287 };
		inline constexpr REL::ID EquipObject{ 988029, 2231392 };
		inline constexpr REL::ID UnequipObject{ 1292493, 2231395 };
		inline constexpr REL::ID UnequipItem{ 1316852, 2231399 };
	}

	namespace ActorUtils
	{
		namespace ArmorRatingVisitorBase
		{
			inline constexpr REL::ID _operator{ 1119011, 2227206 };
			inline constexpr REL::ID ctor{ 1212617, 2227205 };
		}

		inline constexpr REL::ID GetEquippedArmorDamageResistance{ 1204866, 2227189 };
	}

	namespace ActorValue
	{
		inline constexpr REL::ID Singleton{ 405390, 2189587 };
	}

	namespace AIFormulas
	{
		inline constexpr REL::ID GetBarterValue{ 984344, 2208969 };
	}

	namespace AIProcess
	{
		inline constexpr REL::ID GetCurrentAmmo{ 1154936, 2232300 };
		inline constexpr REL::ID GetCommandType{ 678523, 2231825 };
		inline constexpr REL::ID GetOccupiedFurniture{ 1162965, 2232401 };
		inline constexpr REL::ID IsWeaponSubgraphFinishedLoading{ 320183, 2231757 };
		inline constexpr REL::ID KnockExplosion{ 533106, 2232384 };
		inline constexpr REL::ID ProcessGreet{ 1174935, 2231808 };
		inline constexpr REL::ID RequestLoadAnimationsForWeaponChange{ 666002, 2231758 };
		inline constexpr REL::ID SetActorsDetectionEvent{ 1376336, 2231738 };
		inline constexpr REL::ID SetCurrentAmmo{ 795983, 2232302 };
		inline constexpr REL::ID SetCommandType{ 1555789, 2231826 };
		inline constexpr REL::ID SetEquippedItem{ 1200276, 2231627 };
		inline constexpr REL::ID SetupSpecialIdle{ 1446774, 2231704 };
		inline constexpr REL::ID SetWeaponBonesCulled{ 397172, 2232535 };
		inline constexpr REL::ID StopCurrentIdle{ 434460, 2231705 };
		inline constexpr REL::ID SetRunOncePackage{ 155445, 2232344 };
		inline constexpr REL::ID AddToProcedureIndexRunning{ 134486, 2718412 };
		inline constexpr REL::ID ComputeLastTimeProcessed{ 941571, 2231541 };
	}

	namespace AITimer
	{
		inline constexpr REL::ID fTimer{ 936770, 2698609 };
	}

	namespace AnimationSystemUtils
	{
		inline constexpr REL::ID WillEventChangeState{ 35074, 2214271 };
	}

	namespace ApplyChangesFunctor
	{
		inline constexpr REL::ID WriteDataImpl{ 1291190, 2223194 };
	}

	namespace ApplyColorUpdateEvent
	{
		inline constexpr REL::ID GetEventSource{ 421543, 2707340 };
	}

	namespace BarterMenu
	{
		inline constexpr REL::ID ClearTradingData{ 1112285, 2222700 };
		inline constexpr REL::ID CompleteTrade{ 379932, 2222701 };
		inline constexpr REL::ID GetCapsOwedByPlayer{ 672405, 2222714 };
	}

	namespace BGSAnimationSystemUtils
	{
		inline constexpr REL::ID GetActiveSyncInfo{ 1349978, 2214289 };
		inline constexpr REL::ID InitializeActorInstant{ 672857, 2236393 };
		inline constexpr REL::ID IsActiveGraphInTransition{ 839650, 2214305 };
	}

	namespace BGSAttachParentArray
	{
		inline constexpr REL::ID SetParentGroupNumber{ 1412266, 2189125 };
	}

	namespace BGSConstructibleObject
	{
		inline constexpr REL::ID PlayerPassesConditions{ 293575, 2197318 }; // Check
	}

	namespace BGSCraftItemEvent
	{
		inline constexpr REL::ID EventIndex{ 1382765, 2663409 };
	}

	namespace BGSCreatedObjectManager
	{
		inline constexpr REL::ID Singleton{ 1000678, 2689006, 2697789 };
		inline constexpr REL::ID DecrementRef{ 230928, 2228455 };
		inline constexpr REL::ID IncrementRef{ 1042515, 2228454 };
	}

	namespace BGSDefaultObject
	{
		inline constexpr REL::ID Singleton{ 561749, 2690473, 4797762 };
		inline constexpr REL::ID ctor{ 1144014, 2197003 };
	}

	namespace BGSDefaultObjectManager
	{
		inline constexpr REL::ID Singleton{ 484974, 2192850 };
	}

	namespace BGSDynamicPersistenceManager
	{
		inline constexpr REL::ID Singleton{ 109630, 2689026, 4796312 };
		inline constexpr REL::ID PromoteReference{ 1300345, 2193819 };
		inline constexpr REL::ID DemoteReference{ 222813, 2193820 };
	}

	namespace BGSEntryPoint
	{
		inline constexpr REL::ID HandleEntryPoint{ 714336, 2206243 };
	}

	namespace BGSHackTerminal
	{
		inline constexpr REL::ID EventIndex{ 1186942, 2663434 };
	}

	namespace BGSInventoryInterface
	{
		inline constexpr REL::ID Singleton{ 501899, 2689299, 4796586 };
		inline constexpr REL::ID RequestInventoryItem{ 1200959, 2194009 };
		inline constexpr REL::ID ForceMergeStacks{ 1356509, 2194032 };
	}

	namespace BGSInventoryItem
	{
		inline constexpr REL::ID FindAndWriteStackData{ 770140, 2194123 };
		inline constexpr REL::ID GetDisplayFullName1{ 277641, 2194079 };
		inline constexpr REL::ID GetDisplayFullName2{ 623232, 2194080 };
		inline constexpr REL::ID GetInstanceData{ 491493, 2194072 };
		inline constexpr REL::ID GetInventoryValue{ 430292, 2194099 };
		inline constexpr REL::ID GetExtraDataAt{ 851493, 2194092 };
		inline constexpr REL::ID MergeStacks{ 1132179, 2194109 };
		inline constexpr REL::ID IsEquipped{ 806787, 2194086 };
		inline constexpr REL::ID GetStackCount{ 82050, 2194107 };
		inline constexpr REL::ID IsQuestObject{ 823447, 2194076 };
		inline constexpr REL::ID GetTotalWeight{ 571297, 2194074 };
	}

	namespace BGSInventoryItemUtils
	{
		inline constexpr REL::ID GetInventoryValue{ 23543, 2194127 }; // Check
	}

	namespace BGSInventoryList
	{
		inline constexpr REL::ID FindAndWriteStackDataForItem{ 1354005, 2194179 };
		inline constexpr REL::ID BuildFromContainer{ 551792, 2194158 };
		inline constexpr REL::ID ctor{ 845050, 2194153 };
		inline constexpr REL::ID AddItem{ 19103, 2194159 }; // Check
	}

	namespace BGSKeyword
	{
		inline constexpr REL::ID TypedKeywords{ 1095775, 2692038, 4799330 };
	}

	namespace BGSKeywordForm
	{
		inline constexpr REL::ID AddKeyword{ 762999, 2192766 }; // Check
		inline constexpr REL::ID RemoveKeyword{ 921694, 2192767 }; // Check
	}

	namespace BGSListForm
	{
		inline constexpr REL::ID AddScriptAddedForm{ 1064874, 2203262 }; // Check
	}

	namespace BGSLoadGameBuffer
	{
		inline constexpr REL::ID LoadDataEndian{ 1451631, 2228270 };
	}

	namespace BGSLocalizedStringDL
	{
		inline constexpr REL::ID GetText{ 472297, 2194238 };
	}

	namespace BGSMessage
	{
		inline constexpr REL::ID AddButton{ 236744, 0 };  // Inlined in NG/AE
		inline constexpr REL::ID GetConvertedDescription{ 8331, 2203353 };
	}

	namespace BGSMod
	{
		namespace Attachment
		{
			namespace Mod
			{
				inline constexpr REL::ID FindModsForLooseMod{ 410363, 2197524 };
				inline constexpr REL::ID GetData{ 33658, 0 };  // Inlined in NG/AE
				inline constexpr REL::ID GetLooseMod{ 1359613, 2197514 };
				inline constexpr REL::ID SetLooseMod{ 123132, 2197558 };
			}

			inline constexpr REL::ID GetAllLooseMods{ 1359613, 2661620 }; // Check
		}

		namespace Container
		{
			inline constexpr REL::ID GetData{ 659507, 2189206 };
		}

		namespace Template
		{
			namespace Items
			{
				inline constexpr REL::ID CreateInstanceDataForObjectAndExtra{ 147297, 2189244 };
			}
		}
	}

	namespace BGSNumericIDIndex
	{
		inline constexpr REL::ID GetNumericID{ 915982, 2228199 };
		inline constexpr REL::ID SetNumericID{ 1527703, 2228200 };
	}

	namespace BGSObjectInstance
	{
		inline constexpr REL::ID ctor{ 1095748, 2197563 };
	}

	namespace BGSObjectInstanceExtra
	{
		inline constexpr REL::ID ctor{ 1222521, 2189015 };
		inline constexpr REL::ID AttachModToReference{ 3303, 2189033 };
		inline constexpr REL::ID HasMod{ 963890, 2189026 };
		inline constexpr REL::ID AddMod{ 1191757, 2189025 };
		inline constexpr REL::ID RemoveInvalidMods{ 1548060, 2189028 };
		inline constexpr REL::ID RemoveMod{ 1136607, 2189027 };
		inline constexpr REL::ID GetNumMods{ 1526690, 2189019 };
	}

	namespace BGSOpenCloseForm
	{
		inline constexpr REL::ID AutoCloseRef{ 1175698, 2192797 };
		inline constexpr REL::ID GetOpenState{ 1480253, 2192799 };
		inline constexpr REL::ID HasOnlyOpenCloseAnims{ 45754, 2192796 };
		inline constexpr REL::ID IsAnimating{ 495235, 2192801 };
		inline constexpr REL::ID IsOpenCloseEvent{ 1016560, 2192795 };
		inline constexpr REL::ID IsOpenCloseForm{ 860629, 2192790 };
		inline constexpr REL::ID SetOpenState{ 895942, 2192798 };
	}

	namespace BGSPerkRankArray
	{
		inline constexpr REL::ID AllocatePerkRankArray{ 888419, 2192837 };
		inline constexpr REL::ID ClearPerks{ 1247917, 2192836 };
	}

	namespace BGSPickLockEvent
	{
		inline constexpr REL::ID EventIndex{ 701969, 2663410 };
		inline constexpr REL::ID ctor{ 193329, 2214021 };
	}

	namespace BGSPrimitive
	{
		inline constexpr REL::ID CreateAbstract{ 1095144, 2194290 };
	}

	namespace BGSProjectile
	{
		inline constexpr REL::ID CollidesWithSmallTransparentLayer{ 1115694, 2197620 };
	}

	namespace BGSQuestInstanceText
	{
		inline constexpr REL::ID ParseString{ 141681, 2206630 };
	}

	namespace BGSSaveLoadFileEntry
	{
		inline constexpr REL::ID DeleteGame{ 91575, 2227855 };
		inline constexpr REL::ID LoadData{ 741580, 2227871 };
	}

	namespace BGSSaveGameBuffer
	{
		inline constexpr REL::ID SaveDataEndian{ 594281, 2228319 };
	}

	namespace BGSSaveLoadManager
	{
		inline constexpr REL::ID Singleton{ 1247320, 2697802 };
		inline constexpr REL::ID BuildSaveGameList{ 1342984, 2228053 };
		inline constexpr REL::ID GetSaveDirectoryPath{ 1569549, 2228028 };
		inline constexpr REL::ID QueueSaveLoadTask{ 1487308, 2228080 };
	}

	namespace BGSScene
	{
		inline constexpr REL::ID ResetAllSceneActions{ 1356678, 2206864 };
		inline constexpr REL::ID SetSceneActive{ 820354, 2206845 };
	}

	namespace BGSSceneActionNPCResponseDialogue
	{
		inline constexpr REL::ID GetCurrentTopicInfo{ 1369299, 2196825 };
		inline constexpr REL::ID UpdateAction1{ 1439851, 2196817 }; // Check
		inline constexpr REL::ID UpdateAction2{ 574707, 2196800 }; // Check
	}

	namespace BGSSceneActionPlayerDialogue
	{
		inline constexpr REL::ID GetCurrentTopicInfo{ 781358, 2196825 };
	}

	namespace BGSStoryEventManager
	{
		inline constexpr REL::ID Singleton{ 1160067, 2693504, 4800796 };
		inline constexpr REL::ID AddEvent{ 312533, 2214088 };
	}

	namespace BGSSynchronizedAnimationManager
	{
		inline constexpr REL::ID Singleton{ 1346879, 2690996, 4798289 };
		inline constexpr REL::ID IsReferenceInSynchronizedScene{ 915329, 2214437 };
	}

	namespace BGSTerminal
	{
		inline constexpr REL::ID GetHackDifficultyLockLevel{ 537273, 2197777 };
		inline constexpr REL::ID IsTerminalRefInUse{ 1093565, 2197779 };
		inline constexpr REL::ID Show{ 1069012, 2197776 };
		inline constexpr REL::ID Activate{ 178045, 2197778 }; // Check
	}

	namespace bhkCharacterController
	{
		inline constexpr REL::ID Jump{ 1067306, 2278191 };
	}

	namespace bhkNPCollisionObject
	{
		inline constexpr REL::ID CopyMembers{ 1558409, 2277907 };
		inline constexpr REL::ID GetBody{ 1127049, 2277926 };
		inline constexpr REL::ID GetBodyId{ 1286222, 2277928 };
		inline constexpr REL::ID GetShape{ 315427, 2277929 };
		inline constexpr REL::ID GetTransform{ 1508189, 2277944 };
		inline constexpr REL::ID SetMotionType{ 200912, 2277913 };
		inline constexpr REL::ID SetTransform{ 178085, 2277945 };
		inline constexpr REL::ID Getbhk{ 730034, 2277919 };
	}

	namespace bhkPhysicsSystem
	{
		inline constexpr REL::ID ctor{ 1338184, 2278008 };
		inline constexpr REL::ID AddToWorld{ 512878, 2278019 };
		inline constexpr REL::ID CopyMembers{ 301764, 2278007 };
	}

	namespace bhkPickData
	{
		inline constexpr REL::ID ctor{ 526783, 2230668 };
		inline constexpr REL::ID SetStartEnd{ 747470, 2236622 };
		inline constexpr REL::ID Reset{ 438299, 2277761 };
		inline constexpr REL::ID HasHit{ 1181584, 2277770 };
		inline constexpr REL::ID GetHitFraction{ 476687, 2277772 };
		inline constexpr REL::ID GetAllCollectorRayHitSize{ 1288513, 2277765 };
		inline constexpr REL::ID GetAllCollectorRayHitAt{ 583997, 2277766 };
		inline constexpr REL::ID SortAllCollectorHits{ 1274842, 2277767 };
		inline constexpr REL::ID GetNiAVObject{ 863406, 2277764 };
		inline constexpr REL::ID GetBody{ 1223055, 2277762 };
	}

	namespace bhkUtilFunctions
	{
		inline constexpr REL::ID FindFirstCollisionObject{ 507243, 2278093 };
	}

	namespace bhkWorld
	{
		inline constexpr REL::ID AddPhysicsSystem{ 82382, 2277752 };
		inline constexpr REL::ID RemovePhysicsSystem{ 1039226, 2277753 };
		inline constexpr REL::ID RemoveObjects{ 1514984, 2277721 };
	}

	namespace BIPOBJECT
	{
		inline constexpr REL::ID dtor{ 765242, 2194330 };
	}

	namespace BSAudioManager
	{
		inline constexpr REL::ID Singleton{ 1321158, 2703058 };
		inline constexpr REL::ID GetSoundHandleByName{ 196484, 2267105 };
		inline constexpr REL::ID GetSoundHandleByFile{ 37039, 2267103 };
	}

	namespace BSAwardsSystemUtility
	{
		inline constexpr REL::ID Singleton{ 1569384, 2255115 };
	}

	namespace BSGFxDisplayObject
	{
		inline constexpr REL::ID RemoveChild{ 1229383, 2287327 };
	}

	namespace BSGFxObject
	{
		inline constexpr REL::ID AcquireFlashObjectByMemberName{ 1172680, 2287014 };
		inline constexpr REL::ID AcquireFlashObjectByPath{ 1065592, 2287015 };
	}

	namespace BSGFxShaderFXTarget
	{
		inline constexpr REL::ID ProcessEvent{ 848563, 2287033 };
		inline constexpr REL::ID AppendShaderFXInfos{ 544646, 2287021 };
		inline constexpr REL::ID CreateAndSetFiltersToColor1{ 1487925, 2287028 };
		inline constexpr REL::ID CreateAndSetFiltersToColor2{ 783104, 2287029 };
		inline constexpr REL::ID CreateAndSetFiltersToHUD{ 876001, 2287027 };
		inline constexpr REL::ID EnableShadedBackground{ 278402, 2287022 };
	}

	namespace BSGraphics
	{
		namespace Renderer
		{
			inline constexpr REL::ID IncRef{ 1337764, 2276869 };
			inline constexpr REL::ID DecRef{ 194808, 2276870 };
			inline constexpr REL::ID Begin{ 288964, 2276833 };
			inline constexpr REL::ID End{ 700869, 2276834 };
			inline constexpr REL::ID Lock{ 1087134, 2276828 }; // Check
			inline constexpr REL::ID Unlock{ 382332, 2276829 }; // Check
		}

		namespace RenderTargetManager
		{
			inline constexpr REL::ID Singleton{ 1508457, 2666735 };
			inline constexpr REL::ID SetEnableDynamicResolution{ 116947, 2277197 };
		}

		namespace State
		{
			inline constexpr REL::ID Singleton{ 600795, 2704621 };
		}

		namespace Utility
		{
			inline constexpr REL::ID ConvertHALFToNiPoint3Stream{ 463129, 2277113 };
			inline constexpr REL::ID ConvertNiPoint3ToHALFStream{ 1247946, 2277114 };
			inline constexpr REL::ID PackVertexData{ 156126, 2277106 };
			inline constexpr REL::ID UnpackVertexData{ 990748, 2277129 };
		}

		inline constexpr REL::ID GetRendererData{ 1235449, 2704429 };
		inline constexpr REL::ID GetCurrentRendererWindow{ 91810, 2704431 };
	}

	namespace BSIdleInputWatcher
	{
		inline constexpr REL::ID Singleton{ 487306, 2693716, 4801008 };
	}

	namespace BSInputDeviceManager
	{
		inline constexpr REL::ID Singleton{ 1284221, 2694300, 4807767 };
	}

	namespace BSInputEnableLayer
	{
		inline constexpr REL::ID DecRef{ 659989, 2268272 };
	}

	namespace BSInputEnableManager
	{
		inline constexpr REL::ID Singleton{ 781703, 2689007, 4796297 };
		inline constexpr REL::ID AllocateNewLayer{ 537494, 2268244 };
		inline constexpr REL::ID EnableUserEvent{ 1432984, 2268263 };
		inline constexpr REL::ID EnableOtherEvent{ 1419268, 2268265 };
	}

	namespace BSModelDB
	{
		inline constexpr REL::ID Demand1{ 1066398, 2275153 };
		inline constexpr REL::ID Demand2{ 1225688, 2275154 };
	}

	namespace BSPointerHandle
	{
		namespace BSPointerHandleManagerInterface
		{
			inline constexpr REL::ID CreateHandle{ 224532, 2188375 };
			inline constexpr REL::ID GetHandle{ 901626, 2188676 };
			inline constexpr REL::ID GetSmartPointer{ 967277, 2188681 };
		}
	}

	namespace BSRandom
	{
		inline constexpr REL::ID UnsignedInt{ 694400, 2267950 };
		inline constexpr REL::ID Float{ 1118937, 2267953 }; // Check
		inline constexpr REL::ID Float0To1{ 54937, 2267954 }; // Check
		inline constexpr REL::ID Int{ 1212543, 2267952 }; // Check
	}

	namespace BSResource_Archive2_AsyncReaderStream
	{
		inline constexpr REL::ID DoOpen{ 1401160, 2269387 };
		inline constexpr REL::ID DoClose{ 883012, 2269380 };
		inline constexpr REL::ID DoClone{ 803750, 2269379 };
		inline constexpr REL::ID DoStartRead{ 1215072, 2269395 };
		inline constexpr REL::ID DoStartPacketAlignedBufferedRead{ 603387, 2269394 };
		inline constexpr REL::ID DoWait{ 244066, 2269399 };
	}

	namespace BSResource_Archive2_ReaderStream
	{
		inline constexpr REL::ID DoOpen{ 762048, 2269280 };
		inline constexpr REL::ID DoClose{ 109149, 2269285 };
		inline constexpr REL::ID DoGetKey{ 772817, 2269288 };
		inline constexpr REL::ID DoClone{ 855081, 2269279 };
		inline constexpr REL::ID DoRead{ 1359347, 2269281 };
		inline constexpr REL::ID DoSeek{ 1000164, 2269282 };
		inline constexpr REL::ID DoPrefetchAll{ 1518821, 2269390 };
		inline constexpr REL::ID DoCreateAsync{ 893405, 2269287 };
	}

	namespace BSResource_EntryDBBaseUtil
	{
		inline constexpr REL::ID ReleaseEntryAction{ 777279, 2269463 };
	}

	namespace BSResource_GlobalLocations
	{
		inline constexpr REL::ID Singleton{ 1573818, 2703394 };
	}

	namespace BSResource_GlobalPaths
	{
		inline constexpr REL::ID Singleton{ 210868, 2703393 };
	}

	namespace BSResource
	{
		inline constexpr REL::ID RegisterLocation{ 918408, 2269481 };
		inline constexpr REL::ID GetOrCreateStream{ 1143155, 2269490 };

		namespace ID
		{
			inline constexpr REL::ID GenerateFromPath{ 570861, 2269259 };
		}
	}

	namespace BSResourceNiBinaryStream
	{
		inline constexpr REL::ID Seek{ 358512, 2269834 };
		inline constexpr REL::ID DoRead{ 424286, 2269839 };
		inline constexpr REL::ID DoWrite{ 1208863, 2269840 };
		inline constexpr REL::ID GetBufferInfo{ 265501, 2269836 };
		inline constexpr REL::ID Ctor{ 1198116, 2269830 };
		inline constexpr REL::ID Dtor{ 1516202, 2269832 };
		inline constexpr REL::ID BinaryStreamWithRescan{ 543595, 2205871 };
	}

	namespace BSScaleformManager
	{
		inline constexpr REL::ID Singleton{ 106578, 2689600, 4796889 };
		inline constexpr REL::ID LoadMovie{ 1526234, 2287422 };
		inline constexpr REL::ID GetMovieFilename{ 1191277, 2287428 };
		inline constexpr REL::ID InitMovieViewport{ 206895, 2287430, 4494254 };
		inline constexpr REL::ID FileUncacheOnMenuOpen{ 454316, 2667999 };
		inline constexpr REL::ID IsNameValid{ 593721, 2287425 }; // Check
	}

	namespace BSScaleformRenderer
	{
		inline constexpr REL::ID Initialize{ 1403529, 2284938 };
	}

	namespace BSScaleformTranslator
	{
		inline constexpr REL::ID AddTranslations{ 810671, 2295298 };
	}

	namespace BSScript_Array
	{
		inline constexpr REL::ID ctor{ 870924, 2314915 }; // Check
	}

	namespace BSScript_ArrayWrapper
	{
		inline constexpr REL::ID ReplaceArray{ 445184, 2250435 };
	}

	namespace BSScript_Internal_NativeFunctionBase
	{
		inline constexpr REL::ID Call{ 571037, 2314780 };
	}

	namespace BSScript_Internal_Stack
	{
		inline constexpr REL::ID GetPageForFrame{ 1429302, 2314680 };
		inline constexpr REL::ID GetStackFrameVariable{ 897539, 2314681 };
	}

	namespace BSScript_Object
	{
		inline constexpr REL::ID DecRef{ 541793, 2314437 };
		inline constexpr REL::ID GetHandle{ 1452752, 2314431 }; // Check
		inline constexpr REL::ID IncRef{ 461710, 2314436 };
	}

	namespace BSScript_ObjectTypeInfo
	{
		inline constexpr REL::ID dtor{ 1047917, 2314513 }; // Check
	}

	namespace BSScript_ObjectBindPolicy
	{
		inline constexpr REL::ID BindObject{ 709728, 2314370 }; // Check
		inline constexpr REL::ID UnbindObject{ 522763, 2314372 }; // Check
	}

	namespace BSScriptUtil
	{
		inline constexpr REL::ID BaseObjectName{ 648543, 2702269 }; // Check
	}

	namespace BSShaderProperty
	{
		inline constexpr REL::ID SetMaterial{ 706318, 2316285 };
	}

	namespace BSShaderTextureSet
	{
		inline constexpr REL::ID CreateObject{ 993063, 2316324 };
	}

	namespace BSShaderUtil
	{
		inline constexpr REL::ID SetMaterialAlpha{ 211260, 2317566 };
	}

	namespace BSSoundHandle
	{
		inline constexpr REL::ID FadeInPlay{ 353528, 2267075 };
		inline constexpr REL::ID FadeOutAndRelease{ 260328, 2267076 };
		inline constexpr REL::ID IsPlaying{ 1514207, 2267046 }; // Check
		inline constexpr REL::ID Play{ 384073, 2276042 };
		inline constexpr REL::ID SetOutputModel{ 170407, 2267053 };
		inline constexpr REL::ID Stop{ 1340948, 2267045 };
	}

	namespace BSSpinLock
	{
		namespace BSReadWriteLock
		{
			inline constexpr REL::ID lock_read{ 1573164, 2267897 };
			inline constexpr REL::ID lock_write{ 336186, 2267898 };
			inline constexpr REL::ID try_lock_read{ 1372435, 2267901 };
			inline constexpr REL::ID try_lock_write{ 1279453, 2267902 };
		}

		inline constexpr REL::ID lock{ 1425657, 2192245 };
		inline constexpr REL::ID try_lock{ 267930, 2267902 };
	}

	namespace BSStringPool
	{
		namespace Entry
		{
			inline constexpr REL::ID Release{ 1204430, 2268720 };
		}

		inline constexpr REL::ID GetEntry_char{ 507142, 2268729 };
		inline constexpr REL::ID GetEntry_wchar{ 345043, 2268730 };
	}

	namespace BSStringT
	{
		inline constexpr REL::ID Set{ 407804, 2189084, 4471693 }; // Check
	}

	namespace BSSystemFileStreamer
	{
		inline constexpr REL::ID UncacheAll{ 40925, 2268797 };
	}

	namespace BSTempEffectDebris
	{
		inline constexpr REL::ID ctor{ 1075623, 2212059 };
	}

	namespace BSTempEffectWeaponBlood
	{
		inline constexpr REL::ID ClearEffectForWeapon{ 718866, 2212158 };
	}

	namespace BSTEvent
	{
		namespace BSTGlobalEvent
		{
			inline constexpr REL::ID Singleton{ 1424022, 2688814, 4796078 };
		}
	}

	namespace BSThreadEvent
	{
		inline constexpr REL::ID InitSDM{ 1425097, 2268180 };
	}

	namespace BSTimer
	{
		inline constexpr REL::ID Singleton{ 1256126, 2703179 };
		inline constexpr REL::ID QGlobalTimeMultiplier{ 365546, 2666307 };
		inline constexpr REL::ID QGlobalTimeMultiplierTarget{ 1266509, 2666308 };
		inline constexpr REL::ID SetGlobalTimeMultiplier{ 1419977, 2267970 };
	}

	namespace BSUIMessageData
	{
		inline constexpr REL::ID SendUIBoolMessage{ 1388308, 2284981 };
		inline constexpr REL::ID SendUIStringMessage{ 1270833, 2284977 };
		inline constexpr REL::ID SendUIPtrMessage{ 1374542, 2284982 };
		inline constexpr REL::ID SendUIStringUIntMessage{ 99795, 2284979 };
	}

	namespace BSUtilities
	{
		inline constexpr REL::ID ConvertFloatToHalf{ 10414, 2212098 };
		inline constexpr REL::ID ConvertHalfToFloat{ 1502141, 2195843 };
		inline constexpr REL::ID GetObjectByName{ 843650, 2274841 };
		inline constexpr REL::ID GetFlattenedBoneTree{ 1539401, 2274858 }; // Check
	}

	namespace Calendar
	{
		inline constexpr REL::ID Singleton{ 1444952, 2689092, 4796378 };
		inline constexpr REL::ID GetDaysPassed{ 1209930, 2228563 }; // Check
	}

	namespace CanDisplayNextHUDMessage
	{
		inline constexpr REL::ID GetEventSource{ 344866, 2695041, 4802332 };
	}

	namespace CellAttachDetachEvent
	{
		inline constexpr REL::ID GetEventSource{ 862142, 2192250 };
	}

	namespace ColorUpdateEvent
	{
		inline constexpr REL::ID GetEventSource{ 1226590, 2695540, 4802831 };
	}

	namespace CombatBehaviorFindObject
	{
		inline constexpr REL::ID EvaluateArmor{ 1333384, 2241004 }; // Check
	}

	namespace CombatFormulas
	{
		inline constexpr REL::ID GetWeaponDisplayAccuracy{ 1137654, 2209049 };
		inline constexpr REL::ID GetWeaponDisplayDamage{ 1431014, 2209046 };
		inline constexpr REL::ID GetWeaponDisplayRange{ 1324037, 2209047 };
		inline constexpr REL::ID GetWeaponDisplayRateOfFire{ 1403591, 2209048 };
		inline constexpr REL::ID CalcTargetedLimbDamage{ 1530751, 2209033 };
		inline constexpr REL::ID CalcWeaponDamage{ 211411, 2209001 };
		inline constexpr REL::ID GetNumCrippledAttackConditions{ 170270, 2209041 };
		inline constexpr REL::ID CalcScopeSteadyActionPointDrain{ 380926, 2209045 };
	}

	namespace CombatUtilities
	{
		inline constexpr REL::ID CalculateProjectileLOS1{ 798616, 2240617 };
		inline constexpr REL::ID CalculateProjectileLOS2{ 55339, 2240616 };
		inline constexpr REL::ID CalculateProjectileTrajectory{ 1575156, 2240611 };
		inline constexpr REL::ID WorldGravity{ 1378547, 2700340 };
		inline constexpr REL::ID IsActorUsingMelee{ 858050, 2240626 }; // Check
		inline constexpr REL::ID IsActorUsingUnarmed{ 1483696, 2240625 }; // Check
	}

	namespace ComparisonQualifiers
	{
		inline constexpr REL::ID ContainerQualifier{ 883895, 2190674 };
		inline constexpr REL::ID UIQualifier{ 179412, 2190675 };
	}

	namespace Console
	{
		inline constexpr REL::ID ExecuteCommand{ 1061864, 2248537 };
		inline constexpr REL::ID GetCurrentPickIndex{ 1407033, 2701382 };
		inline constexpr REL::ID GetPickRef{ 170742, 2701395 };
		inline constexpr REL::ID GetPickRefs{ 875116, 2701391 };
		inline constexpr REL::ID SetCurrentPickREFR{ 79066, 2248551 };
		inline constexpr REL::ID DisplayRef{ 1107782, 2248550 }; // Check
	}

	namespace ConsoleLog
	{
		inline constexpr REL::ID Singleton{ 689441, 2690148, 4797437 };
		inline constexpr REL::ID AddString{ 764, 2248593 };
		inline constexpr REL::ID Print{ 799546, 2248591 };
	}

	namespace ContainerMenu
	{
		inline constexpr REL::ID TakeAllItems{ 1323703, 2248619 };
	}

	namespace ContainerMenuBase
	{
		namespace ItemSorter
		{
			inline constexpr REL::ID IncrementSort{ 1307263, 2222848 };
		}
	}

	namespace ControlMap
	{
		inline constexpr REL::ID Singleton{ 325206, 2692014, 4799307 };
		inline constexpr REL::ID PopInputContext{ 74587, 2268336 };
		inline constexpr REL::ID PushInputContext{ 1404410, 2268335 };
		inline constexpr REL::ID RemapButton{ 11351, 2268330 };
		inline constexpr REL::ID SaveRemappings{ 1141541, 2268331 };
		inline constexpr REL::ID SetTextEntryMode{ 1270079, 2268339, 4491359 };
	}

	namespace CurrentRadiationSourceCount
	{
		inline constexpr REL::ID GetEventSource{ 696410, 2696196, 4803487 };
	}

	namespace DEFAULT_OBJECT_DATA
	{
		inline constexpr REL::ID GetDefaultObjectData{ 838886 }; // Same
	}

	namespace DialogueCameraState
	{
		inline constexpr REL::ID UpdateActorsAndAction{ 24497, 2214898 }; // Check
	}

	namespace DialogueMenuUtils
	{
		inline constexpr REL::ID OpenMenu{ 1562703, 2249658 };
		inline constexpr REL::ID CloseMenu{ 764651, 2249659 };
		inline constexpr REL::ID ShowSpeechChallengeAnim{ 868159, 2249665 };
	}

	namespace DoBeforeNewOrLoadCompletedEvent
	{
		inline constexpr REL::ID GetEventSource{ 787908, 2695542, 4802833 };
	}

	namespace EffectItem
	{
		inline constexpr REL::ID GetDescription{ 949839, 2189612 };
	}

	namespace EquippedWeaponData
	{
		inline constexpr REL::ID SetupFireSounds{ 1468462, 2232275 };
	}

	namespace ExamineMenu
	{
		inline constexpr REL::ID BuildWeaponScrappingArray{ 646841, 2223077 };
		inline constexpr REL::ID GetSelectedIndex{ 776503, 2223022 };
		inline constexpr REL::ID ShowConfirmMenu{ 443081, 2223081 };
		inline constexpr REL::ID ConsumeSelectedItems{ 686586, 2223052 };
		inline constexpr REL::ID BuildConfirmed{ 1396668, 2223013 };
		inline constexpr REL::ID GetBuildConfirmQuestion{ 1360189, 2223057 }; // Check
	}

	namespace ExteriorCellSingleton
	{
		inline constexpr REL::ID Singleton{ 128691, 2689084, 4796370 };
	}

	namespace ExtraDataList
	{
		inline constexpr REL::ID CreateInstanceData{ 1280130, 2190185 };
		inline constexpr REL::ID GetLegendaryMod{ 178075, 2190180 };
		inline constexpr REL::ID SetBendableSplineInfo{ 894306, 2190623 };
		inline constexpr REL::ID SetDisplayNameFromInstanceData{ 457340, 2190179 };
		inline constexpr REL::ID SetOverrideName{ 222303, 2190167 };
		inline constexpr REL::ID SetStartingWorldOrCell{ 603621, 2190506 };
		inline constexpr REL::ID GetHealthPerc{ 196530, 2190226 };
		inline constexpr REL::ID SetHealthPerc{ 1208294, 2190124 };
		inline constexpr REL::ID ClearFavorite{ 254434, 2190191 };
		inline constexpr REL::ID IsFavorite{ 786568, 2190189 };
		inline constexpr REL::ID IsDamaged{ 116730, 2190224 }; // Check
		inline constexpr REL::ID CompareList{ 585876, 2190098 };
		inline constexpr REL::ID SetFavorite{ 534268, 2190188 }; // Check
		inline constexpr REL::ID GetPrimitive{ 1271508, 2190427 }; // Check
	}

	namespace ExtraTextDisplayData
	{
		inline constexpr REL::ID GetDisplayName{ 1523343, 2191318 };
	}

	namespace FavoritesManager
	{
		inline constexpr REL::ID Singleton{ 198281, 2694399, 4801690 };
		inline constexpr REL::ID IsComponentFavorite{ 352046, 2248752 };
		inline constexpr REL::ID UseQuickkeyItem{ 303130, 2248744 };
		inline constexpr REL::ID HandleEvent{ 1049251, 2248740 }; // Check
		inline constexpr REL::ID Call{ 1566377, 2248766 }; // Check
		inline constexpr REL::ID ClearCurrentAmmoCount{ 541959, 2248745 };
	}

	namespace FlatScreenModel
	{
		inline constexpr REL::ID Singleton{ 847741, 2694427, 4801718 };
	}

	namespace GameMenuBase
	{
		inline constexpr REL::ID SetIsTopButtonBar{ 1367353, 2223204 };
		inline constexpr REL::ID OnMenuDisplayStateChanged{ 1274450, 2223205 };
		inline constexpr REL::ID CacheShaderFXQuadsForRenderer_Impl{ 863029, 2223200 };
		inline constexpr REL::ID TransferCachedShaderFXQuadsForRenderer{ 65166, 2223201 };
		inline constexpr REL::ID SetViewportRect{ 1554334, 2223202 };
		inline constexpr REL::ID AppendShaderFXInfos{ 583584, 2223203 };
		inline constexpr REL::ID SetUpButtonBar{ 531584, 2223197 };
	}

	namespace GamePlayFormulas
	{
		inline constexpr REL::ID CanHackGateCheck{ 269668, 2209069 };
		inline constexpr REL::ID CanPickLockGateCheck{ 1160841, 2209066 };
		inline constexpr REL::ID GetExperienceReward{ 853500, 2209076 };
		inline constexpr REL::ID GetLockXPReward{ 880926, 2209070 };
		inline constexpr REL::ID CalculateItemHealthDamageBonus{ 612133, 2209087 };
		inline constexpr REL::ID CalcSpringingActionPoints{ 1053786, 2209071 };
		inline constexpr REL::ID GetSweetSpotAngle{ 293819, 2209082 }; // Check
		inline constexpr REL::ID GetPartialPickAngle{ 1078228, 2209083 }; // Check
		inline constexpr REL::ID GetPickBreakSeconds{ 984807, 2209084 }; // Check
		inline constexpr REL::ID GetHackingWordCount{ 190347, 2209067 };
		inline constexpr REL::ID CalculateItemValue{ 960532, 2209074 }; // Check
		inline constexpr REL::ID GetForceLockChance{ 549534, 2209065 }; // Check
	}

	namespace GameScript
	{
		namespace HandlePolicy
		{
			inline constexpr REL::ID DropSaveLoadRemapData{ 647657, 2249995 };
			inline constexpr REL::ID GetInventoryObjFromHandle{ 66597, 2249989 };
			inline constexpr REL::ID UpdatePersistence{ 11020, 2249991 };
		}

		namespace ObjectBindPolicy
		{
			inline constexpr REL::ID EndSaveLoad{ 1558837, 2250482 };
		}

		namespace GameVM
		{
			inline constexpr REL::ID Singleton{ 996227, 2689134, 4796420 };
			inline constexpr REL::ID QueuePostRenderCall{ 34412, 2251314 };
			inline constexpr REL::ID RegisterForAllGameEvents{ 680454, 2251353 };
			inline constexpr REL::ID SendEventToObjectAndRelated{ 367992, 2251344 };
		}

		inline constexpr REL::ID LogFormError{ 1081933, 2251028 };
		inline constexpr REL::ID BindCObject{ 81787, 2249771 };
	}

	namespace GameUIModel
	{
		inline constexpr REL::ID Singleton{ 17419, 2695523, 4802814 };
		inline constexpr REL::ID SetGameColors{ 523665, 2220911 };
		inline constexpr REL::ID UpdateDataModels{ 1269653, 2220905 };
	}

	namespace GridCellArray
	{
		inline constexpr REL::ID Get{ 1330136, 2194566 }; // Check
	}

	namespace HolotapeMenu
	{
		inline constexpr REL::ID ShowHolotapeInPipboy{ 217953, 2224028 };
		inline constexpr REL::ID ShowHolotapeInTerminal{ 390509, 2224029 };
	}

	namespace HUDExperienceMeter
	{
		inline constexpr REL::ID UpdateDisplayObject{ 246555, 2220382 }; // Check
	}

	namespace HUDMenu
	{
		inline constexpr REL::ID SetHUDColor{ 505571, 2248918 };
	}

	namespace HUDMenuUtils
	{
		inline constexpr REL::ID GetGameplayHUDColor{ 34363, 2248840 };
		inline constexpr REL::ID GetGameplayHUDBackgroundColor{ 698605, 2248845 };
		inline constexpr REL::ID WorldPtToScreenPt3{ 1132313, 2222464 };
	}

	namespace HUDModeEvent
	{
		inline constexpr REL::ID GetEventSource{ 683142, 2694697, 4801988 };
	}

	namespace IAnimationGraphManagerHolder
	{
		inline constexpr REL::ID SetGraphVariableBool{ 1437197, 2214543 };
		inline constexpr REL::ID SetGraphVariableFloat{ 27400, 2214545 };
		inline constexpr REL::ID SetGraphVariableInt{ 732926, 2214544 };
		inline constexpr REL::ID RevertAnimationGraphManager{ 41382, 2214541 };
	}

	namespace IFormFactory
	{
		inline constexpr REL::ID Factories{ 228366, 2689177, 4796464 };
	}

	namespace ImageSpaceEffectFullScreenBlur
	{
		inline constexpr REL::ID Disable{ 372489, 2713225 };
	}

	namespace ImageSpaceEffectGetHit
	{
		inline constexpr REL::ID Disable{ 1523708, 2713237 };
	}

	namespace ImageSpaceEffectHDR
	{
		inline constexpr REL::ID UsePipboyScreenMask{ 405286, 2678029, 4784697 };
	}

	namespace ImageSpaceEffectPipboyScreen
	{
		inline constexpr REL::ID PowerArmorPipboy{ 1065542, 2713203 };
	}

	namespace ImageSpaceEffectRadialBlur
	{
		inline constexpr REL::ID Disable{ 1500590, 2713225 };
	}

	namespace ImageSpaceEffectTemporalAA
	{
		inline constexpr REL::ID MaskS{ 775377, 2713052 };
	}

	namespace ImageSpaceManager
	{
		inline constexpr REL::ID Singleton{ 161743, 2712627 };
	}

	namespace ImageSpaceModifierInstance
	{
		inline constexpr REL::ID Stop{ 1298537, 2199897 };
	}

	namespace ImageSpaceModifierInstanceDOF
	{
		inline constexpr REL::ID Trigger{ 1158048, 2199922 };
	}

	namespace ImageSpaceModifierInstanceForm
	{
		inline constexpr REL::ID Trigger1{ 179769, 2199906 };
		inline constexpr REL::ID Trigger2{ 1216312, 2199907 };
		inline constexpr REL::ID Stop1{ 217873, 2199909 };
		inline constexpr REL::ID Stop2{ 549773, 2199910 };
	}

	namespace IMenu
	{
		inline constexpr REL::ID ShouldHandleEvent{ 1241790, 2287392 };
		inline constexpr REL::ID PassesRenderConditionText{ 937304, 2287379 };
		inline constexpr REL::ID OnSetSafeRect{ 964859, 2287375 };
		inline constexpr REL::ID ProcessScaleformEvent{ 150211, 2287395 };
		inline constexpr REL::ID RefreshPlatform{ 1071829, 2287374 };
	}

	namespace Interface3D
	{
		inline constexpr REL::ID Create{ 88488, 2222519 };
		inline constexpr REL::ID GetByName{ 140387, 2222524 };
		inline constexpr REL::ID MainScreen_AddPointLight{ 1335675, 2222531 };
		inline constexpr REL::ID MainScreen_AddSpotLight{ 1056093, 2222532 };
		inline constexpr REL::ID MainScreen_ClearLights{ 683530, 2222533 };
		inline constexpr REL::ID MainScreen_SetScreenAttached3D{ 817727, 2222528 };
		inline constexpr REL::ID MainScreen_SetWorldAttached3D{ 724778, 2222529 };
		inline constexpr REL::ID Offscreen_AddLight{ 1267198, 2222543 };
		inline constexpr REL::ID Offscreen_Clear3D{ 1533262, 2222542 };
		inline constexpr REL::ID Offscreen_ClearLights{ 1039253, 2222545 };
		inline constexpr REL::ID Offscreen_GetRenderTargetHeight{ 1280897, 2222538 };
		inline constexpr REL::ID Offscreen_GetRenderTargetWidth{ 403273, 2222537 };
		inline constexpr REL::ID Offscreen_Set3D{ 43983, 2222541 };
		inline constexpr REL::ID Offscreen_SetDebugMode{ 1277879, 2222549 };
		inline constexpr REL::ID Offscreen_SetDirectionalLight{ 987144, 2222544 };
		inline constexpr REL::ID Enable{ 326895, 2222522 };
		inline constexpr REL::ID Disable{ 938370, 2222523 };
		inline constexpr REL::ID DisableAll{ 1470633, 2222521 };
		inline constexpr REL::ID Release{ 74749, 2222520 };
		inline constexpr REL::ID SetViewport{ 825410, 2222552 };
	}

	namespace Inventory3DManager
	{
		inline constexpr REL::ID Begin3D{ 662659, 2249084 };
		inline constexpr REL::ID ClearModel{ 63218, 2249113 };
		inline constexpr REL::ID DisableRendering{ 255893, 2249099 };
		inline constexpr REL::ID EnableRendering{ 176578, 2249098 };
		inline constexpr REL::ID End3D{ 1512675, 2249086 };
		inline constexpr REL::ID SetModelScale{ 1319701, 2249097 };
		inline constexpr REL::ID SetModelScreenPosition{ 2967, 2249096 };
	}

	namespace InventoryItemDisplayData
	{
		inline constexpr REL::ID ctor{ 679373, 2222612 };
	}

	namespace InventoryUserUIUtils
	{
		inline constexpr REL::ID AddItemCardInfoEntry{ 489521, 2222648 };
		inline constexpr REL::ID PopulateItemCardInfo_Helper{ 475551, 2222625 }; // Check
	}

	namespace ItemCrafted
	{
		inline constexpr REL::ID NotifyOfItemCrafted{ 788895, 2232809 };
		inline constexpr REL::ID RegisterSink{ 1320496, 2232807 };
		inline constexpr REL::ID UnregisterSink{ 1054567, 2232808 };
	}

	namespace LevelIncrease
	{
		inline constexpr REL::ID GetEventSource{ 349120, 2233736 };
	}

	namespace LoadingMenu
	{
		inline constexpr REL::ID StartTestingLoadMenu{ 933696, 2249224 };
		inline constexpr REL::ID PopulateLoadScreens{ 316170, 2249232 };
	}

	namespace LockpickingMenu
	{
		inline constexpr REL::ID OpenLockpickingMenu{ 129892, 2249263 };
		inline constexpr REL::ID SendLockInfoToMenu{ 1256681, 2249267 }; // Check
	}

	namespace LocksPicked
	{
		inline constexpr REL::ID GetEventSource{ 594991, 2249292 };
	}

	namespace MagicTarget
	{
		inline constexpr REL::ID IsTakingHealthDamageFromActiveEffect{ 999442, 2226397 };
		inline constexpr REL::ID IsTakingRadDamageFromActiveEffect{ 1079111, 2226398 };
	}

	namespace Main
	{
		inline constexpr REL::ID Singleton{ 756304, 2698043 };
		inline constexpr REL::ID WorldRootCamera{ 384264, 2228956 };
		inline constexpr REL::ID WorldRootNode{ 569647, 2698065 };
		inline constexpr REL::ID QGameSystemsShouldUpdate{ 779552, 2698031 };
		inline constexpr REL::ID QGameDataLoaded{ 1004331, 2698032 };
		inline constexpr REL::ID SetCameraFOV{ 1348813, 2228973 };
	}

	namespace MapMarkerData
	{
		inline constexpr REL::ID GetLocationName{ 50980, 2191791 }; // Check
	}

	namespace MemoryManager
	{
		namespace AutoScrapBuffer
		{
			inline constexpr REL::ID ctor{ 1571567, 2267865 };
			inline constexpr REL::ID dtor{ 68625, 2267867 };
		}

		inline constexpr REL::ID Singleton{ 343176, 2193197, 4471522 };
		inline constexpr REL::ID Allocate{ 652767, 2267872 };
		inline constexpr REL::ID Deallocate{ 1582181, 2267874 };
		inline constexpr REL::ID GetThreadScrapHeap{ 1495205, 2267850 };
		inline constexpr REL::ID Reallocate{ 1502917, 2267873 };
		inline constexpr REL::ID RegisterMemoryManager{ 453212, 2228356 };
	}

	namespace MenuControls
	{
		inline constexpr REL::ID Singleton{ 520890, 2689089, 4796375 };
	}

	namespace MenuCursor
	{
		inline constexpr REL::ID Singleton{ 695696, 2696546, 4803837 };
		inline constexpr REL::ID CenterCursor{ 1107298, 2287473 };
		inline constexpr REL::ID RegisterCursor{ 1318193, 2287475 };
		inline constexpr REL::ID SetCursorConstraintsRaw{ 907092, 2287480 };
		inline constexpr REL::ID UnregisterCursor{ 1225249, 2287486 };
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
		inline constexpr REL::ID Singleton{ 520890, 2689089, 4796375 };
	}

	namespace MessageBoxMenu
	{
		inline constexpr REL::ID ShowMessage{ 442479, 2249469 };
	}

	namespace MessageMenuManager
	{
		inline constexpr REL::ID Singleton{ 959572, 2689087, 4796373 };
		inline constexpr REL::ID Create{ 89563, 2249456 };
	}

	namespace Moon
	{
		inline constexpr REL::ID Init{ 114988, 2208804 }; // Check
	}

	namespace NiAlphaProperty
	{
		inline constexpr REL::ID SetDestBlendMode{ 725249, 0 };  // Inlined in NG/AE
		inline constexpr REL::ID SetSrcBlendMode{ 976961, 0 };   // Inlined in NG/AE
		inline constexpr REL::ID SetTestMode{ 976961, 0 };       // Inlined in NG/AE
		inline constexpr REL::ID SetAlphaBlending{ 645586, 0 };  // Inlined in NG/AE
		inline constexpr REL::ID SetAlphaTesting{ 645586, 0 };   // Inlined in NG/AE
	}

	namespace NiCamera
	{
		inline constexpr REL::ID BoundInFrustum{ 781526, 2194525 };
		inline constexpr REL::ID WorldPtToScreenPt3{ 109441, 2270344 };
		inline constexpr REL::ID ViewPointToRay{ 460613, 2270338 };
	}

	namespace NiControllerManager
	{
		inline constexpr REL::ID GetNiControllerManager{ 1013515, 2271798 };
		inline constexpr REL::ID GetSequenceByName{ 846648, 2192808 };
	}

	namespace NiControllerSequence
	{
		inline constexpr REL::ID Activate{ 829033, 2271861 };
	}

	namespace NiMatrix3
	{
		inline constexpr REL::ID ToEulerAnglesXYZ1{ 34114, 2269806 };
		inline constexpr REL::ID ToEulerAnglesXZY2{ 1164218, 2269807 };
		inline constexpr REL::ID ToEulerAnglesYXZ3{ 272989, 2269808 };
		inline constexpr REL::ID ToEulerAnglesYZX4{ 963829, 2269809 };
		inline constexpr REL::ID ToEulerAnglesZYX5{ 511385, 2269810 };
		inline constexpr REL::ID ToEulerAnglesZXY6{ 606387, 2269824 };
		inline constexpr REL::ID FromEulerAnglesXYZ1{ 124665, 2269813 };
		inline constexpr REL::ID FromEulerAnglesXZY2{ 1319962, 2269814 };
		inline constexpr REL::ID FromEulerAnglesYXZ3{ 55761, 2269815 };
		inline constexpr REL::ID FromEulerAnglesYZX4{ 373803, 2269816 };
		inline constexpr REL::ID FromEulerAnglesZYX5{ 1569564, 2269817 };
		inline constexpr REL::ID FromEulerAnglesZXY6{ 326460, 2269825 };
	}

	namespace NiNode
	{
		inline constexpr REL::ID ChildrenVTable{ 390064 };
	}

	namespace NiPoint
	{
		namespace NiPoint3
		{
			inline constexpr REL::ID GetZAngleFromVector{ 1450064, 2269788 };
		}
	}

	namespace NiRefObject
	{
		inline constexpr REL::ID Objects{ 1161724, 2703471 };
	}

	namespace NiTexture
	{
		inline constexpr REL::ID SetAllowDegrade{ 948181, 2270148 };
	}

	namespace nsHUDNotifications
	{
		inline constexpr REL::ID IsQuestNotification{ 1291377, 2222465 }; // Check
		inline constexpr REL::ID IsObjectiveNotification{ 1025216, 2222466 }; // Check
		inline constexpr REL::ID IsLocationDiscoveredNotification{ 759615, 2222467 }; // Check
	}

	namespace nsHUDTypes
	{
		namespace NotificationInfo
		{
			inline constexpr REL::ID ctor{ 283986, 2223292 }; // Check
		}
	}

	namespace nsStatsMenuUtils
	{
		inline constexpr REL::ID GetEffectDisplayInfo{ 294691, 2224586 };
	}

	namespace PerkPointIncreaseEvent
	{
		inline constexpr REL::ID GetEventSource{ 685859, 2697359, 4804734 };
	}

	namespace PerkUtilities
	{
		inline constexpr REL::ID RemoveGrenadeTrajectory{ 672186, 2233303 };
	}

	namespace PipboyDataManager
	{
		inline constexpr REL::ID Singleton{ 1178971, 2689086, 4796372 };
	}

	namespace PipboyDataGroup
	{
		inline constexpr REL::ID LockDataGroup{ 287528, 2225147 }; // Check
		inline constexpr REL::ID UnlockDataGroup{ 1165260, 2225148 }; // Check
	}

	namespace PipboyInventoryData
	{
		inline constexpr REL::ID AddItemCardInfoEntry{ 1191786, 2225267 };
		inline constexpr REL::ID BaseAddItemCardInfoEntry{ 1150364, 2225270 };
		inline constexpr REL::ID InitializeItem{ 482276, 2225264 }; // Check
		inline constexpr REL::ID PopulateItemCardInfo{ 54211, 2225266 };
		inline constexpr REL::ID QueueItemCardRepopulate{ 1034299, 2225311 }; // Check
		inline constexpr REL::ID RepopulateItemCardOnSection{ 892255, 2225279 };
	}

	namespace PipboyInventoryMenu
	{
		inline constexpr REL::ID UpdateData{ 762897, 2224143 };
		inline constexpr REL::ID SetQuickkey{ 539741, 2224159 };
	}

	namespace PipboyInventoryUtils
	{
		inline constexpr REL::ID DoSlotsOverlap{ 1035436, 2225230 };
		inline constexpr REL::ID FillDamageTypeInfo{ 928518, 2225234 };
		inline constexpr REL::ID FillResistTypeInfo{ 1578434, 2225235 };
	}

	namespace PipboyLightEvent
	{
		inline constexpr REL::ID GetEventSource{ 1140080, 2696280, 4803571 };
	}

	namespace PipboyLogMenu
	{
		inline constexpr REL::ID UpdateData{ 672256, 2224052 };
	}

	namespace PipboyManager
	{
		inline constexpr REL::ID Singleton{ 553234, 2691945, 4799238 };
		inline constexpr REL::ID AddMenuToPipboy{ 394568, 2225453 };
		inline constexpr REL::ID ClosedownPipboy{ 731410, 2225480 };
		inline constexpr REL::ID EnablePipboyShader{ 662519, 2225484 };
		inline constexpr REL::ID InitPipboy{ 1477369, 2225479 };
		inline constexpr REL::ID LowerPipboy{ 1444875, 2225454 };
		inline constexpr REL::ID OnPipboyCloseAnim{ 1231000, 2225457 };
		inline constexpr REL::ID OnPipboyCloseAnimFailed{ 1362084, 2225459 };
		inline constexpr REL::ID OnPipboyClosed{ 592088, 2225458 };
		inline constexpr REL::ID OnPipboyOpenAnim{ 1500318, 2225448 };
		inline constexpr REL::ID OnPipboyOpenAnimFailed{ 702357, 2225449 };
		inline constexpr REL::ID OnPipboyOpened{ 1299608, 2225450 };
		inline constexpr REL::ID PlayItemAnimOnClose{ 377837, 2225461 };
		inline constexpr REL::ID PlayPipboyCloseAnim{ 273927, 2225456 };
		inline constexpr REL::ID PlayPipboyGenericOpenAnim{ 809076, 2225447 };
		inline constexpr REL::ID PlayPipboyLoadHolotapeAnim{ 477096, 2225446 };
		inline constexpr REL::ID PlayPipboyOpenAnim{ 663900, 2225444 };
		inline constexpr REL::ID PlayPipboyOpenTerminalAnim{ 743427, 2225445 };
		inline constexpr REL::ID ProcessLoweringReason{ 302903, 2225486 };
		inline constexpr REL::ID QPipboyActive{ 470886, 2225460 };
		inline constexpr REL::ID RaisePipboy{ 726763, 2225455 };
		inline constexpr REL::ID RefreshPipboyRenderSurface{ 81339, 2225478 };
		inline constexpr REL::ID StartAnimationGraphListening{ 714713, 2225490 };
		inline constexpr REL::ID StopAnimationGraphListening{ 621144, 2225491 };
		inline constexpr REL::ID UpdateCursorConstraint{ 900802, 2225488 };
	}

	namespace PipboyMapMenu
	{
		inline constexpr REL::ID UpdateData{ 92696, 2224074 };
	}

	namespace PipboyMenu
	{
		inline constexpr REL::ID RefreshMapMarkers{ 434114, 2224187 };
	}

	namespace PipboyObject
	{
		inline constexpr REL::ID AddMember{ 1499797, 2225699 };
	}

	namespace PipboyPerksMenu
	{
		inline constexpr REL::ID UpdateData{ 783380, 2224224 }; // Check
	}

	namespace PipboyPlayerInfoData
	{
		inline constexpr REL::ID UpdateCarryWeightData{ 338096, 2225788 };
	}

	namespace PipboyPlayerInfoMenu
	{
		inline constexpr REL::ID UpdateData{ 426990, 2224248 }; // Check
	}

	namespace PipboyPrimitiveValue
	{
		namespace uint32
		{
			inline constexpr REL::ID ctor{ 201797, 2225324 }; // Check
		}

		namespace boolean
		{
			inline constexpr REL::ID ctor{ 1158654, 2225327 }; // Check
		}
	}

	namespace PipboyQuestMenu
	{
		inline constexpr REL::ID UpdateData{ 1495929, 2224231 };
	}

	namespace PipboyRadioMenu
	{
		inline constexpr REL::ID UpdateData{ 713423, 2224242 };
	}

	namespace PipboySpecialMenu
	{
		inline constexpr REL::ID UpdateData{ 1426810, 2224256 };
	}

	namespace PipboyStatsMenu
	{
		inline constexpr REL::ID UpdateData{ 332518, 2224261 };
		inline constexpr REL::ID UpdateActiveEffects{ 236337, 2224262 }; // Check
	}

	namespace PipboySubMenu
	{
		inline constexpr REL::ID ProcessEvent{ 893703, 2224270 };
	}

	namespace PipboyValue
	{
		inline constexpr REL::ID ctor{ 531562, 2225915 }; // Check
	}

	namespace PipboyWorkshopMenu
	{
		inline constexpr REL::ID UpdateData{ 1370368, 2224273 };
	}

	namespace PlayerCamera
	{
		inline constexpr REL::ID Singleton{ 1171980, 2688801, 4796065 };
		inline constexpr REL::ID PopState{ 120998, 2248424 };
		inline constexpr REL::ID PushState{ 746523, 2248422 };
		inline constexpr REL::ID ToggleFreeCameraMode{ 224913, 2248368 };
		inline constexpr REL::ID SetState{ 858847, 2214742 };
		inline constexpr REL::ID StartFurnitureMode{ 10202, 2248373 };
		inline constexpr REL::ID StartPipboyMode{ 998069, 2248358 };
		inline constexpr REL::ID StopPipboyMode{ 811954, 2248359 };
		inline constexpr REL::ID QCameraEquals{ 839543, 2248421 };
	}

	namespace PlayerCharacter
	{
		namespace ScopedInventoryChangeMessageContext
		{
			inline constexpr REL::ID ctor{ 1512872, 2233292 };
			inline constexpr REL::ID dtor{ 542100, 2233293 };
		}

		inline constexpr REL::ID Singleton{ 303410, 2690919, 4798212 };
		inline constexpr REL::ID GetPlayerHandle{ 522947, 2698072 };
		inline constexpr REL::ID GetDifficultyLevel{ 922962, 2233056 };
		inline constexpr REL::ID IsGodMode{ 1032309, 2232986 };
		inline constexpr REL::ID IsHolotapePlaying{ 530826, 2233206 };
		inline constexpr REL::ID IsImmortal{ 500346, 2232988 };
		inline constexpr REL::ID IsPipboyLightOn{ 426550, 2233202 };
		inline constexpr REL::ID PauseHolotape{ 1567456, 2233208 };
		inline constexpr REL::ID PlayHolotape{ 1581042, 2233207 };
		inline constexpr REL::ID QueueFastTravel{ 556824, 2232918 };
		inline constexpr REL::ID RemoveLastUsedPowerArmor{ 1488486, 2233024 };
		inline constexpr REL::ID SelectPerk{ 1397326, 2232926 };
		inline constexpr REL::ID SetAIControlledPackage{ 1431972, 2233087 };
		inline constexpr REL::ID SetEscaping{ 25528, 2233142 };
		inline constexpr REL::ID SetVATSCriticalCount{ 327338, 2233219 };
		inline constexpr REL::ID ShowPipboyLight{ 1304102, 2233203 };
		inline constexpr REL::ID SetLastDialogueInput{ 696117, 2233190 };
		inline constexpr REL::ID ClearPrison{ 920390, 2233196 };
		inline constexpr REL::ID ReloadWeapon{ 458406, 2232907 }; // Check
		inline constexpr REL::ID SetPerkCount{ 616372, 2233187 };
		inline constexpr REL::ID HasLOSToTarget{ 449775, 2233004 };
		inline constexpr REL::ID TryUnlockObject{ 1341574, 2233040 }; // Check
	}

	namespace PlayerControls
	{
		inline constexpr REL::ID Singleton{ 544871, 2692013, 4799306 };
		inline constexpr REL::ID DoAction{ 818081, 2234796 };
		inline constexpr REL::ID DoRegisterHandler{ 177801, 2234822 };
	}

	namespace PlayerCrosshairModeEvent
	{
		inline constexpr REL::ID GetEventSource{ 1231665, 2694517, 4801808 };
	}

	namespace PowerArmor
	{
		inline constexpr REL::ID ActorInPowerArmor{ 1176757, 2219437 };
		inline constexpr REL::ID GetArmorKeyword{ 961172, 2194743 };
		inline constexpr REL::ID GetBatteryKeyword{ 1493537, 2194740 };
		inline constexpr REL::ID GetDefaultBatteryObject{ 1279247, 2194761 };
		inline constexpr REL::ID IsPowerArmorBattery{ 1012910, 2219422 };
		inline constexpr REL::ID SyncFurnitureVisualsToInventory{ 1078979, 2219453 };
		inline constexpr REL::ID fNewBatteryCapacity{ 1353498 };
	}

	namespace PowerArmorGeometry
	{
		inline constexpr REL::ID Singleton{ 1365745, 2694441, 4801732 };
		inline constexpr REL::ID HidePipboyPAGeometry{ 976332, 2248877 };
		inline constexpr REL::ID ShowPipboyPAGeometry{ 19066, 2248876 };
	}

	namespace PowerArmorLightData
	{
		inline constexpr REL::ID GetEventSource{ 120809, 2701547 };
	}

	namespace PowerArmorModMenu
	{
		inline constexpr REL::ID ShowBuildFailureMessage{ 1215152, 2224322 }; // Check
	}

	namespace PowerUtils
	{
		inline constexpr REL::ID ItemIsPowerConnection{ 17704, 2195078, 2195078 };
		inline constexpr REL::ID ItemIsPowerReceiver{ 210626, 2195060, 2195060 };
	}

	namespace ProcessLists
	{
		inline constexpr REL::ID Singleton{ 1569706, 2688869, 4796160 };
		inline constexpr REL::ID AreHostileActorsNear{ 1053584, 2234105 };
		inline constexpr REL::ID IsActorTargetingREFinPackage{ 559542, 2234033 };
		inline constexpr REL::ID RequestHighestDetectionLevelAgainstActor{ 1036693, 2234111 };
	}

	namespace REFR_LOCK
	{
		inline constexpr REL::ID GetLevel{ 689812, 2191019 }; // Check
		inline constexpr REL::ID GetLockLevel{ 782953, 2191018 };
		inline constexpr REL::ID SetLocked{ 157617, 2191020 };
		inline constexpr REL::ID IsBroken{ 1034859, 2191021 }; // Check
		inline constexpr REL::ID NumericValueToEnum{ 1380232, 2191023 }; // Check
		inline constexpr REL::ID IsInaccessible{ 502938, 2191022 }; // Check
	}

	namespace SavefileMetadata
	{
		inline constexpr REL::ID FillDataFromFileName{ 116131, 2228156 };
	}

	namespace ScrapHeap
	{
		inline constexpr REL::ID Allocate{ 1085394, 2267983 };
		inline constexpr REL::ID Deallocate{ 923307, 2267984 };
	}

	namespace ScreenSplatter
	{
		inline constexpr REL::ID Clear{ 1478405, 2194783 };
		inline constexpr REL::ID Update{ 907893, 2194781 };
	}

	namespace SCRIPT_FUNCTION
	{
		inline constexpr REL::ID ConsoleFunctions{ 901511 }; // Same
		inline constexpr REL::ID ScriptFunctions{ 75173 }; // Same
		inline constexpr REL::ID CompileFunction{ 638606, 2204343 };
	}

	namespace Script
	{
		inline constexpr REL::ID ParseParameters{ 1607, 2204298 };
		inline constexpr REL::ID CompileAndRun{ 526625, 2204287 };
		inline constexpr REL::ID GetProcessScripts{ 44950, 2204310 };
		inline constexpr REL::ID SetProcessScripts{ 1188642, 2204309 };
	}

	namespace SendHUDMessage
	{
		inline constexpr REL::ID PopHUDMode{ 1495042, 2222444 };
		inline constexpr REL::ID PushHUDMode{ 1321764, 2222443 };
		inline constexpr REL::ID SetPowerArmorMode{ 361745, 2222459 };
		inline constexpr REL::ID ShowHUDMessage{ 1163005, 2222440 };
	}

	namespace Setting
	{
		namespace INISettingCollection
		{
			inline constexpr REL::ID Singleton{ 791183, 2704108 };
		}

		namespace INIPrefSettingCollection
		{
			inline constexpr REL::ID Singleton{ 767844, 2703234 };
		}

		namespace GameSettingCollection
		{
			inline constexpr REL::ID Singleton{ 8308, 2690301, 4797590 };
			inline constexpr REL::ID InitCollection{ 948832, 2188690 };
		}
	}

	namespace SitWaitMenu
	{
		inline constexpr REL::ID OnEnterFurniture{ 562238, 2249503 };
		inline constexpr REL::ID OnExitFurniture{ 454795, 2249504 };
	}

	namespace Sky
	{
		inline constexpr REL::ID Singleton{ 484694, 2192448 };
		inline constexpr REL::ID ForceWeather{ 698558, 2208861 };
		inline constexpr REL::ID ResetWeather{ 6511, 2208860 };
	}

	namespace SplineUtils
	{
		inline constexpr REL::ID DisconnectSpline{ 750682, 2195074 };
		inline constexpr REL::ID ConnectSpline{ 59311, 2195073 };
	}

	namespace StartMenuBase
	{
		inline constexpr REL::ID GetMenuDifficultyLevel{ 1089336, 2224540 }; // Check
	}

	namespace ILStringMap
	{
		inline constexpr REL::ID Map{ 1497866, 2661471 };
	}

	namespace SubtitleManager
	{
		inline constexpr REL::ID Singleton{ 740511, 2689088, 4796374 };
		inline constexpr REL::ID RWLock{ 589656, 2701704 };
		inline constexpr REL::ID ShowSubtitle{ 875508, 2249542 }; // Check
		inline constexpr REL::ID UpdateSubtitles{ 381778, 2249545 }; // Check
		inline constexpr REL::ID DisplayNextSubtitle{ 102120, 2249551 }; // Check
	}

	namespace SWFToCodeFunctionHandler
	{
		inline constexpr REL::ID MapCodeMethodToASFunction{ 1263128, 2287419 };
		inline constexpr REL::ID RegisterCodeObject{ 67637, 2287415 };
	}

	namespace TaskQueueInterface
	{
		inline constexpr REL::ID Singleton{ 7491, 2698331 };
		inline constexpr REL::ID QueueClosePipboy{ 69886, 2229289 };
		inline constexpr REL::ID QueueRebuildBendableSpline{ 198419, 2229302 };
		inline constexpr REL::ID QueueShow1stPerson{ 994377, 2229268 };
		inline constexpr REL::ID QueueShowPipboy{ 1133684, 2229288 };
		inline constexpr REL::ID QueueUpdate3D{ 581890, 2229234 };
		inline constexpr REL::ID QueueWeaponFire{ 15449, 2229186 };
	}

	namespace TerminalHacked
	{
		inline constexpr REL::ID GetEventSource{ 425579, 2233751 };
	}

	namespace TES
	{
		inline constexpr REL::ID Singleton{ 1194835, 2698044 };
	}

	namespace TESActivateEvent
	{
		inline constexpr REL::ID GetEventSource{ 166230, 2201819 };
	}

	namespace TESActorBaseData
	{
		inline constexpr REL::ID GetLevel{ 151866, 2192891 };
	}

	namespace TESAmmo
	{
		inline constexpr REL::ID GetReloadsWithAmmoRef{ 1035622, 2197864 };
	}

	namespace TESAudio
	{
		namespace ScriptedMusicState
		{
			inline constexpr REL::ID Singleton{ 1216761, 2691985, 4799278 };
			inline constexpr REL::ID Remove{ 544747, 2226976 };
		}
	}

	namespace TESBoundObject
	{
		inline constexpr REL::ID ApplyMods{ 113585, 2198325 };
	}

	namespace TESCellAttachDetachEvent
	{
		inline constexpr REL::ID GetEventSource{ 311270, 2201823 };
	}

	namespace TESCellFullyLoadedEvent
	{
		inline constexpr REL::ID GetEventSource{ 1534478, 2201824 };
	}

	namespace TESCondition
	{
		inline constexpr REL::ID IsTrue{ 1275731, 2211989 };
		inline constexpr REL::ID IsTrueForAllButFunction{ 1182457, 0 };  // Inlined in NG/AE
		inline constexpr REL::ID ClearAllConditionItems{ 757713, 2211988 };
	}

	namespace TESConditionItem
	{
		inline constexpr REL::ID GetComparisonValue{ 1373349, 2212007 };
		inline constexpr REL::ID IsTrue1{ 1453240, 2212008 };
		inline constexpr REL::ID IsTrue2{ 43452, 2212009 };
	}

	namespace TESContainerChangedEvent
	{
		inline constexpr REL::ID GetEventSource{ 242538, 2201832 };
	}

	namespace TESDataHandler
	{
		inline constexpr REL::ID Singleton{ 711558, 2688883, 4796135 };
		inline constexpr REL::ID AddFormToDataHandler{ 350112, 2192271 };
		inline constexpr REL::ID CheckModsLoaded{ 1432894, 2192323 };
		inline constexpr REL::ID CreateReferenceAtLocation{ 500304, 2192301 };
		inline constexpr REL::ID IsFormIDInuse{ 1448838, 2192351 };
	}

	namespace TESDeathEvent
	{
		inline constexpr REL::ID GetEventSource{ 1465690, 2201833 };
	}

	namespace TESDescription
	{
		inline constexpr REL::ID GetDescription{ 523613, 2193019 };
	}

	namespace TESEnterSneakingEvent
	{
		inline constexpr REL::ID GetEventSource{ 28138, 2201837 };
	}

	namespace TESFile
	{
		inline constexpr REL::ID CloseTES{ 766555, 2192491 };
		inline constexpr REL::ID GetChunkData{ 188910, 2192538 };
		inline constexpr REL::ID GetTESChunk{ 641361, 2192536 };
		inline constexpr REL::ID NextChunk{ 1252764, 2192537 };
		inline constexpr REL::ID NextForm{ 644374, 2192527 };
		inline constexpr REL::ID NextGroup{ 339855, 2192522 };
		inline constexpr REL::ID OpenTES{ 728465, 2192490 };
	}

	namespace TESForm
	{
		inline constexpr REL::ID FormSortFunc{ 705530, 0 }; // Inlined in NG/AE
		inline constexpr REL::ID AddCompileIndex{ 1315637, 2193152 };
		inline constexpr REL::ID AllForms{ 422985, 2689178, 4796465 };
		inline constexpr REL::ID AllFormsMapLock{ 691815, 2689189, 4796476 };
		inline constexpr REL::ID AllFormsByEditorID{ 642758, 2689179, 4796466 };
		inline constexpr REL::ID AllFormsEditorIDMapLock{ 910917, 2689190, 4796477 };
		inline constexpr REL::ID GetFile{ 1376557, 2193103 };
		inline constexpr REL::ID GetFormByNumericID{ 796114, 2193092 }; // Check
		inline constexpr REL::ID GetFormEnumString{ 1309967 }; // Same
		inline constexpr REL::ID GetFormTypeFromString{ 565203, 2193108 };
		inline constexpr REL::ID SetTemporary{ 482454, 2193125 };
	}

	namespace TESFormDeleteEvent
	{
		inline constexpr REL::ID GetEventSource{ 1396562, 2201842 };
	}

	namespace TESFullName
	{
		inline constexpr REL::ID SparseFullNameMap{ 226372, 2661402 };
	}

	namespace TESFurniture
	{
		inline constexpr REL::ID GetContainer{ 1049933, 2198043 };
	}

	namespace TESFurnitureEvent
	{
		inline constexpr REL::ID GetEventSource{ 678665, 2201844 };
	}

	namespace TESHarvestEvent
	{
		inline constexpr REL::ID GetEventSource{ 11738, 2193351 };
	}

	namespace TESHealthForm
	{
		inline constexpr REL::ID GetFormHealth{ 1515099, 2193227 };
	}

	namespace TESHitEvent
	{
		inline constexpr REL::ID GetEventSource{ 1411899, 2201886 };
	}

	namespace TESInitScriptEvent
	{
		inline constexpr REL::ID GetEventSource{ 1542080, 2201846 };
	}

	namespace TESLeveledList
	{
		inline constexpr REL::ID AddLeveledObject{ 1163308, 2193258 };
		inline constexpr REL::ID AddScriptAddedLeveledObject{ 860553, 2193269 };
		inline constexpr REL::ID CalculateCurrentFormList{ 603811, 2193259 };
		inline constexpr REL::ID CalculateCurrentFormListForRef{ 507405, 2193260 };
		inline constexpr REL::ID GetUseAll{ 233875, 2193253 };
	}

	namespace TESLoadGameEvent
	{
		inline constexpr REL::ID GetEventSource{ 823570, 2201848 };
	}

	namespace TESLocationClearedEvent
	{
		inline constexpr REL::ID GetEventSource{ 1372013, 2201849 };
	}

	namespace TESMagicEffectApplyEvent
	{
		inline constexpr REL::ID GetEventSource{ 1327824, 2201851 };
	}

	namespace TESNPC
	{
		inline constexpr REL::ID AlternateHeadPartListMap{ 1306546, 2662368 };
		inline constexpr REL::ID GetSex{ 1257181, 2207107 };
		inline constexpr REL::ID GetFacialBoneMorphIntensity{ 272217, 2207416 };
		inline constexpr REL::ID SetHairColor{ 1201742, 2207426 }; // Check
		inline constexpr REL::ID GetShortName{ 1221705, 2207405 };
	}

	namespace TESObjectARMO
	{
		inline constexpr REL::ID Protects{ 1028523, 2198535 };
	}

	namespace TESObjectCELL
	{
		inline constexpr REL::ID GetbhkWorld{ 1326073, 2200260 };
		inline constexpr REL::ID GetCantWaitHere{ 376940, 2200287 };
		inline constexpr REL::ID GetDataX{ 445210, 2200213 };
		inline constexpr REL::ID GetDataY{ 1322816, 2200214 };
		inline constexpr REL::ID GetEncounterZone{ 1414637, 2200242 };
		inline constexpr REL::ID GetLocation{ 868663, 2200179 };
		inline constexpr REL::ID GetOwner{ 910422, 2200236 };
		inline constexpr REL::ID GetRegionList{ 1565031, 2200265 };
		inline constexpr REL::ID Pick{ 434717, 2200263 };
		inline constexpr REL::ID SetCullCellMarkers{ 192259, 2192259 };
		inline constexpr REL::ID UpdateAllRefsLoaded{ 374552, 2200415 };
		inline constexpr REL::ID AttatchReference3D{ 125567, 2200620 };
		inline constexpr REL::ID RemoveReference{ 650855, 2200299 };
		inline constexpr REL::ID UpdateAllDecals{ 283071, 2200643 };
		inline constexpr REL::ID DefaultWater{ 289864, 2691845, 4799138 };
	}

	namespace TESObjectCONT
	{
		inline constexpr REL::ID GetActivateText{ 2917378, 198653 }; // Check
	}

	namespace TESObjectDOOR
	{
		inline constexpr REL::ID GetActivateText{ 978619, 2198690 }; // Check
		inline constexpr REL::ID CalculateDoFavor{ 1428007, 2198692 }; // Check
	}

	namespace TESObjectLoadedEvent
	{
		inline constexpr REL::ID GetEventSource{ 609604, 2201853 };
	}

	namespace TESObjectREFR
	{
		inline constexpr REL::ID ActivateRef{ 753531, 2201147 };
		inline constexpr REL::ID AddInventoryItem{ 78185, 2200949 };
		inline constexpr REL::ID AddKeyword{ 640674, 2200860 };
		inline constexpr REL::ID AddLockChange{ 1578706, 2200731 };
		inline constexpr REL::ID ApplyArtObject{ 357908, 2205200 };
		inline constexpr REL::ID ApplyEffectShader{ 652173, 2205201 };
		inline constexpr REL::ID Enable{ 1396707, 2201150 };
		inline constexpr REL::ID FindReferenceFor3D{ 766937, 2201082 };
		inline constexpr REL::ID GetCurrentLocation{ 1135470, 2201163 };
		inline constexpr REL::ID GetDisplayFullName{ 1212056, 2201126 };
		inline constexpr REL::ID GetEditorDead{ 941388, 2200781 };
		inline constexpr REL::ID GetOwner{ 1323437, 2202616 };
		inline constexpr REL::ID GetGoldAmount{ 564356, 2200923 };
		inline constexpr REL::ID GetHandle{ 1573130, 2201196 }; // Check
		inline constexpr REL::ID GetHasOwner{ 1016277, 2202622 };
		inline constexpr REL::ID GetInventoryObjectCount{ 333415, 2200939 };
		inline constexpr REL::ID GetLinkedRef{ 897287, 2202683 };
		inline constexpr REL::ID GetLock{ 305507, 2202648 }; // Check
		inline constexpr REL::ID GetWeightInContainer{ 1377567, 2201001 };
		inline constexpr REL::ID HasContainer{ 1213017, 2201022 };
		inline constexpr REL::ID IsAnOwner{ 933798, 2202635 };
		inline constexpr REL::ID IsCrimeToActivate{ 836011, 2201180 };
		inline constexpr REL::ID IsLeveledCreature{ 1341859, 2202655 };
		inline constexpr REL::ID MarkAsDeleted{ 192661, 2201156 };
		inline constexpr REL::ID MoveRefToNewSpace{ 629658, 2201149 };
		inline constexpr REL::ID RemoveKeyword{ 281170, 2200861 };
		inline constexpr REL::ID SetAngleOnReference{ 1049748, 2201134 };
		inline constexpr REL::ID SetLinkedRef{ 192840, 2202684 };
		inline constexpr REL::ID SetLocationOnReference{ 1101832, 2201138 };
		inline constexpr REL::ID SetWantsDelete{ 761346, 2201199 };
		inline constexpr REL::ID RebuildBendableSpline{ 340319, 2201119 };
		inline constexpr REL::ID GetItemCount{ 635042, 2200996 };
		inline constexpr REL::ID UpdateReference3D{ 1568075, 2201071 };
		inline constexpr REL::ID GetObjectCenter{ 777738, 2201092 };
		inline constexpr REL::ID SetScale{ 817930, 2200893 };
		inline constexpr REL::ID IsMarker{ 364958, 2201157 };
		inline constexpr REL::ID IsDecalRef{ 686485, 2200794 };
		inline constexpr REL::ID UpdateDynamicNavmesh{ 1518094, 2201206 };
		inline constexpr REL::ID GetMapMarkerData{ 253640, 2202644 }; // Check
		inline constexpr REL::ID GetRelevantWaterHeight{ 6866, 2201189 };
		inline constexpr REL::ID CanBeMoved{ 683719, 2200898 };
	}

	namespace TESObjectWEAP
	{
		inline constexpr REL::ID GetMeleeAttackSpeed{ 817670, 2198957 };
		inline constexpr REL::ID GetMeleeAttackSpeedLabel{ 178784, 2198959 };
		inline constexpr REL::ID Fire{ 1056037, 2198960 }; // Check
	}

	namespace TESQuest
	{
		inline constexpr REL::ID SetStage{ 952799, 2207743 };
		inline constexpr REL::ID GetAliasedRef{ 847223, 2207810 };
	}

	namespace TESResponse
	{
		inline constexpr REL::ID GetResponseText{ 992447, 2208288 };
		inline constexpr REL::ID GetSpeakerIdle{ 606043, 2208293 };
	}

	namespace TESSpellList
	{
		inline constexpr REL::ID AddSpell{ 1312083, 2193395 };
	}

	namespace TESSwitchRaceCompleteEvent
	{
		inline constexpr REL::ID GetEventSource{ 976262, 2201874 };
	}

	namespace TESTopic
	{
		inline constexpr REL::ID InitDialogueItem{ 49777, 2208360 };
	}

	namespace TESTopicInfo
	{
		inline constexpr REL::ID GetParentInfoGroup{ 163538, 2208435 };
		inline constexpr REL::ID GetChallengeLevel{ 613016, 2208441 };
		inline constexpr REL::ID GetSuccessLevel{ 1023955, 2208444 };
		inline constexpr REL::ID StartSceneOnEnd{ 376042, 2208466 };
		inline constexpr REL::ID GetScene{ 820897, 2208453 };
		inline constexpr REL::ID StartScene{ 269139, 2208469 };
		inline constexpr REL::ID GetSpeaker{ 1048628, 2208449 };
	}

	namespace TESValueForm
	{
		inline constexpr REL::ID GetFormValue{ 885783, 2193435 };
	}

	namespace TESWaterDisplacement
	{
		inline constexpr REL::ID SetStencilBit{ 705016, 2213923 }; // Check
	}

	namespace TESWeightForm
	{
		inline constexpr REL::ID GetFormWeight{ 1321341, 2193446 };
	}

	namespace TESWorldSpace
	{
		inline constexpr REL::ID DefaultWater{ 289864, 2691845, 4799138 };
		inline constexpr REL::ID GetSkyCell{ 903020, 2202924 }; // Check
	}

	namespace UI
	{
		inline constexpr REL::ID Singleton{ 548587, 2689028, 4796314 };
		inline constexpr REL::ID CustomRendererHasQuads{ 1401451, 2284757 };
		inline constexpr REL::ID GetMenuMapRWLock{ 578487, 2707105 };
		inline constexpr REL::ID RefreshCursor{ 1436639, 2284772 };
		inline constexpr REL::ID RegisterMenu{ 1519575, 2284766 };
		inline constexpr REL::ID UpdateControllerType{ 175796, 2284768 };
	}

	namespace UIAdvanceMenusFunctionCompleteEvent
	{
		inline constexpr REL::ID GetEventSource{ 1067039, 2694428, 4801719 };
	}

	namespace UIMessageQueue
	{
		inline constexpr REL::ID Singleton{ 82123, 2689091, 4796377 };
		inline constexpr REL::ID AddMessage{ 133053, 2284929 }; // Check
	}

	namespace UIUtils
	{
		inline constexpr REL::ID GetComparisonItems{ 593818, 0 };  // Inlined in NG/AE
		inline constexpr REL::ID PlayPipboySound{ 1320952, 2249706 };
		inline constexpr REL::ID PlayMenuSound{ 1227993, 2249707 };
		inline constexpr REL::ID UpdateGamepadDependentButtonCodes{ 190238, 2249714, 4483350 };
		inline constexpr REL::ID ShowCraftingMenu{ 877836, 2249718 };
		inline constexpr REL::ID HasRequiredInventoryForCraftingMenu{ 639634, 2249717 };
	}

	namespace VATS
	{
		inline constexpr REL::ID Singleton{ 570121, 2690444, 4797733 };
		inline constexpr REL::ID CanActivateCriticals{ 1057603, 2237208 }; // Check
	}

	namespace WorkbenchMenuBase
	{
		inline constexpr REL::ID UpdateOptimizedAutoBuildInv{ 769581, 2224955 };
		inline constexpr REL::ID QCurrentModChoiceData{ 583103, 2224958 }; // Check
		inline constexpr REL::ID ShowBuildFailureMessage{ 316889, 2224959 }; // Check
	}

	namespace Workshop
	{
		namespace PlacementItemData
		{
			inline constexpr REL::ID Set{ 1460935, 2195643 };
		}

		namespace WorkshopMenuNode
		{
			inline constexpr REL::ID FindAndSetSelectedNode{ 1309368, 2195022 };
		}

		inline constexpr REL::ID FindNearestValidWorkshop{ 905705, 2194970 };
		inline constexpr REL::ID FreeBuild{ 1583365, 2194924 };
		inline constexpr REL::ID GetSelectedWorkshopMenuNode{ 763948, 2195024 };
		inline constexpr REL::ID InitializePlacementReference{ 1577199, 0 }; // Inlined in NG/AE
		inline constexpr REL::ID IsLocationWithinBuildableArea{ 990965, 2194956 };
		inline constexpr REL::ID PlaceCurrentReference{ 1058211, 2195155 };
		inline constexpr REL::ID RegisterForItemDestroyed{ 1367004, 2194930 };
		inline constexpr REL::ID RegisterForItemMoved{ 835323, 2194932 };
		inline constexpr REL::ID RegisterForItemPlaced{ 849008, 2194926 };
		inline constexpr REL::ID RegisterForWorkshopModeEvent{ 275798, 2194946 };
		inline constexpr REL::ID RequestExitWorkshop{ 209891, 2195135 };
		inline constexpr REL::ID ScrapReference{ 636327, 2195125 };
		inline constexpr REL::ID SetSelectedEditItem{ 2562, 2195119 };
		inline constexpr REL::ID StartWorkshop{ 171771, 2195134 };
		inline constexpr REL::ID ToggleEditMode{ 1243386, 2195130 };
		inline constexpr REL::ID UnregisterForItemDestroyed{ 1101379, 2194931 };
		inline constexpr REL::ID UnregisterForItemMoved{ 569432, 2194933 };
		inline constexpr REL::ID UnregisterForItemPlaced{ 583255, 2194927 };
		inline constexpr REL::ID UnregisterForWorkshopModeEvent{ 9236, 2194947 };
		inline constexpr REL::ID UpdateActiveEdit{ 69261, 2195210 };
		inline constexpr REL::ID WorkshopCanShowRecipe{ 239190, 2194978 }; // old ID wrong: 2195115
		inline constexpr REL::ID CurrentPlacementItemData{ 1279207, 2689973, 4797261 };
		inline constexpr REL::ID CurrentRow{ 833923, 2689868, 4797160 };
		inline constexpr REL::ID PlacementItem{ 526727, 2689906, 4797235 };
	}

	namespace WorkshopMenu
	{
		inline constexpr REL::ID CheckAndSetItemForPlacement{ 1541862, 2224991 };
		inline constexpr REL::ID UpdateButtonText{ 1089189, 2224992 };
	}

	inline constexpr REL::ID NiFree{ 242362, 2268539 };
	inline constexpr REL::ID NiMalloc{ 974443, 2268535 };
	inline constexpr REL::ID RTDynamicCast{ 84112, 2725673, 4818455 };
	inline constexpr REL::ID IsPlayerInDialogue{ 60126, 2188686 };
}

namespace Scaleform::ID
{
	namespace GFx::ASStringManager
	{
		inline constexpr REL::ID CreateStringNode{ 419974, 2290014 };
	}

	namespace GFx::Loader
	{
		inline constexpr REL::ID CreateMovie{ 912291, 2284723 };
	}

	namespace GFx::Movie
	{
		inline constexpr REL::ID Release{ 404814, 2287230 };
	}

	namespace GFx::Value
	{
		inline constexpr REL::ID ObjectAddRef{ 244786, 2286228 };
		inline constexpr REL::ID ObjectRelease{ 856221, 2286229 };
		inline constexpr REL::ID HasMember{ 788691, 2286078 };
		inline constexpr REL::ID GetArraySize{ 254218, 2285791 };
		inline constexpr REL::ID GetMember{ 1517430, 2285936, 4494126 };
		inline constexpr REL::ID GetElement{ 827659, 2285881 };
		inline constexpr REL::ID SetElement{ 433707, 2286575 };
		inline constexpr REL::ID SetMember{ 1360149, 2286589 };
		inline constexpr REL::ID Invoke{ 655847, 2286101 };
		inline constexpr REL::ID PushBack{ 1330475, 2286424 };
		inline constexpr REL::ID RemoveElements{ 1286586, 2286475 };
		inline constexpr REL::ID VisitMembers{ 1276961, 2286786 };
		inline constexpr REL::ID GetDisplayInfo{ 498814, 2285873 };
	}

	namespace Memory
	{
		inline constexpr REL::ID SetGlobalHeap{ 939898, 2707353 };
		inline constexpr REL::ID GetGlobalHeap{ 939898, 2707353 };
	}

	namespace SysAlloc
	{
		inline constexpr REL::ID InitHeapEngine{ 1047970, 2284532, 4493927 };
		inline constexpr REL::ID ShutdownHeapEngine{ 1207169, 2284536 };
	}
}
