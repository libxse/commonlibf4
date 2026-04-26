#pragma once

#include "Scaleform/F/Flags.h"
#include "Scaleform/N/NewOverrideBase.h"
#include "Scaleform/R/Render_EdgeAAMode.h"
#include "Scaleform/R/Render_Matrix.h"

namespace Scaleform::GFx
{
	class Movie;
	class MovieImpl;

	class Value
	{
	public:
		enum class ValueType : std::int32_t
		{
			kUndefined,
			kNull,
			kBoolean,
			kInt,
			kUInt,
			kNumber,
			kString,

			kStringW,

			kObject,
			kArray,
			kDisplayObject,
			kClosure,

			kOrphanedBit = 1 << 5,
			kManagedBit = 1 << 6,
			kConvertBit = 1 << 7,

			kTypeMask = kConvertBit | 0x0F,

			kConvertBoolean = kConvertBit | kBoolean,
			kConvertInt = kConvertBit | kInt,
			kConvertUInt = kConvertBit | kUInt,
			kConvertNumber = kConvertBit | kNumber,
			kConvertString = kConvertBit | kString,
			kConvertStringW = kConvertBit | kStringW
		};

		union ValueUnion
		{
			ValueUnion() noexcept :
				data(nullptr)
			{}

			ValueUnion(const ValueUnion& a_rhs) noexcept :
				data(a_rhs.data)
			{}

			ValueUnion(ValueUnion&& a_rhs) noexcept :
				data(a_rhs.data)
			{
				a_rhs.data = nullptr;
			}

			explicit ValueUnion(std::int32_t a_rhs) noexcept :
				int32(a_rhs)
			{}

			explicit ValueUnion(std::uint32_t a_rhs) noexcept :
				uint32(a_rhs)
			{}

			explicit ValueUnion(double a_rhs) noexcept :
				number(a_rhs)
			{}

			explicit ValueUnion(bool a_rhs) noexcept :
				boolean(a_rhs)
			{}

			explicit ValueUnion(const char* a_rhs) noexcept :
				string(a_rhs)
			{}

			explicit ValueUnion(const wchar_t* a_rhs) noexcept :
				wstring(a_rhs)
			{}

			ValueUnion& operator=(const ValueUnion& a_rhs) noexcept
			{
				if (this != std::addressof(a_rhs)) {
					data = a_rhs.data;
				}
				return *this;
			}

			ValueUnion& operator=(ValueUnion&& a_rhs) noexcept
			{
				if (this != std::addressof(a_rhs)) {
					data = a_rhs.data;
					a_rhs.data = nullptr;
				}
				return *this;
			}

			ValueUnion& operator=(std::int32_t a_rhs) noexcept
			{
				int32 = a_rhs;
				return *this;
			}

			ValueUnion& operator=(std::uint32_t a_rhs) noexcept
			{
				uint32 = a_rhs;
				return *this;
			}

			ValueUnion& operator=(double a_rhs) noexcept
			{
				number = a_rhs;
				return *this;
			}

			ValueUnion& operator=(bool a_rhs) noexcept
			{
				boolean = a_rhs;
				return *this;
			}

			ValueUnion& operator=(const char* a_rhs) noexcept
			{
				string = a_rhs;
				return *this;
			}

			ValueUnion& operator=(const wchar_t* a_rhs) noexcept
			{
				wstring = a_rhs;
				return *this;
			}

			std::int32_t   int32;
			std::uint32_t  uint32;
			double         number;
			bool           boolean;
			const char*    string;
			const char**   mstring;
			const wchar_t* wstring;
			void*          data;
		};
		static_assert(sizeof(ValueUnion) == 0x8);

		class DisplayInfo
		{
		public:
			enum class SetFlags : std::uint16_t
			{
				kX = 0x01,
				kY = 0x02,
				kRotation = 0x04,
				kXScale = 0x08,
				kYScale = 0x10,
				kAlpha = 0x20,
				kVisible = 0x40,
				kZ = 0x80,
				kXRotation = 0x100,
				kYRotation = 0x200,
				kZScale = 0x400,
				kFOV = 0x800,
				kProjMatrix3D = 0x1000,
				kViewMatrix3D = 0x2000,
				kEdgeAAMode = 0x4000,
			};

