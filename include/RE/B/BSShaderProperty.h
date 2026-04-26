#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/B/BSSpinLock.h"
#include "RE/N/NiShadeProperty.h"

namespace RE
{
	class BSEffectShaderData;
	class BSRenderPass;
	class BSShaderAccumulator;
	class BSShaderMaterial;
	class NiTexture;

	class __declspec(novtable) BSShaderProperty :
		public NiShadeProperty  // 00
	{
	private:
		static constexpr auto BIT64 = static_cast<std::uint64_t>(1);

	public:
		static constexpr auto RTTI{ RTTI::BSShaderProperty };
		static constexpr auto VTABLE{ VTABLE::BSShaderProperty };
		static constexpr auto Ni_RTTI{ Ni_RTTI::BSShaderProperty };

		enum class TextureTypeEnum
		{
			kBase = 0x0,
			kNormal = 0x1,
			kGlow = 0x2,
			kHeight = 0x3,
			kEnv = 0x4,
			kWrinkles = 0x5,
			kMultilayer = 0x6,
			kBacklightMask = 0x7,
			kSmoothSpec = kBacklightMask,

			kTotal
		};

		enum class EShaderPropertyFlag : std::uint64_t
		{
			kSpecular = BIT64 << 0,
			kSkinned = BIT64 << 1,
			kTempRefraction = BIT64 << 2,
			kVertexAlpha = BIT64 << 3,
			kGrayscaleToPaletteColor = BIT64 << 4,
			kGrayscaleToPaletteAlpha = BIT64 << 5,
			kFalloff = BIT64 << 6,
			kEnvMap = BIT64 << 7,
			kRGBFalloff = BIT64 << 8,
			kCastShadows = BIT64 << 9,
			kFace = BIT64 << 10,
			kUIMaskRects = BIT64 << 11,
			kModelSpaceNormals = BIT64 << 12,
			kRefractionClamp = BIT64 << 13,
			kMultiTextureLandscape = BIT64 << 14,
			kRefraction = BIT64 << 15,
			kRefractionFalloff = BIT64 << 16,
			kEyeReflect = BIT64 << 17,
			kHairTint = BIT64 << 18,
			kScreendoorAlphaFade = BIT64 << 19,
			kLocalMapClear = BIT64 << 20,
			kFaceGenRGBTint = BIT64 << 21,
			kOwnEmit = BIT64 << 22,
			kProjectedUV = BIT64 << 23,
			kMultipleTextures = BIT64 << 24,
			kTesselate = BIT64 << 25,
			kDecal = BIT64 << 26,
			kDynamicDecal = BIT64 << 27,
			kCharacterLight = BIT64 << 28,
			kExternalEmittance = BIT64 << 29,
			kSoftEffect = BIT64 << 30,
			kZBufferTest = BIT64 << 31,
			kZBufferWrite = BIT64 << 32,
			kLODLandscape = BIT64 << 33,
			kLODObjects = BIT64 << 34,
			kNoFade = BIT64 << 35,
			kTwoSided = BIT64 << 36,
			kVertexColors = BIT64 << 37,
			kGlowMap = BIT64 << 38,
			kTransformChanged = BIT64 << 39,
			kDismembermentMeatCuff = BIT64 << 40,
			kTint = BIT64 << 41,
			kVertexLighting = BIT64 << 42,
			kUniformScale = BIT64 << 43,
			kFitSlope = BIT64 << 44,
			kBillboard = BIT64 << 45,
			kLODLandBlend = BIT64 << 46,
			kDismemberment = BIT64 << 47,
			kWireframe = BIT64 << 48,
			kWeaponBlood = BIT64 << 49,
			kHideOnLocalMap = BIT64 << 50,
			kPremultAlpha = BIT64 << 51,
			kVATSTarget = BIT64 << 52,
			kAnisotropicLighting = BIT64 << 53,
			kSkewSpecularAlpha = BIT64 << 54,
			kMenuScreen = BIT64 << 55,
			kMultiLayerParallax = BIT64 << 56,
			kAlphaTest = BIT64 << 57,
			kInvertedFadePattern = BIT64 << 58,
			kVATSTargetDrawAll = BIT64 << 59,
			kPipboyScreen = BIT64 << 60,
			kTreeAnim = BIT64 << 61,
			kEffectLighting = BIT64 << 62,
			kRefractionWritesDepth = BIT64 << 63
		};

		class ForEachVisitor;

		class RenderPassArray
		{
		public:
			constexpr RenderPassArray() noexcept {}  // NOLINT(modernize-use-equals-default)

			// members
			BSRenderPass* passList{ nullptr };  // 0
		};
		static_assert(sizeof(RenderPassArray) == 0x8);

		// add
		virtual RenderPassArray*     GetRenderPasses(BSGeometry* a_geom, std::uint32_t a_renderMode, BSShaderAccumulator* a_accumulator) = 0;  // 2B
		virtual RenderPassArray*     GetRenderPasses_ShadowMapOrMask(BSGeometry*, std::uint32_t, BSShaderAccumulator*) { return nullptr; }     // 2C
		virtual RenderPassArray*     GetRenderPasses_LocalMap(BSGeometry*, std::uint32_t, BSShaderAccumulator*) { return nullptr; }            // 2D
		virtual BSRenderPass*        CreateVatsMaskRenderPass(BSGeometry*) { return nullptr; }                                                 // 2E
		virtual std::uint16_t        GetNumberofPasses([[maybe_unused]] BSGeometry* a_geom) { return 1; }                                      // 2F
		virtual BSRenderPass*        GetRenderDepthPass(BSGeometry*) { return nullptr; }                                                       // 30
		virtual bool                 CanMerge(const BSShaderProperty* a_prop);                                                                 // 31
		virtual void                 SetMaterialAlpha(float) { return; }                                                                       // 32
		virtual float                QMaterialAlpha() const { return 1.0F; }                                                                   // 33
		virtual const BSFixedString& GetRootName() const;                                                                                      // 34
		virtual std::int32_t         ForEachTexture(ForEachVisitor&) { return 1; }                                                             // 35
		virtual std::int32_t         QShader() const { return 0; }                                                                             // 36
		virtual void                 ClearUnusedMaterialValues() { return; }                                                                   // 37
		virtual BSShaderProperty*    ClarifyShader(BSGeometry*, bool, bool) { return nullptr; }                                                // 38
		virtual NiTexture*           GetBaseTexture() const { return nullptr; }                                                                // 39
		virtual RenderPassArray*     GetWaterFogPassList(BSGeometry*) { return nullptr; }                                                      // 3A
		virtual bool                 AcceptsEffectData() const { return false; }                                                               // 3B
		virtual void                 PrecacheTextures() { return; }                                                                            // 3C
		virtual std::uint32_t        DetermineUtilityShaderDecl() const { return 0; }                                                          // 3D
		virtual std::uint32_t        GetMaterialType() const { return 0; }                                                                     // 3E
		virtual void                 DoClearRenderPasses() { return; }                                                                         // 3F

		void SetMaterial(BSShaderMaterial* a_material, bool a_unique)
		{
			using func_t = decltype(&BSShaderProperty::SetMaterial);
			static REL::Relocation<func_t> func{ ID::BSShaderProperty::SetMaterial };
			return func(this, a_material, a_unique);
		}

		// members
		float                                             alpha;                  // 28
		std::int32_t                                      lastRenderPassState;    // 2C
		REX::TEnumSet<EShaderPropertyFlag, std::uint64_t> flags;                  // 30
		RenderPassArray                                   renderPassList;         // 38
		RenderPassArray                                   debugRenderPassList;    // 40
		BSFadeNode*                                       fadeNode;               // 48
		BSEffectShaderData*                               effectData;             // 50
		BSShaderMaterial*                                 material;               // 58
		std::uint32_t                                     lastAccumTime;          // 60
		float                                             lodFade;                // 64
		BSNonReentrantSpinLock                            clearRenderPassesLock;  // 68
	};
	static_assert(sizeof(BSShaderProperty) == 0x70);
}
