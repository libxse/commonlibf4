#pragma once

namespace RE
{
	class hkQuaternionf
	{
	public:
		// members
		hkVector4f vec;  // 00
	};
	static_assert(sizeof(hkQuaternionf) == 0x10);
}
