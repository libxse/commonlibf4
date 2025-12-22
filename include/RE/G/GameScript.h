#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/B/BSIntrusiveRefCounted.h"
#include "RE/B/BSScript_CompiledScriptLoader.h"
#include "RE/B/BSScript_ErrorLogger.h"
#include "RE/B/BSScript_IClientVM.h"
#include "RE/B/BSScript_IHandleReaderWriter.h"
#include "RE/B/BSScript_IObjectHandlePolicy.h"
#include "RE/B/BSScript_ISavePatcherInterface.h"
#include "RE/B/BSScript_IStackCallbackSaveInterface.h"
#include "RE/B/BSScript_IVirtualMachine.h"
#include "RE/B/BSScript_Internal_IProfilePolicy.h"
#include "RE/B/BSScript_MergedBoundScript.h"
#include "RE/B/BSScript_ObjectBindPolicy.h"
#include "RE/B/BSScript_SimpleAllocMemoryPagePolicy.h"
#include "RE/B/BSScript_Variable.h"
#include "RE/B/BSSpinLock.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTEvent.h"
#include "RE/B/BSTFreeList.h"
#include "RE/B/BSTHashMap.h"
#include "RE/B/BSTMessageQueue.h"
#include "RE/B/BSTSingleton.h"
#include "RE/B/BSTSmartPointer.h"
#include "RE/B/BSTTuple.h"
#include "RE/B/BSTimer.h"
#include "RE/M/MemoryManager.h"

namespace RE
{
	template <class F>
	using BSTThreadScrapFunction = std::function<F>;

	namespace BSScript
	{
		class IStore;
		class IVirtualMachine;
		class IVMDebugInterface;
		class IVMSaveLoadInterface;
		class Object;
		class StatsEvent;
	}

	namespace PlayerDifficultySettingChanged
	{
		class Event;
	}

	namespace RadioManager
	{
		class PipboyTransmitterDetectionEvent;
	}

	namespace Workshop
	{
		class ItemDestroyedEvent;
		class ItemGrabbedEvent;
		class ItemMovedEvent;
		class ItemPlacedEvent;
		class ItemRepairedEvent;
		class PowerOffEvent;
		class PowerOnEvent;
		class WorkshopModeEvent;
	}

	class BGSLocationLoadedEvent;
	class BGSOnPlayerCompanionDismiss;
	class BGSOnPlayerCreateRobotEvent;
	class BGSOnPlayerEnterVertibirdEvent;
	class BGSOnPlayerFallLongDistances;
	class BGSOnPlayerFireWeaponEvent;
	class BGSOnPlayerHealTeammateEvent;
	class BGSOnPlayerModArmorWeaponEvent;
	class BGSOnPlayerModRobotEvent;
	class BGSOnPlayerSwimmingEvent;
	class BGSOnPlayerUseWorkBenchEvent;
	class BGSOnSpeechChallengeAvailable;
	class BGSRadiationDamageEvent;
	class BSLog;
	class BSStorage;
	class InputEnableLayerDestroyedEvent;
	class PositionPlayerEvent;
	class TESActivateEvent;
	class TESActiveEffectApplyRemoveEvent;
	class TESActorLocationChangeEvent;
	class TESBookReadEvent;
	class TESCellAttachDetachEvent;
	class TESCellFullyLoadedEvent;
	class TESCombatEvent;
	class TESCommandModeCompleteCommandEvent;
	class TESCommandModeEnterEvent;
	class TESCommandModeExitEvent;
	class TESCommandModeGiveCommandEvent;
	class TESConsciousnessEvent;
	class TESDeathEvent;
	class TESDeferredKillEvent;
	class TESDestructionStageChangedEvent;
	class TESEnterBleedoutEvent;
	class TESEnterSneakingEvent;
	class TESEscortWaitStartEvent;
	class TESEscortWaitStopEvent;
	class TESExitFurnitureEvent;
	class TESFile;
	class TESFormDeleteEvent;
	class TESFormIDRemapEvent;
	class TESFurnitureEvent;
	class TESGrabReleaseEvent;
	class TESHitEvent;
	class TESInitScriptEvent;
	class TESLimbCrippleEvent;
	class TESLoadGameEvent;
	class TESLocationClearedEvent;
	class TESLockChangedEvent;
	class TESMagicEffectApplyEvent;
	class TESObjectLoadedEvent;
	class TESObjectREFRTranslationEvent;
	class TESOnPCDialogueTargetEvent;
	class TESOpenCloseEvent;
	class TESPickpocketFailedEvent;
	class TESQuestInitEvent;
	class TESResetEvent;
	class TESResolveNPCTemplatesEvent;
	class TESSellEvent;
	class TESSpellCastEvent;
	class TESSwitchRaceCompleteEvent;
	class TESTrapHitEvent;
	class TESTriggerEnterEvent;
	class TESTriggerLeaveEvent;
	class TESUniqueIDChangeEvent;
	class WorkshopNPCTransferEvent;

	namespace GameScript
	{
		class DelayFunctor;
		class StatsEvent;

		namespace Internal
		{
			class HitRegistrationList;
			class MagicEffectApplyRegistrationList;
			class RadiationDamageRegistrationList;
		}

