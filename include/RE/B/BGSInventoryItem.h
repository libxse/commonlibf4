#pragma once

#include "RE/B/BSIntrusiveRefCounted.h"
#include "RE/B/BSPointerHandle.h"
#include "RE/B/BSTSmartPointer.h"
#include "RE/E/ExtraDataList.h"

namespace RE
{
	class BGSInventoryItem
	{
	public:
		class __declspec(novtable) Stack :
			public BSIntrusiveRefCounted  // 08
		{
		public:
			static constexpr auto RTTI{ RTTI::BGSInventoryItem__Stack };
			static constexpr auto VTABLE{ VTABLE::BGSInventoryItem__Stack };

			enum class Flag
			{
				kSlotIndex1 = 1 << 0,
				kSlotIndex2 = 1 << 1,
				kSlotIndex3 = 1 << 2,
				kEquipStateLocked = 1 << 3,
				kInvShouldEquip = 1 << 4,
				kTemporary = 1 << 5,
				kSlotMask = kSlotIndex1 | kSlotIndex2 | kSlotIndex3
			};

			virtual ~Stack();  // 00

			[[nodiscard]] std::uint32_t GetCount() const noexcept { return count; }
			[[nodiscard]] bool          IsEquipped() const noexcept { return flags.any(Flag::kSlotMask); }

			// members
			BSTSmartPointer<Stack>             nextStack;  // 10
			BSTSmartPointer<ExtraDataList>     extra;      // 18
			std::uint32_t                      count;      // 20
			REX::TEnumSet<Flag, std::uint16_t> flags;      // 24
		};
		static_assert(sizeof(Stack) == 0x28);

		class __declspec(novtable) StackDataCompareFunctor
		{
		public:
			static constexpr auto RTTI{ RTTI::BGSInventoryItem__StackDataCompareFunctor };
			static constexpr auto VTABLE{ VTABLE::BGSInventoryItem__StackDataCompareFunctor };

			// add
			virtual bool CompareData(const BGSInventoryItem::Stack& a_stack) = 0;  // 00
			virtual bool UseDefaultStackIfNoMatch() const { return false; }        // 01
		};
		static_assert(sizeof(StackDataCompareFunctor) == 0x8);

		class alignas(0x08) CheckStackIDFunctor :
			public StackDataCompareFunctor  // 00
		{
		public:
			static constexpr auto RTTI{ RTTI::BGSInventoryItem__CheckStackIDFunctor };
			static constexpr auto VTABLE{ VTABLE::BGSInventoryItem__CheckStackIDFunctor };

			CheckStackIDFunctor(std::uint32_t a_targetIndex) noexcept :
				targetIndex(a_targetIndex)
			{}

			// override (StackDataCompareFunctor)
			bool CompareData(const BGSInventoryItem::Stack&) override { return targetIndex-- == 0; }  // 00

			// members
			std::uint32_t targetIndex;  // 08
		};
		static_assert(sizeof(CheckStackIDFunctor) == 0x10);

		class alignas(0x08) CheckExtraDataFunctor :
			public StackDataCompareFunctor  // 00
		{
		public:
			static constexpr auto RTTI{ RTTI::BGSInventoryItem__CheckExtraDataFunctor };
			static constexpr auto VTABLE{ VTABLE::BGSInventoryItem__CheckExtraDataFunctor };

			CheckExtraDataFunctor(const BGSInventoryItem::Stack* a_stack) noexcept :
				extra(a_stack->extra.get())
			{}

			// override (StackDataCompareFunctor)
			bool CompareData(const BGSInventoryItem::Stack&) override { return true; }  // this->extra == extra; ??

			// members
			const ExtraDataList* extra;  // 08
		};
		static_assert(sizeof(CheckExtraDataFunctor) == 0x10);

		class __declspec(novtable) alignas(0x08) StackDataWriteFunctor
		{
		public:
			static constexpr auto RTTI{ RTTI::BGSInventoryItem__StackDataWriteFunctor };
			static constexpr auto VTABLE{ VTABLE::BGSInventoryItem__StackDataWriteFunctor };

			// add
			virtual void WriteDataImpl(TESBoundObject& a_baseObj, BGSInventoryItem::Stack& a_stack) = 0;  // 01

			// members
			bool shouldSplitStacks{ true };              // 08
			bool transferEquippedToSplitStack{ false };  // 09
		};
		static_assert(sizeof(StackDataWriteFunctor) == 0x10);

		class __declspec(novtable) ModifyModDataFunctor :
			public StackDataWriteFunctor  // 00
		{
		public:
			static constexpr auto RTTI{ RTTI::BGSInventoryItem__ModifyModDataFunctor };
			static constexpr auto VTABLE{ VTABLE::BGSInventoryItem__ModifyModDataFunctor };

			ModifyModDataFunctor(BGSMod::Attachment::Mod* a_mod, std::int8_t a_slotIndex, bool a_attach, bool* a_success) :
				mod(a_mod),
				success(a_success),
				slotIndex(a_slotIndex),
				attach(a_attach)
			{
				REX::EMPLACE_VTABLE(this);
				if (success) {
					*success = true;
				}
			}

			// override (StackDataWriteFunctor)
			void WriteDataImpl(TESBoundObject&, BGSInventoryItem::Stack&) override;  // 01

			// members
			BGSMod::Attachment::Mod* mod;                   // 10
			TESBoundObject*          foundObj{ nullptr };   // 18
			bool*                    success;               // 20
			const std::int8_t        slotIndex;             // 28
			const bool               attach;                // 29
			bool                     equipLocked{ false };  // 2A
		};
		static_assert(sizeof(ModifyModDataFunctor) == 0x30);

