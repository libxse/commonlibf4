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
			bool                 a_ensureUnique = false,
			std::int32_t         a_cancelButtonIndex = -1)
		{
			using func_t = decltype(&MessageMenuManager::Create);
			static REL::Relocation<func_t> func{ ID::MessageMenuManager::Create };
			return func(this, a_headerText, a_bodyText, a_callback, a_warningContext, a_button1Text, a_button2Text, a_button3Text, a_button4Text, a_ensureUnique, a_cancelButtonIndex);
		}

		// Queues a message box with one button for each label in a_buttonText,
		// with no limit on the count. The callback receives the index of the
		// pressed button. a_modal sets the box's kModal menu flag.
		// a_ensureUnique skips the box when the box shown just before it had
		// the same body text. a_cancelButtonIndex is the button the Cancel key
		// presses, or -1 for none.
		//
		// Create calls this with at most four labels and a_modal set. With its
		// own a_ensureUnique set, Create also skips the box when one with the
		// same body text is already waiting in the queue.
		void QueueMessage(
			const char*                   a_headerText,
			const char*                   a_bodyText,
			IMessageBoxCallback*          a_callback,
			WARNING_TYPES                 a_warningContext,
			const BSScrapArray<BSString>* a_buttonText,
			bool                          a_modal = true,
			bool                          a_ensureUnique = false,
			std::int32_t                  a_cancelButtonIndex = -1)
		{
			using func_t = decltype(&MessageMenuManager::QueueMessage);
			static REL::Relocation<func_t> func{ ID::MessageMenuManager::QueueMessage };
			return func(this, a_headerText, a_bodyText, a_callback, a_warningContext, a_buttonText, a_modal, a_ensureUnique, a_cancelButtonIndex);
		}

		// members
		BSReadWriteLock                             messageRWLock;          // 04
		BSTArray<MessageBoxData*>                   messages;               // 10
		REX::TEnumSet<WARNING_TYPES, std::uint32_t> currentWarningContext;  // 28
		bool                                        disabledWarnings[34];   // 2C
	};
	static_assert(sizeof(MessageMenuManager) == 0x50);
}