		inline void LogFormError(
			const TESForm*                  a_obj,
			const char*                     a_error,
			BSScript::IVirtualMachine*      a_vm,
			std::uint32_t                   a_stackID,
			BSScript::ErrorLogger::Severity a_severity = BSScript::ErrorLogger::Severity::kError)
		{
			using func_t = decltype(&LogFormError);
			static REL::Relocation<func_t> func{ ID::GameScript::LogFormError };
			return func(a_obj, a_error, a_vm, a_stackID, a_severity);
		}

		class GetWorkshopResourceObjectsLinkedRefChildVisitor
		{
		public:
			enum class OPTIONS : std::uint32_t
			{
				kAllObjects = 0x0,
				kDamagedObjects = 0x1,
				kUndamagedObjects = 0x2
			};

			// members
			BSScrapArray<TESObjectREFR*>* array;   // 00
			const ActorValueInfo*         filter;  // 08
			std::uint32_t                 option;  // 10
		};
		static_assert(sizeof(GetWorkshopResourceObjectsLinkedRefChildVisitor) == 0x18);

		class __declspec(novtable) DelayFunctor :
			public BSIntrusiveRefCounted  // 08
		{
		public:
			static constexpr auto RTTI{ RTTI::GameScript__DelayFunctor };
			static constexpr auto VTABLE{ VTABLE::GameScript__DelayFunctor };

			enum class FunctorType
			{
				kMoveTo = 0x0,
				kMoveToOwnEditorLoc = 0x1,
				kDamageObject = 0x2,
				kEnable = 0x3,
				kDisable = 0x4,
				kDelete = 0x5,
				kSetPosition = 0x6,
				kSetAngle = 0x7,
				kSetMotionType = 0x8,
				kNonLatentDelete = 0x9,
				kMoveToPackLoc = 0xA,
				kSetScale = 0xB,
				kDropObject = 0xC,
				kAttachAshPile = 0xD,
				kAddRemoveConstraint = 0xE,
				kAddRemoveRagdoll = 0xF,
				kApplyHavokImpulse = 0x10,
				kResetRefr = 0x11,
				kSendPlayerToJail = 0x12,
				kAddItem = 0x13,
				kResurrect = 0x14,
				kCast = 0x15,
				kScrollCast = 0x16,
				kRemoveItem = 0x17,
				kWaitFor3D = 0x18,
				kPlayBink = 0x19,
				kMoveToNearestNavmesh = 0x1A,
				kClearDestruction = 0x1B,
				kWaitForResourceRecalc = 0x1C,
				kRemoveComponent = 0x1D,
				kDropRe = 0x1Ef
			};

			virtual ~DelayFunctor();  // 00

			// add
			[[nodiscard]] virtual BSScript::Variable operator()() = 0;                                                                                // 01
			[[nodiscard]] virtual bool               IsLatent() const = 0;                                                                            // 02
			[[nodiscard]] virtual bool               WantsRequeue() const { return false; }                                                           // 03
			[[nodiscard]] virtual FunctorType        GetType() const = 0;                                                                             // 04
			virtual bool                             SaveImpl(BSStorage& a_storage) const = 0;                                                        // 05
			virtual bool                             LoadImpl(const BSStorage& a_storage, std::uint32_t a_scriptSaveVersion, bool& a_dataValid) = 0;  // 06

			F4_HEAP_REDEFINE_NEW(DelayFunctor);

			// members
			std::uint32_t stackID;  // 0C
		};
		static_assert(sizeof(DelayFunctor) == 0x10);

		class __declspec(novtable) Logger :
			public BSScript::ErrorLogger  // 00
		{
		public:
			static constexpr auto RTTI{ RTTI::GameScript__Logger };
			static constexpr auto VTABLE{ VTABLE::GameScript__Logger };

			// override (BSScript::ErrorLogger)
			void PostErrorImpl(const BSScript::ICachedErrorMessage* a_errMsg, Severity a_severity) override;  // 01

			// members
			BSFixedString logFolder;  // A0
			BSLog*        log;        // A8
		};
		static_assert(sizeof(Logger) == 0xB0);

