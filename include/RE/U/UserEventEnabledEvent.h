#pragma once

#include "RE/U/UserEvents.h"

namespace RE
{
	class UserEventEnabledEvent
	{
	public:
		// members
		REX::TEnumSet<UserEvents::USER_EVENT_FLAG, std::int32_t> newUserEventFlag;  // 0
		REX::TEnumSet<UserEvents::USER_EVENT_FLAG, std::int32_t> oldUserEventFlag;  // 4
		REX::TEnumSet<UserEvents::SENDER_ID, std::int32_t>       senderID;          // 8
	};
	static_assert(sizeof(UserEventEnabledEvent) == 0xC);
}
