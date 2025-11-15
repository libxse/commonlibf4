#pragma once

namespace RE
{
	class TESIdleForm;

	class IDLE_REPLAY_DELAY
	{
	public:
		// memberse
		const TESIdleForm* idleForm;  // 00
		float              delay;     // 08
	};
	static_assert(sizeof(IDLE_REPLAY_DELAY) == 0x10);
}
