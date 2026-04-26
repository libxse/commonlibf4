#pragma once

#include "RE/D/DecalData.h"
#include "RE/T/TESForm.h"
#include "RE/T/TESModel.h"

namespace RE
{
	enum class SOUND_LEVEL;

	class __declspec(novtable) BGSImpactData :
		public TESForm,  // 00
		public TESModel  // 20
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSImpactData };
		static constexpr auto VTABLE{ VTABLE::BGSImpactData };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kIPCT };

		enum class ORIENTATION
		{
			kSurfaceNormal = 0x0,
			kProjVector = 0x1,
			kProjReflect = 0x2
		};

		class IMPACT_DATA_DATA
		{
		public:
			// members
			float                                    effectDuration;   // 00
			REX::TEnumSet<ORIENTATION, std::int32_t> orient;           // 04
			float                                    angleThreshold;   // 08
			float                                    placementRadius;  // 0C
			REX::TEnumSet<SOUND_LEVEL, std::int32_t> soundLevel;       // 10
			std::int8_t                              flags;            // 14
			std::int8_t                              resultOverride;   // 15
		};
		static_assert(sizeof(IMPACT_DATA_DATA) == 0x18);

		// members
		IMPACT_DATA_DATA        data;                     // 50
		BGSTextureSet*          decalTextureSet;          // 68
		BGSTextureSet*          decalTextureSet2;         // 70
		BGSSoundDescriptorForm* sound1;                   // 78
		BGSSoundDescriptorForm* sound2;                   // 80
		BGSExplosion*           explosion;                // 88
		BGSHazard*              hazard;                   // 90
		DecalData               decalData;                // 98
		float                   maxFootstepParticleDist;  // BC
	};
	static_assert(sizeof(BGSImpactData) == 0xC0);
}
