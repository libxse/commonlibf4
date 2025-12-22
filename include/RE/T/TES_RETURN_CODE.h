#pragma once

namespace RE
{
	enum class TES_RETURN_CODE
	{
		kNone = 0x0,
		kNotFound = 0x1,
		kNoFile = 0x2,
		kNoForm = 0x3,
		kNoChunk = 0x4,
		kNoID = 0x5,
		kBadFile = 0x6,
		kBadID = 0x7,
		kFormOpen = 0x8,
		kFileOpen = 0x9,
		kWriteFailure = 0xA,
		kInvalidFile = 0xB,
		kFileInUse = 0xC,
		kCreateFailure = 0xD
	};
}
