#pragma once

#include "RE/N/NiColor.h"
#include "RE/N/NiPointer.h"
#include "RE/S/SkyObject.h"

namespace RE
{
	class BSGeometry;

	class __declspec(novtable) Clouds :
	    public SkyObject  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::Clouds };
		static constexpr auto VTABLE{ VTABLE::Clouds };

		static constexpr std::size_t kMaxLayers = 32;

		~Clouds() override;  // 00

		// members
		NiPointer<BSGeometry> clouds[kMaxLayers];  // 010
		std::byte             pad110[0x200];       // 110
		NiColor               colors[kMaxLayers];  // 310
		float                 alphas[kMaxLayers];  // 490
		std::uint16_t         numLayers;           // 510
	};
	static_assert(offsetof(Clouds, clouds) == 0x10);
	static_assert(offsetof(Clouds, colors) == 0x310);
	static_assert(offsetof(Clouds, alphas) == 0x490);
	static_assert(offsetof(Clouds, numLayers) == 0x510);
	static_assert(sizeof(Clouds) == 0x518);
}
