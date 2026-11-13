#pragma once

#include "RE/B/BIPED_OBJECT.h"
#include "RE/B/BIPOBJECT.h"
#include "RE/B/BSIntrusiveRefCounted.h"
#include "RE/B/BSPointerHandle.h"

namespace RE
{
	class NiNode;

	class BipedAnim :
		public BSIntrusiveRefCounted  // 0000
	{
	public:
		const BIPOBJECT* GetBipObject(const BIPED_OBJECT a_bipedObject) const
		{
			return std::addressof(object[std::to_underlying(a_bipedObject)]);
		}

		BIPOBJECT* GetBipObject(const BIPED_OBJECT a_bipedObject)
		{
			return std::addressof(object[std::to_underlying(a_bipedObject)]);
		}

		ObjectRefHandle GetRequester() const
		{
			return actorRef;
		}

		NiNode* GetRoot() const
		{
			return root;
		}

		NiNode* AttachSkinnedObject(NiNode* a_objectRoot, NiNode* a_parent, std::uint32_t a_bipedIndex, bool a_bFirstPerson) noexcept
		{
			using func_t = decltype(&BipedAnim::AttachSkinnedObject);
			static REL::Relocation<func_t> func{ ID::BipedAnim::AttachSkinnedObject };
			return func(this, a_objectRoot, a_parent, a_bipedIndex, a_bFirstPerson);
		}

		// members
		NiNode*         root;                                                       // 0008
		BIPOBJECT       object[std::to_underlying(BIPED_OBJECT::kTotal)];           // 0010
		BIPOBJECT       bufferedObjects[std::to_underlying(BIPED_OBJECT::kTotal)];  // 0F30
		ObjectRefHandle actorRef;                                                   // 1E50
	};
	static_assert(sizeof(BipedAnim) == 0x1E58);
}
