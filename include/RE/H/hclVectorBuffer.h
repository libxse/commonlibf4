#pragma once

namespace RE
{
	class hclVectorBuffer
	{
	public:
		// members
		void*         bufferStart;  // 00
		std::uint32_t numElements;  // 08
		std::uint8_t  stride;       // 0C
		std::uint32_t flags;        // 10
	};
	static_assert(sizeof(hclVectorBuffer) == 0x18);
}
