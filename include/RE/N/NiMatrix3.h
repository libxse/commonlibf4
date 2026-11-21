#pragma once

#include "RE/N/NiPoint4.h"

namespace RE
{
	class alignas(0x10) NiMatrix3
	{
	public:
		static const NiMatrix3 ZERO;
		static const NiMatrix3 IDENTITY;

		constexpr NiMatrix3() noexcept = default;
		constexpr NiMatrix3(const NiPoint4& a_point0, const NiPoint4& a_point1, const NiPoint4& a_point2) noexcept;
		constexpr NiMatrix3(
			float a_x0, float a_y0, float a_z0, float a_w0,
			float a_x1, float a_y1, float a_z1, float a_w1,
			float a_x2, float a_y2, float a_z2, float a_w2) noexcept;

		constexpr NiPoint4&       operator[](std::size_t a_pos) noexcept;
		constexpr const NiPoint4& operator[](std::size_t a_pos) const noexcept;
		constexpr bool            operator==(const NiMatrix3& a_rhs) const noexcept;
		constexpr bool            operator!=(const NiMatrix3& a_rhs) const noexcept;
		constexpr NiMatrix3       operator*(const NiMatrix3& a_rhs) const noexcept;
		constexpr NiMatrix3       operator*(float a_scalar) const noexcept;
		constexpr NiPoint3        operator*(const NiPoint3& a_rhs) const noexcept;

		constexpr void      MakeIdentity() noexcept;
		constexpr NiMatrix3 Transpose() const noexcept;

		bool ToEulerAnglesXYZ(NiPoint3& a_point) const;
		bool ToEulerAnglesXYZ(float& a_x, float& a_y, float& a_z) const;
		bool ToEulerAnglesXZY(float& a_x, float& a_z, float& a_y) const;
		bool ToEulerAnglesYXZ(float& a_y, float& a_x, float& a_z) const;
		bool ToEulerAnglesYZX(float& a_y, float& a_z, float& a_x) const;
		bool ToEulerAnglesZYX(float& a_z, float& a_y, float& a_x) const;
		bool ToEulerAnglesZXY(float& a_z, float& a_y, float& a_x) const;

		void FromEulerAnglesXYZ(const NiPoint3& a_point);
		void FromEulerAnglesXYZ(float a_x, float a_y, float a_z);
		void FromEulerAnglesXZY(float a_x, float a_z, float a_y);
		void FromEulerAnglesYXZ(float a_y, float a_x, float a_z);
		void FromEulerAnglesYZX(float a_y, float a_z, float a_x);
		void FromEulerAnglesZYX(float a_z, float a_y, float a_x);
		void FromEulerAnglesZXY(float a_z, float a_x, float a_y);

		// members
		NiPoint4 entry[3];  // 00 - three padded columns, indexed [column][row]
	};
	static_assert(sizeof(NiMatrix3) == 0x30);
}

namespace RE
{
	inline const NiMatrix3 NiMatrix3::ZERO = { 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F };
	inline const NiMatrix3 NiMatrix3::IDENTITY = { NiPoint4::IDENTITY0, NiPoint4::IDENTITY1, NiPoint4::IDENTITY2 };

	constexpr NiMatrix3::NiMatrix3(const NiPoint4& a_point0, const NiPoint4& a_point1, const NiPoint4& a_point2) noexcept
	{
		entry[0] = a_point0;
		entry[1] = a_point1;
		entry[2] = a_point2;
	}

	constexpr NiMatrix3::NiMatrix3(
		float a_x0, float a_y0, float a_z0, float a_w0,
		float a_x1, float a_y1, float a_z1, float a_w1,
		float a_x2, float a_y2, float a_z2, float a_w2) noexcept
	{
		entry[0] = { a_x0, a_y0, a_z0, a_w0 };
		entry[1] = { a_x1, a_y1, a_z1, a_w1 };
		entry[2] = { a_x2, a_y2, a_z2, a_w2 };
	}

	constexpr NiPoint4& NiMatrix3::operator[](std::size_t a_pos) noexcept
	{
		assert(a_pos < 3);
		return entry[a_pos];
	}

	constexpr const NiPoint4& NiMatrix3::operator[](std::size_t a_pos) const noexcept
	{
		assert(a_pos < 3);
		return entry[a_pos];
	}

	constexpr bool NiMatrix3::operator==(const NiMatrix3& a_rhs) const noexcept
	{
		return (entry[0] == a_rhs[0]) && (entry[1] == a_rhs[1]) && (entry[2] == a_rhs[2]);
	}

	constexpr bool NiMatrix3::operator!=(const NiMatrix3& a_rhs) const noexcept
	{
		return !operator==(a_rhs);
	}

	constexpr NiMatrix3 NiMatrix3::operator*(const NiMatrix3& a_rhs) const noexcept
	{
		NiMatrix3 result;
		for (std::size_t column = 0; column < 3; ++column) {
			result[column] = entry[0] * a_rhs[column].x + entry[1] * a_rhs[column].y + entry[2] * a_rhs[column].z;
		}
		return result;
	}

	constexpr NiMatrix3 NiMatrix3::operator*(float a_scalar) const noexcept
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

	constexpr NiPoint3 NiMatrix3::operator*(const NiPoint3& a_rhs) const noexcept
	{
		return NiPoint3(
			entry[0].x * a_rhs.x + entry[1].x * a_rhs.y + entry[2].x * a_rhs.z,
			entry[0].y * a_rhs.x + entry[1].y * a_rhs.y + entry[2].y * a_rhs.z,
			entry[0].z * a_rhs.x + entry[1].z * a_rhs.y + entry[2].z * a_rhs.z);
	}

	constexpr void NiMatrix3::MakeIdentity() noexcept
	{
		entry[0] = NiPoint4::IDENTITY0;
		entry[1] = NiPoint4::IDENTITY1;
		entry[2] = NiPoint4::IDENTITY2;
	}

	constexpr NiMatrix3 NiMatrix3::Transpose() const noexcept
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
}

template <>
struct std::formatter<RE::NiMatrix3>
{
	template <class ParseContext>
	constexpr auto parse(ParseContext& a_ctx)
	{
		return a_ctx.begin();
	}

	template <class FormatContext>
	constexpr auto format(const RE::NiMatrix3& a_matrix, FormatContext& a_ctx) const
	{
		return format_to(a_ctx.out(), "[{}, {}, {}]", a_matrix[0], a_matrix[1], a_matrix[2]);
	}
};
