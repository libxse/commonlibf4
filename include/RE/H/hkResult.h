#pragma once

#include "RE/H/hkResultEnum.h"

namespace RE
{
	class hkResult
	{
	public:
		~hkResult() noexcept {}  // NOLINT(modernize-use-equals-default)

		// members
		hkResultEnum e;  // 0
	};
	static_assert(sizeof(hkResult) == 0x4);
}
