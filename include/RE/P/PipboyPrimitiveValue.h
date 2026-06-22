#pragma once

#include "RE/P/PipboyValue.h"

namespace RE
{
	template <class T>
	class PipboyPrimitiveValue;  // Forward declaration for specialization **only**

	template <>
	class __declspec(novtable) PipboyPrimitiveValue<std::uint32_t> :
		public PipboyValue
	{
	public:
		static constexpr auto RTTI{ RTTI::PipboyPrimitiveValue_unsignedint_ };
		static constexpr auto VTABLE{ VTABLE::PipboyPrimitiveValue_unsignedint_ };

		PipboyPrimitiveValue(std::uint32_t a_value, PipboyValue* a_parent) :
			PipboyValue(a_parent), m_value(a_value)
		{}

		// override
		virtual void                    CleanDirtyToGame() override {}                                                                                              // 00
		virtual void                    Serialize([[maybe_unused]] Json::Value* a_json) override {}                                                                 // 01
		virtual void                    SerializeChanges([[maybe_unused]] BSBinarySerializer& a_serializer, [[maybe_unused]] bool a_fullSerialization) override {}  // 03
		virtual SERIALIZATION_DATA_TYPE GetType() override { return SERIALIZATION_DATA_TYPE::kUint32; }

		void ctor(std::uint32_t a_value, PipboyValue* a_parent)
		{
			using func_t = decltype(&PipboyPrimitiveValue<std::uint32_t>::ctor);
			static REL::Relocation<func_t> func{ ID::PipboyPrimitiveValue::uint32::ctor };
			func(this, a_value, a_parent);
		}

		operator std::uint32_t() const
		{
			return m_value;
		}

		// members
		std::uint32_t m_value;  // 0x18
	};
	static_assert(sizeof(PipboyPrimitiveValue<std::uint32_t>) == 0x20);

	template <>
	class __declspec(novtable) PipboyPrimitiveValue<bool> :
		public PipboyValue
	{
	public:
		static constexpr auto RTTI{ RTTI::PipboyPrimitiveValue_bool_ };
		static constexpr auto VTABLE{ VTABLE::PipboyPrimitiveValue_bool_ };

		PipboyPrimitiveValue(bool a_value, PipboyValue* a_parent) :
			PipboyValue(a_parent), m_value(a_value)
		{}

		// override
		virtual void                    CleanDirtyToGame() override {}                                                                                              // 00
		virtual void                    Serialize([[maybe_unused]] Json::Value* a_json) override {}                                                                 // 01
		virtual void                    SerializeChanges([[maybe_unused]] BSBinarySerializer& a_serializer, [[maybe_unused]] bool a_fullSerialization) override {}  // 03
		virtual SERIALIZATION_DATA_TYPE GetType() override { return SERIALIZATION_DATA_TYPE::kBool; }

		void ctor(bool a_value, PipboyValue* a_parent)
		{
			using func_t = decltype(&PipboyPrimitiveValue<bool>::ctor);
			static REL::Relocation<func_t> func{ ID::PipboyPrimitiveValue::boolean::ctor };
			func(this, a_value, a_parent);
		}

		operator bool() const
		{
			return m_value;
		}

		// members
		bool m_value;  // 0x18
	};
	static_assert(sizeof(PipboyPrimitiveValue<bool>) == 0x20);
}
