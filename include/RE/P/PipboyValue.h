#pragma once

namespace Json
{
	class Value;
}

namespace RE
{
	class BSBinarySerializer;

	class __declspec(novtable) PipboyValue
	{
	public:
		static constexpr auto RTTI{ RTTI::PipboyValue };
		static constexpr auto VTABLE{ VTABLE::PipboyValue };

		enum SERIALIZATION_DATA_TYPE : std::uint8_t
		{
			kBool = 0x0,
			kInt8 = 0x1,
			kUint8 = 0x2,
			kInt32 = 0x3,
			kUint32 = 0x4,
			kFloat = 0x5,
			kString = 0x6,
			kArray = 0x7,
			kObject = 0x8,
		};

		PipboyValue(PipboyValue* a_parent)
		{
			ctor(a_parent);
		};

		virtual ~PipboyValue() = default;  // 00

		// add
		virtual void                    CleanDirtyToGame();                                                        // 01
		virtual void                    Serialize(Json::Value* a_json) = 0;                                        // 02
		virtual void                    SerializeChanges(BSBinarySerializer& a_serializer, bool a_fullSerialize);  // 03
		virtual SERIALIZATION_DATA_TYPE GetType() = 0;                                                             // 04

		void ctor(PipboyValue* a_parent)
		{
			using func_t = decltype(&PipboyValue::ctor);
			static REL::Relocation<func_t> func{ ID::PipboyValue::ctor };
			func(this, a_parent);
		}

		// members
		std::uint32_t m_id;                  // 0x08
		bool          m_isDirtyGame;         // 0x0C
		bool          m_isDirtyToCompanion;  // 0x0D
		PipboyValue*  m_parent;              // 0x10
	};
	static_assert(sizeof(PipboyValue) == 0x18);
}
