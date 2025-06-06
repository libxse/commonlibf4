#pragma once

namespace Scaleform
{
	template <class T>
	class Ptr
	{
	public:
		using element_type = T;

		// 1
		constexpr Ptr() noexcept = default;

		// 2
		constexpr Ptr(std::nullptr_t) noexcept {}

		// 3
		template <
			class Y,
			std::enable_if_t<
				std::is_convertible_v<
					Y*,
					element_type*>,
				int> = 0>
		explicit Ptr(Y* a_rhs) :
			_ptr(a_rhs)
		{
			TryAttach();
		}

		// 9a
		Ptr(const Ptr& a_rhs) :
			_ptr(a_rhs._ptr)
		{
			TryAttach();
		}

		// 9b
		template <
			class Y,
			std::enable_if_t<
				std::is_convertible_v<
					Y*,
					element_type*>,
				int> = 0>
		Ptr(const Ptr<Y>& a_rhs) :
			_ptr(a_rhs._ptr)
		{
			TryAttach();
		}

		// 10a
		Ptr(Ptr&& a_rhs) noexcept :
			_ptr(a_rhs._ptr)
		{
			a_rhs._ptr = nullptr;
		}

		// 10b
		template <
			class Y,
			std::enable_if_t<
				std::is_convertible_v<
					Y*,
					element_type*>,
				int> = 0>
		Ptr(Ptr<Y>&& a_rhs) noexcept :
			_ptr(a_rhs._ptr)
		{
			a_rhs._ptr = nullptr;
		}

		~Ptr() { TryDetach(); }

		// 1a
		Ptr& operator=(const Ptr& a_rhs)
		{
			if (this != std::addressof(a_rhs)) {
				TryDetach();
				_ptr = a_rhs._ptr;
				TryAttach();
			}
			return *this;
		}

		// 1b
		template <
			class Y,
			std::enable_if_t<
				std::is_convertible_v<
					Y*,
					element_type*>,
				int> = 0>
		Ptr& operator=(const Ptr<Y>& a_rhs)
		{
			TryDetach();
			_ptr = a_rhs._ptr;
			TryAttach();
			return *this;
		}

		// 2a
		Ptr& operator=(Ptr&& a_rhs)
		{
			if (this != std::addressof(a_rhs)) {
				TryDetach();
				_ptr = a_rhs._ptr;
				a_rhs._ptr = nullptr;
			}
			return *this;
		}

		// 2b
		template <
			class Y,
			std::enable_if_t<
				std::is_convertible_v<
					Y*,
					element_type*>,
				int> = 0>
		Ptr& operator=(Ptr<Y>&& a_rhs)
		{
			TryDetach();
			_ptr = a_rhs._ptr;
			a_rhs._ptr = nullptr;
			return *this;
		}

		void reset() { TryDetach(); }

		template <
			class Y,
			std::enable_if_t<
				std::is_convertible_v<
					Y*,
					element_type*>,
				int> = 0>
		void reset(Y* a_ptr)
		{
			if (_ptr != a_ptr) {
				TryDetach();
				_ptr = a_ptr;
				TryAttach();
			}
		}

		[[nodiscard]] constexpr element_type* get() const noexcept
		{
			return _ptr;
		}

		[[nodiscard]] explicit constexpr operator bool() const noexcept
		{
			return static_cast<bool>(_ptr);
		}

		[[nodiscard]] constexpr element_type& operator*() const noexcept
		{
			assert(static_cast<bool>(*this));
			return *_ptr;
		}

		[[nodiscard]] constexpr element_type* operator->() const noexcept
		{
			assert(static_cast<bool>(*this));
			return _ptr;
		}

	protected:
		template <class>
		friend class Ptr;

		void TryAttach()
		{
			if (_ptr) {
				_ptr->AddRef();
			}
		}

		void TryDetach()
		{
			if (_ptr) {
				_ptr->Release();
				_ptr = nullptr;
			}
		}

		// members
		element_type* _ptr{ nullptr };  // 0
	};
	static_assert(sizeof(Ptr<void*>) == 0x8);

	template <class T, class... Args>
	[[nodiscard]] Ptr<T> make_shared(Args&&... a_args)
	{
		auto ptr = Ptr<T>{ new T(std::forward<Args>(a_args)...) };
		if (ptr) {
			ptr->Release();  // ensure lifetime ends with smart pointer
		}
		return ptr;
	}

	template <class T1, class T2>
	[[nodiscard]] constexpr bool operator==(const Ptr<T1>& a_lhs, const Ptr<T2>& a_rhs)
	{
		return a_lhs.get() == a_rhs.get();
	}

	template <class T1, class T2>
	[[nodiscard]] constexpr bool operator!=(const Ptr<T1>& a_lhs, const Ptr<T2>& a_rhs)
	{
		return !(a_lhs == a_rhs);
	}

	template <class T>
	[[nodiscard]] constexpr bool operator==(const Ptr<T>& a_lhs, std::nullptr_t) noexcept
	{
		return !a_lhs;
	}

	template <class T>
	[[nodiscard]] constexpr bool operator==(std::nullptr_t, const Ptr<T>& a_rhs) noexcept
	{
		return !a_rhs;
	}

	template <class T>
	[[nodiscard]] constexpr bool operator!=(const Ptr<T>& a_lhs, std::nullptr_t) noexcept
	{
		return static_cast<bool>(a_lhs);
	}

	template <class T>
	[[nodiscard]] constexpr bool operator!=(std::nullptr_t, const Ptr<T>& a_rhs) noexcept
	{
		return static_cast<bool>(a_rhs);
	}

	template <class T>
	Ptr(T*) -> Ptr<T>;
}
