#pragma once

namespace RE
{
	class ACTOR_BASE_DATA
	{
	public:
		enum class Flag
		{
			kNone = 0,
			kFemale = 1 << 0,
			kEssential = 1 << 1,
			kIsChargenFacePreset = 1 << 2,
			kRespawn = 1 << 3,
			kAutoCalcStats = 1 << 4,
			kUnique = 1 << 5,
			kDoesntAffectStealthMeter = 1 << 6,
			kPCLevelMult = 1 << 7,
			kUsesTemplate = 1 << 8,
			kProtected = 1 << 11,
			kSummonable = 1 << 14,
			kDoesntBleed = 1 << 16,
			kBleedoutOverride = 1 << 18,
			kOppositeGenderanims = 1 << 19,
			kSimpleActor = 1 << 20,
			kLoopedScript = 1 << 21,  // ?
			kLoopedAudio = 1 << 28,   // ?
			kIsGhost = 1 << 29,
			kInvulnerable = 1 << 31
		};

		enum class TEMPLATE_USE_FLAG
		{
			kNone = 0,
			kTraits = 1 << 0,
			kStats = 1 << 1,
			kFactions = 1 << 2,
			kSpells = 1 << 3,
			kAIData = 1 << 4,
			kAIPackages = 1 << 5,
			kUnused = 1 << 6,
			kBaseData = 1 << 7,
			kInventory = 1 << 8,
			kScript = 1 << 9,
			kAIDefPackList = 1 << 10,
			kAttackData = 1 << 11,
			kKeywords = 1 << 12
		};

		// members
		REX::TEnumSet<Flag, std::uint32_t>              actorBaseFlags;    // 00
		std::int16_t                                    xpValueOffset;     // 04
		std::uint16_t                                   level;             // 06
		std::uint16_t                                   calcLevelMin;      // 08
		std::uint16_t                                   calcLevelMax;      // 0A
		std::uint16_t                                   baseDisposition;   // 0C
		REX::TEnumSet<TEMPLATE_USE_FLAG, std::uint16_t> templateUseFlags;  // 0E
		std::int16_t                                    bleedoutOverride;  // 10
	};
	static_assert(sizeof(ACTOR_BASE_DATA) == 0x14);
}
