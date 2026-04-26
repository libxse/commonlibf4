#pragma once

#include "RE/B/BSISoundOutputModel.h"
#include "RE/T/TESForm.h"

namespace RE
{
	class __declspec(novtable) BGSSoundOutput :
		public TESForm,             // 00
		public BSISoundOutputModel  // 20
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSSoundOutput };
		static constexpr auto VTABLE{ VTABLE::BGSSoundOutput };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kSOPM };

		enum class SPEAKER_OUTPUT_MODE;

		class DynamicAttenuationCharacteristics;
		class SpeakerArrays;

		// members
		DynamicAttenuationCharacteristics*               attenuation;          // 28
		SpeakerArrays*                                   speakerOutputArrays;  // 30
		BGSAudioEffectChain*                             effectChain;          // 38
		std::uint32_t                                    flags;                // 40
		REX::TEnumSet<SPEAKER_OUTPUT_MODE, std::int32_t> mode;                 // 44
		std::uint16_t                                    staticAttenuation;    // 48
	};
	static_assert(sizeof(BGSSoundOutput) == 0x50);
}
