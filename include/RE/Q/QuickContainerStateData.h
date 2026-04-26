#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/B/BSPointerHandle.h"
#include "RE/B/BSTArray.h"
#include "RE/I/InventoryItemDisplayData.h"

namespace RE
{
	enum class QuickContainerMode;

	class QuickContainerStateData
	{
	public:
		// members
		BSTSmallArray<InventoryItemDisplayData, 5>      itemData;              // 00
		ObjectRefHandle                                 containerRef;          // 88
		ObjectRefHandle                                 inventoryRef;          // 8C
		BSFixedStringCS                                 aButtonText;           // 90
		BSFixedString                                   containerName;         // 98
		BSFixedStringCS                                 perkButtonText;        // A0
		std::int32_t                                    selectedClipIndex;     // A8
		REX::TEnumSet<QuickContainerMode, std::int32_t> mode;                  // AC
		bool                                            perkButtonEnabled;     // B0
		bool                                            isNewContainer;        // B1
		bool                                            addedDroppedItems;     // B2
		bool                                            isLocked;              // B3
		bool                                            buttonAEnabled;        // B4
		bool                                            buttonXEnabled;        // B5
		bool                                            refreshContainerSize;  // B6
		bool                                            containerActivated;    // B7
	};
	static_assert(sizeof(QuickContainerStateData) == 0xB8);
}
