#pragma once

#include "RE/B/BaseFormComponent.h"

namespace RE
{
	namespace MagicSystem
	{
		enum class CastingType;
	}

	class __declspec(novtable) TESEnchantableForm :
		public BaseFormComponent  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::TESEnchantableForm };
		static constexpr auto VTABLE{ VTABLE::TESEnchantableForm };

		virtual MagicSystem::CastingType GetCastingType() const { return *castingType; }  // 07

		[[nodiscard]] std::uint16_t    GetBaseCharge() const noexcept { return amountOfEnchantment; }
		[[nodiscard]] EnchantmentItem* GetBaseEnchanting() const noexcept { return formEnchanting; }
		void                           SetBaseCharge(std::uint16_t a_amount) noexcept { amountOfEnchantment = a_amount; }
		void                           SetBaseEnchanting(EnchantmentItem* a_ench) noexcept { formEnchanting = a_ench; }

		// members
		EnchantmentItem*                                       formEnchanting;       // 08
		REX::TEnumSet<MagicSystem::CastingType, std::uint16_t> castingType;          // 10
		std::uint16_t                                          amountOfEnchantment;  // 12
	};
	static_assert(sizeof(TESEnchantableForm) == 0x18);
}
