#pragma once

namespace RE
{
	template <class T>
	class hkPadSpu
	{
	public:
		void operator=(T val) { storage = val; }
		T    val() const { return storage; }
		T&   operator*() const { return &storage; }
		T*   operator->() const { return &storage; }

		// members
		T storage;  // 00
	};
	static_assert(sizeof(hkPadSpu<void*>) == 0x08);
}
