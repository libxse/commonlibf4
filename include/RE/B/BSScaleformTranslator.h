#pragma once

#include "RE/B/BSResourceStreamParser.h"
#include "RE/B/BSStreamParser.h"
#include "RE/B/BSTranslator.h"
#include "RE/S/Setting.h"
#include "Scaleform/G/GFx_Translator.h"

namespace RE
{
	class __declspec(novtable) BSScaleformTranslator :
		public Scaleform::GFx::Translator
	{
	public:
		void AddTranslations(BSStreamParser<wchar_t>* a_parser)
		{
			using func_t = void (*)(BSScaleformTranslator*, BSStreamParser<wchar_t>*);
			static REL::Relocation<func_t> func{ ID::BSScaleformTranslator::AddTranslations };
			func(this, a_parser);
		}

		void AddTranslationsFile(const char* a_file)
		{
			BSResourceStreamParser  parserResource(a_file);
			BSStreamParser<wchar_t> parser(&parserResource);
			AddTranslations(&parser);
		}

		void AddTranslationsMod(const char* a_name)
		{
			const auto setting = GetINISetting("sLanguage:General");
			const auto language = setting ? setting->GetString() : "EN";
			const auto path = std::format("Interface\\Translations\\{}_{}.txt", a_name, language);
			AddTranslationsFile(path.c_str());
		}

		// members
		BSTranslator translator;  //20
	};
	static_assert(sizeof(BSScaleformTranslator) == 0x50);
}
