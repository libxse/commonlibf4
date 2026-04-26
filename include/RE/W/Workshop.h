#pragma once

#include "RE/A/Actor.h"
#include "RE/B/BSExtraData.h"
#include "RE/B/BSPointerHandle.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTTuple.h"
#include "RE/N/NiPoint.h"
#include "RE/N/NiPointer.h"
#include "RE/P/PowerUtils.h"
#include "RE/T/TESObjectCELL.h"

namespace RE
{
	template <class>
	class BSPointerHandleSmartPointer;

	class bhkNPCollisionObject;
	class hknpShape;

	namespace Workshop
	{
		enum class PlacementStatusValue : std::int8_t
		{
			kNoEditItem = 0x0,
			kValidPlacement = 0x1,
			kFloating = 0x2,
			kIntersecting = 0x3,
			kTerrainOnly = 0x4,
			kWaterRestriction = 0x5,
			kSplineTooLong = 0x6,
			kOutsideBuildArea = 0x7,
			kRedundantSpline = 0x8,
			kAttachedSplineInvalid = 0x9,
			kUnsupported = 0xA,
			kMustSnap = 0xB,
			kRadiusOverlap = 0xC,
			kTimer = 0xD,
			kReasonCount = 0xE
		};

		enum class StartWorkshopStatus
		{
			kOk = 0x0,
			kNoNearbyWorkshop = 0x1,
			kAlreadyInWorkshopMode = 0x2,
			kActivationBlocked = 0x3
		};

		class BuildableAreaEvent
		{
		public:
			// members
			bool exit;  // 00
		};
		static_assert(sizeof(BuildableAreaEvent) == 0x1);

		class ContextData
		{
		public:
			ContextData(Actor* a_actor)
			{
				// lookDir.y = 1.0f;
				zAngle = a_actor->data.angle.z;
				parentCell = a_actor->parentCell;
				worldSpace = a_actor->parentCell->worldSpace;
				a_actor->GetEyeVector(lookPos, lookDir, false);
			}

			// members
			NiPoint3       lookPos;     // 00
			NiPoint3       lookDir;     // 0C
			float          zAngle;      // 18
			TESObjectCELL* parentCell;  // 20
			TESWorldSpace* worldSpace;  // 28
		};
		static_assert(sizeof(ContextData) == 0x30);

		class DeletedItemInfo
		{
		public:
			~DeletedItemInfo() noexcept {}  // NOLINT(modernize-use-equals-default)

			// members
			TESFormID     formID;  // 0
			std::uint32_t count;   // 4
		};
		static_assert(sizeof(DeletedItemInfo) == 0x8);

		class __declspec(novtable) ExtraData :
			public BSExtraData  // 00
		{
		public:
			static constexpr auto RTTI{ RTTI::Workshop__ExtraData };
			static constexpr auto VTABLE{ VTABLE::Workshop__ExtraData };
			static constexpr auto TYPE{ EXTRA_DATA_TYPE::kWorkshop };

			// members
			PowerUtils::PowerGrid*           currentPowerGrid;  // 18
			BSTArray<PowerUtils::PowerGrid*> powerGrid;         // 20
			BSTArray<DeletedItemInfo*>       deletedItems;      // 38
			std::int32_t                     powerRating;       // 50
			bool                             offGridItems;      // 54
		};
		static_assert(sizeof(ExtraData) == 0x58);

		class ItemDestroyedEvent
		{
		public:
			// members
			NiPointer<TESObjectREFR> workshop;         // 00
			NiPointer<TESObjectREFR> objectDestroyed;  // 08
		};
		static_assert(sizeof(ItemDestroyedEvent) == 0x10);

		class ItemMovedEvent
		{
		public:
			// members
			NiPointer<TESObjectREFR> workshop;   // 00
			NiPointer<TESObjectREFR> movedItem;  // 08
		};
		static_assert(sizeof(ItemMovedEvent) == 0x10);

		class ItemPlacedEvent
		{
		public:
			// members
			NiPointer<TESObjectREFR> workshop;    // 00
			NiPointer<TESObjectREFR> placedItem;  // 08
		};
		static_assert(sizeof(ItemPlacedEvent) == 0x10);

		class alignas(0x10) PlacementItemData
		{
		public:
			void Set(TESObjectREFR& a_refr)
			{
				using func_t = decltype(&PlacementItemData::Set);
				static REL::Relocation<func_t> func{ ID::Workshop::PlacementItemData::Set };
				return func(this, a_refr);
			}

