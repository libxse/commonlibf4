#pragma once

#include "RE/B/BSLight.h"
#include "RE/B/BSTArray.h"
#include "RE/N/NiFrustumPlanes.h"

namespace RE
{
	class BSCullingProcess;
	class BSShaderAccumulator;
	class NiCamera;

	class __declspec(novtable) BSShadowLight :
	    public BSLight  // 000
	{
	public:
		static constexpr auto RTTI{ RTTI::BSShadowLight };
		static constexpr auto VTABLE{ VTABLE::BSShadowLight };

		class ShadowMapData
		{
		public:
			// members
			float                          worldToShadow[4][4];  // 00
			NiCamera*                      camera;               // 40
			NiPointer<BSShaderAccumulator> accumulator;          // 48
			std::uint32_t                  depthStencilTarget;   // 50
			std::uint32_t                  arraySlice;           // 54
			NiFrustumPlanes                clipPlanes;           // 58
			float                          worldUnitsPerTexel;   // C8
			std::byte                      padCC[0x4];           // CC
			std::int32_t                   viewport[4];          // D0
			BSCullingProcess*              cullingProcess;       // E0
			std::byte                      padE8[0x8];           // E8
		};
		static_assert(sizeof(ShadowMapData) == 0xF0);

		// members
		std::uint32_t                   shadowMapCount;   // 190
		std::byte                       pad194[0x4];      // 194
		BSTArray<ShadowMapData>         shadowMapData;    // 198
		std::byte                       pad1B0[0x8];      // 1B0
		BSTArray<NiPointer<NiAVObject>> shadowCasters;    // 1B8
		float                           shadowDepthBias;  // 1D0
		std::byte                       pad1D4[0x2C];     // 1D4
	};
	static_assert(sizeof(BSShadowLight) == 0x200);
}
