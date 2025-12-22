#pragma once

namespace RE
{
	class BSPathingStreamRead;
	class BSPathingStreamWrite;
	class ICheckEndReachedFunctorMapper;
	class MovementPlannerAgentReturnDataSmallDelta;
	class MovementTweenerAgentOutputData;
	class PathFollowerStateUpdateData;

	class IPathFollowerState
	{
	public:
		static constexpr auto RTTI{ RTTI::IPathFollowerState };
		static constexpr auto VTABLE{ VTABLE::IPathFollowerState };

		enum class PATH_FOLLOWER_STATE_RESULT : std::uint32_t
		{
			kContinue = 0x0,
			kDone = 0x1
		};

		virtual ~IPathFollowerState();  // 00

		// add
		virtual IPathFollowerState::PATH_FOLLOWER_STATE_RESULT Update(const PathFollowerStateUpdateData*, MovementPlannerAgentReturnDataSmallDelta*, MovementTweenerAgentOutputData*);  // 01
		virtual void                                           SaveGame(BSPathingStreamWrite*, const ICheckEndReachedFunctorMapper*) = 0;                                               // 02
		virtual void                                           LoadGame(BSPathingStreamRead*, const ICheckEndReachedFunctorMapper*) = 0;                                                // 03
	};
	static_assert(sizeof(IPathFollowerState) == 0x8);
}
