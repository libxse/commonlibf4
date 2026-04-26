#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/B/BSScript_IVMDebugInterface.h"
#include "RE/B/BSScript_IVMObjectBindInterface.h"
#include "RE/B/BSScript_IVirtualMachine.h"
#include "RE/B/BSScript_Internal_AttachedScript.h"
#include "RE/B/BSScript_Internal_EventRelay.h"
#include "RE/B/BSScript_Internal_FunctionMessage.h"
#include "RE/B/BSScript_Internal_IVMSaveLoadInterface.h"
#include "RE/B/BSScript_Internal_LinkerProcessor.h"
#include "RE/B/BSScript_Internal_ReadableStringTable.h"
#include "RE/B/BSScript_Internal_ReadableTypeTable.h"
#include "RE/B/BSScript_Internal_VirtualMachine.h"
#include "RE/B/BSScript_Internal_WritableStringTable.h"
#include "RE/B/BSScript_Internal_WritableTypeTable.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTEvent.h"
#include "RE/B/BSTFreeList.h"
#include "RE/B/BSTHashMap.h"
#include "RE/B/BSTMessageQueue.h"
#include "RE/B/BSTObjectArena.h"
#include "RE/B/BSTSmartPointer.h"

namespace RE
{
	namespace BSScript
	{
		class Array;
		class ErrorLogger;
		class IClientVM;
		class IMemoryPagePolicy;
		class IObjectHandlePolicy;
		class IProfilePolicy;
		class ISavePatcherInterface;
		class IStackCallbackFunctor;
		class IStackCallbackSaveInterface;
		class ObjectBindPolicy;
		class Stack;
		class StatsEvent;

		namespace Internal
		{
			class CodeTasklet;
			class SuspendedStack;