		class __declspec(novtable) SetHealthFunctor :
			public StackDataWriteFunctor  // 00
		{
		public:
			static constexpr auto RTTI{ RTTI::BGSInventoryItem__SetHealthFunctor };
			static constexpr auto VTABLE{ VTABLE::BGSInventoryItem__SetHealthFunctor };

			SetHealthFunctor(float a_health) :
				health(a_health)
			{
				REX::EMPLACE_VTABLE(this);
			}

			// override (StackDataWriteFunctor)
			void WriteDataImpl(TESBoundObject&, BGSInventoryItem::Stack&) override;  // 01

			// members
			float health;  // 10
		};
		static_assert(sizeof(SetHealthFunctor) == 0x18);

		bool FindAndWriteStackData(StackDataCompareFunctor& a_compareFunc, StackDataWriteFunctor& a_writeFunc, bool a_manualMerge, ObjectRefHandle a_owner)
		{
			using func_t = decltype(&BGSInventoryItem::FindAndWriteStackData);
			static REL::Relocation<func_t> func{ ID::BGSInventoryItem::FindAndWriteStackData };
			return func(this, a_compareFunc, a_writeFunc, a_manualMerge, a_owner);
		}

		[[nodiscard]] std::uint32_t GetCount() const noexcept;
		[[nodiscard]] Stack*        GetStackByID(std::uint32_t a_stackID) const
		{
			auto iter = stackData.get();
			while (a_stackID--) {
				iter = iter->nextStack.get();
			}

			return iter;
		}

		[[nodiscard]] const char* GetDisplayFullName(std::uint32_t a_stackID) const
		{
			using func_t = const char* (BGSInventoryItem::*)(std::uint32_t) const;
			static REL::Relocation<func_t> func{ ID::BGSInventoryItem::GetDisplayFullName1 };
			return func(this, a_stackID);
		}

		[[nodiscard]] const char* GetDisplayFullName(const ExtraDataList* a_extra) const
		{
			using func_t = const char* (BGSInventoryItem::*)(const ExtraDataList*) const;
			static REL::Relocation<func_t> func{ ID::BGSInventoryItem::GetDisplayFullName2 };
			return func(this, a_extra);
		}

		[[nodiscard]] TBO_InstanceData* GetInstanceData(std::uint32_t a_stackID) const
		{
			using func_t = decltype(&BGSInventoryItem::GetInstanceData);
			static REL::Relocation<func_t> func{ ID::BGSInventoryItem::GetInstanceData };
			return func(this, a_stackID);
		}

		[[nodiscard]] std::int32_t GetInventoryValue(std::uint32_t a_stackID, bool a_scale) const
		{
			using func_t = decltype(&BGSInventoryItem::GetInventoryValue);
			static REL::Relocation<func_t> func{ ID::BGSInventoryItem::GetInventoryValue };
			return func(this, a_stackID, a_scale);
		}

		ExtraDataList GetExtraDataAt(std::uint32_t a_index)
		{
			using func_t = decltype(&BGSInventoryItem::GetExtraDataAt);
			static REL::Relocation<func_t> func{ ID::BGSInventoryItem::GetExtraDataAt };
			return func(this, a_index);
		}

		void MergeStacks()
		{
			using func_t = decltype(&BGSInventoryItem::MergeStacks);
			static REL::Relocation<func_t> func{ ID::BGSInventoryItem::MergeStacks };
			return func(this);
		}

		bool IsEquipped(std::uint32_t a_stackID)
		{
			using func_t = decltype(&BGSInventoryItem::IsEquipped);
			static REL::Relocation<func_t> func{ ID::BGSInventoryItem::IsEquipped };
			return func(this, a_stackID);
		}

		int64_t GetStackCount()
		{
			using func_t = decltype(&BGSInventoryItem::GetStackCount);
			static REL::Relocation<func_t> func{ ID::BGSInventoryItem::GetStackCount };
			return func(this);
		}

		bool IsQuestObject(std::uint32_t a_stackID)
		{
			using func_t = decltype(&BGSInventoryItem::IsQuestObject);
			static REL::Relocation<func_t> func{ ID::BGSInventoryItem::IsQuestObject };
			return func(this, a_stackID);
		}

		float GetTotalWeight()
		{
			using func_t = decltype(&BGSInventoryItem::GetTotalWeight);
			static REL::Relocation<func_t> func{ ID::BGSInventoryItem::GetTotalWeight };
			return func(this);
		}

		// members
		TESBoundObject*        object;     // 00
		BSTSmartPointer<Stack> stackData;  // 08
	};
	static_assert(sizeof(BGSInventoryItem) == 0x10);
}
