#pragma once

namespace RE
{
	class CombatBehaviorStack
	{
	public:
		// members
		std::uint8_t* buffer;      // 00
		std::uint32_t bufferSize;  // 08
		std::uint32_t size;        // 0C
	};
	static_assert(sizeof(CombatBehaviorStack) == 0x10);
}
