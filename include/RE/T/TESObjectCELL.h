#pragma once

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
	class TESRegionList;

	namespace BGSWaterCollisionManager
	{
		class AutoWater;
		class BGSWaterUpdateI;
	}

	class __declspec(novtable) TESObjectCELL :
		public TESForm,     // 00
		public TESFullName  // 20
	{
	public:
		static constexpr auto RTTI{ RTTI::TESObjectCELL };
		static constexpr auto VTABLE{ VTABLE::TESObjectCELL };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kCELL };

		enum class CELL_STATE
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

		[[nodiscard]] void SetCullCellMarkers(bool a_cull)
		{
			using func_t = decltype(&TESObjectCELL::SetCullCellMarkers);
			static REL::Relocation<func_t> func{ ID::TESObjectCELL::SetCullCellMarkers };
			return func(this, a_cull);
		}

		[[nodiscard]] void UpdateAllRefsLoaded()
		{
			using func_t = decltype(&TESObjectCELL::UpdateAllRefsLoaded);
			static REL::Relocation<func_t> func{ ID::TESObjectCELL::UpdateAllRefsLoaded };
			return func(this);
		}

		[[nodiscard]] void AttatchReference3D(TESObjectREFR* a_ref, bool a_onTop, bool a_queueAttatch)
		{
			using func_t = decltype(&TESObjectCELL::AttatchReference3D);
			static REL::Relocation<func_t> func{ ID::TESObjectCELL::AttatchReference3D };
			return func(this, a_ref, a_onTop, a_queueAttatch);
		}

		[[nodiscard]] void RemoveReference(TESObjectREFR* a_ref)
		{
			using func_t = decltype(&TESObjectCELL::RemoveReference);
			static REL::Relocation<func_t> func{ ID::TESObjectCELL::RemoveReference };
			return func(this, a_ref);
		}

		[[nodiscard]] void UpdateAllDecals()
		{
			using func_t = decltype(&TESObjectCELL::UpdateAllDecals);
			static REL::Relocation<func_t> func{ ID::TESObjectCELL::UpdateAllDecals };
			return func(this);
		}

		[[nodiscard]] TESWaterForm* GetWaterType() const noexcept;
		[[nodiscard]] bool          HasWater() const noexcept { return cellFlags.all(Flag::kHasWater); }
		[[nodiscard]] bool          IsExterior() const noexcept { return !IsInterior(); }
		[[nodiscard]] bool          IsInterior() const noexcept { return cellFlags.all(Flag::kInterior); }

		// members
		BSSpinLock                             grassCreateLock;  // 30
		BSSpinLock                             grassTaskLock;    // 38
		REX::EnumSet<Flag, std::uint16_t>      cellFlags;        // 40
		std::uint16_t                          cellGameFlags;    // 42
		REX::EnumSet<CELL_STATE, std::uint8_t> cellState;        // 44
		bool                                   autoWaterLoaded;  // 45
		bool                                   cellDetached;     // 46
		BSTSmartPointer<ExtraDataList>         extraList;        // 48
		union
		{
			void*          cellData;
			EXTERIOR_DATA* cellDataExterior;
			INTERIOR_DATA* cellDataInterior;
		};  // 50
		TESObjectLAND*                                                     cellLand;     // 58
		float                                                              waterHeight;  // 60
		NavMeshArray*                                                      navMeshes;    // 68
		BSTArray<NiPointer<TESObjectREFR>>                                 references;   // 70
		BSTSmartPointer<BGSWaterCollisionManager::AutoWater>               autoWater;    // 77
		BSTSet<BSTSmartPointer<BGSWaterCollisionManager::BGSWaterUpdateI>> waterSet;     // 80
		BSSpinLock                                                         spinLock;     // C0
		union
		{
			TESWorldSpace* worldSpace;
			std::uint32_t  tempDataOffset;
		};  // C8
		LOADED_CELL_DATA*    loadedData;            // D0
		BGSLightingTemplate* lightingTemplate;      // D8
		void*                visibilityData;        // E0 - TODO
		std::uint32_t        rootVisibilityCellID;  // E8
		std::uint16_t        visCalcDate;           // EC
		std::uint16_t        preCombineDate;        // F0
	};
	static_assert(sizeof(TESObjectCELL) == 0xF0);
}
