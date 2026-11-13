#pragma once

#include "RE/B/BSCRC32.h"
#include "RE/B/BSFixedString.h"
#include "RE/B/BSStringT.h"
#include "RE/M/MemoryManager.h"

namespace RE
{
	class TESFile;

	class BGSLocalizedStrings
	{
	public:
		class ScrapStringBuffer
		{
		public:
			[[nodiscard]] const char* GetString() const noexcept { return static_cast<const char*>(buffer.GetPtr()) + offset; }

			// members
			MemoryManager::AutoScrapBuffer buffer;  // 00
			std::size_t                    offset;  // 08
		};
		static_assert(sizeof(ScrapStringBuffer) == 0x10);
	};
	static_assert(std::is_empty_v<BGSLocalizedStrings>);

	class BGSLocalizedStringDL
	{
	public:
		[[nodiscard]] BGSLocalizedStrings::ScrapStringBuffer GetText(TESFile& a_file) const
		{
			using func_t = decltype(&BGSLocalizedStringDL::GetText);
			static REL::Relocation<func_t> func{ ID::BGSLocalizedStringDL::GetText };
			return func(this, a_file);
		}

		// members
		std::uint32_t id{ 0 };  // 0
	};
	static_assert(sizeof(BGSLocalizedStringDL) == 0x4);

	class BGSLocalizedStringIL
	{
	public:
		// Sets a_text to string a_id from a_file's .ILSTRINGS file, in the
		// game's current language. An a_id of 0 gives an empty string.
		static void LookupByID(BSFixedStringCS& a_text, const TESFile* a_file, std::uint32_t a_id)
		{
			using func_t = decltype(&BGSLocalizedStringIL::LookupByID);
			static REL::Relocation<func_t> func{ ID::BGSLocalizedStringIL::LookupByID };
			return func(a_text, a_file, a_id);
		}
	};

	class BGSLocalizedString
	{
	public:
		using size_type = typename BSFixedStringCS::size_type;
		using value_type = typename BSFixedStringCS::value_type;
		using pointer = typename BSFixedStringCS::pointer;
		using const_pointer = typename BSFixedStringCS::const_pointer;
		using reference = typename BSFixedStringCS::reference;
		using const_reference = typename BSFixedStringCS::const_reference;

		BGSLocalizedString& operator=(std::basic_string_view<value_type> a_rhs)
		{
			const auto self = static_cast<std::basic_string_view<value_type>>(_data);
			if (self.starts_with("<ID=")) {
				assert(self.length() >= PREFIX_LENGTH);
				std::vector<char> buf(PREFIX_LENGTH + a_rhs.length() + 1, '\0');
				strncpy_s(buf.data(), buf.size(), self.data(), PREFIX_LENGTH);
				strcpy_s(buf.data() + PREFIX_LENGTH, buf.size() - PREFIX_LENGTH, (a_rhs.empty() ? "" : a_rhs.data()));
				_data = std::string_view{ buf.data(), buf.size() };
			} else {
				_data = a_rhs;
			}

			return *this;
		}

		[[nodiscard]] const_pointer data() const noexcept { return _data.data(); }
		[[nodiscard]] const_pointer c_str() const noexcept { return _data.c_str(); }

		[[nodiscard]] operator std::basic_string_view<value_type>() const { return { _data }; }

		[[nodiscard]] bool empty() const noexcept { return _data.empty(); }

		[[nodiscard]] size_type size() const noexcept { return _data.size(); }
		[[nodiscard]] size_type length() const noexcept { return _data.length(); }

	protected:
		template <class>
		friend struct BSCRC32;

		[[nodiscard]] const BSFixedStringCS& hash_accessor() const noexcept { return _data; }

	private:
		static constexpr std::size_t PREFIX_LENGTH = 13;

		// members
		BSFixedStringCS _data;  // 0
	};
	static_assert(sizeof(BGSLocalizedString) == 0x8);

	template <>
	struct BSCRC32<BGSLocalizedString>
	{
	public:
		[[nodiscard]] std::uint32_t operator()(const BGSLocalizedString& a_key) const noexcept
		{
			return BSCRC32<BSFixedStringCS>()(a_key.hash_accessor());
		}
	};
}
