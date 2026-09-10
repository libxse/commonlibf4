#pragma once

#include "RE/B/BSIntrusiveRefCounted.h"
#include "RE/B/BSTSmartPointer.h"

namespace RE
{
	class bhkWorld;
	class BSPathingNumericIDVisitor;
	class BSPathingSpace;
	class BSPathingStreamRead;
	class BSPathingStreamWrite;

	class __declspec(novtable) BSPathingCell :
		public BSIntrusiveRefCounted  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BSPathingCell };
		static constexpr auto VTABLE{ VTABLE::BSPathingCell };

		virtual ~BSPathingCell();                                                            // 00
		virtual std::uint32_t GetType();                                                     // 01
		virtual void          Write(BSPathingStreamWrite* a_dst);                            // 02
		virtual void          Read(BSPathingStreamRead* a_src);                              // 03
		virtual void          FixupNumericID(BSPathingNumericIDVisitor* a_visitor);          // 04
		virtual bool          IsEqual(const BSTSmartPointer<BSPathingCell>* a_other);        // 05
		virtual void          GetSpace(BSTSmartPointer<BSPathingSpace>* a_spaceOut);         // 06
		virtual bhkWorld*     GetBhkWorld();                                                 // 07
		virtual bool          QValid();                                                      // 08
		virtual bool          QAttached();                                                   // 09
		virtual bool          QLoaded();                                                     // 0A
		virtual bool          IsInSameSpace(const BSTSmartPointer<BSPathingCell>* a_other);  // 0B
	};
	static_assert(sizeof(BSPathingCell) == 0x10);
}
