#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/B/BSScript_IComplexType.h"
#include "RE/B/BSScript_ObjectTypeInfo.h"
#include "RE/B/BSScript_TypeInfo.h"
#include "RE/B/BSScript_Variable.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTHashMap.h"
#include "RE/B/BSTSmartPointer.h"

namespace RE
{
	namespace BSScript
	{
		class ObjectTypeInfo;

		class __declspec(novtable) StructTypeInfo :
			public IComplexType  // 00
		{
		public:
			static constexpr auto RTTI{ RTTI::BSScript__StructTypeInfo };
			static constexpr auto VTABLE{ VTABLE::BSScript__StructTypeInfo };

			enum class LinkValidState
			{
				kNotLinked = 0x0,
				kCurrentlyLinking = 0x1,
				kLinkedInvalid = 0x2,
				kLinkedValid = 0x3
			};

			class StructVar
			{
			public:
				// members
				Variable      initialValue;  // 00
				TypeInfo      varType;       // 10
				BSFixedString docString;     // 18
				std::uint32_t userFlags;     // 20
				bool          isConst;       // 24
			};
			static_assert(sizeof(StructVar) == 0x28);

			const char* GetName() const
			{
				return name.c_str();
			}

			virtual TypeInfo::RawType GetRawType() const override;

			// members
			BSFixedString                               name;                   // 10
			BSTSmartPointer<ObjectTypeInfo>             containingObjTypeInfo;  // 18
			BSTArray<StructVar>                         variables;              // 20
			BSTHashMap<BSFixedString, std::uint32_t>    varNameIndexMap;        // 38
			REX::TEnumSet<LinkValidState, std::int32_t> linkedValid;            // 68
		};
		static_assert(sizeof(StructTypeInfo) == 0x70);
	}
}
