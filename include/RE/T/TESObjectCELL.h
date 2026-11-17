#pragma once

#include "RE/B/BSContainer.h"
#include "RE/B/BSSpinLock.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTHashMap.h"
#include "RE/B/BSTSmartPointer.h"
#include "RE/N/NiPointer.h"
#include "RE/T/TESForm.h"
#include "RE/T/TESFullName.h"

namespace RE
{
	class bhkPickData;
	class bhkWorldM;
	class EXTERIOR_DATA;
	class ExtraDataList;
	class INTERIOR_DATA;
	class LOADED_CELL_DATA;
	class NavMeshArray;
	class NiAVObject;
	class NiPoint3;
	class TESFile;
	class TESRegionList;

	namespace BGSWaterCollisionManager
	{
		class AutoWater;
		class BGSWaterUpdateI;
	}

	class __declspec(novtable) TESObjectCELL :
		public TESForm,     // 0x00
		public TESFullName  // 0x20
	{
	public:
		static constexpr auto RTTI{ RTTI::TESObjectCELL };
		static constexpr auto VTABLE{ VTABLE::TESObjectCELL };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kCELL };
		static constexpr auto TYPE_ID{ BSScript::kCell };

		enum class CELL_STATE : std::uint8_t
		{
			kNotLoaded = 0x0,
			kUnloading = 0x1,
			kLoadingData = 0x2,
			kLoading = 0x3,
			kLoaded = 0x4,
			kDetaching = 0x5,
			kAttachQueued = 0x6,
			kAttaching = 0x7,
			kAttached = 0x8
		};

		enum class CELLNODE
		{
			kActor = 0x0,
			kMarker = 0x1,
			kLand = 0x2,
			kStatic = 0x3,
			kDynamic = 0x4,
			kOcclusionPlane = 0x5,
			kPortal = 0x6,
			kMultibound = 0x7,
			kCollision = 0x8,
			kSmallObjects = 0x9,
			kLightMarker = 0xA,
			kSoundMarker = 0xB
		};

		enum class CELL_CULL_NODE
		{
			kActor = 0x0,
			kMarker = 0x1,
			kLand = 0x2,
			kStatic = 0x3,
			kDynamic = 0x4,
			kOcclusionPlane = 0x5,
			kPortal = 0x6,
			kMultibound = 0x7,
			kCollision = 0x8,
			kLightMarker = 0x9,
			kSoundMarker = 0xA,
			kWater = 0xB
		};

		enum class Flag
		{
			kInterior = 1u << 0,
			kHasWater = 1u << 1,
			kWarnToLeave = 1u << 9,
		};

		enum class QUAD_HIDE_STATE
		{
			kNormal = 0x0,
			kCulled = 0x1,
			kMissing = 0x2
		};

		enum class MARKERNODECHILD
		{
			kLightMarker = 0x0,
			kSoundMarker = 0x1
		};

		union CELL_DATA
		{
			EXTERIOR_DATA* exterior;  // XCLC
			INTERIOR_DATA* interior;  // XCLL
		};

		class RENDER_DATA
		{
		public:
			// members
			std::uint32_t geometryCount;       // 00
			std::uint32_t triangleCount;       // 04
			std::uint32_t newRenderPassCoutn;  // 08
			std::uint32_t activeLights;        // 0C
			std::uint64_t totalTime;           // 10
			std::uint32_t accumulateTime;      // 18
		};
		static_assert(sizeof(RENDER_DATA) == 0x20);

		[[nodiscard]] bhkWorldM* GetbhkWorld() const
		{
			using func_t = decltype(&TESObjectCELL::GetbhkWorld);
			static REL::Relocation<func_t> func{ ID::TESObjectCELL::GetbhkWorld };
			return func(this);
		}

		[[nodiscard]] bool GetCantWaitHere()
		{
			using func_t = decltype(&TESObjectCELL::GetCantWaitHere);
			static REL::Relocation<func_t> func{ ID::TESObjectCELL::GetCantWaitHere };
			return func(this);
		}

		[[nodiscard]] std::int32_t GetDataX()
		{
			using func_t = decltype(&TESObjectCELL::GetDataX);
			static REL::Relocation<func_t> func{ ID::TESObjectCELL::GetDataX };
			return func(this);
		}

		[[nodiscard]] std::int32_t GetDataY()
		{
			using func_t = decltype(&TESObjectCELL::GetDataY);
			static REL::Relocation<func_t> func{ ID::TESObjectCELL::GetDataY };
			return func(this);
		}

		[[nodiscard]] BGSEncounterZone* GetEncounterZone() const
		{
			using func_t = decltype(&TESObjectCELL::GetEncounterZone);
			static REL::Relocation<func_t> func{ ID::TESObjectCELL::GetEncounterZone };
			return func(this);
		}

		[[nodiscard]] BGSLocation* GetLocation() const
		{
			using func_t = decltype(&TESObjectCELL::GetLocation);
			static REL::Relocation<func_t> func{ ID::TESObjectCELL::GetLocation };
			return func(this);
		}

		[[nodiscard]] float GetExteriorWaterHeight() const
		{
			using func_t = decltype(&TESObjectCELL::GetExteriorWaterHeight);
			static REL::Relocation<func_t> func{ ID::TESObjectCELL::GetExteriorWaterHeight };
			return func(this);
		}

