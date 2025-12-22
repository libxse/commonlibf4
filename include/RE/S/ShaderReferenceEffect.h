#pragma once

#include "RE/B/BSMagicShaderParticles.h"
#include "RE/B/BSModelDB.h"
#include "RE/B/BSSoundHandle.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTTuple.h"
#include "RE/N/NiPointer.h"
#include "RE/R/ReferenceEffect.h"

namespace RE
{
	class BSEffectShaderData;
	class NiAVObject;
	class NiSourceTexture;
	class NiTexture;

	class __declspec(novtable) ShaderReferenceEffect :
		public ReferenceEffect  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::ShaderReferenceEffect };
		static constexpr auto VTABLE{ VTABLE::ShaderReferenceEffect };
		static constexpr auto Ni_RTTI{ Ni_RTTI::ShaderReferenceEffect };
		static constexpr auto TYPE{ TEMP_EFFECT_TYPE::kRefShader };

		~ShaderReferenceEffect() override;

		enum class Flag
		{
			kThirdPerson = 0x0,
			kInterfaceEffect = 0x1,
			kRestart = 0x2,
			kAllTexturesAvailable = 0x3,
			kParticleShadersStarted = 0x4,
			kSuspended = 0x5,
			kDisallowTargetRoot = 0x6
		};

		// members
		BSMagicShaderParticles                           particles;               // 048
		BSTArray<BSTTuple<void*, NiPointer<NiTexture>*>> textureRequests;         // 068 - TextureDB::Handle
		BSTArray<NiPointer<NiAVObject>>                  addOnObjects;            // 080
		BSTArray<void*>                                  modelHandles;            // 098 - BSModelDB::Handle
		BSTArray<NiPointer<NiAVObject>>                  targetArray;             // 0B0
		BSSoundHandle                                    soundHandle;             // 0C8
		NiPointer<NiSourceTexture>                       textureShaderTexture;    // 0D0
		NiPointer<NiSourceTexture>                       textureBlockOutTexture;  // 0D8
		NiPointer<NiSourceTexture>                       texturePaletteTexture;   // 0E0
		TESBoundObject*                                  wornObject;              // 0E8
		TESEffectShader*                                 effectData;              // 0F0
		BSEffectShaderData*                              effectShaderData;        // 0F8
		NiPointer<NiAVObject>                            lastRootNode;            // 100
		float                                            alphaTimer;              // 104
		float                                            addonAlpha;              // 108
		float                                            addonScale;              // 10C
		float                                            effectShaderAge;         // 110
		std::uint32_t                                    flags;                   // 114
		std::uint32_t                                    pushCount;               // 118
	};
	static_assert(sizeof(ShaderReferenceEffect) == 0x120);
}
