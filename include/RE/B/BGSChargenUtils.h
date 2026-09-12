#pragma once

#include "RE/B/BGSCharacterMorph.h"
#include "RE/B/BGSCharacterTint.h"
#include "RE/B/BGSHeadPart.h"
#include "RE/B/BSFaceGenUtils.h"
#include "RE/B/BSFixedString.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTEvent.h"
#include "RE/B/BSTHashmap.h"

namespace RE
{
	namespace LooksMenuEvent
	{
		enum class EventType;
	}

	class Actor;
	class BGSColorForm;
	class BGSTextureSet;
	class CharGenCharacterUpdateEvent;
	class TESNPC;

	class BGSChargenUtils :
		public BSTEventSource<CharGenCharacterUpdateEvent>  // 00
	{
	public:
		enum class EditMode;
		enum class UndoType;

		struct AxisRemappingData
		{
			// members
			std::int32_t axisMap[6];  //00
		};
		static_assert(sizeof(AxisRemappingData) == 0x18);

		struct UndoData
		{
			struct Vec3
			{
				// members
				float x;  // 00
				float y;  // 04
				float z;  // 08
			};
			static_assert(sizeof(Vec3) == 0x0C);

			struct Transform
			{
				// members
				Vec3  pos;    // 00
				Vec3  rot;    // 0C
				float scale;  // 18
			};
			static_assert(sizeof(Transform) == 0x1C);

			// members
			UndoType      type;             // 00
			std::uint32_t targetID;         // 04
			float         featureModifier;  // 08
			union
			{
				Vec3          weight;
				Transform     transform;
				std::uint32_t featureIndex;
			};  // 0C
			BGSCharacterTint::Entries        tintEntries;        // 28
			BSTHashMap<std::uint32_t, float> morphSliderValues;  // 40
		};
		static_assert(sizeof(UndoData) == 0x70);

		[[nodiscard]] static BGSChargenUtils* GetSingleton()
		{
			static REL::Relocation<std::uint32_t*> characterIndex{ ID::BGSChargenUtils::CharacterIndex };
			static REL::Relocation<BGSChargenUtils***> singleton{ ID::BGSChargenUtils::Singleton };
			return *singleton ? (*singleton)[*characterIndex] : nullptr;
		}

		void LoadPreset(std::uint32_t a_presetIndex)
		{
			using func_t = decltype(&BGSChargenUtils::LoadPreset);
			static REL::Relocation<func_t> func{ ID::BGSChargenUtils::LoadPreset };
			return func(this, a_presetIndex);
		}

		// members
		Actor*                                                                            targetActor;                                                // 058
		TESNPC*                                                                           targetNPC;                                                  // 060
		TESNPC*                                                                           cacheNPC;                                                   // 068
		const BSTArray<TESNPC*>*                                                          characterPresets;                                           // 070
		BSTArray<BGSColorForm*>                                                           hairColors;                                                 // 078
		const BSTArray<BGSTextureSet*>*                                                   complexions;                                                // 090
		BSTArray<BGSHeadPart*>                                                            headParts[10];                                              // 098
		BSTHashMap<std::uint32_t, BGSChargenUtils::AxisRemappingData>                     facialBoneRegionAxisRemapping;                              // 188
		BSTHashMap<std::uint32_t, std::uint32_t>                                          textureValueToFacialBoneRegionMap;                          // 1B8
		BSTHashMap<std::uint32_t, std::int32_t>                                           sliderAxisMapping;                                          // 1E8
		BSTHashMap<std::uint32_t, const BGSCharacterMorph::Group*>                        regionIDToMorphGroupMap;                                    // 218
		BSTHashMap<std::uint32_t, const BGSCharacterTint::Template::Group*>               regionIDToTintGroupMap;                                     // 248
		BSTHashMap<BGSHeadPart::HeadPartType, std::uint32_t>                              headPartTypeToRegionIDMap;                                  // 278
		BSTHashMap<std::uint32_t, LooksMenuEvent::EventType>                              regionIDToEventTypeMap;                                     // 2A8
		BSTArray<const BGSCharacterMorph::Group*>                                         morphGroups;                                                // 2D8
		BSTHashMap<const BGSCharacterMorph::Group*, BSTArray<BGSCharacterMorph::Preset>*> morphPresets;                                               // 2F0
		BSTArray<const BGSCharacterTint::Template::Group*>                                facePartCustomizationGroups;                                // 320
		BSTArray<BSTArray<const BGSCharacterTint::Template::Entry*>*>                     facePartCustomizationGroupEntries;                          // 338
		const BGSCharacterTint::Template::Palette*                                        skinToneCustomizationPalette;                               // 350
		BSTArray<const BGSCharacterTint::Template::Group*>                                faceExtraGroups;                                            // 358
		BSTArray<BSTArray<const BGSCharacterTint::Template::Entry*>*>                     faceExtraEntries;                                           // 370
		std::uint32_t                                                                     tempFaceExtra;                                              // 388
		UndoData                                                                          undoData;                                                   // 390
		UndoData                                                                          saveData;                                                   // 400
		UndoData                                                                          detailUndoData;                                             // 470
		BSTHashMap<BSFixedString, float>                                                  morphSliderDeltas;                                          // 4E0
		std::uint32_t                                                                     lastCharacterPreset;                                        // 510
		bool                                                                              needsCustomizationUpdate;                                   // 514
		bool                                                                              needsFaceUpdate;                                            // 515
		bool                                                                              needsBodyUpdate;                                            // 516
		bool                                                                              needsMorphUpdate;                                           // 517
		bool                                                                              needsFullUpdate;                                            // 518
		bool                                                                              playableOnly;                                               // 519
		std::byte                                                                         characterCustomizationTextureArraysHandles[0x540 - 0x520];  // 520 - BSResource::RHandleType[4]
		BSTSmartPointer<BSFaceGenUtils::FaceGenData>                                      customizationData;                                          // 540
	};
	static_assert(sizeof(BGSChargenUtils) == 0x548);
}
