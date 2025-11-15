#pragma once

#include "RE/H/hkContainerHeapAllocator.h"

namespace RE
{
	template <class T>
	class hkMapOperations
	{
	public:
	};
	static_assert(std::is_empty_v<hkMapOperations<void>>);

	template <class T, class U, class Operations = hkMapOperations<T>>
	class hkMapBase
	{
	public:
		class Pair
		{
		public:
			// members
			T key;  // 00
			U val;  // ??
		};

		// members
		Pair*        elem;      // 00
		std::int32_t numElems;  // 08
		std::int32_t hashMod;   // 0C
	};
	static_assert(sizeof(hkMapBase<std::uint64_t, std::uint64_t>) == 0x10);

	template <class T, class U, class Operations = hkMapOperations<T>, class Allocator = hkContainerHeapAllocator>
	class hkMap :
		public hkMapBase<T, U, Operations>
	{
	public:
	};
	static_assert(sizeof(hkMap<std::uint64_t, std::uint64_t>) == 0x10);

	template <class T, class U, class Allocator = hkContainerHeapAllocator>
	class hkPointerMap
	{
	public:
		// members
		hkMap<std::uint64_t, std::uint64_t, hkMapOperations<std::uint64_t>, Allocator> map;  // 10
	};
	static_assert(sizeof(hkPointerMap<void*, void*>) == 0x10);

	template <class K>
	struct hkMultiMapOperations
	{};

	template <>
	struct hkMultiMapOperations<std::int32_t>
	{};

	template <class K, class V = K, class O = hkMultiMapOperations<K>, class A = hkContainerHeapAllocator>
	class hkMultiMap
	{
	public:
		struct Pair
		{
			// members
			K key;    // 00
			V value;  // ??
		};

		// members
		Pair*        elem;       // 00
		std::int32_t elemCount;  // 08 - high bits are flags
		std::int32_t hashMod;    // 10 - capacity - 1
	};
	static_assert(sizeof(hkMultiMap<int>) == 0x10);
}
