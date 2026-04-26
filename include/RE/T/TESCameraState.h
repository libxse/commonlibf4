#pragma once

#include "RE/B/BSInputEventUser.h"
#include "RE/B/BSIntrusiveRefCounted.h"
#include "RE/B/BSTSmartPointer.h"
#include "RE/C/CameraStates.h"
#include "RE/N/NiPoint.h"
#include "RE/N/NiQuaternion.h"

namespace RE
{
	class BGSLoadFormBuffer;
	class BGSSaveFormBuffer;
	class TESCamera;

	class __declspec(novtable) TESCameraState :
		public BSIntrusiveRefCounted,  // 10
		public BSInputEventUser        // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::TESCameraState };
		static constexpr auto VTABLE{ VTABLE::TESCameraState };

		virtual ~TESCameraState();  // 00

		// add
		virtual void Begin() { return; }                                                         // 09
		virtual void End() { return; }                                                           // 0A
		virtual void Update(BSTSmartPointer<TESCameraState>& a_nextState);                       // 0B
		virtual void GetRotation(NiQuaternion& a_rotation) const;                                // 0C
		virtual void GetTranslation(NiPoint3& a_translation) const;                              // 0D
		virtual void SaveGame([[maybe_unused]] BGSSaveFormBuffer* a_saveGameBuffer) { return; }  // 0E
		virtual void LoadGame([[maybe_unused]] BGSLoadFormBuffer* a_loadGameBuffer) { return; }  // 0F
		virtual void Revert([[maybe_unused]] BGSLoadFormBuffer* a_loadGameBuffer) { return; }    // 10

		// members
		TESCamera*                                camera;  // 18
		REX::TEnumSet<CameraState, std::uint32_t> id;      // 20
	};
	static_assert(sizeof(TESCameraState) == 0x28);
}
