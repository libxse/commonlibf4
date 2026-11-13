#pragma once

#include "RE/B/BSInputEventReceiver.h"
#include "RE/B/BSSpinLock.h"
#include "RE/B/BSTEvent.h"
#include "RE/B/BSTHashMap.h"
#include "RE/B/BSTSingleton.h"
#include "RE/B/BSTimer.h"
#include "RE/I/IMenu.h"
#include "RE/U/UIMenuEntry.h"

namespace RE
{
	class MenuModeChangeEvent;
	class MenuOpenCloseEvent;
	class MenuModeCounterChangedEvent;
	class TutorialEvent;

	class __declspec(novtable) UI :
		public BSInputEventReceiver,                         // 000
		public BSTSingletonSDM<UI>,                          // 010
		public BSTEventSource<MenuOpenCloseEvent>,           // 018
		public BSTEventSource<MenuModeChangeEvent>,          // 070
		public BSTEventSource<MenuModeCounterChangedEvent>,  // 0C8
		public BSTEventSource<TutorialEvent>                 // 120
	{
	public:
		static constexpr auto RTTI{ RTTI::UI };
		static constexpr auto VTABLE{ VTABLE::UI };

		using Create_t = typename UIMenuEntry::Create_t;
		using StaticUpdate_t = typename UIMenuEntry::StaticUpdate_t;

		// add
		virtual ~UI() = default;  // 01

		[[nodiscard]] bool CustomRendererHasQuads(const BSFixedString& a_customRendererName)
		{
			using func_t = decltype(&UI::CustomRendererHasQuads);
			static REL::Relocation<func_t> func{ ID::UI::CustomRendererHasQuads };
			return func(this, a_customRendererName);
		}

		template <class T>
		[[nodiscard]] BSTEventSource<T>* GetEventSource()
		{
			return static_cast<RE::BSTEventSource<T>*>(this);
		}

		[[nodiscard]] static BSReadWriteLock& GetMenuMapRWLock()
		{
			static REL::Relocation<BSReadWriteLock*> menuMapRWLock{ ID::UI::GetMenuMapRWLock };
			return *menuMapRWLock;
		}

		[[nodiscard]] static UI* GetSingleton()
		{
			static REL::Relocation<UI**> singleton{ ID::UI::Singleton };
			return *singleton;
		}

		[[nodiscard]] Scaleform::Ptr<IMenu> GetMenu(const BSFixedString& a_name) const
		{
			BSAutoReadLock l{ GetMenuMapRWLock() };
			const auto     it = menuMap.find(a_name);
			return it != menuMap.end() ? it->second.menu : nullptr;
		}

		[[nodiscard]] Scaleform::Ptr<IMenu> GetMenuByMovie(const Scaleform::GFx::Movie* a_movie) const
		{
			BSAutoReadLock l{ GetMenuMapRWLock() };
			const auto     it = std::find_if(menuMap.begin(), menuMap.end(), [a_movie](const auto& item) {
				return item.second.menu ? item.second.menu->uiMovie.get() == a_movie : false;
			});
			return it != menuMap.end() ? it->second.menu : nullptr;
		}

		template <class T>
		[[nodiscard]] Scaleform::Ptr<T> GetMenu() const
			requires(requires { T::MENU_NAME; })
		{
			const auto ptr = GetMenu(T::MENU_NAME);
			return Scaleform::Ptr{ static_cast<T*>(ptr.get()) };
		}

		[[nodiscard]] bool GetMenuOpen(const BSFixedString& a_name) const
		{
			const auto menu = GetMenu(a_name);
			return menu ? menu->OnStack() : false;
		}

		template <class T>
		[[nodiscard]] bool GetMenuOpen() const
			requires(requires { T::MENU_NAME; })
		{
			return GetMenuOpen(T::MENU_NAME);
		}

		void RefreshCursor()
		{
			using func_t = decltype(&UI::RefreshCursor);
			static REL::Relocation<func_t> func{ ID::UI::RefreshCursor };
			return func(this);
		}

		void RegisterMenu(const char* a_menu, Create_t* a_create, StaticUpdate_t* a_staticUpdate = nullptr)
		{
			using func_t = decltype(&UI::RegisterMenu);
			static REL::Relocation<func_t> func{ ID::UI::RegisterMenu };
			return func(this, a_menu, a_create, a_staticUpdate);
		}

		template <class T>
		void RegisterSink(BSTEventSink<T>* a_sink)
		{
			GetEventSource<T>()->RegisterSink(a_sink);
		}

		void UpdateControllerType()
		{
			using func_t = decltype(&UI::UpdateControllerType);
			static REL::Relocation<func_t> func{ ID::UI::UpdateControllerType };
			return func(this);
		}

		template <class T>
		void UnregisterSink(BSTEventSink<T>* a_sink)
		{
			GetEventSource<T>()->UnregisterSink(a_sink);
		}

		// members
		BSTArray<BSFixedString>                releasedMovies;              // 178
		BSTArray<Scaleform::Ptr<IMenu>>        menuStack;                   // 190
		BSTHashMap<BSFixedString, UIMenuEntry> menuMap;                     // 1A8
		BSSpinLock                             processMessagesLock;         // 1D8
		std::uint32_t                          menuMode;                    // 1E0
		BSTAtomicValue<std::uint32_t>          itemMenuMode;                // 1E4
		BSTAtomicValue<std::uint32_t>          pauseMenuDisableCt;          // 1E8
		std::uint32_t                          freezeFrameMenuBG;           // 1EC
		std::uint32_t                          freezeFramePause;            // 1F0
		std::uint32_t                          savingDisabled;              // 1F4
		std::uint32_t                          disablesCompanion;           // 1F8
		std::uint32_t                          largeCacheRenderModeCount;   // 1FC
		std::uint32_t                          movementToDirectionalCount;  // 200
		BSTimer                                uiTimer;                     // 208
		bool                                   menuSystemVisible;           // 258
		bool                                   closingAllMenus;             // 259
		bool                                   freezeFrameScreenshotReady;  // 25A
	};
	static_assert(sizeof(UI) == 0x260);
}