		class __declspec(novtable) HandlePolicy :
			public BSScript::IObjectHandlePolicy  // 00
		{
		public:
			static constexpr auto RTTI{ RTTI::GameScript__HandlePolicy };
			static constexpr auto VTABLE{ VTABLE::GameScript__HandlePolicy };

			// override (BSScript::IObjectHandlePolicy)
			bool        HandleIsType(std::uint32_t a_type, std::size_t a_handle) const override;              // 01
			bool        GetHandleType(std::size_t a_handle, std::uint32_t& a_type) const override;            // 02
			bool        IsHandleLoaded(std::size_t a_handle) const override;                                  // 03
			bool        IsHandleObjectAvailable(std::size_t a_handle) const override;                         // 04
			bool        ShouldAttemptToCleanHandle(std::size_t a_handle) const override;                      // 05
			std::size_t EmptyHandle() const override { return 0xFFFF00000000; }                               // 06
			std::size_t GetHandleForObject(std::uint32_t a_type, const void* a_object) const override;        // 07
			bool        HasParent(std::size_t a_childHandle) const override;                                  // 08
			std::size_t GetParentHandle(std::size_t a_childHandle) const override;                            // 09
			std::size_t GetHandleScriptsMovedFrom(std::size_t a_newHandle) const override;                    // 0A
			std::size_t GetSaveRemappedHandle(std::size_t a_saveHandle) const override;                       // 0B
			void*       GetObjectForHandle(std::uint32_t a_type, std::size_t a_handle) const override;        // 0C
			void        PersistHandle(std::size_t a_handle) override;                                         // 0D
			void        ReleaseHandle(std::size_t a_handle) override;                                         // 0E
			void        ConvertHandleToString(std::size_t a_handle, BSFixedString& a_string) const override;  // 0F

			[[nodiscard]] static std::uint64_t GetHandleForInventoryID(std::uint16_t a_uniqueID, std::uint32_t a_containerFormID) noexcept
			{
				return static_cast<std::uint64_t>(static_cast<std::uint32_t>(a_containerFormID)) |
				       (static_cast<std::uint64_t>(a_uniqueID) << 32ull) |
				       (1ull << (32ull + 16ull));
			}

			void DropSaveLoadRemapData()
			{
				using func_t = decltype(&HandlePolicy::DropSaveLoadRemapData);
				static REL::Relocation<func_t> func{ ID::GameScript::HandlePolicy::DropSaveLoadRemapData };
				return func(this);
			}

			void GetInventoryObjFromHandle(std::uint64_t a_cobj, TESObjectREFR*& a_container, std::uint16_t& a_uniqueID, TESObjectREFR*& a_inWorldREFR)
			{
				using func_t = decltype(&HandlePolicy::GetInventoryObjFromHandle);
				static REL::Relocation<func_t> func{ ID::GameScript::HandlePolicy::GetInventoryObjFromHandle };
				return func(this, a_cobj, a_container, a_uniqueID, a_inWorldREFR);
			}

			void UpdatePersistence()
			{
				using func_t = decltype(&HandlePolicy::UpdatePersistence);
				static REL::Relocation<func_t> func{ ID::GameScript::HandlePolicy::UpdatePersistence };
				return func(this);
			}

			// members
			BSSpinLock                               persistLock;      // 08
			BSTHashMap<std::size_t, std::uint32_t>   persistRefCount;  // 10
			BSTHashMap<std::size_t, bool>            queuedPromotes;   // 40
			BSSpinLock                               remapLock;        // 70
			BSTHashMap<std::uint32_t, std::uint32_t> changedFormIDs;   // 78
		};
		static_assert(sizeof(HandlePolicy) == 0xA8);

		class __declspec(novtable) ObjectBindPolicy :
			public BSScript::ObjectBindPolicy  // 00
		{
		public:
			static constexpr auto RTTI{ RTTI::GameScript__ObjectBindPolicy };
			static constexpr auto VTABLE{ VTABLE::GameScript__ObjectBindPolicy };

			class QueuedObject
			{
			public:
				// members
				BSTSmartPointer<BSScript::Object> createdObject;  // 00
				BSScript::MergedBoundScript       boundInfo;      // 08
			};
			static_assert(sizeof(QueuedObject) == 0x18);

			// override (BSScript::ObjectBindPolicy)
			void          EnsureBaseDataLoaded(std::size_t a_objHandle) override;                                                                                                                                                                                               // 01
			void          ObjectNoLongerNeeded(std::size_t a_objHandle) override;                                                                                                                                                                                               // 02
			void          AddBoundInfoImpl(std::size_t a_objHandle) override;                                                                                                                                                                                                   // 03
			void          ClearBoundInfoImpl(std::size_t a_objHandle) override;                                                                                                                                                                                                 // 04
			void          ClearDiskLoadedBoundInfoImpl(std::size_t a_objHandle) override;                                                                                                                                                                                       // 05
			void          ClearAllBoundInfoImpl() override;                                                                                                                                                                                                                     // 06
			void          PostBindObject(std::size_t a_objHandle) override;                                                                                                                                                                                                     // 07
			std::uint32_t GetExtraInfoSize(std::size_t) const override { return 0; }                                                                                                                                                                                            // 08
			void          WriteExtraInfo(std::size_t, const BSScript::IHandleReaderWriter&, BSStorage&) const override { return; }                                                                                                                                              // 09
			void          ReadExtraInfo(std::size_t a_objHandle, std::uint16_t a_handleVersion, const BSScript::IHandleReaderWriter& a_handleReaderWriter, const BSStorage& a_storage) override;                                                                                // 0A
			bool          IsIgnoringClear() const override;                                                                                                                                                                                                                     // 0B
			void          ResolveProperties(std::size_t a_objTarget, const BSTSmartPointer<BSScript::Object>& a_object, const BSTSmartPointer<BSScript::BoundScript>& a_boundScript, bool a_postSaveConstOnly) override;                                                        // 0D
			void          ResolveProperties(std::size_t a_objTarget, const BSTSmartPointer<BSScript::Object>& a_object, const BSScript::MergedBoundScript& a_boundScript, bool a_postSaveConstOnly) override;                                                                   // 0C
			void          ConvertProperties(std::size_t a_objTarget, const BSTSmartPointer<BSScript::BoundScript>& a_boundScript, bool a_constOnly, BSTScrapHashMap<BSFixedString, BSScript::Variable>& a_properties, std::uint32_t& a_nonConvertedProperties) const override;  // 0F
			void          ConvertProperties(std::size_t a_objTarget, const BSScript::MergedBoundScript& a_mergedScript, bool a_constOnly, BSTScrapHashMap<BSFixedString, BSScript::Variable>& a_properties, std::uint32_t& a_nonConvertedProperties) const override;            // 0E

			void EndSaveLoad()
			{
				using func_t = decltype(&ObjectBindPolicy::EndSaveLoad);
				static REL::Relocation<func_t> func{ ID::GameScript::ObjectBindPolicy::EndSaveLoad };
				return func(this);
			}

			// members
			BSSpinLock                                                 queueLock;               // 50
			bool                                                       resolveCalled;           // 58
			bool                                                       ignoringClear;           // 59
			bool                                                       initialLoadDone;         // 5A
			BSTHashMap<std::size_t, BSTSmallSharedArray<QueuedObject>> queuedObjects;           // 60
			BSTArray<std::size_t>                                      queuedAliases;           // 90
			BSTSet<std::size_t>                                        initiallyLoadedObjects;  // A8
		};
		static_assert(sizeof(ObjectBindPolicy) == 0xD8);

