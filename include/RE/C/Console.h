#pragma once

#include "RE/B/BSPointerHandle.h"
#include "RE/G/GameMenuBase.h"
#include "RE/R/Rumble.h"

namespace RE
{
	class __declspec(novtable) Console :
		public GameMenuBase  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::Console };
		static constexpr auto VTABLE{ VTABLE::Console };
		static constexpr auto MENU_NAME{ "Console"sv };

		static void ExecuteCommand(const char* a_command)
		{
			using func_t = decltype(&Console::ExecuteCommand);
			static REL::Relocation<func_t> func{ ID::Console::ExecuteCommand };
			return func(a_command);
		}

		// Runs the commands ExecuteCommand has queued. ExecuteCommand only parses
		// what was typed and puts it in a queue, and the game's update drains
		// the queue through this, the ForEachRef form included, so everything a
		// console command does happens inside this call and on its thread.
		static void RunQueuedCommands()
		{
			using func_t = decltype(&Console::RunQueuedCommands);
			static REL::Relocation<func_t> func{ ID::Console::RunQueuedCommands };
			return func();
		}

		[[nodiscard]] static decltype(auto) GetCurrentPickIndex()
		{
			static REL::Relocation<std::int32_t*> currentPickIndex{ ID::Console::GetCurrentPickIndex };
			return *currentPickIndex;
		}

		[[nodiscard]] static decltype(auto) GetPickRef()
		{
			static REL::Relocation<ObjectRefHandle*> ref{ ID::Console::GetPickRef };
			return *ref;
		}

		[[nodiscard]] static decltype(auto) GetPickRefs()
		{
			static REL::Relocation<BSTArray<ObjectRefHandle>*> pickRefs{ ID::Console::GetPickRefs };
			return *pickRefs;
		}

		[[nodiscard]] static ObjectRefHandle GetCurrentPickREFR()
		{
			const auto  idx = GetCurrentPickIndex();
			const auto& refs = GetPickRefs();
			return 0 <= idx && static_cast<std::size_t>(idx) < refs.size() ?
			           refs[static_cast<std::size_t>(idx)] :
			           ObjectRefHandle{};
		}

		void SetCurrentPickREFR(ObjectRefHandle* a_refr)
		{
			using func_t = decltype(&Console::SetCurrentPickREFR);
			static REL::Relocation<func_t> func{ ID::Console::SetCurrentPickREFR };
			return func(this, a_refr);
		}

		// members
		Rumble::AutoRumblePause* rumbleLock;  // E0
		bool                     minimized;   // E8
	};
	static_assert(sizeof(Console) == 0xF0);
}
