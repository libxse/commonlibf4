#pragma once

#include "RE/N/NiColor.h"
#include "RE/N/NiPoint.h"
#include "RE/N/NiPointer.h"

namespace RE
{
	class BGSPrimitiveLine;
	class BSMultiBoundShape;
	class BSFadeNode;

	class __declspec(novtable) BGSPrimitive
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSPrimitive };
		static constexpr auto VTABLE{ VTABLE::BGSPrimitive };

		enum class PRIMITIVE_TYPE
		{
			kNone = 0x0,
			kBox = 0x1,
			kSphere = 0x2,
			kPlane = 0x3,
			kLine = 0x4,
			kEllipsoid = 0x5
		};

		virtual ~BGSPrimitive();  // 00

		// add
		virtual void               SetColor(const NiColorA& a_color) = 0;                                                   // 01
		virtual void               SetRadii(const NiPoint3& a_radii) = 0;                                                   // 02
		virtual bool               IsInside(const NiPoint3& a_point) const = 0;                                             // 03
		virtual BSMultiBoundShape* MakeMultiBoundShape([[maybe_unused]] const NiPoint3& a_angle) const { return nullptr; }  // 04

		// members
		REX::TEnumSet<PRIMITIVE_TYPE, std::int32_t> type;   // 08
		NiPoint3                                    radii;  // 0C
		NiPointer<BSFadeNode>                       node;   // 18

		static BGSPrimitiveLine* CreateAbstract(PRIMITIVE_TYPE a_type, const NiPoint3* a_radii, const NiColorA* a_color)
		{
			using func_t = decltype(&BGSPrimitive::CreateAbstract);
			static REL::Relocation<func_t> func{ ID::BGSPrimitive::CreateAbstract };
			return func(a_type, a_radii, a_color);
		}
	};
	static_assert(sizeof(BGSPrimitive) == 0x20);
}
