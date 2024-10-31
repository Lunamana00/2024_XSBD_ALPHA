// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Alpha/Public/Enums/FractTypes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFractTypes() {}

// Begin Cross Module References
ALPHA_API UEnum* Z_Construct_UEnum_Alpha_EFractAttackRange();
ALPHA_API UEnum* Z_Construct_UEnum_Alpha_EFractAttackType();
ALPHA_API UEnum* Z_Construct_UEnum_Alpha_EFractCharacterState();
ALPHA_API UEnum* Z_Construct_UEnum_Alpha_EFractElementType();
ALPHA_API UScriptStruct* Z_Construct_UScriptStruct_FFractAttack();
ALPHA_API UScriptStruct* Z_Construct_UScriptStruct_FFractSkill();
ENGINE_API UClass* Z_Construct_UClass_UAnimMontage_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UParticleSystem_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USoundBase_NoRegister();
UPackage* Z_Construct_UPackage__Script_Alpha();
// End Cross Module References

// Begin Enum EFractElementType
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EFractElementType;
static UEnum* EFractElementType_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EFractElementType.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EFractElementType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_Alpha_EFractElementType, (UObject*)Z_Construct_UPackage__Script_Alpha(), TEXT("EFractElementType"));
	}
	return Z_Registration_Info_UEnum_EFractElementType.OuterSingleton;
}
template<> ALPHA_API UEnum* StaticEnum<EFractElementType>()
{
	return EFractElementType_StaticEnum();
}
struct Z_Construct_UEnum_Alpha_EFractElementType_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xec\x9b\x90\xec\x86\x8c \xec\xa2\x85\xeb\xa5\x98\n" },
#endif
		{ "Earth.DisplayName", "Earth" },
		{ "Earth.Name", "EFractElementType::Earth" },
		{ "Fire.DisplayName", "Fire" },
		{ "Fire.Name", "EFractElementType::Fire" },
		{ "ModuleRelativePath", "Public/Enums/FractTypes.h" },
		{ "None.DisplayName", "None" },
		{ "None.Name", "EFractElementType::None" },
		{ "Player.DisplayName", "Player" },
		{ "Player.Name", "EFractElementType::Player" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xec\x9b\x90\xec\x86\x8c \xec\xa2\x85\xeb\xa5\x98" },
#endif
		{ "Water.DisplayName", "Water" },
		{ "Water.Name", "EFractElementType::Water" },
		{ "Wind.DisplayName", "Wind" },
		{ "Wind.Name", "EFractElementType::Wind" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EFractElementType::None", (int64)EFractElementType::None },
		{ "EFractElementType::Fire", (int64)EFractElementType::Fire },
		{ "EFractElementType::Water", (int64)EFractElementType::Water },
		{ "EFractElementType::Earth", (int64)EFractElementType::Earth },
		{ "EFractElementType::Wind", (int64)EFractElementType::Wind },
		{ "EFractElementType::Player", (int64)EFractElementType::Player },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_Alpha_EFractElementType_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_Alpha,
	nullptr,
	"EFractElementType",
	"EFractElementType",
	Z_Construct_UEnum_Alpha_EFractElementType_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_Alpha_EFractElementType_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_Alpha_EFractElementType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_Alpha_EFractElementType_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_Alpha_EFractElementType()
{
	if (!Z_Registration_Info_UEnum_EFractElementType.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EFractElementType.InnerSingleton, Z_Construct_UEnum_Alpha_EFractElementType_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EFractElementType.InnerSingleton;
}
// End Enum EFractElementType

// Begin Enum EFractAttackRange
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EFractAttackRange;
static UEnum* EFractAttackRange_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EFractAttackRange.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EFractAttackRange.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_Alpha_EFractAttackRange, (UObject*)Z_Construct_UPackage__Script_Alpha(), TEXT("EFractAttackRange"));
	}
	return Z_Registration_Info_UEnum_EFractAttackRange.OuterSingleton;
}
template<> ALPHA_API UEnum* StaticEnum<EFractAttackRange>()
{
	return EFractAttackRange_StaticEnum();
}
struct Z_Construct_UEnum_Alpha_EFractAttackRange_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xea\xb3\xb5\xea\xb2\xa9 \xeb\xb2\x94\xec\x9c\x84 \xed\x83\x80\xec\x9e\x85\n" },
#endif
		{ "Melee.DisplayName", "Melee" },
		{ "Melee.Name", "EFractAttackRange::Melee" },
		{ "ModuleRelativePath", "Public/Enums/FractTypes.h" },
		{ "Ranged.DisplayName", "Ranged" },
		{ "Ranged.Name", "EFractAttackRange::Ranged" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xea\xb3\xb5\xea\xb2\xa9 \xeb\xb2\x94\xec\x9c\x84 \xed\x83\x80\xec\x9e\x85" },
#endif
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EFractAttackRange::Melee", (int64)EFractAttackRange::Melee },
		{ "EFractAttackRange::Ranged", (int64)EFractAttackRange::Ranged },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_Alpha_EFractAttackRange_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_Alpha,
	nullptr,
	"EFractAttackRange",
	"EFractAttackRange",
	Z_Construct_UEnum_Alpha_EFractAttackRange_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_Alpha_EFractAttackRange_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_Alpha_EFractAttackRange_Statics::Enum_MetaDataParams), Z_Construct_UEnum_Alpha_EFractAttackRange_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_Alpha_EFractAttackRange()
{
	if (!Z_Registration_Info_UEnum_EFractAttackRange.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EFractAttackRange.InnerSingleton, Z_Construct_UEnum_Alpha_EFractAttackRange_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EFractAttackRange.InnerSingleton;
}
// End Enum EFractAttackRange

// Begin Enum EFractAttackType
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EFractAttackType;
static UEnum* EFractAttackType_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EFractAttackType.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EFractAttackType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_Alpha_EFractAttackType, (UObject*)Z_Construct_UPackage__Script_Alpha(), TEXT("EFractAttackType"));
	}
	return Z_Registration_Info_UEnum_EFractAttackType.OuterSingleton;
}
template<> ALPHA_API UEnum* StaticEnum<EFractAttackType>()
{
	return EFractAttackType_StaticEnum();
}
struct Z_Construct_UEnum_Alpha_EFractAttackType_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xec\x8a\xa4\xed\x82\xac\xec\x9d\xb8\xec\xa7\x80 \xea\xb8\xb0\xeb\xb3\xb8 \xea\xb3\xb5\xea\xb2\xa9\xec\x9d\xb8\xec\xa7\x80\n" },
#endif
		{ "ModuleRelativePath", "Public/Enums/FractTypes.h" },
		{ "Normal.DisplayName", "Normal" },
		{ "Normal.Name", "EFractAttackType::Normal" },
		{ "Skill.DisplayName", "Skill" },
		{ "Skill.Name", "EFractAttackType::Skill" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xec\x8a\xa4\xed\x82\xac\xec\x9d\xb8\xec\xa7\x80 \xea\xb8\xb0\xeb\xb3\xb8 \xea\xb3\xb5\xea\xb2\xa9\xec\x9d\xb8\xec\xa7\x80" },
#endif
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EFractAttackType::Normal", (int64)EFractAttackType::Normal },
		{ "EFractAttackType::Skill", (int64)EFractAttackType::Skill },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_Alpha_EFractAttackType_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_Alpha,
	nullptr,
	"EFractAttackType",
	"EFractAttackType",
	Z_Construct_UEnum_Alpha_EFractAttackType_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_Alpha_EFractAttackType_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_Alpha_EFractAttackType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_Alpha_EFractAttackType_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_Alpha_EFractAttackType()
{
	if (!Z_Registration_Info_UEnum_EFractAttackType.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EFractAttackType.InnerSingleton, Z_Construct_UEnum_Alpha_EFractAttackType_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EFractAttackType.InnerSingleton;
}
// End Enum EFractAttackType

// Begin Enum EFractCharacterState
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EFractCharacterState;
static UEnum* EFractCharacterState_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EFractCharacterState.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EFractCharacterState.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_Alpha_EFractCharacterState, (UObject*)Z_Construct_UPackage__Script_Alpha(), TEXT("EFractCharacterState"));
	}
	return Z_Registration_Info_UEnum_EFractCharacterState.OuterSingleton;
}
template<> ALPHA_API UEnum* StaticEnum<EFractCharacterState>()
{
	return EFractCharacterState_StaticEnum();
}
struct Z_Construct_UEnum_Alpha_EFractCharacterState_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xec\xba\x90\xeb\xa6\xad\xed\x84\xb0 \xec\x8a\xa4\xed\x85\x8c\xec\x9d\xb4\xed\x8a\xb8\n" },
#endif
		{ "ECS_Attacking.DisplayName", "Attacking" },
		{ "ECS_Attacking.Name", "EFractCharacterState::ECS_Attacking" },
		{ "ECS_Dodging.DisplayName", "Dodging" },
		{ "ECS_Dodging.Name", "EFractCharacterState::ECS_Dodging" },
		{ "ECS_Hit.DisplayName", "Hit" },
		{ "ECS_Hit.Name", "EFractCharacterState::ECS_Hit" },
		{ "ECS_Idle.DisplayName", "Idle" },
		{ "ECS_Idle.Name", "EFractCharacterState::ECS_Idle" },
		{ "ECS_UsingSkill.DisplayName", "UsingSkill" },
		{ "ECS_UsingSkill.Name", "EFractCharacterState::ECS_UsingSkill" },
		{ "ModuleRelativePath", "Public/Enums/FractTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xec\xba\x90\xeb\xa6\xad\xed\x84\xb0 \xec\x8a\xa4\xed\x85\x8c\xec\x9d\xb4\xed\x8a\xb8" },
