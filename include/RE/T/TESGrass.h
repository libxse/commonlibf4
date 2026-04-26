#pragma once

#include "RE/T/TESBoundObject.h"
#include "RE/T/TESModel.h"

namespace RE
{
	class __declspec(novtable) TESGrass :
		public TESBoundObject,  // 00
		public TESModel         // 68
	{
	public:
		static constexpr auto RTTI{ RTTI::TESGrass };
		static constexpr auto VTABLE{ VTABLE::TESGrass };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kGRAS };

		enum class GRASS_WATER_STATE
		{
			kAboveOnlyAtleast = 0x0,
			kAboveOnlyAtmost = 0x1,
			kBelowOnlyAtleast = 0x2,
			kBelowOnlyAtmost = 0x3,
			kBothAtlest = 0x4,
			kBothAtmost = 0x5,
			kBothAtmostAbove = 0x6,
			kBothAtmostBelow = 0x7,
			kTotal = 0x8
		};

		class GRASS_DATA
		{
		public:
			// members
			std::int8_t                                    density;                 // 00
			std::int8_t                                    minSlopeDegrees;         // 01
			std::int8_t                                    maxSlopeDegrees;         // 02
			std::uint16_t                                  distanceFromWaterLevel;  // 04
			REX::TEnumSet<GRASS_WATER_STATE, std::int32_t> underwater;              // 08
			float                                          positionRange;           // 0C
			float                                          heightRange;             // 10
			float                                          colorRange;              // 14
			float                                          wavePeriod;              // 18
			std::int8_t                                    flags;                   // 1C
		};
		static_assert(sizeof(GRASS_DATA) == 0x20);

		// add
		virtual std::int8_t       GetDensity() const { return data.density; }                                                                                          // 67
		virtual bool              SetDensity(std::int8_t a_density);                                                                                                   // 68
		virtual std::int8_t       GetMinSlopeDegrees() const { return data.minSlopeDegrees; }                                                                          // 69
		virtual bool              SetMinSlopeDegrees(std::int8_t a_minSlopeDegrees);                                                                                   // 6A
		virtual std::int8_t       GetMaxSlopeDegrees() const { return data.maxSlopeDegrees; }                                                                          // 6B
		virtual bool              SetMaxSlopeDegrees(std::int8_t a_maxSlopeDegrees);                                                                                   // 6C
		virtual float             GetMinSlope() const;                                                                                                                 // 6D
		virtual float             GetMaxSlope() const;                                                                                                                 // 6E
		virtual std::uint16_t     GetDistanceFromWaterLevel() const { return data.distanceFromWaterLevel; }                                                            // 6F
		virtual void              SetDistanceFromWaterLevel(const std::uint16_t a_distanceFromWaterLevel) { data.distanceFromWaterLevel = a_distanceFromWaterLevel; }  // 70
		virtual GRASS_WATER_STATE GetUnderwaterState() const { return *data.underwater; }                                                                              // 71
		virtual void              SetUnderwaterState(const GRASS_WATER_STATE a_underwater) { data.underwater = a_underwater; }                                         // 72
		virtual float             GetPositionRange() const { return data.positionRange; }                                                                              // 73
		virtual bool              SetPositionRange(float a_range);                                                                                                     // 74
		virtual float             GetHeightRange() const { return data.heightRange; }                                                                                  // 75
		virtual bool              SetHeightRange(float a_range);                                                                                                       // 76
		virtual float             GetColorRange() const { return data.colorRange; }                                                                                    // 77
		virtual bool              SetColorRange(float a_range);                                                                                                        // 78
		virtual float             GetWavePeriod() const { return data.wavePeriod; }                                                                                    // 79
		virtual bool              SetWavePeriod(float a_period);                                                                                                       // 7A
		virtual bool              GetVertexLighting() const;                                                                                                           // 7B
		virtual void              SetVertexLighting(bool a_flag);                                                                                                      // 7C
		virtual bool              GetUniformScaling() const;                                                                                                           // 7D
		virtual void              SetUniformScaling(bool a_flag);                                                                                                      // 7E
		virtual bool              GetFitToSlope() const;                                                                                                               // 7F
		virtual void              SetFitToSlope(bool a_flag) const;                                                                                                    // 80

		// members
		GRASS_DATA data;  // 98
	};
	static_assert(sizeof(TESGrass) == 0xB8);
}
