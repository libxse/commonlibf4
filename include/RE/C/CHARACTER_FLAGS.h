#pragma once

namespace RE
{
	enum class CHARACTER_FLAGS : std::uint32_t
	{
		kQuadruped = 0x1,
		kNoGravityOnGround = 0x2,
		kTryStep = 0x4,
		kNoFriction = 0x8,
		kStuckQuad = 0x20,
		kAllowJumpNoContact = 0x10,
		kAnimAngleMod = 0x40,
		kHitDamage = 0x80,
		kSupport = 0x100,
		kHasPotentialSupportManifold = 0x200,
		kCanJump = 0x400,
		kChaseBip = 0x800,
		kFollowRagdoll = 0x1000,
		kJumping = 0x2000,
		kNotPushable = 0x4000,
		kCheckSupport = 0x10000,
		kNoSim = 0x20000,
		kFarAway = 0x40000,
		kOnStilts = 0x80000,
		kQuickSimulate = 0x100000,
		kRecordHits = 0x200000,
		kComputeTiltPreIntegrate = 0x400000,
		kShouldersUnderWater = 0x800000,
		kOnStairs = 0x1000000,
		kCanPitch = 0x2000000,
		kCanRoll = 0x4000000,
		kNoCharacterCollisions = 0x8000000,
		kNotPushablePermanent = 0x10000000,
		kPossiblePathObstacle = 0x20000000,
		kShapeRequiresZRot = 0x40000000,
		kSwimAtWaterSurface = 0x80000000
	};
}
