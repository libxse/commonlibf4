#pragma once

#include "RE/B/BSExtraData.h"
#include "RE/M/MagicCaster.h"

namespace RE
{
	class __declspec(novtable) ExtraMagicCaster :
		public BSExtraData,  // 00
		public MagicCaster   // 18
	{
	public:
		static constexpr auto RTTI{ RTTI::ExtraMagicCaster };
		static constexpr auto VTABLE{ VTABLE::ExtraMagicCaster };
		static constexpr auto TYPE{ EXTRA_DATA_TYPE::kMagicCaster };

		~ExtraMagicCaster() override;  // 00
	};
	static_assert(sizeof(ExtraMagicCaster) == 0x60);
}
