#pragma once

#include "RE/B/BGSDestructibleObjectForm.h"
#include "RE/B/BGSEquipType.h"
#include "RE/B/BGSKeywordForm.h"
#include "RE/B/BGSMessageIcon.h"
#include "RE/B/BGSModelMaterialSwap.h"
#include "RE/B/BGSOpenCloseForm.h"
#include "RE/B/BGSPropertySheet.h"
#include "RE/N/NiColor.h"
#include "RE/N/NiPointer.h"
#include "RE/O/OBJ_LIGH.h"
#include "RE/T/TESBoundAnimObject.h"
#include "RE/T/TESIcon.h"
#include "RE/T/TESTexture.h"
#include "RE/T/TESValueForm.h"
#include "RE/T/TESWeightForm.h"

namespace RE
{
	class BSLight;
	class NiAVObject;
	class NiLight;
	class TESObjectREFR;

	class __declspec(novtable) TESObjectLIGH :
		public TESBoundAnimObject,         // 000
		public BGSModelMaterialSwap,       // 068
		public TESIcon,                    // 0A8
		public BGSMessageIcon,             // 0B8
		public TESWeightForm,              // 0D0
		public TESValueForm,               // 0E0
		public BGSDestructibleObjectForm,  // 0F0
		public BGSEquipType,               // 100
		public BGSPropertySheet,           // 110
		public BGSOpenCloseForm,           // 120
		public BGSKeywordForm              // 128
	{
	public:
		static constexpr auto RTTI{ RTTI::TESObjectLIGH };
		static constexpr auto VTABLE{ VTABLE::TESObjectLIGH };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kLIGH };
		static constexpr auto TYPE_ID{ BSScript::kLight };

		NiLight* GenDynamic(TESObjectREFR* a_ref, NiAVObject* a_root, bool a_dynamic, bool a_useFormRadius, bool a_requester, NiPointer<BSLight>* a_outLight, float a_shadowDepthBias, bool a_disableShadows)
		{
			using func_t = decltype(&TESObjectLIGH::GenDynamic);
			static REL::Relocation<func_t> func{ ID::TESObjectLIGH::GenDynamic };
			return func(this, a_ref, a_root, a_dynamic, a_useFormRadius, a_requester, a_outLight, a_shadowDepthBias, a_disableShadows);
		}

		void Update(NiPointer<NiLight>& a_light, TESObjectREFR* a_ref, float a_delta)
		{
			using func_t = decltype(&TESObjectLIGH::Update);
			static REL::Relocation<func_t> func{ ID::TESObjectLIGH::Update };
			return func(this, a_light, a_ref, a_delta);
		}

		// members
		OBJ_LIGH                data;            // 148
		float                   fade;            // 180
		BGSSoundDescriptorForm* sound;           // 188
		TESTexture              goboTexture;     // 190
		NiColor                 emittanceColor;  // 1A0
		BGSLensFlare*           lensFlare;       // 1B0
		BGSGodRays*             godRays;         // 1B8
	};
	static_assert(sizeof(TESObjectLIGH) == 0x1C0);
}
