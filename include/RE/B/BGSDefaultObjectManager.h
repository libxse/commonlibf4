#pragma once

#include "RE/B/BSTSingleton.h"
#include "RE/D/DEFAULT_OBJECT.h"
#include "RE/T/TESForm.h"

namespace RE
{
	class __declspec(novtable) BGSDefaultObjectManager :
		public TESForm,                                       // 00
		public BSTSingletonImplicit<BGSDefaultObjectManager>  // 20
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSDefaultObjectManager };
		static constexpr auto VTABLE{ VTABLE::BGSDefaultObjectManager };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kDOBJ };

		[[nodiscard]] static BGSDefaultObjectManager* GetSingleton()
		{
			static REL::Relocation<BGSDefaultObjectManager*> singleton{ ID::BGSDefaultObjectManager::Singleton };
			return singleton.get();
		}

		[[nodiscard]] TESForm* GetDefaultObject(DEFAULT_OBJECT a_obj) const noexcept
		{
			assert(a_obj < DEFAULT_OBJECT::kTotal);
			return objectInitArray[std::to_underlying(a_obj)] ?
			           objectArray[std::to_underlying(a_obj)] :
			           nullptr;
		}

		template <class T>
		[[nodiscard]] T* GetDefaultObject(DEFAULT_OBJECT a_obj) const  //
			requires(std::derived_from<T, TESForm> &&
					 !std::is_pointer_v<T> &&
					 !std::is_reference_v<T>)
		{
			const auto obj = GetDefaultObject(a_obj);
			return obj ? obj->As<T>() : nullptr;
		}

		// members
		TESForm* objectArray[std::to_underlying(DEFAULT_OBJECT::kTotal)];      // 020
		bool     objectInitArray[std::to_underlying(DEFAULT_OBJECT::kTotal)];  // C70
	};
	static_assert(sizeof(BGSDefaultObjectManager) == 0xE00);
}
