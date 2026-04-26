#pragma once

namespace RE
{
	class __declspec(novtable) PipboyCommandResult
	{
	public:
		static constexpr auto RTTI{ RTTI::PipboyCommandResult };
		static constexpr auto VTABLE{ VTABLE::PipboyCommandResult };

		// add
		virtual ~PipboyCommandResult();                   // 00
		virtual void Serialize(Json::Value* a_json) = 0;  // 01

		// members
		const std::uint32_t commandID;    // 08
		const bool          succeeded;    // 0C
		const bool          shouldReply;  // 0D
	};
	static_assert(sizeof(PipboyCommandResult) == 0x10);
}
