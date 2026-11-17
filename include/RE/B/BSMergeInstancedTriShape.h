#pragma once

#include "RE/B/BSGraphics.h"
#include "RE/B/BSTriShape.h"
#include "RE/N/NiRTTI.h"

namespace RE
{
	class __declspec(novtable) BSMergeInstancedTriShape :
	    public BSTriShape  // 000
	{
	public:
		static constexpr auto RTTI{ RTTI::BSMergeInstancedTriShape };
		static constexpr auto VTABLE{ VTABLE::BSMergeInstancedTriShape };
		static constexpr auto Ni_RTTI{ Ni_RTTI::BSMergeInstancedTriShape };

		// override (BSTriShape)
		const NiRTTI* GetRTTI() const override  // 02
		{
			static REL::Relocation<const NiRTTI*> rtti{ BSMergeInstancedTriShape::Ni_RTTI };
			return rtti.get();
		}

		NiObject*                 CreateClone(NiCloningProcess& a_cloneData) override;    // 1A
		void                      OnVisible(NiCullingProcess& a_culler) override;         // 39
		BSMergeInstancedTriShape* IsBSMergeInstancedTriShape() override { return this; }  // 3F
		std::uint32_t             GetRenderableTris(std::uint32_t a_LODMode) override;    // 41

		// members
		BSGraphics::StructuredBuffer* shapeDataBuffer;       // 170
		BSGraphics::ByteBuffer*       shapeIdLookupTable;    // 178
		std::byte                     pad180[0x10];          // 180
		std::uint32_t                 vertexStride;          // 190
		std::uint32_t                 trianglesPerSlot;      // 194
		std::byte                     pad198[0x8];           // 198
		std::uint32_t                 lodTriangleCounts[4];  // 1A0
	};
	static_assert(offsetof(BSMergeInstancedTriShape, shapeDataBuffer) == 0x170);
	static_assert(offsetof(BSMergeInstancedTriShape, vertexStride) == 0x190);
	static_assert(offsetof(BSMergeInstancedTriShape, lodTriangleCounts) == 0x1A0);
	static_assert(sizeof(BSMergeInstancedTriShape) == 0x1B0);
}
