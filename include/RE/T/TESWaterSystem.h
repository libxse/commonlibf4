#pragma once

#include "RE/B/BSSpinLock.h"
#include "RE/B/BSTArray.h"
#include "RE/N/NiPointer.h"

namespace RE
{
	class BSCullingProcess;
	class BSMultiBoundAABB;
	class BSMultiBoundNode;
	class NiAVObject;
	class NiNode;
	class TESWaterForm;
	class TESWorldSpace;

	class TESWaterSystem
	{
	public:
		[[nodiscard]] static TESWaterSystem* GetSingleton()
		{
			static REL::Relocation<TESWaterSystem**> singleton{ ID::TESWaterSystem::Singleton };
			return *singleton;
		}

		bool AddWater(NiAVObject* a_geometry, TESWaterForm* a_form, float a_height, BSTArray<NiPointer<BSMultiBoundAABB>>* a_bounds, bool a_forceNonHorizontal, bool a_addRipples)
		{
			using func_t = decltype(&TESWaterSystem::AddWater);
			static REL::Relocation<func_t> func{ ID::TESWaterSystem::AddWater };
			return func(this, a_geometry, a_form, a_height, a_bounds, a_forceNonHorizontal, a_addRipples);
		}

		bool RemoveWater(NiAVObject* a_geometry)
		{
			using func_t = decltype(&TESWaterSystem::RemoveWater);
			static REL::Relocation<func_t> func{ ID::TESWaterSystem::RemoveWater };
			return func(this, a_geometry);
		}

		void AddLODWater(NiAVObject* a_geometry, TESWorldSpace* a_world, NiNode* a_root, BSMultiBoundNode* a_parent, bool a_useWorldHeight)
		{
			using func_t = decltype(&TESWaterSystem::AddLODWater);
			static REL::Relocation<func_t> func{ ID::TESWaterSystem::AddLODWater };
			return func(this, a_geometry, a_world, a_root, a_parent, a_useWorldHeight);
		}

		void RemoveLODWater(NiAVObject* a_geometry, NiNode* a_root, BSMultiBoundNode* a_parent)
		{
			using func_t = decltype(&TESWaterSystem::RemoveLODWater);
			static REL::Relocation<func_t> func{ ID::TESWaterSystem::RemoveLODWater };
			return func(this, a_geometry, a_root, a_parent);
		}

		void UpdateWaterSystem(BSCullingProcess* a_process)
		{
			using func_t = decltype(&TESWaterSystem::UpdateWaterSystem);
			static REL::Relocation<func_t> func{ ID::TESWaterSystem::UpdateWaterSystem };
			return func(this, a_process);
		}

		// members
		std::byte         pad00[0x88];  // 000
		NiPointer<NiNode> waterRoot;    // 088
		std::byte         pad90[0x88];  // 090
		BSSpinLock        lock;         // 118
		std::byte         pad120[0x8];  // 120
	};
	static_assert(offsetof(TESWaterSystem, waterRoot) == 0x88);
	static_assert(offsetof(TESWaterSystem, lock) == 0x118);
}
