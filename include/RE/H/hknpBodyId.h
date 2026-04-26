#pragma once

#include "RE/H/hkHandle.h"

namespace RE
{
	class hknpBodyIdBaseDiscriminant
	{
	public:
	};
	static_assert(std::is_empty_v<hknpBodyIdBaseDiscriminant>);

	class hknpBodyId :
		public hkHandle<std::uint32_t, 2147483647, hknpBodyIdBaseDiscriminant>
	{
	public:
	};
	static_assert(sizeof(hknpBodyId) == 0x04);
}