		class FragmentSystem
		{
		public:
			class Fragment :
				public BSIntrusiveRefCounted  // 00
			{
			public:
				// members
				BSFixedString objectName;    // 08
				BSFixedString functionName;  // 10
			};
			static_assert(sizeof(Fragment) == 0x18);

			class QuestStageFragments :
				public BSIntrusiveRefCounted  // 00
			{
			public:
				// members
				BSTHashMap<std::uint32_t, BSTSmartPointer<Fragment>> itemFragments;  // 08
			};
			static_assert(sizeof(QuestStageFragments) == 0x38);

			class QuestFragments :
				public BSIntrusiveRefCounted  // 00
			{
			public:
				// members
				BSTHashMap<std::uint32_t, BSTSmartPointer<QuestStageFragments>> stageFragments;  // 08
			};
			static_assert(sizeof(QuestFragments) == 0x38);

			class BeginEndFragments :
				public BSIntrusiveRefCounted  // 00
			{
			public:
				// members
				BSTSmartPointer<Fragment> beginFragment;  // 08
				BSTSmartPointer<Fragment> endFragment;    // 10
			};
			static_assert(sizeof(BeginEndFragments) == 0x18);

			class SceneFragments :
				public BSIntrusiveRefCounted  // 00
			{
			public:
				// members
				BSTSmartPointer<Fragment>                                     beginFragment;    // 08
				BSTSmartPointer<Fragment>                                     endFragment;      // 10
				BSTHashMap<std::uint32_t, BSTSmartPointer<Fragment>>          actionFragments;  // 18
				BSTHashMap<std::uint32_t, BSTSmartPointer<BeginEndFragments>> phaseFragments;   // 48
			};
			static_assert(sizeof(SceneFragments) == 0x78);

			class PackageFragments :
				public BSIntrusiveRefCounted  // 00
			{
			public:
				// members
				BSTSmartPointer<Fragment> beginFragment;   // 08
				BSTSmartPointer<Fragment> endFragment;     // 10
				BSTSmartPointer<Fragment> changeFragment;  // 18
			};
			static_assert(sizeof(PackageFragments) == 0x20);

			class PerkFragments :
				public BSIntrusiveRefCounted  // 00
			{
			public:
				// members
				BSTHashMap<std::uint32_t, BSTSmartPointer<Fragment>> entryFragments;  // 08
			};
			static_assert(sizeof(PerkFragments) == 0x38);

			class TerminalFragments :
				public BSIntrusiveRefCounted  // 00
			{
			public:
				// members
				BSTHashMap<std::uint32_t, BSTSmartPointer<Fragment>> menuItemFragments;  // 08
			};
			static_assert(sizeof(TerminalFragments) == 0x38);

			// members
			BSTHashMap<std::uint32_t, BSTSmartPointer<QuestFragments>>        questFragments;              // 000
			BSSpinLock                                                        kQuestFragmentSpinLock;      // 030
			BSTHashMap<std::uint32_t, BSTSmartPointer<BeginEndFragments>>     topicInfoFragments;          // 038
			BSSpinLock                                                        kTopicInfoFragmentSpinLock;  // 068
			BSTHashMap<std::uint32_t, BSTSmartPointer<SceneFragments>>        sceneFragments;              // 070
			BSSpinLock                                                        kSceneFragmentSpinLock;      // 0A0
			BSTHashMap<std::uint32_t, BSTSmartPointer<PackageFragments>>      packageFragments;            // 0A8
			BSSpinLock                                                        kPackageFragmentSpinLock;    // 0D8
			BSTHashMap<std::uint32_t, BSTSmartPointer<PerkFragments>>         perkFragments;               // 0E0
			BSSpinLock                                                        kPerkFragmentSpinLock;       // 110
			BSTHashMap<std::uint32_t, BSTSmartPointer<TerminalFragments>>     terminalFragments;           // 118
			BSSpinLock                                                        kTerminalFragmentSpinLock;   // 148
			BSTHashMap<std::uint32_t, BSTSmartPointer<BSScript::BoundScript>> boundScripts;                // 150
			BSSpinLock                                                        kBindInfoSpinLock;           // 180
		};
		static_assert(sizeof(FragmentSystem) == 0x188);

