#pragma once

#include "RE/B/BGSBodyPartDefs.h"
#include "RE/B/BGSEquipIndex.h"
#include "RE/B/BGSObjectInstance.h"
#include "RE/B/BSPointerHandle.h"
#include "RE/B/BSSoundHandle.h"
#include "RE/B/BSTArray.h"
#include "RE/B/bhkCollisionQueryResultHandle.h"
#include "RE/C/CELLJobs.h"
#include "RE/C/CFilter.h"
#include "RE/H/hknpBodyId.h"
#include "RE/N/NiPoint.h"
#include "RE/N/NiPointer.h"
#include "RE/N/NiTransform.h"
#include "RE/T/TESObjectREFR.h"

namespace RE
{
	enum class COL_LAYER;
	enum class ImpactResult;
	class bhkNPCollisionObject;
	class BSMagicShaderParticles;
	class hknpAllHitsCollector;
	class hknpShape;
	class NiAVObject;
	class NiLight;
	class NiNode;
	class QueuedFile;

	namespace MagicSystem
	{
		enum class CastingSource;
	}

	class __declspec(novtable) Projectile :
		public TESObjectREFR  // 000
	{
	public:
		static constexpr auto RTTI{ RTTI::Projectile };
		static constexpr auto VTABLE{ VTABLE::Projectile };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kREFR };

		class ImpactCreation
		{
		public:
			// members
			NiPoint3A      contactPoint;       // 00
			NiPoint3A      contactNormal;      // 10
			TESObjectREFR* collidee;           // 20
			CFilter        collisionFilter;    // 28
			hknpBodyId     collisionBodyId;    // 2C
			std::uint32_t  collisionShapeKey;  // 30
			bool           spellCast;          // 34
			bool           backface;           // 35
			bool           trigger;            // 36
		};
		static_assert(sizeof(ImpactCreation) == 0x40);

		class ImpactData
		{
		public:
			// members
			NiPoint3                                                 location;                // 00
			NiPoint3                                                 normal;                  // 0C
			bhkCollisionQueryResultHandle                            impactDecalQuery;        // 18
			ObjectRefHandle                                          collidee;                // 20
			NiPointer<bhkNPCollisionObject>                          colObj;                  // 28
			BGSMaterialType*                                         materialType;            // 30
			REX::TEnumSet<BGSBodyPartDefs::LIMB_ENUM, std::uint32_t> damageLimb;              // 38
			REX::TEnumSet<COL_LAYER, std::int32_t>                   collisionLayer;          // 3C
			NiPointer<NiNode>                                        closestBone;             // 40
			REX::TEnumSet<ImpactResult, std::int32_t>                resultOverride;          // 48
			float                                                    decalSize;               // 4C
			std::uint32_t                                            collisionShapeKey;       // 50
			std::int16_t                                             targetWorldObjectCount;  // 54
			std::int16_t                                             targetWorldObjectIndex;  // 56
			bool                                                     processed;               // 58
			bool                                                     spellCast;               // 59
			bool                                                     effectSpawned;           // 5A
			bool                                                     backface;                // 5B
		};
		static_assert(sizeof(ImpactData) == 0x60);

