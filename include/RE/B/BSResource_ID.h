#pragma once

#include "RE/B/BSResource_FileID.h"

namespace RE::BSResource
{
	class ID :
		public FileID  // 0
	{
	public:
		[[nodiscard]] bool operator==(const ID&) const noexcept = default;

		void GenerateFromPath(const char* a_path)
		{
			using func_t = decltype(&ID::GenerateFromPath);
			static REL::Relocation<func_t> func{ RE::ID::BSResource::ID::GenerateFromPath };
			return func(this, a_path);
		}

		// members
		std::uint32_t dir = 0;  // 8
	};
	static_assert(sizeof(ID) == 0xC);
}
