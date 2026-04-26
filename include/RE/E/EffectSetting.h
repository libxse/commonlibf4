#pragma once

#include "RE/B/BGSKeywordForm.h"
#include "RE/B/BGSMenuDisplayObject.h"
#include "RE/B/BSSimpleList.h"
#include "RE/B/BSTArray.h"
#include "RE/T/TESCondition.h"
#include "RE/T/TESForm.h"
#include "RE/T/TESFullName.h"

namespace RE
{
	enum class SOUND_LEVEL;

	namespace EffectArchetypes
	{
		enum class ArchetypeID;
	}

	namespace MagicSystem
	{
		enum class CastingType;
		enum class Delivery;
		enum class SoundID;
	}

	class __declspec(novtable) EffectSetting :
		public TESForm,               // 000
		public TESFullName,           // 020
		public BGSMenuDisplayObject,  // 030
		public BGSKeywordForm         // 040
	{
	public:
		static constexpr auto RTTI{ RTTI::EffectSetting };
		static constexpr auto VTABLE{ VTABLE::EffectSetting };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kMGEF };

		using FilterValidationFunction_t = bool(EffectSetting*, void*);

		class EffectSettingData
		{
		public:
			enum class Flag
			{
				kNone = 0,
				kHostile = 1 << 0,
				kRecover = 1 << 1,
				kDetrimental = 1 << 2,
				kSnapToNavMesh = 1 << 3,
				kNoHitEvent = 1 << 4,
				kDispelWithKeywords = 1 << 8,
				kNoDuration = 1 << 9,
				kNoMagnitude = 1 << 10,
				kNoArea = 1 << 11,
				kFXPersist = 1 << 12,
				kGoryVisuals = 1 << 14,
				kHideInUI = 1 << 15,
				kNoRecast = 1 << 17,
				kPowerAffectsMagnitude = 1 << 21,
				kPowerAffectsDuration = 1 << 22,
				kPainless = 1 << 26,
				kNoHitEffect = 1 << 27,
				kNoDeathDispel = 1 << 28
			};

			// members
			REX::TEnumSet<Flag, std::uint32_t>                         flags;                  // 000
			float                                                      baseCost;               // 004
			TESForm*                                                   associatedForm;         // 008
			ActorValueInfo*                                            associatedSkill;        // 010
			ActorValueInfo*                                            resistVariable;         // 018
			std::int16_t                                               numCounterEffects;      // 020
			TESObjectLIGH*                                             light;                  // 028
			float                                                      taperWeight;            // 030
			TESEffectShader*                                           effectShader;           // 038
			TESEffectShader*                                           enchantEffect;          // 040
			std::int32_t                                               minimumSkill;           // 048
			std::int32_t                                               spellmakingArea;        // 04C
			float                                                      spellmakingChargeTime;  // 050
			float                                                      taperCurve;             // 054
			float                                                      taperDuration;          // 058
			float                                                      secondaryAVWeight;      // 05C
			REX::TEnumSet<EffectArchetypes::ArchetypeID, std::int32_t> archetype;              // 060
			ActorValueInfo*                                            primaryAV;              // 068
			BGSProjectile*                                             projectileBase;         // 070
			BGSExplosion*                                              explosion;              // 078
			REX::TEnumSet<MagicSystem::CastingType, std::int32_t>      castingType;            // 080
			REX::TEnumSet<MagicSystem::Delivery, std::int32_t>         delivery;               // 084
			ActorValueInfo*                                            secondaryAV;            // 088
			BGSArtObject*                                              castingArt;             // 090
			BGSArtObject*                                              hitEffectArt;           // 098
			BGSImpactDataSet*                                          impactDataSet;          // 0A0
			float                                                      skillUsageMult;         // 0A8
			BGSDualCastData*                                           dualCastData;           // 0B0
			float                                                      dualCastScale;          // 0B8
			BGSArtObject*                                              enchantEffectArt;       // 0C0
			BGSReferenceEffect*                                        hitVisuals;             // 0C8
			BGSReferenceEffect*                                        enchantVisuals;         // 0D0
			SpellItem*                                                 equipAbility;           // 0D8
			TESImageSpaceModifier*                                     imageSpaceMod;          // 0E0
			BGSPerk*                                                   perk;                   // 0E8
			REX::TEnumSet<SOUND_LEVEL, std::int32_t>                   castingSoundLevel;      // 0F0
			float                                                      aiScore;                // 0F4
			float                                                      aiDelayTime;            // 0F8
		};
		static_assert(sizeof(EffectSettingData) == 0x100);

		class SoundPair
		{
		public:
			// members
			REX::TEnumSet<MagicSystem::SoundID, std::int32_t> id;     // 00
			BGSSoundDescriptorForm*                           sound;  // 08
		};
		static_assert(sizeof(SoundPair) == 0x10);

		// members
		FilterValidationFunction_t*        filterValidationFunction;   // 060
		void*                              filterValidationItem;       // 068
		EffectSettingData                  data;                       // 070
		BSSimpleList<EffectSetting*>       counterEffects;             // 170
		BSTArray<EffectSetting::SoundPair> effectSounds;               // 180
		BGSLocalizedString                 magicItemDescription;       // 198
		std::int32_t                       effectLoadedCount;          // 1A0
		std::int32_t                       associatedItemLoadedCount;  // 1A4
		TESCondition                       conditions;                 // 1A8
	};
	static_assert(sizeof(EffectSetting) == 0x1B0);
}
