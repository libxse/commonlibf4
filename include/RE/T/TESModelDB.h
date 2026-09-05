#pragma once

#include "RE/B/BSModelDB.h"

namespace RE
{
	class __declspec(novtable) TESModelDB :
		public BSModelDB  // 00
	{
	public:
		class __declspec(novtable) TESProcessor : public BSModelProcessor
		{
		public:
			static constexpr auto RTTI{ RTTI::TESModelDB____TESProcessor };
			static constexpr auto VTABLE{ VTABLE::TESModelDB____TESProcessor };

			virtual ~TESProcessor(); // 00

			virtual void Process(ModelData* modelData, const char* modelName, NiAVObject** root, std::uint32_t* typeOut) override; // 01
		};
		static_assert(sizeof(TESProcessor) == 0x08);
	};
}