			DisplayInfo() = default;

			double GetX() const
			{
				assert(varsSet.any(SetFlags::kX));
				return x;
			}

			double GetY() const
			{
				assert(varsSet.any(SetFlags::kY));
				return y;
			}

			double GetZ() const
			{
				assert(varsSet.any(SetFlags::kZ));
				return z;
			}

			double GetXScale() const
			{
				assert(varsSet.any(SetFlags::kXScale));
				return xScale;
			}

			double GetYScale() const
			{
				assert(varsSet.any(SetFlags::kYScale));
				return yScale;
			}

			double GetZScale() const
			{
				assert(varsSet.any(SetFlags::kZScale));
				return zScale;
			}

			double GetRotation() const
			{
				assert(varsSet.any(SetFlags::kRotation));
				return rotation;
			}

			double GetXRotation() const
			{
				assert(varsSet.any(SetFlags::kXRotation));
				return xRotation;
			}

			double GetYRotation() const
			{
				assert(varsSet.any(SetFlags::kYRotation));
				return yRotation;
			}

			double GetAlpha() const
			{
				assert(varsSet.any(SetFlags::kAlpha));
				return alpha;
			}

			bool GetVisible() const
			{
				assert(varsSet.any(SetFlags::kVisible));
				return visible;
			}

			double GetFOV() const
			{
				assert(varsSet.any(SetFlags::kFOV));
				return fov;
			}

			const Render::Matrix3x4<float>* GetViewMatrix3D() const
			{
				return varsSet.any(SetFlags::kViewMatrix3D) ? &viewMatrix3D : nullptr;
			}

			const Render::Matrix4x4<float>* GetProjectionMatrix3D() const
			{
				return varsSet.any(SetFlags::kProjMatrix3D) ? &projectionMatrix3D : nullptr;
			}

			Render::EdgeAAMode GetEdgeAAMode() const
			{
				assert(varsSet.any(SetFlags::kEdgeAAMode));
				return edgeAAMode;
			}

			void SetX(double a_x)
			{
				varsSet.set(SetFlags::kX);
				x = a_x;
			}

			void SetY(double a_y)
			{
				varsSet.set(SetFlags::kY);
				y = a_y;
			}

			void SetZ(double a_z)
			{
				varsSet.set(SetFlags::kZ);
				z = a_z;
			}

			void SetXScale(double a_xScale)
			{
				varsSet.set(SetFlags::kXScale);
				xScale = a_xScale;
			}

			void SetYScale(double a_yScale)
			{
				varsSet.set(SetFlags::kYScale);
				yScale = a_yScale;
			}

			void SetZScale(double a_zScale)
			{
				varsSet.set(SetFlags::kZScale);
				zScale = a_zScale;
			}

			void SetRotation(double a_rotation)
			{
				varsSet.set(SetFlags::kRotation);
				rotation = a_rotation;
			}

			void SetXRotation(double a_xRotation)
			{
				varsSet.set(SetFlags::kXRotation);
				xRotation = a_xRotation;
			}

			void SetYRotation(double a_yRotation)
			{
				varsSet.set(SetFlags::kYRotation);
				yRotation = a_yRotation;
			}

			void SetAlpha(double a_alpha)
			{
				varsSet.set(SetFlags::kAlpha);
				alpha = a_alpha;
			}

			void SetVisible(bool a_visible)
			{
				varsSet.set(SetFlags::kVisible);
				visible = a_visible;
			}

			void SetFOV(double a_fov)
			{
				varsSet.set(SetFlags::kFOV);
				fov = a_fov;
			}

			void SetViewMatrix3D(const Render::Matrix3x4<float>* a_matrix)
			{
				if (a_matrix) {
					varsSet.set(SetFlags::kViewMatrix3D);
					viewMatrix3D = *a_matrix;
				} else {
					varsSet.reset(SetFlags::kViewMatrix3D);
				}
			}

			void SetProjectionMatrix3D(const Render::Matrix4x4<float>* a_matrix)
			{
				if (a_matrix) {
					varsSet.set(SetFlags::kProjMatrix3D);
					projectionMatrix3D = *a_matrix;
				} else {
					varsSet.reset(SetFlags::kProjMatrix3D);
				}
			}

