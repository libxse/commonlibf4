#pragma once

#include "RE/B/BGSTypedFormValuePair.h"
#include "RE/B/BSTHashMap.h"
#include "RE/B/BSTTuple.h"
#include "RE/G/GameMenuBase.h"
#include "RE/S/Setting.h"

namespace RE
{
	class ExamineMenu;

	class __declspec(novtable) ExamineConfirmMenu :
		public GameMenuBase  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::ExamineConfirmMenu };
		static constexpr auto VTABLE{ VTABLE::ExamineConfirmMenu };
		static constexpr auto MENU_NAME{ "ExamineConfirmMenu"sv };

		enum class CONFIRM_TYPE
		{
			kSimple = 0,
			kBuild = 1,
			kScrap = 2,
			kRepairFailure = 3
		};

		class __declspec(novtable) ICallback
		{
		public:
			static constexpr auto RTTI{ RTTI::ExamineConfirmMenu__ICallback };
			static constexpr auto VTABLE{ VTABLE::ExamineConfirmMenu__ICallback };

			ICallback(ExamineMenu* a_thisMenu) :
				thisMenu(a_thisMenu)
			{
				REX::EMPLACE_VTABLE(this);
			}

			virtual ~ICallback() = default;  // 00

			// add
			virtual void OnAccept();  // 01

			F4_HEAP_REDEFINE_NEW(ICallback);

			// members
			ExamineMenu* thisMenu;  // 08
		};
		static_assert(sizeof(ICallback) == 0x10);

		class __declspec(novtable) InitData
		{
		public:
			static constexpr auto RTTI{ RTTI::ExamineConfirmMenu__InitData };
			static constexpr auto VTABLE{ VTABLE::ExamineConfirmMenu__InitData };

			InitData(BSFixedString a_confirmQuestion, BSFixedStringCS a_buttonLabel, CONFIRM_TYPE a_confirmType) :
				confirmQuestion(a_confirmQuestion),
				buttonLabel(a_buttonLabel),
				confirmType(a_confirmType)
			{
				REX::EMPLACE_VTABLE(this);
			}

			virtual ~InitData() = default;  // 00

			F4_HEAP_REDEFINE_NEW(InitData);

			// members
			BSFixedString                             confirmQuestion;                       // 08
			BSFixedStringCS                           buttonLabel;                           // 10
			REX::TEnumSet<CONFIRM_TYPE, std::int32_t> confirmType{ CONFIRM_TYPE::kSimple };  // 18
			bool                                      hasCancelButton{ true };               // 1C
		};
		static_assert(sizeof(InitData) == 0x20);

		class __declspec(novtable) InitDataScrap :
			public InitData  // 00
		{
		public:
			static constexpr auto RTTI{ RTTI::ExamineConfirmMenu__InitDataScrap };
			static constexpr auto VTABLE{ VTABLE::ExamineConfirmMenu__InitDataScrap };

			InitDataScrap(const char* a_confirmQuestion, const char* a_buttonLabel, const char* a_scrapSourceName, BSTArray<BSTTuple<TESBoundObject*, std::uint32_t>> a_scrapResults) :
				InitData(a_confirmQuestion, a_buttonLabel, CONFIRM_TYPE::kScrap),
				scrapSourceName(a_scrapSourceName),
				scrapResults(a_scrapResults)
			{
				REX::EMPLACE_VTABLE(this);
			}

			virtual ~InitDataScrap() = default;  // 00

			F4_HEAP_REDEFINE_NEW(InitDataScrap);

			// members
			BSFixedStringCS                                    scrapSourceName;  // 20
			BSTArray<BSTTuple<TESBoundObject*, std::uint32_t>> scrapResults;     // 28
		};
		static_assert(sizeof(InitDataScrap) == 0x40);

		class __declspec(novtable) InitDataRepairFailure :
			public InitData  // 00
		{
		public:
			static constexpr auto RTTI{ RTTI::ExamineConfirmMenu__InitDataRepairFailure };
			static constexpr auto VTABLE{ VTABLE::ExamineConfirmMenu__InitDataRepairFailure };

			InitDataRepairFailure(const BSTArray<BSTTuple<TESForm*, BGSTypedFormValuePair::SharedVal>>* a_requiredItems) :
				InitData(GameSettingCollection::GetSingleton()->GetSetting("sCannotRepairMessage")->GetString(), "$OK", CONFIRM_TYPE::kRepairFailure),
				requiredItems(a_requiredItems)
			{
				this->hasCancelButton = false;
				REX::EMPLACE_VTABLE(this);
			}

			virtual ~InitDataRepairFailure() = default;  // 00

			F4_HEAP_REDEFINE_NEW(InitDataRepairFailure);

			// members
			const BSTArray<BSTTuple<TESForm*, BGSTypedFormValuePair::SharedVal>>* requiredItems;        // 20
			BSTHashMap<TESBoundObject*, std::uint32_t>                            availableComponents;  // 28
		};
		static_assert(sizeof(InitDataRepairFailure) == 0x58);

		// members
		Scaleform::GFx::Value confirmObj;  // E0
	};
	static_assert(sizeof(ExamineConfirmMenu) == 0x100);
}
