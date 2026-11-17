#pragma once

#include "RE/N/NiObject.h"
#include "RE/N/NiRTTI.h"

namespace RE
{
	class __declspec(novtable) BSGeometrySegmentData :
	    public NiObject  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BSGeometrySegmentData };
		static constexpr auto VTABLE{ VTABLE::BSGeometrySegmentData };
		static constexpr auto Ni_RTTI{ Ni_RTTI::BSGeometrySegmentData };

		// override (NiObject)
		const NiRTTI* GetRTTI() const override  // 02
		{
			static REL::Relocation<const NiRTTI*> rtti{ BSGeometrySegmentData::Ni_RTTI };
			return rtti.get();
		}

		void EnableAllSegments()
		{
			using func_t = decltype(&BSGeometrySegmentData::EnableAllSegments);
			static REL::Relocation<func_t> func{ ID::BSGeometrySegmentData::EnableAllSegments };
			return func(this);
		}

		void EnableSegment(std::uint32_t a_segment, std::uint32_t a_subsegment, bool a_refresh)
		{
			using func_t = decltype(&BSGeometrySegmentData::EnableSegment);
			static REL::Relocation<func_t> func{ ID::BSGeometrySegmentData::EnableSegment };
			return func(this, a_segment, a_subsegment, a_refresh);
		}

		void DisableSegment(std::uint32_t a_segment, std::uint32_t a_subsegment, bool a_refresh)
		{
			using func_t = decltype(&BSGeometrySegmentData::DisableSegment);
			static REL::Relocation<func_t> func{ ID::BSGeometrySegmentData::DisableSegment };
			return func(this, a_segment, a_subsegment, a_refresh);
		}

		[[nodiscard]] bool IsEnabled(std::uint32_t a_segment, std::uint32_t a_subsegment)
		{
			using func_t = decltype(&BSGeometrySegmentData::IsEnabled);
			static REL::Relocation<func_t> func{ ID::BSGeometrySegmentData::GetSegmentEnabled };
			return func(this, a_segment, a_subsegment);
		}

		[[nodiscard]] bool IsEmpty(std::uint32_t a_segment, std::uint32_t a_subsegment)
		{
			using func_t = decltype(&BSGeometrySegmentData::IsEmpty);
			static REL::Relocation<func_t> func{ ID::BSGeometrySegmentData::GetSegmentEmpty };
			return func(this, a_segment, a_subsegment);
		}

		void UpdateDrawData()
		{
			using func_t = decltype(&BSGeometrySegmentData::UpdateDrawData);
			static REL::Relocation<func_t> func{ ID::BSGeometrySegmentData::UpdateDrawData };
			return func(this);
		}

		[[nodiscard]] std::uint32_t GetSegmentCount() const noexcept { return segmentCount; }

		// members
		std::byte     pad10[0x1C];   // 10
		std::uint32_t segmentCount;  // 2C
		std::byte     pad30[0xC];    // 30
		bool          dirty;         // 3C
		std::byte     pad3D[0x3];    // 3D
	};
	static_assert(offsetof(BSGeometrySegmentData, segmentCount) == 0x2C);
	static_assert(offsetof(BSGeometrySegmentData, dirty) == 0x3C);
	static_assert(sizeof(BSGeometrySegmentData) == 0x40);
}
