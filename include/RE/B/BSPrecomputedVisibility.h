#pragma once

namespace RE::BSPrecomputedVisibility
{
	class MultiCellVisibilityData
	{
	public:
		[[nodiscard]] static MultiCellVisibilityData* GetSingleton()
		{
			static REL::Relocation<MultiCellVisibilityData**> singleton{ ID::BSPrecomputedVisibility::MultiCellVisibilityData::Singleton };
			return *singleton;
		}

		[[nodiscard]] bool IsCellVisibilityActive(std::uint32_t a_formID)
		{
			using func_t = decltype(&MultiCellVisibilityData::IsCellVisibilityActive);
			static REL::Relocation<func_t> func{ ID::BSPrecomputedVisibility::MultiCellVisibilityData::IsCellVisibilityActive };
			return func(this, a_formID);
		}
	};
}
