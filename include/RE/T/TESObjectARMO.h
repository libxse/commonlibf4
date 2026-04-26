#pragma once

#include "RE/B/BGSAttachParentArray.h"
#include "RE/B/BGSBipedObjectForm.h"
#include "RE/B/BGSBlockBashData.h"
#include "RE/B/BGSDestructibleObjectForm.h"
#include "RE/B/BGSEquipType.h"
#include "RE/B/BGSInstanceNamingRulesForm.h"
#include "RE/B/BGSKeywordForm.h"
#include "RE/B/BGSPickupPutdownSounds.h"
#include "RE/B/BGSTypedFormValuePair.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTTuple.h"
#include "RE/T/TESBipedModelForm.h"
#include "RE/T/TESBoundObject.h"
#include "RE/T/TESDescription.h"
#include "RE/T/TESEnchantableForm.h"
#include "RE/T/TESFullName.h"
#include "RE/T/TESRaceForm.h"

namespace RE
{
	enum class STAGGER_MAGNITUDE;

	class __declspec(novtable) TESObjectARMO :
		public TESBoundObject,             // 000
		public TESFullName,                // 068
		public TESRaceForm,                // 078
		public TESEnchantableForm,         // 088
		public BGSDestructibleObjectForm,  // 0A0
		public BGSPickupPutdownSounds,     // 0B0
		public TESBipedModelForm,          // 0C8
		public BGSEquipType,               // 1D0
		public BGSBipedObjectForm,         // 1E0
		public BGSBlockBashData,           // 1F0
		public BGSKeywordForm,             // 208
		public TESDescription,             // 228
		public BGSInstanceNamingRulesForm  // 240
	{
	public:
		static constexpr auto RTTI{ RTTI::TESObjectARMO };
		static constexpr auto VTABLE{ VTABLE::TESObjectARMO };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kARMO };

		class __declspec(novtable) InstanceData :
			public TBO_InstanceData  // 00
		{
		public:
			static constexpr auto RTTI{ RTTI::TESObjectARMO__InstanceData };
			static constexpr auto VTABLE{ VTABLE::TESObjectARMO__InstanceData };

			// members
			BSTArray<EnchantmentItem*>*                                     enchantments;         // 10
			BSTArray<BGSMaterialSwap*>*                                     materialSwaps;        // 18
			BGSBlockBashData*                                               blockBashData;        // 20
			BGSKeywordForm*                                                 keywords;             // 28
			BSTArray<BSTTuple<TESForm*, BGSTypedFormValuePair::SharedVal>>* damageTypes;          // 30
			BSTArray<BSTTuple<TESForm*, BGSTypedFormValuePair::SharedVal>>* actorValues;          // 38
			float                                                           weight;               // 40
			float                                                           colorRemappingIndex;  // 44
			std::uint32_t                                                   value;                // 48
			std::uint32_t                                                   health;               // 4C
			REX::TEnumSet<STAGGER_MAGNITUDE, std::int32_t>                  staggerRating;        // 50
			std::uint16_t                                                   rating;               // 54
			std::uint16_t                                                   index;                // 56
		};
		static_assert(sizeof(InstanceData) == 0x58);

		class ArmorAddon
		{
		public:
			// members
			std::uint16_t  index;       // 00
			TESObjectARMA* armorAddon;  // 08
		};
		static_assert(sizeof(ArmorAddon) == 0x10);

		bool Protects(const ActorValueInfo* a_condition, bool a_only)
		{
			using func_t = decltype(&TESObjectARMO::Protects);
			static REL::Relocation<func_t> func{ ID::TESObjectARMO::Protects };
			return func(this, a_condition, a_only);
		}

		// members
		InstanceData         armorData;      // 250
		BSTArray<ArmorAddon> modelArray;     // 2A8
		TESObjectARMO*       armorTemplate;  // 2C0
		BGSAttachParentArray attachParents;  // 2C8
	};
	static_assert(sizeof(TESObjectARMO) == 0x2E0);
}