			// members
			ObjectRefHandle                 placementItem;             // 00
			BSTArray<hknpShape*>            dropProxy;                 // 08
			BSTArray<bhkNPCollisionObject*> body;                      // 20
			std::byte                       pad38[0x80 - 0x38];        // 38 - TODO
			float                           sinkDepth;                 // 80
			float                           zOffset;                   // 84
			float                           intersectTolerance;        // 88
			float                           snapPointQueryRadius;      // 8C
			float                           forwardCastZRot;           // 90
			float                           xyBoundOverride;           // 94
			float                           xBoundMinOverride;         // 98
			float                           xBoundMaxOverride;         // 9C
			float                           yBoundMinOverride;         // A0
			float                           yBoundMaxOverride;         // A4
			float                           zBoundMinOverride;         // A8
			float                           zBoundMaxOverride;         // AC
			std::uint32_t                   dropProxyIndex;            // B0
			bool                            anythingIsGround;          // B4
			bool                            clampUp;                   // B5
			bool                            forwardCast;               // B6
			bool                            recenter;                  // B7
			bool                            ignoreSimpleIntersection;  // B8
			bool                            allowUnsupportedStacking;  // B9
			bool                            isSet;                     // BA
			bool                            mustSnap;                  // BB
			bool                            stacksWhenSnapped;         // BC
		};
		static_assert(sizeof(PlacementItemData) == 0xC0);

		class PlacementStatusEvent
		{
		public:
			// members
			PlacementStatusValue value;  // 00
		};
		static_assert(sizeof(PlacementStatusEvent) == 0x1);

		class WorkshopMenuNode
		{
		public:
			~WorkshopMenuNode() { Clear(); }

			void Clear()
			{
				filterKeyword = nullptr;
				parent = nullptr;
				recipe = nullptr;
				row = 0;
				column = 0;
				selected = false;
				children.clear();
			}

			bool FindAndSetSelectedNode(std::uint16_t a_row, std::uint32_t a_crc, std::uint16_t& a_outRow)
			{
				using func_t = decltype(&WorkshopMenuNode::FindAndSetSelectedNode);
				static REL::Relocation<func_t> func{ ID::Workshop::WorkshopMenuNode::FindAndSetSelectedNode };
				return func(this, a_row, a_crc, a_outRow);
			}

			F4_HEAP_REDEFINE_NEW(WorkshopMenuNode);

			// members
			BGSKeyword*                                 filterKeyword{ nullptr };                    // 00
			WorkshopMenuNode*                           parent{ nullptr };                           // 08
			BSTArray<std::unique_ptr<WorkshopMenuNode>> children;                                    // 10
			BGSConstructibleObject*                     recipe{ nullptr };                           // 28
			BGSConstructibleObject*                     sourceFormListRecipe{ nullptr };             // 30
			TESForm*                                    form{ nullptr };                             // 38
			std::uint32_t                               uniqueID{ static_cast<std::uint32_t>(-1) };  // 40
			std::uint16_t                               row{ 0 };                                    // 44
			std::uint16_t                               column{ 0 };                                 // 46
			bool                                        selected{ false };                           // 48
		};
		static_assert(sizeof(WorkshopMenuNode) == 0x50);

		class WorkshopModeEvent
		{
		public:
			// members
			NiPointer<TESObjectREFR> workshop;  // 00
			bool                     start;     // 08
		};
		static_assert(sizeof(WorkshopModeEvent) == 0x10);

		[[nodiscard]] inline TESObjectREFR* FindNearestValidWorkshop(const TESObjectREFR& a_refr)
		{
			using func_t = decltype(&Workshop::FindNearestValidWorkshop);
			static REL::Relocation<func_t> func{ ID::Workshop::FindNearestValidWorkshop };
			return func(a_refr);
		}

		[[nodiscard]] inline bool FreeBuild()
		{
			using func_t = decltype(&Workshop::FreeBuild);
			static REL::Relocation<func_t> func{ ID::Workshop::FreeBuild };
			return func();
		}

		[[nodiscard]] inline WorkshopMenuNode* GetSelectedWorkshopMenuNode(std::uint32_t a_row, std::uint32_t& a_column)
		{
			using func_t = decltype(&Workshop::GetSelectedWorkshopMenuNode);
			static REL::Relocation<func_t> func{ ID::Workshop::GetSelectedWorkshopMenuNode };
			return func(a_row, a_column);
		}

		inline void InitializePlacementReference(const ContextData& a_context, TESBoundObject& a_object)
		{
			using func_t = decltype(&Workshop::InitializePlacementReference);
			static REL::Relocation<func_t> func{ ID::Workshop::InitializePlacementReference };
			return func(a_context, a_object);
		}

		[[nodiscard]] inline bool IsLocationWithinBuildableArea(const TESObjectREFR& a_workshop, const NiPoint3& a_location)
		{
			using func_t = decltype(&Workshop::IsLocationWithinBuildableArea);
			static REL::Relocation<func_t> func{ ID::Workshop::IsLocationWithinBuildableArea };
			return func(a_workshop, a_location);
		}

		inline bool PlaceCurrentReference(const ContextData& a_context)
		{
			using func_t = decltype(&Workshop::PlaceCurrentReference);
			static REL::Relocation<func_t> func{ ID::Workshop::PlaceCurrentReference };
			return func(a_context);
		}

		inline void RegisterForItemDestroyed(BSTEventSink<ItemDestroyedEvent>* a_sink)
		{
			using func_t = decltype(&Workshop::RegisterForItemDestroyed);
			static REL::Relocation<func_t> func{ ID::Workshop::RegisterForItemDestroyed };
			return func(a_sink);
		}

