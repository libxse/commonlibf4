#pragma once

#include "RE/B/BSTArray.h"
#include "RE/N/NiNode.h"

namespace RE
{
	class BSTempEffect;

	class __declspec(novtable) BGSDecalNode :
		public NiNode  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSDecalNode };
		static constexpr auto VTABLE{ VTABLE::BGSDecalNode };
		static constexpr auto Ni_RTTI{ Ni_RTTI::BGSDecalNode };

		// members
		BSTArray<NiPointer<BSTempEffect>> decals;               // 140
		BSTArray<std::uint32_t>           decalCreationFrames;  // 158
		bool                              skinnedNode;          // 170
	};
	static_assert(sizeof(BGSDecalNode) == 0x180);
}
