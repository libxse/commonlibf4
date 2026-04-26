#pragma once

#include "RE/E/EXTRA_DATA_TYPE.h"
#include "RE/M/MemoryManager.h"

namespace RE
{
	class __declspec(novtable) BSExtraData
	{
	public:
		static constexpr auto RTTI{ RTTI::BSExtraData };
		static constexpr auto VTABLE{ VTABLE::BSExtraData };
		static constexpr auto TYPE{ EXTRA_DATA_TYPE::kNone };

		BSExtraData() :
			BSExtraData(EXTRA_DATA_TYPE::kNone)
		{}

		BSExtraData(EXTRA_DATA_TYPE a_type) :
			type(a_type)
		{
			REX::EMPLACE_VTABLE(this);
		}

		virtual ~BSExtraData() = default;  // 00

		// add
		virtual bool CompareImpl([[maybe_unused]] const BSExtraData& a_compare) const { return false; }  // 01
		virtual bool CompareForUI(const BSExtraData* a_compare) const                                    // 02
		{
			if (a_compare && type == a_compare->type) {
				return CompareImpl(*a_compare);
			} else {
				return true;
			}
		}

		F4_HEAP_REDEFINE_NEW(BSExtraData);

		[[nodiscard]] EXTRA_DATA_TYPE GetExtraType() const noexcept { return *type; }

		// members
		BSExtraData*                                 next{ nullptr };                 // 08
		std::uint16_t                                flags{ 0 };                      // 10
		REX::TEnumSet<EXTRA_DATA_TYPE, std::uint8_t> type{ EXTRA_DATA_TYPE::kNone };  // 12
	};
	static_assert(sizeof(BSExtraData) == 0x18);
}
