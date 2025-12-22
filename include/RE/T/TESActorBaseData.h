#pragma once

#include "RE/A/ACTOR_BASE_DATA.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BaseFormComponent.h"
#include "RE/F/FACTION_RANK.h"

namespace RE
{
	class __declspec(novtable) TESActorBaseData :
		public BaseFormComponent  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::TESActorBaseData };
		static constexpr auto VTABLE{ VTABLE::TESActorBaseData };

		enum class ALIGNMENT : std::uint32_t
		{
			kGood = 0x0,
			kNeutral = 0x1,
			kEvil = 0x2,
			kVeryGood = 0x3,
			kVeryEvil = 0x4
		};

		// add
		virtual void CopyFromTemplateForms([[maybe_unused]] TESActorBase** a_forceTemplates) { return; }  // 07
		virtual bool GetIsGhost() const;                                                                  // 08
		virtual bool GetInvulnerable() const;                                                             // 09

		[[nodiscard]] constexpr bool AffectsStealthMeter() const noexcept { return actorData.actorBaseFlags.none(ACTOR_BASE_DATA::Flag::kDoesntAffectStealthMeter); }
		[[nodiscard]] constexpr bool Bleeds() const noexcept { return actorData.actorBaseFlags.none(ACTOR_BASE_DATA::Flag::kDoesntBleed); }
		[[nodiscard]] constexpr bool IsEssential() const noexcept { return actorData.actorBaseFlags.all(ACTOR_BASE_DATA::Flag::kEssential); }
		[[nodiscard]] constexpr bool IsFemale() const noexcept { return actorData.actorBaseFlags.all(ACTOR_BASE_DATA::Flag::kFemale); }
		[[nodiscard]] inline bool    IsGhost() const { return GetIsGhost(); }
		[[nodiscard]] constexpr bool IsPreset() const noexcept { return actorData.actorBaseFlags.all(ACTOR_BASE_DATA::Flag::kIsChargenFacePreset); }
		[[nodiscard]] constexpr bool IsProtected() const noexcept { return actorData.actorBaseFlags.all(ACTOR_BASE_DATA::Flag::kProtected); }
		[[nodiscard]] constexpr bool IsSimpleActor() const noexcept { return actorData.actorBaseFlags.all(ACTOR_BASE_DATA::Flag::kSimpleActor); }
		[[nodiscard]] constexpr bool IsSummonable() const noexcept { return actorData.actorBaseFlags.all(ACTOR_BASE_DATA::Flag::kSummonable); }
		[[nodiscard]] constexpr bool IsUnique() const noexcept { return actorData.actorBaseFlags.all(ACTOR_BASE_DATA::Flag::kUnique); }
		[[nodiscard]] inline bool    IsInvulnerable() const { return GetInvulnerable(); }
		[[nodiscard]] constexpr bool HasAutoCalcStats() const noexcept { return actorData.actorBaseFlags.all(ACTOR_BASE_DATA::Flag::kAutoCalcStats); }
		[[nodiscard]] constexpr bool HasBleedoutOverride() const noexcept { return actorData.actorBaseFlags.all(ACTOR_BASE_DATA::Flag::kBleedoutOverride); }
		[[nodiscard]] constexpr bool HasPCLevelMult() const noexcept { return actorData.actorBaseFlags.all(ACTOR_BASE_DATA::Flag::kPCLevelMult); }
		[[nodiscard]] constexpr bool Respawns() const noexcept { return actorData.actorBaseFlags.all(ACTOR_BASE_DATA::Flag::kRespawn); }
		[[nodiscard]] constexpr bool UsesOppositeGenderAnims() const noexcept { return actorData.actorBaseFlags.all(ACTOR_BASE_DATA::Flag::kOppositeGenderanims); }
		[[nodiscard]] constexpr bool UsesTemplate() const noexcept { return actorData.actorBaseFlags.all(ACTOR_BASE_DATA::Flag::kUsesTemplate); }

		std::uint16_t GetLevel() const
		{
			using func_t = decltype(&TESActorBaseData::GetLevel);
			static REL::Relocation<func_t> func{ ID::TESActorBaseData::GetLevel };
			return func(this);
		}

		// members
		ACTOR_BASE_DATA        actorData;         // 08
		std::int32_t           changeFlags;       // 1C
		TESLevItem*            deathItem;         // 20
		BGSVoiceType*          voiceType;         // 28
		TESForm*               baseTemplateForm;  // 30
		TESForm**              templateForms;     // 38
		TESGlobal*             legendChance;      // 40
		TESForm*               legendTemplate;    // 48
		BSTArray<FACTION_RANK> factions;          // 50
	};
	static_assert(sizeof(TESActorBaseData) == 0x68);
}
