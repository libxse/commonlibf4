#include "RE/B/BSGraphics.h"

namespace RE
{
	namespace BSGraphics
	{
		TriShape* Renderer::CreateTriShape(std::uint32_t* a_dataSize, void* a_data, VertexDesc a_vertexDesc, IndexBuffer* a_indexBuffer)
		{
			using func_t = decltype(&BSGraphics::Renderer::CreateTriShape);
			static REL::Relocation<func_t> func{ ID::BSGraphics::Renderer::CreateTriShape };
			return func(this, a_dataSize, a_data, a_vertexDesc, a_indexBuffer);
		}

		VertexBuffer* Renderer::CreateVertexBuffer(std::uint32_t* a_dataSize, void* a_data, std::uint32_t a_stride)
		{
			using func_t = decltype(&BSGraphics::Renderer::CreateVertexBuffer);
			static REL::Relocation<func_t> func{ ID::BSGraphics::Renderer::CreateVertexBuffer };
			return func(this, a_dataSize, a_data, a_stride);
		}

		IndexBuffer* Renderer::CreateIndexBuffer(std::uint32_t a_indexCount, const std::uint16_t* a_indices)
		{
			using func_t = decltype(&BSGraphics::Renderer::CreateIndexBuffer);
			static REL::Relocation<func_t> func{ ID::BSGraphics::Renderer::CreateIndexBuffer };
			return func(this, a_indexCount, a_indices);
		}
	}
}
