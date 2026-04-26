#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/I/InputEvent.h"

namespace RE
{
	class __declspec(novtable) IDEvent :
		public InputEvent  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::IDEvent };
		static constexpr auto VTABLE{ VTABLE::IDEvent };

		// NOLINTNEXTLINE(modernize-use-override)
		virtual ~IDEvent() = default;  // 00

		// override (InputEvent)
		bool HasIDCode() const override { return true; }  // 02

		const BSFixedString& QUserEvent() const override  // 03
		{
			if (!disabled) {
				return strUserEvent;
			}

			static const BSFixedString DISABLED{ "DISABLED" };

			return DISABLED;
		}

		[[nodiscard]] const bool           QDisabled() const noexcept { return disabled; }
		[[nodiscard]] const std::uint32_t  QIDCode() const noexcept { return idCode; }
		[[nodiscard]] const BSFixedString& QRawUserEvent() const noexcept { return strUserEvent; }

		// members
		BSFixedString strUserEvent;       // 28
		std::int32_t  idCode{ -1 };       // 30
		bool          disabled{ false };  // 34
	};
	static_assert(sizeof(IDEvent) == 0x38);

	extern template IDEvent*       InputEvent::As();
	extern template const IDEvent* InputEvent::As() const;
}
