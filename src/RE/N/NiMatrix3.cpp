#include "RE/N/NiMatrix3.h"

namespace RE
{
	const NiMatrix3 NiMatrix3::ZERO = { 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F };
	const NiMatrix3 NiMatrix3::IDENTITY = { NiPoint4::IDENTITY0, NiPoint4::IDENTITY0, NiPoint4::IDENTITY0 };

	NiMatrix3::NiMatrix3(const NiPoint4& a_point0, const NiPoint4& a_point1, const NiPoint4& a_point2) noexcept
	{
		entry[0] = a_point0;
		entry[1] = a_point1;
		entry[2] = a_point2;
	}

	NiMatrix3::NiMatrix3(
		float a_x0, float a_y0, float a_z0, float a_w0,
		float a_x1, float a_y1, float a_z1, float a_w1,
		float a_x2, float a_y2, float a_z2, float a_w2) noexcept
	{
		entry[0] = { a_x0, a_y0, a_z0, a_w0 };
		entry[1] = { a_x1, a_y1, a_z1, a_w1 };
		entry[2] = { a_x2, a_y2, a_z2, a_w2 };
	}

	NiPoint4& NiMatrix3::operator[](std::size_t a_pos) noexcept
	{
		assert(a_pos < 3);
		return entry[a_pos];
	}

	const NiPoint4& NiMatrix3::operator[](std::size_t a_pos) const noexcept
	{
		assert(a_pos < 3);
		return entry[a_pos];
	}

	bool NiMatrix3::operator==(const NiMatrix3& a_rhs) const noexcept
	{
		return (entry[0] == a_rhs[0]) && (entry[1] == a_rhs[1]) && (entry[2] == a_rhs[2]);
	}

	bool NiMatrix3::operator!=(const NiMatrix3& a_rhs) const noexcept
	{
		return !operator==(a_rhs);
	}

	NiMatrix3 NiMatrix3::operator*(const NiMatrix3& a_rhs) const noexcept
	{
		NiMatrix3 result;
		result[0][0] = entry[0][0] * a_rhs[0][0] + entry[0][1] * a_rhs[1][0] + entry[0][2] * a_rhs[2][0];
		result[1][0] = entry[1][0] * a_rhs[0][0] + entry[1][1] * a_rhs[1][0] + entry[1][2] * a_rhs[2][0];
		result[2][0] = entry[2][0] * a_rhs[0][0] + entry[2][1] * a_rhs[1][0] + entry[2][2] * a_rhs[2][0];
		result[0][1] = entry[0][0] * a_rhs[0][1] + entry[0][1] * a_rhs[1][1] + entry[0][2] * a_rhs[2][1];
		result[1][1] = entry[1][0] * a_rhs[0][1] + entry[1][1] * a_rhs[1][1] + entry[1][2] * a_rhs[2][1];
		result[2][1] = entry[2][0] * a_rhs[0][1] + entry[2][1] * a_rhs[1][1] + entry[2][2] * a_rhs[2][1];
		result[0][2] = entry[0][0] * a_rhs[0][2] + entry[0][1] * a_rhs[1][2] + entry[0][2] * a_rhs[2][2];
		result[1][2] = entry[1][0] * a_rhs[0][2] + entry[1][1] * a_rhs[1][2] + entry[1][2] * a_rhs[2][2];
		result[2][2] = entry[2][0] * a_rhs[0][2] + entry[2][1] * a_rhs[1][2] + entry[2][2] * a_rhs[2][2];
		return result;
	}

	NiMatrix3 NiMatrix3::operator*(float a_scalar) const noexcept
	{
		NiMatrix3 result;
		result[0][0] = entry[0][0] * a_scalar;
		result[0][1] = entry[0][1] * a_scalar;
		result[0][2] = entry[0][2] * a_scalar;
		result[1][0] = entry[1][0] * a_scalar;
		result[1][1] = entry[1][1] * a_scalar;
		result[1][2] = entry[1][2] * a_scalar;
		result[2][0] = entry[2][0] * a_scalar;
		result[2][1] = entry[2][1] * a_scalar;
		result[2][2] = entry[2][2] * a_scalar;
		return result;
	}

	NiPoint3 NiMatrix3::operator*(const NiPoint3& a_rhs) const noexcept
	{
		return NiPoint3(
			entry[0][0] * a_rhs.x + entry[0][1] * a_rhs.y + entry[0][2] * a_rhs.z,
			entry[1][0] * a_rhs.x + entry[1][1] * a_rhs.y + entry[1][2] * a_rhs.z,
			entry[2][0] * a_rhs.x + entry[2][1] * a_rhs.y + entry[2][2] * a_rhs.z);
	}

	void NiMatrix3::MakeIdentity() noexcept
	{
		entry[0] = NiPoint4::IDENTITY0;
		entry[1] = NiPoint4::IDENTITY1;
		entry[2] = NiPoint4::IDENTITY2;
	}

