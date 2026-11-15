#pragma once

namespace RE
{
	class BGSSoundDescriptorForm;
	class BGSSoundOutput;
	class NiAVObject;
	class NiPoint3;

	class BGSAudio
	{
	public:
		static BGSSoundDescriptorForm* GetSoundDescriptor(const char* a_formName)
		{
			using func_t = decltype(&BGSAudio::GetSoundDescriptor);
			static REL::Relocation<func_t> func{ ID::BGSAudio::GetSoundDescriptor };
			return func(a_formName);
		}

		static const BGSSoundOutput* GetUIOutputModel()
		{
			using func_t = decltype(&BGSAudio::GetUIOutputModel);
			static REL::Relocation<func_t> func{ ID::BGSAudio::GetUIOutputModel };
			return func();
		}

		static void PlaySoundDescriptor(BGSSoundDescriptorForm* a_descriptor, std::uint32_t a_usageFlags, const NiPoint3* a_position, NiAVObject* a_objectToFollow)
		{
			using func_t = decltype(&BGSAudio::PlaySoundDescriptor);
			static REL::Relocation<func_t> func{ ID::BGSAudio::PlaySoundDescriptor };
			return func(a_descriptor, a_usageFlags, a_position, a_objectToFollow);
		}
	};
}
