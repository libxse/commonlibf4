#pragma once

#include "RE/B/BSInputEventReceiver.h"
#include "RE/B/BSTEvent.h"

namespace RE
{
	class MenuOpenCloseEvent;
	class IdleInputEvent;

	class BSIdleInputWatcher :
		public BSInputEventReceiver,
		public BSTEventSink<MenuOpenCloseEvent>,
		public BSTSingletonSDM<BSIdleInputWatcher>,
		public BSTEventSource<IdleInputEvent>

	{
	public:
		[[nodiscard]] static BSIdleInputWatcher* GetSingleton()
		{
			static REL::Relocation<BSIdleInputWatcher**> singleton{ ID::BSIdleInputWatcher::Singleton };
			return *singleton;
		}

		// members
		std::uint64_t lastInputTime;  // 78
		std::uint8_t  disableCount;   // 80
		bool          isInputIdle;    // 81
	};
	static_assert(sizeof(BSIdleInputWatcher) == 0x88);
}
