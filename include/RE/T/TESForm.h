#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/B/BSSpinLock.h"
#include "RE/B/BSTHashMap.h"
#include "RE/B/BaseFormComponent.h"
#include "RE/E/ENUM_FORM_ID.h"
#include "RE/F/FORM_ENUM_STRING.h"
#include "RE/T/TESFile.h"
#include "RE/T/TESFileContainer.h"

namespace RE
{
	class BGSLoadFormBuffer;
	class BGSPreviewTransform;
	class BGSSaveFormBuffer;
	class BGSSoundTagComponent;

	class __declspec(novtable) TESForm :
		public BaseFormComponent  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::TESForm };
		static constexpr auto VTABLE{ VTABLE::TESForm };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kNONE };

		class FormSortFunc
		{
		public:
			std::int32_t operator()(const TESForm* a_arg1, const TESForm* a_arg2)
			{
				using func_t = decltype(&FormSortFunc::operator());
				static REL::Relocation<func_t> func{ ID::TESForm::FormSortFunc };
				return func(this, a_arg1, a_arg2);
			}
		};
		static_assert(std::is_empty_v<FormSortFunc>);

		// override (BaseFormComponent)
		void InitializeDataComponent() override { return; }          // 02
		void ClearDataComponent() override { SetFormEditorID(""); }  // 03
		void CopyComponent(BaseFormComponent*) override { return; }  // 06

		// add
		virtual void                     InitializeData() { return; }                                                                                                                                                                                     // 07
		virtual void                     ClearData() { return; }                                                                                                                                                                                          // 08
		virtual bool                     Load([[maybe_unused]] TESFile* a_file) { return true; }                                                                                                                                                          // 09
		virtual bool                     LoadPartial([[maybe_unused]] TESFile* a_file) { return true; }                                                                                                                                                   // 0A
		virtual bool                     LoadEdit(TESFile* a_file) { return Load(a_file); }                                                                                                                                                               // 0B
		virtual TESForm*                 CreateDuplicateForm(bool a_createEditorID, BSTHashMap<TESForm*, TESForm*>* a_copyMap);                                                                                                                           // 0C
		virtual bool                     AddChange(std::uint32_t a_changeFlags);                                                                                                                                                                          // 0D
		virtual void                     RemoveChange(std::uint32_t a_changeFlags);                                                                                                                                                                       // 0E
		virtual bool                     FindInFileFast([[maybe_unused]] TESFile* a_file) { return false; }                                                                                                                                               // 0F
		virtual bool                     CheckSaveGame([[maybe_unused]] BGSSaveFormBuffer* a_saveGameBuffer) const { return true; }                                                                                                                       // 10
		virtual void                     SaveGame(BGSSaveFormBuffer* a_saveGameBuffer);                                                                                                                                                                   // 11
		virtual void                     LoadGame(BGSLoadFormBuffer* a_loadGameBuffer);                                                                                                                                                                   // 12
		virtual void                     InitLoadGame([[maybe_unused]] BGSLoadFormBuffer* a_loadGameBuffer) { return; }                                                                                                                                   // 13
		virtual void                     FinishLoadGame([[maybe_unused]] BGSLoadFormBuffer* a_loadGameBuffer) { return; }                                                                                                                                 // 14
		virtual void                     Revert([[maybe_unused]] BGSLoadFormBuffer* a_loadGameBuffer) { return; }                                                                                                                                         // 15
		virtual void                     InitItemImpl() { return; }                                                                                                                                                                                       // 16
		virtual TESFile*                 GetRevertFile() const;                                                                                                                                                                                           // 17
		virtual TESFile*                 GetDescriptionOwnerFile() const;                                                                                                                                                                                 // 18
		virtual ENUM_FORM_ID             GetSavedFormType() const { return *formType; }                                                                                                                                                                   // 19
		virtual void                     GetFormDetailedString(char* a_dest, std::uint32_t a_size) const;                                                                                                                                                 // 1A
		virtual bool                     GetKnown() const { return (formFlags >> 6) & 1; }                                                                                                                                                                // 1B
		virtual bool                     GetRandomAnim() const { return (formFlags >> 16) & 1; }                                                                                                                                                          // 1C
		virtual bool                     GetPlayable([[maybe_unused]] const TBO_InstanceData* a_data) const { return (formFlags >> 2) & 1; }                                                                                                              // 1D
		virtual bool                     IsHeadingMarker() const { return false; }                                                                                                                                                                        // 1E
		virtual bool                     IsHeadtrackMarker() const { return false; }                                                                                                                                                                      // 1F
		virtual bool                     GetDangerous() const { return (formFlags >> 17) & 1; }                                                                                                                                                           // 20
		virtual bool                     QHasCurrents() const { return (formFlags >> 19) & 1; }                                                                                                                                                           // 21
		virtual bool                     GetObstacle() const { return (formFlags >> 25) & 1; }                                                                                                                                                            // 22
		virtual bool                     QIsLODLandObject() const { return false; }                                                                                                                                                                       // 23
		virtual bool                     GetOnLocalMap() const { return (formFlags >> 9) & 1; }                                                                                                                                                           // 24
		virtual bool                     GetMustUpdate() const { return (formFlags >> 8) & 1; }                                                                                                                                                           // 25
		virtual void                     SetOnLocalMap(bool a_val);                                                                                                                                                                                       // 26
		virtual bool                     GetIgnoredBySandbox() const { return false; }                                                                                                                                                                    // 27
		virtual void                     SetDelete(bool a_deleted);                                                                                                                                                                                       // 28
		virtual void                     SetAltered(bool a_altered);                                                                                                                                                                                      // 29
		virtual void                     SaveObjectBound() { return; }                                                                                                                                                                                    // 2A
		virtual void                     LoadObjectBound([[maybe_unused]] TESFile* a_file) { return; }                                                                                                                                                    // 2B
		virtual void                     SavePreviewTransform(CHUNK_ID) { return; }                                                                                                                                                                       // 2C
		virtual void                     LoadPreviewTransform([[maybe_unused]] TESFile* a_file) { return; }                                                                                                                                               // 2D
		virtual bool                     IsBoundObject() const { return false; }                                                                                                                                                                          // 2E
		virtual bool                     IsObject() const { return false; }                                                                                                                                                                               // 2F
		virtual bool                     IsMagicItem() const { return false; }                                                                                                                                                                            // 30
		virtual bool                     IsWater() const { return false; }                                                                                                                                                                                // 31
		virtual TESObjectREFR*           IsReference() { return nullptr; }                                                                                                                                                                                // 33
		virtual const TESObjectREFR*     IsReference() const { return nullptr; }                                                                                                                                                                          // 32
		virtual std::uint32_t            GetRefCount() const { return 0; }                                                                                                                                                                                // 34
		virtual const char*              GetTextForParsedSubTag(const BSFixedString& a_subTag) const;                                                                                                                                                     // 35
		virtual void                     Copy([[maybe_unused]] TESForm* a_copy) { return; }                                                                                                                                                               // 36
		virtual bool                     BelongsInGroup(FORM* a_groupFORM, bool a_allowParentGroups, bool a_currentOnly);                                                                                                                                 // 37
		virtual void                     CreateGroupData(FORM* a_outGroupFORM, FORM_GROUP* a_parentGroup);                                                                                                                                                // 38
		virtual std::uint32_t            GetFormEditorIDLength() const;                                                                                                                                                                                   // 39
		virtual const char*              GetFormEditorID() const { return ""; }                                                                                                                                                                           // 3A
		virtual bool                     SetFormEditorID([[maybe_unused]] const char* a_editorID) { return true; }                                                                                                                                        // 3B
		virtual bool                     IsParentForm() { return false; }                                                                                                                                                                                 // 3C
		virtual bool                     IsParentFormTree() { return false; }                                                                                                                                                                             // 3D
		virtual bool                     IsFormTypeChild([[maybe_unused]] std::uint8_t a_type) { return false; }                                                                                                                                          // 3E
		virtual bool                     LoopingActivate(TESObjectREFR* a_itemActivated, TESObjectREFR* a_actionRef) { return Activate(a_itemActivated, a_actionRef, nullptr, 1); }                                                                       // 3F
		virtual bool                     Activate([[maybe_unused]] TESObjectREFR* a_itemActivated, [[maybe_unused]] TESObjectREFR* a_actionRef, [[maybe_unused]] TESBoundObject* a_objectToGet, [[maybe_unused]] std::int32_t a_count) { return false; }  // 40
		virtual void                     SetFormID(TESFormID a_formID, bool a_updateFile);                                                                                                                                                                // 41
		virtual const char*              GetObjectTypeName() const { return ""; }                                                                                                                                                                         // 42
		virtual bool                     QAvailableInGame() const { return true; }                                                                                                                                                                        // 43
		virtual BGSMod::Template::Items* GetObjectTemplate() { return nullptr; }                                                                                                                                                                          // 44
		virtual BGSPreviewTransform*     GetPreviewTransform() { return nullptr; }                                                                                                                                                                        // 45
		virtual BGSSoundTagComponent*    GetSoundTagComponent() { return nullptr; }                                                                                                                                                                       // 46
		virtual std::uint32_t            GetFilledSlots() const;                                                                                                                                                                                          // 47
		virtual std::uint32_t            GetFilledSlotsImpl() const { return static_cast<std::uint32_t>(-1); }                                                                                                                                            // 48
		virtual float                    GetDesirability([[maybe_unused]] TBO_InstanceData* a_instanceData, [[maybe_unused]] const TESForm* a_user) const { return 0.0F; }                                                                                // 49

		static void AddCompileIndex(std::uint32_t& a_id, TESFile* a_file)
		{
			using func_t = decltype(&TESForm::AddCompileIndex);
			static REL::Relocation<func_t> func{ ID::TESForm::AddCompileIndex };
			return func(a_id, a_file);
		}

		[[nodiscard]] static auto GetAllForms()
			-> std::pair<
				BSTHashMap<std::uint32_t, TESForm*>*,
				std::reference_wrapper<BSReadWriteLock>>
		{
			static REL::Relocation<BSTHashMap<std::uint32_t, TESForm*>**> allForms{ ID::TESForm::AllForms };
			static REL::Relocation<BSReadWriteLock*>                      allFormsMapLock{ ID::TESForm::AllFormsMapLock };
			return { *allForms, *allFormsMapLock };
		}

		[[nodiscard]] static auto GetAllFormsByEditorID()
			-> std::pair<
				BSTHashMap<BSFixedString, TESForm*>*,
				std::reference_wrapper<BSReadWriteLock>>
		{
			static REL::Relocation<BSTHashMap<BSFixedString, TESForm*>**> allFormsByEditorID{ ID::TESForm::AllFormsByEditorID };
			static REL::Relocation<BSReadWriteLock*>                      allFormsEditorIDMapLock{ ID::TESForm::AllFormsEditorIDMapLock };
			return { *allFormsByEditorID, *allFormsEditorIDMapLock };
		}

		[[nodiscard]] bool GetDelete()
		{
			return (formFlags & 0x20);
		}

		[[nodiscard]] TESFile* GetFile(std::int32_t a_index = -1) const
		{
			using func_t = decltype(&TESForm::GetFile);
			static REL::Relocation<func_t> func{ ID::TESForm::GetFile };
			return func(this, a_index);
		}

		[[nodiscard]] static TESForm* GetFormByID(TESFormID a_formID)
		{
			const auto& [map, lock] = GetAllForms();
			BSAutoReadLock l{ lock };
			if (map) {
				const auto it = map->find(a_formID);
				return it != map->end() ? it->second : nullptr;
			} else {
				return nullptr;
			}
		}

		template <class T>
		[[nodiscard]] static T* GetFormByID(TESFormID a_formID)
		{
			const auto form = GetFormByID(a_formID);
			return form ? form->As<T>() : nullptr;
		}

		[[nodiscard]] static TESForm* GetFormByEditorID(const BSFixedString& a_editorID)
		{
			const auto& [map, lock] = GetAllFormsByEditorID();
			BSAutoReadLock l{ lock };
			if (map) {
				const auto it = map->find(a_editorID);
				return it != map->end() ? it->second : nullptr;
			} else {
				return nullptr;
			}
		}

		template <class T>
		[[nodiscard]] static T* GetFormByEditorID(const BSFixedString& a_editorID)
		{
			const auto form = GetFormByEditorID(a_editorID);
			return form ? form->As<T>() : nullptr;
		}

		[[nodiscard]] static std::uint32_t GetFormCode(ENUM_FORM_ID a_formType)
		{
			auto formEnumString = GetFormEnumString();
			return formEnumString[std::to_underlying(a_formType)].formCode;
		}

		[[nodiscard]] std::uint32_t GetFormCode() const
		{
			return GetFormCode(GetFormType());
		}

		[[nodiscard]] static std::span<FORM_ENUM_STRING, 159> GetFormEnumString()
		{
			static REL::Relocation<FORM_ENUM_STRING(*)[159]> functions{ ID::TESForm::GetFormEnumString };
			return { *functions };
		}

		[[nodiscard]] static ENUM_FORM_ID GetFormTypeFromString(const char* a_formTypeString)
		{
			using func_t = decltype(&TESForm::GetFormTypeFromString);
			static REL::Relocation<func_t> func{ ID::TESForm::GetFormTypeFromString };
			return func(a_formTypeString);
		}

		[[nodiscard]] static const char* GetFormTypeString(ENUM_FORM_ID a_formType)
		{
			auto formEnumString = GetFormEnumString();
			return formEnumString[std::to_underlying(a_formType)].formString;
		}

		[[nodiscard]] const char* GetFormTypeString() const
		{
			return GetFormTypeString(GetFormType());
		}

		[[nodiscard]] std::uint32_t GetFormFlags() const noexcept { return formFlags; }
		[[nodiscard]] TESFormID     GetFormID() const noexcept { return formID; }
		[[nodiscard]] ENUM_FORM_ID  GetFormType() const noexcept { return *formType; }

		[[nodiscard]] TESFormID GetLocalFormID()
		{
			auto file = GetFile(0);

			std::uint32_t fileIndex = file->compileIndex << (3 * 8);
			fileIndex += file->smallFileCompileIndex << ((1 * 8) + 4);

			return formID & ~fileIndex;
		}

		[[nodiscard]] bool Is(ENUM_FORM_ID a_type) const noexcept { return GetFormType() == a_type; }
		template <class... Args>

		[[nodiscard]] bool Is(Args... a_args) const noexcept  //
			requires(std::same_as<Args, ENUM_FORM_ID> && ...)
		{
			return (Is(a_args) || ...);
		}

		template <class T>
		[[nodiscard]] bool Is() const noexcept  //
			requires(std::derived_from<T, TESForm> &&
					 !std::is_pointer_v<T> &&
					 !std::is_reference_v<T>)
		{
			return Is(T::FORM_ID);
		}

		[[nodiscard]] bool IsActor() const noexcept { return Is(ENUM_FORM_ID::kACHR); }
		[[nodiscard]] bool IsAlchemyItem() const noexcept { return Is(ENUM_FORM_ID::kALCH); }
		[[nodiscard]] bool IsCreated() const noexcept { return (formID >> (8 * 3)) == 0xFF; }
		[[nodiscard]] bool IsDeleted() noexcept { return (formFlags & (1u << 5)) != 0; }
		[[nodiscard]] bool IsDisabled() noexcept { return (formFlags & (1u << 11)) != 0; }
		[[nodiscard]] bool IsInitialized() const noexcept { return (formFlags & (1u << 3)) != 0; }

		[[nodiscard]] bool IsNot(ENUM_FORM_ID a_type) const noexcept { return !Is(a_type); }
		template <class... Args>

		[[nodiscard]] bool IsNot(Args... a_args) const noexcept  //
			requires(std::same_as<Args, ENUM_FORM_ID> && ...)
		{
			return (IsNot(a_args) && ...);
		}

		[[nodiscard]] bool IsPlayer() const noexcept { return GetFormID() == 0x00000007; }
		[[nodiscard]] bool IsPlayerRef() const noexcept { return GetFormID() == 0x00000014; }
		[[nodiscard]] bool IsWeapon() const noexcept { return Is(ENUM_FORM_ID::kWEAP); }

		void SetInGameFormFlags(std::uint16_t a_flags, bool a_value)
		{
			if (a_value) {
				inGameFormFlags |= a_flags;
				AddChange(1);
			} else {
				inGameFormFlags &= ~a_flags;
				AddChange(1);
			}
		}

		void SetTemporary()
		{
			using func_t = decltype(&TESForm::SetTemporary);
			static REL::Relocation<func_t> func{ ID::TESForm::SetTemporary };
			return func(this);
		}

		static TESForm* GetFormByNumericID(std::uint32_t a_searchID)
		{
			using func_t = decltype(&TESForm::GetFormByNumericID);
			static REL::Relocation<func_t> func{ ID::TESForm::GetFormByNumericID };
			return func(a_searchID);
		}

		template <
			class T,
			class = std::enable_if_t<
				std::negation_v<
					std::disjunction<
						std::is_pointer<T>,
						std::is_reference<T>,
						std::is_const<T>,
						std::is_volatile<T>>>>>
		[[nodiscard]] T* As() noexcept;

		template <
			class T,
			class = std::enable_if_t<
				std::negation_v<
					std::disjunction<
						std::is_pointer<T>,
						std::is_reference<T>,
						std::is_const<T>,
						std::is_volatile<T>>>>>
		[[nodiscard]] const T* As() const noexcept;

		// members
		TESFileContainer                          sourceFiles;      // 08
		std::uint32_t                             formFlags;        // 10
		TESFormID                                 formID;           // 14
		std::uint16_t                             inGameFormFlags;  // 18
		REX::TEnumSet<ENUM_FORM_ID, std::uint8_t> formType;         // 1A
	};
	static_assert(sizeof(TESForm) == 0x20);
}

namespace std
{
	[[nodiscard]] inline std::string to_string(RE::ENUM_FORM_ID a_formType)
	{
		return RE::TESForm::GetFormTypeString(a_formType);
	}
}

#ifdef FMT_VERSION
namespace fmt
{
	template <>
	struct formatter<RE::ENUM_FORM_ID>
	{
		template <class ParseContext>
		constexpr auto parse(ParseContext& a_ctx)
		{
			return a_ctx.begin();
		}

		template <class FormatContext>
		auto format(const RE::ENUM_FORM_ID& a_formType, FormatContext& a_ctx)
		{
			return fmt::format_to(a_ctx.out(), "{}", RE::TESForm::GetFormTypeString(a_formType));
		}
	};
}
#endif

#ifdef __cpp_lib_format
namespace std
{
	template <class CharT>
	struct formatter<RE::ENUM_FORM_ID, CharT> : std::formatter<std::string_view, CharT>
	{
		template <class FormatContext>
		auto format(RE::ENUM_FORM_ID a_formType, FormatContext& a_ctx)
		{
			return formatter<std::string_view, CharT>::format(RE::TESForm::GetFormTypeString(a_formType), a_ctx);
		}
	};
}
#endif
