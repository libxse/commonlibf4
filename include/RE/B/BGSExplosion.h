#pragma once

#include "RE/B/BGSExplosionData.h"
#include "RE/B/BGSPreloadable.h"
#include "RE/T/TESBoundObject.h"
#include "RE/T/TESEnchantableForm.h"
#include "RE/T/TESFullName.h"
#include "RE/T/TESImageSpaceModifiableForm.h"
#include "RE/T/TESModel.h"

namespace RE
{
	class __declspec(novtable) BGSExplosion :
		public TESBoundObject,              // 000
		public TESFullName,                 // 068
		public TESModel,                    // 078
		public TESEnchantableForm,          // 0A8
		public BGSPreloadable,              // 0C0
		public TESImageSpaceModifiableForm  // 0C8
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSExplosion };
		static constexpr auto VTABLE{ VTABLE::BGSExplosion };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kEXPL };

		enum class EXPLOSION_TYPE
		{
			kNormal = 0x0,
			kChain = 0x1
		};

		enum class KnockDownMode
		{
			kNever = 0x0,
			kAlways = 0x1,
			kFormula = 0x2,
			kNPC = 0x3
		};

		// members
		BGSExplosionData data;  // 0D8
	};
	static_assert(sizeof(BGSExplosion) == 0x148);
}
