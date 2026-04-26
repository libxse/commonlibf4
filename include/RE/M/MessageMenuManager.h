#pragma once

#include "RE/B/BSSpinLock.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTSingleton.h"
#include "RE/M/MessageBoxData.h"

namespace RE
{
	class MessageMenuManager :
		public BSTSingletonSDM<MessageMenuManager>  // 00
	{
	public:
		[[nodiscard]] static MessageMenuManager* GetSingleton()
		{
			static REL::Relocation<MessageMenuManager**> singleton{ ID::MessageMenuManager::Singleton };
			return *singleton;
		}

		void Create(
			const char*          a_headerText,
			const char*          a_bodyText,
			IMessageBoxCallback* a_callback,
			WARNING_TYPES        a_warningContext,
			const char*          a_button1Text = nullptr,
			const char*          a_button2Text = nullptr,
			const char*          a_button3Text = nullptr,
			const char*          a_button4Text = nullptr,
			bool                 a_ensureUnique = false)
		{
			using func_t = decltype(&MessageMenuManager::Create);
			static REL::Relocation<func_t> func{ ID::MessageMenuManager::Create };
			return func(this, a_headerText, a_bodyText, a_callback, a_warningContext, a_button1Text, a_button2Text, a_button3Text, a_button4Text, a_ensureUnique);
		}

		// members
		BSReadWriteLock                             messageRWLock;          // 04
		BSTArray<MessageBoxData*>                   messages;               // 10
		REX::TEnumSet<WARNING_TYPES, std::uint32_t> currentWarningContext;  // 28
		bool                                        disabledWarnings[34];   // 2C
	};
	static_assert(sizeof(MessageMenuManager) == 0x50);
}
