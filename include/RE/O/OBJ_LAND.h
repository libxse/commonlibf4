#pragma once

namespace RE
{
	class OBJ_LAND
	{
	public:
		enum class LAND
		{
			kHeightAltered = 1 << 0,
			kCLRAltered = 1 << 1,
			kTexAltered = 1 << 2,
			kLoaded = 1 << 3,
			kGoodNormals = 1 << 4,
			kHiResHeightfield = 1 << 5,

			kRemapped = 1 << 10,

			kDataAltered = kHeightAltered | kCLRAltered | kTexAltered | kHiResHeightfield,
		};

		// members
		REX::TEnumSet<LAND, std::uint32_t> flags;  // 0
	};
	static_assert(sizeof(OBJ_LAND) == 0x4);
}
