#pragma once

#include "RE/B/BGSModelMaterialSwap.h"
#include "RE/O/OBJ_TREE.h"
#include "RE/T/TESBoundObject.h"
#include "RE/T/TESFullName.h"
#include "RE/T/TESProduceForm.h"

namespace RE
{
	class BaseTreeData;

	class __declspec(novtable) TESObjectTREE :
		public TESBoundObject,        // 000
		public BGSModelMaterialSwap,  // 068
		public TESFullName,           // 0A8
		public TESProduceForm         // 0B8
	{
	public:
		static constexpr auto RTTI{ RTTI::TESObjectTREE };
		static constexpr auto VTABLE{ VTABLE::TESObjectTREE };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kTREE };

		enum class etTreeType
		{
			kShortAndThin = 0x0,
			kShortAndThick = 0x1,
			kTallAndThin = 0x2,
			kTallAndThick = 0x3,
			kTotal = 0x4
		};

		// members
		OBJ_TREE                                data;      // 0D8
		BaseTreeData*                           baseData;  // 108
		REX::TEnumSet<etTreeType, std::int32_t> type;      // 110
	};
	static_assert(sizeof(TESObjectTREE) == 0x118);
}
