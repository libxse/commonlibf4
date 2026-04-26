#pragma once

#include "RE/A/ApplyColorUpdateEvent.h"
#include "RE/B/BSGFxDisplayObject.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTEvent.h"
#include "RE/H/HUDColorTypes.h"
#include "RE/U/UIShaderColors.h"
#include "RE/U/UIShaderFXInfo.h"

namespace RE
{
	class BSGFxShaderFXTarget :
		public BSGFxDisplayObject,                  // 00
		public BSTEventSink<ApplyColorUpdateEvent>  // 50
	{
	public:
		static constexpr auto RTTI{ RTTI::BSGFxShaderFXTarget };
		static constexpr auto VTABLE{ VTABLE::BSGFxShaderFXTarget };

		BSGFxShaderFXTarget(const Scaleform::GFx::Value& a_flashObject) :
			BSGFxDisplayObject(a_flashObject)
		{
			ctor_shared();
		}

		BSGFxShaderFXTarget(const Scaleform::GFx::Value& a_flashObject, const char* a_relativePathToMember) :
			BSGFxDisplayObject(a_flashObject, a_relativePathToMember)
		{
			ctor_shared();
		}

		BSGFxShaderFXTarget(const Scaleform::GFx::Movie& a_parentMovie, const char* a_pathToObject) :
			BSGFxDisplayObject(a_parentMovie, a_pathToObject)
		{
			ctor_shared();
		}

		virtual ~BSGFxShaderFXTarget()
		{
			if (auto source = ApplyColorUpdateEvent::GetEventSource()) {
				source->UnregisterSink(this);
			}
		}

		// override
		virtual BSEventNotifyControl ProcessEvent(const ApplyColorUpdateEvent& a_event, BSTEventSource<ApplyColorUpdateEvent>* a_source) override  // 01
		{
			using func_t = decltype(&BSGFxShaderFXTarget::ProcessEvent);
			static REL::Relocation<func_t> func{ ID::BSGFxShaderFXTarget::ProcessEvent };
			return func(this, a_event, a_source);
		}

		// add
		virtual void AppendShaderFXInfos(BSTArray<UIShaderFXInfo>& a_colorFXInfo, BSTArray<UIShaderFXInfo>& a_backgroundFXInfo)  // 02
		{
			using func_t = decltype(&BSGFxShaderFXTarget::AppendShaderFXInfos);
			static REL::Relocation<func_t> func{ ID::BSGFxShaderFXTarget::AppendShaderFXInfos };
			return func(this, a_colorFXInfo, a_backgroundFXInfo);
		}

		void CreateAndSetFiltersToColor(const NiColor& a_color, float a_brightness)
		{
			using func_t = void (BSGFxShaderFXTarget::*)(const NiColor&, float);
			static REL::Relocation<func_t> func{ ID::BSGFxShaderFXTarget::CreateAndSetFiltersToColor1 };
			func(this, a_color, a_brightness);
		}

		void CreateAndSetFiltersToColor(std::uint8_t a_r, std::uint8_t a_g, std::uint8_t a_b, float a_brightness)
		{
			using func_t = void (BSGFxShaderFXTarget::*)(std::uint8_t, std::uint8_t, std::uint8_t, float);
			static REL::Relocation<func_t> func{ ID::BSGFxShaderFXTarget::CreateAndSetFiltersToColor2 };
			func(this, a_r, a_g, a_b, a_brightness);
		}

		void CreateAndSetFiltersToHUD(HUDColorTypes a_colorType, float a_scale = 1.0)
		{
			using func_t = decltype(&BSGFxShaderFXTarget::CreateAndSetFiltersToHUD);
			static REL::Relocation<func_t> func{ ID::BSGFxShaderFXTarget::CreateAndSetFiltersToHUD };
			func(this, a_colorType, a_scale);
		}

		void EnableShadedBackground(HUDColorTypes a_colorType, float a_scale = 1.0)
		{
			using func_t = decltype(&BSGFxShaderFXTarget::EnableShadedBackground);
			static REL::Relocation<func_t> func{ ID::BSGFxShaderFXTarget::EnableShadedBackground };
			func(this, a_colorType, a_scale);
		}

		void SetToHUDColor(bool a_useWarningColor)
		{
			auto colorType = (a_useWarningColor) ? HUDColorTypes::kWarningColor : HUDColorTypes::kGameplayHUDColor;
			CreateAndSetFiltersToHUD(colorType, 1.0);
		}

		// members
		UIShaderColors                              shaderFX;             // 58
		BSTArray<BSGFxShaderFXTarget*>              shaderFXObjects;      // 90
		REX::TEnumSet<HUDColorTypes, std::uint32_t> HUDColorType;         // A8
		REX::TEnumSet<HUDColorTypes, std::uint32_t> backgroundColorType;  // AC

	private:
		void ctor_shared()
		{
			if (HasMember("bUseShadedBackground")) {
				Scaleform::GFx::Value bUseShadedBackground;
				if (GetMember("bUseShadedBackground", &bUseShadedBackground)) {
					if (bUseShadedBackground.IsBoolean()) {
						if (bUseShadedBackground.GetBoolean()) {
							EnableShadedBackground(HUDColorTypes::kMenuNoColorBackground);
						}
					}
				}
			}

			if (auto source = ApplyColorUpdateEvent::GetEventSource()) {
				source->RegisterSink(this);
			}
		}
	};
	static_assert(sizeof(BSGFxShaderFXTarget) == 0xB0);
}
