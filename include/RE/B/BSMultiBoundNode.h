#pragma once

#include "RE/B/BSCullingProcess.h"
#include "RE/B/BSMultiBoundShape.h"
#include "RE/B/BSNiNode.h"
#include "RE/N/NiBound.h"

namespace RE
{
	class BSMultiBoundRoom;

	class __declspec(novtable) BSMultiBoundNode :
		public BSNiNode  // 000
	{
	public:
		static constexpr auto RTTI{ RTTI::BSMultiBoundNode };
		static constexpr auto VTABLE{ VTABLE::BSMultiBoundNode };
		static constexpr auto Ni_RTTI{ Ni_RTTI::BSMultiBoundNode };

		// add
		virtual BSMultiBoundRoom*                      GetMultiBoundRoom();                            // 43
		virtual bool                                   QPointWithin(const NiPoint3* a_point);          // 44
		virtual BSMultiBoundShape::BSMBIntersectResult CheckBound(const BSMultiBound* a_Targetbound);  // 45
		virtual BSMultiBoundShape::BSMBIntersectResult CheckBound(const NiBound* a_Targetbound);       // 46

		// members
		NiPointer<BSMultiBound>                                     multiBound;     // 140
		REX::TEnumSet<BSCullingProcess::CullingType, std::uint32_t> cullingMode;    // 148
		float                                                       lastAccumTime;  // 14C
	};
	static_assert(sizeof(BSMultiBoundNode) == 0x150);
}
