#pragma once

namespace RE
{
	class DetectionLevels
	{
	public:
		// members
		std::int16_t visualLevel;  // 00
		std::int16_t soundLevel;   // 02
	};
	static_assert(sizeof(DetectionLevels) == 0x04);
}
