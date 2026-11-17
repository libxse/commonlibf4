#pragma once

#include "RE/B/BSContainer.h"
#include "RE/B/BSSimpleList.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTEvent.h"
#include "RE/B/BSTTuple.h"
#include "RE/N/NiPointer.h"

namespace RE
{
	class BSCullingProcess;
	class GridCellArray;
	class GridDistantArray;
	class ImageSpaceModifierInstance;
	class LoadedAreaBound;
	class NavMeshInfoMap;
	class NiAVObject;
	class NiDirectionalLight;
	class NiFogProperty;
	class NiNode;
	class NiPoint3;
	class NiTexture;
	class PositionPlayerEvent;
	class QueuedFile;
	class Sky;
	class TESObjectCELL;
	class TESObjectREFR;
	class TESRegion;
	class TESWorldSpace;

	namespace BSResource::Archive2
	{
		class StreamOpenedEvent;
	}

	class TES :
		public BSTEventSink<BSResource::Archive2::StreamOpenedEvent>,  // 000
		public BSTEventSink<PositionPlayerEvent>                       // 008
	{
	public:
		static constexpr auto RTTI{ RTTI::TES };
		static constexpr auto VTABLE{ VTABLE::TES };

		using TACCallbackFunc_t = void(TESObjectCELL*, void*, void*);

		[[nodiscard]] bool IsCellLoaded(TESObjectCELL* a_cell, bool a_requireFullyLoaded)
		{
			using func_t = decltype(&TES::IsCellLoaded);
			static REL::Relocation<func_t> func{ ID::TES::IsCellLoaded };
			return func(this, a_cell, a_requireFullyLoaded);
		}

		enum class PICKWORLD_NODE
		{
			kActors = 0x1,
			kMarkers = 0x2,
			kLand = 0x4,
			kStatic = 0x8,
			kActive = 0x10,
			kAll = 0x1F,
		};

		enum class TACMode
		{
			kAll = 0x0,
			kMainWorldOnly = 0x1,
			kOtherWorldsOnly = 0x2,
			kInteriorsOnly = 0x3,
			kSpecifiedWorldOnly = 0x4
		};

		enum class TAC_CONTROL : std::uint32_t
		{
			kStop = 0xFFFFFFFF,
			kContinue = 0x0,
			kAllStandard = 0x1,
			kInteriorsStandard = 0x2,
			kStartInCurrentCell = 0x3,
			kAllSaves = 0x4,
			kAllSavesAfterChangingObjects = 0x5,
			kAllRenderTest = 0x6,
			kInteriorsRenderTest = 0x7,
			kRegionFilter = 0x8,
			kAllFileUsage = 0x9,
			kAllGraphicsTest = 0xA,
			kAllGraphicsTestLimited = 0xB
		};

		class ParticleObjectCache
		{
		public:
			// members
			NiPointer<NiAVObject>  model;   // 00
			NiPointer<NiAVObject>* clones;  // 08
			ParticleObjectCache*   next;    // 10
		};
		static_assert(sizeof(ParticleObjectCache) == 0x18);

		virtual ~TES();  // 00

		// override (BSTEventSink<BSResource::ArchiveStreamOpenedEvent>)
		BSEventNotifyControl ProcessEvent(const BSResource::Archive2::StreamOpenedEvent& a_event, BSTEventSource<BSResource::Archive2::StreamOpenedEvent>* a_eventSource) override;  // 01 - { return BSEventNotifyControl::kContinue; }

		// override (BSTEventSink<PositionPlayerEvent>)
		BSEventNotifyControl ProcessEvent(const PositionPlayerEvent& a_event, BSTEventSource<PositionPlayerEvent>* a_eventSource) override;  // 01

		[[nodiscard]] static TES* GetSingleton()
		{
			static REL::Relocation<TES**> singleton{ ID::TES::Singleton };
			return *singleton;
		}

		void ForEachReference(std::function<BSContainer::ForEachResult(TESObjectREFR* a_ref)> a_callback);
		void ForEachReferenceInRange(const NiPoint3& a_origin, const float a_radius, std::function<BSContainer::ForEachResult(TESObjectREFR* a_ref)> a_callback);
		void ForEachReferenceInRange(const TESObjectREFR* a_ref, const float a_radius, std::function<BSContainer::ForEachResult(TESObjectREFR* a_ref)> a_callback);

		void UpdateMultiBoundVisibility(BSCullingProcess* a_cullingProcess)
		{
			using func_t = decltype(&TES::UpdateMultiBoundVisibility);
			static REL::Relocation<func_t> func{ ID::TES::UpdateMultiBoundVisibility };
			return func(this, a_cullingProcess);
		}

		// members
		GridDistantArray*                                   gridDistant;                    // 010
		GridCellArray*                                      gridCells;                      // 018
		NiNode*                                             objRoot;                        // 020
		NiNode*                                             lodLandRoot;                    // 028
		NiNode*                                             objLODWaterRoot;                // 030
		NiDirectionalLight*                                 objLight;                       // 038
		NiFogProperty*                                      objFog;                         // 040
		std::int32_t                                        currentGridX;                   // 044
		std::int32_t                                        currentGridY;                   // 048
		std::int32_t                                        currentQueuedX;                 // 04C
		std::int32_t                                        currentQueuedY;                 // 050
		TESObjectCELL*                                      interiorCell;                   // 058
		TESObjectCELL**                                     interiorBuffer;                 // 060
		TESObjectCELL**                                     exteriorBuffer;                 // 068
		std::uint32_t                                       tempInteriorBufferSize;         // 070
		std::uint32_t                                       tempExteriorBufferSize;         // 074
		std::int32_t                                        saveGridX;                      // 078
		std::int32_t                                        saveGridY;                      // 07C
		TACCallbackFunc_t*                                  tacCallbackFunc;                // 080
		void*                                               tacCallbackData;                // 088
		TESRegion*                                          tacRegionFilter;                // 090
		Sky*                                                sky;                            // 098
		BSSimpleList<NiPointer<ImageSpaceModifierInstance>> activeImageSpaceModifiers;      // 0A0
		std::uint32_t                                       totalToLoad;                    // 0B0
		std::uint32_t                                       loaded;                         // 0B4
		std::uint64_t                                       cellCaptureStartTime;           // 0B8
		bool                                                disablePercentageUpdate;        // 0C0
		bool                                                showLANDborders;                // 0C1
		bool                                                fadeWhenLoading;                // 0C2
		bool                                                forceUpdateMultiBoundExterior;  // 0C3
		bool                                                collisionBoxes;                 // 0C4
		bool                                                runningCellTests;               // 0C5
		bool                                                runningCellTests2;              // 0C6
		bool                                                runningGraphicsTests;           // 0C7
		bool                                                runningCellListGraphicsTests;   // 0C8
		bool                                                runningSubmergedObjectTest;     // 0C9
		bool                                                allowUnusedPurge;               // 0CA
		float                                               cellDeltaX;                     // 0D0
		float                                               cellDeltaY;                     // 0D4
		TESWorldSpace*                                      worldSpace;                     // 0D8
		BSTArray<BSTTuple<TESActorBase*, std::uint16_t>>    deadCount;                      // 0E0
		NiPointer<QueuedFile>                               preloadedAddonNodes;            // 0F8
		NiPointer<NiTexture>                                bloodDecalPreload1;             // 100
		NiPointer<QueuedFile>                               preloadedForms;                 // 108
		NiPointer<QueuedFile>                               preloadedDefaultModels;         // 110
		ParticleObjectCache*                                particleCacheHead;              // 118
		std::uint32_t                                       placeableWaterCount;            // 120
		NavMeshInfoMap*                                     navMeshInfoMap;                 // 128
		NiPointer<LoadedAreaBound>                          loadedAreaBound;                // 130
	};
	static_assert(sizeof(TES) == 0x138);
}
