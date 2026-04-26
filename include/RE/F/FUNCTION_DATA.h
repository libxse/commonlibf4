#pragma once

namespace RE
{
	enum class SCRIPT_OUTPUT;

	class FUNCTION_DATA
	{
	public:
		// members
		REX::TEnumSet<SCRIPT_OUTPUT, std::uint16_t> function;  // 00
		void*                                       param[2];  // 08
	};
	static_assert(sizeof(FUNCTION_DATA) == 0x18);
}
