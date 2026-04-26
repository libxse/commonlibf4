#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/B/BSTHashMap.h"

namespace RE
{
	enum class INPUT_DEVICE;

	class __declspec(novtable) BSInputDevice
	{
	public:
		static constexpr auto RTTI{ RTTI::BSInputDevice };
		static constexpr auto VTABLE{ VTABLE::BSInputDevice };

		class InputButton
		{
		public:
			// members
			BSFixedStringCS name;          // 00
			float           heldDownSecs;  // 08
			std::uint32_t   keyCode;       // 0C
		};
		static_assert(sizeof(InputButton) == 0x10);

		// add
		virtual void Initialize() = 0;                     // 00
		virtual void Poll(float a_pollDelta) = 0;          // 01
		virtual void Shutdown() = 0;                       // 02
		virtual bool IsConnected() const { return true; }  // 03
		virtual ~BSInputDevice();                          // 04
		virtual void ClearInputState() = 0;                // 05

		// members
		REX::TEnumSet<INPUT_DEVICE, std::int32_t>  deviceType;       // 08
		std::int32_t                               deviceID;         // 0C
		BSTHashMap<std::uint32_t, InputButton*>    deviceButtons;    // 10
		BSTHashMap<BSFixedStringCS, std::uint32_t> buttonNameIDMap;  // 40
	};
	static_assert(sizeof(BSInputDevice) == 0x70);
}
