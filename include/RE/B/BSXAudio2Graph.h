#pragma once

#include "REX/W32/XAUDIO2.h"
#include "REX/W32/XAUDIO2FX.h"

namespace RE
{
	struct ReverbSendData
	{
		// members
		REX::W32::XAUDIO2FX_REVERB_I3DL2_PARAMETERS m_currentParams{ REX::W32::XAUDIO2FX_I3DL2_PRESET_DEFAULT };  // 0x00
		REX::W32::XAUDIO2FX_REVERB_I3DL2_PARAMETERS m_targetParams{ REX::W32::XAUDIO2FX_I3DL2_PRESET_DEFAULT };   // 0x34
		REX::W32::IUnknown*                         m_effectAPO{ nullptr };                                       // 0x68
		REX::W32::IXAudio27SubmixVoice*             m_reverbVoice{ nullptr };                                     // 0x70
		std::uint64_t                               m_transitionStart{ 0 };                                       // 0x78
		std::uint64_t                               m_transitionEnd{ 0 };                                         // 0x80
	};
	static_assert(sizeof(ReverbSendData) == 0x88);

	class __declspec(novtable) BSXAudio2Graph :
		public REX::W32::IXAudio2EngineCallback
	{
	public:
		inline static constexpr auto RTTI = RE::RTTI::__BSXAudio2Graph;
		inline static constexpr auto VTABLE = RE::VTABLE::__BSXAudio2Graph[0];

		[[nodiscard]] static BSXAudio2Graph* GetSingleton()
		{
			static REL::Relocation<BSXAudio2Graph**> singleton{ ID::BSXAudio2Graph::Singleton };
			return *singleton;
		}

		[[nodiscard]] BSXAudio2Graph* Ctor(bool a_protected)
		{
			using func_t = decltype(&BSXAudio2Graph::Ctor);
			static REL::Relocation<func_t> func{ ID::BSXAudio2Graph::Ctor };
			return func(this, a_protected);
		}

		// override (IXAudio2EngineCallback)
		virtual void OnProcessingPassStart() noexcept override {}

		virtual void OnProcessingPassEnd() noexcept override
		{
			using func_t = decltype(&BSXAudio2Graph::OnProcessingPassEnd);
			static REL::Relocation<func_t> func{ ID::BSXAudio2Graph::OnProcessingPassEnd };
			func(this);
		}

		virtual void OnCriticalError(REX::W32::HRESULT) noexcept override {}

		// members
		REX::W32::IXAudio27*               m_instance;           // 0x008
		REX::W32::IXAudio27MasteringVoice* m_masteringVoice;     // 0x010
		std::array<ReverbSendData, 2>      m_reverbSendArray;    // 0x018
		std::uint32_t                      m_masterChannelMask;  // 0x128
		std::uint32_t                      m_outputChannels;     // 0x12C
		bool                               m_reverbInitialized;  // 0x130
		bool                               m_valid;              // 0x131
		bool                               m_canMonitor;         // 0x132
	};
	static_assert(sizeof(BSXAudio2Graph) == 0x138);
}
