#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTSingleton.h"
#include "RE/I/INPUT_DEVICE.h"
#include "RE/U/UserEvents.h"

namespace RE
{
	enum class PC_GAMEPAD_TYPE;

	class ControlMap :
		public BSTSingletonSDM<ControlMap>  // 000
	{
	public:
		using InputContextID = UserEvents::INPUT_CONTEXT_ID;

		enum : std::uint32_t
		{
			kInvalid = static_cast<std::uint8_t>(-1)
		};

		class UserEventMapping
		{
		public:
			// members
			BSFixedString                                            eventID;             // 00
			std::int32_t                                             inputKey;            // 08
			std::int8_t                                              byIndexInContext;    // 0C
			bool                                                     remappable;          // 0D
			bool                                                     linked;              // 0E
			REX::TEnumSet<UserEvents::USER_EVENT_FLAG, std::int32_t> userEventGroupFlag;  // 10
		};
		static_assert(sizeof(UserEventMapping) == 0x18);

		class InputContext
		{
		public:
			// members
			BSTArray<UserEventMapping> deviceMappings[std::to_underlying(INPUT_DEVICE::kSupported)];  // 00
		};
		static_assert(sizeof(InputContext) == 0x48);

		class LinkedMapping
		{
		public:
			// members
			BSFixedString                                             linkedMappingName;     // 00
			REX::TEnumSet<UserEvents::INPUT_CONTEXT_ID, std::int32_t> linkedMappingContext;  // 08
			REX::TEnumSet<INPUT_DEVICE, std::int32_t>                 device;                // 0C
			REX::TEnumSet<UserEvents::INPUT_CONTEXT_ID, std::int32_t> linkFromContext;       // 10
			BSFixedString                                             linkFromName;          // 18
		};
		static_assert(sizeof(LinkedMapping) == 0x20);

		[[nodiscard]] static ControlMap* GetSingleton()
		{
			static REL::Relocation<ControlMap**> singleton{ ID::ControlMap::Singleton };
			return *singleton;
		}

		std::uint32_t GetMappedKey(std::string_view a_eventID, INPUT_DEVICE a_device, InputContextID a_context = InputContextID::kMainGameplay) const
		{
			assert(a_device < INPUT_DEVICE::kTotal);
			assert(a_context < InputContextID::kTotal);

			if (controlMaps[std::to_underlying(a_context)]) {
				const auto&   mappings = controlMaps[std::to_underlying(a_context)]->deviceMappings[std::to_underlying(a_device)];
				BSFixedString eventID(a_eventID);
				for (auto& mapping : mappings) {
					if (mapping.eventID == eventID) {
						return mapping.inputKey;
					}
				}
			}

			return kInvalid;
		}

		bool PopInputContext(UserEvents::INPUT_CONTEXT_ID a_context)
		{
			using func_t = decltype(&ControlMap::PopInputContext);
			static REL::Relocation<func_t> func{ ID::ControlMap::PopInputContext };
			return func(this, a_context);
		}

		void PushInputContext(UserEvents::INPUT_CONTEXT_ID a_context)
		{
			using func_t = decltype(&ControlMap::PushInputContext);
			static REL::Relocation<func_t> func{ ID::ControlMap::PushInputContext };
			return func(this, a_context);
		}

		bool RemapButton(BSFixedString const& a_id, INPUT_DEVICE a_device, std::int32_t a_buttonID)
		{
			using func_t = decltype(&ControlMap::RemapButton);
			static REL::Relocation<func_t> func{ ID::ControlMap::RemapButton };
			return func(this, a_id, a_device, a_buttonID);
		}

		void SaveRemappings()
		{
			using func_t = decltype(&ControlMap::SaveRemappings);
			static REL::Relocation<func_t> func{ ID::ControlMap::SaveRemappings };
			return func(this);
		}

		void SetTextEntryMode(bool a_enable)
		{
			using func_t = decltype(&ControlMap::SetTextEntryMode);
			static REL::Relocation<func_t> func{ ID::ControlMap::SetTextEntryMode };
			return func(this, a_enable);
		}

		void SetIgnoreKeyboardMouse(bool a_value) noexcept { ignoreKeyboardMouse = a_value; }

		// members
		InputContext*                                                       controlMaps[std::to_underlying(UserEvents::INPUT_CONTEXT_ID::kTotal)];  // 008
		BSTArray<LinkedMapping>                                             linkedMappings;                                                         // 110
		BSTArray<REX::TEnumSet<UserEvents::INPUT_CONTEXT_ID, std::int32_t>> contextPriorityStack;                                                   // 128
		std::int8_t                                                         byTextEntryCount;                                                       // 140
		bool                                                                ignoreKeyboardMouse;                                                    // 141
		bool                                                                ignoreActivateDisabledEvents;                                           // 142
		REX::TEnumSet<PC_GAMEPAD_TYPE, std::int32_t>                        pcGamePadMapType;                                                       // 144
	};
	static_assert(sizeof(ControlMap) == 0x148);
}
