#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/B/BSSpinLock.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTEvent.h"
#include "RE/B/BSTSingleton.h"
#include "RE/B/BSTSmartPointer.h"
#include "RE/O/OtherInputEvents.h"
#include "RE/U/UserEvents.h"

namespace RE
{
	class BSInputEnableLayer;
	class InputEnableLayerDestroyedEvent;
	class OtherEventEnabledEvent;
	class UserEventEnabledEvent;

	class BSInputEnableManager :
		public BSTEventSource<UserEventEnabledEvent>,           // 000
		public BSTEventSource<OtherEventEnabledEvent>,          // 058
		public BSTEventSource<InputEnableLayerDestroyedEvent>,  // 0B0
		public BSTSingletonSDM<BSInputEnableManager>            // 108
	{
	public:
		class EnableLayer
		{
		public:
			// members
			REX::TEnumSet<UserEvents::USER_EVENT_FLAG, std::uint32_t>        inputUserEvents;   // 00
			REX::TEnumSet<OtherInputEvents::OTHER_EVENT_FLAG, std::uint32_t> otherInputEvents;  // 04
		};
		static_assert(sizeof(EnableLayer) == 0x08);

		[[nodiscard]] static BSInputEnableManager* GetSingleton()
		{
			static REL::Relocation<BSInputEnableManager**> singleton{ ID::BSInputEnableManager::Singleton };
			return *singleton;
		}

		bool AllocateNewLayer(BSTSmartPointer<BSInputEnableLayer>& a_layer, const char* a_debugName)
		{
			using func_t = decltype(&BSInputEnableManager::AllocateNewLayer);
			static REL::Relocation<func_t> func{ ID::BSInputEnableManager::AllocateNewLayer };
			return func(this, a_layer, a_debugName);
		}

		void ClearForcedState()
		{
			BSAutoLock locker(cacheLock);
			forceEnableInputUserEventsFlags.reset();
			forceOtherInputEventsFlags.reset();
		}

		bool EnableUserEvent(std::uint32_t a_layerID, UserEvents::USER_EVENT_FLAG a_userEventFlags, bool a_enable, UserEvents::SENDER_ID a_senderID)
		{
			using func_t = decltype(&BSInputEnableManager::EnableUserEvent);
			static REL::Relocation<func_t> func{ ID::BSInputEnableManager::EnableUserEvent };
			return func(this, a_layerID, a_userEventFlags, a_enable, a_senderID);
		}

		bool EnableOtherEvent(std::uint32_t a_layerID, OtherInputEvents::OTHER_EVENT_FLAG a_otherEventFlags, bool a_enable, UserEvents::SENDER_ID a_senderID)
		{
			using func_t = decltype(&BSInputEnableManager::EnableOtherEvent);
			static REL::Relocation<func_t> func{ ID::BSInputEnableManager::EnableOtherEvent };
			return func(this, a_layerID, a_otherEventFlags, a_enable, a_senderID);
		}

		void ForceUserEventEnabled(UserEvents::USER_EVENT_FLAG a_userEventFlags, bool a_enable)
		{
			BSAutoLock locker(cacheLock);
			if (a_enable) {
				forceEnableInputUserEventsFlags.set(a_userEventFlags);
			} else {
				forceEnableInputUserEventsFlags.reset(a_userEventFlags);
			}
		}

		void ForceOtherEventEnabled(OtherInputEvents::OTHER_EVENT_FLAG a_otherEventFlags, bool a_enable)
		{
			BSAutoLock locker(cacheLock);
			if (a_enable) {
				forceOtherInputEventsFlags.set(a_otherEventFlags);
			} else {
				forceOtherInputEventsFlags.reset(a_otherEventFlags);
			}
		}

		// members
		BSSpinLock                                                       cacheLock;                        // 110
		REX::TEnumSet<UserEvents::USER_EVENT_FLAG, std::uint32_t>        cachedInputUserEventsFlags;       // 118
		REX::TEnumSet<OtherInputEvents::OTHER_EVENT_FLAG, std::uint32_t> cachedOtherInputEventsFlags;      // 11C
		REX::TEnumSet<UserEvents::USER_EVENT_FLAG, std::uint32_t>        forceEnableInputUserEventsFlags;  // 120
		REX::TEnumSet<OtherInputEvents::OTHER_EVENT_FLAG, std::uint32_t> forceOtherInputEventsFlags;       // 124
		BSSpinLock                                                       layerLock;                        // 128
		BSTArray<EnableLayer>                                            layers;                           // 130
		BSTArray<BSTSmartPointer<BSInputEnableLayer>>                    layerWrappers;                    // 148
		BSTArray<BSFixedString>                                          debugNames;                       // 160
		bool                                                             isCurrentlyInSaveLoad;            // 178
	};
	static_assert(sizeof(BSInputEnableManager) == 0x180);
}
