#pragma once

namespace RE
{
	class BGSHazardData
	{
	public:
		enum class BGSHazardFlags
		{
			kNone = 0,
			kPlayerOnly = 1 << 0,
			kInheritDuration = 1 << 1,
			kAlignToNormal = 1 << 2,
			kInheritRadius = 1 << 3,
			kDropToGround = 1 << 4,
			kTaperEffectiveness = 1 << 5,
		};

		// members
		std::uint32_t                                limit;             // 00
		float                                        radius;            // 04
		float                                        lifetime;          // 08
		float                                        imageSpaceRadius;  // 0C
		float                                        targetInterval;    // 10
		REX::TEnumSet<BGSHazardFlags, std::uint32_t> flags;             // 14
		SpellItem*                                   spell;             // 18
		TESObjectLIGH*                               light;             // 20
		BGSImpactDataSet*                            impactDataSet;     // 28
		BGSSoundDescriptorForm*                      sound;             // 30
		float                                        fullEffectRadius;  // 38
		float                                        taperWeight;       // 3C
		float                                        taperCurve;        // 40
	};
	static_assert(sizeof(BGSHazardData) == 0x48);
}
