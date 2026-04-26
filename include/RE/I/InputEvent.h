#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/I/INPUT_DEVICE.h"
#include "RE/I/INPUT_EVENT_TYPE.h"

namespace RE
{
	class IDEvent;

	class __declspec(novtable) InputEvent
	{
	public:
		static constexpr auto RTTI{ RTTI::InputEvent };
		static constexpr auto VTABLE{ VTABLE::InputEvent };

		enum class HANDLED_RESULT : std::int32_t
		{
			kUnhandled,
			kContinue,
			kStop
		};

		virtual ~InputEvent() = default;  // 00

		// add
		virtual bool                 HasIDCode() const { return false; }  // 02
		virtual const BSFixedString& QUserEvent() const;                  // 03

		template <class T>
		[[nodiscard]] T* As() noexcept  //
			requires(std::derived_from<T, InputEvent> &&
					 !std::same_as<std::decay_t<T>, IDEvent>)
		{
			if (*eventType == T::TYPE) {
				return static_cast<T*>(this);
			} else {
				return nullptr;
			}
		}

		template <class T>
		[[nodiscard]] const T* As() const noexcept  //
			requires(std::derived_from<T, InputEvent> &&
					 !std::same_as<std::decay_t<T>, IDEvent>)
		{
			if (*eventType == T::TYPE) {
				return static_cast<const T*>(this);
			} else {
				return nullptr;
			}
		}

		template <class T>
		[[nodiscard]] T* As()  //
			requires(std::same_as<std::decay_t<T>, IDEvent>)
		{
			if (HasIDCode()) {
				return static_cast<T*>(this);
			} else {
				return nullptr;
			}
		}

		template <class T>
		[[nodiscard]] const T* As() const  //
			requires(std::same_as<std::decay_t<T>, IDEvent>)
		{
			if (HasIDCode()) {
				return static_cast<const T*>(this);
			} else {
				return nullptr;
			}
		}

		// members
		REX::TEnumSet<INPUT_DEVICE, std::int32_t>     device{ INPUT_DEVICE::kNone };               // 08
		std::int32_t                                  deviceID{ 0 };                               // 0C
		REX::TEnumSet<INPUT_EVENT_TYPE, std::int32_t> eventType{ INPUT_EVENT_TYPE::kNone };        // 10
		InputEvent*                                   next{ nullptr };                             // 18
		std::uint32_t                                 timeCode{ static_cast<std::uint32_t>(-1) };  // 20
		REX::TEnumSet<HANDLED_RESULT, std::int32_t>   handled{ HANDLED_RESULT::kUnhandled };       // 24
	};
	static_assert(sizeof(InputEvent) == 0x28);
}
