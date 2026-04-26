#pragma once

#include "RE/B/BSInputEventSingleUser.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTEvent.h"
#include "RE/B/BSTHashMap.h"
#include "RE/B/BSTSingleton.h"
#include "RE/N/NiPointer.h"
#include "RE/Q/QuickContainerStateEvent.h"

namespace RE
{
	class QueuedFile;

	namespace BGSInventoryListEvent
	{
		class Event;
	}

	namespace FavoriteMgr_Events
	{
		class ComponentFavoriteEvent;
	}

	namespace InventoryInterface
	{
		class FavoriteChangedEvent;
	}

	class __declspec(novtable) FavoritesManager :
		public BSInputEventSingleUser,                                     // 000
		public BSTEventSink<BGSInventoryListEvent::Event>,                 // 020
		public BSTEventSink<InventoryInterface::FavoriteChangedEvent>,     // 028
		public BSTSingletonSDM<FavoritesManager>,                          // 030
		public BSTEventSource<FavoriteMgr_Events::ComponentFavoriteEvent>  // 038
	{
	public:
		static constexpr auto RTTI{ RTTI::FavoritesManager };
		static constexpr auto VTABLE{ VTABLE::FavoritesManager };

		enum class FAVORITE_SLOT
		{
			kLeft3 = 0x0,
			kLeft2 = 0x1,
			kLeft1 = 0x2,
			kRight1 = 0x3,
			kRight2 = 0x4,
			kRight3 = 0x5,
			kUp3 = 0x6,
			kUp2 = 0x7,
			kUp1 = 0x8,
			kDown1 = 0x9,
			kDown2 = 0xA,
			kDown3 = 0xB
		};

		[[nodiscard]] static FavoritesManager* GetSingleton()
		{
			static REL::Relocation<FavoritesManager**> singleton{ ID::FavoritesManager::Singleton };
			return *singleton;
		}

		[[nodiscard]] bool IsComponentFavorite(const TESBoundObject* a_component)
		{
			using func_t = decltype(&FavoritesManager::IsComponentFavorite);
			static REL::Relocation<func_t> func{ ID::FavoritesManager::IsComponentFavorite };
			return func(this, a_component);
		}

		[[nodiscard]] bool UseQuickkeyItem(std::uint32_t a_quickkeyIndex)
		{
			using func_t = decltype(&FavoritesManager::UseQuickkeyItem);
			static REL::Relocation<func_t> func{ ID::FavoritesManager::UseQuickkeyItem };
			return func(this, a_quickkeyIndex);
		}

		void ClearCurrentAmmoCount()
		{
			using func_t = decltype(&FavoritesManager::ClearCurrentAmmoCount);
			static REL::Relocation<func_t> func{ ID::FavoritesManager::ClearCurrentAmmoCount };
			return func(this);
		}

		// members
		TESBoundObject*                                  storedFavTypes[12];         // 090
		NiPointer<QueuedFile>                            bufferedFavGeometries[12];  // 0F0
		BSTSet<const BGSConstructibleObject*>            favoriteMods;               // 150
		BSTHashMap<const TESBoundObject*, std::uint32_t> favoritedComponents;        // 180
		BSTSmallArray<std::int32_t, 12>                  weaponLoadedAmmo;           // 1B0
		BSTValueEventSink<QuickContainerStateEvent>      quickContainerMode;         // 1F0
		bool                                             allowStimpakUse;            // 2C8
	};
	static_assert(sizeof(FavoritesManager) == 0x2D0);
}
