#pragma once

#include "RE/N/NiColor.h"
#include "RE/N/NiPoint3.h"

namespace RE
{
	namespace BSDFTiledLighting
	{
		struct TiledLightRecord
		{
		public:
			// members
			std::uint32_t flags;         // 00
			NiPoint3      viewPosition;  // 04
			float         radius;        // 10
			NiColor       color;         // 14
			NiPoint3      radialABC;     // 20
			std::byte     pad2C[0x4];    // 2C
		};
		static_assert(sizeof(TiledLightRecord) == 0x30);

		inline constexpr std::size_t MAX_LIGHTS = 625;

		using LightCounts = std::uint32_t[2];
		using LightRecords = TiledLightRecord[2][MAX_LIGHTS];

		inline void AddLight(std::uint32_t a_typeSelector, const NiPoint3& a_viewPosition, float a_radius, const NiColor& a_color, const NiPoint3& a_radialABC, bool a_zeroRoughness, bool a_suppressRim, bool a_attenuationOnly, bool a_specular)
		{
			using func_t = decltype(&AddLight);
			static REL::Relocation<func_t> func{ ID::BSDFTiledLighting::AddLight };
			func(a_typeSelector, a_viewPosition, a_radius, a_color, a_radialABC, a_zeroRoughness, a_suppressRim, a_attenuationOnly, a_specular);
		}

		[[nodiscard]] inline std::uint32_t& GetWriteSide()
		{
			static REL::Relocation<std::uint32_t*> side{ ID::BSDFTiledLighting::WriteSide };
			return *side;
		}

		[[nodiscard]] inline LightCounts& GetLightCounts()
		{
			static REL::Relocation<LightCounts*> counts{ ID::BSDFTiledLighting::LightCounts };
			return *counts;
		}

		[[nodiscard]] inline LightRecords& GetLightRecords()
		{
			static REL::Relocation<LightRecords*> records{ ID::BSDFTiledLighting::LightRecords };
			return *records;
		}
	}
}
