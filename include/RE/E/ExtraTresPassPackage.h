#pragma once

#include "RE/B/BSExtraData.h"
#include "RE/T/TrespassPackage.h"

namespace RE
{
	class __declspec(novtable) ExtraTresPassPackage :
		public BSExtraData  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::ExtraTresPassPackage };
		static constexpr auto VTABLE{ VTABLE::ExtraTresPassPackage };
		static constexpr auto TYPE{ EXTRA_DATA_TYPE::kTresPassPackage };

		// members
		TrespassPackage* pack;  // 18
	};
	static_assert(sizeof(ExtraTresPassPackage) == 0x20);
}
