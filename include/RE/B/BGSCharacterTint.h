#pragma once

#include "RE/B/BGSLocalizedString.h"
#include "RE/B/BSFixedString.h"
#include "RE/B/BSTArray.h"
#include "RE/T/TESCondition.h"

namespace RE
{
	namespace BGSCharacterTint
	{
		enum class BlendOp : std::uint32_t
		{
			kDefault = 0x0,
			kMultiply = 0x1,
			kOverlay = 0x2,
			kSoftLight = 0x3,
			kHardLight = 0x4,
			kTotal = 0x5
		};

		enum class EntryType : std::uint32_t
		{
			kMask = 0x0,
			kPalette = 0x1,
			kTexture = 0x2,
			kUnknown = 0x3
		};

		enum class EntrySlot
		{
			kForeheadMask = 0x0,
			kEyesMask = 0x1,
			kNoseMask = 0x2,
			kEarsMask = 0x3,
			kCheeksMask = 0x4,
			kMouthMask = 0x5,
			kNeckMask = 0x6,
			kLipColor = 0x7,
			kCheekColor = 0x8,
			kEyeliner = 0x9,
			kEyeSocketUpper = 0xA,
			kEyeSocketLower = 0xB,
			kSkinTone = 0xC,
			kPaint = 0xD,
			kLaughLines = 0xE,
			kCheekColorLower = 0xF,
			kNose = 0x10,
			kChin = 0x11,
			kNeck = 0x12,
			kForehead = 0x13,
			kDirt = 0x14,
			kScars = 0x15,
			kFaceDetail = 0x16,
			kBrow = 0x17,
			kWrinkles = 0x18,
			kBeard = 0x19
		};

		namespace Template
		{
			class __declspec(novtable) Entry
			{
			public:
				static constexpr auto RTTI{ RTTI::BGSCharacterTint__Template__Entry };
				static constexpr auto VTABLE{ VTABLE::BGSCharacterTint__Template__Entry };

				enum Flags : std::uint32_t
				{
					kOnOffOnly = 0x1,
					kIsChargenDetaul = 0x2,
					kTakesSkinTone = 0x4
				};

				Entry() { REX::EMPLACE_VTABLE(this); }
				virtual ~Entry() = default;  // 00

				F4_HEAP_REDEFINE_NEW(Entry);

				// add
				virtual float GetDefaultValue() { return 0.0F; }                    // 01
				virtual void  InitItem(TESForm* a_owner);                           // 02
				virtual void  CopyData(BGSCharacterTint::Template::Entry* a_copy);  // 03
				virtual void  LoadImpl(TESFile* a_file);                            // 04

				// members
				BGSLocalizedString                                       name;               // 08
				TESCondition                                             chargenConditions;  // 10
				REX::TEnumSet<BGSCharacterTint::EntrySlot, std::int32_t> slot;               // 18
				const std::uint16_t                                      uniqueID{ 0 };      // 1C
				std::int8_t                                              flags;              // 1E
			};
			static_assert(sizeof(Entry) == 0x20);

			class Group
			{
			public:
				Entry* GetTemplateBySlot(BGSCharacterTint::EntrySlot a_slot);
				Entry* GetTemplateByUniqueID(std::uint16_t a_id);

				// members
				BGSLocalizedString name;          // 00
				std::uint32_t      id;            // 08
				std::uint32_t      chargenIndex;  // 0C
				BSTArray<Entry*>   entries;       // 10
			};
			static_assert(sizeof(Group) == 0x28);

			class Groups
			{
			public:
				Entry* GetTemplateBySlot(BGSCharacterTint::EntrySlot a_slot);
				Entry* GetTemplateByUniqueID(std::uint16_t a_id);

				// members
				BSTArray<Group*> groups;  // 00
			};
			static_assert(sizeof(Groups) == 0x18);

			class __declspec(novtable) Mask :
				public Entry
			{
			public:
				static constexpr auto RTTI{ RTTI::BGSCharacterTint__Template__Mask };
				static constexpr auto VTABLE{ VTABLE::BGSCharacterTint__Template__Mask };

				Mask() { REX::EMPLACE_VTABLE(this); }

				// Members
				BSFixedString             maskTextureName;
				BGSCharacterTint::BlendOp blendOp;
				std::uint32_t             unk2C;
			};
			static_assert(sizeof(Mask) == 0x30);

