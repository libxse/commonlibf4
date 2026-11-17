#pragma once

namespace RE
{
	class NiAVObject;

	class BSPreCulledObjects
	{
	public:
		class ObjectRecord
		{
		public:
			// members
			NiAVObject*   obj{ nullptr };  // 00
			std::uint32_t flags{ 0 };      // 08
		};
		static_assert(sizeof(ObjectRecord) == 0x10);

		[[nodiscard]] static bool QTempDisabled()
		{
			using func_t = decltype(&BSPreCulledObjects::QTempDisabled);
			static REL::Relocation<func_t> func{ ID::BSPreCulledObjects::QTempDisabled };
			return func();
		}

		static void SetTempDisabled(bool a_disabled, bool a_notify)
		{
			using func_t = decltype(&BSPreCulledObjects::SetTempDisabled);
			static REL::Relocation<func_t> func{ ID::BSPreCulledObjects::SetTempDisabled };
			func(a_disabled, a_notify);
		}
	};
	static_assert(std::is_empty_v<BSPreCulledObjects>);
}
