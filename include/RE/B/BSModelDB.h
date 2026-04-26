#pragma once

#include "RE/B/BSResource_ErrorCode.h"
#include "RE/N/NiPointer.h"

namespace RE
{
	enum class ENUM_LOD_MULT;
	class NiNode;

	class BSModelDB
	{
	public:
		using Handle = void*;

		class DBTraits
		{
		public:
			class ArgsType
			{
			public:
				// members
				REX::TEnumSet<ENUM_LOD_MULT, std::int32_t> lodFadeMult;          // 00
				std::uint32_t                              loadLevel;            // 04
				std::uint8_t                               prepareAfterLoad: 1;  // 08:00
				std::uint8_t                               faceGenModel: 1;      // 08:01
				std::uint8_t                               useErrorMarker: 1;    // 08:02
				std::uint8_t                               performProcess: 1;    // 08:03
				std::uint8_t                               createFadeNode: 1;    // 08:04
				std::uint8_t                               loadTextures: 1;      // 08:05
			};
			static_assert(sizeof(ArgsType) == 0x0C);
		};
		static_assert(std::is_empty_v<DBTraits>);

		class HandelListHead
		{
		public:
			class HandleList
			{
			public:
				// members
				Handle      handle;  // 00
				HandleList* next;    // 08
			};
			static_assert(sizeof(HandleList) == 0x10);

			// members
			HandleList* head;  // 00
		};
		static_assert(sizeof(HandelListHead) == 0x8);

		static BSResource::ErrorCode Demand(
			const char*               a_name,
			Handle&                   a_result,
			const DBTraits::ArgsType& a_args)
		{
			using func_t = BSResource::ErrorCode (*)(const char*, Handle&, const DBTraits::ArgsType&);
			static REL::Relocation<func_t> func{ ID::BSModelDB::Demand1 };
			return func(a_name, a_result, a_args);
		}

		static BSResource::ErrorCode Demand(
			const char*               a_name,
			NiPointer<NiNode>*        a_result,
			const DBTraits::ArgsType& a_args)
		{
			using func_t = BSResource::ErrorCode (*)(const char*, NiPointer<NiNode>*, const DBTraits::ArgsType&);
			static REL::Relocation<func_t> func{ ID::BSModelDB::Demand2 };
			return func(a_name, a_result, a_args);
		}
	};
}
