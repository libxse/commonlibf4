#pragma once

namespace Scaleform::Render
{
	class LinearHeap;

	namespace ContextImpl
	{
		class Entry;

		class __declspec(novtable) EntryData
		{
		public:
			enum class EntryType : std::uint16_t
			{
				kBase,
				kRoot,
				kContainer,
				kShape,
				kMesh,
				kText
			};

			virtual ~EntryData();  // 00

			// add
			virtual EntryData* ConstructCopy(LinearHeap& a_heap) const = 0;  // 01
			virtual void       CopyTo(void* a_dest) const = 0;               // 02
			virtual void       ReleaseNodes() const {}                       // 03
			virtual void       Destroy() = 0;                                // 04
			virtual bool       PropagateUp(Entry* a_entry) const;            // 05

			// members
			REX::TEnumSet<EntryType, std::uint16_t> type;   // 08
			std::uint16_t                           flags;  // 0A
		};
		static_assert(sizeof(EntryData) == 0x10);
	}
}
