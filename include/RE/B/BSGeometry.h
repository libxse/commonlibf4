#pragma once

#include "RE/B/BSGraphics.h"
#include "RE/N/NiAVObject.h"
#include "RE/N/NiPointer.h"

namespace RE
{
	namespace BSSkin
	{
		class Instance : public NiObject {};
	}

	class BSCombinedTriShape;
	class BSGeometrySegmentData;
	class BSMergeInstancedTriShape;
	class BSMultiIndexTriShape;
	class NiProperty;

	class __declspec(novtable) BSGeometry :
		public NiAVObject  // 000
	{
	public:
		static constexpr auto RTTI{ RTTI::BSGeometry };
		static constexpr auto VTABLE{ VTABLE::BSGeometry };
		static constexpr auto Ni_RTTI{ Ni_RTTI::BSGeometry };

		BSGeometry();
		virtual ~BSGeometry();  // NOLINT(modernize-use-override) 00

		// add
		virtual void                      UpdatePropertyControllers(NiUpdateData& a_data);  // 3A
		virtual BSGeometrySegmentData*    GetSegmentData();                                 // 3B
		virtual void                      SetSegmentData(BSGeometrySegmentData* a_data);    // 3C
		virtual BSGraphics::IndexBuffer*  GetCustomIndexBuffer();                           // 3D
		virtual BSCombinedTriShape*       IsBSCombinedTriShape();                           // 3E
		virtual BSMergeInstancedTriShape* IsBSMergeInstancedTriShape();                     // 3F
		virtual BSMultiIndexTriShape*     IsMultiIndexTriShape();                           // 40
		virtual std::uint32_t             GetRenderableTris(std::uint32_t a_LODMode);       // 40

		// members
		NiBound                     modelBound;     // 120
		NiPointer<NiProperty>       properties[2];  // 130
		NiPointer<BSSkin::Instance> skinInstance;   // 140
		void*                       rendererData;   // 148
		BSGraphics::VertexDesc      vertexDesc;     // 150
		std::uint8_t                type;           // 158
		bool                        registered;     // 159
	};
	static_assert(sizeof(BSGeometry) == 0x160);
}
