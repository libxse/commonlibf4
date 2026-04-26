#pragma once

#include "RE/N/NiObject.h"
#include "RE/N/NiPointer.h"

namespace RE
{
	class ImageSpaceModifierInstanceForm;
	class NiAVObject;

	class ImageSpaceModifierInstance :
		public NiObject  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::ImageSpaceModifierInstance };
		static constexpr auto VTABLE{ VTABLE::ImageSpaceModifierInstance };

		enum class FLAGS
		{
			kNone = 0,
			kPermanent = 1 << 0,
			kCrossfade = 1 << 1,
			kPreviousCrossfade = 1 << 2,
			kMenuIMOD = 1 << 3,
			kStopped = 1 << 4
		};

		virtual ~ImageSpaceModifierInstance();  // 00

		// add
		virtual bool                            IsExpired();                    // 28
		virtual void                            Apply() = 0;                    // 29
		virtual void                            PrintInfo(char* a_buffer) = 0;  // 2A
		virtual ImageSpaceModifierInstanceForm* IsForm();                       // 2B

		void Stop()
		{
			using func_t = decltype(&ImageSpaceModifierInstance::Stop);
			static REL::Relocation<func_t> func{ ID::ImageSpaceModifierInstance::Stop };
			return func(this);
		}

		// members
		float                               strength;  // 10
		NiPointer<NiAVObject>               target;    // 18
		float                               age;       // 20
		REX::TEnumSet<FLAGS, std::uint32_t> flags;     // 24
	};
	static_assert(sizeof(ImageSpaceModifierInstance) == 0x28);
}