			void SetEdgeAAMode(Render::EdgeAAMode a_mode)
			{
				varsSet.set(SetFlags::kEdgeAAMode);
				edgeAAMode = a_mode;
			}

		private:
			// members
			double x;
			double y;
			double rotation;
			double xScale;
			double yScale;
			double alpha;
			double z;
			double xRotation;
			double yRotation;
			double zScale;
			double fov;
			alignas(16) Render::Matrix3x4<float> viewMatrix3D;
			Render::Matrix4x4<float> projectionMatrix3D;
			Render::EdgeAAMode       edgeAAMode;
			Flags<SetFlags>          varsSet{};
			bool                     visible;
		};
		static_assert(sizeof(DisplayInfo) == 0xE0);

		class __declspec(novtable) ObjectInterface :
			public NewOverrideBase<327>
		{
		public:
			class __declspec(novtable) ObjVisitor
			{
			public:
				virtual ~ObjVisitor() = default;  // 00

				// add
				virtual bool IncludeAS3PublicMembers() const { return false; }   // 01
				virtual void Visit(const char* a_name, const Value& a_val) = 0;  // 02
			};
			static_assert(sizeof(ObjVisitor) == 0x8);

			class __declspec(novtable) ArrVisitor
			{
			public:
				virtual ~ArrVisitor() = default;

				// add
				virtual void Visit(std::uint32_t a_idx, const Value& a_val) = 0;  // 00
			};
			static_assert(sizeof(ArrVisitor) == 0x8);

			virtual ~ObjectInterface() = default;  // 00

			void ObjectAddRef(Value* a_val, void* a_obj)
			{
				using func_t = decltype(&ObjectInterface::ObjectAddRef);
				static REL::Relocation<func_t> func{ ID::GFx::Value::ObjectAddRef };
				return func(this, a_val, a_obj);
			}

			void ObjectRelease(Value* a_val, void* a_obj)
			{
				using func_t = decltype(&ObjectInterface::ObjectRelease);
				static REL::Relocation<func_t> func{ ID::GFx::Value::ObjectRelease };
				return func(this, a_val, a_obj);
			}

			bool HasMember(void* a_data, const char* a_name, bool a_isdobj) const
			{
				using func_t = decltype(&ObjectInterface::HasMember);
				static REL::Relocation<func_t> func{ ID::GFx::Value::HasMember };
				return func(this, a_data, a_name, a_isdobj);
			}

			std::uint32_t GetArraySize(void* a_data) const
			{
				using func_t = decltype(&ObjectInterface::GetArraySize);
				static REL::Relocation<func_t> func{ ID::GFx::Value::GetArraySize };
				return func(this, a_data);
			}

			bool GetMember(void* a_data, const char* a_name, Value* a_val, bool a_isdobj) const
			{
				using func_t = decltype(&ObjectInterface::GetMember);
				static REL::Relocation<func_t> func{ ID::GFx::Value::GetMember };
				return func(this, a_data, a_name, a_val, a_isdobj);
			}

			bool GetElement(void* a_data, std::uint32_t a_idx, Value* a_val) const
			{
				using func_t = decltype(&ObjectInterface::GetElement);
				static REL::Relocation<func_t> func{ ID::GFx::Value::GetElement };
				return func(this, a_data, a_idx, a_val);
			}

			bool SetElement(void* a_data, std::uint32_t a_idx, const Value& a_val)
			{
				using func_t = decltype(&ObjectInterface::SetElement);
				static REL::Relocation<func_t> func{ ID::GFx::Value::SetElement };
				return func(this, a_data, a_idx, a_val);
			}

			bool SetMember(void* a_data, const char* a_name, const Value& a_value, bool a_isdobj)
			{
				using func_t = decltype(&ObjectInterface::SetMember);
				static REL::Relocation<func_t> func{ ID::GFx::Value::SetMember };
				return func(this, a_data, a_name, a_value, a_isdobj);
			}

			bool Invoke(void* a_data, Value* a_result, const char* a_name, const Value* a_args, std::size_t a_numArgs, bool a_isdobj)
			{
				using func_t = decltype(&ObjectInterface::Invoke);
				static REL::Relocation<func_t> func{ ID::GFx::Value::Invoke };
				return func(this, a_data, a_result, a_name, a_args, a_numArgs, a_isdobj);
			}

			bool PushBack(void* a_data, const Value& a_value)
			{
				using func_t = decltype(&ObjectInterface::PushBack);
				static REL::Relocation<func_t> func{ ID::GFx::Value::PushBack };
				return func(this, a_data, a_value);
			}

			bool RemoveElements(void* a_data, std::uint32_t a_idx, std::int32_t a_count)
			{
				using func_t = decltype(&ObjectInterface::RemoveElements);
				static REL::Relocation<func_t> func{ ID::GFx::Value::RemoveElements };
				return func(this, a_data, a_idx, a_count);
			}

			void VisitMembers(void* a_data, ObjVisitor* a_visitor, bool a_isDObj) const
			{
				using func_t = decltype(&ObjectInterface::VisitMembers);
				static REL::Relocation<func_t> func{ ID::GFx::Value::VisitMembers };
				return func(this, a_data, a_visitor, a_isDObj);
			}

			bool GetDisplayInfo(void* a_data, DisplayInfo* a_info) const
			{
				using func_t = decltype(&ObjectInterface::GetDisplayInfo);
				static REL::Relocation<func_t> func{ ID::GFx::Value::GetDisplayInfo };
				return func(this, a_data, a_info);
			}

			// members
			MovieImpl* movieRoot;  // 08
		};
		static_assert(sizeof(ObjectInterface) == 0x10);

