#pragma once

#include "RE/A/ActorValue.h"
#include "RE/B/BGSLocalizedString.h"
#include "RE/B/BSStringT.h"
#include "RE/T/TESDescription.h"
#include "RE/T/TESForm.h"
#include "RE/T/TESFullName.h"

namespace RE
{
	class ActorValueOwner;

	class __declspec(novtable) ActorValueInfo :
		public TESForm,        // 000
		public TESFullName,    // 020
		public TESDescription  // 030
	{
	public:
		static constexpr auto RTTI{ RTTI::ActorValueInfo };
		static constexpr auto VTABLE{ VTABLE::ActorValueInfo };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kAVIF };

		using ModifiedCallback_t = void(Actor* a_actor, const ActorValueInfo& a_info, float a_originalValue, float a_delta, Actor* a_actorSource);
		using DerivationFunction_t = float(const ActorValueOwner* a_actor, const ActorValueInfo& a_info);

		// members
		std::function<ModifiedCallback_t>               modifiedCallback;          // 048
		BSString                                        formEditorID;              // 088
		ActorValueInfo*                                 dependentActorValues[15];  // 098
		std::function<DerivationFunction_t>             derivationFunction;        // 110
		const char*                                     enumNames[10];             // 150
		BGSLocalizedString                              abbreviation;              // 1A0
		std::int32_t                                    oldActorValue;             // 1A8
		REX::TEnumSet<ActorValue::Flags, std::int32_t>  flags;                     // 1AC
		REX::TEnumSet<ActorValue::AVType, std::int32_t> avType;                    // 1B0
		std::uint32_t                                   numDependentActorValues;   // 1B4
		std::uint32_t                                   enumCount;                 // 1B8
		std::int32_t                                    fullCacheIndex;            // 1BC
		std::int32_t                                    permanentCacheIndex;       // 1C0
		float                                           defaultValue;              // 1C4
		std::uint32_t                                   sortIndex;                 // 1C8
	};
	static_assert(sizeof(ActorValueInfo) == 0x1D0);
}
