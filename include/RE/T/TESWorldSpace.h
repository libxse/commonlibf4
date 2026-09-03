#pragma once

#include "RE/B/BGSLargeRefData.h"
#include "RE/B/BSPointerHandle.h"
#include "RE/B/BSSimpleList.h"
#include "RE/B/BSStringT.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTHashMap.h"
#include "RE/N/NiPoint3.h"
#include "RE/N/NiPointer.h"
#include "RE/N/NiTMap.h"
#include "RE/T/TESForm.h"
#include "RE/T/TESFullName.h"
#include "RE/T/TESTexture.h"
#include "RE/W/WORLD_MAP_DATA.h"
#include "RE/W/WORLD_MAP_OFFSET_DATA.h"

namespace RE
{
	class BGSTerrainManager;
	class BSMultiBoundNode;
	class BSPortalGraph;
	class NiNode;

	class __declspec(novtable) TESWorldSpace :
		public TESForm,      // 0x000
		public TESFullName,  // 0x020
		public TESTexture    // 0x030
	{
	public:
		static constexpr auto RTTI{ RTTI::TESWorldSpace };
		static constexpr auto VTABLE{ VTABLE::TESWorldSpace };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kWRLD };

		enum class PARENT_USE_FLAG
		{
			kLand = 1u << 0,
			kLOD = 1u << 1,
			kMap = 1u << 2,
			kWater = 1u << 3,
			kClimate = 1u << 4,

			kSkyCell = 1u << 6
		};

		class ShortPoint
		{
		public:
			// members
			std::int16_t x;  // 0x0
			std::int16_t y;  // 0x2
		};
		static_assert(sizeof(ShortPoint) == 0x4);

		class OFFSET_DATA
		{
		public:
			// members
			std::uint32_t* cellFileOffsets;  // 0x00
			std::uint32_t* cellFileSizes;    // 0x08
			NiPoint2       offsetMinCoords;  // 0x10
			NiPoint2       offsetMaxCoords;  // 0x18
			std::uint32_t  fileOffset;       // 0x20
		};
		static_assert(sizeof(OFFSET_DATA) == 0x28);

		[[nodiscard]] TESWorldSpace* GetParentWorld(PARENT_USE_FLAG a_flags) const noexcept
		{
			return parentUseFlags.all(a_flags) ? parentWorld : nullptr;
		}

		[[nodiscard]] TESObjectCELL* GetSkyCell() const
		{
			using func_t = decltype(&TESWorldSpace::GetSkyCell);
			static REL::Relocation<func_t> func{ ID::TESWorldSpace::GetSkyCell };
			return func(this);
		}

		[[nodiscard]] TESWaterForm* GetWaterType() const noexcept
		{
			auto root = this;
			for (auto iter = root; iter; iter = iter->GetParentWorld(PARENT_USE_FLAG::kWater)) {
				root = iter;
			}

			if (root->worldWater) {
				return root->worldWater;
			} else {
				static REL::Relocation<TESWaterForm**> defaultWater{ ID::TESWorldSpace::DefaultWater };
				return *defaultWater;
			}
		}

		void AdjustMapMarkerCoord(NiPoint3* a_mapCoord, bool a_inverse)
		{
			using func_t = decltype(&TESWorldSpace::AdjustMapMarkerCoord);
			static REL::Relocation<func_t> func{ ID::TESWorldSpace::AdjustMapMarkerCoord };
			return func(this, a_mapCoord, a_inverse);
		}

		// members
		BSTHashMap<std::int32_t, TESObjectCELL*>                       cellMap;                  // 0x040
		TESObjectCELL*                                                 persistentCell;           // 0x070
		BGSTerrainManager*                                             terrainManager;           // 0x078
		TESClimate*                                                    climate;                  // 0x080
		std::int8_t                                                    flags;                    // 0x088
		REX::TEnumSet<PARENT_USE_FLAG, std::uint16_t>                  parentUseFlags;           // 0x08A
		std::int8_t                                                    worldFlags;               // 0x08C
		ShortPoint                                                     fixedCenter;              // 0x08E
		BSTHashMap<std::uint32_t, BSTArray<NiPointer<TESObjectREFR>>*> fixedPersistentRefMap;    // 0x098
		BSTArray<NiPointer<TESObjectREFR>>                             mobilePersistentRefs;     // 0x0C8
		BSTHashMap<std::uint32_t, BSSimpleList<TESObjectREFR*>*>       overlappedMultiboundMap;  // 0x0E0
		TESObjectCELL*                                                 skyCell;                  // 0x110
		BSTHashMap<std::uint32_t, BGSLocation*>                        locationMap;              // 0x118
		BSTArray<TESObjectREFR*>                                       teleportDoorCache;        // 0x148
		NiPointer<BSPortalGraph>                                       portalGraph;              // 0x160
		BSTHashMap<ObjectRefHandle, NiPointer<BSMultiBoundNode>>*      multiboundRefMap;         // 0x168
		BSTHashMap<BSMultiBoundNode*, ObjectRefHandle>*                refMultiboundMap;         // 0x170
		NiPointer<NiNode>                                              multiboundNode;           // 0x178
		NiPointer<NiNode>                                              portalSharedNode;         // 0x180
		TESWorldSpace*                                                 parentWorld;              // 0x188
		BGSLightingTemplate*                                           lightingTemplate;         // 0x190
		TESWaterForm*                                                  worldWater;               // 0x198
		TESWaterForm*                                                  lodWater;                 // 0x1A0
		float                                                          lodWaterHeight;           // 0x1A8
		WORLD_MAP_DATA                                                 worldMapData;             // 0x1AC
		WORLD_MAP_OFFSET_DATA                                          worldMapOffsetData;       // 0x1BC
		BGSMusicType*                                                  musicType;                // 0x1D0
		NiPoint2                                                       minimumCoords;            // 0x1D8
		NiPoint2                                                       maximumCoords;            // 0x1E0
		NiTMap<TESFile*, OFFSET_DATA*>                                 offsetDataMap;            // 0x1E8
		BSString                                                       editorID;                 // 0x208
		float                                                          defaultLandHeight;        // 0x218
		float                                                          defaultWaterHeight;       // 0x21C
		float                                                          distantLODMult;           // 0x220
		BGSEncounterZone*                                              encounterZone;            // 0x228
		BGSLocation*                                                   location;                 // 0x230
		TESTexture                                                     canopyShadowTexture;      // 0x238
		TESTexture                                                     waterEnvMap;              // 0x248
		BGSLargeRefData                                                largeRefData;             // 0x258
		float                                                          northRotation;            // 0x2B8
		std::int8_t                                                    lvlDataCellStartX;        // 0x2BC
		std::int8_t                                                    lvlDataCellStartY;        // 0x2BD
		std::int8_t                                                    lvlDataCellWidthX;        // 0x2BE
		std::int8_t                                                    lvlDataCellWidthY;        // 0x2BF
		std::int8_t*                                                   lvlDataCellA;             // 0x2C0
		std::int8_t*                                                   maxHeightData;            // 0x2C8
	};
	static_assert(sizeof(TESWorldSpace) == 0x2D0);
}