		using ObjectVisitor = ObjectInterface::ObjVisitor;
		using ArrayVisitor = ObjectInterface::ArrVisitor;
		using ObjectVisitFn = std::function<void(const char*, const Value&)>;

		Value() noexcept = default;

		Value(const Value& a_rhs) :
			_type(a_rhs._type),
			_value(a_rhs._value),
			_dataAux(a_rhs._dataAux)
		{
			if (a_rhs.IsManagedValue()) {
				AcquireManagedValue(a_rhs);
			}
		}

		Value(Value&& a_rhs) noexcept :
			_objectInterface(a_rhs._objectInterface),
			_type(a_rhs._type),
			_value(std::move(a_rhs._value)),
			_dataAux(a_rhs._dataAux)
		{
			a_rhs._objectInterface = nullptr;
			a_rhs._type = ValueType::kUndefined;
			a_rhs._dataAux = 0;
		}

		Value(std::nullptr_t) noexcept :
			_type(ValueType::kNull)
		{}

		Value(std::int32_t a_rhs) noexcept :
			_type(ValueType::kInt),
			_value(a_rhs)
		{}

		Value(std::uint32_t a_rhs) noexcept :
			_type(ValueType::kUInt),
			_value(a_rhs)
		{}

		Value(double a_rhs) noexcept :
			_type(ValueType::kNumber),
			_value(a_rhs)
		{}

		Value(bool a_rhs) noexcept :
			_type(ValueType::kBoolean),
			_value(a_rhs)
		{}

		Value(const char* a_rhs) noexcept :
			_type(ValueType::kString),
			_value(a_rhs)
		{}

		Value(std::string_view a_rhs) noexcept :
			_type(ValueType::kString),
			_value(a_rhs.data())
		{}

		Value(const wchar_t* a_rhs) noexcept :
			_type(ValueType::kStringW),
			_value(a_rhs)
		{}

		Value(std::wstring_view a_rhs) noexcept :
			_type(ValueType::kStringW),
			_value(a_rhs.data())
		{}

		~Value()
		{
			if (IsManagedValue()) {
				ReleaseManagedValue();
			}

			_type = ValueType::kUndefined;
		}

		Value& operator=(const Value& a_rhs)
		{
			if (this != std::addressof(a_rhs)) {
				if (IsManagedValue()) {
					ReleaseManagedValue();
				}

				_type = a_rhs._type;
				_value = a_rhs._value;
				_dataAux = a_rhs._dataAux;

				if (a_rhs.IsManagedValue()) {
					AcquireManagedValue(a_rhs);
				}
			}
			return *this;
		}

