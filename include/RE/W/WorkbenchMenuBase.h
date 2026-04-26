#pragma once

#include "RE/B/BGSInventoryList.h"
#include "RE/B/BGSTypedFormValuePair.h"
#include "RE/B/BSPointerHandle.h"
#include "RE/B/BSTSmartPointer.h"
#include "RE/B/BSTTuple.h"
#include "RE/G/GameMenuBase.h"
#include "RE/I/Inventory3DManager.h"
#include "RE/I/InventoryInterface.h"
#include "RE/N/NiPointer.h"
#include "RE/R/Rumble.h"

namespace RE
{
	class ExtraDataList;
	class NiNode;

	class __declspec(novtable) WorkbenchMenuBase :
		public GameMenuBase  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::WorkbenchMenuBase };
		static constexpr auto VTABLE{ VTABLE::WorkbenchMenuBase };

		enum class HighlightMode
		{
			kModMenu,
			kAll,
			kWorld
		};

		class InitParams
		{
		public:
			InitParams();

			// members
			ObjectRefHandle            workbenchFurniture;                // 00
			ObjectRefHandle            inventorySource;                   // 04
			InventoryInterface::Handle item{ 0xFFFFFFFF };                // 08
			NiPointer<Actor>           actor{ nullptr };                  // 10
			std::uint32_t              stack{ 0 };                        // 18
			bool                       inspectMode{ true };               // 1C
			bool                       inspectingSingleItem{ false };     // 1D
			bool                       inspectingFeaturedItem{ false };   // 1E
			bool                       showFeaturedItemMessage{ false };  // 1F
			bool                       botCompanion{ false };             // 20
		};
		static_assert(sizeof(InitParams) == 0x28);

		class ModChoiceData
		{
		public:
			// members
			union
			{
				BGSMod::Attachment::Mod* mod;
				TESBoundObject*          object;
			};  // 00
			const BGSConstructibleObject*                                   recipe;         // 08
			BSTArray<BSTTuple<TESForm*, BGSTypedFormValuePair::SharedVal>>* requiredItems;  // 10
			BSTArray<BSTTuple<BGSPerk*, std::uint32_t>>                     requiredPerks;  // 18
			std::uint8_t                                                    rank;           // 30
			std::uint8_t                                                    index;          // 31
		};
		static_assert(sizeof(ModChoiceData) == 0x38);

		virtual ~WorkbenchMenuBase();  // 00

		// override (GameMenuBase)
		virtual void Call(const Params&) override;                                                               // 01
		virtual void MapCodeObjectFunctions() override;                                                          // 02
		virtual void PreDisplay() override;                                                                      // 05
		virtual void OnMenuStackChanged(const BSFixedString& a_topMenuName, bool a_passesTopMenuTest) override;  // 09

		// override (BSInputEventUser)
		virtual bool ShouldHandleEvent(const InputEvent*) override;       // 01
		virtual void OnThumbstickEvent(const ThumbstickEvent*) override;  // 04
		virtual void OnCursorMoveEvent(const CursorMoveEvent*) override;  // 05
		virtual void OnButtonEvent(const ButtonEvent*) override;          // 08

		// add
		virtual void                 OnHideMenu();                                 // 14
		virtual void                 UpdateMenu();                                 // 15
		virtual void                 BuildCanceled();                              // 16
		virtual void                 BuildConfirmed(bool a_ownerIsWorkbench) = 0;  // 17
		virtual bool                 GetWorkbenchHasInventory();                   // 18
		virtual const ModChoiceData* QCurrentModChoiceData();                      // 19
		virtual void                 ShowBuildFailureMessage();                    // 1A
		virtual bool                 TryCreate() = 0;                              // 1B

		void UpdateOptimizedAutoBuildInv()
		{
			using func_t = decltype(&WorkbenchMenuBase::UpdateOptimizedAutoBuildInv);
			static REL::Relocation<func_t> func{ ID::WorkbenchMenuBase::UpdateOptimizedAutoBuildInv };
			return func(this);
		}

		// members
		NiPointer<TESObjectREFR>                    sharedContainerRef;        // 0E0
		NiPointer<TESObjectREFR>                    workbenchContainerRef;     // 0E8
		BSTArray<NiPointer<TESObjectREFR>>          sharedContainers;          // 0F0
		Inventory3DManager                          inv3DModelManager;         // 110
		BGSInventoryList                            optimizedAutoBuildInv;     // 250
		BSTArray<ModChoiceData>                     modChoiceArray;            // 2D0
		std::uint32_t                               modChoiceIndex;            // 2E8
		std::uint32_t                               lastModChoiceIndex;        // 2EC
		bool                                        repairing;                 // 2F0
		bool                                        queueHide;                 // 2F1
		bool                                        hiding;                    // 2F2
		bool                                        VATSWasEnabled;            // 2F3
		NiPointer<TESObjectREFR>                    workbenchRef;              // 2F8
		BSTSmartPointer<ExtraDataList>              recipeExtraDataList;       // 300
		NiPointer<NiNode>                           item3DGeometry;            // 308
		BSTArray<TESForm*>                          queuedCraftingComponents;  // 310
		std::uint64_t                               soundTimer;                // 328
		REX::TEnumSet<HighlightMode, std::uint32_t> highlightMode;             // 330
		Rumble::AutoRumblePause                     autoRumblePause;           // 334
		bool                                        initialized;               // 335
		bool                                        soundsQueued;              // 336
	};
	static_assert(sizeof(WorkbenchMenuBase) == 0x340);
}
