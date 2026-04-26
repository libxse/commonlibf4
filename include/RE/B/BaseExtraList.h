#pragma once

#include "RE/B/BSExtraData.h"

namespace RE
{
	class BaseExtraList
	{
	public:
		void AddExtra(BSExtraData* a_extra)
		{
			assert(a_extra != nullptr);
			assert(a_extra->next == nullptr);

			const auto type = a_extra->GetExtraType();
			assert(!HasType(type));

			if (!_head || !IsHighUseExtra(type)) {
				assert(_tail != nullptr);
				*_tail = a_extra;
				_tail = std::addressof(a_extra->next);
			} else {
				a_extra->next = _head;
				_head = a_extra;
			}

			MarkType(type, true);
		}

		[[nodiscard]] BSExtraData* GetByType(EXTRA_DATA_TYPE a_type) const noexcept
		{
			if (HasType(a_type)) {
				for (auto iter = _head; iter; iter = iter->next) {
					if (iter->GetExtraType() == a_type) {
						return iter;
					}
				}
			}

			return nullptr;
		}

		[[nodiscard]] bool HasType(EXTRA_DATA_TYPE a_type) const noexcept
		{
			assert(a_type < EXTRA_DATA_TYPE::kTotal);
			const auto idx = std::to_underlying(a_type) / 8;
			const auto flags = GetFlags();
			if (!flags.empty() && static_cast<std::size_t>(idx) < flags.size()) {
				const auto pos = static_cast<std::uint8_t>(1u << (std::to_underlying(a_type) % 8));
				return (flags[idx] & pos) != 0;
			} else {
				return false;
			}
		}

		std::unique_ptr<BSExtraData> RemoveExtra(EXTRA_DATA_TYPE a_type)
		{
			if (HasType(a_type)) {
				BSExtraData* prev = nullptr;
				for (auto iter = _head; iter; prev = iter, iter = iter->next) {
					if (iter->GetExtraType() == a_type) {
						if (prev) {
							prev->next = iter->next;
						} else {
							_head = iter->next;
						}

						if (!_tail || *_tail == iter) {
							_tail = std::addressof(prev ? prev->next : _head);
						}

						MarkType(a_type, false);
						return std::unique_ptr<BSExtraData>{ iter };
					}
				}
			}

			return nullptr;
		}

	private:
		static constexpr std::size_t N = (std::to_underlying(EXTRA_DATA_TYPE::kTotal) / 8) + 1;

		[[nodiscard]] static bool IsHighUseExtra(EXTRA_DATA_TYPE a_type) noexcept
		{
			return !((std::to_underlying(a_type) - 11) & ~0x22u) && a_type != EXTRA_DATA_TYPE::kLeveledCreature;
		}

		void CreateFlags() { _flags = calloc<std::uint8_t>(N); }

		[[nodiscard]] std::span<std::uint8_t> GetFlags() const noexcept
		{
			if (_flags) {
				return { _flags, N };
			} else {
				return {};
			}
		}

		[[nodiscard]] std::span<std::uint8_t, N> GetOrCreateFlags()
		{
			if (!_flags) {
				CreateFlags();
			}

			return std::span{ reinterpret_cast<std::uint8_t(&)[N]>(*_flags) };
		}

		void MarkType(EXTRA_DATA_TYPE a_type, bool a_set)
		{
			assert(a_type < EXTRA_DATA_TYPE::kTotal);
			const auto idx = std::to_underlying(a_type) / 8;
			const auto pos = static_cast<std::uint8_t>(1u << (std::to_underlying(a_type) % 8));
			const auto flags = GetOrCreateFlags();
			if (a_set) {
				flags[idx] |= pos;
			} else {
				flags[idx] &= ~pos;
			}
		}

		// members
		BSExtraData*  _head{ nullptr };                // 00
		BSExtraData** _tail{ std::addressof(_head) };  // 08
		std::uint8_t* _flags{ nullptr };               // 10
	};
	static_assert(sizeof(BaseExtraList) == 0x18);
}
