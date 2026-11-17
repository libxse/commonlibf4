#pragma once

#include "RE/N/NiPointer.h"

namespace RE
{
	class BGSTerrainNode;
	class BSMultiBoundNode;
	class NiAVObject;
	class NiNode;

	class BGSTerrainChunk
	{
	public:
		void Attach()
		{
			using func_t = decltype(&BGSTerrainChunk::Attach);
			static REL::Relocation<func_t> func{ ID::BGSTerrainChunk::Attach };
			return func(this);
		}

		static void AttachWater(bool a_attach)
		{
			using func_t = decltype(&BGSTerrainChunk::AttachWater);
			static REL::Relocation<func_t> func{ ID::BGSTerrainChunk::AttachWater };
			return func(a_attach);
		}

		void Detach()
		{
			using func_t = decltype(&BGSTerrainChunk::Detach);
			static REL::Relocation<func_t> func{ ID::BGSTerrainChunk::Detach };
			return func(this);
		}

		void Prepare()
		{
			using func_t = decltype(&BGSTerrainChunk::Prepare);
			static REL::Relocation<func_t> func{ ID::BGSTerrainChunk::Prepare };
			return func(this);
		}

		// members
		BGSTerrainNode*             node;           // 00
		NiPointer<NiAVObject>       land;           // 08
		NiPointer<BSMultiBoundNode> water;          // 10
		NiPointer<NiNode>           chunk;          // 18
		bool                        loaded;         // 20
		bool                        attached;       // 21
		bool                        waterAttached;  // 22
		std::byte                   pad23[0x5];     // 23
	};
	static_assert(offsetof(BGSTerrainChunk, water) == 0x10);
	static_assert(offsetof(BGSTerrainChunk, chunk) == 0x18);
	static_assert(offsetof(BGSTerrainChunk, loaded) == 0x20);
	static_assert(offsetof(BGSTerrainChunk, attached) == 0x21);
	static_assert(offsetof(BGSTerrainChunk, waterAttached) == 0x22);
	static_assert(sizeof(BGSTerrainChunk) == 0x28);
}
