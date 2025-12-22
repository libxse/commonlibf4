#pragma once

namespace RE
{
	class BSISoundOutputModel;

	class BSSoundHandle
	{
	public:
		~BSSoundHandle() noexcept {}  // NOLINT(modernize-use-equals-default)

		enum class ASSUMED_STATE : std::uint32_t
		{
			kInitialized = 0x0,
			kPlaying = 0x1,
			kStopped = 0x2,
			kPaused = 0x3
		};

		enum class LOOP_TYPE : std::uint32_t
		{
			kNone = 0x0,
			kWholeFile = 0x1,
			kEnvFast = 0x2,
			kEnvSlow = 0x3
		};

		bool FadeInPlay(std::uint16_t a_milliseconds)
		{
			using func_t = decltype(&BSSoundHandle::FadeInPlay);
			static REL::Relocation<func_t> func{ ID::BSSoundHandle::FadeInPlay };
			return func(this, a_milliseconds);
		}

		bool FadeOutAndRelease(std::uint16_t a_milliseconds)
		{
			using func_t = decltype(&BSSoundHandle::FadeOutAndRelease);
			static REL::Relocation<func_t> func{ ID::BSSoundHandle::FadeOutAndRelease };
			return func(this, a_milliseconds);
		}

		bool IsPlaying() const
		{
			using func_t = decltype(&BSSoundHandle::IsPlaying);
			static REL::Relocation<func_t> func{ ID::BSSoundHandle::IsPlaying };
			return func(this);
		}

		bool Play()
		{
			using func_t = decltype(&BSSoundHandle::Play);
			static REL::Relocation<func_t> func{ ID::BSSoundHandle::Play };
			return func(this);
		}

		bool SetOutputModel(const BSISoundOutputModel* a_outputModel)
		{
			using func_t = decltype(&BSSoundHandle::SetOutputModel);
			static REL::Relocation<func_t> func{ ID::BSSoundHandle::SetOutputModel };
			return func(this, a_outputModel);
		}

		bool Stop()
		{
			using func_t = decltype(&BSSoundHandle::Stop);
			static REL::Relocation<func_t> func{ ID::BSSoundHandle::Stop };
			return func(this);
		}

		// members
		std::uint32_t soundID;        // 0
		bool          assumeSuccess;  // 4
		std::int8_t   state;          // 5
	};
	static_assert(sizeof(BSSoundHandle) == 0x8);
}
