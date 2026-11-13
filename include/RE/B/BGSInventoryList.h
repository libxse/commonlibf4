#pragma once

#include "RE/B/BGSInventoryItem.h"
#include "RE/B/BSPointerHandle.h"
#include "RE/B/BSSpinLock.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTEvent.h"
#include "RE/M/MemoryManager.h"

namespace RE
{
	class TESContainer;

	namespace BGSInventoryListEvent
	{
		class Event;
	}

	class BGSInventoryList :
		public BSTEventSource<BGSInventoryListEvent::Event>  // 00
	{
	public:
		BGSInventoryList(const TESContainer* a_container, ObjectRefHandle a_owner)
		{
			auto native_handle = a_owner.get_handle();
			ctor(a_container, &native_handle);
		}

		F4_HEAP_REDEFINE_NEW(BGSInventoryList)

		[[nodiscard]] static bool StandardObjectCompareCallbackFn(TESBoundObject* a_lhs, TESBoundObject* a_rhs)
		{
			return a_lhs == a_rhs;
		}

		inline void AddItem2(TESBoundObject* a_object, std::uint32_t a_count, ExtraDataList* a_extra, std::uint16_t a_flags = 0) noexcept
		{
			using func_t = void (*)(BGSInventoryList*, TESBoundObject*, std::uint32_t, ExtraDataList*, std::uint16_t);
			static REL::Relocation<func_t> func{ ID::BGSInventoryList::AddItem2 };
			func(this, a_object, a_count, a_extra, a_flags);
		}

		inline void AddItem2(TESBoundObject* a_object, std::uint32_t a_count, std::uint16_t a_flags = 0) noexcept
		{
			AddItem2(a_object, a_count, new ExtraDataList(), a_flags);
		}

		// Adds a copy of a_stack, a stack of a_object, to the list. It joins a
		// stack of the same object whose extra data matches, which is how
		// identical items come to share one stack and a count, and goes in as a
		// stack of its own otherwise. a_oldCount and a_newCount, when given,
		// receive the count of the stack it went into before and after.
		//
		// AddItem1 and AddItem2 add through it, and so does filling a list from a
		// container, for each entry whose base form has an object template. All
		// three hold the list's write lock.
		void AddStack(TESBoundObject* a_object, BGSInventoryItem::Stack* a_stack, std::uint32_t* a_oldCount = nullptr, std::uint32_t* a_newCount = nullptr)
		{
			using func_t = decltype(&BGSInventoryList::AddStack);
			static REL::Relocation<func_t> func{ ID::BGSInventoryList::AddStack };
			return func(this, a_object, a_stack, a_oldCount, a_newCount);
		}

		inline void BuildFromContainer(const TESContainer* a_container)
		{
			using func_t = decltype(&BGSInventoryList::BuildFromContainer);
			static REL::Relocation<func_t> func{ ID::BGSInventoryList::BuildFromContainer };
			func(this, a_container);
		}

		inline void Clear() noexcept
		{
			using func_t = decltype(&BGSInventoryList::Clear);
			static REL::Relocation<func_t> func{ ID::BGSInventoryList::Clear };
			func(this);
		}

		inline void FindAndWriteStackDataForItem(
			TESBoundObject*                            a_object,
			BGSInventoryItem::StackDataCompareFunctor& a_compareFunc,
			BGSInventoryItem::StackDataWriteFunctor&   a_writeFunc,
			bool (*a_objCompFn)(TESBoundObject*, TESBoundObject*) = StandardObjectCompareCallbackFn,
			bool a_alwaysContinue = false)
		{
			using func_t = decltype(&BGSInventoryList::FindAndWriteStackDataForItem);
			static REL::Relocation<func_t> func{ ID::BGSInventoryList::FindAndWriteStackDataForItem };
			return func(this, a_object, a_compareFunc, a_writeFunc, a_objCompFn, a_alwaysContinue);
		}

		[[nodiscard]] inline std::uint32_t FindItemIndex(TESBoundObject* a_object) const noexcept
		{
			using func_t = decltype(&BGSInventoryList::FindItemIndex);
			static REL::Relocation<func_t> func{ ID::BGSInventoryList::FindItemIndex };
			return func(this, a_object);
		}

		// DOES NOT LOCK
		inline void ForEachStack(
			std::function<bool(BGSInventoryItem&)>                           a_filter,   // return true to iterate stacks
			std::function<bool(BGSInventoryItem&, BGSInventoryItem::Stack&)> a_continue  // return false to return control from function
		)
		{
			for (auto& elem : data) {
				if (a_filter(elem)) {
					for (auto stack = elem.stackData.get(); stack; stack = stack->nextStack.get()) {
						if (!a_continue(elem, *stack)) {
							return;
						}
					}
				}
			}
		}

		[[nodiscard]] inline std::uint32_t GetItemCount(TESBoundObject* a_object) const noexcept
		{
			using func_t = decltype(&BGSInventoryList::GetItemCount);
			static REL::Relocation<func_t> func{ ID::BGSInventoryList::GetItemCount };
			return func(this, a_object);
		}

		[[nodiscard]] inline std::uint32_t GetQuestItemCount(TESBoundObject* a_object) const noexcept
		{
			using func_t = decltype(&BGSInventoryList::GetQuestItemCount);
			static REL::Relocation<func_t> func{ ID::BGSInventoryList::GetQuestItemCount };
			return func(this, a_object);
		}

		inline void RemoveItem1(TESBoundObject* a_object, std::uint32_t a_stackID, std::uint32_t a_count, bool a_manualMerge = false) noexcept
		{
			using func_t = void (*)(BGSInventoryList*, TESBoundObject*, std::uint32_t, std::uint32_t, bool);
			static REL::Relocation<func_t> func{ ID::BGSInventoryList::RemoveItem1 };
			func(this, a_object, a_stackID, a_count, a_manualMerge);
		}

		inline void RemoveItem1(TESBoundObject* a_object, std::uint32_t a_count, bool a_manualMerge = false) noexcept
		{
			RemoveItem1(a_object, 0, a_count, a_manualMerge);
		}

		// members
		BSTArray<BGSInventoryItem> data;          // 58
		float                      cachedWeight;  // 70
		ObjectRefHandle            owner;         // 74
		BSReadWriteLock            rwLock;        // 78

	private:
		void ctor(const TESContainer* a_container, std::uint32_t* a_owner)
		{
			using func_t = decltype(&BGSInventoryList::ctor);
			static REL::Relocation<func_t> func{ ID::BGSInventoryList::ctor };
			func(this, a_container, a_owner);
		}
	};
	static_assert(sizeof(BGSInventoryList) == 0x80);
}
