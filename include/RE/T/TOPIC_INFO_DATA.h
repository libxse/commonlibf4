#pragma once

namespace RE
{
	class TOPIC_INFO_DATA
	{
	public:
		enum class TOPIC_INFO_FLAGS : std::uint32_t
		{
			kNone = 0x0,
			kStartSceneOnEnd = 0x1,
			kRandom = 0x2,
			kSayOnce = 0x4,
			kRequirePlayerActivation = 0x8,
			kInfoRefusal = 0x10,
			kRandomEnd = 0x20,
			kEndRunningScene = 0x40,
			kIsForceGreet = 0x80,
			kPlaredAddress = 0x100,
			kGroupTracksData = 0x100,
			kForceSubtitle = 0x200,
			kGroupForceRandom = 0x200,
			kCanMoveWhileGreeitng = 0x400,
			kNoLIPFile = 0x800,
			kGroupDontDoAll = 0x800,
			kPostProcess = 0x1000,
			kCustomSoundOutpt = 0x2000,
			kDialogueInfoSaid = 0x4000,
			kHasCapsData = 0x4000,
			kAlreadySaidDoAllBeforeRepeating = 0x8000,
			kEditorOnly = 0x4000,
		};

		// members
		REX::TEnumSet<TOPIC_INFO_FLAGS, std::uint16_t> flags;           // 0
		std::uint16_t                                  timeUntilReset;  // 2
	};
	static_assert(sizeof(TOPIC_INFO_DATA) == 0x4);
}
