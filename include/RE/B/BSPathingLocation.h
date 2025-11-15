#pragma once

#include "RE/B/BSTArray.h"
#include "RE/B/BSTSmartPointer.h"
#include "RE/N/NiPoint.h"

namespace RE
{
	class BSNavmeshInfo;
	class BSPatchingCell;

	class BSPathingLocation
	{
	public:
		// members
		NiPoint3                              location;    // 00
		const BSNavmeshInfo*                  navMesh;     // 10
		const BSTArray<BSNavmeshInfo const*>* navMeshes;   // 18
		BSTSmartPointer<BSPathingCell>        cell;        // 20
		std::uint16_t                         triangle;    // 28
		std::uint8_t                          flags;       // 2A
		std::uint8_t                          clientData;  // 2B
	};
	static_assert(sizeof(BSPathingLocation) == 0x30);
}
