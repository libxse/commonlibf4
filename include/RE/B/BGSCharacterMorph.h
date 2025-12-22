#pragma once

#include "RE/B/BGSCharacterTint.h"
#include "RE/B/BGSHeadPart.h"
#include "RE/B/BGSLocalizedString.h"
#include "RE/B/BSFixedString.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTHashMap.h"
#include "RE/N/NiPoint.h"

namespace RE
{
	namespace BGSCharacterMorph
	{
		class BoneBaseScales
		{
		public:
			// members
			NiPoint3 scales[3];  // 00
		};
		static_assert(sizeof(BoneBaseScales) == 0x24);

		class BONE_MODIFIER_MIN_MAX
		{
		public:
			// members
			float minY;  // 00
			float minZ;  // 04
			float maxY;  // 08
			float maxZ;  // 0C
		};
		static_assert(sizeof(BONE_MODIFIER_MIN_MAX) == 0x10);

		class Slider
		{
		public:
			// members
			BSFixedString       morphNames[2];  // 00
			const std::uint32_t uniqueID;       // 10
		};
		static_assert(sizeof(Slider) == 0x18);

		class Transform
		{
		public:
			// members
			NiPoint3 position;  // 00
			NiPoint3 rotation;  // 0C
			NiPoint3 scale;     // 18
		};
		static_assert(sizeof(Transform) == 0x24);

		class TransformMinMax
		{
		public:
			// members
			Transform minima;  // 00
			Transform maxima;  // 24
		};
		static_assert(sizeof(TransformMinMax) == 0x48);

		class FacialBoneRegion
		{
		public:
			// members
			Transform                                   defaultTransform;          // 00
			BGSLocalizedString                          name;                      // 28
			BSFixedString                               associatedMorphGroupName;  // 30
			BGSCharacterTint::EntrySlot                 associatedTintSlot;        // 38
			BGSHeadPart::HeadPartType                   associatedHeadPartType;    // 3C
			BSTHashMap<BSFixedString, TransformMinMax*> boneMinMaxMap;             // 40
			BSTArray<std::uint32_t>                     associatedMorphSliders;    // 70
			const std::uint32_t                         id;                        // 88
		};
		static_assert(sizeof(FacialBoneRegion) == 0x90);

		class Preset
		{
		public:
			// members
			BGSLocalizedString name;        // 00
			BSFixedString      morph;       // 08
			BGSTextureSet*     textureSet;  // 10
			std::int8_t        flags;       // 18
			std::uint32_t      id;          // 1C
		};
		static_assert(sizeof(Preset) == 0x20);

		class Group
		{
		public:
			// members
			BSFixedString           name;          // 00
			BSTArray<Preset>        presets;       // 08
			BSTArray<std::uint32_t> sliders;       // 20
			std::uint16_t           presetMaskID;  // 38
		};
		static_assert(sizeof(Group) == 0x40);

		enum class WeightComponent : std::uint32_t
		{
			kThin = 0x0,
			kMuscular = 0x1,
			kFat = 0x2
		};

		enum class BODY_MORPH_REGION : std::uint32_t
		{
			kHead = 0x0,
			kUpperTorso = 0x1,
			kArms = 0x2,
			kLowerTorso = 0x3,
			kLegs = 0x4
		};
	}
}
