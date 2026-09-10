#pragma once

#include "RE/B/BSPointerHandle.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTEvent.h"
#include "RE/B/BSTHashMap.h"
#include "RE/N/NiPoint3.h"
#include "RE/P/PipboyDataGroup.h"

namespace RE
{
	class BGSActorCellEvent;
	class MapMarkerData;
	class PipboyArray;
	class PlayerUpdateEvent;
	class TESLocationClearedEvent;

	namespace ActorValueEvents
	{
		class ActorValueChangedEvent;
	}

	namespace CustomMarkerUpdate
	{
		class Event;
	}

	namespace LocalMapCameraUpdate
	{
		class Event;
	}

	namespace LocationMarkerArrayUpdate
	{
		class Event;
	}

	namespace MapMarker
	{
		enum class MARKER_SCOPE;
	}

	namespace PlayerCharacterQuestEvent
	{
		class Event;
	}

	namespace TESQuestEvent
	{
		class Event;
	}

	namespace TravelMarkerStateChange
	{
		class Event;
	}

	class __declspec(novtable) PipboyMapData :
		public PipboyDataGroup,                                        // 00
		public BSTEventSink<TravelMarkerStateChange::Event>,           // 98
		public BSTEventSink<PlayerUpdateEvent>,                        // A0
		public BSTEventSink<BGSActorCellEvent>,                        // A8
		public BSTEventSink<TESQuestEvent::Event>,                     // B0
		public BSTEventSink<PlayerCharacterQuestEvent::Event>,         // B8
		public BSTEventSink<CustomMarkerUpdate::Event>,                // C0
		public BSTEventSink<LocationMarkerArrayUpdate::Event>,         // C8
		public BSTEventSink<LocalMapCameraUpdate::Event>,              // D0
		public BSTEventSink<TESLocationClearedEvent>,                  // D8
		public BSTEventSink<ActorValueEvents::ActorValueChangedEvent>  // E0
	{
	public:
		static constexpr auto RTTI{ RTTI::PipboyMapData };
		static constexpr auto VTABLE{ VTABLE::PipboyMapData };

		virtual ~PipboyMapData() = default;

		virtual BSEventNotifyControl ProcessEvent(const TravelMarkerStateChange::Event& a_event, BSTEventSource<TravelMarkerStateChange::Event>* a_source);                      // 01
		virtual BSEventNotifyControl ProcessEvent(const PlayerUpdateEvent& a_event, BSTEventSource<PlayerUpdateEvent>* a_source);                                                // 02
		virtual BSEventNotifyControl ProcessEvent(const BGSActorCellEvent& a_event, BSTEventSource<BGSActorCellEvent>* a_source);                                                // 03
		virtual BSEventNotifyControl ProcessEvent(const TESQuestEvent::Event& a_event, BSTEventSource<TESQuestEvent::Event>* a_source);                                          // 04
		virtual BSEventNotifyControl ProcessEvent(const PlayerCharacterQuestEvent::Event& a_event, BSTEventSource<PlayerCharacterQuestEvent::Event>* a_source);                  // 05
		virtual BSEventNotifyControl ProcessEvent(const CustomMarkerUpdate::Event& a_event, BSTEventSource<CustomMarkerUpdate::Event>* a_source);                                // 06
		virtual BSEventNotifyControl ProcessEvent(const LocationMarkerArrayUpdate::Event& a_event, BSTEventSource<LocationMarkerArrayUpdate::Event>* a_source);                  // 07
		virtual BSEventNotifyControl ProcessEvent(const LocalMapCameraUpdate::Event& a_event, BSTEventSource<LocalMapCameraUpdate::Event>* a_source);                            // 08
		virtual BSEventNotifyControl ProcessEvent(const TESLocationClearedEvent& a_event, BSTEventSource<TESLocationClearedEvent>* a_source);                                    // 09
		virtual BSEventNotifyControl ProcessEvent(const ActorValueEvents::ActorValueChangedEvent& a_event, BSTEventSource<ActorValueEvents::ActorValueChangedEvent>* a_source);  // 0A

		// override
		virtual void Populate(bool a_arg1) override;  // 0B
		virtual void DoClearData() override;          // 0C
		virtual void DoClearSink() override;          // 0D

		ObjectRefHandle GetTravelLocationRefr(ObjectRefHandle* a_result, std::uint32_t a_markerId)
		{
			using func_t = decltype(&PipboyMapData::GetTravelLocationRefr);
			static REL::Relocation<func_t> func{ ID::PipboyMapData::GetTravelLocationRefr };
			return func(this, a_result, a_markerId);
		}

		void UpdateQuestMarkers(PipboyArray* a_questMarkers, BSTHashMap<ObjectRefHandle, PipboyObject*>* a_questMarkerMap, MapMarker::MARKER_SCOPE a_scope, float a_heightReference)
		{
			using func_t = decltype(&PipboyMapData::UpdateQuestMarkers);
			static REL::Relocation<func_t> func{ ID::PipboyMapData::UpdateQuestMarkers };
			return func(this, a_questMarkers, a_questMarkerMap, a_scope, a_heightReference);
		}

		// members
		PipboyObject*                                   mapObject;                   // E8
		BSTHashMap<const MapMarkerData*, PipboyObject*> travelLocationsMarkers;      // F0
		BSTHashMap<std::uint32_t, ObjectRefHandle>      travelLocationRefrHandles;   // 120
		BSTArray<PipboyObject*>                         doorMarkers;                 // 150
		BSTArray<ObjectRefHandle>                       doorRefHandles;              // 168
		BSTHashMap<ObjectRefHandle, PipboyObject*>      localQuestMarkers;           // 180
		BSTHashMap<ObjectRefHandle, PipboyObject*>      worldQuestMarkers;           // 1B0
		NiPoint3                                        playerLastLocationPosition;  // 1E0
		NiPoint3                                        playerLastWorldPosition;     // 1EC
		PipboyObject*                                   localPlayerMarker;           // 1F8
		PipboyObject*                                   worldPlayerMarker;           // 200
		PipboyObject*                                   localCustomMarker;           // 208
		PipboyObject*                                   worldCustomMarker;           // 210
		PipboyObject*                                   localPowerArmorMarker;       // 218
		PipboyObject*                                   worldPowerArmorMarker;       // 220
		PipboyObject*                                   worldMapExtents;             // 230
		PipboyObject*                                   localMapExtents;             // 238
	};
	static_assert(sizeof(PipboyMapData) == 0x238);
}
