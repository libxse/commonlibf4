#pragma once

namespace RE
{
	class ENCOUNTER_ZONE_DATA
	{
	public:
		enum class FLAG
		{
			kNeverReset = 1u << 0,
			kMatchPCBelowMin = 1u << 1,
			kDisableCombatBoundary = 1u << 2,
			kWorkshopZone = 1u << 3
		};

		// members
		TESForm*                          zoneOwner;  // 00
		BGSLocation*                      location;   // 08
		std::int8_t                       ownerRank;  // 10
		std::int8_t                       minLevel;   // 11
		REX::TEnumSet<FLAG, std::uint8_t> flags;      // 12
		std::int8_t                       maxLevel;   // 13
	};
	static_assert(sizeof(ENCOUNTER_ZONE_DATA) == 0x18);
}
