#pragma once

namespace RE
{
	enum class DIALOGUE_SUBTYPE;

	class BGSTopicSubtypeUnion
	{
	public:
		enum class TOPIC_MODE;

		// members
		REX::TEnumSet<TOPIC_MODE, std::int32_t> mode;  // 0
		union
		{
			DIALOGUE_SUBTYPE generalTopicSubtype;
			std::uint32_t    specificTopicID;
		};  // 4
	};
	static_assert(sizeof(BGSTopicSubtypeUnion) == 0x8);
}
