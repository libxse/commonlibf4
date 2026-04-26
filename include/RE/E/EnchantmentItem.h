#pragma once

#include "RE/M/MagicItem.h"

namespace RE
{
	namespace MagicSystem
	{
		enum class CastingType;
		enum class Delivery;
		enum class SpellType;
	}

	class __declspec(novtable) EnchantmentItem :
		public MagicItem  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::EnchantmentItem };
		static constexpr auto VTABLE{ VTABLE::EnchantmentItem };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kENCH };

		class Data :
			public MagicItem::Data  // 00
		{
		public:
			// members
			REX::TEnumSet<MagicSystem::CastingType, std::int32_t> castingType;       // 08
			std::int32_t                                          chargeOverride;    // 0C
			REX::TEnumSet<MagicSystem::Delivery, std::int32_t>    delivery;          // 10
			REX::TEnumSet<MagicSystem::SpellType, std::int32_t>   spellType;         // 14
			float                                                 chargeTime;        // 18
			EnchantmentItem*                                      baseEnchantment;   // 20
			BGSListForm*                                          wornRestrictions;  // 28
		};
		static_assert(sizeof(Data) == 0x30);

		// members
		Data data;  // 0D0
	};
	static_assert(sizeof(EnchantmentItem) == 0x100);
}
