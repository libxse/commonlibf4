#pragma once

namespace RE
{
	namespace NonMorphFaceManagement
	{
		class InstanceData
		{
		public:
			// members
			void* instanceData;  // 00
		};
		static_assert(sizeof(InstanceData) == 0x8);
	}
}
