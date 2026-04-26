#pragma once

namespace RE
{
	class NiAvObject;
	class NiSwitchNode;

	namespace BSShaderUtil
	{
		inline void SetMaterialAlpha(NiAvObject* a_object, float a_alpha, bool a_onlyFade)
		{
			using func_t = decltype(&BSShaderUtil::SetMaterialAlpha);
			static REL::Relocation<func_t> func{ ID::BSShaderUtil::SetMaterialAlpha };
			return func(a_object, a_alpha, a_onlyFade);
		}
	}
}
