#pragma once

#include "RE/B/BSTriShape.h"
#include "RE/N/NiRTTI.h"

namespace RE
{
	class __declspec(novtable) BSMeshLODTriShape :
	    public BSTriShape  // 000
	{
	public:
		static constexpr auto RTTI{ RTTI::BSMeshLODTriShape };
		static constexpr auto VTABLE{ VTABLE::BSMeshLODTriShape };
		static constexpr auto Ni_RTTI{ Ni_RTTI::BSMeshLODTriShape };

		// override (BSTriShape)
		const NiRTTI* GetRTTI() const override  // 02
		{
			static REL::Relocation<const NiRTTI*> rtti{ BSMeshLODTriShape::Ni_RTTI };
			return rtti.get();
		}

		NiObject*     CreateClone(NiCloningProcess& a_cloneData) override;  // 1A
		void          LoadBinary(NiStream& a_stream) override;              // 1B
		void          SaveBinary(NiStream& a_stream) override;              // 1E
		void          OnVisible(NiCullingProcess& a_culler) override;       // 39
		std::uint32_t GetRenderableTris(std::uint32_t a_LODMode) override;  // 41

		// members
		std::uint32_t lodTriangleCounts[3];  // 170
		std::byte     pad17C[0x4];           // 17C
	};
	static_assert(offsetof(BSMeshLODTriShape, lodTriangleCounts) == 0x170);
	static_assert(sizeof(BSMeshLODTriShape) == 0x180);
}
