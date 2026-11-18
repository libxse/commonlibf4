#pragma once

#include "RE/B/BSTArray.h"

namespace RE
{
	class BGSTerrainManager;
	class NiNode;
	class TESObjectCELL;

	class BGSTerrainNode
	{
	public:
		[[nodiscard]] std::uint32_t GetLODLevel() const noexcept
		{
			return (flags >> 21) & 0x3FC;
		}

		[[nodiscard]] bool IsInLoadedRange() const noexcept
		{
			return (flags & 0x4000) != 0;
		}

		void UpdateWaterVisibility(NiNode* a_parent)
		{
			using func_t = decltype(&BGSTerrainNode::UpdateWaterVisibility);
			static REL::Relocation<func_t> func{ ID::BGSTerrainNode::UpdateWaterVisibility };
			return func(this, a_parent);
		}

		void BuildCellCache(BSScrapArray<TESObjectCELL*>& a_cells)
		{
			using func_t = decltype(&BGSTerrainNode::BuildCellCache);
			static REL::Relocation<func_t> func{ ID::BGSTerrainNode::BuildCellCache };
			return func(this, a_cells);
		}

		// members
		BGSTerrainManager* manager;      // 00
		std::byte          pad08[0x38];  // 08
		std::uint32_t      flags;        // 40
		std::byte          pad44[0x4];   // 44
		std::int16_t       baseCellX;    // 48
		std::int16_t       baseCellY;    // 4A
		std::byte          pad4C[0x4];   // 4C
	};
	static_assert(offsetof(BGSTerrainNode, manager) == 0x00);
	static_assert(offsetof(BGSTerrainNode, flags) == 0x40);
	static_assert(offsetof(BGSTerrainNode, baseCellX) == 0x48);
	static_assert(offsetof(BGSTerrainNode, baseCellY) == 0x4A);
	static_assert(sizeof(BGSTerrainNode) == 0x50);
}
