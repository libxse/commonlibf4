#pragma once

#include "RE/D/DifficultyLevel.h"
#include "RE/L/LOCK_LEVEL.h"

namespace RE
{
	namespace GamePlayFormulas
	{
		enum class ExperienceActivity : std::int32_t
		{
			kKillNPC = 0x0,
			kHackComputer = 0x1,
		};

		inline bool CanHackGateCheck(LOCK_LEVEL a_lockLevel)
		{
			using func_t = decltype(&GamePlayFormulas::CanHackGateCheck);
			static REL::Relocation<func_t> func{ ID::GamePlayFormulas::CanHackGateCheck };
			return func(a_lockLevel);
		}

		inline bool CanPickLockGateCheck(LOCK_LEVEL a_lockLevel)
		{
			using func_t = decltype(&GamePlayFormulas::CanPickLockGateCheck);
			static REL::Relocation<func_t> func{ ID::GamePlayFormulas::CanPickLockGateCheck };
			return func(a_lockLevel);
		}

		inline float GetExperienceReward(ExperienceActivity a_activity, DifficultyLevel a_difficulty, float a_xpBase)
		{
			using func_t = decltype(&GamePlayFormulas::GetExperienceReward);
			static REL::Relocation<func_t> func{ ID::GamePlayFormulas::GetExperienceReward };
			return func(a_activity, a_difficulty, a_xpBase);
		}

		inline float GetLockXPReward(LOCK_LEVEL a_lockLevel)
		{
			using func_t = decltype(&GamePlayFormulas::GetLockXPReward);
			static REL::Relocation<func_t> func{ ID::GamePlayFormulas::GetLockXPReward };
			return func(a_lockLevel);
		}

		inline float CalculateItemHealthDamageBonus(float a_itemHealth)
		{
			using func_t = decltype(&GamePlayFormulas::CalculateItemHealthDamageBonus);
			static REL::Relocation<func_t> func{ ID::GamePlayFormulas::CalculateItemHealthDamageBonus };
			return func(a_itemHealth);
		}

		// Turns an item's base value into the price the player sees. While a
		// barter screen is open every price the game works out comes through
		// here with the trader's markup put on, from the player's Charisma.
		// a_health only counts when the fHealthDataValue6 game setting is above
		// 1.0, and Fallout4.esm does not define it.
		inline float CalculateItemValue(float a_baseValue, float a_health)
		{
			using func_t = decltype(&GamePlayFormulas::CalculateItemValue);
			static REL::Relocation<func_t> func{ ID::GamePlayFormulas::CalculateItemValue };
			return func(a_baseValue, a_health);
		}

		inline float CalcSprintingActionPoints(float a_equippedWeight, float a_elapsedTime, float a_endurance)
		{
			using func_t = decltype(&GamePlayFormulas::CalcSprintingActionPoints);
			static REL::Relocation<func_t> func{ ID::GamePlayFormulas::CalcSpringingActionPoints };
			return func(a_equippedWeight, a_elapsedTime, a_endurance);
		}

		inline float GetHackingWordCount(float a_playerIntelligence)
		{
			using func_t = decltype(&GamePlayFormulas::GetHackingWordCount);
			static REL::Relocation<func_t> func{ ID::GamePlayFormulas::GetHackingWordCount };
			return func(a_playerIntelligence);
		}

		inline float GetForceLockChance(float a_playerPerception, std::int32_t a_lockLevel)
		{
			using func_t = decltype(&GamePlayFormulas::GetForceLockChance);
			static REL::Relocation<func_t> func{ ID::GamePlayFormulas::GetForceLockChance };
			return func(a_playerPerception, a_lockLevel);
		}
	}
}
