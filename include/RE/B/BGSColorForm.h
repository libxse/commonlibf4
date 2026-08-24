#pragma once

#include "RE/T/TESCondition.h"
#include "RE/T/TESForm.h"
#include "RE/T/TESFullName.h"

namespace RE
{
	class __declspec(novtable) BGSColorForm :
		public TESForm,     // 00
		public TESFullName  // 20
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSColorForm };
		static constexpr auto VTABLE{ VTABLE::BGSColorForm };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kCLFM };

		enum class Flags : std::int32_t
		{
			kPlayable = 0x1,
			kRemappingIndex = 0x2
		};

		// members
		union
		{
			struct
			{
				std::uint8_t r;
				std::uint8_t g;
				std::uint8_t b;
				std::uint8_t x;
			} channels;
			std::uint32_t color;
			float         remappingIndex;
		};  // 30
		TESCondition  conditions;  // 38
		std::uint32_t flags;       // 40
	};
	static_assert(sizeof(BGSColorForm) == 0x48);
}
