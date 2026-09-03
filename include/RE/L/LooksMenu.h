#pragma once

#include "RE/G/GameMenuBase.h"
#include "RE/L/LooksInputRepeatHandler.h"

namespace RE
{
	class BSInputEnableLayer;
	class ChargenCharacterUpdateEvent;

	class __declspec(novtable) LooksMenu :
		public GameMenuBase,
		public BSTEventSink<ChargenCharacterUpdateEvent>
	{
	public:
		BSTSmartPointer<BSInputEnableLayer> inputLayer;                   // 0x0E8
		LooksInputRepeatHandler             inputRepeatHandler;           // 0x0F0
		void*                               bracketExtents;               // 0x138 - std::unique_ptr<BSGFxShaderFXTarget>
		std::byte                           facePickMask[0x150 - 0x140];  // 0x140
		std::uint32_t                       currentRegionID;              // 0x150
		std::uint32_t                       lastRegionID;                 // 0x154
																		  // ... and more
	};
}
