#pragma once

#include "RE/H/hkSignal.h"

namespace RE
{
	class hknpShapeSignals
	{
	public:
		enum class MutationFlagsEnum
		{
			kAABBChanged = 0x1,
			kUpdateCollisionCaches = 0x2,
			kRebuildCollisionCaches = 0x4
		};

		class ShapeDestroyedSignal :
			public hkSignal0
		{
		public:
		};
		static_assert(sizeof(ShapeDestroyedSignal) == 0x08);

		class ShapeMutatedSignal :
			public hkSignal1<std::uint8_t>
		{
		public:
		};
		static_assert(sizeof(ShapeMutatedSignal) == 0x08);

		// members
		ShapeMutatedSignal   shapeMutated;    // 00
		ShapeDestroyedSignal shapeDestroyed;  // 08
	};
	static_assert(sizeof(hknpShapeSignals) == 0x10);
}
