#pragma once

#include "RE/N/NiVisibleArray.h"

namespace RE
{
	class __declspec(novtable) NiCullingProcess
	{
	public:
		static constexpr auto RTTI{ RTTI::NiCullingProcess };
		static constexpr auto VTABLE{ VTABLE::NiCullingProcess };
		static constexpr auto Ni_RTTI{ Ni_RTTI::NiCullingProcess };

		// add
		virtual const NiRTTI*             GetRTTI() const;                                                  // 00
		virtual const NiNode*             IsNode() const;                                                   // 01
		virtual NiNode*                   IsNode();                                                         // 02
		virtual NiSwitchNode*             IsSwitchNode();                                                   // 03
		virtual BSFadeNode*               IsFadeNode();                                                     // 04
		virtual BSMultiBoundNode*         IsMultiBoundNode();                                               // 05
		virtual BSGeometry*               IsGeometry();                                                     // 06
		virtual NiTriStrips*              IsTriStrips();                                                    // 07
		virtual BSTriShape*               IsTriShape();                                                     // 08
		virtual BSDynamicTriShape*        IsDynamicTriShape();                                              // 09
		virtual BSSegmentedTriShape*      IsSegmentedTriShape();                                            // 0A
		virtual BSSubIndexTriShape*       IsSubIndexTriShape();                                             // 0B
		virtual NiGeometry*               IsNiGeometry();                                                   // 0C
		virtual NiTriBasedGeom*           IsNiTriBasedGeom();                                               // 0D
		virtual NiTriShape*               IsNiTriShape();                                                   // 0E
		virtual NiParticles*              IsParticlesGeom();                                                // 0F
		virtual NiParticleSystem*         IsParticleSystem();                                               // 10
		virtual BSLines*                  IsLinesGeom();                                                    // 11
		virtual NiLight*                  IsLight();                                                        // 12
		virtual bhkNiCollisionObject*     IsBhkNiCollisionObject();                                         // 13
		virtual bhkBlendCollisionObject   IsBhkBlendCollisionObject();                                      // 14
		virtual bhkRigidBody              IsBhkRigidBody();                                                 // 15
		virtual bhkLimitedHingeConstraint IsBhkLimitedHingeConstraint();                                    // 16
		virtual bhkNPCollisionObject      IsbhkNPCollisionObject();                                         // 17
		virtual ~NiCullingProcess();                                                                        // 18
		virtual void Process(NiAVObject* a_object);                                                         // 19
		virtual void Process(const NiCamera* a_camera, NiAVObject* a_scene, NiVisibleArray* a_visibleSet);  // 1A
		virtual void AppendVirtual(BSGeometry* a_visible);                                                  // 1B

		// members
		bool            useVirtualAppend;      // 08
		NiVisibleArray* visibleSet;            // 10
		NiCamera*       camera;                // 18
		NiFrustum       frustum;               // 20
		NiFrustumPlanes planes;                // 3C
		NiFrustumPlanes customCullPlanes;      // AC
		bool            cameraRelatedUpdates;  // 11C
		bool            updateAccumulateFlag;  // 11D
		bool            ignorePreprocess;      // 11E
		bool            bCustomCullPlanes;     // 11F
	};
	static_assert(sizeof(NiCullingProcess) == 0x120);
}
