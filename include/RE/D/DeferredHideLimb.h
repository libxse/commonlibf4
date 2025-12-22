#pragma once

#include "RE/B/BGSBodyPartDefs.h"
#include "RE/N/NiPointer.h"

namespace RE
{
	class NiNode;

	class DeferredHideLimb
	{
	public:
		// members
		float                      dismemberTimer;       // 00
		BGSBodyPartDefs::LIMB_ENUM limbIndex;            // 04
		NiPointer<NiNode>          dismemberedLimbRoot;  // 08
		NiPointer<NiNode>          replacementLimb;      // 10
		DeferredHideLimb*          next;                 // 18
		bool                       explosion;            // 20
	};
	static_assert(sizeof(DeferredHideLimb) == 0x28);
}
