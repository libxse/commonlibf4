#pragma once

namespace RE
{
	class QuickContainerStateData;

	class __declspec(novtable) HUDQuickContainerDataModel
	{
	public:
		static constexpr auto RTTI{ RTTI::HUDQuickContainerDataModel };
		static constexpr auto VTABLE{ VTABLE::HUDQuickContainerDataModel };

		virtual ~HUDQuickContainerDataModel();  // 00

		void AddItemRows(QuickContainerStateData& a_state)
		{
			using func_t = decltype(&HUDQuickContainerDataModel::AddItemRows);
			static REL::Relocation<func_t> func{ ID::HUDQuickContainerDataModel::AddItemRows };
			return func(this, a_state);
		}
	};
}
