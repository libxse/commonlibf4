#pragma once

namespace RE
{
	class OBJ_LIGH
	{
	public:
		enum class Flag : std::uint32_t
		{
			kNegative = 1 << 2,
			kShadowSpotlight = 1 << 10,
			kShadowHemisphere = 1 << 11,
			kShadowOmnidirectional = 1 << 12
		};

		// members
		std::int32_t                       time;                       // 00
		std::uint32_t                      radius;                     // 04
		std::uint32_t                      color;                      // 08
		REX::TEnumSet<Flag, std::uint32_t> flags;                      // 0C
		float                              fallOffExponent;            // 10
		float                              fov;                        // 14
		float                              nearDistance;               // 18
		float                              flickerPeriodRecip;         // 1C
		float                              flickerIntensityAmplitude;  // 20
		float                              flickerMovementAmplitude;   // 24
		float                              attenConstant;              // 28
		float                              attenScalar;                // 2C
		float                              attenExponent;              // 30
		float                              godrayNearClipDistance;     // 34
	};
	static_assert(sizeof(OBJ_LIGH) == 0x38);
}