		// add
		virtual bool          IsMissileProjectile() const { return false; }                                                       // C6
		virtual bool          IsGrenadeProjectile() const { return false; }                                                       // C7
		virtual bool          IsFlameProjectile() const { return false; }                                                         // C8
		virtual bool          IsBeamProjectile() const { return false; }                                                          // C9
		virtual bool          IsFogProjectile() const { return false; }                                                           // CA
		virtual bool          IsBarrierProjectile() const { return false; }                                                       // CB
		virtual void          OnKill() { return; }                                                                                // CC
		virtual void          Process3D() { return; }                                                                             // CD
		virtual void          PostLoad3D(NiAVObject* a_obj3D);                                                                    // CE
		virtual void          UpdateImpl(float a_delta) = 0;                                                                      // CF
		virtual bool          ProcessImpacts();                                                                                   // D0
		virtual void          Update3D(CELLJobs::AnimatedRefJobData* a_data);                                                     // D1
		virtual bool          IsMine() const { return false; }                                                                    // D2
		virtual float         GetPowerSpeedMult() const { return spell ? 1.0F : power; }                                          // D3
		virtual float         GetWeaponSpeedMult() const { return 1.0F; }                                                         // D4
		virtual bool          GetStopMainSoundAfterImpact() const { return false; }                                               // D5
		virtual void          ReportHavokDeactivation() { return; }                                                               // D6
		virtual bool          TurnOff(Actor* a_actionActor, bool a_silent);                                                       // D7
		virtual bool          IsPermanent();                                                                                      // D8
		virtual float         GetGravity() const;                                                                                 // D9
		virtual void          CleanUpPointersOnDisable();                                                                         // DA
		virtual bool          RunTargetPick();                                                                                    // DB
		virtual bool          GetKillOnCollision() const { return true; }                                                         // DC
		virtual bool          ShouldBeLimited() const { return false; }                                                           // DD
		virtual bool          TargetsWholeBody() const { return false; }                                                          // DE
		virtual bool          GetAllowMovement() const;                                                                           // DF
		virtual std::uint32_t GetCollisionGroup() const;                                                                          // E0
		virtual hknpShape*    GetCollisionShape();                                                                                // E1
		virtual void          InitializeImpl() { return; }                                                                        // E2
		virtual void          Relaunch() { return; }                                                                              // E3
		virtual std::uint32_t AddImpact(const ImpactCreation& a_data);                                                            // E4
		virtual bool          HandleHits(const hknpAllHitsCollector& a_collector, const NiPoint3& a_from, const NiPoint3& a_to);  // E5
		virtual void          OnEnterTrigger() { return; }                                                                        // E6
		virtual void          AddInitialVelocity();                                                                               // E7
		virtual void          Handle3DLoaded() { return; }                                                                        // E8
		virtual bool          ShouldUseDesiredTarget() { return false; }                                                          // E9

		// members
		BSTArray<ImpactData>                                     impacts;              // 110
		NiTransform                                              followOffset;         // 130
		NiPointer<bhkNPCollisionObject>                          collisionObject;      // 170
		NiPointer<TESObjectREFR>                                 droppedRefr;          // 178
		NiPoint3                                                 movementDirection;    // 180
		NiPoint3                                                 velocity;             // 18C
		NiPointer<NiLight>                                       light;                // 198
		NiPointer<ActorCause>                                    actorCause;           // 1A0
		ObjectRefHandle                                          shooter;              // 1A8
		ObjectRefHandle                                          desiredTarget;        // 1AC
		BSSoundHandle                                            sndHandle;            // 1B0
		BSSoundHandle                                            sndCountdown;         // 1B8
		BGSExplosion*                                            explosion;            // 1C0
		MagicItem*                                               spell;                // 1C8
		REX::TEnumSet<MagicSystem::CastingSource, std::int32_t>  castingSource;        // 1D0
		EffectSetting*                                           avEffect;             // 1D8
		NiPointer<QueuedFile>                                    projectileDBFiles;    // 1E0
		void*                                                    muzzleFlashDBHandle;  // 1E8 - TODO
		NiPointer<NiNode>                                        muzzleFlashArt;       // 1F0
		BSMagicShaderParticles*                                  particles;            // 1F8
		REX::TEnumSet<BGSBodyPartDefs::LIMB_ENUM, std::uint32_t> targetLimb;           // 200
		NiPointer<NiAVObject>                                    targetLimbObj;        // 208
		NiAVObject*                                              clonePoolKey;         // 210
		float                                                    power;                // 218
		float                                                    speedMult;            // 21C
		float                                                    range;                // 220
		float                                                    age;                  // 224
		float                                                    damage;               // 228
		float                                                    alpha;                // 22C
		float                                                    explosionTimer;       // 230
		float                                                    blinkTimer;           // 234
		BGSObjectInstanceT<TESObjectWEAP>                        weaponSource;         // 238
		TESAmmo*                                                 ammoSource;           // 248
		BGSEquipIndex                                            equipIndex;           // 250
		float                                                    distanceMoved;        // 254
		float                                                    movementDelta;        // 258
		float                                                    scale;                // 25C
		std::uint64_t                                            flags;                // 260
		bool                                                     artRequested;         // 268
		bool                                                     animationsLoaded;     // 269
	};
	static_assert(sizeof(Projectile) == 0x270);
}
