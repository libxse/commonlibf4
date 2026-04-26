#pragma once

#include "RE/B/BSTArray.h"

namespace RE
{
	class BGSInventoryItem;

	namespace ActorUtils
	{
		class __declspec(novtable) ArmorRatingVisitorBase
		{
		public:
			static constexpr auto RTTI{ RTTI::ActorUtils__ArmorRatingVisitorBase };
			static constexpr auto VTABLE{ VTABLE::ActorUtils__ArmorRatingVisitorBase };

			ArmorRatingVisitorBase()
			{
				REX::EMPLACE_VTABLE(this);
			}

			ArmorRatingVisitorBase(const Actor* a_actor, bool a_checkEquipped)
			{
				ctor(a_actor, a_checkEquipped);
			}

			// add
			virtual bool ShouldProcess(TESBoundObject*) { return 1; };  // 00
			virtual void PostProcess(TESBoundObject*) {};               // 01

			std::int64_t operator()(const BGSInventoryItem* a_item, std::uint32_t a_stackID)
			{
				using func_t = decltype(&ArmorRatingVisitorBase::operator());
				static REL::Relocation<func_t> func{ ID::ActorUtils::ArmorRatingVisitorBase::_operator };
				return func(this, a_item, a_stackID);
			}

			// members
			Actor* actor;          // 08
			float  rating;         // 10
			float  armorPerks;     // 14
			bool   checkEquipped;  // 18

		private:
			void ctor(const Actor* a_actor, bool a_checkEquipped)
			{
				using func_t = decltype(&ArmorRatingVisitorBase::ctor);
				static REL::Relocation<func_t> func{ ID::ActorUtils::ArmorRatingVisitorBase::ctor };
				return func(this, a_actor, a_checkEquipped);
			}
		};
		static_assert(sizeof(ArmorRatingVisitorBase) == 0x20);

		class __declspec(novtable) ArmorRatingVisitor :
			public ArmorRatingVisitorBase  // 00
		{
			static constexpr auto RTTI{ RTTI::ActorUtils__ArmorRatingVisitor };
			static constexpr auto VTABLE{ VTABLE::ActorUtils__ArmorRatingVisitor };

			BSScrapArray<TESBoundObject*> foundArmor;  // 20
		};
		static_assert(sizeof(ArmorRatingVisitor) == 0x40);

		static inline float GetEquippedArmorDamageResistance(Actor* a_actor, const ActorValueInfo* a_info)
		{
			using func_t = decltype(ActorUtils::GetEquippedArmorDamageResistance);
			static REL::Relocation<func_t> func{ ID::ActorUtils::GetEquippedArmorDamageResistance };
			return func(a_actor, a_info);
		}
	}
}
