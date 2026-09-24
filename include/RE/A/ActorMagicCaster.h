#pragma once

#include "RE/B/BSTEvent.h"
#include "RE/M/MagicCaster.h"
#include "RE/R/RefAttachTechniqueInput.h"
#include "RE/S/SimpleAnimationGraphManagerHolder.h"

namespace RE
{
	class BSAnimationGraphEvent;

	class __declspec(novtable) ActorMagicCaster :
		public MagicCaster,                         // 00
		public SimpleAnimationGraphManagerHolder,   // 48
		public BSTEventSink<BSAnimationGraphEvent>  // 60
	{
	public:
		static constexpr auto RTTI{ RTTI::ActorMagicCaster };
		static constexpr auto VTABLE{ VTABLE::ActorMagicCaster };

		~ActorMagicCaster() override;  // 00

		// override (MagicCaster)
		bool                       CheckCast(MagicItem* a_spell, bool a_dualCast, float* a_effectiveness, MagicSystem::CannotCastReason* a_reason, bool a_arg5) override;  // 0B
		TESObjectREFR*             GetCasterStatsObject() const override;                                                                                                  // 0C
		Actor*                     GetCasterAsActor() const override;                                                                                                      // 0D
		NiNode*                    GetMagicNode() override;                                                                                                                // 0F
		void                       ClearMagicNode() override;                                                                                                              // 10
		MagicSystem::CastingSource GetCastingSource() const override;                                                                                                      // 16
		bool                       GetIsDualCasting() const override;                                                                                                      // 17
		void                       SetDualCasting(bool a_dualCasting) override;                                                                                            // 18
		void                       AdjustActiveEffect(ActiveEffect* a_effect, float a_power, bool a_hostileEffectivenessOnly) override;                                    // 1D

		// members
		RefAttachTechniqueInput    unk68;          // 68
		std::uint64_t              unkB0;          // B0
		Actor*                     actor;          // B8
		NiNode*                    magicNode;      // C0
		std::uint64_t              unkC8;          // C8
		std::uint64_t              unkD0;          // D0
		std::uint64_t              unkD8;          // D8
		std::uint64_t              unkE0;          // E0
		std::uint64_t              unkE8;          // E8
		std::uint32_t              unkF0;          // F0
		MagicSystem::CastingSource castingSource;  // F4
		std::uint32_t              flags;          // F8
	};
	static_assert(sizeof(ActorMagicCaster) == 0x100);
}
