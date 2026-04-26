#pragma once

#include "RE/B/BSBatchRenderer.h"
#include "RE/B/BSEventFlag.h"
#include "RE/B/BSTArray.h"

namespace RE
{
	class BSGeometry;
	class BSRenderPass;

	namespace BSMTAManager
	{
		enum class MODE
		{
			kIdle = 0x0,
			kCollecting = 0x1,
			kExecuting = 0x2,
		};

		class CalculateBoneMatricesTask
		{
		public:
			// members
			BSGeometry* geometry;  // 0
		};
		static_assert(sizeof(CalculateBoneMatricesTask) == 0x8);

		class RegisterBatchRendererPassTask
		{
		public:
			// members
			BSBatchRenderer* batchRenderer;  // 00
			BSRenderPass*    renderPass;     // 08
		};
		static_assert(sizeof(RegisterBatchRendererPassTask) == 0x10);

		class RegisterGeometryGroupPassTask
		{
		public:
			// members
			BSBatchRenderer*                                                   batchRenderer;  // 00
			BSRenderPass*                                                      renderPass;     // 08
			BSBatchRenderer::GeometryGroup*                                    geometryGroup;  // 10
			REX::TEnumSet<BSBatchRenderer::GEOMETRY_GROUP_ENUM, std::uint32_t> group;          // 18
			bool                                                               addToFront;     // 1C
		};
		static_assert(sizeof(RegisterGeometryGroupPassTask) == 0x20);

		class JobData
		{
		public:
			// members
			BSTArray<RegisterBatchRendererPassTask> registerBatchRendererPasses;  // 00
			BSTArray<RegisterGeometryGroupPassTask> registerGeometryGroupPasses;  // 18
			BSEventFlag                             finishedEvent;                // 30
		};
		static_assert(sizeof(JobData) == 0x38);

		class RegisterObjectTask
		{
		public:
			// members
			BSGeometry*                     geometry;                        // 00
			std::int32_t                    groupingAlphas;                  // 08
			BSBatchRenderer::GeometryGroup* currentAlphaGroup;               // 10
			bool                            alphaGroupZPrePass;              // 18
			JobData*                        owner;                           // 20
			std::uint32_t                   registerBatchRendererPassIndex;  // 28
			std::uint32_t                   registerBatchRendererPassCount;  // 2C
			std::uint32_t                   registerGeometryGroupPassIndex;  // 30
			std::uint32_t                   registerGeometryGroupPassCount;  // 34
		};
		static_assert(sizeof(RegisterObjectTask) == 0x38);
	}
}
