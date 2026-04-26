#pragma once

#include "RE/B/BSCRC32.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTHashMap.h"

namespace RE
{
	namespace PowerUtils
	{
		class GridConnection
		{
		public:
			~GridConnection() noexcept {}  // NOLINT(modernize-use-equals-default)

			// members
			std::uint32_t connection{ 0 };  // 0 - the powered object
			std::uint32_t connector{ 0 };   // 4 - how the object is connected
		};
		static_assert(sizeof(GridConnection) == 0x8);

		class GridSaveLoadData
		{
		public:
			// members
			std::uint32_t  node{ 0 };   // 0
			GridConnection connection;  // 4
		};
		static_assert(sizeof(GridSaveLoadData) == 0xC);

		class PowerGrid
		{
		public:
			// members
			BSTHashMap<std::uint32_t, BSTSet<GridConnection>*> adjacencyMap;      // 00 - maps powered objects to the objects they connect to
			BSTArray<GridSaveLoadData>                         loadGameData;      // 30
			std::uint32_t                                      loadElement{ 0 };  // 48
			BSTArray<std::uint32_t>                            currentlyPowered;  // 50
			float                                              capacity{ 0.0 };   // 68
			float                                              load{ 0.0 };       // 6C
		};
		static_assert(sizeof(PowerGrid) == 0x70);

		class TraverseConnectionsOptions
		{
		public:
			// members
			std::uint32_t ignoreMode;  // 00
			bool          wiredOnly;   // 04
			bool          inputsOnly;  // 05
		};
		static_assert(sizeof(TraverseConnectionsOptions) == 0x8);

		bool ItemIsPowerConnection(const TESObjectREFR* refr)
		{
			using func_t = decltype(&PowerUtils::ItemIsPowerConnection);
			static REL::Relocation<func_t> func{ ID::PowerUtils::ItemIsPowerConnection };
			return func(refr);
		}

		bool ItemIsPowerReceiver(const TESObjectREFR* refr)
		{
			using func_t = decltype(&PowerUtils::ItemIsPowerReceiver);
			static REL::Relocation<func_t> func{ ID::PowerUtils::ItemIsPowerReceiver };
			return func(refr);
		}
	}

	template <>
	struct BSCRC32<PowerUtils::GridConnection>
	{
	public:
		[[nodiscard]] std::uint32_t operator()(const PowerUtils::GridConnection& a_connection) const noexcept
		{
			return detail::GenerateCRC32(
				std::span(
					reinterpret_cast<const std::uint8_t*>(std::addressof(a_connection)),
					sizeof(PowerUtils::GridConnection)));
		}
	};
}
