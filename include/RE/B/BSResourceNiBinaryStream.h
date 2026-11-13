#pragma once

#include "RE/B/BSResource_ErrorCode.h"
#include "RE/B/BSResource_Stream.h"
#include "RE/B/BSTSmartPointer.h"
#include "RE/N/NiBinaryStream.h"

namespace RE
{
	namespace BSResource
	{
		class Location;
	}

	class BSResourceNiBinaryStream :
		public NiBinaryStream
	{
	public:
		inline static constexpr auto RTTI{ RTTI::BSResourceNiBinaryStream };
		inline static constexpr auto VTABLE{ VTABLE::BSResourceNiBinaryStream };

		class BufferType;

		BSResourceNiBinaryStream();
		BSResourceNiBinaryStream(const char* a_file, bool a_writeable = false, BSResource::Location* a_optionalStart = nullptr, bool a_fullReadHint = false);

		virtual ~BSResourceNiBinaryStream() override;  // 00

		// override (NiBinaryStream)
		explicit    operator bool() const noexcept override { return static_cast<bool>(stream); };  // 01 - { return static_cast<bool>(stream); }
		void        Seek(std::ptrdiff_t a_numBytes) override;                                       // 02
		std::size_t GetPosition() const noexcept override { return streamPos; };                    // 03 - { return streamPos; }
		void        GetBufferInfo(BufferInfo& a_buf) override;                                      // 04
		std::size_t DoRead(void* a_buf, std::size_t a_bytes) override;                              // 05
		std::size_t DoWrite(const void* a_buf, std::size_t a_bytes) override;                       // 06

		std::uint32_t ReadLine(char * a_buf, std::uint32_t a_bytes, std::uint32_t a_term);  // 07

		[[nodiscard]] static BSResourceNiBinaryStream* BinaryStreamWithRescan(const char* a_fileName);

		// members
		BSTSmartPointer<BSResource::Stream> stream{ nullptr };                          // 10
		BufferType*                         buffer{ nullptr };                          // 18
		std::size_t                         streamPos{ 0 };                             // 20
		BSResource::ErrorCode               lastError{ BSResource::ErrorCode::kNone };  // 28
	};
	static_assert(sizeof(BSResourceNiBinaryStream) == 0x30);
}
