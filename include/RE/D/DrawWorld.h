#pragma once

namespace RE
{
	class BSGeometryListCullingProcess;

	namespace DrawWorld
	{
		using UpdateWaterFunc = void (*)(BSGeometryListCullingProcess*);
		using RenderFunc = void (*)();

		[[nodiscard]] inline bool& GetEndOfFrameImagespaceEffectsEnabled()
		{
			static REL::Relocation<bool*> enabled{ ID::DrawWorld::EndOfFrameImagespaceEffectsEnabled };
			return *enabled;
		}

		[[nodiscard]] inline bool QTiledLighting()
		{
			using func_t = decltype(&QTiledLighting);
			static REL::Relocation<func_t> func{ ID::DrawWorld::QTiledLighting };
			return func();
		}

		inline void SetUpdateWaterFunc(UpdateWaterFunc a_func)
		{
			using func_t = decltype(&SetUpdateWaterFunc);
			static REL::Relocation<func_t> func{ ID::DrawWorld::SetUpdateWaterFunc };
			return func(a_func);
		}

		inline void SetCompanionLocalMapRenderFunc(RenderFunc a_func)
		{
			using func_t = decltype(&SetCompanionLocalMapRenderFunc);
			static REL::Relocation<func_t> func{ ID::DrawWorld::SetCompanionLocalMapRenderFunc };
			return func(a_func);
		}

		inline void Render_UI()
		{
			using func_t = decltype(&Render_UI);
			static REL::Relocation<func_t> func{ ID::DrawWorld::Render_UI };
			return func();
		}

		inline void Forward()
		{
			using func_t = decltype(&Forward);
			static REL::Relocation<func_t> func{ ID::DrawWorld::Forward };
			return func();
		}

		inline void DeferredPrePass()
		{
			using func_t = decltype(&DeferredPrePass);
			static REL::Relocation<func_t> func{ ID::DrawWorld::DeferredPrePass };
			return func();
		}

		inline void DeferredLightsImpl()
		{
			using func_t = decltype(&DeferredLightsImpl);
			static REL::Relocation<func_t> func{ ID::DrawWorld::DeferredLightsImpl };
			return func();
		}

		inline void DeferredComposite()
		{
			using func_t = decltype(&DeferredComposite);
			static REL::Relocation<func_t> func{ ID::DrawWorld::DeferredComposite };
			return func();
		}
	}
}
