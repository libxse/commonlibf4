#pragma once

#include "RE/N/NiBound.h"
#include "RE/N/NiCollisionObject.h"
#include "RE/N/NiObjectNET.h"
#include "RE/N/NiPointer.h"
#include "RE/N/NiTFlags.h"
#include "RE/N/NiTransform.h"

namespace RE
{
	class NiAlphaProperty;
	class NiCullingProcess;
	class NiNode;
	class NiUpdateData;
	class PerformOpFunc;

	class __declspec(novtable) NiAVObject :
		public NiObjectNET  // 000
	{
	public:
		F4_HEAP_REDEFINE_ALIGNED_NEW(NiAVObject);

		static constexpr auto RTTI{ RTTI::NiAVObject };
		static constexpr auto VTABLE{ VTABLE::NiAVObject };
		static constexpr auto Ni_RTTI{ Ni_RTTI::NiAVObject };

		enum class Flag : std::uint64_t
		{
			kAlwaysDraw = 1ull << 11,
			kMeshLOD = 1ull << 12,
			kFixedWorldBound = 1ull << 13
		};

		NiAVObject();
		virtual ~NiAVObject();  // NOLINT(modernize-use-override) 00

		// add
		virtual void        UpdateControllers(NiUpdateData& a_data);                                                            // 28
		virtual void        PerformOp(PerformOpFunc& a_operation);                                                              // 29
		virtual void        AttachProperty([[maybe_unused]] NiAlphaProperty* a_prop) { return; }                                // 2A
		virtual void        SetMaterialNeedsUpdate(bool) { return; }                                                            // 2B
		virtual void        SetDefaultMaterialNeedsUpdateFlag(bool) { return; }                                                 // 2C
		virtual void        SetAppCulled(bool a_appCulled);                                                                     // 2D
		virtual NiAVObject* GetObjectByName(const BSFixedString& a_name) { return name == a_name ? this : nullptr; }            // 2E
		virtual void        SetSelectiveUpdateFlags(bool& a_selectiveUpdate, bool a_selectiveUpdateTransforms, bool& a_rigid);  // 2F
		virtual void        UpdateDownwardPass(NiUpdateData& a_data, std::uint32_t a_flags);                                    // 30
		virtual void        UpdateSelectedDownwardPass(NiUpdateData& a_data, std::uint32_t a_flags);                            // 31
		virtual void        UpdateRigidDownwardPass(NiUpdateData& a_data, std::uint32_t a_flags);                               // 32
		virtual void        UpdateWorldBound() { return; }                                                                      // 33
		virtual void        UpdateWorldData(NiUpdateData* a_data);                                                              // 34
		virtual void        UpdateTransformAndBounds(NiUpdateData& a_data);                                                     // 35
		virtual void        UpdateTransforms(NiUpdateData& a_data) { UpdateWorldData(std::addressof(a_data)); }                 // 36
		virtual void        PreAttachUpdate(NiNode* a_eventualParent, NiUpdateData& a_data);                                    // 37
		virtual void        PostAttachUpdate();                                                                                 // 38
		virtual void        OnVisible([[maybe_unused]] NiCullingProcess& a_culler) { return; }                                  // 39

		bool                         GetAppCulled() const noexcept { return flags.flags & 1; }
		NiPointer<NiCollisionObject> GetCollisionObject() const noexcept { return collisionObject; }
		std::uint64_t                GetFlags() const noexcept { return flags.flags; }
		bool                         HasFlag(Flag a_flag) const noexcept { return flags.flags & static_cast<std::uint64_t>(a_flag); }
		const NiMatrix3&             GetLocalRotate() const noexcept { return local.rotate; }
		float                        GetLocalScale() const noexcept { return local.scale; }
		const NiTransform&           GetLocalTransform() const noexcept { return local; }
		const NiPoint3&              GetLocalTranslate() const noexcept { return local.translate; }
		const NiMatrix3&             GetWorldRotate() const noexcept { return world.rotate; }
		float                        GetWorldScale() const noexcept { return world.scale; }
		const NiTransform&           GetWorldTransform() const noexcept { return world; }
		const NiPoint3&              GetWorldTranslate() const noexcept { return world.translate; }
		void                         SetLocalRotate(const NiMatrix3& a_rotate) noexcept { local.rotate = a_rotate; }
		void                         SetLocalScale(float a_scale) noexcept { local.scale = a_scale; }
		void                         SetLocalTransform(const NiTransform& a_transform) noexcept { local = a_transform; }
		void                         SetLocalTranslate(const NiPoint3& a_translate) noexcept { local.translate = a_translate; }
		void                         SetWorldRotate(const NiMatrix3& a_rotate) noexcept { world.rotate = a_rotate; }
		void                         SetWorldScale(float a_scale) noexcept { world.scale = a_scale; }
		void                         SetWorldTransform(const NiTransform& a_transform) noexcept { world = a_transform; }
		void                         SetWorldTranslate(const NiPoint3& a_translate) noexcept { world.translate = a_translate; }
		bool                         ShadowCaster() const noexcept { return ~(flags.flags >> 40) & 1; }
		void                         CullGeometry(bool a_cull);
		void                         CullNode(bool a_cull);
		void                         Update(NiUpdateData& a_data);

		// members
		NiNode*                             parent{ nullptr };          // 027
		NiTransform                         local;                      // 030
		NiTransform                         world;                      // 070
		NiBound                             worldBound;                 // 0B0
		NiTransform                         previousWorld;              // 0C0
		NiPointer<NiCollisionObject>        collisionObject;            // 100
		NiTFlags<std::uint64_t, NiAVObject> flags;                      // 108
		std::uintptr_t                      userData{ 0 };              // 110
		float                               fadeAmount{ 1.0F };         // 118
		std::int8_t                         multType{ 0 };              // 11C
		std::int8_t                         meshLODFadingLevel{ 0 };    // 11D
		std::int8_t                         currentMeshLODLevel{ 0 };   // 11E
		std::int8_t                         previousMeshLODLevel{ 0 };  // 11F
	};
	static_assert(sizeof(NiAVObject) == 0x120);
}
