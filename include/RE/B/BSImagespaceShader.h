#pragma once

#include "RE/B/BSShader.h"
#include "RE/I/ImageSpaceEffect.h"

namespace RE
{
	class __declspec(novtable) BSImagespaceShader :
	    public BSShader,         // 000
	    public ImageSpaceEffect  // 190
	{
	public:
		static constexpr auto RTTI{ RTTI::BSImagespaceShader };
		static constexpr auto VTABLE{ VTABLE::BSImagespaceShader };

		struct ShaderMacro
		{
			const char* name;   // 00
			const char* value;  // 08
		};
		static_assert(sizeof(ShaderMacro) == 0x10);

		// add
		virtual bool         SetupComputeShaderResources(bool a_unk);  // 0D
		virtual void         Unk0E();                                  // 0E
		virtual void         Unk0F();                                  // 0F
		virtual void         Initialize();                             // 10
		virtual ShaderMacro* GetShaderMacros(ShaderMacro* a_macros);   // 11

		// members
		const char* className;     // 240
		const char* sourcePrefix;  // 248
		std::byte   pad250[0x68];  // 250
	};
	static_assert(sizeof(BSImagespaceShader) == 0x2B8);
}
