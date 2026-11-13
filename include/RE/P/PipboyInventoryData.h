#pragma once

#include "RE/B/BGSInventoryItem.h"
#include "RE/B/BSFixedString.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTEvent.h"
#include "RE/B/BSTHashMap.h"
#include "RE/E/ENUM_FORM_ID.h"
#include "RE/I/InventoryInterface.h"
#include "RE/P/PipboyDataGroup.h"

namespace RE
{
	namespace ActorEquipManagerEvent
	{
		class Event;
	}

	namespace ActorValueEvents
	{
		class ActorValueChangedEvent;
	}

	namespace BGSInventoryItemEvent
	{
		class Event;
	}

	namespace BGSInventoryListEvent
	{
		class Event;
	}

	namespace HolotapeStateChanged
	{
		class Event;
	}

	namespace InventoryInterface
	{
		class FavoriteChangedEvent;
	}

	namespace FavoriteMgr_Events
	{
		class ComponentFavoriteEvent;
	}

	namespace PerkValueEvents
	{
		class PerkValueChangedEvent;
		class PerkEntryUpdatedEvent;
	}

	namespace PlayerDifficultySettingChanged
	{
		class Event;
	}

	class PipboyInventoryData :
		public PipboyDataGroup,                                           // 00
		public BSTEventSink<BGSInventoryListEvent::Event>,                // 98
		public BSTEventSink<ActorEquipManagerEvent::Event>,               // A0
		public BSTEventSink<ActorValueEvents::ActorValueChangedEvent>,    // A8
		public BSTEventSink<PerkValueEvents::PerkEntryUpdatedEvent>,      // B0
		public BSTEventSink<PerkValueEvents::PerkValueChangedEvent>,      // B8
		public BSTEventSink<InventoryInterface::FavoriteChangedEvent>,    // C0
		public BSTEventSink<HolotapeStateChanged::Event>,                 // C8
		public BSTEventSink<BGSInventoryItemEvent::Event>,                // D0
		public BSTEventSink<FavoriteMgr_Events::ComponentFavoriteEvent>,  // D8
		public BSTEventSink<PlayerDifficultySettingChanged::Event>        // E0
	{
	public:
		static constexpr auto RTTI{ RTTI::PipboyInventoryData };
		static constexpr auto VTABLE{ VTABLE::PipboyInventoryData };

		virtual ~PipboyInventoryData();

		enum class ENTRY_TYPE
		{
			kInt = 0x0,
			kFixedString = 0x1,
			kFloat = 0x1
		};

		enum class ITEM_ICON_ID
		{
			kNone = 0x1,
			kBasicPistol = 0x2,
			kLaserPistol = 0x3,
			kPlasmaPistol = 0x4,
			kShotgun = 0x5,
			kBasicRifle = 0x6,
			kAssaultRifle = 0x7,
			kGaussRifle = 0x8,
			kLaserMusket = 0x9,
			kLaserRifle = 0xA,
			kPlasmaRifle = 0xB,
			k1hMelee = 0xC,
			k2hMelee = 0xD,
			kH2hWeap = 0xE,
			kMissileLauncher = 0xF,
			kFatman = 0x10,
			kMinigun = 0x11,
			kGatlingLaser = 0x12,
			kCryolator = 0x13,
			kFlamer = 0x14,
			kFlareGun = 0x15,
			kGammaGun = 0x16,
			kJunkJet = 0x17,
			kRailwayRifle = 0x18,
			kSyringer = 0x19,
			kBroadsider = 0x1A,
			kAlienBlaster = 0x1B,
			kRipper = 0x1C,
			kShishkebab = 0x1D,
			kThrownWeap = 0x1E,
			kExplosiveMine = 0x1F,
			kBottlecapMine = 0x20,
			kCryoMine = 0x21,
			kCryoGrenade = 0x22,
			kPlasmaMine = 0x23,
			kPlasmaGrenade = 0x24,
			kPulseMine = 0x25,
			kPulseGrenade = 0x26,
			kMolotov = 0x27,
			kNukaGrenade = 0x28,
			kRepairKit = 0x29,
			kSurgeryKit = 0x2A,
			kArmor = 0x2B,
			kGloves = 0x2C,
			kHelmet = 0x2D,
			kBook = 0x2E,
			kClothes = 0x2F,
			kAmmo = 0x30,
			kAdrenaline = 0x31,
			kDisease = 0x32,
			kSleep = 0x33,
			kHunger = 0x34,
			kThirst = 0x35,
			kChems = 0x36,
			kStimpak = 0x37,
			kFood = 0x38,
			kAlcohol = 0x39,
			kStealthBoy = 0x3A,
			kUnknown = 0x3B,
			kMax = 0x3B
		};

		enum class SORT_ON_FIELD
		{
			kAlphabetically = 0x0,
			kDamage = 0x1,
			kRof = 0x2,
			kRange = 0x3,
			kAccuracy = 0x4,
			kValue = 0x5,
			kWeight = 0x6
		};

		class StackEntry
		{
		public:
			// members
			PipboyObject*                    linkedObject;     // 00
			const InventoryInterface::Handle inventoryHandle;  // 08
		};
		static_assert(sizeof(StackEntry) == 0x10);

		class ItemEntry
		{
		public:
			// members
			void* stackEntries;  // 00 - BSTList<PipboyInventoryData::StackEntry*>
		};
		static_assert(sizeof(ItemEntry) == 0x8);

		// override
		virtual BSEventNotifyControl ProcessEvent(const PipboyValueChangedEvent& a_event, BSTEventSource<PipboyValueChangedEvent>* a_source);  // 01

		// add
		virtual BSEventNotifyControl ProcessEvent(const BGSInventoryListEvent::Event& a_event, BSTEventSource<BGSInventoryListEvent::Event>* a_source);                              // 02
		virtual BSEventNotifyControl ProcessEvent(const ActorEquipManagerEvent::Event& a_event, BSTEventSource<ActorEquipManagerEvent::Event>* a_source);                            // 03
		virtual BSEventNotifyControl ProcessEvent(const ActorValueEvents::ActorValueChangedEvent& a_event, BSTEventSource<ActorValueEvents::ActorValueChangedEvent>* a_source);      // 04
		virtual BSEventNotifyControl ProcessEvent(const PerkValueEvents::PerkEntryUpdatedEvent& a_event, BSTEventSource<PerkValueEvents::PerkEntryUpdatedEvent>* a_source);          // 05
		virtual BSEventNotifyControl ProcessEvent(const PerkValueEvents::PerkValueChangedEvent& a_event, BSTEventSource<PerkValueEvents::PerkValueChangedEvent>* a_source);          // 06
		virtual BSEventNotifyControl ProcessEvent(const InventoryInterface::FavoriteChangedEvent& a_event, BSTEventSource<InventoryInterface::FavoriteChangedEvent>* a_source);      // 07
		virtual BSEventNotifyControl ProcessEvent(const HolotapeStateChanged::Event& a_event, BSTEventSource<HolotapeStateChanged::Event>* a_source);                                // 08
		virtual BSEventNotifyControl ProcessEvent(const BGSInventoryItemEvent::Event& a_event, BSTEventSource<BGSInventoryItemEvent::Event>* a_source);                              // 09
		virtual BSEventNotifyControl ProcessEvent(const FavoriteMgr_Events::ComponentFavoriteEvent& a_event, BSTEventSource<FavoriteMgr_Events::ComponentFavoriteEvent>* a_source);  // 0A
		virtual BSEventNotifyControl ProcessEvent(const PlayerDifficultySettingChanged::Event& a_event, BSTEventSource<PlayerDifficultySettingChanged::Event>* a_source);            // 0B

		virtual void Populate(bool a_arg1);  // 0C
		virtual void DoClearData();          // 0D
		virtual void DoClearSink();          // 0E

		void AddItemCardInfoEntry(const BSFixedStringCS* a_string, float a_value, PipboyArray* a_itemCardSection)
		{
			using func_t = decltype(&PipboyInventoryData::AddItemCardInfoEntry);
			static REL::Relocation<func_t> func{ ID::PipboyInventoryData::AddItemCardInfoEntry };
			return func(this, a_string, a_value, a_itemCardSection);
		}

		PipboyObject* BaseAddItemCardInfoEntry(const BSFixedStringCS* a_string, PipboyArray* a_itemCardSection)
		{
			using func_t = decltype(&PipboyInventoryData::BaseAddItemCardInfoEntry);
			static REL::Relocation<func_t> func{ ID::PipboyInventoryData::BaseAddItemCardInfoEntry };
			return func(this, a_string, a_itemCardSection);
		}

		void PopulateItemCardInfo(const BGSInventoryItem* a_inventoryItem, const BGSInventoryItem::Stack* a_stack, PipboyObject* a_data)
		{
			using func_t = decltype(&PipboyInventoryData::PopulateItemCardInfo);
			static REL::Relocation<func_t> func{ ID::PipboyInventoryData::PopulateItemCardInfo };
			return func(this, a_inventoryItem, a_stack, a_data);
		}

		void QueueItemCardRepopulate(ENUM_FORM_ID a_formType)
		{
			using func_t = decltype(&PipboyInventoryData::QueueItemCardRepopulate);
			static REL::Relocation<func_t> func{ ID::PipboyInventoryData::QueueItemCardRepopulate };
			return func(this, a_formType);
		}

		void RepopulateItemCardOnSection(ENUM_FORM_ID a_itemTypeID)
		{
			using func_t = decltype(&PipboyInventoryData::RepopulateItemCardOnSection);
			static REL::Relocation<func_t> func{ ID::PipboyInventoryData::RepopulateItemCardOnSection };
			return func(this, a_itemTypeID);
		}

		void SortItems(SORT_ON_FIELD a_sortType)
		{
			using func_t = decltype(&PipboyInventoryData::SortItems);
			static REL::Relocation<func_t> func{ ID::PipboyInventoryData::SortItems };
			return func(this, a_sortType);
		}

		// members
		PipboyObject*                                             inventoryObject;             // E8
		BSTHashMap<std::uint32_t, PipboyInventoryData::ItemEntry> itemEntries;                 // F0
		BSTHashMap<const BGSComponent*, PipboyObject*>            invComponents;               // 120
		BSTArray<PipboyObject*>                                   sortedItems;                 // 150
		BSTSet<ENUM_FORM_ID>                                      queuedRepopulateCategories;  // 168
	};
	static_assert(sizeof(PipboyInventoryData) == 0x198);
}
