#pragma once

#include "RE/B/BSLight.h"
#include "RE/B/BSSpinLock.h"
#include "RE/B/BSTArray.h"
#include "RE/N/NiNode.h"
#include "RE/N/NiPointer.h"

namespace RE
{
	class BSShadowDirectionalLight;

	class __declspec(novtable) ShadowSceneNode :
	    public NiNode  // 000
	{
	public:
		static constexpr auto RTTI{ RTTI::ShadowSceneNode };
		static constexpr auto VTABLE{ VTABLE::ShadowSceneNode };
		static constexpr auto Ni_RTTI{ Ni_RTTI::ShadowSceneNode };

		struct LIGHT_CREATE_PARAMS;

		BSLight* AddLight(NiLight* a_light, LIGHT_CREATE_PARAMS& a_params)
		{
			using func_t = BSLight* (*)(ShadowSceneNode*, NiLight*, LIGHT_CREATE_PARAMS&);
			static REL::Relocation<func_t> func{ ID::ShadowSceneNode::AddLight };
			return func(this, a_light, a_params);
		}

		BSLight* AddLight(NiLight* a_light, bool a_flag)
		{
			using func_t = BSLight* (*)(ShadowSceneNode*, NiLight*, bool);
			static REL::Relocation<func_t> func{ ID::ShadowSceneNode::AddLightWithBool };
			return func(this, a_light, a_flag);
		}

		void RemoveLight(NiPointer<BSLight>& a_light)
		{
			using func_t = decltype(&ShadowSceneNode::RemoveLight);
			static REL::Relocation<func_t> func{ ID::ShadowSceneNode::RemoveLight };
			func(this, a_light);
		}

		// members
		std::byte                    pad140[0x18];            // 140
		BSTArray<NiPointer<BSLight>> nonShadowLights;         // 158
		BSTArray<NiPointer<BSLight>> shadowLights;            // 170
		std::byte                    pad188[0x48];            // 188
		BSSpinLock                   lightLock;               // 1D0
		std::byte                    pad1D8[0x20];            // 1D8
		BSLight*                     sunLight;                // 1F8
		BSLight*                     cloudSunLight;           // 200
		BSShadowDirectionalLight*    directionalShadowLight;  // 208
		BSLight*                     localSunLight;           // 210
		std::byte                    pad218[0x118];           // 218
	};
	static_assert(sizeof(ShadowSceneNode) == 0x330);
}
