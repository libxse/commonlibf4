#pragma once

#include "RE/B/BSTEvent.h"
#include "Scaleform/G/GFx_Value.h"

namespace RE
{
	class PipboyValueChangedEvent;

	class __declspec(novtable) PipboySubMenu :
		public BSTEventSink<PipboyValueChangedEvent>  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::PipboySubMenu };
		static constexpr auto VTABLE{ VTABLE::PipboySubMenu };

		// override (BSTEventSink<PipboyValueChangedEvent>)
		BSEventNotifyControl ProcessEvent(const PipboyValueChangedEvent& a_event, BSTEventSource<PipboyValueChangedEvent>* a_source) override
		{
			using func_t = decltype(&PipboySubMenu::ProcessEvent);
			static REL::Relocation<func_t> func{ ID::PipboySubMenu::ProcessEvent };
			return func(this, a_event, a_source);
		}

		// add
		virtual void UpdateData() = 0;  // 02

		// members
		Scaleform::GFx::Value* dataObj;  // 08
		Scaleform::GFx::Value* menuObj;  // 10
	};
	static_assert(sizeof(PipboySubMenu) == 0x18);
}
