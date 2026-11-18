#pragma once

namespace RE
{
	class __declspec(novtable) BSCubeMapCamera :
		public NiCamera  // 000
	{
	public:
		static constexpr auto RTTI{ RTTI::BSCubeMapCamera };
		static constexpr auto VTABLE{ VTABLE::BSCubeMapCamera };
		static constexpr auto Ni_RTTI{ Ni_RTTI::BSCubeMapCamera };

		enum class FaceEnableFlags
		{
			kEnablePosX = 0x1,
			kEnableNegX = 0x2,
			kEnablePosY = 0x4,
			kEnableNegY = 0x8,
			kEnablePosZ = 0x10,
			kEnableNegZ = 0x20,
			kEnableAll = 0x3F
		};

		enum class Face
		{
			kPosX = 0x0,
			kNegX = 0x1,
			kPosY = 0x2,
			kNegY = 0x3,
			kPosZ = 0x4,
			kNegZ = 0x5
		};

		// add
		virtual void Click(FaceEnableFlags a_faceEnableFlags, bool a_silhouette, bool a_clearScene, bool a_LODOnly);  // 3A

		[[nodiscard]] static NiPointer<BSCubeMapCamera> Create()
		{
			using func_t = BSCubeMapCamera* (*)(BSCubeMapCamera*);
			static REL::Relocation<func_t> func{ ID::BSCubeMapCamera::Ctor };
			auto*                          memory = static_cast<BSCubeMapCamera*>(NiAVObject::operator new(sizeof(BSCubeMapCamera)));
			return NiPointer<BSCubeMapCamera>{ func(memory) };
		}

		void AddCubeMapScene(NiAVObject* a_scene)
		{
			using func_t = decltype(&BSCubeMapCamera::AddCubeMapScene);
			static REL::Relocation<func_t> func{ ID::BSCubeMapCamera::AddCubeMapScene };
			return func(this, a_scene);
		}

		// members
		BSTArray<NiPointer<NiAVObject>, BSTArrayHeapAllocator> cubeMapScene;           // 1A0
		NiPointer<BSShaderAccumulator>                         accumulator;            // 1B8
		NiPointer<BSShaderAccumulator>                         accumulatorBackground;  // 1C0
		NiPointer<NiCamera>                                    cameraBackground;       // 1C8
		NiColorA                                               silhouetteColor;        // 1D0
	};
	static_assert(sizeof(BSCubeMapCamera) == 0x1E0);
}
