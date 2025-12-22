#pragma once

namespace RE
{
	class BSGaphics
	{
		class OcclussionQuery;
	};

	class SunOcclusionTest
	{
	public:
		BSGraphics::OcclusionQuery* occlusionQuery;   // 00
		float                       percentOccluded;  // 08
		std::uint32_t               pixelCount;       // 0C
		std::uint32_t               frameCount;       // 10
		bool                        waiting;          // 14
	};
}
