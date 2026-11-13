#pragma once

namespace RE
{
	class NiAVObject;
	class NiSwitchNode;

	namespace BSShaderUtil
	{
		inline void SetMaterialAlpha(NiAVObject* a_object, float a_alpha, bool a_onlyFade)
		{
			using func_t = decltype(&BSShaderUtil::SetMaterialAlpha);
			static REL::Relocation<func_t> func{ ID::BSShaderUtil::SetMaterialAlpha };
			return func(a_object, a_alpha, a_onlyFade);
		}

		inline void ClearRenderPasses(NiAVObject* a_object)
		{
			using func_t = decltype(&BSShaderUtil::ClearRenderPasses);
			static REL::Relocation<func_t> func{ ID::BSShaderUtil::ClearRenderPasses };
			return func(a_object);
		}
	}
}
