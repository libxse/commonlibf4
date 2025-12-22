#pragma once

#include "RE/H/hkBool.h"

namespace RE
{
	class hclTriangleBuffer
	{
	public:
		// members
		const void*   bufferStart;       // 00
		std::uint32_t numElements;       // 08
		std::uint8_t  stride;            // 0C
		hkBool        use16BitsIndices;  /// 0D
	};
	static_assert(sizeof(hclTriangleBuffer) == 0x10);
}
