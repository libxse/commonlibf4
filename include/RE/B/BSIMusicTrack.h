#pragma once

namespace RE
{
	class __declspec(novtable) BSIMusicTrack
	{
	public:
		static constexpr auto RTTI{ RTTI::BSIMusicTrack };
		static constexpr auto VTABLE{ VTABLE::BSIMusicTrack };

		enum class MUSIC_STATUS
		{
			kInactive = 0x0,
			kPlaying = 0x1,
			kPaused = 0x2,
			kFinishing = 0x3,
			kFinished = 0x4
		};

		virtual ~BSIMusicTrack() = default;  // 00

		// add
		virtual void          DoUpdate() = 0;                                                                // 01
		virtual void          DoPlay() = 0;                                                                  // 02
		virtual void          DoPause() = 0;                                                                 // 03
		virtual void          DoFinish(bool a_immediate, float a_fadeTime) = 0;                              // 04
		virtual float         GetDurationImpl() const = 0;                                                   // 05
		virtual std::uint32_t GetType() const = 0;                                                           // 06
		virtual bool          TestCanPlay() const { return true; }                                           // 07
		virtual MUSIC_STATUS  GetMusicStatus() const { return *trackStatus; }                                // 08
		virtual void          DoSetDuckingAttenuation([[maybe_unused]] std::uint16_t a_ducking) { return; }  // 09
		virtual void          DoClearDucking() { return; }                                                   // 0A

		// members
		REX::TEnumSet<MUSIC_STATUS, std::int32_t> trackStatus;  // 08
	};
	static_assert(sizeof(BSIMusicTrack) == 0x10);
}
