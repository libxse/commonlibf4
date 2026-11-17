#pragma once

#include "RE/B/BSTArray.h"
#include "RE/B/BSTSmallIndexScatterTable.h"
#include "RE/P/PersistentPassList.h"

namespace RE
{
	class BSRenderPass;

	class BSBatchRenderer
	{
	public:
		static constexpr auto RTTI{ RTTI::BSBatchRenderer };
		static constexpr auto VTABLE{ VTABLE::BSBatchRenderer };

		enum class GEOMETRY_GROUP_ENUM : std::uint32_t
		{
			kNone = static_cast<std::underlying_type_t<GEOMETRY_GROUP_ENUM>>(-1),

			kLODLand = 0x0,
			kLODObjects = 0x1,
			kMultiIndexDecal = 0x2,
			kOpaqueDecal = 0x3,
			kBlendedDecal = 0x4,
			kRefrActive = 0x5,
			k1stPersonNonRefractive = 0x6,
			kFading = 0x7,
			kNoShadow = 0x8,
			kLowAniso = 0x9,
			kUnderwaterFog = 0xA,
			kSSLR = 0xB,
			kZOnly = 0xC,
			kPostZOnly = 0xD,
			kSkyClouds = 0xE,
			kSmoothAlphaTest = 0xF,
			kVATSMaskDepthOnly = 0x10,
			kVATSMask = 0x11,
			kSunGlare = 0x12,
			kBloodSpatter = 0x13,
			kZPrepass = 0x14,
			kWaterStencil = 0x15,
			kWaterDepth = 0x16,

			kTotal = 0x17
		};

		class CommandBufferPassesMapAccess;
		class RenderPassMapAccess;

		class CommandBufferPassesData
		{
		public:
			// members
			std::byte*               buffer[1u << 13];  // 00000
			std::byte**              currentBuffer;     // 10000
			CommandBufferPassesData* next;              // 10008
			std::uint32_t            frame;             // 10010
			std::uint32_t            ownerIndex;        // 10014
		};
		static_assert(sizeof(CommandBufferPassesData) == 0x10018);

		class CommandBufferPassesDataEntry
		{
		public:
			// members
			CommandBufferPassesData* data;          // 00
			std::uint64_t            groupAndPass;  // 08
		};
		static_assert(sizeof(CommandBufferPassesDataEntry) == 0x10);

		class GeometryGroup
		{
		public:
			// members
			BSBatchRenderer*   batchRenderer;  // 00
			PersistentPassList passList;       // 08
			float              depth;          // 18
			std::uint32_t      count;          // 1C
			std::uint8_t       flags;          // 20
			std::int8_t        group;          // 21
		};
		static_assert(sizeof(GeometryGroup) == 0x28);

		class PassGroup
		{
		public:
			// members
			BSRenderPass* passHead;             // 00
			std::uint32_t passEnum;             // 08
			std::uint16_t nextPassGroup;        // 0C
			std::uint16_t commandBufferPasses;  // 0E
		};
		static_assert(sizeof(PassGroup) == 0x10);

		virtual ~BSBatchRenderer();  // 00

		void RenderBatches(std::uint32_t a_shaderType, bool a_alphaTest, GEOMETRY_GROUP_ENUM a_group)
		{
			using func_t = decltype(&BSBatchRenderer::RenderBatches);
			static REL::Relocation<func_t> func{ ID::BSBatchRenderer::RenderBatches };
			return func(this, a_shaderType, a_alphaTest, a_group);
		}

		[[nodiscard]] static bool RenderPassImmediately(BSRenderPass* a_pass, std::uint32_t a_technique, bool a_alphaTest)
		{
			using func_t = decltype(&BSBatchRenderer::RenderPassImmediately);
			static REL::Relocation<func_t> func{ ID::BSBatchRenderer::RenderPassImmediately };
			return func(a_pass, a_technique, a_alphaTest);
		}

		void RenderPassImpl(BSRenderPass* a_passHead, std::uint32_t a_technique, bool a_alphaTest)
		{
			using func_t = decltype(&BSBatchRenderer::RenderPassImpl);
			static REL::Relocation<func_t> func{ ID::BSBatchRenderer::RenderPassImpl };
			return func(this, a_passHead, a_technique, a_alphaTest);
		}

		BSTArray<PassGroup>                                                                             renderPasses[13];                                                 // 008
		BSTSmallIndexScatterTable<BSTArray<PassGroup>, RenderPassMapAccess>                             renderPassMap[13];                                                // 140
		std::uint32_t                                                                                   activePassIndexLists[13][2];                                      // 2E0
		std::uint32_t                                                                                   currentFirstPass;                                                 // 348
		std::uint32_t                                                                                   currentLastPass;                                                  // 34C
		bool                                                                                            autoClearPasses;                                                  // 350
		GeometryGroup*                                                                                  geometryGroups[std::to_underlying(GEOMETRY_GROUP_ENUM::kTotal)];  // 358
		GeometryGroup*                                                                                  alphaGroup;                                                       // 410
		std::uint32_t                                                                                   groupingAlphasGroupCount;                                         // 418
		GeometryGroup*                                                                                  groupingAlphasGroup;                                              // 420
		BSTArray<CommandBufferPassesDataEntry>                                                          commandBufferPasses;                                              // 428
		BSTSmallIndexScatterTable<BSTArray<CommandBufferPassesDataEntry>, CommandBufferPassesMapAccess> commandBufferPassMap;                                             // 440
		CommandBufferPassesData*                                                                        bufferPassesCurr;                                                 // 460
		CommandBufferPassesData*                                                                        bufferPassesHead;                                                 // 468
		CommandBufferPassesData**                                                                       bufferPassesTail;                                                 // 470
		std::uint32_t                                                                                   bufferPassesCurrAllocFrame;                                       // 478
	};
	static_assert(sizeof(BSBatchRenderer) == 0x480);
}
