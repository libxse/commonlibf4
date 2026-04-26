#pragma once

namespace RE
{
	enum class LOCK_LEVEL;

	class REFR_LOCK
	{
	public:
		[[nodiscard]] LOCK_LEVEL GetLockLevel(TESObjectREFR* a_owner)
		{
			using func_t = decltype(&REFR_LOCK::GetLockLevel);
			static REL::Relocation<func_t> func{ ID::REFR_LOCK::GetLockLevel };
			return func(this, a_owner);
		}

		void SetLocked(bool a_locked)
		{
			using func_t = decltype(&REFR_LOCK::SetLocked);
			static REL::Relocation<func_t> func{ ID::REFR_LOCK::SetLocked };
			return func(this, a_locked);
		}

		bool IsBroken()
		{
			using func_t = decltype(&REFR_LOCK::IsBroken);
			static REL::Relocation<func_t> func{ ID::REFR_LOCK::IsBroken };
			return func(this);
		}

		[[nodiscard]] static LOCK_LEVEL NumericValueToEnum(std::int32_t a_value)
		{
			using func_t = decltype(&REFR_LOCK::NumericValueToEnum);
			static REL::Relocation<func_t> func{ ID::REFR_LOCK::NumericValueToEnum };
			return func(a_value);
		}

		// members
		std::uint8_t  baseLevel;  // 00
		TESKey*       key;        // 08
		std::uint8_t  flags;      // 10
		std::uint32_t numTries;   // 14
	};
	static_assert(sizeof(REFR_LOCK) == 0x18);
}
