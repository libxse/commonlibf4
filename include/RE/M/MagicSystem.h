#pragma once

namespace RE
{
	namespace MagicSystem
	{
		enum class CastingType : std::int32_t
		{
			kConstantEffect = 0,
			kFireAndForget = 1,
			kConcentration = 2
		};

		enum class Delivery : std::int32_t
		{
			kSelf = 0,
			kTouch = 1,
			kAimed = 2,
			kTargetActor = 3,
			kTargetLocation = 4
		};

		enum class SpellType : std::int32_t
		{
			kSpell = 0,
			kDisease = 1,
			kPower = 2,
			kLesserPower = 3,
			kAbility = 4,
			kPoison = 5,
			kEnchantment = 6,
			kPotion = 7,
			kIngredient = 8,
			kLeveledSpell = 9,
			kAddiction = 10,
			kVoicePower = 11,
			kStaffEnchantment = 12,
			kScroll = 13
		};
	}
}
