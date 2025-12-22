#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/B/BSSpinLock.h"
#include "RE/B/BSSystemFile.h"

namespace RE
{
	class BSLog
	{
	public:
		// members
		BSFixedString       logName;        // 00
		BSFixedString       logPath;        // 08
		bool                addTimestamps;  // 10
		std::uint32_t       logsToKeep;     // 14
		BSSpinLock          bufferLock;     // 18
		char*               buffer;         // 20
		const std::uint32_t bufferSize;     // 28
		char*               writePos;       // 30
		char*               readPos;        // 38
		bool                folderExists;   // 40
		bool                fileOpen;       // 41
		BSSystemFile        log;
	};
	static_assert(sizeof(BSLog) == 0x58);
}
