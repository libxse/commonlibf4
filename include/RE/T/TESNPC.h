#pragma once

#include "RE/B/BGSAttachParentArray.h"
#include "RE/B/BGSCharacterMorph.h"
#include "RE/B/BGSCharacterTint.h"
#include "RE/B/BGSForcedLocRefType.h"
#include "RE/B/BGSLocalizedString.h"
#include "RE/B/BGSNativeTerminalForm.h"
#include "RE/B/BGSOverridePackCollection.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTEvent.h"
#include "RE/B/BSTHashMap.h"
#include "RE/N/NPC_DATA.h"
#include "RE/N/NiPoint.h"
#include "RE/P/PerkRankData.h"
#include "RE/S/SEX.h"
#include "RE/T/TESActorBase.h"
#include "RE/T/TESRaceForm.h"
#include "RE/T/TESSpellList.h"

namespace RE
{
	class BGSRelationship;
	class CreatureSounds;
	class MenuOpenCloseEvent;

	class __declspec(novtable) TESNPC :
		public TESActorBase,                     // 000
		public TESRaceForm,                      // 1B0
		public BGSOverridePackCollection,        // 1C0
		public BGSForcedLocRefType,              // 1F8
		public BGSNativeTerminalForm,            // 208
		public BSTEventSink<MenuOpenCloseEvent>  // 218
	{
	public:
		static constexpr auto RTTI{ RTTI::TESActorBase };
		static constexpr auto VTABLE{ VTABLE::TESActorBase };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kNPC_ };

		class HeadRelatedData
		{
		public:
			// members
			BGSColorForm*  hairColor;        // 00
			BGSColorForm*  facialHairColor;  // 08
			BGSTextureSet* faceDetails;      // 10
		};
		static_assert(sizeof(HeadRelatedData) == 0x18);

		void CopyPerkRankArray(const std::vector<PerkRankData>& a_copiedData);

		bool AddPerk(BGSPerk* a_perk, std::int8_t a_rank)
		{
			if (!GetPerkIndex(a_perk)) {
				std::vector<PerkRankData> storage{ &perks[0], &perks[perkCount] };

				auto perk = new PerkRankData(a_perk, a_rank);
				storage.push_back(*perk);

				AllocatePerkRankArray(static_cast<std::uint32_t>(storage.size()));
				std::ranges::copy(storage, perks);

				return true;
			}

			return false;
		}

		bool AddPerks(const std::vector<BGSPerk*>& a_perks, std::int8_t a_rank);

		[[nodiscard]] bool ContainsKeyword(std::string_view a_editorID) const;

		[[nodiscard]] static BSTHashMap<const TESNPC*, BSTArray<BGSHeadPart*>>& GetAlternateHeadPartListMap()
		{
			static REL::Relocation<BSTHashMap<const TESNPC*, BSTArray<BGSHeadPart*>>*> map{ ID::TESNPC::AlternateHeadPartListMap, -0x8 };
			return *map;
		}

		[[nodiscard]] std::span<BGSHeadPart*> GetHeadParts(bool a_alternate = true) const
		{
			if (a_alternate && UsingAlternateHeadPartList()) {
				auto&      map = GetAlternateHeadPartListMap();
				const auto it = map.find(this);
				if (it != map.end()) {
					return { it->second.data(), it->second.size() };
				} else {
					return {};
				}
			} else {
				return { headParts, static_cast<std::size_t>(numHeadParts) };
			}
		}

		[[nodiscard]] std::optional<std::uint32_t> GetPerkIndex(BGSPerk* a_perk) const
		{
			if (perks) {
				for (std::uint32_t i = 0; i < perkCount; i++) {
					if (perks[i].perk == a_perk) {
						return i;
					}
				}
			}

			return std::nullopt;
		}

		[[nodiscard]] TESNPC* GetRootFaceNPC() noexcept
		{
			return const_cast<TESNPC*>(static_cast<const TESNPC*>(this)->GetRootFaceNPC());
		}

