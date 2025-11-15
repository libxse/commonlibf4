#pragma once

#include "RE/B/BSSpinLock.h"
#include "RE/B/BSTHashMap.h"
#include "RE/H/hkMap.h"
#include "RE/H/hknpBodyId.h"
#include "RE/H/hknpWorld.h"

namespace RE
{
	class __declspec(novtable) hknpBSWorld :
		public hknpWorld
	{
	public:
		static constexpr auto RTTI{ RTTI::hknpBSWorld };
		static constexpr auto VTABLE{ VTABLE::hknpBSWorld };

		virtual ~hknpBSWorld() override;  // 00

		// members
		void*                     userData;                        // 6D0
		BSReadWriteLock           worldLock;                       // 6D8
		std::byte                 activateBodyPostCollideSet[48];  // 6E0 - BSTSet<hknpBodyId>
		BSSpinLock                activateBodyPostCollideLock;     // 710
		hkMultiMap<std::uint32_t> constrainedBodyFromBody;         // 718
	};
	static_assert(sizeof(hknpBSWorld) == 0x730);
}
