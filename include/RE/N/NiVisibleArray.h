#pragma once

namespace RE
{
	class alignas(0x08) NiVisibleArray
	{
		BSGeometry**  array;          // 00
		std::uint32_t currentSize;    // 08
		std::uint32_t allocatedSize;  // 0C
		std::uint32_t growBy;         // 10
	};
	static_assert(sizeof(0x18));
}
