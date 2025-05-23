#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/B/BSTHashMap.h"
#include "RE/B/BSTSmartPointer.h"

namespace RE
{
	namespace BSScript
	{
		class ObjectTypeInfo;
		class StructTypeInfo;

		namespace Internal
		{
			class WritableTypeTable
			{
			public:
				// members
				BSTScrapHashMap<BSFixedString, BSTSmartPointer<ObjectTypeInfo>>* objectTypeMap;  // 00
				BSTScrapHashMap<BSFixedString, BSTSmartPointer<StructTypeInfo>>* structTypeMap;  // 08
			};
			static_assert(sizeof(WritableTypeTable) == 0x10);
		}
	}
}
