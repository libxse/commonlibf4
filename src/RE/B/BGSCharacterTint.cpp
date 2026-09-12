#include "RE/B/BGSCharacterTint.h"

namespace RE::BGSCharacterTint
{
	Template::Entry* Template::Group::GetTemplateBySlot(BGSCharacterTint::EntrySlot a_slot)
	{
		auto it = std::find_if(entries.begin(), entries.end(), [a_slot](Entry* entry){ return entry->slot == a_slot; });
		return it != entries.end() ? *it : nullptr;
	}

	Template::Entry* Template::Group::GetTemplateByUniqueID(std::uint16_t a_id)
	{
		auto it = std::find_if(entries.begin(), entries.end(), [a_id](Entry* entry){ return entry->uniqueID == a_id; });
		return it != entries.end() ? *it : nullptr;
	}

	Template::Entry* Template::Groups::GetTemplateBySlot(BGSCharacterTint::EntrySlot a_slot)
	{
		for (Group* group : groups)
		{
			Entry* entry = group->GetTemplateBySlot(a_slot);
			if (entry)
				return entry;
		}
		return nullptr;
	}

	Template::Entry* Template::Groups::GetTemplateByUniqueID(std::uint16_t a_id)
	{
		for (Group* group : groups)
		{
			Entry* entry = group->GetTemplateByUniqueID(a_id);
			if (entry)
				return entry;
		}
		return nullptr;
	}

	Template::Palette::ColorValue* Template::Palette::GetColorDataBySwatchID(std::uint16_t a_id)
	{
		auto it = std::find_if(colorValues.begin(), colorValues.end(), [a_id](ColorValue& color){ return color.swatchID == a_id; });
		return it != colorValues.end() ? &*it : nullptr;
	}

	[[nodiscard]] Entry* Entry::CreateCharacterTintEntry(std::uint32_t a_id) noexcept
	{
		using func_t = decltype(&CreateCharacterTintEntry);
		static REL::Relocation<func_t> func{ ID::BGSCharacterTint::CreateCharacterTintEntry };
		return func(a_id);
	}

	void Entry::ClearCharacterTints(Entries* a_src) noexcept
	{
		using func_t = decltype(&ClearCharacterTints);
		static REL::Relocation<func_t> func{ ID::BGSCharacterTint::ClearCharacterTints };
		return func(a_src);
	}

	void Entry::CopyCharacterTints(Entries* a_dst, Entries* a_src) noexcept
	{
		using func_t = decltype(&CopyCharacterTints);
		static REL::Relocation<func_t> func{ ID::BGSCharacterTint::CopyCharacterTints };
		return func(a_dst, a_src);
	}
}
