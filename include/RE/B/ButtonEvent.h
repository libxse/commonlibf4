#pragma once

#include "RE/B/BS_BUTTON_CODE.h"
#include "RE/I/IDEvent.h"

namespace RE
{
	class __declspec(novtable) ButtonEvent :
		public IDEvent  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::ButtonEvent };
		static constexpr auto VTABLE{ VTABLE::ButtonEvent };
		static constexpr auto TYPE{ INPUT_EVENT_TYPE::kButton };

		// NOLINTNEXTLINE(modernize-use-override)
		virtual ~ButtonEvent() = default;  // 00

		[[nodiscard]] BS_BUTTON_CODE GetBSButtonCode() const noexcept
		{
			REX::TEnumSet<BS_BUTTON_CODE> result{ static_cast<BS_BUTTON_CODE>(idCode) };
			switch (device.get()) {
				case INPUT_DEVICE::kGamepad:
					result.set(BS_BUTTON_CODE::kGamepad);
				default:
					return result.get();
			}
		}

		[[nodiscard]] float QAnalogValue() const noexcept { return value; }
		[[nodiscard]] bool  QHeldDown(float a_heldDownSecs) const noexcept { return value != 0.0 && a_heldDownSecs <= heldDownSecs; }
		[[nodiscard]] bool  QHeldDown() const noexcept { return value != 0.0 && heldDownSecs > 0.0F; }
		[[nodiscard]] float QHeldDownSecs() const noexcept { return heldDownSecs; }
		[[nodiscard]] bool  QJustPressed() const noexcept { return value != 0.0F && heldDownSecs == 0.0F; }
		[[nodiscard]] bool  QPressed() const noexcept { return value != 0.0F; }
		[[nodiscard]] bool  QReleased(float a_heldDownSecs) const noexcept { return value == 0.0F && a_heldDownSecs <= heldDownSecs; }
		[[nodiscard]] bool  QReleased() const noexcept { return value == 0.0F && heldDownSecs > 0.0F; }

		// members
		float value{ 0.0F };         // 38
		float heldDownSecs{ 0.0F };  // 3C
	};
	static_assert(sizeof(ButtonEvent) == 0x40);

	extern template ButtonEvent*       InputEvent::As() noexcept;
	extern template const ButtonEvent* InputEvent::As() const noexcept;
}
