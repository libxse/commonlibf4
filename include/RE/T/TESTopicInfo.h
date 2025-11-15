#pragma once

#include "RE/R/ResponseListWrapper.h"
#include "RE/T/TESCondition.h"
#include "RE/T/TESForm.h"
#include "RE/T/TOPIC_INFO_DATA.h"

namespace RE
{
	class __declspec(novtable) TESTopicInfo :
		public TESForm  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::TESTopicInfo };
		static constexpr auto VTABLE{ VTABLE::TESTopicInfo };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kINFO };

		enum Flags
		{
			kInfoGroup = (1 << 6),
		};

		enum class CHARISMA_CHALLENGE_DIFFICULTY : std::uint32_t
		{
			kNone = 0,
			kEasy = 1,
			kMedium = 2,
			kHard = 3,
			kAlwaysSucceeds = 4,
			kEasyRepeatable = 5,
			kMediumRepeatable = 6,
			kHardRepeatable = 7,

			kTotal = 8,
		};

		enum class CHARISMA_CHALLENGE_SUCCESS : int32_t
		{
			kNone = -1,
			kFail = 0,
			kSucceed = 1,

			kTotal = 8
		};

		TESTopicInfo* GetParentInfoGroup()
		{
			using func_t = decltype(&TESTopicInfo::GetParentInfoGroup);
			static REL::Relocation<func_t> func{ ID::TESTopicInfo::GetParentInfoGroup };
			return func(this);
		}

		CHARISMA_CHALLENGE_DIFFICULTY GetChallengeLevel()
		{
			using func_t = decltype(&TESTopicInfo::GetChallengeLevel);
			static REL::Relocation<func_t> func{ ID::TESTopicInfo::GetChallengeLevel };
			return func(this);
		}

		CHARISMA_CHALLENGE_SUCCESS GetSuccessLevel()
		{
			using func_t = decltype(&TESTopicInfo::GetSuccessLevel);
			static REL::Relocation<func_t> func{ ID::TESTopicInfo::GetSuccessLevel };
			return func(this);
		}

		BGSScene* StartSceneOnEnd(BSPointerHandle<TESObjectREFR, BSUntypedPointerHandle<21, 5>> a_ref)
		{
			using func_t = decltype(&TESTopicInfo::StartSceneOnEnd);
			static REL::Relocation<func_t> func{ ID::TESTopicInfo::StartSceneOnEnd };
			return func(this, a_ref);
		}

		BGSScene* GetScene()
		{
			using func_t = decltype(&TESTopicInfo::GetScene);
			static REL::Relocation<func_t> func{ ID::TESTopicInfo::GetScene };
			return func(this);
		}

		void StartScene(TESObjectREFR* a_ref)
		{
			using func_t = decltype(&TESTopicInfo::StartScene);
			static REL::Relocation<func_t> func{ ID::TESTopicInfo::StartScene };
			return func(this, a_ref);
		}

		TESActorBase* GetSpeaker()
		{
			using func_t = decltype(&TESTopicInfo::GetSpeaker);
			static REL::Relocation<func_t> func{ ID::TESTopicInfo::GetSpeaker };
			return func(this);
		}

		[[nodiscard]] bool IsRandom() const noexcept { return data.flags.all(TOPIC_INFO_DATA::TOPIC_INFO_FLAGS::kRandom); }
		[[nodiscard]] bool IsRandomEnd() const noexcept { return data.flags.all(TOPIC_INFO_DATA::TOPIC_INFO_FLAGS::kRandomEnd); }
		[[nodiscard]] bool IsSayOnce() const noexcept { return data.flags.all(TOPIC_INFO_DATA::TOPIC_INFO_FLAGS::kSayOnce); }
		[[nodiscard]] bool IsStartSceneOnEnd() const noexcept { return data.flags.all(TOPIC_INFO_DATA::TOPIC_INFO_FLAGS::kStartSceneOnEnd); }

		// members
		TESTopic*           parentTopic;       // 20
		TESGlobal*          resetGlobal;       // 28
		TESTopicInfo*       dataInfo;          // 30
		TESCondition        objConditions;     // 38
		std::uint16_t       infoIndex;         // 40
		std::int8_t         subtitlePriority;  // 42
		bool                saidOnce;          // 43
		TOPIC_INFO_DATA     data;              // 44
		ResponseListWrapper responses;         // 48
	};
	static_assert(sizeof(TESTopicInfo) == 0x50);
}