		class __declspec(novtable) Profiler :
			public BSScript::IProfilePolicy  // 000
		{
		public:
			static constexpr auto RTTI{ RTTI::GameScript__Profiler };
			static constexpr auto VTABLE{ VTABLE::GameScript__Profiler };

			// override (BSScript::IProfilePolicy)
			void StackFramePushQueued(std::uint32_t a_stackID, std::uint32_t a_frameNumber, const BSTSmartPointer<BSScript::Internal::IFuncCallQuery>& a_funcCallQuery) override;                                                                 // 01
			void StackFramePushed(std::uint32_t a_stackID, std::uint32_t a_frameNumber, const BSScript::Variable& a_self, const BSFixedString& a_scriptName, const BSFixedString& a_stateName, const BSFixedString& a_functionName) override;     // 02
			void StackFramePopQueued(std::uint32_t a_stackID, std::uint32_t a_frameNumber, const BSScript::Variable& a_self, const BSFixedString& a_scriptName, const BSFixedString& a_stateName, const BSFixedString& a_functionName) override;  // 03
			void StackFramePopped(std::uint32_t a_stackID, std::uint32_t a_frameNumber, const BSScript::Variable& a_self, const BSFixedString& a_scriptName, const BSFixedString& a_stateName, const BSFixedString& a_functionName) override;     // 04

			// members
			BSSpinLock                                     dataLock;            // 008
			BSLog*                                         globalProfilingLog;  // 010
			BSTHashMap<std::uint32_t, BSLog*>              watchedStacks;       // 018
			BSTHashMap<BSFixedString, BSLog*>              watchedScripts;      // 048
			BSTHashMap<std::size_t, BSLog*>                watchedObjects;      // 078
			BSTArray<BSTTuple<BSFixedString, std::size_t>> watchedStackRoots;   // 0A8
			BSTimer                                        timer;               // 0C0
		};
		static_assert(sizeof(Profiler) == 0x110);

		class __declspec(novtable) SavePatcher :
			public BSScript::ISavePatcherInterface  // 0
		{
		public:
			static constexpr auto RTTI{ RTTI::GameScript__SavePatcher };
			static constexpr auto VTABLE{ VTABLE::GameScript__SavePatcher };

			// override (BSScript::ISavePatcherInterface)
			void PatchStackFrame(BSScript::StackFrame&, BSScript::IVirtualMachine&) override { return; }  // 01
		};
		static_assert(sizeof(SavePatcher) == 0x8);
	}

