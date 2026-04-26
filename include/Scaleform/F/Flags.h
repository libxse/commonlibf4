#pragma once

namespace Scaleform
{
	template <class E, class U = std::underlying_type_t<E>>
	using Flags = REX::TEnumSet<E, U>;
}
