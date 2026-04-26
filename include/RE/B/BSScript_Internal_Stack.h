#pragma once

#include "RE/B/BSIntrusiveRefCounted.h"
#include "RE/B/BSScript_Variable.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTSmartPointer.h"

namespace RE
{
	namespace BSScript
	{
		class IMemoryPagePolicy;
		class IProfilePolicy;
		class IStackCallbackFunctor;
		class MemoryPage;
		class Object;
		class StackFrame;

		namespace Internal
		{
			class CodeTasklet;
		}

		class Stack :
			public BSIntrusiveRefCounted  // 00
		{
		public:
			enum class StackType;

			enum class FreezeState
			{
				kUnfrozen = 0x0,
				kFreezing = 0x1,
				kFrozen = 0x2
			};

			enum class State
			{
				kRunning = 0x0,
				kFinished = 0x1,
				kWaitingOnMemory = 0x2,
				kWaitingOnLatentFunction = 0x3,
				kWaitingInOtherStackForCall = 0x4,
				kWaitingInOtherStackForReturn = 0x5,
				kWaitingInOtherStackForReturnNoPop = 0x6,
				kRetryReturnNoPop = 0x7,
				kRetryCall = 0x8
			};

			class MemoryPageData
			{
			public:
				// members
				BSTAutoPointer<MemoryPage> page;                    // 00
				std::uint32_t              availableMemoryInBytes;  // 08
			};
			static_assert(sizeof(MemoryPageData) == 0x10);

			[[nodiscard]] std::uint32_t GetPageForFrame(const StackFrame* a_frame) const
			{
				using func_t = decltype(&Stack::GetPageForFrame);
				static REL::Relocation<func_t> func{ ID::BSScript_Internal_Stack::GetPageForFrame };
				return func(this, a_frame);
			}

			[[nodiscard]] Variable& GetStackFrameVariable(const StackFrame* a_frame, std::uint32_t a_index, std::uint32_t a_pageHint)
			{
				using func_t = decltype(&Stack::GetStackFrameVariable);
				static REL::Relocation<func_t> func{ ID::BSScript_Internal_Stack::GetStackFrameVariable };
				return func(this, a_frame, a_index, a_pageHint);
			}

			// members
			IMemoryPagePolicy*                       policy;         // 08
			IProfilePolicy*                          profilePolicy;  // 10
			BSTSmallArray<MemoryPageData, 3>         pages;          // 18
			std::uint32_t                            frames;         // 58
			StackFrame*                              top;            // 60
			REX::TEnumSet<State, std::int32_t>       state;          // 68
			REX::TEnumSet<FreezeState, std::int32_t> freezeState;    // 6C
			Variable                                 returnValue;    // 70
			std::uint32_t                            stackID;        // 80
			REX::TEnumSet<StackType, std::int32_t>   stackType;      // 84
			BSTSmartPointer<Internal::CodeTasklet>   owningTasklet;  // 88
			BSTSmartPointer<IStackCallbackFunctor>   callback;       // 90
			BSTSmartPointer<Object>                  objToUnbind;    // 98
			BSTSmartPointer<Stack>                   nextStack;      // A0
		};
		static_assert(sizeof(Stack) == 0xA8);
	}
}