		static bool FindLandDataInFile(TESFile* a_file)
		{
			using func_t = decltype(&TESObjectCELL::FindLandDataInFile);
			static REL::Relocation<func_t> func{ ID::TESObjectCELL::FindLandDataInFile };
			return func(a_file);
		}

		[[nodiscard]] TESForm* GetOwner()
		{
			using func_t = decltype(&TESObjectCELL::GetOwner);
			static REL::Relocation<func_t> func{ ID::TESObjectCELL::GetOwner };
			return func(this);
		}

		[[nodiscard]] TESRegionList* GetRegionList(bool a_createIfMissing)
		{
			using func_t = decltype(&TESObjectCELL::GetRegionList);
			static REL::Relocation<func_t> func{ ID::TESObjectCELL::GetRegionList };
			return func(this, a_createIfMissing);
		}

		[[nodiscard]] NiAVObject* Pick(bhkPickData& pd)
		{
			using func_t = decltype(&TESObjectCELL::Pick);
			static REL::Relocation<func_t> func{ ID::TESObjectCELL::Pick };
			return func(this, pd);
		}

		void SetCullCellMarkers(bool a_cull)
		{
			using func_t = decltype(&TESObjectCELL::SetCullCellMarkers);
			static REL::Relocation<func_t> func{ ID::TESObjectCELL::SetCullCellMarkers };
			return func(this, a_cull);
		}

		void UpdateAllRefsLoaded()
		{
			using func_t = decltype(&TESObjectCELL::UpdateAllRefsLoaded);
			static REL::Relocation<func_t> func{ ID::TESObjectCELL::UpdateAllRefsLoaded };
			return func(this);
		}

		void AttatchReference3D(TESObjectREFR* a_ref, bool a_onTop, bool a_queueAttatch)
		{
			using func_t = decltype(&TESObjectCELL::AttatchReference3D);
			static REL::Relocation<func_t> func{ ID::TESObjectCELL::AttatchReference3D };
			return func(this, a_ref, a_onTop, a_queueAttatch);
		}

		void RemoveReference(TESObjectREFR* a_ref)
		{
			using func_t = decltype(&TESObjectCELL::RemoveReference);
			static REL::Relocation<func_t> func{ ID::TESObjectCELL::RemoveReference };
			return func(this, a_ref);
		}

		void UpdateAllDecals()
		{
			using func_t = decltype(&TESObjectCELL::UpdateAllDecals);
			static REL::Relocation<func_t> func{ ID::TESObjectCELL::UpdateAllDecals };
			return func(this);
		}

		EXTERIOR_DATA*              GetCoordinates() const;
		[[nodiscard]] TESWaterForm* GetWaterType() const noexcept;
		[[nodiscard]] bool          HasWater() const noexcept { return cellFlags.all(Flag::kHasWater); }
		[[nodiscard]] bool          IsAttached() const noexcept { return cellState == CELL_STATE::kAttached; }
		[[nodiscard]] bool          IsExterior() const noexcept { return !IsInterior(); }
		[[nodiscard]] bool          IsInterior() const noexcept { return cellFlags.all(Flag::kInterior); }

		void ForEachReference(std::function<BSContainer::ForEachResult(TESObjectREFR*)> a_callback);
		void ForEachReferenceInRange(const NiPoint3& a_origin, float a_radius, std::function<BSContainer::ForEachResult(TESObjectREFR*)> a_callback);

		// members
		BSSpinLock                                                         grassCreateLock;  // 0x30
		BSSpinLock                                                         grassTaskLock;    // 0x38
		REX::TEnumSet<Flag, std::uint16_t>                                 cellFlags;        // 0x40
		std::uint16_t                                                      cellGameFlags;    // 0x42
		CELL_STATE                                                         cellState;        // 0x44
		bool                                                               autoWaterLoaded;  // 0x45
		bool                                                               cellDetached;     // 0x46
		BSTSmartPointer<ExtraDataList>                                     extraList;        // 0x48
		CELL_DATA                                                          cellData;         // 0x50
		TESObjectLAND*                                                     cellLand;         // 0x58
		float                                                              waterHeight;      // 0x60
		NavMeshArray*                                                      navMeshes;        // 0x68
		BSTArray<NiPointer<TESObjectREFR>>                                 references;       // 0x70
		BSTSmartPointer<BGSWaterCollisionManager::AutoWater>               autoWater;        // 0x77
		BSTSet<BSTSmartPointer<BGSWaterCollisionManager::BGSWaterUpdateI>> waterSet;         // 0x80
		BSSpinLock                                                         spinLock;         // 0xC0
		union
		{
			TESWorldSpace* worldSpace;
			std::uint32_t  tempDataOffset;
		};  // 0xC8
		LOADED_CELL_DATA*    loadedData;            // 0xD0
		BGSLightingTemplate* lightingTemplate;      // 0xD8
		void*                visibilityData;        // 0xE0 - TODO
		std::uint32_t        rootVisibilityCellID;  // 0xE8
		std::uint16_t        visCalcDate;           // 0xEC
		std::uint16_t        preCombineDate;        // 0xF0
	};
	static_assert(sizeof(TESObjectCELL) == 0xF0);
}
