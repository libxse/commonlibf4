#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/B/BSResource_Stream.h"
#include "RE/B/BSTSmartPointer.h"

namespace RE
{
	class __declspec(novtable) BSIStream
	{
	public:
		static constexpr auto RTTI{ RTTI::BSIStream };
		static constexpr auto VTABLE{ VTABLE::BSIStream };

		virtual ~BSIStream();  // 00

		[[nodiscard]] bool IsGood() const noexcept { return good; }

		// members
		BSTSmartPointer<BSResource::Stream> stream;  // 08
		bool                                good;    // 10
		BSFixedString                       name;    // 18
	};
	static_assert(offsetof(BSIStream, stream) == 0x08);
	static_assert(offsetof(BSIStream, good) == 0x10);
	static_assert(offsetof(BSIStream, name) == 0x18);
	static_assert(sizeof(BSIStream) == 0x20);
}
