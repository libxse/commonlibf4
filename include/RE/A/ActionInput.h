#pragma once

#include "RE/N/NiPointer.h"

namespace RE
{
	class __declspec(novtable) ActionInput
	{
	public:
		static constexpr auto RTTI{ RTTI::ActionInput };
		static constexpr auto VTABLE{ VTABLE::ActionInput };

		enum class ACTIONPRIORITY
		{
			kImperative = 0x0,
			kQueue = 0x1,
			kTry = 0x2
		};

		class Data
		{
		public:
			union
			{
				float         f;
				std::int32_t  i;
				std::uint32_t ui;
			};  //00
		};

		virtual ~ActionInput();  // 00

		// members
		NiPointer<TESObjectREFR>                     ref;         // 08
		NiPointer<TESObjectREFR>                     targetRef;   // 10
		BGSAction*                                   action;      // 18
		REX::TEnumSet<ACTIONPRIORITY, std::uint32_t> priority;    // 20
		Data                                         ActionData;  // 24
	};
	static_assert(sizeof(ActionInput) == 0x28);
}
