#pragma once

#include "RE/B/BSBound.h"
#include "RE/B/BSTEvent.h"
#include "RE/B/BSTHashMap.h"
#include "RE/B/bhkNPCollisionObjectUnlinked.h"
#include "RE/H/hkRefPtr.h"
#include "RE/H/hkStepInfo.h"
#include "RE/H/hkVector4f.h"
#include "RE/H/hknpCharacterContext.h"
#include "RE/H/hknpCharacterState.h"
#include "RE/H/hknpCharacterSurfaceInfo.h"
#include "RE/N/NiPoint.h"
#include "RE/N/NiPointer.h"

namespace RE
{
	enum class COL_LAYER;
	enum class SHAPE_TYPES;
	class bhkCharacterControllerCinfo;
	class bhkCharacterMoveFinishEvent;
	class bhkCharacterStateChangeEvent;
	class bhkICharOrientationController;
	class bhkNonSupportContactEvent;
	class bhkWorld;
	class DamageImpactData;
	class MoveData;

	class __declspec(novtable) bhkCharacterController :
		public bhkNPCollisionObjectUnlinked,                 // 000
		public BSTEventSource<bhkCharacterMoveFinishEvent>,  // 030
		public BSTEventSource<bhkNonSupportContactEvent>,    // 088
		public BSTEventSource<bhkCharacterStateChangeEvent>  // 0E0
	{
	public:
		inline static constexpr auto RTTI{ RTTI::bhkCharacterController };
		inline static constexpr auto VTABLE{ VTABLE::bhkCharacterController };

		enum class CHARACTER_SIZE
		{
			kNormal = 0x0,
			kSized = 0x1,
			kSizing = 0x2
		};

		class CheckGoodType
		{
		public:
			// members
			bool checkDangerous;        // 00
			bool checkActors;           // 01
			bool checkGround;           // 02
			bool checkEnvironment;      // 03
			bool useHitToleranceCheck;  // 04
		};
		static_assert(sizeof(CheckGoodType) == 0x05);

		// add
		virtual float           GetKeepDistanceImpl() const = 0;                                                                              // 31
		virtual void            InitPhysicsSystemImpl(const bhkCharacterControllerCinfo& a_info) = 0;                                         // 32
		virtual void            GetPositionImpl(hkVector4f& a_pos, bool a_applyCenterOffset) const = 0;                                       // 33
		virtual void            SetPositionImpl(const hkVector4f& a_pos, bool a_applyCenterOffset, bool a_forceWarp) = 0;                     // 34
		virtual void            GetPredictedPositionImpl(hkVector4f& a_pos, bool a_applyCenterOffset) const = 0;                              // 35
		virtual void            ClearPreviousStepCachedDataImpl() = 0;                                                                        // 36
		virtual void            GetTransformImpl(hkTransformf& a_transform) const = 0;                                                        // 37
		virtual void            SetTransformImpl(const hkTransformf& a_transform) = 0;                                                        // 38
		virtual void            GetLinearVelocityImpl(hkVector4f& a_linVel) const = 0;                                                        // 39
		virtual void            SetLinearVelocityImpl(const hkVector4f& a_linVel) = 0;                                                        // 3A
		virtual bool            CheckPenetrationImpl() = 0;                                                                                   // 3B
		virtual bool            IntegrateStepImpl(BSTArray<NiPointer<bhkNPCollisionObject>>* a_deferredReleaseColObjs) = 0;                   // 3C
		virtual void            FinishMoveImpl(const MoveData& a_moveData) = 0;                                                               // 3D
		virtual void            CheckSupportImpl() = 0;                                                                                       // 3E
		virtual void            SetWorldImpl(bhkWorld* a_newWorld) = 0;                                                                       // 3F
		virtual bhkWorld*       GetWorldImpl() const = 0;                                                                                     // 40
		virtual hknpBodyId      GetBodyIdImpl() const = 0;                                                                                    // 41
		virtual const hknpBody* GetBodyImpl() const = 0;                                                                                      // 42
		virtual bool            SetShapeImpl(hknpShape* a_shape, const hkVector4f&) = 0;                                                      // 43
		virtual float           GetVDBAlpha() const = 0;                                                                                      // 44
		virtual bool            GetCurrentCollisionsImpl(BSScrapArray<const hknpBody*>& a_cols) = 0;                                          // 45
		virtual bool            HasPhysicsStepSubscriptionsImpl() const = 0;                                                                  // 46
		virtual bool            AddPhysicsStepSubscriptionsImpl() = 0;                                                                        // 47
		virtual bool            RemovePhysicsStepSubscriptionsImpl() = 0;                                                                     // 48
		virtual void            RotateImpl(const hkTransformf& a_transf, bool a_forceWarp) = 0;                                               // 49
		virtual void            SendEventOnNonSupportContactsImpl(BSTEventSink<bhkNonSupportContactEvent>& a_sink, bool a_receiveEvent) = 0;  // 4A
		virtual void            ApplyMoveImmediately() = 0;                                                                                   // 4B
		virtual void            ClearCollectorDataImpl() = 0;                                                                                 // 4C

		void Jump(float a_height)
		{
			using func_t = decltype(&bhkCharacterController::Jump);
			static REL::Relocation<func_t> func{ ID::bhkCharacterController::Jump };
			return func(this, a_height);
		}

		// members
		hkVector4f                                                              forwardVec;                 // 140
		hkStepInfo                                                              stepInfo;                   // 150
		hkVector4f                                                              outVelocity;                // 160
		hkVector4f                                                              initialVelocity;            // 170
		hkVector4f                                                              velocityMod;                // 180
		hkVector4f                                                              direction;                  // 190
		hkVector4f                                                              rotCenter;                  // 1A0
		hkVector4f                                                              pushDelta;                  // 1B0
		hkVector4f                                                              fakeSupportStart;           // 1C0
		hkVector4f                                                              up;                         // 1D0
		hkVector4f                                                              supportNorm;                // 1E0
		BSBound                                                                 collisionBound;             // 1F0
		BSBound                                                                 bumperCollisionBound;       // 220
		NiPoint3                                                                cachedLinearVelocity;       // 250
		NiPoint3                                                                remainderDeltaWS;           // 24C
		bhkICharOrientationController*                                          orientationCtrl;            // 268
		hknpCharacterSurfaceInfo                                                surfaceInfo;                // 270
		hknpCharacterContext                                                    context;                    // 2A0
		std::uint32_t                                                           flags;                      // 300
		REX::TEnumSet<hknpCharacterState::hknpCharacterStateType, std::int32_t> wantState;                  // 304
		float                                                                   velocityTime;               // 308
		float                                                                   rotMod;                     // 30C
		float                                                                   rotModTime;                 // 310
		float                                                                   calculatePitchTimer;        // 314
		float                                                                   acrobatics;                 // 318
		float                                                                   center;                     // 31C
		float                                                                   waterHeight;                // 320
		float                                                                   jumpHeight;                 // 324
		float                                                                   fallStartHeight;            // 328
		float                                                                   fallTime;                   // 32C
		float                                                                   gravity;                    // 330
		float                                                                   pitchAngle;                 // 334
		float                                                                   rollAngle;                  // 338
		float                                                                   pitchMult;                  // 33C
		float                                                                   scale;                      // 340
		float                                                                   swimFloatHeight;            // 344
		float                                                                   actorHeight;                // 348
		float                                                                   speedPct;                   // 34C
		std::uint32_t                                                           pushCount;                  // 350
		REX::TEnumSet<SHAPE_TYPES, std::int32_t>                                shapeType;                  // 354
		REX::TEnumSet<SHAPE_TYPES, std::int32_t>                                sizedShapeType;             // 358
		hkRefPtr<hknpShape>                                                     shapes[2];                  // 360
		float                                                                   radius;                     // 370
		float                                                                   height;                     // 374
		float                                                                   destRadius;                 // 378
		float                                                                   lodDistance;                // 37C
		REX::TEnumSet<CHARACTER_SIZE, std::int32_t>                             size;                       // 380
		std::uint32_t                                                           priority;                   // 384
		std::int32_t                                                            supportCount;               // 388
		NiPointer<bhkNPCollisionObject>                                         supportBody;                // 390
		float                                                                   bumpedForce;                // 398
		NiPointer<bhkNPCollisionObject>                                         bumpedBody;                 // 3A0
		NiPointer<bhkNPCollisionObject>                                         bumpedCharCollisionObject;  // 3A8
		BSTHashMap<std::uint32_t, float>                                        bumpedBodyIdExpirationM;    // 3B0
		void*                                                                   userData;                   // 3E0
		BSTHashMap<bhkNPCollisionObject*, DamageImpactData*>                    damageImpacts;              // 3E8
		float                                                                   maxSlope;                   // 418
		std::uint32_t                                                           supportMaterial;            // 41C
		REX::TEnumSet<COL_LAYER, std::int32_t>                                  supportLayer;               // 420
		float                                                                   stepHeight;                 // 424
		float                                                                   stepHeightMod;              // 428
		float                                                                   stepHeightModTimer;         // 42C
		float                                                                   castDepthC;                 // 430
		std::uint32_t                                                           numCollisions;              // 434
		std::uint32_t                                                           stickyCollisionGroup;       // 438
		bool                                                                    allSurfacesStopped;         // 43C
		bool                                                                    stickyCollisions;           // 43D
		bool                                                                    fakeSupport;                // 43E
		bool                                                                    calculatePitch;             // 43F
		bool                                                                    useBumper;                  // 440
		bool                                                                    hasBumper;                  // 441
		bool                                                                    inAirPreMove;               // 442
	};
	static_assert(sizeof(bhkCharacterController) == 0x450);
}
