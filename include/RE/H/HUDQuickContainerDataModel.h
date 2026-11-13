#pragma once

namespace RE
{
	class QuickContainerStateData;

	// Builds what the quick container shows for the container under the
	// crosshair, and sends the result to the HUD as a QuickContainerStateEvent.
	class __declspec(novtable) HUDQuickContainerDataModel
	{
	public:
		static constexpr auto RTTI{ RTTI::HUDQuickContainerDataModel };
		static constexpr auto VTABLE{ VTABLE::HUDQuickContainerDataModel };

		virtual ~HUDQuickContainerDataModel();  // 00

		// Fills a_state's itemData with one row per visible entry, each built by
		// InventoryItemDisplayData's constructor. When more entries follow, a
		// "..." row goes at the end. A locked container gets a single
		// $LockedContainer row instead.
		void AddItemRows(QuickContainerStateData& a_state)
		{
			using func_t = decltype(&HUDQuickContainerDataModel::AddItemRows);
			static REL::Relocation<func_t> func{ ID::HUDQuickContainerDataModel::AddItemRows };
			return func(this, a_state);
		}
	};
}