	class __declspec(novtable) GameVM :
		public BSScript::IClientVM,                           // 0000
		public BSScript::IStackCallbackSaveInterface,         // 0008
		public BSTEventSink<BSScript::StatsEvent>,            // 0010
		public BSTEventSink<InputEnableLayerDestroyedEvent>,  // 0018
		public BSTEventSink<PositionPlayerEvent>,             // 0020
		public BSTEventSink<TESFormDeleteEvent>,              // 0028
		public BSTEventSink<TESFormIDRemapEvent>,             // 0030
		public BSTEventSink<TESInitScriptEvent>,              // 0037
		public BSTEventSink<TESResolveNPCTemplatesEvent>,     // 0040
		public BSTEventSink<TESUniqueIDChangeEvent>,          // 0048
		public BSTSingletonSDM<GameVM>,                       // 0050
		public BSTEventSource<GameScript::StatsEvent>         // 0058
	{
	public:
		static constexpr auto RTTI{ RTTI::GameVM };
		static constexpr auto VTABLE{ VTABLE::GameVM };

		[[nodiscard]] static GameVM* GetSingleton()
		{
			static REL::Relocation<GameVM**> singleton{ ID::GameScript::GameVM::Singleton };
			return *singleton;
		}

		[[nodiscard]] BSTSmartPointer<BSScript::IVirtualMachine> GetVM() const noexcept { return impl; }

		bool QueuePostRenderCall(const BSTSmartPointer<GameScript::DelayFunctor>& a_functor)
		{
			using func_t = decltype(&GameVM::QueuePostRenderCall);
			static REL::Relocation<func_t> func{ ID::GameScript::GameVM::QueuePostRenderCall };
			return func(this, a_functor);
		}

		void RegisterForAllGameEvents()
		{
			using func_t = decltype(&GameVM::RegisterForAllGameEvents);
			static REL::Relocation<func_t> func{ ID::GameScript::GameVM::RegisterForAllGameEvents };
			return func(this);
		}

		void SendEventToObjectAndRelated(
			std::size_t                                                                   a_object,
			const BSFixedString&                                                          a_eventName,
			const BSTThreadScrapFunction<bool(BSScrapArray<BSScript::Variable>&)>&        a_args,
			const BSTThreadScrapFunction<bool(const BSTSmartPointer<BSScript::Object>&)>& a_filter,
			const BSTSmartPointer<BSScript::IStackCallbackFunctor>&                       a_callback)
		{
			using func_t = decltype(&GameVM::SendEventToObjectAndRelated);
			static REL::Relocation<func_t> func{ ID::GameScript::GameVM::SendEventToObjectAndRelated };
			return func(this, a_object, a_eventName, a_args, a_filter, a_callback);
		}

		// members
		BSTSmartPointer<BSScript::IVirtualMachine>                          impl;                           // 00B0
		BSScript::IVMSaveLoadInterface*                                     saveLoadInterface;              // 00B8
		BSScript::IVMDebugInterface*                                        debugInterface;                 // 00C0
		BSScript::SimpleAllocMemoryPagePolicy                               memoryPagePolicy;               // 00C8
		BSScript::CompiledScriptLoader                                      scriptLoader;                   // 00F8
		GameScript::Logger                                                  logger;                         // 0130
		GameScript::HandlePolicy                                            handlePolicy;                   // 01E0
		GameScript::ObjectBindPolicy                                        objectBindPolicy;               // 0288
		BSTSmartPointer<BSScript::IStore>                                   scriptStore;                    // 0360
		GameScript::FragmentSystem                                          fragmentSystem;                 // 0368
		GameScript::Profiler                                                profiler;                       // 04F0
		GameScript::SavePatcher                                             savePatcher;                    // 0600
		BSSpinLock                                                          freezeLock;                     // 0608
		bool                                                                frozen;                         // 0610
		BSSpinLock                                                          vmTimeLock;                     // 0614
		std::uint32_t                                                       currentTime;                    // 061C
		std::uint32_t                                                       currentMenuModeTime;            // 0620
		std::uint32_t                                                       currentGameTime;                // 0624
		bool                                                                updateHasBeenRun;               // 0628
		bool                                                                saveLoad;                       // 0629
		BSTStaticFreeList<BSTSmartPointer<GameScript::DelayFunctor>, 512>   renderSafeFunctorPool1;         // 0630
		BSTCommonLLMessageQueue<BSTSmartPointer<GameScript::DelayFunctor>>  renderSafeFunctorQueue1;        // 2648
		BSTStaticFreeList<BSTSmartPointer<GameScript::DelayFunctor>, 512>   renderSafeFunctorPool2;         // 2670
		BSTCommonLLMessageQueue<BSTSmartPointer<GameScript::DelayFunctor>>  renderSafeFunctorQueue2;        // 4688
		BSTStaticFreeList<BSTSmartPointer<GameScript::DelayFunctor>, 512>   postRenderFunctorPool1;         // 46B0
		BSTCommonLLMessageQueue<BSTSmartPointer<GameScript::DelayFunctor>>  postRenderFunctorQueue1;        // 66C8
		BSTStaticFreeList<BSTSmartPointer<GameScript::DelayFunctor>, 512>   postRenderFunctorPool2;         // 66F0
		BSTCommonLLMessageQueue<BSTSmartPointer<GameScript::DelayFunctor>>  postRenderFunctorQueue2;        // 8708
		BSSpinLock                                                          renderSafeQueueLock;            // 8730
		BSTCommonLLMessageQueue<BSTSmartPointer<GameScript::DelayFunctor>>* renderSafeQueueToReadFrom;      // 8738
		BSTCommonLLMessageQueue<BSTSmartPointer<GameScript::DelayFunctor>>* renderSafeQueueToWriteTo;       // 8740
		BSSpinLock                                                          postRenderQueueLock;            // 8748
		BSTCommonLLMessageQueue<BSTSmartPointer<GameScript::DelayFunctor>>* postRenderQueueToReadFrom;      // 8750
		BSTCommonLLMessageQueue<BSTSmartPointer<GameScript::DelayFunctor>>* postRenderQueueToWriteTo;       // 8758
		BSSpinLock                                                          userLogLock;                    // 8760
		BSTHashMap<BSFixedString, BSScript::ErrorLogger*>                   userLogs;                       // 8768
		BSSpinLock                                                          statsWarningLock;               // 8798
		std::uint32_t                                                       initialSuspendOverageTime;      // 87A0
		std::uint32_t                                                       initialRunningOverageTime;      // 87A4
		std::uint32_t                                                       initialStackMemoryOverageTime;  // 87A8
		std::uint32_t                                                       lastWarningTime;                // 87AC
		std::uint32_t                                                       overflowFlags;                  // 87B0
	};
	static_assert(sizeof(GameVM) == 0x87B8);

