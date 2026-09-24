#pragma once

#include "RE/B/BGSTypedFormValuePair.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTTuple.h"
#include "RE/B/BaseFormComponent.h"

namespace RE
{
	enum class ENUM_FORM_ID;
	class CALCED_OBJECT;
	class ContainerItemExtra;
	class LEVELED_OBJECT;
	class INSTANCE_FILTER;

	class __declspec(novtable) TESLeveledList :
		public BaseFormComponent  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::TESLeveledList };
		static constexpr auto VTABLE{ VTABLE::TESLeveledList };

		enum class LeveledListAllBelowForce
		{
			kNever = -1,
			kDefault = 0,
			kAlways = 1,
			kShiftUp = 2,
		};

		// add
		virtual std::int8_t  GetChanceNone();                                          // 07
		virtual bool         GetMultCalc();                                            // 08
		virtual std::int32_t GetMaxLevelDifference() { return 0; }                     // 09
		virtual const char*  GetOverrideName() { return nullptr; }                     // 0A
		virtual bool         GetCanContainFormsOfType(ENUM_FORM_ID a_type) const = 0;  // 0B

		LEVELED_OBJECT* AddLeveledObject(std::uint16_t a_level, std::uint16_t a_count, std::int8_t a_chanceNone, TESForm* a_item, ContainerItemExtra* a_itemExtra)
		{
			using func_t = decltype(&TESLeveledList::AddLeveledObject);
			static REL::Relocation<func_t> func{ ID::TESLeveledList::AddLeveledObject };
			return func(this, a_level, a_count, a_chanceNone, a_item, a_itemExtra);
		}

		void CalculateCurrentFormList(
			std::uint16_t                a_level,
			std::uint16_t                a_count,
			BSScrapArray<CALCED_OBJECT>& a_outCont,
			LeveledListAllBelowForce     a_allBelowForce = LeveledListAllBelowForce::kDefault,
			bool                         a_clampToPlayer = false,
			INSTANCE_FILTER*             a_instanceFilter = nullptr,
			const char*                  a_overrideName = nullptr)
		{
			using func_t = decltype(&TESLeveledList::CalculateCurrentFormList);
			static REL::Relocation<func_t> func{ ID::TESLeveledList::CalculateCurrentFormList };
			return func(this, a_level, a_count, a_outCont, a_allBelowForce, a_clampToPlayer, a_instanceFilter, a_overrideName);
		}

		void CalculateCurrentFormListForRef(TESObjectREFR* a_ref, BSScrapArray<CALCED_OBJECT>& a_outCont, bool a_legendary)
		{
			using func_t = decltype(&TESLeveledList::CalculateCurrentFormListForRef);
			static REL::Relocation<func_t> func{ ID::TESLeveledList::CalculateCurrentFormListForRef };
			return func(this, a_ref, a_outCont, a_legendary);
		}

		[[nodiscard]] bool GetUseAll() const
		{
			using func_t = decltype(&TESLeveledList::GetUseAll);
			static REL::Relocation<func_t> func{ ID::TESLeveledList::GetUseAll };
			return func(this);
		}

		// members
		TESGlobal*                                                      chanceGlobal;      // 08
		BSTArray<BSTTuple<TESForm*, BGSTypedFormValuePair::SharedVal>>* keywordChances;    // 10
		LEVELED_OBJECT*                                                 leveledLists;      // 18
		LEVELED_OBJECT**                                                scriptAddedLists;  // 20
		std::uint8_t                                                    scriptListCount;   // 28
		std::uint8_t                                                    baseListCount;     // 29
		std::int8_t                                                     chanceNone;        // 2A
		std::int8_t                                                     llFlags;           // 2B
		std::uint8_t                                                    maxUseAllCount;    // 2C
	};
	static_assert(sizeof(TESLeveledList) == 0x30);
}
