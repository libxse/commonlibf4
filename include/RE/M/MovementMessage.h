#pragma once

#include "RE/B/BSIntrusiveRefCounted.h"

namespace RE
{
	class BSPathingNumericIDVisitor;
	class BSPathingStreamRead;
	class BSPathingStreamWrite;
	class IPathFollowerAction;

	class __declspec(novtable) MovementMessage :
		public BSIntrusiveRefCounted  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::MovementMessage };
		static constexpr auto VTABLE{ VTABLE::MovementMessage };

		virtual ~MovementMessage();                                                         // 00
		virtual std::uint32_t        GetMessageType();                                      // 01
		virtual std::uint32_t        GetType();                                             // 02
		virtual void                 Write(BSPathingStreamWrite* a_dst);                    // 03
		virtual void                 Read(BSPathingStreamRead* a_src);                      // 04
		virtual void                 FixupNumericID(BSPathingNumericIDVisitor* a_visitor);  // 05
		virtual IPathFollowerAction* GetPathFollowerActionInterface();                      // 06
	};
	static_assert(sizeof(MovementMessage) == 0x10);
}