		Value& operator=(Value&& a_rhs)
		{
			if (this != std::addressof(a_rhs)) {
				if (IsManagedValue()) {
					ReleaseManagedValue();
				}

				_objectInterface = a_rhs._objectInterface;
				a_rhs._objectInterface = nullptr;

				_type = a_rhs._type;
				a_rhs._type = ValueType::kUndefined;

				_value = std::move(a_rhs._value);

				_dataAux = a_rhs._dataAux;
				a_rhs._dataAux = 0;
			}
			return *this;
		}

		Value& operator=(std::nullptr_t) noexcept
		{
			if (IsManagedValue()) {
				ReleaseManagedValue();
			}

			_type = ValueType::kNull;
			return *this;
		}

		Value& operator=(std::int32_t a_rhs) noexcept
		{
			if (IsManagedValue()) {
				ReleaseManagedValue();
			}

			_type = ValueType::kInt;
			_value = a_rhs;
			return *this;
		}

		Value& operator=(std::uint32_t a_rhs) noexcept
		{
			if (IsManagedValue()) {
				ReleaseManagedValue();
			}

			_type = ValueType::kUInt;
			_value = a_rhs;
			return *this;
		}

		Value& operator=(double a_rhs) noexcept
		{
			if (IsManagedValue()) {
				ReleaseManagedValue();
			}

			_type = ValueType::kNumber;
			_value = a_rhs;
			return *this;
		}

		Value& operator=(bool a_rhs) noexcept
		{
			if (IsManagedValue()) {
				ReleaseManagedValue();
			}

			_type = ValueType::kBoolean;
			_value = a_rhs;
			return *this;
		}

		Value& operator=(const char* a_rhs) noexcept
		{
			if (IsManagedValue()) {
				ReleaseManagedValue();
			}

			_type = ValueType::kString;
			_value = a_rhs;
			return *this;
		}

		Value& operator=(const wchar_t* a_rhs) noexcept
		{
			if (IsManagedValue()) {
				ReleaseManagedValue();
			}

			_type = ValueType::kStringW;
			_value = a_rhs;
			return *this;
		}

		[[nodiscard]] ValueType GetType() const noexcept { return *(_type & ValueType::kTypeMask); }

		[[nodiscard]] bool IsArray() const noexcept { return GetType() == ValueType::kArray; }
		[[nodiscard]] bool IsBoolean() const noexcept { return GetType() == ValueType::kBoolean; }
		[[nodiscard]] bool IsDisplayObject() const noexcept { return GetType() == ValueType::kDisplayObject; }
		[[nodiscard]] bool IsInt() const noexcept { return GetType() == ValueType::kInt; }
		[[nodiscard]] bool IsNumber() const noexcept { return GetType() == ValueType::kNumber; }
		[[nodiscard]] bool IsString() const noexcept { return GetType() == ValueType::kString; }
		[[nodiscard]] bool IsUndefined() const noexcept { return GetType() == ValueType::kUndefined; }
		[[nodiscard]] bool IsUInt() const noexcept { return GetType() == ValueType::kUInt; }

		[[nodiscard]] bool IsObject() const noexcept
		{
			switch (GetType()) {
				case ValueType::kObject:
				case ValueType::kArray:
				case ValueType::kDisplayObject:
					return true;
				default:
					return false;
			}
		}

		[[nodiscard]] bool GetBoolean() const
		{
			assert(IsBoolean());
			return _value.boolean;
		}

		[[nodiscard]] std::int32_t GetInt() const
		{
			assert(IsInt());
			return _value.int32;
		}

		[[nodiscard]] double GetNumber() const
		{
			assert(IsNumber());
			return _value.number;
		}

		[[nodiscard]] const char* GetString() const
		{
			assert(IsString());
			return IsManagedValue() ? *_value.mstring : _value.string;
		}

		[[nodiscard]] std::uint32_t GetUInt() const
		{
			assert(IsUInt());
			return _value.uint32;
		}

		bool HasMember(std::string_view a_name) const
		{
			assert(IsObject());
			return _objectInterface->HasMember(_value.data, a_name.data(), IsDisplayObject());
		}

		void VisitMembers(ObjectVisitor* a_visitor) const
		{
			assert(IsObject());
			return _objectInterface->VisitMembers(_value.data, a_visitor, IsDisplayObject());
		}