			class VirtualMachine :
				public IVirtualMachine,  // 0000
				//IVM -> public BSIntrusiveRefCounted  // 0008
				public IVMObjectBindInterface,     // 0010
				public IVMSaveLoadInterface,       // 0018
				public IVMDebugInterface,          // 0020
				public BSTEventSource<StatsEvent>  // 0028
			{
			public:
				static constexpr auto RTTI{ RTTI::BSScript__Internal__VirtualMachine };
				static constexpr auto VTABLE{ VTABLE::BSScript__Internal__VirtualMachine };

				enum class FreezeState
				{
					kNotFrozen = 0,
					kFreezing,
					kFrozen
				};

				class LoadedArrayEntry
				{
				public:
					// members
					BSTSmartPointer<Array> array;      // 00
					std::uint32_t          arraySize;  // 08
				};
				static_assert(sizeof(LoadedArrayEntry) == 0x10);

				class PendingLatentReturn
				{
				public:
					// members
					std::uint32_t stackID;      // 00
					Variable      returnValue;  // 08
				};
				static_assert(sizeof(PendingLatentReturn) == 0x18);

				class QueuedUnbindRefs
				{
				public:
					// members
					BSTSmartPointer<Object> obj;       // 00
					std::uint32_t           refCount;  // 08
					std::uint32_t           pad0C;     // 0C
				};
				static_assert(sizeof(QueuedUnbindRefs) == 0x10);

				~VirtualMachine() override;  // 00

				using RE::BSScript::IVirtualMachine::SendEvent;
				//using RE::BSTEventSource<RE::BSScript::StatsEvent>::SendEvent;

			public:
				// override (IVirtualMachine)
				virtual void                                     SetLoader(ILoader* a_newLoader) override;                                                                                                                                                                                                                                                           // 01
				virtual void                                     SetLinkedCallback(ITypeLinkedCallback* a_typeLinkedCallback) override;                                                                                                                                                                                                                              // 02
				virtual void                                     Update(float a_updateBudget) override;                                                                                                                                                                                                                                                              // 03
				virtual void                                     UpdateTasklets(float a_updateBudget) override;                                                                                                                                                                                                                                                      // 04
				virtual void                                     SetOverstressed(bool a_overstressed) override;                                                                                                                                                                                                                                                      // 05
				virtual bool                                     IsCompletelyFrozen() const override;                                                                                                                                                                                                                                                                // 06
				virtual bool                                     RegisterObjectType(std::uint32_t a_typeID, const char* a_objectTypeName) override;                                                                                                                                                                                                                  // 07
				virtual bool                                     GetScriptObjectType(std::uint32_t a_typeID, BSTSmartPointer<ObjectTypeInfo>& a_objType) override;                                                                                                                                                                                                   // 09
				virtual bool                                     GetScriptObjectType(const BSFixedString& a_name, BSTSmartPointer<ObjectTypeInfo>& a_objType) override;                                                                                                                                                                                              // 08
				virtual bool                                     GetScriptObjectTypeNoLoad(std::uint32_t a_typeID, BSTSmartPointer<ObjectTypeInfo>& a_objType) const override;                                                                                                                                                                                       // 0B
				virtual bool                                     GetScriptObjectTypeNoLoad(const BSFixedString& a_objectTypeName, BSTSmartPointer<ObjectTypeInfo>& a_objType) const override;                                                                                                                                                                        // 0A
				virtual bool                                     GetTypeIDForScriptObject(const BSFixedString& a_objectTypeName, std::uint32_t& a_typeID) const override;                                                                                                                                                                                            // 0C
				virtual void                                     GetScriptObjectsWithATypeID(BSScrapArray<BSFixedString>& a_objectTypeList) const override;                                                                                                                                                                                                          // 0D
				virtual bool                                     GetParentNativeType(const BSFixedString& a_childTypeName, BSTSmartPointer<ObjectTypeInfo>& a_parentType) override;                                                                                                                                                                                  // 0E
				virtual bool                                     TypeIsValid(const BSFixedString& a_objectTypeName) override;                                                                                                                                                                                                                                        // 0F
				virtual bool                                     ReloadType(const char* a_objectTypeName) override;                                                                                                                                                                                                                                                  // 10
				virtual void                                     TasksToJobs(JobList& a_jobList) override;                                                                                                                                                                                                                                                           // 11
				virtual void                                     CalculateFullReloadList(const BSTSet<BSFixedString>& a_scriptSet, BSTObjectArena<BSFixedString>& a_scriptList) const override;                                                                                                                                                                      // 12
				virtual bool                                     GetScriptStructType(const BSFixedString& a_structTypeName, BSTSmartPointer<StructTypeInfo>& a_structType) override;                                                                                                                                                                                 // 13
				virtual bool                                     GetScriptStructTypeNoLoad(const BSFixedString& a_structTypeName, BSTSmartPointer<StructTypeInfo>& a_structType) const override;                                                                                                                                                                     // 14
				virtual bool                                     GetChildStructTypes(const BSFixedString& a_parentObjectName, BSTObjectArena<BSFixedString>& a_structTypes) const override;                                                                                                                                                                          // 15
				virtual bool                                     CreateObject(const BSFixedString& a_objectTypeName, BSTSmartPointer<Object>& a_newObj) override;                                                                                                                                                                                                    // 17
				virtual bool                                     CreateObject(const BSFixedString& a_objectTypeName, const BSTScrapHashMap<BSFixedString, Variable>& a_properties, BSTSmartPointer<Object>& a_newObj) override;                                                                                                                                      // 16
				virtual bool                                     CreateStruct(const BSFixedString& a_structTypeName, BSTSmartPointer<Struct>& a_newStruct) override;                                                                                                                                                                                                 // 18
				virtual bool                                     CreateArray(TypeInfo::RawType a_elementType, const BSFixedString& a_elementObjectTypeName, std::uint32_t a_elementCount, BSTSmartPointer<Array>& a_newArray) override;                                                                                                                              // 1A
				virtual bool                                     CreateArray(const TypeInfo& a_type, std::uint32_t a_elementCount, BSTSmartPointer<Array>& a_newArray) override;                                                                                                                                                                                     // 19
				virtual bool                                     BindNativeMethod(IFunction* a_function) override;                                                                                                                                                                                                                                                   // 1B
				virtual void                                     SetCallableFromTasklets(const char* a_objectName, const char* a_functionName, bool a_taskletCallable) override;                                                                                                                                                                                     // 1D
				virtual void                                     SetCallableFromTasklets(const char* a_objectName, const char* a_stateName, const char* a_functionName, bool a_taskletCallable) override;                                                                                                                                                            // 1C
				virtual void                                     ForEachBoundObject(std::uint64_t a_objHandle, const BSTThreadScrapFunction<BSContainer::ForEachResult(Object*)>& a_functor) override;                                                                                                                                                               // 1E
				virtual bool                                     FindBoundObject(std::uint64_t a_objHandle, const char* a_objectTypeName, bool a_allowConst, BSTSmartPointer<Object>& a_attachedObj, bool a_exactMatch) const override;                                                                                                                              // 1F
				virtual void                                     MoveBoundObjects(std::uint64_t a_sourceHandle, std::uint64_t a_destHandle) override;                                                                                                                                                                                                                // 20
				virtual void                                     ResetAllBoundObjects(std::uint64_t a_objHandle) override;                                                                                                                                                                                                                                           // 21
				virtual bool                                     CastObject(const BSTSmartPointer<Object>& a_sourceObj, const BSTSmartPointer<ObjectTypeInfo>& a_targetType, BSTSmartPointer<Object>& a_castedObj) override;                                                                                                                                         // 22
				virtual bool                                     SetPropertyValue(const BSTSmartPointer<Object>& a_self, const char* a_propName, const Variable& a_newValue, const BSTSmartPointer<IStackCallbackFunctor>& a_callback) override;                                                                                                                     // 23
				virtual bool                                     GetPropertyValue(const BSTSmartPointer<Object>& a_self, const char* a_propName, const BSTSmartPointer<IStackCallbackFunctor>& a_callback) override;                                                                                                                                                 // 24
				virtual bool                                     GetVariableValue(std::uint64_t a_objHandle, const BSFixedString& a_scriptName, std::uint32_t a_varIndex, Variable& a_var) const override;                                                                                                                                                           // 26
				virtual bool                                     GetVariableValue(const BSTSmartPointer<Object>& a_obj, std::uint32_t a_varIndex, Variable& a_var) const override;                                                                                                                                                                                   // 25
				virtual bool                                     HandleImplementsEvent(std::uint64_t a_object, const BSFixedString& a_eventName) const override;                                                                                                                                                                                                     // 27
				virtual bool                                     AddEventRelay(std::uint64_t a_sourceObject, const BSFixedString& a_eventName, const BSTSmartPointer<Object>& a_destObj) override;                                                                                                                                                                   // 28
				virtual void                                     RemoveEventRelay(std::uint64_t a_sourceObject, const BSFixedString& a_eventName, const BSTSmartPointer<Object>& a_destObj) override;                                                                                                                                                                // 29
				virtual void                                     RemoveAllEventRelays(const BSTSmartPointer<Object>& a_destObj) override;                                                                                                                                                                                                                            // 2A
				virtual void                                     SendEvent(std::uint64_t a_objHandle, const BSFixedString& a_eventName, const BSTThreadScrapFunction<bool(BSScrapArray<Variable>&)>& a_arguments, const BSTThreadScrapFunction<bool(const BSTSmartPointer<Object>&)>& a_filter, const BSTSmartPointer<IStackCallbackFunctor>& a_callback) override;  // 2B
				virtual bool                                     DispatchStaticCall(const BSFixedString& a_objName, const BSFixedString& a_funcName, const BSTThreadScrapFunction<bool(BSScrapArray<Variable>&)>& a_arguments, const BSTSmartPointer<IStackCallbackFunctor>& a_callback) override;                                                                   // 2C
				virtual bool                                     DispatchMethodCall(std::uint64_t a_objHandle, const BSFixedString& a_objName, const BSFixedString& a_funcName, const BSTThreadScrapFunction<bool(BSScrapArray<Variable>&)>& a_arguments, const BSTSmartPointer<IStackCallbackFunctor>& a_callback) override;                                        // 2E
				virtual bool                                     DispatchMethodCall(const BSTSmartPointer<Object>& a_self, const BSFixedString& a_funcName, const BSTThreadScrapFunction<bool(BSScrapArray<Variable>&)>& a_arguments, const BSTSmartPointer<IStackCallbackFunctor>& a_callback) override;                                                            // 2D
				virtual bool                                     DispatchUnboundMethodCall(std::uint64_t a_objHandle, const BSTSmartPointer<BoundScript>& a_script, const BSFixedString& a_funcName, const BSTThreadScrapFunction<bool(BSScrapArray<Variable>&)>& a_arguments, const BSTSmartPointer<IStackCallbackFunctor>& a_callback) override;                   // 2F
				virtual bool                                     IsWaitingOnLatent(std::uint32_t a_stackID) const override;                                                                                                                                                                                                                                          // 30
				virtual void                                     ReturnFromLatent(std::uint32_t a_stackID, const Variable& a_retValue) override;                                                                                                                                                                                                                     // 31
				[[nodiscard]] virtual ErrorLogger&               GetErrorLogger() const override;                                                                                                                                                                                                                                                                    // 32
				[[nodiscard]] virtual const IObjectHandlePolicy& GetObjectHandlePolicy() const override;                                                                                                                                                                                                                                                             // 34
				[[nodiscard]] virtual IObjectHandlePolicy&       GetObjectHandlePolicy() override;                                                                                                                                                                                                                                                                   // 33
				[[nodiscard]] virtual const ObjectBindPolicy&    GetObjectBindPolicy() const override;                                                                                                                                                                                                                                                               // 36
				[[nodiscard]] virtual ObjectBindPolicy&          GetObjectBindPolicy() override;                                                                                                                                                                                                                                                                     // 35
				[[nodiscard]] virtual ISavePatcherInterface&     GetSavePatcherInterface() override;                                                                                                                                                                                                                                                                 // 37
				virtual void                                     RegisterForLogEvent(BSTEventSink<LogEvent>* a_sink) override;                                                                                                                                                                                                                                       // 38
				virtual void                                     UnregisterForLogEvent(BSTEventSink<LogEvent>* a_sink) override;                                                                                                                                                                                                                                     // 39
				virtual void                                     RegisterForStatsEvent(BSTEventSink<StatsEvent>* a_sink) override;                                                                                                                                                                                                                                   // 3A
				virtual void                                     UnregisterForStatsEvent(BSTEventSink<StatsEvent>* a_sink) override;                                                                                                                                                                                                                                 // 3B
				virtual void                                     PostCachedErrorToLogger(const ICachedErrorMessage& a_errorFunctor, ErrorLogger::Severity a_severity) const override;                                                                                                                                                                                // 3D
				virtual void                                     PostCachedErrorToLogger(const ICachedErrorMessage& a_errorFunctor, std::uint32_t a_stackID, ErrorLogger::Severity a_severity) const override;                                                                                                                                                       // 3C
				// TODO: figure out if align 10h here fucks things up???

				// override (IVMObjectBindInterface) 14307D8D8
				virtual std::uint64_t GetBoundHandle(const BSTSmartPointer<Object>& a_objPtr) const override;                                                                   // 01
				virtual void          TypeCanBeBound(const BSFixedString& a_className, std::uint64_t a_handle) override;                                                        // 02
				virtual void          BindObject(BSTSmartPointer<Object>& a_objPtr, std::uint64_t a_handle, bool a_conditional) override;                                       // 03
				virtual void          HandleLoadedBinding(BSTSmartPointer<Object>& a_objPtr, std::uint64_t a_handle, bool a_conditional) override;                              // 04
				virtual void          RemoveAllBoundObjects(std::uint64_t a_handle) override;                                                                                   // 05
				virtual void          RemoveAllDiskLoadedBoundObjects(std::uint64_t a_handle) override;                                                                         // 06
				virtual void          HandleCObjectDeletion(std::uint64_t a_handle) override;                                                                                   // 07
				virtual void          UnbindObject(const BSTSmartPointer<Object>& a_objPtr) override;                                                                           // 08
				virtual bool          CreateObjectWithProperties(const BSFixedString& a_className, std::uint32_t a_numProperties, BSTSmartPointer<Object>& a_objPtr) override;  // 09
				virtual bool          InitObjectProperties(BSTSmartPointer<Object>& a_objPtr, void* a_property, bool a_arg3) override;                                          // 0A

				// TODO: CommonLibSSE doesn't have these, figure out why
				// override (IVMSaveLoadInterface) 14307D938
				virtual bool                                           SaveGame(BSStorage& a_storage, BSScript::IHandleReaderWriter const& a_HandleReaderWriter, bool a_flag) override;                                                                   //14307D940 	// 01
				virtual bool                                           LoadGame(BSStorage const& a_storage, BSScript::IHandleReaderWriter const& a_HandleReaderWriter, bool& a_flag, bool& b_flag) override;                                              //14307D948 	// 02
				virtual void                                           MarkSaveInvalid(BSStorage& a_storage) override;                                                                                                                                    //14307D950 	// 03
				virtual unsigned short                                 GetSaveGameVersion() const override;                                                                                                                                               //14307D958 	// 04
				virtual void                                           CleanupSave() override;                                                                                                                                                            //14307D960 	// 05
				virtual void                                           CleanupLoad() override;                                                                                                                                                            //14307D968 	// 06
				virtual void                                           DropAllRunningData() override;                                                                                                                                                     //14307D970 	// 07
				virtual std::uint64_t                                  GetSaveHandleForObject(const BSScript::Object* a_Object) const override;                                                                                                           //14307D978 	// 08
				virtual void                                           SetSaveHandleForObject(const BSScript::Object* a_Object, std::uint64_t) override;                                                                                                  //14307D980 	// 09
				virtual bool                                           GetObjectBySaveHandle(std::uint64_t, const BSScript::TypeInfo& a_TypeInfo, BSTSmartPointer<BSScript::Object, BSTSmartPointerIntrusiveRefCount>& a_object_pointer) const override;  //14307D988 	// 0A
				virtual bool                                           GetObjectBySaveHandle(std::uint64_t, BSTSmartPointer<BSScript::Object, BSTSmartPointerIntrusiveRefCount>& a_object_pointer) const override;                                        //14307D990 	// 0B
				virtual std::uint64_t                                  GetSaveHandleForStruct(const BSScript::Struct* a_Struct) const override;                                                                                                           //14307D998 	// 0C
				virtual void                                           SetSaveHandleForStruct(const BSScript::Struct* a_Struct, std::uint64_t) override;                                                                                                  //14307D9A0 	// 0D
				virtual bool                                           GetStructBySaveHandle(std::uint64_t, BSTSmartPointer<BSScript::Struct, BSTSmartPointerIntrusiveRefCount>& a_object_pointer) const override;                                        //14307D9A8 	// 0E
				virtual std::uint64_t                                  GetSaveHandleForArray(const BSScript::Array* a_Array) const override;                                                                                                              //14307D9B0 	// 0F
				virtual void                                           SetSaveHandleForArray(const BSScript::Array* a_Array, std::uint64_t) override;                                                                                                     //14307D9B8 	// 10
				virtual bool                                           GetArrayBySaveHandle(std::uint64_t handle, BSTSmartPointer<BSScript::Array, BSTSmartPointerIntrusiveRefCount>& a_array_pointer) const override;                                    //14307D9C0 	// 11
				virtual bool                                           GetStackByID(unsigned int, BSTSmartPointer<BSScript::Stack, BSTSmartPointerIntrusiveRefCount>& a_stack_pointer) const override;                                                    //14307D9C8 	// 12
				virtual const BSScript::Internal::WritableStringTable& GetWritableStringTable() const override;                                                                                                                                           //14307D9D0 	// 13
				virtual const BSScript::Internal::WritableStringTable& GetWritableStringTable() override;                                                                                                                                                 //14307D9D8 	// 14
				virtual BSScript::Internal::ReadableStringTable&       GetReadableStringTable() const override;                                                                                                                                           //14307D9E0 	// 15
				virtual const BSScript::Internal::WritableTypeTable&   GetWritableTypeTable() const override;                                                                                                                                             //14307D9E8 	// 16
				virtual BSScript::Internal::WritableTypeTable&         GetWritableTypeTable() override;                                                                                                                                                   //14307D9F0 	// 17
				virtual const BSScript::Internal::ReadableTypeTable&   GetReadableTypeTable() const override;                                                                                                                                             //14307D9F8 	// 18
				virtual bool                                           CreateEmptyTasklet(BSScript::Stack* a_Stack, BSTSmartPointer<BSScript::Internal::CodeTasklet, BSTSmartPointerIntrusiveRefCount>& a_tasklet_pointer) override;                      //14307DA00 	// 19

				// override (IVMDebugInterface)
				virtual void DumpRunningStacksToLog() override;                                                                                // 01
				virtual void DumpStackFrameToLog(unsigned int a_v, unsigned int b_v, bool a_flag) override;                                    // 02
				virtual void GetStackFrame(unsigned int a_v, unsigned int b_v, bool a_flag, BSFixedString& a_identifier) override;             // 03
				virtual void DumpPersistenceInformationToLog(char const* logfile, uint64_t a_v) const override;                                // 04
				virtual void DumpEventRelayInformationToLog(char const* logfile, uint64_t a_v, BSFixedString const& a_string) const override;  // 05

				static VirtualMachine* GetSingleton();

				//bool StackExists(std::uint32_t stack_id);

				// members
				ErrorLogger*                                               errorLogger;                 // 0080
				IMemoryPagePolicy*                                         memoryPagePolicy;            // 0088
				IObjectHandlePolicy*                                       handlePolicy;                // 0090
				ObjectBindPolicy*                                          objectBindPolicy;            // 0098
				IClientVM*                                                 clientVM;                    // 00A0
				IStackCallbackSaveInterface*                               stackCallbackSaveInterface;  // 00A8
				IProfilePolicy*                                            profilePolicy;               // 00B0
				ISavePatcherInterface*                                     savePatcherInterface;        // 00B8
				mutable BSSpinLock                                         typeInfoLock;                // 00C0
				LinkerProcessor                                            linker;                      // 00C8
				BSTHashMap<BSFixedString, BSTSmartPointer<ObjectTypeInfo>> objectTypeMap;               // 0168
				BSTHashMap<BSFixedString, BSTSmartPointer<StructTypeInfo>> structTypeMap;               // 0198
				BSTHashMap<std::uint32_t, BSFixedString>                   typeIDToObjectType;          // 01C8
				BSTHashMap<BSFixedString, std::uint32_t>                   objectTypeToTypeID;          // 01F8
				BSTArray<BSTSmartPointer<ObjectTypeInfo>>                  typesToUnload;               // 0228
				mutable BSSpinLock                                         funcQueueLock;               // 0240
				BSTStaticFreeList<FunctionMessage, 1024>                   funcMsgPool;                 // 0248
				BSTCommonLLMessageQueue<FunctionMessage>                   funcMsgQueue;                // 8260
				BSTArray<FunctionMessage>                                  overflowFuncMsgs;            // 8288
				BSTArray<CodeTasklet*>                                     vmTasks;                     // 82A0
				std::uint32_t                                              uiWaitingFunctionMessages;   // 82B8
				bool                                                       overstressed;                // 82BC
				bool                                                       initialized;                 // 82BD
				std::byte                                                  pad82BE[0xBD00 - 0x82BE];    // 82BE
				BSTArray<SuspendedStack>                                   overflowSuspendArray1;       // BD00
				BSTArray<SuspendedStack>                                   overflowSuspendArray2;       // BD18
				mutable BSSpinLock                                         suspendQueueLock;            // BD30
				std::byte                                                  padBD38[0xBD40 - 0xBD38];    // BD38
				BSTArray<SuspendedStack>*                                  stacksToResumeOverflow;      // BD40
				std::byte                                                  padBD48[0xBD50 - 0xBD48];    // BD48
				BSTArray<SuspendedStack>*                                  stacksToSuspendOverflow;     // BD50
				mutable BSSpinLock                                         runningStacksLock;           // BD58
				BSTHashMap<std::uint32_t, BSTSmartPointer<Stack>>          allRunningStacks;            // BD60
				BSTHashMap<std::uint32_t, BSTSmartPointer<Stack>>          waitingLatentReturns;        // BD90
				std::uint32_t                                              nextStackID;                 // BDC0
				mutable BSSpinLock                                         frozenStacksLock;            // BDC4
				std::byte                                                  padBDCC[0xBDD0 - 0xBDCC];    // BDCC
				BSTArray<std::unique_ptr<PendingLatentReturn>>             pendingLatentReturns;        // BDD0
				BSTSmartPointer<BSScript::Stack>                           frozenStacksHead;            // BDE8
				std::uint32_t                                              frozenStacksCount;           // BDF0
				REX::TEnumSet<FreezeState, std::uint32_t>                  freezeState;                 // BDF4
				mutable BSSpinLock                                         attachedScriptsLock;         // BDF8
				BSTHashMap<uint64_t, BSTSmallSharedArray<AttachedScript>>  attachedScripts;             // BE00
				std::uint32_t                                              nextObjectToClean;           // BE30
				std::byte                                                  padBE34[0xBE38 - 0xBE34];    // BE34
				std::uint64_t                                              nextAttachedObjectToClean;   // BE38
				BSTArray<BSTSmartPointer<Object>>                          detachedScripts;             // BE40
				mutable BSSpinLock                                         structsLock;                 // BE58
				std::uint32_t                                              nextStructToClean;           // BE60
				std::byte                                                  padBE64[0xBE68 - 0xBE64];    // BE64
				BSTArray<BSTSmartPointer<Struct>>                          allStructs;                  // BE68
				mutable BSSpinLock                                         arraysLock;                  // BE80
				std::uint32_t                                              nextArrayToClean;            // BE88
				std::byte                                                  padBE8C[0xBE90 - 0xBE8C];    // BE8C
				BSTArray<BSTSmartPointer<Array>>                           arrays;                      // BE90
				mutable BSSpinLock                                         objectResetLock;             // BEA8
				BSTArray<BSTSmartPointer<Object>>                          objectsAwaitingReset;        // BEB0
				mutable BSSpinLock                                         loadTableLock;               // BEC8
				BSTHashMap<std::uint64_t, BSTSmartPointer<Object>>         loadTable;                   // BED0
				BSTHashMap<std::uint64_t, std::uint64_t>                   loadHandlesTable;            // BF00
				BSTHashMap<std::uint64_t, BSTSmartPointer<Struct>>         structLoadTable;             // BF30
				BSTHashMap<std::uint64_t, LoadedArrayEntry>                arrayLoadTable;              // BF60
				mutable BSSpinLock                                         queuedUnbindLock;            // BF90
				BSTArray<QueuedUnbindRefs>                                 queuedUnbinds;               // BF98
				mutable BSSpinLock                                         eventRelayLock;              // BFB0
				BSTHashMap<std::uint64_t, BSTSmartPointer<EventRelay>>     eventRelays;                 // BFB8
				std::uint16_t                                              currentSaveGameVersion;      // BFE8
				std::byte                                                  padBFEA[0xBFEC - 0xBFEA];    // BFEA
				std::uint32_t                                              saveObjectCount;             // BFEC
				std::uint32_t                                              saveStructCount;             // BFF0
				std::uint32_t                                              saveArrayCount;              // BFF4
				WritableStringTable                                        writableStringTable;         // BFF8
				ReadableStringTable                                        readableStringTable;         // C010
				WritableTypeTable                                          writableTypeTable;           // C028
				ReadableTypeTable                                          readableTypeTable;           // C038
				std::byte                                                  padC040[0xC080 - 0xC040];    // C040
			};
			static_assert(sizeof(VirtualMachine) == 0xC080);
		}
	}
}
