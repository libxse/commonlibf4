#pragma once

namespace RE
{
	class ActorStance
	{
	public:
		// members
		std::uint8_t stance;          // 00
		std::uint8_t stanceModifier;  // 01
		bool         mirrored;        // 02
	};
	static_assert(sizeof(ActorStance) == 0x03);
}
