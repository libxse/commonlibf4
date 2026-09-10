#pragma once

#include "RE/B/BSActorPathingMessage.h"
#include "RE/B/BSIntrusiveRefCounted.h"
#include "RE/B/BSSpinLock.h"
#include "RE/B/BSTArray.h"

namespace RE
{
	class BSActorPathingMessageQueue :
		public BSIntrusiveRefCounted
	{
	public:
		// members
		BSTSmallArray<BSActorPathingMessage, 1> messages;      // 008
		BSSpinLock                              messagesLock;  // 030
	};
	static_assert(sizeof(BSActorPathingMessageQueue) == 0x38);
}
