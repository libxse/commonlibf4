#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/B/BSScript_Internal_IFuncCallQuery.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTSmartPointer.h"

namespace RE
{
	namespace BSScript
	{
		class ErrorLogger;
		class Stack;
		class StackFrame;

		namespace Internal
		{
			class VirtualMachine;

			class __declspec(novtable) CodeTasklet :
				public IFuncCallQuery  // 00
			{
			public:
				static constexpr auto RTTI{ RTTI::BSScript__Internal__CodeTasklet };
				static constexpr auto VTABLE{ VTABLE::BSScript__Internal__CodeTasklet };

				enum class OpCode : std::uint32_t
				{
					kNOP,
					kIADD,
					kFADD,
					kISUB,
					kFSUB,
					kIMUL,
					kFMUL,
					kIDIV,
					kFDIV,
					kIMOD,
					kNOT,
					kINEG,
					kFNEG,
					kASSIGN,
					kCAST,
					kCMP_EQ,
					kCMP_LT,
					kCMP_LTE,
					kCMP_GT,
					kCMP_GTE,
					kJMP,
					kJMPT,
					kJMPF,
					kCALLMETHOD,
					kCALLPARENT,
					kCALLSTATIC,
					kRETURN,
					kSTRCAT,
					kPROPGET,
					kPROPSET,
					kARRAY_CREATE,
					kARRAY_LENGTH,
					kARRAY_GETELEMENT,
					kARRAY_SETELEMENT,
					kARRAY_FINDELEMENT,
					kARRAY_RFINDELEMENT,
					kIS,
					kSTRUCT_CREATE,
					kSTRUCT_GET,
					kSTRUCT_SET,
					kARRAY_FINDSTRUCT,
					kARRAY_RFINDSTRUCT,
					kARRAY_ADD,
					kARRAY_INSERT,
					kARRAY_REMOVELAST,
					kARRAY_REMOVE,
					kARRAY_CLEAR
				};

				enum class ResumeReason
				{
					kNotResuming = 0,
					kNotResumingNoIncrement = 1,
					kInitialStart = 2,
					kFunctionReturn = 3,
					kRetryInstruction = 4,
					kFunctionCall = 5
				};

				virtual ~CodeTasklet();  // 00

				// override (IFuncCallQuery)
				virtual bool GetFunctionCallInfo(
					CallType&                        a_callType,
					BSTSmartPointer<ObjectTypeInfo>& a_objectTypeInfo,
					BSFixedString&                   a_name,
					Variable&                        a_self,
					BSScrapArray<Variable>&          a_args) const override;  // 01

				// members
				Stack*                                     stack;                    // 10
				VirtualMachine*                            vm;                       // 18
				ErrorLogger*                               errorLogger;              // 20
				REX::TEnumSet<ResumeReason, std::uint32_t> resumeReason;             // 28
				std::uint32_t                              pad2C;                    // 2C
				StackFrame*                                topFrame;                 // 30
				std::uint32_t                              frameMemoryPage;          // 38
				std::int8_t                                jumpBitCount;             // 3C
				std::int8_t                                localVarBitCount;         // 3D
				std::int8_t                                memberVarBitCount;        // 3E
				std::uint8_t                               pad3F;                    // 3F
				std::uint32_t                              instructionDataBitCount;  // 40
				std::uint32_t                              pad44;                    // 44
				const void*                                instructionDataStart;     // 48
			};
			static_assert(sizeof(CodeTasklet) == 0x50);
		}
	}
}
