#pragma once

#include "RE/B/BSPointerHandle.h"
#include "RE/B/BSTEvent.h"
#include "RE/D/DisableHeavyItemsFunc.h"
#include "RE/G/GameMenuBase.h"
#include "RE/I/Inventory3DManager.h"
#include "RE/I/InventoryUserUIInterface.h"
#include "RE/R/Rumble.h"

namespace RE
{
	enum class ContainerMenuMode;
	class MenuOpenCloseEvent;

	class __declspec(novtable) ContainerMenuBase :
		public GameMenuBase,                                // 000
		public BSTEventSink<InvInterfaceStateChangeEvent>,  // 0E0
		public BSTEventSink<MenuOpenCloseEvent>             // 0E8
	{
	public:
		static constexpr auto RTTI{ RTTI::ContainerMenuBase };
		static constexpr auto VTABLE{ VTABLE::ContainerMenuBase };

		class __declspec(novtable) FXQuantityMenu :
			public BSGFxShaderFXTarget  // 000
		{
		public:
			// members
			BSGFxShaderFXTarget label;                  // 0B0
			BSGFxShaderFXTarget value;                  // 160
			BSGFxShaderFXTarget quantityBracketHolder;  // 210
		};
		static_assert(sizeof(FXQuantityMenu) == 0x2C0);

		class ItemSorter
		{
		public:
			enum class SORT_ON_FIELD
			{
				kAlphabetical = 0x0,
				kDamage = 0x1,
				kRateOfFire = 0x2,
				kRange = 0x3,
				kAccuracy = 0x4,
				kValue = 0x5,
				kWeight = 0x6,
			};

			void IncrementSort()
			{
				using func_t = decltype(&ItemSorter::IncrementSort);
				static REL::Relocation<func_t> func{ ID::ContainerMenuBase::ItemSorter::IncrementSort };
				return func(this);
			}

			void SetTab(std::uint32_t a_tab)
			{
				currentTab = a_tab;
			}

			// members
			REX::TEnumSet<SORT_ON_FIELD, std::uint32_t> currentSort[14];  // 00
			std::uint32_t                               currentTab;       // 38
		};
		static_assert(sizeof(ItemSorter) == 0x3C);

		// override
		virtual void Call(const Params&) override;                                    // 01
		virtual void MapCodeObjectFunctions() override;                               // 02
		virtual void AdvanceMovie(float a_timeDelta, std::uint64_t a_time) override;  // 04
		virtual void PreDisplay() override;                                           // 05

		// add
		virtual void                                 ConfirmInvestment() { return; }                                                                                                                          // 14
		virtual void                                 DoItemTransfer(std::uint32_t a_itemIndex, std::uint32_t a_count, bool a_fromContainer) = 0;                                                              // 15
		virtual bool                                 GetDisplayBarterValues() { return false; }                                                                                                               // 16
		virtual bool                                 GetCanEquipItem([[maybe_unused]] std::uint32_t a_itemIndex, [[maybe_unused]] bool a_inContainer) { return false; }                                       // 17
		virtual bool                                 GetIsItemEquipped([[maybe_unused]] std::uint32_t a_itemIndex, [[maybe_unused]] bool a_inContainer) { return false; }                                     // 18
		virtual void                                 ToggleItemEquipped([[maybe_unused]] std::uint32_t a_itemIndex, [[maybe_unused]] bool a_inContainer) { return; }                                          // 19
		virtual std::uint32_t                        GetItemValue(std::uint32_t a_itemIndex, bool a_inContainer);                                                                                             // 1A
		virtual const InventoryUserUIInterfaceEntry* GetInventoryItemByListIndex(bool a_inContainer, std::uint32_t a_index);                                                                                  // 1B
		virtual void                                 PopulateMenuObj(ObjectRefHandle a_inventoryRef, const InventoryUserUIInterfaceEntry& a_entry, Scaleform::GFx::Value& a_menuObj) = 0;                     // 1C
		virtual void                                 SetMenuSuppressed(bool a_suppressed);                                                                                                                    // 1D
		virtual void                                 UpdateEncumbranceAndCaps(bool a_inContainer, std::int32_t a_capsDifferential);                                                                           // 1E
		virtual void                                 UpdateItemPickpocketInfo([[maybe_unused]] std::int32_t a_index, [[maybe_unused]] bool a_inContainer, [[maybe_unused]] std::int32_t a_count) { return; }  // 1F
		virtual void                                 UpdateList(bool a_inContainer) = 0;                                                                                                                      // 20

		void SetMessageBoxMode(bool a_messageBoxMode)
		{
			if (menuObj.IsObject() && menuObj.HasMember("messageBoxIsActive"sv)) {
				menuObj.SetMember("messageBoxIsActive"sv, a_messageBoxMode);
			}
		}

		// members
		ItemSorter                                      containerItemSorter;            // 0F0
		ItemSorter                                      playerItemSorter;               // 12C
		std::unique_ptr<BSGFxShaderFXTarget>            playerBracketBackground_mc;     // 168
		std::unique_ptr<BSGFxShaderFXTarget>            containerBracketBackground_mc;  // 170
		std::unique_ptr<BSGFxShaderFXTarget>            containerList_mc;               // 178
		std::unique_ptr<BSGFxShaderFXTarget>            playerInventory_mc;             // 180
		std::unique_ptr<BSGFxShaderFXTarget>            containerInventory_mc;          // 188
		std::unique_ptr<BSGFxShaderFXTarget>            itemCard_mc;                    // 190
		std::unique_ptr<FXQuantityMenu>                 quantityMenu_mc;                // 198
		InventoryUserUIInterface                        playerInv;                      // 1A0
		InventoryUserUIInterface                        containerInv;                   // 220
		Inventory3DManager                              inv3DModelManager;              // 2A0
		BSTArray<const TESBoundObject*>                 partialPlayerUpdateList;        // 3E0
		BSTArray<const TESBoundObject*>                 partialContainerUpdateList;     // 3F8
		REX::TEnumSet<ContainerMenuMode, std::uint32_t> menuMode;                       // 410
		Rumble::AutoRumblePause                         autoRumblePause;                // 414
		DisableHeavyItemsFunc                           disableHeavyFunc;               // 418
		ObjectRefHandle                                 containerRef;                   // 428
		bool                                            suppressed;                     // 42C
		bool                                            menuOpening;                    // 42D
	};
	static_assert(sizeof(ContainerMenuBase) == 0x430);
}
