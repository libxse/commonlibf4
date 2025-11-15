#pragma once

namespace RE
{
	class hknpCollisionDispatchType
	{
	public:
		enum Enum
		{
			kNone,
			kConvex,
			kComposite,
			kDistanceField,
			kUser
		};
	};
	static_assert(std::is_empty_v<hknpCollisionDispatchType>);
}
