#pragma once

#include "RE/E/ExamineConfirmMenu.h"
#include "RE/I/InventoryUserUIInterface.h"
#include "RE/W/WorkbenchMenuBase.h"

namespace RE
{
	enum class EQUIP_TYPE;
	class BGSObjectInstanceExtra;
	class BSInputEnableLayer;
	class NiAVObject;

	class __declspec(novtable) ExamineMenu :
		public WorkbenchMenuBase  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::ExamineMenu };
		static constexpr auto VTABLE{ VTABLE::ExamineMenu };
		static constexpr auto MENU_NAME{ "ExamineMenu"sv };

		enum class INSPECT_MODE_STATE
		{
			kModSlotSelect = 0,
			kSelectNewMod = 1,
			kInvComponentSelect = 2,
			kItemSelect = 3,
			kConfirm = 4
		};

		class ComponentBuilderFunctor
		{
		public:
			// members
			BSTArray<BSTTuple<BGSComponent*, std::uint8_t>> components;  // 00
			TESObjectMISC*                                  a_object;    // 18
			std::uint32_t                                   a_index;     // 20
		};
		static_assert(sizeof(ComponentBuilderFunctor) == 0x28);

		virtual ~ExamineMenu();  // 00

		// override (WorkbenchMenuBase)
		virtual void               Call(const Params&) override;                                    // 01
		virtual void               MapCodeObjectFunctions() override;                               // 02
		virtual UI_MESSAGE_RESULTS ProcessMessage(UIMessage& a_message) override;                   // 03
		virtual void               AdvanceMovie(float a_timeDelta, std::uint64_t a_time) override;  // 04
		virtual void               OnHideMenu() override;                                           // 14
		virtual void               BuildConfirmed(bool a_ownerIsWorkbench) override;                // 17
		virtual bool               TryCreate() override;                                            // 1B

		// override (BSInputEventUser)
		virtual bool ShouldHandleEvent(const InputEvent*) override;       // 01
		virtual void OnThumbstickEvent(const ThumbstickEvent*) override;  // 04
		virtual void OnCursorMoveEvent(const CursorMoveEvent*) override;  // 05
		virtual void OnButtonEvent(const ButtonEvent*) override;          // 08

		// add
		virtual EQUIP_TYPE              GetInventoryEntryEquipState(const InventoryUserUIInterfaceEntry& a_entry);                                                          // 1C
		virtual void                    ShowCurrent3D();                                                                                                                    // 1D
		virtual TESBoundObject*         GetCurrentObj();                                                                                                                    // 1E
		virtual void                    FindWeaponMods(TESBoundObject* a_object, Scaleform::GFx::Value& a_modList);                                                         // 1F
		virtual void                    BuildPossibleModList(TESBoundObject* a_object);                                                                                     // 20
		virtual void                    SwitchMod(std::int32_t a_index, Scaleform::GFx::Value& a_entryList);                                                                // 21
		virtual void                    NextItemPart();                                                                                                                     // 22
		virtual void                    PreviousItemPart();                                                                                                                 // 23
		virtual void                    AttachModToPreview(bool a_storeModelPosition);                                                                                      // 24
		virtual BGSObjectInstanceExtra* GetInitialObjectInstanceExtra();                                                                                                    // 25
		virtual BGSObjectInstanceExtra* GetObjectInstanceExtra();                                                                                                           // 26
		virtual const ExtraDataList*    GetItemExtraDataList();                                                                                                             // 27
		virtual void                    HighlightWeaponPart();                                                                                                              // 28
		virtual void                    ResetHighlight();                                                                                                                   // 29
		virtual void                    CreateModdedInventoryItem();                                                                                                        // 2A
		virtual void                    RevertToInventoryItem();                                                                                                            // 2B
		virtual const char*             GetCurrentName();                                                                                                                   // 2C
		virtual void                    RenameCurrent(const char* a_newName);                                                                                               // 2D
		virtual void                    UpdateItemCard(bool a_compare);                                                                                                     // 2E
		virtual void                    UpdateItemList(std::int32_t a_indexToSelect);                                                                                       // 2F
		virtual const char*             GetBuildConfirmButtonLabel();                                                                                                       // 30
		virtual void                    GetBuildConfirmQuestion(char* a_buffer, std::uint32_t a_bufferLength);                                                              // 31
		virtual bool                    GetCanRepairSelectedItem();                                                                                                         // 32
		virtual NiAVObject*             GetCurrent3D();                                                                                                                     // 33
		virtual bool                    GetCurrent3DLoaded();                                                                                                               // 34
		virtual bool                    GetIsValidInventoryItem(const BGSInventoryItem& a_item, std::uint32_t a_stackID);                                                   // 35
		virtual const char*             GetMenuName();                                                                                                                      // 36
		virtual void                    OnSwitchBaseItem();                                                                                                                 // 37
		virtual void                    PopulateInventoryItemObj(ObjectRefHandle a_owner, const InventoryUserUIInterfaceEntry& a_entry, Scaleform::GFx::Value& a_itemObj);  // 38
		virtual void                    RegisterMenuComponents(const Scaleform::GFx::FunctionHandler::Params& a_params);                                                    // 39
		virtual void                    RepairSelectedItem();                                                                                                               // 3A
		virtual void                    SetFilter();                                                                                                                        // 3B
		virtual void                    SetMouseRotation(bool a_rotation);                                                                                                  // 3C
		virtual void                    ToggleItemEquipped();                                                                                                               // 3D
		virtual void                    UpdateModSlotList();                                                                                                                // 3E
		virtual void                    UpdateModChoiceList();                                                                                                              // 3F
		virtual const char*             GetRankSuffix(std::uint32_t a_rank);                                                                                                // 40
		virtual bool                    QIgnoreRank();                                                                                                                      // 41
		virtual bool                    ShouldInitToFirstMod();                                                                                                             // 42
		virtual void                    SetDataForConditionCheck();                                                                                                         // 43
		virtual bool                    AddLooseModToModChoiceArray(BGSMod::Attachment::Mod* a_mod, std::uint8_t a_rank);                                                   // 44
		virtual bool                    ShouldShowModSlot(const BGSKeyword* a_keyword);                                                                                     // 45

		void BuildWeaponScrappingArray()
		{
			using func_t = decltype(&ExamineMenu::BuildWeaponScrappingArray);
			static REL::Relocation<func_t> func{ ID::ExamineMenu::BuildWeaponScrappingArray };
			return func(this);
		}

		[[nodiscard]] std::uint32_t GetSelectedIndex()
		{
			using func_t = decltype(&ExamineMenu::GetSelectedIndex);
			static REL::Relocation<func_t> func{ ID::ExamineMenu::GetSelectedIndex };
			return func(this);
		}

		void ShowConfirmMenu(ExamineConfirmMenu::InitData* a_data, ExamineConfirmMenu::ICallback* a_callback)
		{
			using func_t = decltype(&ExamineMenu::ShowConfirmMenu);
			static REL::Relocation<func_t> func{ ID::ExamineMenu::ShowConfirmMenu };
			return func(this, a_data, a_callback);
		}

		void ConsumeSelectedItems(bool a_autoBuild, const BGSSoundDescriptorForm* a_consumeSound)
		{
			using func_t = decltype(&ExamineMenu::ConsumeSelectedItems);
			static REL::Relocation<func_t> func{ ID::ExamineMenu::ConsumeSelectedItems };
			return func(this, a_autoBuild, a_consumeSound);
		}

		// members
		ComponentBuilderFunctor                            componentFunctor;                    // 340
		REX::TEnumSet<INSPECT_MODE_STATE, std::uint32_t>   inspectModeState;                    // 368
		ObjectRefHandle                                    inventorySource;                     // 36C
		InventoryUserUIInterface                           invInterface;                        // 370
		InventoryInterface::Handle                         modItem;                             // 3F0
		std::uint32_t                                      modStack;                            // 3F4
		BSTHashMap<std::uint32_t, std::uint32_t>           scrappableItemsMap;                  // 3F8
		BSTArray<BSTTuple<TESBoundObject*, std::uint32_t>> scrappingArray;                      // 420
		BSTArray<BSTTuple<NiAVObject*, BGSKeyword const*>> slotObjects;                         // 440
		BSTSmartPointer<ExtraDataList>                     extraDataList;                       // 458
		std::uint32_t                                      slotObjectIndex;                     // 460
		Scaleform::GFx::Value                              buttonAnimBase;                      // 468
		Scaleform::GFx::Value                              itemList;                            // 488
		Scaleform::GFx::Value                              itemNameTextField;                   // 4A8
		Scaleform::GFx::Value                              itemInfoList;                        // 4C8
		Scaleform::GFx::Value                              modChoiceList;                       // 4E8
		Scaleform::GFx::Value                              modSlotList;                         // 508
		Scaleform::GFx::Value                              currentModsList;                     // 528
		BGSInventoryItem                                   moddedInventoryItem;                 // 548
		bool                                               queueItemHighlight;                  // 558
		float                                              zoomDistance;                        // 55C
		float                                              lastFrameDelta;                      // 560
		float                                              menuCursorLeftPct;                   // 564
		float                                              menuCursorRightPct;                  // 568
		float                                              menuCursorTopPct;                    // 56C
		float                                              menuCursorBottomPct;                 // 570
		BSTArray<BGSComponent*>                            queuedSoundArray;                    // 578
		std::byte                                          attachPointSource3D[0x598 - 0x590];  // 590 - TODO
		const BGSMod::Attachment::Mod*                     nullMod;                             // 598
		Scaleform::GFx::Value                              requirementsList;                    // 5A0
		Scaleform::GFx::Value                              itemSelectList;                      // 5C0
		const BGSKeyword*                                  keyword;                             // 5E0
		bool                                               queueChangeCameraPosition;           // 5E8
		bool                                               returnToInspect;                     // 5E9
		bool                                               highlightStoredItem;                 // 5EA
		bool                                               textEntry;                           // 5EB
		bool                                               virtualKeyboardPendingEvt;           // 5EC
		bool                                               inspectMode;                         // 5ED
		bool                                               inspectingSingleItem;                // 5EE
		bool                                               inspectingFeaturedItem;              // 5EF
		bool                                               showFeaturedItemMessage;             // 5F0
		char                                               renameItemTo[260];                   // 5F1
		char                                               renameItemCancelState[260];          // 6F5
		BSTSmartPointer<BSInputEnableLayer>                inputLayer;                          // 800
	};
	static_assert(sizeof(ExamineMenu) == 0x810);
}
