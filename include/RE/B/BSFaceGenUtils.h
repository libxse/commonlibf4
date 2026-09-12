#pragma once

#include "RE/B/BSIntrusiveRefCounted.h"
#include "RE/N/NiPointer.h"

namespace RE
{
	struct BSFaceGenPendingHeadData;

	namespace BSTextureArray
	{
		class StaticTextureIndexed;
	}

	namespace BSFaceGenUtils
	{
		class FaceGenData :
			public BSIntrusiveRefCounted
		{
		public:
			NiPointer<BSTextureArray::StaticTextureIndexed> textures[4];                     // 008
			std::byte                                       hairLookupTexture[0x30 - 0x28];  // 028 - BSResource::RHandleType
			std::uint32_t                                   layerCount;                      // 030
			std::uint32_t                                   lru[128];                        // 034
			std::uint32_t                                   stamp;                           // 234
		};
		static_assert(sizeof(FaceGenData) == 0x238);

		inline void StartFaceCustomizationGenerationForNPC(TESNPC* a_npc, const BSTArray<BGSCharacterTint::Entry*>& a_entries, FaceGenData* a_faceGenData, void* a_customizationBuffer, std::uint32_t a_uiLoadingPriority, bool a_bForceMaxLayers)
		{
			using func_t = decltype(&BSFaceGenUtils::StartFaceCustomizationGenerationForNPC);
			static REL::Relocation<func_t> func{ ID::BSFaceGenUtils::StartFaceCustomizationGenerationForNPC };
			func(a_npc, a_entries, a_faceGenData, a_customizationBuffer, a_uiLoadingPriority, a_bForceMaxLayers);
		}

		inline void PrepareHeadPartForShaders(BSFaceGenNiNode* a_node, BGSHeadPart* a_headPart, TESNPC* a_npc, BSFaceGenPendingHeadData* a_pendingHeadData)
		{
			using func_t = decltype(&BSFaceGenUtils::PrepareHeadPartForShaders);
			static REL::Relocation<func_t> func{ ID::BSFaceGenUtils::PrepareHeadPartForShaders };
			func(a_node, a_headPart, a_npc, a_pendingHeadData);
		}
	}
}
