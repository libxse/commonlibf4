#pragma once

namespace RE
{
	class BGSObjectInstance;

	namespace ActorEquipManagerEvent
	{
		enum class Type : std::int32_t
		{
			kEquip = 0x0,
			kUnequip = 0x1
		};

		class Event
		{
		public:
			// members
			REX::TEnumSet<Type, std::uint16_t> changeType;     // 00
			const BGSObjectInstance*           itemAffected;   // 08
			Actor*                             actorAffected;  // 10
			std::uint32_t                      stackID;        // 18
		};
		static_assert(sizeof(Event) == 0x20);
	}
}
