#pragma once

#include "RE/B/bhkNPCollisionObjectBase.h"
#include "RE/H/hknpMotionPropertiesId.h"
#include "RE/N/NiPointer.h"

namespace RE
{
	class bhkPhysicsSystem;
	class bhkWorld;
	class CFilter;
	class hknpBody;
	class hknpBodyId;
	class hknpShape;
	class hkTransformf;

	class __declspec(novtable) bhkNPCollisionObject :
		public bhkNPCollisionObjectBase  // 00
	{
	public:
		inline static constexpr auto RTTI{ RTTI::bhkNPCollisionObject };
		inline static constexpr auto VTABLE{ VTABLE::bhkNPCollisionObject };
		inline static constexpr auto Ni_RTTI{ Ni_RTTI::bhkNPCollisionObject };

		// add
		virtual void CreateInstance(bhkWorld& a_world);             // 2D
		virtual void AddToWorld(bhkWorld& a_world);                 // 2E
		virtual void RemoveFromWorld();                             // 2F
		virtual bool SetCollisionFilterInfo(CFilter a_filterInfo);  // 30

		void CopyMembers(bhkNPCollisionObject* a_dest, NiCloningProcess& a_cloningProcess)
		{
			using func_t = decltype(&bhkNPCollisionObject::CopyMembers);
			static REL::Relocation<func_t> func{ ID::bhkNPCollisionObject::CopyMembers };
			func(this, a_dest, a_cloningProcess);
		}

		const hknpBody* GetBody()
		{
			using func_t = decltype(&bhkNPCollisionObject::GetBody);
			static REL::Relocation<func_t> func{ ID::bhkNPCollisionObject::GetBody };
			return func(this);
		}

		hknpBodyId& GetBodyId(hknpBodyId& a_id)
		{
			using func_t = decltype(&bhkNPCollisionObject::GetBodyId);
			static REL::Relocation<func_t> func{ ID::bhkNPCollisionObject::GetBodyId };
			return func(this, a_id);
		}

		bhkPhysicsSystem* GetPhysicsSystem()
		{
			return system.get();
		}

		hknpShape* GetShape()
		{
			using func_t = decltype(&bhkNPCollisionObject::GetShape);
			static REL::Relocation<func_t> func{ ID::bhkNPCollisionObject::GetShape };
			return func(this);
		}

		bool GetTransform(hkTransformf& a_transform)
		{
			using func_t = decltype(&bhkNPCollisionObject::GetTransform);
			static REL::Relocation<func_t> func{ ID::bhkNPCollisionObject::GetTransform };
			return func(this, a_transform);
		}

		void SetMotionType(hknpMotionPropertiesId::Preset a_type)
		{
			using func_t = decltype(&bhkNPCollisionObject::SetMotionType);
			static REL::Relocation<func_t> func{ ID::bhkNPCollisionObject::SetMotionType };
			func(this, a_type);
		}

		bool SetTransform(hkTransformf& a_transform)
		{
			using func_t = decltype(&bhkNPCollisionObject::SetTransform);
			static REL::Relocation<func_t> func{ ID::bhkNPCollisionObject::SetTransform };
			return func(this, a_transform);
		}

		static bhkNPCollisionObject* Getbhk(bhkWorld* a_world, hknpBodyId& a_bodyId)
		{
			using func_t = decltype(&bhkNPCollisionObject::Getbhk);
			static REL::Relocation<func_t> func{ ID::bhkNPCollisionObject::Getbhk };
			return func(a_world, a_bodyId);
		}

		// members
		NiPointer<bhkPhysicsSystem> system;         // 20
		std::uint32_t               systemBodyIdx;  // 28
	};
	static_assert(sizeof(bhkNPCollisionObject) == 0x30);
}
