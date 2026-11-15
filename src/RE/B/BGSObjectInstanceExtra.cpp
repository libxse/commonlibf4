#include "RE/B/BGSObjectInstanceExtra.h"

#include "RE/B/BGSMod.h"
#include "RE/T/TESBoundObject.h"

namespace RE
{
	void BGSObjectInstanceExtra::CreateBaseInstanceData(const TESBoundObject& a_object, BSTSmartPointer<TBO_InstanceData>& a_instanceData) const
	{
		if (values && itemIndex != static_cast<std::uint16_t>(-1)) {
			a_object.ApplyMods(a_instanceData, this);
		}
	}

	std::span<BGSMod::ObjectIndexData> BGSObjectInstanceExtra::GetIndexData() const noexcept
	{
		if (!values) {
			return {};
		}
		return values->GetBuffer<BGSMod::ObjectIndexData>(0);
	}
}
