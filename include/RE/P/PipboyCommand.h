#pragma once

namespace RE
{
	class PipboyCommandResult;

	class __declspec(novtable) PipboyCommand
	{
	public:
		static constexpr auto RTTI{ RTTI::PipboyCommand };
		static constexpr auto VTABLE{ VTABLE::PipboyCommand };

		// add
		virtual ~PipboyCommand();                                          // 00
		virtual void                       Init(Json::Value* a_json) = 0;  // 01
		virtual const PipboyCommandResult* DoValidate();                   // 02
		virtual const PipboyCommandResult* DoExecute();                    // 03

		// members
		const std::uint32_t        id;                // 08
		const PipboyCommandResult* validationResult;  // 10
		const PipboyCommandResult* executionResult;   // 18
		bool                       isReadonOnly;      // 20
	};
	static_assert(sizeof(PipboyCommand) == 0x28);
}
