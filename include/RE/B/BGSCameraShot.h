#pragma once

#include "RE/T/TESCondition.h"
#include "RE/T/TESForm.h"
#include "RE/T/TESImageSpaceModifiableForm.h"
#include "RE/T/TESModel.h"

namespace RE
{
	class __declspec(novtable) BGSCameraShot :
		public TESForm,                     // 00
		public TESModel,                    // 20
		public TESImageSpaceModifiableForm  // 50
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSCameraShot };
		static constexpr auto VTABLE{ VTABLE::BGSCameraShot };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kCAMS };

		enum class CAM_ACTION
		{
			kShoot = 0x0,
			kFly = 0x1,
			kHit = 0x2,
			kZoom = 0x3,

			kTotal = 0x4
		};

		enum class CAM_OBJECT
		{
			kAttacker = 0x0,
			kProjectile = 0x1,
			kTarget = 0x2,
			kLeadActor = 0x3,

			kTotal = 0x4
		};

		enum class CAM_USER
		{
			kNone = 0x0,
			kVATS = 0x1,
			kDialogue = 0x2
		};

		enum class CAM_ZOOM
		{
			kDefault = 0x0,
			kDisable = 0x1,
			kShotList = 0x2
		};

		class CAMERA_SHOT_DATA
		{
		public:
			// members
			REX::EnumSet<CAM_ACTION, std::int32_t> cameraAction;                // 00
			REX::EnumSet<CAM_OBJECT, std::int32_t> location;                    // 04
			REX::EnumSet<CAM_OBJECT, std::int32_t> target;                      // 08
			std::uint32_t                          flags;                       // 0C
			float                                  playerTimeMult;              // 10
			float                                  targetTimeMult;              // 14
			float                                  globalTimeMult;              // 18
			float                                  maxTime;                     // 1C
			float                                  minTime;                     // 20
			float                                  targetPercentBetweenActors;  // 24
			float                                  nearTargetDistance;          // 28
			float                                  locationSpring;              // 2C
			float                                  targetSpring;                // 30
			float                                  rotationOffsetX;             // 34
			float                                  rotationOffsetY;             // 38
			float                                  rotationOffsetZ;             // 3C
		};
		static_assert(sizeof(CAMERA_SHOT_DATA) == 0x40);

		// members
		CAMERA_SHOT_DATA data;        // 60
		TESCondition     conditions;  // A0
	};
	static_assert(sizeof(BGSCameraShot) == 0xA8);
}
