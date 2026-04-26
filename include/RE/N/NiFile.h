#pragma once

#include "RE/B/BSSystemFile.h"
#include "RE/N/NiBinaryStream.h"

namespace RE
{
	class __declspec(novtable) NiFile :
		public NiBinaryStream  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::NiFile };
		static constexpr auto VTABLE{ VTABLE::NiFile };

		enum class OpenMode : std::int32_t
		{
			kReadOnly,
			kWriteOnly,
			kAppendOnly,
			kReadWrite,
		};

		// members
		std::size_t                           bufferAllocSize;  // 10
		std::size_t                           bufferReadSize;   // 18
		std::size_t                           pos;              // 20
		std::size_t                           currentFilePos;   // 28
		char*                                 buffer;           // 30
		BSSystemFile                          systemFile;       // 38
		REX::TEnumSet<OpenMode, std::int32_t> mode;             // 48
		bool                                  good;             // 4C
	};
	static_assert(sizeof(NiFile) == 0x50);
}
