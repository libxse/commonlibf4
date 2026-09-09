#pragma once

#include "RE/B/BSIntrusiveRefCounted.h"
#include "RE/B/BSPathingActorAttributes.h"
#include "RE/B/BSPathingGoal.h"
#include "RE/B/BSPathingRestrictions.h"
#include "RE/B/BSPathingSearchParameters.h"
#include "RE/B/BSPathingStart.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTSmartPointer.h"
#include "RE/M/MeanderSettingsData.h"
#include "RE/M/MovementActorAvoidanceParameters.h"

namespace RE
{
	class BSPathingStreamRead;
	class BSPathingStreamWrite;
	class IDebugText;
	class IMovementParameters;

	class __declspec(novtable) BSPathingRequest :
		public BSIntrusiveRefCounted  // 0008
	{
	public:
		static constexpr auto RTTI{ RTTI::BSPathingRequest };
		static constexpr auto VTABLE{ VTABLE::BSPathingRequest };

		virtual ~BSPathingRequest();                                    // 00
		virtual std::uint32_t GetType();                                // 01
		virtual void          CopyTo(BSPathingRequest* a_dst);          // 02
		virtual void          Write(BSPathingStreamWrite* a_dst);       // 03
		virtual void          Read(BSPathingStreamRead* a_src);         // 04
		virtual void          CheckValid();                             // 05
		virtual void          PrintDebugText(IDebugText* a_debugText);  // 06
		virtual bool          UpdateRequest();                          // 07

		// members
		BSPathingStart                                                         start;                         // 0010
		BSPathingGoal                                                          goal;                          // 0048
		BSPathingRestrictions                                                  restrictions;                  // 0098
		BSPathingSearchParameters                                              searchParameters;              // 00B0
		BSPathingActorAttributes                                               actorAttributes;               // 00C0
		MovementActorAvoidanceParameters                                       avoidanceParameters;           // 00E0
		BSTSmartPointer<IMovementParameters, BSTSmartPointerIntrusiveRefCount> defaultParameters;             // 0100
		MeanderSettingsData                                                    meanderSettings;               // 0108
		BSTArray<BSPathingStart>                                               optionalStartArray;            // 0120
		bool                                                                   shouldMotionCorrectStartIdle;  // 0138
		bool                                                                   requiresPathStartIdle;         // 0139
		bool                                                                   disablePathEndIdle;            // 013A
	};
	static_assert(sizeof(BSPathingRequest) == 0x140);
}
