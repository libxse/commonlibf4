#pragma once

#include "RE/B/BSGraphics.h"
#include "RE/B/BSReloadShaderI.h"
#include "RE/B/BSShaderTechniqueIDMap.h"
#include "RE/N/NiRefObject.h"

namespace RE
{
	class __declspec(novtable) BSComputeShader :
	    public NiRefObject,     // 00
	    public BSReloadShaderI  // 10
	{
	public:
		static constexpr auto RTTI{ RTTI::BSComputeShader };
		static constexpr auto VTABLE{ VTABLE::BSComputeShader };

		// add
		virtual void Run(std::uint32_t a_technique, std::uint32_t a_threadGroupCountX, std::uint32_t a_threadGroupCountY, std::uint32_t a_threadGroupCountZ);  // 02

		// override (BSReloadShaderI)
		void ReloadShaders(BSIStream* a_stream) override;  // 00

		std::uint32_t LoadTechniquesFromStream(BSIStream* a_stream)
		{
			using func_t = decltype(&BSComputeShader::LoadTechniquesFromStream);
			static REL::Relocation<func_t> func{ ID::BSComputeShader::LoadTechniquesFromStream };
			return func(this, a_stream);
		}

		// members
		const char*                                                 name;            // 18
		BSShaderTechniqueIDMap::MapType<BSGraphics::ComputeShader*> computeShaders;  // 20
	};
	static_assert(offsetof(BSComputeShader, name) == 0x18);
	static_assert(offsetof(BSComputeShader, computeShaders) == 0x20);
	static_assert(sizeof(BSComputeShader) == 0x50);
}