	NiMatrix3 NiMatrix3::Transpose() const noexcept
	{
		NiMatrix3 result;
		result[0][0] = entry[0][0];
		result[0][1] = entry[1][0];
		result[0][2] = entry[2][0];
		result[0][3] = entry[0][3];
		result[1][0] = entry[0][1];
		result[1][1] = entry[1][1];
		result[1][2] = entry[2][1];
		result[1][3] = entry[1][3];
		result[2][0] = entry[0][2];
		result[2][1] = entry[1][2];
		result[2][2] = entry[2][2];
		result[2][3] = entry[2][3];
		return result;
	}

	bool NiMatrix3::ToEulerAnglesXYZ(NiPoint3& a_point) const
	{
		return ToEulerAnglesXYZ(a_point.x, a_point.y, a_point.z);
	}

	bool NiMatrix3::ToEulerAnglesXYZ(float& a_x, float& a_y, float& a_z) const
	{
		using func_t = bool (*)(const NiMatrix3*, float&, float&, float&);
		static REL::Relocation<func_t> func{ ID::NiMatrix3::ToEulerAnglesXYZ1 };
		return func(this, a_x, a_y, a_z);
	}

	bool NiMatrix3::ToEulerAnglesXZY(float& a_x, float& a_z, float& a_y) const
	{
		using func_t = bool (*)(const NiMatrix3*, float&, float&, float&);
		static REL::Relocation<func_t> func{ ID::NiMatrix3::ToEulerAnglesXZY2 };
		return func(this, a_x, a_z, a_y);
	}

	bool NiMatrix3::ToEulerAnglesYXZ(float& a_y, float& a_x, float& a_z) const
	{
		using func_t = bool (*)(const NiMatrix3*, float&, float&, float&);
		static REL::Relocation<func_t> func{ ID::NiMatrix3::ToEulerAnglesYXZ3 };
		return func(this, a_y, a_x, a_z);
	}

	bool NiMatrix3::ToEulerAnglesYZX(float& a_y, float& a_z, float& a_x) const
	{
		using func_t = bool (*)(const NiMatrix3*, float&, float&, float&);
		static REL::Relocation<func_t> func{ ID::NiMatrix3::ToEulerAnglesYZX4 };
		return func(this, a_y, a_z, a_x);
	}

	bool NiMatrix3::ToEulerAnglesZYX(float& a_z, float& a_y, float& a_x) const
	{
		using func_t = bool (*)(const NiMatrix3*, float&, float&, float&);
		static REL::Relocation<func_t> func{ ID::NiMatrix3::ToEulerAnglesZYX5 };
		return func(this, a_z, a_y, a_x);
	}

	bool NiMatrix3::ToEulerAnglesZXY(float& a_z, float& a_x, float& a_y) const
	{
		using func_t = bool (*)(const NiMatrix3*, float&, float&, float&);
		static REL::Relocation<func_t> func{ ID::NiMatrix3::ToEulerAnglesZXY6 };
		return func(this, a_z, a_x, a_y);
	}

	void NiMatrix3::FromEulerAnglesXYZ(const NiPoint3& a_point)
	{
		FromEulerAnglesXYZ(a_point.x, a_point.y, a_point.z);
	}

	void NiMatrix3::FromEulerAnglesXYZ(float a_x, float a_y, float a_z)
	{
		using func_t = void (*)(NiMatrix3*, float, float, float);
		static REL::Relocation<func_t> func{ ID::NiMatrix3::FromEulerAnglesXYZ1 };
		return func(this, a_x, a_y, a_z);
	}

	void NiMatrix3::FromEulerAnglesXZY(float a_x, float a_z, float a_y)
	{
		using func_t = void (*)(NiMatrix3*, float, float, float);
		static REL::Relocation<func_t> func{ ID::NiMatrix3::FromEulerAnglesXZY2 };
		return func(this, a_x, a_z, a_y);
	}

	void NiMatrix3::FromEulerAnglesYXZ(float a_y, float a_x, float a_z)
	{
		using func_t = void (*)(NiMatrix3*, float, float, float);
		static REL::Relocation<func_t> func{ ID::NiMatrix3::FromEulerAnglesYXZ3 };
		return func(this, a_y, a_x, a_z);
	}

	void NiMatrix3::FromEulerAnglesYZX(float a_y, float a_z, float a_x)
	{
		using func_t = void (*)(NiMatrix3*, float, float, float);
		static REL::Relocation<func_t> func{ ID::NiMatrix3::FromEulerAnglesYZX4 };
		return func(this, a_y, a_z, a_x);
	}

	void NiMatrix3::FromEulerAnglesZYX(float a_z, float a_y, float a_x)
	{
		using func_t = void (*)(NiMatrix3*, float, float, float);
		static REL::Relocation<func_t> func{ ID::NiMatrix3::FromEulerAnglesZYX5 };
		return func(this, a_z, a_y, a_x);
	}

	void NiMatrix3::FromEulerAnglesZXY(float a_z, float a_x, float a_y)
	{
		using func_t = void (*)(NiMatrix3*, float, float, float);
		static REL::Relocation<func_t> func{ ID::NiMatrix3::FromEulerAnglesZXY6 };
		return func(this, a_z, a_x, a_y);
	}
}
