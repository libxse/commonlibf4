#pragma once

#include "RE/B/BSIntrusiveRefCounted.h"
#include "RE/B/BSResource.h"

namespace RE
{
	namespace BSExternalAudioIO
	{
		class ExternalLoad :
			public BSIntrusiveRefCounted  // 00
		{
		public:
			// members
			std::uint32_t bufferSize;    // 04
			std::uint32_t sourceSize;    // 08
			std::uint32_t streamOffset;  // 0C
			void*         buffer;        // 10
		};
		static_assert(sizeof(ExternalLoad) == 0x18);

		class __declspec(novtable) ExternalIOInterface
		{
		public:
			static constexpr auto RTTI{ RTTI::BSExternalAudioIO__ExternalIOInterface };
			static constexpr auto VTABLE{ VTABLE::BSExternalAudioIO__ExternalIOInterface };

			virtual ~ExternalIOInterface();  // 00

			// add
			virtual BSResource::ErrorCode Request(const BSResource::ID*, BSExternalAudioIO::ExternalLoad**);  // 01
		};
		static_assert(sizeof(ExternalIOInterface) == 0x08);

		class LipVoiceHeader
		{
		public:
			// members
			std::uint32_t magic;    // 00
			std::uint32_t version;  // 04
			std::uint32_t lipSize;  // 08
		};
		static_assert(sizeof(LipVoiceHeader) == 0x0C);
	}
}
