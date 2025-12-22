#pragma once

#include "RE/B/BSBatchRenderer.h"
#include "RE/B/BSShaderManager.h"
#include "RE/N/NiAlphaAccumulator.h"
#include "RE/N/NiColor.h"
#include "RE/N/NiPoint.h"
#include "RE/N/NiPointer.h"
#include "RE/S/SunOcclusionTest.h"

namespace RE
{
	class BSLight;
	class ShadowSceneNode;

	class __declspec(novtable) BSShaderAccumulator :
		public NiAlphaAccumulator  // 000
	{
	public:
		static constexpr auto RTTI{ RTTI::BSShaderAccumulator };
		static constexpr auto VTABLE{ VTABLE::BSShaderAccumulator };
		static constexpr auto Ni_RTTI{ Ni_RTTI::BSShaderAccumulator };

		enum class WATER_SIDE : std::uint32_t
		{
			kAboveWater = 0x0,
			kBelowWater = 0x1
		};

		// add
		virtual void FinishAccumulatingPreResolveDepth();   // 2E
		virtual void FinishAccumulatingPostResolveDepth();  // 2F

		// members
		std::uint32_t                 sunPixelCount;             // 058
		bool                          waitingForSunQuery;        // 05C
		float                         percentSunOccludedStored;  // 060
		SunOcclusionTest              sunTests[3];               // 068
		bool                          firstPerson;               // 0B0
		bool                          zPrePass;                  // 0B1
		NiColorA                      silhouetteColor;           // 0B4
		bool                          renderDecals;              // 0C4
		BSBatchRenderer               batchRenderer;             // 0C8
		std::uint32_t                 currentPass;               // 548
		std::uint32_t                 currentBucket;             // 54C
		bool                          currentActiveA;            // 550
		ShadowSceneNode*              activeShadowSceneNode;     // 558
		BSShaderManager::etRenderMode renderMode;                // 560
		NiPointer<BSLight>            shadowLight;               // 568
		NiPoint3A                     eyePosition;               // 570
		std::uint32_t                 depthPassIndex;            // 580
	};
	static_assert(sizeof(BSShaderAccumulator) == 0x590);
}
