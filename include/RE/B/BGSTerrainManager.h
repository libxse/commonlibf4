#pragma once

#include "RE/B/BSSpinLock.h"
#include "RE/B/BSTArray.h"
#include "RE/N/NiPoint2.h"
#include "RE/N/NiPoint3.h"

namespace RE
{
	class BGSTerrainNode;
	class NiCamera;
	class NiNode;
	class TESWorldSpace;

	class BGSTerrainManager
	{
	public:
		class CullState
		{
		public:
			bool cullRoot;       // 00
			bool cullLand;       // 01
			bool cullTrees;      // 02
			bool cullObjects;    // 03
			bool cullInstanced;  // 04
		};

		class QuickCullDAta
		{
		public:
			NiPoint2 frustNearLeft;   // 000
			NiPoint2 frustFarLeft;    // 008
			NiPoint2 frustNearRight;  // 010
			NiPoint2 frustFarRight;   // 018
		};

		[[nodiscard]] static NiNode* GetWaterNode()
		{
			static REL::Relocation<NiNode**> node{ ID::BGSTerrainManager::WaterNode };
			return *node;
		}

		[[nodiscard]] static NiNode* GetLandNode()
		{
			static REL::Relocation<NiNode**> node{ ID::BGSTerrainManager::LandNode };
			return *node;
		}

		[[nodiscard]] static NiNode* GetObjectsNode()
		{
			static REL::Relocation<NiNode**> node{ ID::BGSTerrainManager::ObjectsNode };
			return *node;
		}

		[[nodiscard]] static NiNode* GetTreesNode()
		{
			static REL::Relocation<NiNode**> node{ ID::BGSTerrainManager::TreesNode };
			return *node;
		}

		void RecomputeQuickCullData(const NiCamera* a_camera)
		{
			using func_t = decltype(&BGSTerrainManager::RecomputeQuickCullData);
			static REL::Relocation<func_t> func{ ID::BGSTerrainManager::RecomputeQuickCullData };
			return func(this, a_camera);
		}

		// members
		bool                      mapMode;                 // 000
		TESWorldSpace*            world;                   // 008
		BGSTerrainNode*           rootNode;                // 010
		std::int16_t              minCellX;                // 018
		std::int16_t              minCellY;                // 01A
		std::uint32_t             maxLevel;                // 01C
		std::uint32_t             minLevel;                // 020
		std::uint32_t             rootLevel;               // 024
		std::uint32_t             segmentedBlockLevel;     // 028
		std::uint32_t             treeLevel;               // 02C
		CullState                 savedCullState;          // 030
		CullState                 activeCullState;         // 035
		bool                      cullActive;              // 03A
		bool                      needsImmediateUpdate;    // 03B
		bool                      initialUpdateDone;       // 03C
		bool                      hasLOD;                  // 03D
		QuickCullDAta             cullData;                // 040
		bool                      staticDataLoaded;        // 060
		BSTArray<BGSTerrainNode*> updateUpdates;           // 068
		std::uint32_t             nextUpdateNode;          // 080
		BSTArray<BGSTerrainNode*> immediateUpdates;        // 088
		BSSpinLock                immediateUpdateLock;     // 0A0
		bool                      lockedLOD;               // 0A8
		std::uint32_t             lockedTerrainLOD;        // 0AC
		std::uint32_t             lockedObjectLOD;         // 0B0
		std::uint32_t             totalChildNodes;         // 0B4
		std::uint8_t*             childNodeBufferStart;    // 0B8
		std::uint8_t*             childNodeBufferCurr;     // 0C0
		std::uint8_t*             childNodeBufferEnd;      // 0C8
		std::uint32_t             nodeCount;               // 0D0
		std::uint32_t             loadedRectUpdateDelay;   // 0D4
		NiPoint3                  interiorAdjustedOffset;  // 0D8
		BSTArray<BGSTerrainNode*> fadeNodeA;               // 0E8
	};
	static_assert(sizeof(BGSTerrainManager) == 0x100);
}
