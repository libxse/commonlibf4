#pragma once

namespace RE
{
	enum class CrosshairMode;

	class PlayerCrosshairModeEvent :
		public BSTValueEvent<CrosshairMode>
	{
	private:
		using EventSource_t = BSTGlobalEvent::EventSource<PlayerCrosshairModeEvent>;

	public:
		[[nodiscard]] static EventSource_t* GetEventSource()
		{
			static REL::Relocation<EventSource_t**> singleton{ ID::PlayerCrosshairModeEvent::GetEventSource };
			if (!*singleton) {
				*singleton = new EventSource_t(&BSTGlobalEvent::GetSingleton()->eventSourceSDMKiller);
			}
			return *singleton;
		}
	};
	static_assert(sizeof(PlayerCrosshairModeEvent) == 0x08);
}
