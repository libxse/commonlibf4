#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/N/NiObject.h"
#include "RE/N/NiPointer.h"

namespace RE
{
	class BSAnimNote;
	class NiAVObject;
	class NiControllerManager;
	class NiStringPalette;
	class NiTextKeyExtraData;

	class NiControllerSequence :
		public NiObject  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::NiControllerSequence };
		static constexpr auto VTABLE{ VTABLE::NiControllerSequence };
		static constexpr auto Ni_RTTI{ Ni_RTTI::NiControllerSequence };

		enum class AnimState : std::int32_t
		{
			kInactive = 0x0,
			kAnimating = 0x1,
			kEaseIn = 0x2,
			kEaseOut = 0x3,
			kTransSource = 0x4,
			kTransDest = 0x5,
			kMorphSource = 0x6
		};

		class IDTag
		{
		public:
			// members
			BSFixedString avObjectName;    // 00
			BSFixedString propertyType;    // 08
			BSFixedString ctrlType;        // 10
			BSFixedString ctrlID;          // 18
			BSFixedString interpolatorID;  // 20
		};
		static_assert(sizeof(IDTag) == 0x28);

		class InterpArrayItem;

		bool Activate(std::uint8_t a_priority, bool a_startOver, float a_weight, float a_easeInTime, NiControllerSequence* a_timeSyncSeq, bool a_transition)
		{
			using func_t = decltype(&NiControllerSequence::Activate);
			static REL::Relocation<func_t> func{ ID::NiControllerSequence::Activate };
			return func(this, a_priority, a_startOver, a_weight, a_easeInTime, a_timeSyncSeq, a_transition);
		}

		// members
		BSFixedString                          name;                     // 10
		std::uint32_t                          arraySize;                // 18
		std::uint32_t                          arrayGrowBy;              // 1C
		InterpArrayItem*                       interpArray;              // 20
		IDTag*                                 idTagArray;               // 28
		float                                  seqWeight;                // 30
		NiPointer<NiTextKeyExtraData>          textKeys;                 // 38
		std::byte                              cycleType[4];             // 40
		float                                  frequency;                // 44
		float                                  beginKeyTime;             // 48
		float                                  endKeyTime;               // 4C
		float                                  lastTime;                 // 50
		float                                  weightedLastTime;         // 54
		float                                  lastScaledTime;           // 58
		NiControllerManager*                   owner;                    // 60
		REX::TEnumSet<AnimState, std::int32_t> state;                    // 68
		float                                  offset;                   // 6C
		float                                  startTime;                // 70
		float                                  endTime;                  // 74
		float                                  destFrame;                // 78
		NiControllerSequence*                  partnerSequence;          // 80
		BSFixedString                          accumRootName;            // 88
		NiAVObject*                            accumRoot;                // 90
		NiPointer<NiStringPalette>             deprecatedStringPalette;  // 98
		std::int16_t                           curAnimNIdx;              // A0
		NiPointer<BSAnimNote>*                 animNotes;                // A8
		std::uint16_t                          numNotes;                 // B0
		bool                                   removableObjects;         // B2
	};
	static_assert(sizeof(NiControllerSequence) == 0xB8);
}