		void VisitMembers(ObjectVisitFn&& a_visitor) const
		{
			assert(IsObject());

			class MemberVisitor :
				public ObjectInterface::ObjVisitor
			{
			public:
				MemberVisitor(ObjectVisitFn&& a_fn) :
					_fn(a_fn) {}

				void Visit(const char* a_name, const Value& a_val) override
				{
					if (_fn) {
						_fn(a_name, a_val);
					}
				}

			private:
				ObjectVisitFn _fn;
			};

			MemberVisitor visitor{ std::forward<ObjectVisitFn>(a_visitor) };
			return _objectInterface->VisitMembers(_value.data, std::addressof(visitor), IsDisplayObject());
		}

		std::uint32_t GetArraySize() const
		{
			assert(IsArray());
			return _objectInterface->GetArraySize(_value.data);
		}

		bool GetElement(std::uint32_t a_idx, Value* a_val) const
		{
			assert(IsArray());
			return _objectInterface->GetElement(_value.data, a_idx, a_val);
		}

		bool SetElement(std::uint32_t a_idx, const Value& a_val)
		{
			assert(IsArray());
			return _objectInterface->SetElement(_value.data, a_idx, a_val);
		}

		bool GetMember(std::string_view a_name, Value* a_val) const
		{
			assert(IsObject());
			return _objectInterface->GetMember(_value.data, a_name.data(), a_val, IsDisplayObject());
		}

		bool SetMember(std::string_view a_name, const Value& a_val)
		{
			assert(IsObject());
			return _objectInterface->SetMember(_value.data, a_name.data(), a_val, IsDisplayObject());
		}

		bool Invoke(const char* a_name, Value* a_result, const Value* a_args, std::size_t a_numArgs)
		{
			assert(IsObject());
			return _objectInterface->Invoke(_value.data, a_result, a_name, a_args, a_numArgs, IsDisplayObject());
		}

		bool Invoke(const char* a_name, Value* a_result = nullptr)
		{
			return Invoke(a_name, a_result, nullptr, 0);
		}

		template <std::size_t N>
		inline bool Invoke(const char* a_name, const std::array<Value, N>& a_args)
		{
			return Invoke(a_name, nullptr, a_args);
		}

		template <std::size_t N>
		inline bool Invoke(const char* a_name, Value* a_result, const std::array<Value, N>& a_args)
		{
			return Invoke(a_name, a_result, a_args.data(), a_args.size());
		}

		bool PushBack(const Value& a_val)
		{
			assert(IsArray());
			return _objectInterface->PushBack(_value.data, a_val);
		}

		bool RemoveElements(std::uint32_t a_idx, std::int32_t a_count = -1)
		{
			assert(IsArray());
			return _objectInterface->RemoveElements(_value.data, a_idx, a_count);
		}

		bool RemoveElement(std::uint32_t a_idx)
		{
			return RemoveElements(a_idx, 1);
		}

		bool ClearElements()
		{
			return RemoveElements(0);
		}

		bool GetDisplayInfo(DisplayInfo* a_info) const
		{
			assert(IsDisplayObject());
			return _objectInterface->GetDisplayInfo(_value.data, a_info);
		}

		[[nodiscard]] Movie* GetMovie() const
		{
			assert(_objectInterface && _objectInterface->movieRoot);
			return reinterpret_cast<Movie*>(_objectInterface->movieRoot);
		}

	private:
		void AcquireManagedValue(const Value& a_rhs)
		{
			assert(a_rhs._value.data && a_rhs._objectInterface);
			_objectInterface = a_rhs._objectInterface;
			_objectInterface->ObjectAddRef(this, _value.data);
		}

		[[nodiscard]] bool IsManagedValue() const noexcept
		{
			const auto managed = _type.all(ValueType::kManagedBit);
			assert(managed ? _objectInterface != nullptr : true);
			return managed;
		}

		void ReleaseManagedValue()
		{
			assert(_value.data && _objectInterface);
			_objectInterface->ObjectRelease(this, _value.data);
			_objectInterface = nullptr;
		}

		// members
		ObjectInterface*                       _objectInterface{ nullptr };     // 00
		REX::TEnumSet<ValueType, std::int32_t> _type{ ValueType::kUndefined };  // 08
		ValueUnion                             _value{};                        // 10
		std::size_t                            _dataAux{ 0 };                   // 18
	};
	static_assert(sizeof(Value) == 0x20);
}
