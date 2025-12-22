#pragma once

namespace RE
{
	class BSNavmeshInfo;

	class BSNavmeshTriHandle
	{
	public:
		BSNavmeshInfo* pNavMeshInfo;  // 00
		std::uint16_t  triangle;      // 08
	};
	static_assert(sizeof(BSNavmeshTriHandle) == 0x10);
}
