#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/D/DIALOGUE_DATA.h"
#include "RE/D/DialogueItem.h"
#include "RE/T/TESForm.h"
#include "RE/T/TESFullName.h"

namespace RE
{
	class __declspec(novtable) TESTopic :
		public TESForm,     // 00
		public TESFullName  // 20
	{
	public:
		static constexpr auto RTTI{ RTTI::TESTopic };
		static constexpr auto VTABLE{ VTABLE::TESTopic };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kDIAL };

		class InfoTree
		{
		public:
			class Node
			{
				// members
				std::uint16_t left;   // 00
				std::uint16_t right;  // 02
			};
			static_assert(sizeof(Node) == 0x4);

			// members
			Node roots;  // 00
		};
		static_assert(sizeof(InfoTree) == 0x4);

		bool InitDialogueItem(DialogueItem& a_outItem, TESObjectREFR* a_speaker, TESObjectREFR* a_target, TESTopicInfo* a_info, TESTopic* a_previousTopic, BSSimpleList<DialogueItem*>* a_conversationList = nullptr)
		{
			using func_t = decltype(&TESTopic::InitDialogueItem);
			static REL::Relocation<func_t> func{ ID::TESTopic::InitDialogueItem };
			return func(this, a_outItem, a_speaker, a_target, a_info, a_previousTopic, a_conversationList);
		}

		// members
		DIALOGUE_DATA      data;                     // 30
		std::uint32_t      priorityAndJournalIndex;  // 34
		BGSDialogueBranch* ownerBranch;              // 38
		TESQuest*          ownerQuest;               // 40
		BGSKeyword*        subtypeKeyword;           // 48
		TESTopicInfo**     topicInfos;               // 50
		InfoTree*          infoTree;                 // 58
		std::uint32_t      numTopicInfos;            // 60
		std::uint32_t      topicInfoAllocSize;       // 64
		std::uint32_t      firstFileOffset;          // 68
		BSFixedString      formEditorID;             // 70
	};
	static_assert(sizeof(TESTopic) == 0x78);
}
