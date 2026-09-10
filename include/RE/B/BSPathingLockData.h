#pragma once

#include "RE/B/BSIntrusiveRefCounted.h"
#include "RE/B/BSTSmartPointer.h"

namespace RE
{
	class BSPathingDoor;
	class BSPathingStreamRead;
	class BSPathingStreamWrite;

	class __declspec(novtable) BSPathingLockData :
		public BSIntrusiveRefCounted
	{
	public:
		static constexpr auto RTTI{ RTTI::BSPathingLockData };
		static constexpr auto VTABLE{ VTABLE::BSPathingLockData };

		virtual ~BSPathingLockData();                                                                                  // 00
		virtual std::uint32_t GetType();                                                                               // 01
		virtual bool          CanTraverse(const BSTSmartPointer<BSPathingDoor>* a_door, float* a_arg2, bool* a_arg3);  // 02
		virtual bool          CanTraverse(const BSTSmartPointer<BSPathingDoor>* a_door, float* a_arg2);                // 03
		virtual bool          CanTraverse(const BSTSmartPointer<BSPathingDoor>* a_door);                               // 04
		virtual void          Write(BSPathingStreamWrite* a_dst);                                                      // 05
		virtual void          Read(BSPathingStreamRead* a_src);                                                        // 06
	};
	static_assert(sizeof(BSPathingLockData) == 0x10);
}