			class __declspec(novtable) Palette :
				public Entry
			{
			public:
				static constexpr auto RTTI{ RTTI::BGSCharacterTint__Template__Palette };
				static constexpr auto VTABLE{ VTABLE::BGSCharacterTint__Template__Palette };

				Palette() { REX::EMPLACE_VTABLE(this); }

				class ColorValue
				{
				public:
					BGSColorForm* color;     // 00
					float         value;     // 08
					BlendOp       blendOp;   // 0C
					std::uint16_t swatchID;  // 01
				};
				static_assert(sizeof(ColorValue) == 0x18);

				ColorValue* GetColorDataBySwatchID(std::uint16_t a_id);

				// Members
				BSFixedString        maskTextureName;
				std::uint32_t        defaultIndex;
				BSTArray<ColorValue> colorValues;
			};
			static_assert(sizeof(Palette) == 0x48);

			class __declspec(novtable) TextureSet :
				public Entry
			{
			public:
				static constexpr auto RTTI{ RTTI::BGSCharacterTint__Template__TextureSet };
				static constexpr auto VTABLE{ VTABLE::BGSCharacterTint__Template__TextureSet };

				TextureSet() { REX::EMPLACE_VTABLE(this); }

				// Members
				BSFixedString	          diffuse;
				BSFixedString             normal;
				BSFixedString             specular;
				BGSCharacterTint::BlendOp blendOp;
				float                     defaultValue;
			};
			static_assert(sizeof(TextureSet) == 0x40);
		}

		class __declspec(novtable) Entry
		{
		public:
			static constexpr auto RTTI{ RTTI::BGSCharacterTint__Entry };
			static constexpr auto VTABLE{ VTABLE::BGSCharacterTint__Entry };

			Entry() { REX::EMPLACE_VTABLE(this); }
			virtual ~Entry() = default;  // 00

			F4_HEAP_REDEFINE_NEW(Entry);

			virtual bool      GetIsIdentical(const Entry* entry);                       // 08
			virtual bool      CopyData(const Entry entry);                              // 10
			virtual bool      SetFromTemplateDefault(const Template::Entry* entry);     // 18
			virtual bool      GetMatchesTemplateDefault(const Template::Entry* entry);  // 20
			virtual EntryType GetType();                                                // 28

			[[nodiscard]] static Entry* CreateCharacterTintEntry(std::uint32_t a_id) noexcept;
			static void ClearCharacterTints(class Entries* a_src) noexcept;
			static void CopyCharacterTints(class Entries* a_dst, class Entries* a_src) noexcept;

			// Members
			Entry*        templateEntry;  // 08
			std::uint16_t idLink;         // 10
			std::uint8_t  tingingValue;   // 12
		};
		static_assert(sizeof(Entry) == 0x18);

		class Entries
		{
		public:
			BSTArray<Entry*> entriesA;
		};
		static_assert(sizeof(Entries) == 0x18);

		class __declspec(novtable) MaskEntry :
			public Entry
		{
		public:
			static constexpr auto RTTI{ RTTI::BGSCharacterTint__MaskEntry };
			static constexpr auto VTABLE{ VTABLE::BGSCharacterTint__MaskEntry };

			MaskEntry() { REX::EMPLACE_VTABLE(this); }
		};
		static_assert(sizeof(MaskEntry) == 0x18);

		class __declspec(novtable) PaletteEntry :
			public MaskEntry
		{
		public:
			static constexpr auto RTTI{ RTTI::BGSCharacterTint__PaletteEntry };
			static constexpr auto VTABLE{ VTABLE::BGSCharacterTint__PaletteEntry };

			PaletteEntry() { REX::EMPLACE_VTABLE(this); }

			// members
			union
			{
				struct
				{
					std::uint8_t r;
					std::uint8_t g;
					std::uint8_t b;
					std::uint8_t x;
				} tintingChannels;
				std::uint32_t tintingColor;
			};  // 18
			std::uint16_t swatchID;  // 1C
		};
		static_assert(sizeof(PaletteEntry) == 0x20);

		class __declspec(novtable) TextureSetEntry :
			public Entry
		{
		public:
			static constexpr auto RTTI{ RTTI::BGSCharacterTint__TextureSetEntry };
			static constexpr auto VTABLE{ VTABLE::BGSCharacterTint__TextureSetEntry };

			TextureSetEntry() { REX::EMPLACE_VTABLE(this); }
		};
		static_assert(sizeof(TextureSetEntry) == 0x18);
	}
}
