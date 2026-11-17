#pragma once

#include "RE/N/NiPoint3.h"
#include "RE/N/NiPointer.h"

namespace RE
{
	class BSCullingProcess;
	class BSParticleShaderCubeEmitter;
	class BSShaderAccumulator;
	class NiCamera;

	class __declspec(novtable) Precipitation
	{
	public:
		static constexpr auto RTTI{ RTTI::Precipitation };
		static constexpr auto VTABLE{ VTABLE::Precipitation };

		struct OcclusionMapData
		{
			// members
			std::byte                      pad00[0x40];     // 00
			NiPointer<NiCamera>            camera;          // 40
			NiPointer<BSShaderAccumulator> accumulator;     // 48
			std::byte                      pad50[0x8];      // 50
			BSCullingProcess*              cullingProcess;  // 58
		};
		static_assert(offsetof(OcclusionMapData, camera) == 0x40);
		static_assert(offsetof(OcclusionMapData, accumulator) == 0x48);
		static_assert(offsetof(OcclusionMapData, cullingProcess) == 0x58);
		static_assert(sizeof(OcclusionMapData) == 0x60);

		using OcclusionMatrix = float[4][4];

		virtual ~Precipitation();  // 00

		static void RenderOcclusionMap()
		{
			using func_t = decltype(&Precipitation::RenderOcclusionMap);
			static REL::Relocation<func_t> func{ ID::Precipitation::RenderOcclusionMap };
			return func();
		}

		void RenderOcclusionMapImpl(BSParticleShaderCubeEmitter* a_emitter)
		{
			using func_t = decltype(&Precipitation::RenderOcclusionMapImpl);
			static REL::Relocation<func_t> func{ ID::Precipitation::RenderOcclusionMapImpl };
			return func(this, a_emitter);
		}

		void ComputeProjection(NiPointer<NiCamera> a_camera)
		{
			using func_t = decltype(&Precipitation::ComputeProjection);
			static REL::Relocation<func_t> func{ ID::Precipitation::ComputeProjection };
			return func(this, a_camera);
		}

		[[nodiscard]] static float& GetBoxSize()
		{
			static REL::Relocation<float*> data{ ID::Precipitation::BoxSize };
			return *data;
		}

		[[nodiscard]] static NiPoint3& GetDirection()
		{
			static REL::Relocation<NiPoint3*> data{ ID::Precipitation::Direction };
			return *data;
		}

		[[nodiscard]] static OcclusionMatrix& GetOcclusionMatrix()
		{
			static REL::Relocation<OcclusionMatrix*> data{ ID::Precipitation::OcclusionMatrix };
			return *data;
		}

		// members
		std::byte        pad08[0x8];     // 08
		OcclusionMapData occlusionData;  // 10
		std::byte        pad70[0x30];    // 70
	};
	static_assert(offsetof(Precipitation, occlusionData) == 0x10);
	static_assert(sizeof(Precipitation) == 0xA0);
}
