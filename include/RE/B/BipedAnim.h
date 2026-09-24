#pragma once

#include "RE/B/BIPED_OBJECT.h"
#include "RE/B/BIPOBJECT.h"
#include "RE/B/BSFixedString.h"
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

		// Sets a whole number variable on the animation graph of the model in one
		// biped slot. False when the slot has no graph or the graph refuses it.
		// UseAmmo tells a gun's own graph how many rounds are left this way,
		// through iWeaponCharge on kWeaponGun.
		bool SetObjectGraphVariableInt(BIPED_OBJECT a_bipedObject, const BSFixedString& a_variable, std::int32_t a_value)
		{
			using func_t = decltype(&BipedAnim::SetObjectGraphVariableInt);
			static REL::Relocation<func_t> func{ ID::BipedAnim::SetObjectGraphVariableInt };
			return func(this, a_bipedObject, a_variable, a_value);
		}

		// members
		NiNode*         root;                                                       // 0008
		BIPOBJECT       object[std::to_underlying(BIPED_OBJECT::kTotal)];           // 0010
		BIPOBJECT       bufferedObjects[std::to_underlying(BIPED_OBJECT::kTotal)];  // 0F30
		ObjectRefHandle actorRef;                                                   // 1E50
	};
	static_assert(sizeof(BipedAnim) == 0x1E58);
}
