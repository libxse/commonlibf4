#pragma once

namespace RE
{
	class IdleInputEvent
	{
	public:
		// members
		bool starting;  // 00
	};
	static_assert(sizeof(IdleInputEvent) == 0x1);
}
