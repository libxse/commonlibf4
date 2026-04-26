#pragma once

#include "RE/N/NiBillboardNode.h"
#include "RE/S/SkyObject.h"

namespace RE
{
	class __declspec(novtable) alignas(0x08) Moon :
		public SkyObject  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::Moon };
		static constexpr auto VTABLE{ VTABLE::Moon };

		virtual ~Moon();

		enum class Phase
		{
			kFull = 0x0,
			k3QWan = 0x1,
			kHalfWan = 0x2,
			k1QWan = 0x3,
			kNew = 0x4,
			k1QWax = 0x5,
			kHalfWax = 0x6,
			k3QWax = 0x7
		};

		enum class UpdateStatus
		{
			kNotRequired = 0x0,
			kWhenCulled = 0x1,
			kInitialize = 0x2
		};

		// members
		NiPointer<NiBillboardNode> moonBaseNode;          // 10
		NiPointer<NiNode>          moonNode;              // 18
		NiPointer<NiNode>          shadowNode;            // 20
		NiPointer<BSTriShape>      moonMesh;              // 28
		NiPointer<BSTriShape>      shadowMesh;            // 30
		BSString                   textures[8];           // 38
		float                      angleFadeStart;        // B8
		float                      angleFadeEnd;          // BC
		float                      angleShadowEarlyFade;  // C0
		float                      speed;                 // C4
		float                      zOffset;               // C8
		std::uint32_t              size;                  // CC
		UpdateStatus               updateMoonTexture;     // D0
	};
}
