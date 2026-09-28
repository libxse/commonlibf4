#pragma once

#include "RE/B/BSIntrusiveRefCounted.h"
#include "RE/N/NiPoint2.h"

namespace RE
{
	class BSShaderProperty;

	class __declspec(novtable) BSShaderMaterial :
		public BSIntrusiveRefCounted  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BSShaderMaterial };
		static constexpr auto VTABLE{ VTABLE::BSShaderMaterial };

		enum class Feature
		{
			kNone = static_cast<std::underlying_type_t<Feature>>(-1),
			kDefault = 0x0,
			kEnvmap = 0x1,
			kGlowmap = 0x2,
			kParallax = 0x3,
			kFace = 0x4,
			kSkinTint = 0x5,
			kHairTint = 0x6,
			kParallaxOcc = 0x7,
			kLandscape = 0x8,
			kLODLandscape = 0x9,
			kSnow = 0xA,
			kMultiLayerParallax = 0xB,
			kTreeAnim = 0xC,
			kLODObjects = 0xD,
			kMultiIndexSnow = 0xE,
			kLODObjectsHD = 0xF,
			kEye = 0x10,
			kCloud = 0x11,
			kLODLandscapeNoise = 0x12,
			kLODLandscapeBlend = 0x13,
			kDismemberment = 0x14
		};

		enum class Type
		{
			kBase = 0x0,
			kEffect = 0x1,
			kLighting = 0x2,
			kWater = 0x3
		};

		virtual ~BSShaderMaterial();

		void SetOffsetUV(float u, float v)
		{
			texCoordOffset[0].x = u;
			texCoordOffset[1].x = u;
			texCoordOffset[0].y = v;
			texCoordOffset[1].y = v;
		}

		void GetOffsetUV(float * u, float * v)
		{
			*u = texCoordOffset[0].x;
			*v = texCoordOffset[0].y;
		}

		void SetScaleUV(float u, float v)
		{
			texCoordScale[0].x = u;
			texCoordScale[1].x = u;
			texCoordScale[0].y = v;
			texCoordScale[1].y = v;
		}

		void GetScaleUV(float * u, float * v)
		{
			*u = texCoordScale[0].x;
			*v = texCoordScale[0].y;
		}

		// add
		virtual BSShaderMaterial* Create();                                                     // 01
		virtual void              CopyMembers(const BSShaderMaterial* a_other);                 // 02
		virtual std::uint32_t     ComputeCRC32(std::uint32_t a_uniqueID, bool a_combining);     // 03
		virtual BSShaderMaterial* GetDefault();                                                 // 04
		virtual Feature           GetFeature();                                                 // 05
		virtual Type              GetType();                                                    // 06
		virtual void              ReceiveValuesFromRootMaterial(BSShaderProperty* a_property);  // 07
		virtual bool              DoIsCopy(const BSShaderMaterial* a_other);                    // 08

		// members
		NiPoint2      texCoordOffset[2];  // 0C
		NiPoint2      texCoordScale[2];   // 1C
		std::uint32_t hashKey;            // 2C
		std::uint32_t uniqueCode;         // 30
	};
	static_assert(sizeof(BSShaderMaterial) == 0x38);
}