#endif
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EFractCharacterState::ECS_Idle", (int64)EFractCharacterState::ECS_Idle },
		{ "EFractCharacterState::ECS_Attacking", (int64)EFractCharacterState::ECS_Attacking },
		{ "EFractCharacterState::ECS_Dodging", (int64)EFractCharacterState::ECS_Dodging },
		{ "EFractCharacterState::ECS_Hit", (int64)EFractCharacterState::ECS_Hit },
		{ "EFractCharacterState::ECS_UsingSkill", (int64)EFractCharacterState::ECS_UsingSkill },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_Alpha_EFractCharacterState_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_Alpha,
	nullptr,
	"EFractCharacterState",
	"EFractCharacterState",
	Z_Construct_UEnum_Alpha_EFractCharacterState_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_Alpha_EFractCharacterState_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_Alpha_EFractCharacterState_Statics::Enum_MetaDataParams), Z_Construct_UEnum_Alpha_EFractCharacterState_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_Alpha_EFractCharacterState()
{
	if (!Z_Registration_Info_UEnum_EFractCharacterState.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EFractCharacterState.InnerSingleton, Z_Construct_UEnum_Alpha_EFractCharacterState_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EFractCharacterState.InnerSingleton;
}
// End Enum EFractCharacterState

// Begin ScriptStruct FFractAttack
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FractAttack;
class UScriptStruct* FFractAttack::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FractAttack.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FractAttack.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FFractAttack, (UObject*)Z_Construct_UPackage__Script_Alpha(), TEXT("FractAttack"));
	}
	return Z_Registration_Info_UScriptStruct_FractAttack.OuterSingleton;
}
template<> ALPHA_API UScriptStruct* StaticStruct<FFractAttack>()
{
	return FFractAttack::StaticStruct();
}
struct Z_Construct_UScriptStruct_FFractAttack_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xea\xb8\xb0\xeb\xb3\xb8 \xea\xb3\xb5\xea\xb2\xa9 \xea\xb5\xac\xec\xa1\xb0\xec\xb2\xb4\n" },
#endif
		{ "ModuleRelativePath", "Public/Enums/FractTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xea\xb8\xb0\xeb\xb3\xb8 \xea\xb3\xb5\xea\xb2\xa9 \xea\xb5\xac\xec\xa1\xb0\xec\xb2\xb4" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DamageMultiplier_MetaData[] = {
		{ "Category", "FractAttack" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xea\xb8\xb0\xeb\xb3\xb8 \xec\x86\x8d\xec\x84\xb1\n" },
#endif
		{ "ModuleRelativePath", "Public/Enums/FractTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xea\xb8\xb0\xeb\xb3\xb8 \xec\x86\x8d\xec\x84\xb1" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Range_MetaData[] = {
		{ "Category", "FractAttack" },
		{ "ModuleRelativePath", "Public/Enums/FractTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AttackType_MetaData[] = {
		{ "Category", "FractAttack" },
		{ "ModuleRelativePath", "Public/Enums/FractTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Element_MetaData[] = {
		{ "Category", "FractAttack" },
		{ "ModuleRelativePath", "Public/Enums/FractTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsFlyingAttack_MetaData[] = {
		{ "Category", "FractAttack" },
		{ "ModuleRelativePath", "Public/Enums/FractTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AttackMontages_MetaData[] = {
		{ "Category", "FractAttack" },
		{ "ModuleRelativePath", "Public/Enums/FractTypes.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DamageMultiplier;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Range_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Range;
	static const UECodeGen_Private::FBytePropertyParams NewProp_AttackType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_AttackType;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Element_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Element;
	static void NewProp_bIsFlyingAttack_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsFlyingAttack;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_AttackMontages_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_AttackMontages;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FFractAttack>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FFractAttack_Statics::NewProp_DamageMultiplier = { "DamageMultiplier", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FFractAttack, DamageMultiplier), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DamageMultiplier_MetaData), NewProp_DamageMultiplier_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FFractAttack_Statics::NewProp_Range_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FFractAttack_Statics::NewProp_Range = { "Range", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FFractAttack, Range), Z_Construct_UEnum_Alpha_EFractAttackRange, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Range_MetaData), NewProp_Range_MetaData) }; // 3466953335
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FFractAttack_Statics::NewProp_AttackType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FFractAttack_Statics::NewProp_AttackType = { "AttackType", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FFractAttack, AttackType), Z_Construct_UEnum_Alpha_EFractAttackType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AttackType_MetaData), NewProp_AttackType_MetaData) }; // 4005700029
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FFractAttack_Statics::NewProp_Element_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FFractAttack_Statics::NewProp_Element = { "Element", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FFractAttack, Element), Z_Construct_UEnum_Alpha_EFractElementType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Element_MetaData), NewProp_Element_MetaData) }; // 1003798865
void Z_Construct_UScriptStruct_FFractAttack_Statics::NewProp_bIsFlyingAttack_SetBit(void* Obj)
{
	((FFractAttack*)Obj)->bIsFlyingAttack = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FFractAttack_Statics::NewProp_bIsFlyingAttack = { "bIsFlyingAttack", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FFractAttack), &Z_Construct_UScriptStruct_FFractAttack_Statics::NewProp_bIsFlyingAttack_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsFlyingAttack_MetaData), NewProp_bIsFlyingAttack_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FFractAttack_Statics::NewProp_AttackMontages_Inner = { "AttackMontages", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FFractAttack_Statics::NewProp_AttackMontages = { "AttackMontages", nullptr, (EPropertyFlags)0x0010000000010005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FFractAttack, AttackMontages), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AttackMontages_MetaData), NewProp_AttackMontages_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FFractAttack_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FFractAttack_Statics::NewProp_DamageMultiplier,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FFractAttack_Statics::NewProp_Range_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FFractAttack_Statics::NewProp_Range,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FFractAttack_Statics::NewProp_AttackType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FFractAttack_Statics::NewProp_AttackType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FFractAttack_Statics::NewProp_Element_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FFractAttack_Statics::NewProp_Element,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FFractAttack_Statics::NewProp_bIsFlyingAttack,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FFractAttack_Statics::NewProp_AttackMontages_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FFractAttack_Statics::NewProp_AttackMontages,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FFractAttack_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FFractAttack_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_Alpha,
	nullptr,
	&NewStructOps,
	"FractAttack",
	Z_Construct_UScriptStruct_FFractAttack_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FFractAttack_Statics::PropPointers),
	sizeof(FFractAttack),
	alignof(FFractAttack),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FFractAttack_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FFractAttack_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FFractAttack()
{
	if (!Z_Registration_Info_UScriptStruct_FractAttack.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FractAttack.InnerSingleton, Z_Construct_UScriptStruct_FFractAttack_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FractAttack.InnerSingleton;
}
// End ScriptStruct FFractAttack

// Begin ScriptStruct FFractSkill
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FractSkill;
class UScriptStruct* FFractSkill::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FractSkill.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FractSkill.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FFractSkill, (UObject*)Z_Construct_UPackage__Script_Alpha(), TEXT("FractSkill"));
	}
	return Z_Registration_Info_UScriptStruct_FractSkill.OuterSingleton;
}
template<> ALPHA_API UScriptStruct* StaticStruct<FFractSkill>()
{
	return FFractSkill::StaticStruct();
}
struct Z_Construct_UScriptStruct_FFractSkill_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xec\x8a\xa4\xed\x82\xac \xea\xb5\xac\xec\xa1\xb0\xec\xb2\xb4\n" },
#endif
		{ "ModuleRelativePath", "Public/Enums/FractTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xec\x8a\xa4\xed\x82\xac \xea\xb5\xac\xec\xa1\xb0\xec\xb2\xb4" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SkillName_MetaData[] = {
		{ "Category", "Skill Info" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xea\xb8\xb0\xeb\xb3\xb8 \xec\xa0\x95\xeb\xb3\xb4\n" },
#endif
		{ "ModuleRelativePath", "Public/Enums/FractTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xea\xb8\xb0\xeb\xb3\xb8 \xec\xa0\x95\xeb\xb3\xb4" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Description_MetaData[] = {
		{ "Category", "Skill Info" },
		{ "ModuleRelativePath", "Public/Enums/FractTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsFlyingSkill_MetaData[] = {
		{ "Category", "Skill Info" },
		{ "ModuleRelativePath", "Public/Enums/FractTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BaseDamage_MetaData[] = {
		{ "Category", "Damage" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xeb\x8d\xb0\xeb\xaf\xb8\xec\xa7\x80 \xea\xb4\x80\xeb\xa0\xa8\n" },
#endif
		{ "ModuleRelativePath", "Public/Enums/FractTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xeb\x8d\xb0\xeb\xaf\xb8\xec\xa7\x80 \xea\xb4\x80\xeb\xa0\xa8" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DamageRadius_MetaData[] = {
		{ "Category", "Damage" },
		{ "ModuleRelativePath", "Public/Enums/FractTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ProjectileSpeed_MetaData[] = {
		{ "Category", "Projectile" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xed\x88\xac\xec\x82\xac\xec\xb2\xb4 \xea\xb4\x80\xeb\xa0\xa8\n// UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = \"Projectile\")\n// TSubclassOf<AFractProjectile> ProjectileClass;\n" },
#endif
		{ "ModuleRelativePath", "Public/Enums/FractTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xed\x88\xac\xec\x82\xac\xec\xb2\xb4 \xea\xb4\x80\xeb\xa0\xa8\nUPROPERTY(EditAnywhere, BlueprintReadWrite, Category = \"Projectile\")\nTSubclassOf<AFractProjectile> ProjectileClass;" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ProjectileCount_MetaData[] = {
		{ "Category", "Projectile" },
		{ "ModuleRelativePath", "Public/Enums/FractTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ProjectileSpread_MetaData[] = {
		{ "Category", "Projectile" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xeb\x8b\xa4\xec\xa4\x91 \xeb\xb0\x9c\xec\x82\xac \xea\xb0\x80\xeb\x8a\xa5\n" },
#endif
		{ "ModuleRelativePath", "Public/Enums/FractTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xeb\x8b\xa4\xec\xa4\x91 \xeb\xb0\x9c\xec\x82\xac \xea\xb0\x80\xeb\x8a\xa5" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Element_MetaData[] = {
		{ "Category", "Element" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xec\x9b\x90\xec\x86\x8c \xec\x86\x8d\xec\x84\xb1\n" },
#endif
		{ "ModuleRelativePath", "Public/Enums/FractTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xec\x9b\x90\xec\x86\x8c \xec\x86\x8d\xec\x84\xb1" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Cooldown_MetaData[] = {
		{ "Category", "Cooldown" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xec\xbf\xa8\xeb\x8b\xa4\xec\x9a\xb4\n" },
#endif
		{ "ModuleRelativePath", "Public/Enums/FractTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xec\xbf\xa8\xeb\x8b\xa4\xec\x9a\xb4" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SkillMontage_MetaData[] = {
		{ "Category", "FX" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xeb\xb9\x84\xec\xa3\xbc\xec\x96\xbc/\xec\x82\xac\xec\x9a\xb4\xeb\x93\x9c\n" },
#endif
		{ "ModuleRelativePath", "Public/Enums/FractTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xeb\xb9\x84\xec\xa3\xbc\xec\x96\xbc/\xec\x82\xac\xec\x9a\xb4\xeb\x93\x9c" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CastEffect_MetaData[] = {
		{ "Category", "FX" },
		{ "ModuleRelativePath", "Public/Enums/FractTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CastSound_MetaData[] = {
		{ "Category", "FX" },
		{ "ModuleRelativePath", "Public/Enums/FractTypes.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FTextPropertyParams NewProp_SkillName;
	static const UECodeGen_Private::FTextPropertyParams NewProp_Description;
	static void NewProp_bIsFlyingSkill_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsFlyingSkill;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_BaseDamage;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DamageRadius;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ProjectileSpeed;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ProjectileCount;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ProjectileSpread;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Element_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Element;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Cooldown;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SkillMontage;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CastEffect;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CastSound;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FFractSkill>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FTextPropertyParams Z_Construct_UScriptStruct_FFractSkill_Statics::NewProp_SkillName = { "SkillName", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FFractSkill, SkillName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SkillName_MetaData), NewProp_SkillName_MetaData) };
const UECodeGen_Private::FTextPropertyParams Z_Construct_UScriptStruct_FFractSkill_Statics::NewProp_Description = { "Description", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FFractSkill, Description), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Description_MetaData), NewProp_Description_MetaData) };
void Z_Construct_UScriptStruct_FFractSkill_Statics::NewProp_bIsFlyingSkill_SetBit(void* Obj)
{
	((FFractSkill*)Obj)->bIsFlyingSkill = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FFractSkill_Statics::NewProp_bIsFlyingSkill = { "bIsFlyingSkill", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FFractSkill), &Z_Construct_UScriptStruct_FFractSkill_Statics::NewProp_bIsFlyingSkill_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsFlyingSkill_MetaData), NewProp_bIsFlyingSkill_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FFractSkill_Statics::NewProp_BaseDamage = { "BaseDamage", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FFractSkill, BaseDamage), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BaseDamage_MetaData), NewProp_BaseDamage_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FFractSkill_Statics::NewProp_DamageRadius = { "DamageRadius", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FFractSkill, DamageRadius), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DamageRadius_MetaData), NewProp_DamageRadius_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FFractSkill_Statics::NewProp_ProjectileSpeed = { "ProjectileSpeed", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FFractSkill, ProjectileSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ProjectileSpeed_MetaData), NewProp_ProjectileSpeed_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FFractSkill_Statics::NewProp_ProjectileCount = { "ProjectileCount", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FFractSkill, ProjectileCount), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ProjectileCount_MetaData), NewProp_ProjectileCount_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FFractSkill_Statics::NewProp_ProjectileSpread = { "ProjectileSpread", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FFractSkill, ProjectileSpread), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ProjectileSpread_MetaData), NewProp_ProjectileSpread_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FFractSkill_Statics::NewProp_Element_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FFractSkill_Statics::NewProp_Element = { "Element", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FFractSkill, Element), Z_Construct_UEnum_Alpha_EFractElementType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Element_MetaData), NewProp_Element_MetaData) }; // 1003798865
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FFractSkill_Statics::NewProp_Cooldown = { "Cooldown", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FFractSkill, Cooldown), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Cooldown_MetaData), NewProp_Cooldown_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FFractSkill_Statics::NewProp_SkillMontage = { "SkillMontage", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FFractSkill, SkillMontage), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SkillMontage_MetaData), NewProp_SkillMontage_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FFractSkill_Statics::NewProp_CastEffect = { "CastEffect", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FFractSkill, CastEffect), Z_Construct_UClass_UParticleSystem_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CastEffect_MetaData), NewProp_CastEffect_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FFractSkill_Statics::NewProp_CastSound = { "CastSound", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FFractSkill, CastSound), Z_Construct_UClass_USoundBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CastSound_MetaData), NewProp_CastSound_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FFractSkill_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FFractSkill_Statics::NewProp_SkillName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FFractSkill_Statics::NewProp_Description,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FFractSkill_Statics::NewProp_bIsFlyingSkill,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FFractSkill_Statics::NewProp_BaseDamage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FFractSkill_Statics::NewProp_DamageRadius,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FFractSkill_Statics::NewProp_ProjectileSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FFractSkill_Statics::NewProp_ProjectileCount,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FFractSkill_Statics::NewProp_ProjectileSpread,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FFractSkill_Statics::NewProp_Element_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FFractSkill_Statics::NewProp_Element,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FFractSkill_Statics::NewProp_Cooldown,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FFractSkill_Statics::NewProp_SkillMontage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FFractSkill_Statics::NewProp_CastEffect,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FFractSkill_Statics::NewProp_CastSound,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FFractSkill_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FFractSkill_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_Alpha,
	nullptr,
	&NewStructOps,
	"FractSkill",
	Z_Construct_UScriptStruct_FFractSkill_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FFractSkill_Statics::PropPointers),
	sizeof(FFractSkill),
	alignof(FFractSkill),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FFractSkill_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FFractSkill_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FFractSkill()
{
	if (!Z_Registration_Info_UScriptStruct_FractSkill.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FractSkill.InnerSingleton, Z_Construct_UScriptStruct_FFractSkill_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FractSkill.InnerSingleton;
}
// End ScriptStruct FFractSkill

// Begin Registration
struct Z_CompiledInDeferFile_FID_Alpha_Source_Alpha_Public_Enums_FractTypes_h_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EFractElementType_StaticEnum, TEXT("EFractElementType"), &Z_Registration_Info_UEnum_EFractElementType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1003798865U) },
		{ EFractAttackRange_StaticEnum, TEXT("EFractAttackRange"), &Z_Registration_Info_UEnum_EFractAttackRange, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3466953335U) },
		{ EFractAttackType_StaticEnum, TEXT("EFractAttackType"), &Z_Registration_Info_UEnum_EFractAttackType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 4005700029U) },
		{ EFractCharacterState_StaticEnum, TEXT("EFractCharacterState"), &Z_Registration_Info_UEnum_EFractCharacterState, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3248930071U) },
	};
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FFractAttack::StaticStruct, Z_Construct_UScriptStruct_FFractAttack_Statics::NewStructOps, TEXT("FractAttack"), &Z_Registration_Info_UScriptStruct_FractAttack, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FFractAttack), 686256981U) },
		{ FFractSkill::StaticStruct, Z_Construct_UScriptStruct_FFractSkill_Statics::NewStructOps, TEXT("FractSkill"), &Z_Registration_Info_UScriptStruct_FractSkill, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FFractSkill), 3798258329U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Alpha_Source_Alpha_Public_Enums_FractTypes_h_3842379113(TEXT("/Script/Alpha"),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_Alpha_Source_Alpha_Public_Enums_FractTypes_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Alpha_Source_Alpha_Public_Enums_FractTypes_h_Statics::ScriptStructInfo),
	Z_CompiledInDeferFile_FID_Alpha_Source_Alpha_Public_Enums_FractTypes_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Alpha_Source_Alpha_Public_Enums_FractTypes_h_Statics::EnumInfo));
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