	namespace GameScript
	{
		class __declspec(novtable) BasicEventHandler :
			public BSTEventSink<BGSLocationLoadedEvent>,                         // 000
			public BSTEventSink<BGSOnPlayerCompanionDismiss>,                    // 008
			public BSTEventSink<BGSOnPlayerEnterVertibirdEvent>,                 // 010
			public BSTEventSink<BGSOnPlayerFallLongDistances>,                   // 018
			public BSTEventSink<BGSOnPlayerFireWeaponEvent>,                     // 020
			public BSTEventSink<BGSOnPlayerHealTeammateEvent>,                   // 028
			public BSTEventSink<BGSOnPlayerModArmorWeaponEvent>,                 // 030
			public BSTEventSink<BGSOnPlayerCreateRobotEvent>,                    // 038
			public BSTEventSink<BGSOnPlayerModRobotEvent>,                       // 040
			public BSTEventSink<BGSOnPlayerSwimmingEvent>,                       // 048
			public BSTEventSink<BGSOnPlayerUseWorkBenchEvent>,                   // 050
			public BSTEventSink<BGSOnSpeechChallengeAvailable>,                  // 058
			public BSTEventSink<PlayerDifficultySettingChanged::Event>,          // 060
			public BSTEventSink<RadioManager::PipboyTransmitterDetectionEvent>,  // 068
			public BSTEventSink<TESActiveEffectApplyRemoveEvent>,                // 070
			public BSTEventSink<TESActivateEvent>,                               // 078
			public BSTEventSink<TESActorLocationChangeEvent>,                    // 080
			public BSTEventSink<TESBookReadEvent>,                               // 088
			public BSTEventSink<TESCellAttachDetachEvent>,                       // 090
			public BSTEventSink<TESCellFullyLoadedEvent>,                        // 098
			public BSTEventSink<TESCombatEvent>,                                 // 0A0
			public BSTEventSink<TESCommandModeCompleteCommandEvent>,             // 0A8
			public BSTEventSink<TESCommandModeEnterEvent>,                       // 0B0
			public BSTEventSink<TESCommandModeExitEvent>,                        // 0B8
			public BSTEventSink<TESCommandModeGiveCommandEvent>,                 // 0C0
			public BSTEventSink<TESDeathEvent>,                                  // 0C8
			public BSTEventSink<TESDeferredKillEvent>,                           // 0D0
			public BSTEventSink<TESDestructionStageChangedEvent>,                // 0D8
			public BSTEventSink<TESEnterBleedoutEvent>,                          // 0E0
			public BSTEventSink<TESEnterSneakingEvent>,                          // 0E8
			public BSTEventSink<TESEscortWaitStartEvent>,                        // 0F0
			public BSTEventSink<TESEscortWaitStopEvent>,                         // 0F8
			public BSTEventSink<TESExitFurnitureEvent>,                          // 100
			public BSTEventSink<TESFurnitureEvent>,                              // 108
			public BSTEventSink<TESGrabReleaseEvent>,                            // 110
			public BSTEventSink<TESConsciousnessEvent>,                          // 118
			public BSTEventSink<TESLimbCrippleEvent>,                            // 120
			public BSTEventSink<TESLoadGameEvent>,                               // 128
			public BSTEventSink<TESLocationClearedEvent>,                        // 130
			public BSTEventSink<TESLockChangedEvent>,                            // 138
			public BSTEventSink<TESObjectLoadedEvent>,                           // 140
			public BSTEventSink<TESObjectREFRTranslationEvent>,                  // 148
			public BSTEventSink<TESOnPCDialogueTargetEvent>,                     // 150
			public BSTEventSink<TESOpenCloseEvent>,                              // 158
			public BSTEventSink<TESPickpocketFailedEvent>,                       // 160
			public BSTEventSink<TESQuestInitEvent>,                              // 168
			public BSTEventSink<TESResetEvent>,                                  // 170
			public BSTEventSink<TESSellEvent>,                                   // 178
			public BSTEventSink<TESSpellCastEvent>,                              // 180
			public BSTEventSink<TESSwitchRaceCompleteEvent>,                     // 188
			public BSTEventSink<TESTrapHitEvent>,                                // 190
			public BSTEventSink<TESTriggerEnterEvent>,                           // 198
			public BSTEventSink<TESTriggerLeaveEvent>,                           // 1A0
			public BSTEventSink<Workshop::ItemDestroyedEvent>,                   // 1A8
			public BSTEventSink<Workshop::ItemMovedEvent>,                       // 1B0
			public BSTEventSink<Workshop::ItemPlacedEvent>,                      // 1B8
			public BSTEventSink<Workshop::ItemRepairedEvent>,                    // 1C0
			public BSTEventSink<Workshop::ItemGrabbedEvent>,                     // 1C8
			public BSTEventSink<Workshop::PowerOffEvent>,                        // 1D0
			public BSTEventSink<Workshop::PowerOnEvent>,                         // 1D8
			public BSTEventSink<WorkshopNPCTransferEvent>,                       // 1E0
			public BSTEventSink<Workshop::WorkshopModeEvent>,                    // 1E8
			public BSTSingletonSDM<BasicEventHandler>                            // 1F0
		{
		public:
			static constexpr auto RTTI{ RTTI::GameScript__BasicEventHandler };
			static constexpr auto VTABLE{ VTABLE::GameScript__BasicEventHandler };

			// members
			GameVM*                                    gameVM;            // 1F8
			FragmentSystem*                            fragmentSystem;    // 200
			HandlePolicy*                              handlePolicy;      // 208
			ObjectBindPolicy*                          objectBindPolicy;  // 210
			BSTSmartPointer<BSScript::IVirtualMachine> vm;                // 218
		};
		static_assert(sizeof(BasicEventHandler) == 0x220);