		inline void RegisterForItemMoved(BSTEventSink<ItemMovedEvent>* a_sink)
		{
			using func_t = decltype(&Workshop::RegisterForItemMoved);
			static REL::Relocation<func_t> func{ ID::Workshop::RegisterForItemMoved };
			return func(a_sink);
		}

		inline void RegisterForItemPlaced(BSTEventSink<ItemPlacedEvent>* a_sink)
		{
			using func_t = decltype(&Workshop::RegisterForItemPlaced);
			static REL::Relocation<func_t> func{ ID::Workshop::RegisterForItemPlaced };
			return func(a_sink);
		}

		inline void RegisterForWorkshopModeEvent(BSTEventSink<WorkshopModeEvent>* a_sink)
		{
			using func_t = decltype(&Workshop::RegisterForWorkshopModeEvent);
			static REL::Relocation<func_t> func{ ID::Workshop::RegisterForWorkshopModeEvent };
			return func(a_sink);
		}

		inline void RequestExitWorkshop(bool a_allowReEntry)
		{
			using func_t = decltype(&Workshop::RequestExitWorkshop);
			static REL::Relocation<func_t> func{ ID::Workshop::RequestExitWorkshop };
			return func(a_allowReEntry);
		}

		inline void ScrapReference(const ContextData& a_context, BSPointerHandleSmartPointer<BSPointerHandleManagerInterface<TESObjectREFR, HandleManager>>& a_scrapRef, BSTArray<BSTTuple<TESBoundObject*, std::uint32_t>>* a_rewards)
		{
			using func_t = decltype(&Workshop::ScrapReference);
			static REL::Relocation<func_t> func{ ID::Workshop::ScrapReference };
			return func(a_context, a_scrapRef, a_rewards);
		}

		inline void SetSelectedEditItem(ObjectRefHandle a_refr)
		{
			using func_t = decltype(&Workshop::SetSelectedEditItem);
			static REL::Relocation<func_t> func{ ID::Workshop::SetSelectedEditItem };
			return func(a_refr);
		}

		inline void StartWorkshop(TESObjectREFR* a_workshopRef)
		{
			using func_t = decltype(&Workshop::StartWorkshop);
			static REL::Relocation<func_t> func{ ID::Workshop::StartWorkshop };
			return func(a_workshopRef);
		}

		inline void ToggleEditMode(const ContextData& a_context)
		{
			using func_t = decltype(&Workshop::ToggleEditMode);
			static REL::Relocation<func_t> func{ ID::Workshop::ToggleEditMode };
			return func(a_context);
		}

		inline void UnregisterForItemDestroyed(BSTEventSink<ItemDestroyedEvent>* a_sink)
		{
			using func_t = decltype(&Workshop::UnregisterForItemDestroyed);
			static REL::Relocation<func_t> func{ ID::Workshop::UnregisterForItemDestroyed };
			return func(a_sink);
		}

		inline void UnregisterForItemMoved(BSTEventSink<ItemMovedEvent>* a_sink)
		{
			using func_t = decltype(&Workshop::UnregisterForItemMoved);
			static REL::Relocation<func_t> func{ ID::Workshop::UnregisterForItemMoved };
			return func(a_sink);
		}

		inline void UnregisterForItemPlaced(BSTEventSink<ItemPlacedEvent>* a_sink)
		{
			using func_t = decltype(&Workshop::UnregisterForItemPlaced);
			static REL::Relocation<func_t> func{ ID::Workshop::UnregisterForItemPlaced };
			return func(a_sink);
		}

		inline void UnregisterForWorkshopModeEvent(BSTEventSink<WorkshopModeEvent>* a_sink)
		{
			using func_t = decltype(&Workshop::UnregisterForWorkshopModeEvent);
			static REL::Relocation<func_t> func{ ID::Workshop::UnregisterForWorkshopModeEvent };
			return func(a_sink);
		}

		inline void UpdateActiveEdit(const ContextData& a_context, bool a_multiselect = false)
		{
			using func_t = decltype(&Workshop::UpdateActiveEdit);
			static REL::Relocation<func_t> func{ ID::Workshop::UpdateActiveEdit };
			return func(a_context, a_multiselect);
		}

		[[nodiscard]] inline bool WorkshopCanShowRecipe(BGSConstructibleObject* a_recipe, BGSKeyword* a_filter)
		{
			using func_t = decltype(&Workshop::WorkshopCanShowRecipe);
			static REL::Relocation<func_t> func{ ID::Workshop::WorkshopCanShowRecipe };
			return func(a_recipe, a_filter);
		}

		[[nodiscard]] inline PlacementItemData* GetCurrentPlacementItemData()
		{
			static REL::Relocation<PlacementItemData*> value{ ID::Workshop::CurrentPlacementItemData };
			return value.get();
		}

		[[nodiscard]] inline std::uint16_t* GetCurrentRow()
		{
			static REL::Relocation<std::uint16_t*> value{ ID::Workshop::CurrentRow };
			return value.get();
		}

		[[nodiscard]] inline ObjectRefHandle* GetPlacementItem()
		{
			static REL::Relocation<ObjectRefHandle*> value{ ID::Workshop::PlacementItem };
			return value.get();
		}
	}
}
