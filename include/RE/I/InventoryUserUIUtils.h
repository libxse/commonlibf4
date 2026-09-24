#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTTuple.h"
#include "Scaleform/G/GFx_Value.h"

namespace RE
{
	class BGSInventoryItem;

	namespace InventoryUserUIUtils
	{
		namespace detail
		{
			inline void AddItemCardInfoEntry(
				Scaleform::GFx::Value& a_array,
				Scaleform::GFx::Value& a_newEntry,
				const BSFixedStringCS& a_textID,
				Scaleform::GFx::Value& a_value,
				float                  a_difference = 0.0F,
				float                  a_totalDamage = FLT_MAX,
				float                  a_compareDamage = FLT_MAX)
			{
				using func_t = decltype(&detail::AddItemCardInfoEntry);
				static REL::Relocation<func_t> func{ ID::InventoryUserUIUtils::AddItemCardInfoEntry };
				return func(a_array, a_newEntry, a_textID, a_value, a_difference, a_totalDamage, a_compareDamage);
			}
		}

		inline void AddItemCardInfoEntry(Scaleform::GFx::Value& a_array, Scaleform::GFx::Value& a_entry, const char* a_name, Scaleform::GFx::Value a_value, float a_difference, float a_totalValue = FLT_MAX, float a_comparisonValue = FLT_MAX)
		{
			detail::AddItemCardInfoEntry(a_array, a_entry, a_name, a_value, a_difference, a_totalValue, a_comparisonValue);
		}

		inline void AddItemCardInfoEntry(Scaleform::GFx::Value& a_array, Scaleform::GFx::Value& a_entry, const char* a_name = "", Scaleform::GFx::Value a_value = 0)
		{
			detail::AddItemCardInfoEntry(a_array, a_entry, a_name, a_value);
		}

		inline void AddItemCardInfoEntry(Scaleform::GFx::Value& a_array, const char* a_name, Scaleform::GFx::Value a_value)
		{
			Scaleform::GFx::Value entry;
			detail::AddItemCardInfoEntry(a_array, entry, a_name, a_value);
		}

		// Builds the item card for one stack of a_item into a_target. a_target
		// is either the card's own array of entries, or a list entry that gets
		// the array as its ItemCardInfoList member. The container, barter,
		// workbench and cooking menus build their cards here, and the Pip-Boy
		// has its own code. Weapon and armor rows are compared against the
		// equipped items in a_compareItems. For armor,
		// a_compareArmorWeightAndValue also compares weight and value.
		inline void PopulateItemCardInfo_Helper(Scaleform::GFx::Value& a_target, const BGSInventoryItem& a_item, std::uint32_t a_stackID, const BSScrapArray<BSTTuple<const BGSInventoryItem*, std::uint32_t>>& a_compareItems, bool a_compareArmorWeightAndValue)
		{
			using func_t = decltype(&InventoryUserUIUtils::PopulateItemCardInfo_Helper);
			static REL::Relocation<func_t> func{ ID::InventoryUserUIUtils::PopulateItemCardInfo_Helper };
			return func(a_target, a_item, a_stackID, a_compareItems, a_compareArmorWeightAndValue);
		}
	}
}
