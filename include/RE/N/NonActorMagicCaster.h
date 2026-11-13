#pragma once

#include "RE/B/BSPointerHandle.h"
#include "RE/E/ExtraMagicCaster.h"

namespace RE
{
	class __declspec(novtable) NonActorMagicCaster :
		public ExtraMagicCaster  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::NonActorMagicCaster };
		static constexpr auto VTABLE{ VTABLE::NonActorMagicCaster };

		~NonActorMagicCaster() override;  // 00

		// override (MagicCaster)
		void           CastSpellImmediate(MagicItem* a_spell, bool a_noHitEffectArt, TESObjectREFR* a_target, float a_effectiveness, bool a_hostileEffectivenessOnly, float a_magnitudeOverride, Actor* a_blameActor) override;  // 02
		TESObjectREFR* GetCasterStatsObject() const override;                                                                                                                                                                    // 0C
		Actor*         GetCasterAsActor() const override;                                                                                                                                                                        // 0D
		TESObjectREFR* GetCasterObjectReference(Actor** a_outCaster) const override;                                                                                                                                             // 0E
		NiNode*        GetMagicNode() override;                                                                                                                                                                                  // 0F

		// members
		TESObjectREFR* ref;         // 60
		ActorHandle    blameActor;  // 68
	};
	static_assert(sizeof(NonActorMagicCaster) == 0x70);
}
