#pragma once

#include "RE/B/BSStringT.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTSmartPointer.h"
#include "RE/I/IUIMessageData.h"

namespace RE
{
	enum class UI_DEPTH_PRIORITY;
	enum class WARNING_TYPES;
	class IMessageBoxCallback;

	class __declspec(novtable) MessageBoxData :
		public IUIMessageData  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::MessageBoxData };
		static constexpr auto VTABLE{ VTABLE::MessageBoxData };

		// members
		BSString                                        headerText;      // 18
		BSString                                        bodyText;        // 28
		BSTArray<BSString>                              buttonText;      // 38
		REX::TEnumSet<WARNING_TYPES, std::uint32_t>     warningContext;  // 50
		BSTSmartPointer<IMessageBoxCallback>            callback;        // 58
		REX::TEnumSet<UI_DEPTH_PRIORITY, std::uint32_t> menuDepth;       // 60
		bool                                            modal;           // 64
		bool                                            ensureUnique;    // 65
	};
	static_assert(sizeof(MessageBoxData) == 0x68);
}