		class __declspec(novtable) CombatEventHandler :
			public BSTEventSink<TESHitEvent>,               // 00
			public BSTEventSink<TESMagicEffectApplyEvent>,  // 08
			public BSTEventSink<BGSRadiationDamageEvent>,   // 10
			public BSTSingletonSDM<CombatEventHandler>      // 18
		{
		public:
			static constexpr auto RTTI{ RTTI::GameScript__CombatEventHandler };
			static constexpr auto VTABLE{ VTABLE::GameScript__CombatEventHandler };

			// members
			BSTSmartPointer<BSScript::IVirtualMachine>                                             vm;                      // 20
			BSSpinLock                                                                             hitLock;                 // 28
			BSTHashMap<std::uint64_t, BSTSmartPointer<Internal::HitRegistrationList>>              hitEvents;               // 30
			BSSpinLock                                                                             magicEffectApplyLock;    // 60
			BSTHashMap<std::uint64_t, BSTSmartPointer<Internal::MagicEffectApplyRegistrationList>> magicEffectApplyEvents;  // 68
			BSSpinLock                                                                             radiationDamageLock;     // 98
			BSTHashMap<std::uint64_t, BSTSmartPointer<Internal::RadiationDamageRegistrationList>>  radiationDamageEvents;   // A0
		};
		static_assert(sizeof(CombatEventHandler) == 0xD0);

		class RefrOrInventoryObj
		{
		public:
			RefrOrInventoryObj() = default;

			explicit RefrOrInventoryObj(std::uint64_t a_cobj)
			{
				const auto vm = GameVM::GetSingleton();
				vm->handlePolicy.GetInventoryObjFromHandle(a_cobj, _container, _uniqueID, _ref);
			}

			[[nodiscard]] TESObjectREFR* Container() const noexcept { return _container; }
			[[nodiscard]] TESObjectREFR* Reference() const noexcept { return _ref; }
			[[nodiscard]] std::uint16_t  UniqueID() const noexcept { return _uniqueID; }

		private:
			// members
			TESObjectREFR* _ref{ nullptr };        // 00
			TESObjectREFR* _container{ nullptr };  // 08
			std::uint16_t  _uniqueID{ 0 };         // 10
		};
		static_assert(sizeof(RefrOrInventoryObj) == 0x18);

		inline void BindCObject(const BSTSmartPointer<BSScript::Object>& a_scriptObj, const RefrOrInventoryObj& a_cobj, BSScript::IVirtualMachine& a_vm)
		{
			using func_t = decltype(&BindCObject);
			static REL::Relocation<func_t> func{ ID::GameScript::BindCObject };
			return func(a_scriptObj, a_cobj, a_vm);
		}

		class __declspec(novtable) BaseHandleReaderWriter :
			public RE::BSScript::IHandleReaderWriter
		{
		public:
			inline static constexpr auto RTTI = { RTTI::GameScript__BaseHandleReaderWriter };
			inline static constexpr auto VTABLE = { VTABLE::GameScript__BaseHandleReaderWriter };

			~BaseHandleReaderWriter() override;                                                                // 0
			virtual std::uint16_t GetHandleVersion() const override;                                           // 142D8E390
			virtual bool          WriteHandle(BSStorage& storage, std::uint64_t) const override;               // 142D8E398
			virtual bool          ReadHandle(BSStorage const& storage, std::uint64_t&) const override;         // 142D8E3A0
			virtual bool          ReadHandleNoRemap(BSStorage const& storage, std::uint64_t&) const override;  // 142D8E3A8

			virtual bool WriteFormID(BSStorage& storage, std::uint32_t) const = 0;        // 142D8E3B0
			virtual bool ReadFormID(const BSStorage& storage, std::uint32_t&) const = 0;  // 142D8E3B8

			// members
			BSScript::IObjectHandlePolicy* objectHandlePolicy;  //08
		};
		static_assert(sizeof(BaseHandleReaderWriter) == 0x10);

		class DataFileHandleReaderWriter :
			public BaseHandleReaderWriter
		{
		public:
			inline static constexpr auto RTTI = { RTTI::GameScript__DataFileHandleReaderWriter };
			inline static constexpr auto VTABLE = { VTABLE::GameScript__DataFileHandleReaderWriter };

			~DataFileHandleReaderWriter() override;  // 0
			//DataFileHandleReaderWriter(TESFile *f, BSScript::IObjectHandlePolicy * objectHandlePolicy);
			virtual bool WriteFormID(BSStorage& storage, std::uint32_t) const override;        // 142D8E3B0
			virtual bool ReadFormID(const BSStorage& storage, std::uint32_t&) const override;  // 142D8E3B8

			// members
			TESFile* file;  //10
		};
		static_assert(sizeof(DataFileHandleReaderWriter) == 0x18);
	}
}
