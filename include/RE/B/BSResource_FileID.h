#pragma once

namespace RE::BSResource
{
	class FileID
	{
	public:
		[[nodiscard]] bool operator==(const FileID&) const noexcept = default;

		// members
		std::uint32_t file{ 0 };  // 0
		std::uint32_t ext{ 0 };   // 4
	};
	static_assert(sizeof(FileID) == 0x8);
}
