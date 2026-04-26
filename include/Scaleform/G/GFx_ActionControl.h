#pragma once

#include "Scaleform/F/Flags.h"
#include "Scaleform/G/GFx_State.h"

namespace Scaleform::GFx
{
	class __declspec(novtable) ActionControl :
		public State  // 00
	{
	public:
		static constexpr auto GFX_STATE_TYPE{ StateType::kActionControl };

		enum class ActionControlFlags : std::uint32_t
		{
			kVerbose = 0x01,
			kErrorSuppress = 0x02,
			kLogRootFilenames = 0x04,
			kLogChildFilenames = 0x08,
			kLogAllFilenames = 0x04 | 0x08,
			kLongFilenames = 0x10
		};

		ActionControl(Flags<ActionControlFlags> a_actionFlags = ActionControlFlags::kLogChildFilenames) :
			State(StateType::kActionControl), actionFlags(a_actionFlags)
		{}

		// members
		Flags<ActionControlFlags> actionFlags;  // 18
	};
	static_assert(sizeof(ActionControl) == 0x20);
}
