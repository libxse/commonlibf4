#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/B/BSScript_Internal_IFunction.h"
#include "RE/B/BSScript_Internal_VDescTable.h"
#include "RE/B/BSScript_PackedInstructionStream.h"
#include "RE/B/BSScript_TypeInfo.h"
#include "RE/B/BSTSmartPointer.h"

namespace RE
{
	namespace BSScript
	{
		namespace Internal
		{
			class __declspec(novtable) ScriptFunction :
				public IFunction  // 00
			{
			public:
				static constexpr auto RTTI{ RTTI::BSScript__Internal__ScriptFunction };
				static constexpr auto VTABLE{ VTABLE::BSScript__Internal__ScriptFunction };

				virtual ~ScriptFunction();  // 00

				// override (IFunction)
				virtual const BSFixedString& GetName() const override;                                                                                                                        // 01 - { return functionName; }
				virtual const BSFixedString& GetObjectTypeName() const override;                                                                                                              // 02 - { return scriptName; }
				virtual const BSFixedString& GetStateName() const override;                                                                                                                   // 03 - { return stateName; }
				virtual TypeInfo             GetReturnType() const override;                                                                                                                  // 04 - { a_dst = returnType; return a_dst; }
				virtual std::uint32_t        GetParamCount() const override;                                                                                                                  // 05 - { return varInfo.numParams; }
				virtual void                 GetParam(std::uint32_t a_param, BSFixedString& a_paramName, TypeInfo& a_paramType) const override;                                               // 06
				virtual std::uint32_t        GetStackFrameSize() const override;                                                                                                              // 07 - { return (varInfo.numVars - varInfo.numParams) + GetNumParams(); }
				virtual bool                 GetIsNative() const override;                                                                                                                    // 08 - { return false; }
				virtual bool                 GetIsStatic() const override;                                                                                                                    // 09 - { return isStatic; }
				virtual bool                 GetIsEmpty() const override;                                                                                                                     // 0A - { return unk48 == 0; }
				virtual FunctionType         GetFunctionType() const override;                                                                                                                // 0B - { return unk58; }
				virtual std::uint32_t        GetUserFlags() const override;                                                                                                                   // 0C - { return unk40; }
				virtual const BSFixedString& GetDocString() const override;                                                                                                                   // 0D - { return unk60; }
				virtual void                 InsertLocals(StackFrame& a_frame) const override;                                                                                                // 0E
				virtual CallResult           Call(const BSTSmartPointer<Stack>& a_stack, ErrorLogger& a_errorLogger, Internal::VirtualMachine& a_vm, bool a_inScriptTasklet) const override;  // 0F
				virtual const BSFixedString& GetSourceFilename() const override;                                                                                                              // 10 - { return sourceFileName; }
				virtual bool                 TranslateIPToLineNumber(std::uint32_t a_ip, std::uint32_t& a_lineNumber) const override;                                                         // 11
				virtual bool                 GetVarNameForStackIndex(std::uint32_t a_idx, BSFixedString& a_out) const override;                                                               // 12
				virtual bool                 CanBeCalledFromTasklets() const override;                                                                                                        // 13 - { return true; }
				virtual void                 SetCallableFromTasklets(bool a_taskletCallable) override;                                                                                        // 14 - { return; }

				// members
				BSFixedString                              name;             // 10
				BSFixedString                              objName;          // 18
				BSFixedString                              stateName;        // 20
				TypeInfo                                   retType;          // 28
				VDescTable                                 descTable;        // 30
				std::uint32_t                              userFlags;        // 40
				std::uint32_t                              pad44;            // 44
				ByteCode::PackedInstructionStream          instructions;     // 48
				REX::TEnumSet<FunctionType, std::uint16_t> functionType;     // 58
				bool                                       isStatic;         // 5A
				std::uint8_t                               pad5B;            // 5B
				std::uint32_t                              pad5C;            // 5C
				BSFixedString                              docString;        // 60
				BSFixedString                              sourceFileName;   // 68
				std::uint32_t                              lineNumberCount;  // 70
				std::uint32_t                              pad74;            // 74
				std::uint16_t*                             lineNumbers;      // 78
			};
			static_assert(sizeof(ScriptFunction) == 0x80);
		}
	}
}
