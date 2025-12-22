#pragma once

#include "RE/B/BSGeometry.h"
#include "RE/N/NiColor.h"
#include "RE/N/NiPoint.h"
#include "RE/N/NiPointer.h"
#include "RE/N/NiTexture.h"
#include "RE/N/NiTransform.h"

namespace RE
{
	class ShadowSceneNode;

	class BSShaderManager
	{
	public:
		enum class BSShaderTimerMode : std::uint32_t
		{
			kDefault = 0x0,
			kDelta = 0x1,
			kSystem = 0x2,
			kRealDelta = 0x3,
			kFrameCount = 0x4,
			kAccumulatedDelta = 0x5,

			kTotal = 0x6
		};

		enum class ShaderEnum : std::uint32_t
		{
			kEffect = 0x0,
			kUtility = 0x1,
			kDistantTree = 0x2,
			kParticle = 0x3,
			kDFPrepass = 0x4,
			kDFLight = 0x5,
			kDFComposite = 0x6,
			kSky = 0x7,
			kLighting = 0x8,
			kBloodSpatter = 0x9,
			kWater = 0xA,
			kFaceCustomization = 0xB,
			kImageSpace = 0xC,

			kTotal = 0xD
		};

		enum class eCameraInWaterState : std::uint32_t
		{
			kAboveWater = 0x0,
			kPartiallyAboveWater = 0x1,
			kPartiallyUnderWater = 0x2,
			kUnderWater = 0x3
		};

		enum class eSceneGraphEnum : std::uint32_t
		{
			kWorld = 0x0,
			kUIOld = 0x1,
			kPreview = 0x2,
			kUILoadingMenu = 0x3,
			kUI = 0x4,

			kTotal = 0x5
		};

		enum class etRenderFlag : std::uint32_t
		{
			kColorWriteDisable = 0x0
		};

		enum class etRenderMode : std::uint32_t
		{
			kNormal = 0x0,
			kNumLights = 0x1,
			kNumNonShadowLights = 0x2,
			kNumShadowLights = 0x3,
			kNumPasses = 0x4,
			kSinglePass = 0x5,
			kTexUsage = 0x6,
			kDegrade = 0x7,
			kFade = 0x8,
			kShadowSplitDebug = 0x9,
			kTexSize = 0xA,
			kFadeNodeTriDebug = 0xB,
			kOverdraw = 0xC,
			kDepthPrepass = 0xD,
			kOcclusionMap = 0xE,
			kShadowmap = 0xF,
			kShadowmapDir = 0x10,
			kShadowmapPB = 0x11,
			kLocalmap = 0x12,
			kFrozen = 0x13,
			kScreenSplatter = 0x14,
			kLODOnlyNoNoise = 0x15,
			kSilhouetteLOD = 0x16,
			kSilhouette = 0x17,
			kDeferredGBuffer = 0x18,
			kDeferredGB0 = 0x19,
			kDeferredGBDebgStart = 0x19,
			kDeferredGB1 = 0x1A,
			kDeferredGB2 = 0x1B,
			kDeferredGB3 = 0x1C,
			kDeferredGB4 = 0x1D,
			kDeferredGB5 = 0x1E,
			kDeferredGBDebugEnd = 0x1E,
			kDeferredGBAll = 0x1F,
			kLightvis = 0x20,
			kVATSMask = 0x21,
			kVATSMaskDebug = 0x22,
			kVATSMaskPrepass = 0x23,
			kMapMaker = 0x25,
			kSimpleLighting = 0x26,

			kTotal = 0x27
		};

		enum class etShadowMode : std::uint32_t
		{
			kISFilter = 0x0,
			kPCF4 = 0x1,
			kPCF9 = 0x2,
			kLoopFilter = 0x3
		};

		class State
		{
			// members
			ShadowSceneNode*              shadowSceneNode[5];                      // 00
			float                         timerValues[6];                          // 28
			std::uint32_t                 frameCount;                              // 40
			NiColorA                      loadedRange;                             // 44
			bool                          interior;                                // 54
			bool                          liteBrite;                               // 55
			bool                          deferredRGBEmit;                         // 56
			bool                          deferredRGBSpec;                         // 57
			bool                          menuScreenPremultAlpha;                  // 58
			bool                          menuScreenPostAA;                        // 59
			float                         menuScreenAlpha;                         // 5C
			bool                          characterLightEnabled;                   // 60
			bool                          screenSpaceReflectionsEnabled;           // 61
			bool                          screenSpaceSubsurfaceScatteringEnabled;  // 62
			std::uint32_t                 pipboyScreenTarget;                      // 64
			NiPointer<NiTexture>          pipboyFXTexture;                         // 68
			float                         pipboyScreenEmitIntensity;               // 70
			float                         pipboyScreenDiffuseIntensity;            // 74
			float                         pipboyScreenEmitIntensityWA;             // 78
			float                         pipboyScreenDiffuseIntensityWA;          // 7C
			float                         specularLODStartFadeSquared;             // 80
			float                         specularLODEndSquared;                   // 84
			float                         landLOFaceSeconds;                       // 88
			float                         leafAnimDampenDistStartSPU;              // 8C
			float                         leafAnimDampenDistEndSPU;                // 90
			NiPoint2                      oldGridArrayCenter;                      // 94
			NiPoint2                      gridArrayCenter;                         // 9C
			float                         gridArrayLerpStart;                      // A4
			bool                          LODFadeInProgress;                       // A8
			std::uint8_t                  sceneGraph;                              // A9
			BSShaderManager::etRenderMode debugMode;                               // AC
			std::uint32_t                 debugColorWrite;                         // B0
			NiTransform                   directionalAmbientTransform;             // C0
			NiTransform                   localDirectionalAmbientTransform;        // 100
			NiColorA                      ambientSpecular;                         // 140
			bool                          ambientSpecularEnabled;                  // 150
			std::uint32_t                 textureTransformCurrentBuffer;           // 154
			std::uint32_t                 textureTransformFlipMode;                // 158
			std::uint32_t                 cameraInWaterState;                      // 15C
			float                         cameraNear;                              // 160
			float                         cameraFar;                               // 164
			float                         waterIntersect;                          // 168
			NiColorA                      menuScreenBlendParams;                   // 16C
			NiColorA                      debugTintColor;                          // 17C
			float                         boneTintingTiming;                       // 18C
			NiPoint3                      forwardLightOffset;                      // 190
			NiPoint3                      clipVolume[2];                           // 19C
			NiPointer<BSGeometry>         clipVolumeGeom;                          // 1B8
			NiColorA                      maskRectParams;                          // 1C0
			NiColorA                      UIMaskRectsA[16];                        // 1D0
			NiColorA                      UIMaskRectColorsA[16];                   // 2D0
			NiColorA                      characterLightParams;                    // 3D0
			std::uint32_t                 forceDisableFrame;                       // 3E0
			bool                          effectShaderVATSHighlight;               // 3E4
			bool                          forceEffectShaderPremultAlpha;           // 3E5
			bool                          forceDisableSSR;                         // 3E6
			bool                          forceDisableGodrays;                     // 3E7
			bool                          forceDisableDirLights;                   // 3E8
			bool                          pendingForceDisableSSR;                  // 3E9
			bool                          pendingForceDisableGodrays;              // 3EA
			bool                          pendingForceDisableDirLights;            // 3EB
		};
		static_assert(sizeof(State) == 0x3F0);
	};
}
