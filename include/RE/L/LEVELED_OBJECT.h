#pragma once

namespace RE
{
	class ContainerItemExtra;

	class LEVELED_OBJECT
	{
	public:
		// members
		TESForm*            form;        // 00
		ContainerItemExtra* itemExtra;   // 08
		std::uint16_t       count;       // 10
		std::uint16_t       level;       // 12
		std::uint8_t        chanceNone;  // 14
	};
	static_assert(sizeof(LEVELED_OBJECT) == 0x18);
}
