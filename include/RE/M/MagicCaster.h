#pragma once

#include "RE/B/BSPointerHandle.h"
#include "RE/B/BSSoundHandle.h"
#include "RE/B/BSTArray.h"

namespace RE
{
	class ActiveEffect;
	class Actor;
	class MagicItem;
	class NiNode;
	class TESBoundObject;
	class TESObjectREFR;

	namespace MagicSystem
	{
		enum class CannotCastReason;
		enum class CastingSource : std::int32_t;
	}

	class __declspec(novtable) MagicCaster
	{
	public:
		static constexpr auto RTTI{ RTTI::MagicCaster };
		static constexpr auto VTABLE{ VTABLE::MagicCaster };

		virtual ~MagicCaster();  // 00

		// add
		virtual void                       Unk01();                                                                                                                                                                                         // 01
		virtual void                       CastSpellImmediate(MagicItem* a_spell, bool a_noHitEffectArt, TESObjectREFR* a_target, float a_effectiveness, bool a_hostileEffectivenessOnly, float a_magnitudeOverride, Actor* a_blameActor);  // 02
		virtual void                       Unk03();                                                                                                                                                                                         // 03
		virtual void                       Unk04();                                                                                                                                                                                         // 04
		virtual void                       Unk05();                                                                                                                                                                                         // 05
		virtual void                       Unk06();                                                                                                                                                                                         // 06
		virtual void                       Unk07();                                                                                                                                                                                         // 07
		virtual void                       Unk08();                                                                                                                                                                                         // 08
		virtual void                       Unk09();                                                                                                                                                                                         // 09
		virtual void                       Unk0A();                                                                                                                                                                                         // 0A
		virtual bool                       CheckCast(MagicItem* a_spell, bool a_dualCast, float* a_effectiveness, MagicSystem::CannotCastReason* a_reason, bool a_arg5);                                                                    // 0B
		virtual TESObjectREFR*             GetCasterStatsObject() const;                                                                                                                                                                    // 0C
		virtual Actor*                     GetCasterAsActor() const;                                                                                                                                                                        // 0D
		virtual TESObjectREFR*             GetCasterObjectReference(Actor** a_outCaster) const;                                                                                                                                             // 0E
		virtual NiNode*                    GetMagicNode();                                                                                                                                                                                  // 0F
		virtual void                       ClearMagicNode();                                                                                                                                                                                // 10
		virtual void                       Unk11();                                                                                                                                                                                         // 11
		virtual void                       Unk12();                                                                                                                                                                                         // 12
		virtual void                       Unk13();                                                                                                                                                                                         // 13
		virtual void                       Unk14();                                                                                                                                                                                         // 14
		virtual void                       Unk15();                                                                                                                                                                                         // 15
		virtual MagicSystem::CastingSource GetCastingSource() const;                                                                                                                                                                        // 16
		virtual bool                       GetIsDualCasting() const;                                                                                                                                                                        // 17
		virtual void                       SetDualCasting(bool a_dualCasting);                                                                                                                                                              // 18
		virtual void                       Unk19();                                                                                                                                                                                         // 19
		virtual void                       Unk1A();                                                                                                                                                                                         // 1A
		virtual void                       Unk1B();                                                                                                                                                                                         // 1B
		virtual void                       Unk1C();                                                                                                                                                                                         // 1C
		virtual void                       AdjustActiveEffect(ActiveEffect* a_effect, float a_power, bool a_hostileEffectivenessOnly);                                                                                                      // 1D

		// Casts currentSpell on the targets it finds. a_effectiveness is the
		// power the spell lands at, a multiplier on each effect's magnitude, or
		// on its duration for an effect that has no magnitude, and
		// a_hostileEffectivenessOnly narrows it to the hostile effects. Some
		// kinds of spell ignore it, abilities, addictions and constant effect
		// enchantments among them. a_targetCount receives how many targets were
		// reached, and a_source names what the spell came from, the weapon for
		// the object effects of a melee blow. Returns whether anything was cast.
		//
		// A weapon's object effects, a blast's and anything CastSpellImmediate
		// casts all end here.
		bool Cast(float a_effectiveness, std::uint32_t* a_targetCount, TESBoundObject* a_source, bool a_noHitEffectArt, bool a_hostileEffectivenessOnly)
		{
			using func_t = decltype(&MagicCaster::Cast);
			static REL::Relocation<func_t> func{ ID::MagicCaster::Cast };
			return func(this, a_effectiveness, a_targetCount, a_source, a_noHitEffectArt, a_hostileEffectivenessOnly);
		}

		// members
		BSTArray<BSSoundHandle> sounds;             // 08
		ObjectRefHandle         desiredTarget;      // 20
		MagicItem*              currentSpell;       // 28
		std::uint32_t           state;              // 30
		float                   unk34;              // 34
		float                   unk38;              // 38
		float                   magnitudeOverride;  // 3C
		float                   unk40;              // 40
		float                   unk44;              // 44
	};
	static_assert(sizeof(MagicCaster) == 0x48);
}
