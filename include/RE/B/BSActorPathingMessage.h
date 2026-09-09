#pragma once

#include "RE/B/BSPathingRequest.h"
#include "RE/B/BSPathingSolution.h"
#include "RE/B/BSTSmartPointer.h"
#include "RE/P/PATHING_MESSAGE_TYPE.h"

namespace RE
{
	class BSActorPathingMessage
	{
	public:
		// members
		PATHING_MESSAGE_TYPE               type;      // 00
		BSTSmartPointer<BSPathingRequest>  request;   // 08
		BSTSmartPointer<BSPathingSolution> solution;  // 10
	};
	static_assert(sizeof(BSActorPathingMessage) == 0x18);
}
