#pragma once

#include "RE/C/CXAPOBase.h"

namespace RE
{
	class __declspec(novtable) MonitorAPO :
		public CXAPOBase
	{
	public:
		inline static constexpr auto RTTI = RE::RTTI::__MonitorAPO;
		inline static constexpr auto VTABLE = RE::VTABLE::__MonitorAPO[0];

		// override (IXAPO)
		virtual void              Reset() noexcept override;
		virtual REX::W32::HRESULT LockForProcess(std::uint32_t a_inputLockedParameterCount, const REX::W32::XAPO_LOCKFORPROCESS_BUFFER_PARAMETERS* a_inputLockedParameters, std::uint32_t a_outputLockedParameterCount, const REX::W32::XAPO_LOCKFORPROCESS_BUFFER_PARAMETERS* a_outputLockedParameters) noexcept override;
		virtual void              Process(std::uint32_t a_inputProcessParameterCount, const REX::W32::XAPO_PROCESS_BUFFER_PARAMETERS* a_InputProcessParameters, uint32_t a_outputProcessParameterCount, REX::W32::XAPO_PROCESS_BUFFER_PARAMETERS* a_outputProcessParameters, REX::W32::BOOL a_isEnabled) noexcept override;

		// members
		std::uint32_t m_numChannels;  // 30
		float         m_amplitude;    // 34
		float         m_decay;        // 38
		float         m_decayTime;    // 3C
	};
	static_assert(sizeof(MonitorAPO) == 0x40);
}