		[[nodiscard]] const TESNPC* GetRootFaceNPC() const noexcept
		{
			auto root = this;
			while (root->faceNPC) {
				root = root->faceNPC;
			}
			return root;
		}

		[[nodiscard]] SEX GetSex() noexcept
		{
			using func_t = decltype(&TESNPC::GetSex);
			static REL::Relocation<func_t> func{ ID::TESNPC::GetSex };
			return func(this);
		}

		[[nodiscard]] TESSpellList::SpellData* GetSpellList()
		{
			if (!spellData) {
				spellData = new TESSpellList::SpellData();
			}
			return spellData;
		}

		[[nodiscard]] bool HasApplicableKeywordString(std::string_view a_editorID) const;

		bool RemovePerks(const std::vector<BGSPerk*>& a_perks);

		[[nodiscard]] bool IsInFaction(const TESFaction* a_faction)
		{
			for (const auto& faction : factions) {
				if (faction.faction == a_faction && faction.rank > -1) {
					return true;
				}
			}
			return false;
		}

		[[nodiscard]] bool UsingAlternateHeadPartList() const;

		float GetFacialBoneMorphIntensity()
		{
			using func_t = decltype(&TESNPC::GetFacialBoneMorphIntensity);
			static REL::Relocation<func_t> func{ ID::TESNPC::GetFacialBoneMorphIntensity };
			return func(this);
		}

		void SetHairColor(BGSColorForm* a_col)
		{
			using func_t = decltype(&TESNPC::SetHairColor);
			static REL::Relocation<func_t> func{ ID::TESNPC::SetHairColor };
			return func(this, a_col);
		}

		[[nodiscard]] const char* GetShortName() noexcept
		{
			using func_t = decltype(&TESNPC::GetShortName);
			static REL::Relocation<func_t> func{ ID::TESNPC::GetShortName };
			return func(this);
		}

		// members
		BGSAttachParentArray attachParents;    // 220
		NPC_DATA             data;             // 238
		TESClass*            cl;               // 240
		HeadRelatedData*     headRelatedData;  // 248
		BGSListForm*         giftFilter;       // 250
		TESCombatStyle*      combatStyle;      // 258
		std::uint32_t        fileOffset;       // 260
		TESRace*             originalRace;     // 268
		TESNPC*              faceNPC;          // 270
		NiPoint3             morphWeight;      // 278
		float                height;           // 284
		float                heightMax;        // 288
		union
		{
			TESNPC*         soundCreature;
			CreatureSounds* creatureSounds;
		};  // 290
		BGSLocalizedString                                       shortName;                     // 298
		TESObjectARMO*                                           farSkin;                       // 2A0
		TESFurniture*                                            powerArmorFurn;                // 2A8
		BGSOutfit*                                               defOutfit;                     // 2B0
		BGSOutfit*                                               sleepOutfit;                   // 2B8
		BGSListForm*                                             defaultPackList;               // 2C0
		TESFaction*                                              crimeFaction;                  // 2C8
		BGSHeadPart**                                            headParts;                     // 2D0
		BSTArray<float>*                                         morphRegionSliderValues;       // 2D8
		BSTHashMap<std::uint32_t, BGSCharacterMorph::Transform>* facialBoneRegionSliderValues;  // 2E0
		std::int8_t                                              numHeadParts;                  // 2E8
		std::int8_t                                              soundLevel;                    // 2E9
		std::int8_t                                              bodyTintColorR;                // 2EA
		std::int8_t                                              bodyTintColorG;                // 2EN
		std::int8_t                                              bodyTintColorB;                // 2EC
		std::int8_t                                              bodyTintColorA;                // 2ED
		BSTArray<BGSRelationship*>*                              relationships;                 // 2F0
		BSTHashMap<std::uint32_t, float>*                        morphSliderValues;             // 2F8
		BGSCharacterTint::Entries*                               tintingData;                   // 300
	};
	static_assert(sizeof(TESNPC) == 0x308);
}
