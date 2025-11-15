#pragma once

namespace RE
{
	class hknpShapeType
	{
	public:
		enum class Enum
		{
			kConvex,
			kConvexPolytope,
			kSphere,
			kCapsule,
			kTriangle,
			kCompressedMesh,
			kExternMesh,
			kStaticCompound,
			kDynamicCompound,
			kHeightField,
			kCompressedHeightField,
			kScaledConvex,
			kMasked,
			kMaskedCompound,
			kLOD,
			kDummy,
			kUser0,
			kUser1,
			kUser2,
			kUser3,

			kTotal,

			kInvalid
		};
	};
	static_assert(std::is_empty_v<hknpShapeType>);
}
