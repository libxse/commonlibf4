#pragma once

#include "RE/B/BSCullingProcess.h"

namespace RE
{
	class __declspec(novtable) BSGeometryListCullingProcess :
	    public BSCullingProcess  // 000
	{
	public:
		static constexpr auto RTTI{ RTTI::BSGeometryListCullingProcess };
		static constexpr auto VTABLE{ VTABLE::BSGeometryListCullingProcess };
		static constexpr auto Ni_RTTI{ Ni_RTTI::BSGeometryListCullingProcess };

		~BSGeometryListCullingProcess() override;  // 18

		// override (BSCullingProcess)
		const NiRTTI* GetRTTI() const override;                       // 00
		void          AppendVirtual(BSGeometry* a_visible) override;  // 1B
		void          AppendNonAccum(NiAVObject* a_object) override;  // 1C

		// members
		std::byte pad1A0[0x88];  // 1A0
	};
	static_assert(sizeof(BSGeometryListCullingProcess) == 0x228);
}
