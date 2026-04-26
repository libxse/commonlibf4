#pragma once

#include "RE/B/BSExtraData.h"
#include "RE/R/RagDollData.h"

namespace RE
{
	class __declspec(novtable) ExtraRagDolldata :
		public BSExtraData  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::ExtraRagDollData };
		static constexpr auto VTABLE{ VTABLE::ExtraRagDollData };
		static constexpr auto TYPE{ EXTRA_DATA_TYPE::kRagdollData };

		// members
		RagDollData* ragDollData;  // 18
	};
	static_assert(sizeof(ExtraRagDolldata) == 0x20);
}
