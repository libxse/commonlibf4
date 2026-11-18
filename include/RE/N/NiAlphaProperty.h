#pragma once

#include "RE/N/NiProperty.h"
#include "RE/N/NiTFlags.h"

namespace RE
{
	class __declspec(novtable) NiAlphaProperty :
		public NiProperty  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::NiAlphaProperty };
		static constexpr auto VTABLE{ VTABLE::NiAlphaProperty };
		static constexpr auto Ni_RTTI{ Ni_RTTI::NiAlphaProperty };

		enum class AlphaFunction
		{
			kOne,
			kZero,
			kSrcColor,
			kInvSrcColor,
			kDestColor,
			kInvDestColor,
			kSrcAlpha,
			kInvSrcAlpha,
			kDestAlpha,
			kInvDestAlpha,
			kSrcAlphaTest
		};

		enum class TestFunction
		{
			kAlways,
			kLess,
			kEqual,
			kLessEqual,
			kGreater,
			kNotEqual,
			kGreaterEqual,
			kNever
		};

		NiAlphaProperty()
		{
			REX::EMPLACE_VTABLE(this);
			NiTFlags<std::uint16_t, NiProperty> f;
			f.flags = 0xEC;
			flags = f;
			alphaTestRef = 0;
		}
		virtual ~NiAlphaProperty();

		virtual std::int32_t Type()
		{
			return 0;
		}

		F4_HEAP_REDEFINE_ALIGNED_NEW(NiAlphaProperty);

		void SetDestBlendMode(AlphaFunction f)
		{
			using func_t = decltype(&NiAlphaProperty::SetDestBlendMode);
			static REL::Relocation<func_t> func{ ID::NiAlphaProperty::SetDestBlendMode };
			return func(this, f);
		}

		void SetSrcBlendMode(AlphaFunction f)
		{
			using func_t = decltype(&NiAlphaProperty::SetSrcBlendMode);
			static REL::Relocation<func_t> func{ ID::NiAlphaProperty::SetSrcBlendMode };
			return func(this, f);
		}

		void SetTestMode(TestFunction f)
		{
			using func_t = decltype(&NiAlphaProperty::SetTestMode);
			static REL::Relocation<func_t> func{ ID::NiAlphaProperty::SetTestMode, 0x20 };
			return func(this, f);
		}

		void SetAlphaBlending(bool b)
		{
			using func_t = decltype(&NiAlphaProperty::SetAlphaBlending);
			static REL::Relocation<func_t> func{ ID::NiAlphaProperty::SetAlphaBlending };
			return func(this, b);
		}

		void SetAlphaTesting(bool b)
		{
			using func_t = decltype(&NiAlphaProperty::SetAlphaTesting);
			static REL::Relocation<func_t> func{ ID::NiAlphaProperty::SetAlphaTesting, 0x20 };
			return func(this, b);
		}

		[[nodiscard]] bool GetAlphaBlending() const noexcept { return flags.flags & 0x1; }
		[[nodiscard]] bool GetAlphaTesting() const noexcept { return flags.flags & 0x200; }

		// members
		NiTFlags<std::uint16_t, NiProperty> flags;         // 28
		std::int8_t                         alphaTestRef;  // 2A
	};
	static_assert(sizeof(NiAlphaProperty) == 0x30);
}
