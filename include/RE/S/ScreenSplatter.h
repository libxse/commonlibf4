#pragma once

namespace RE
{
	class NiCamera;

	namespace ScreenSplatter
	{
		enum class SCREENSPLATTER_TEXTURES : std::uint32_t
		{
			kColor = 0x0,
			kAlpha = 0x1,
			kFlare = 0x2,
		};

		inline void Clear()
		{
			using func_t = decltype(&ScreenSplatter::Clear);
			static REL::Relocation<func_t> func{ ID::ScreenSplatter::Clear };
			return func();
		}

		inline void Update()
		{
			using func_t = decltype(&ScreenSplatter::Update);
			static REL::Relocation<func_t> func{ ID::ScreenSplatter::Update };
			return func();
		}
	}
}
