#pragma once

#include "RE/B/BSTArray.h"
#include "RE/N/NiLight.h"
#include "RE/N/NiMatrix3.h"
#include "RE/N/NiPoint3.h"
#include "RE/N/NiPointer.h"
#include "RE/N/NiRefObject.h"

namespace RE
{
	class BSMultiBoundRoom;
	class BSPortal;
	class BSPortalGraph;
	class NiCullingProcess;

	class __declspec(novtable) BSLight :
	    public NiRefObject  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BSLight };
		static constexpr auto VTABLE{ VTABLE::BSLight };

		enum class Shape : std::uint32_t
		{
			kNone = 0,
			kPoint = 2,
			kHemisphere = 3,
			kBox = 5,
			kCone = 6
		};

		struct BoxShape
		{
		public:
			// members
			NiPoint3 center;       // 00
			NiPoint3 halfExtents;  // 0C
		};
		static_assert(sizeof(BoxShape) == 0x18);

		struct ConeShape
		{
		public:
			// members
			float     exponent;      // 00
			float     cosineCutoff;  // 04
			std::byte pad08[0x10];   // 08
		};
		static_assert(sizeof(ConeShape) == 0x18);

		// add
		virtual void SetLight(NiLight* a_light);  // 02
		virtual bool IsShadowLight();             // 03

		[[nodiscard]] Shape GetShape() const noexcept { return static_cast<Shape>(shape); }

		[[nodiscard]] NiLight* GetSourceLight() const noexcept { return light.get(); }

		void InvalidateSpotCone() noexcept
		{
			if (GetShape() == Shape::kCone) {
				spotConeGeometry.reset();
			}
		}

		std::uint32_t TestFrustumCull(NiCullingProcess* a_process)
		{
			using func_t = decltype(&BSLight::TestFrustumCull);
			static REL::Relocation<func_t> func{ ID::BSLight::TestFrustumCull };
			return func(this, a_process);
		}

		float GetLuminanceAtPoint(NiPoint3& a_point, NiLight* a_ignoreLight)
		{
			using func_t = decltype(&BSLight::GetLuminanceAtPoint);
			static REL::Relocation<func_t> func{ ID::BSLight::GetLuminanceAtPoint };
			return func(this, a_point, a_ignoreLight);
		}

		// members
		float         currentFade;  // 10
		float         luminance;    // 14
		std::uint32_t cullResult;   // 18
		std::byte     pad1C[0x44];  // 1C
		NiMatrix3     rotation;     // 60
		std::byte     pad90[0x10];  // 90
		union
		{
			BoxShape  box;
			ConeShape cone;
		};  // A0
		NiPointer<NiLight>          light;                      // B8
		std::byte                   padC0[0x30];                // C0
		BSTArray<BSMultiBoundRoom*> rooms;                      // F0
		BSTArray<BSPortal*>         portals;                    // 108
		std::byte                   pad120[0x18];               // 120
		BSPortalGraph*              portalGraph;                // 138
		std::byte                   pad140[0x8];                // 140
		NiPointer<NiAVObject>       spotConeGeometry;           // 148
		std::byte                   pad150[0x23];               // 150
		bool                        portalStrict;               // 173
		std::byte                   pad174[0x3];                // 174
		bool                        distanceLimited;            // 177
		std::byte                   pad178[0x6];                // 178
		bool                        excludeFromPointLuminance;  // 17E
		std::byte                   pad17F;                     // 17F
		std::uint32_t               shape;                      // 180
		std::byte                   pad184[0xC];                // 184
	};
	static_assert(sizeof(BSLight) == 0x190);
}
