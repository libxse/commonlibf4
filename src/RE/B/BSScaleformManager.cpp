#include "RE/B/BSScaleformManager.h"

#include "RE/B/BSSystemFileStreamer.h"
#include "RE/I/IMenu.h"
#include "RE/S/Setting.h"
#include "Scaleform/G/GFx_Loader.h"
#include "Scaleform/G/GFx_MovieDef.h"
#include "Scaleform/P/Ptr.h"

namespace RE
{
	bool BSScaleformManager::LoadMovieEx(
		IMenu&           a_menu,
		std::string_view a_filePath,
		std::string_view a_menuObjPath,
		ScaleModeType    a_scaleMode,
		float            a_backgroundAlpha)
	{
		static REL::Relocation<SettingT<INISettingCollection>*> fileUncacheOnMenuOpen{ ID::BSScaleformManager::FileUncacheOnMenuOpen };
		if (fileUncacheOnMenuOpen && fileUncacheOnMenuOpen->GetBinary()) {
			BSSystemFileStreamer::UncacheAll(true);
		}

		REX::TEnumSet loadConstants{
			Scaleform::GFx::Loader::LoadConstants::kKeepBindData,
			Scaleform::GFx::Loader::LoadConstants::kWaitFrame1
		};

		const auto movieDef = Scaleform::Ptr{ loader->CreateMovie(a_filePath.data(), loadConstants.get()) };
		if (!movieDef) {
			return false;
		}
		movieDef->Release();

		auto& movie = a_menu.uiMovie;
		movie.reset(movieDef->CreateInstance(true));
		if (!movie) {
			return false;
		}
		movie->Release();

		movie->SetViewScaleMode(a_scaleMode);
		movie->SetBackgroundAlpha(a_backgroundAlpha);
		a_menu.DoAdvanceMovie(0.0);
		if (!a_menuObjPath.empty()) {
			a_menu.SetMenuCodeObject(*movie, a_menuObjPath);
		}
		a_menu.RefreshPlatform();
		InitMovieViewport(*movie, 1.0F, 1.0F);
		a_menu.OnSetSafeRect();

		return true;
	}
}
