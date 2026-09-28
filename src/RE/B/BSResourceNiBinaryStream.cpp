#include "RE/B/BSResourceNiBinaryStream.h"

namespace RE
{
	BSResourceNiBinaryStream::BSResourceNiBinaryStream() :
		NiBinaryStream()
	{}

	BSResourceNiBinaryStream::BSResourceNiBinaryStream(const char* a_file, bool a_writeable, BSResource::Location* a_optionalStart, bool a_fullReadHint) :
		NiBinaryStream()
	{
		using func_t = void (*)(BSResourceNiBinaryStream*, const char*, bool, BSResource::Location*, bool);
		static REL::Relocation<func_t> func{ ID::BSResourceNiBinaryStream::Ctor };
		func(this, a_file, a_writeable, a_optionalStart, a_fullReadHint);
	}

	BSResourceNiBinaryStream::~BSResourceNiBinaryStream()
	{
		using func_t = void (*)(BSResourceNiBinaryStream*);
		static REL::Relocation<func_t> func{ ID::BSResourceNiBinaryStream::Dtor };
		func(this);
	}

	void BSResourceNiBinaryStream::Seek(std::ptrdiff_t a_numBytes)
	{
		using func_t = decltype(&BSResourceNiBinaryStream::Seek);
		static REL::Relocation<func_t> func{ ID::BSResourceNiBinaryStream::Seek };
		return func(this, a_numBytes);
	}

	void BSResourceNiBinaryStream::GetBufferInfo(BufferInfo& a_buf)
	{
		using func_t = decltype(&BSResourceNiBinaryStream::GetBufferInfo);
		static REL::Relocation<func_t> func{ ID::BSResourceNiBinaryStream::GetBufferInfo };
		return func(this, a_buf);
	}

	std::size_t BSResourceNiBinaryStream::DoRead(void* a_buf, std::size_t a_toRead)
	{
		using func_t = decltype(&BSResourceNiBinaryStream::DoRead);
		static REL::Relocation<func_t> func{ ID::BSResourceNiBinaryStream::DoRead };
		return func(this, a_buf, a_toRead);
	}

	std::size_t BSResourceNiBinaryStream::DoWrite(const void* a_buf, std::size_t a_toWrite)
	{
		using func_t = decltype(&BSResourceNiBinaryStream::DoWrite);
		static REL::Relocation<func_t> func{ ID::BSResourceNiBinaryStream::DoWrite };
		return func(this, a_buf, a_toWrite);
	}

	std::uint32_t BSResourceNiBinaryStream::ReadLine(char * a_buf, std::uint32_t a_bytes, std::uint32_t a_term)
	{
		using func_t = decltype(&BSResourceNiBinaryStream::ReadLine);
		static REL::Relocation<func_t> func{ ID::BSResourceNiBinaryStream::ReadLine };
		return func(this, a_buf, a_bytes, a_term);
	}

	[[nodiscard]] BSResourceNiBinaryStream* BSResourceNiBinaryStream::BinaryStreamWithRescan(const char* a_fileName)
	{
		using func_t = decltype(&BSResourceNiBinaryStream::BinaryStreamWithRescan);
		static REL::Relocation<func_t> func{ ID::BSResourceNiBinaryStream::BinaryStreamWithRescan };
		return func(a_fileName);
	}
}
