// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Alpha/Public/Components/FractPlayerAttackComponent.h"
#include "Alpha/Public/Enums/FractTypes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFractPlayerAttackComponent() {}

// Begin Cross Module References
ALPHA_API UClass* Z_Construct_UClass_AFractTestCharacter_NoRegister();
ALPHA_API UClass* Z_Construct_UClass_UFractPlayerAttackComponent();
ALPHA_API UClass* Z_Construct_UClass_UFractPlayerAttackComponent_NoRegister();
ALPHA_API UEnum* Z_Construct_UEnum_Alpha_EFractAttackRange();
ALPHA_API UScriptStruct* Z_Construct_UScriptStruct_FFractAttack();
ALPHA_API UScriptStruct* Z_Construct_UScriptStruct_FFractSkill();
ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
UPackage* Z_Construct_UPackage__Script_Alpha();
// End Cross Module References

// Begin Class UFractPlayerAttackComponent Function ResetCombo
struct Z_Construct_UFunction_UFractPlayerAttackComponent_ResetCombo_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "Public/Components/FractPlayerAttackComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UFractPlayerAttackComponent_ResetCombo_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFractPlayerAttackComponent, nullptr, "ResetCombo", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UFractPlayerAttackComponent_ResetCombo_Statics::Function_MetaDataParams), Z_Construct_UFunction_UFractPlayerAttackComponent_ResetCombo_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_UFractPlayerAttackComponent_ResetCombo()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UFractPlayerAttackComponent_ResetCombo_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UFractPlayerAttackComponent::execResetCombo)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ResetCombo();
	P_NATIVE_END;
}
// End Class UFractPlayerAttackComponent Function ResetCombo

// Begin Class UFractPlayerAttackComponent
void UFractPlayerAttackComponent::StaticRegisterNativesUFractPlayerAttackComponent()
{
	UClass* Class = UFractPlayerAttackComponent::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "ResetCombo", &UFractPlayerAttackComponent::execResetCombo },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UFractPlayerAttackComponent);
UClass* Z_Construct_UClass_UFractPlayerAttackComponent_NoRegister()
{
	return UFractPlayerAttackComponent::StaticClass();
}
struct Z_Construct_UClass_UFractPlayerAttackComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
		{ "IncludePath", "Components/FractPlayerAttackComponent.h" },
		{ "ModuleRelativePath", "Public/Components/FractPlayerAttackComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Character_MetaData[] = {
		{ "Category", "Player" },
		{ "ModuleRelativePath", "Public/Components/FractPlayerAttackComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentRange_MetaData[] = {
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "Public/Components/FractPlayerAttackComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsFlying_MetaData[] = {
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "Public/Components/FractPlayerAttackComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MeleeAttacks_MetaData[] = {
		{ "Category", "Combat|Attacks" },
		{ "ModuleRelativePath", "Public/Components/FractPlayerAttackComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RangedAttacks_MetaData[] = {
		{ "Category", "Combat|Attacks" },
		{ "ModuleRelativePath", "Public/Components/FractPlayerAttackComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GroundSkills_MetaData[] = {
		{ "Category", "Combat|Skills" },
		{ "ModuleRelativePath", "Public/Components/FractPlayerAttackComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AerialSkills_MetaData[] = {
		{ "Category", "Combat|Skills" },
		{ "ModuleRelativePath", "Public/Components/FractPlayerAttackComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ComboCount_MetaData[] = {
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "Public/Components/FractPlayerAttackComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Character;
	static const UECodeGen_Private::FBytePropertyParams NewProp_CurrentRange_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_CurrentRange;
	static void NewProp_bIsFlying_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsFlying;
	static const UECodeGen_Private::FStructPropertyParams NewProp_MeleeAttacks_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_MeleeAttacks;
	static const UECodeGen_Private::FStructPropertyParams NewProp_RangedAttacks_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_RangedAttacks;
	static const UECodeGen_Private::FStructPropertyParams NewProp_GroundSkills_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_GroundSkills;
	static const UECodeGen_Private::FStructPropertyParams NewProp_AerialSkills_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_AerialSkills;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ComboCount;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UFractPlayerAttackComponent_ResetCombo, "ResetCombo" }, // 4018860418
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UFractPlayerAttackComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UFractPlayerAttackComponent_Statics::NewProp_Character = { "Character", nullptr, (EPropertyFlags)0x0020080000020001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UFractPlayerAttackComponent, Character), Z_Construct_UClass_AFractTestCharacter_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Character_MetaData), NewProp_Character_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UFractPlayerAttackComponent_Statics::NewProp_CurrentRange_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UFractPlayerAttackComponent_Statics::NewProp_CurrentRange = { "CurrentRange", nullptr, (EPropertyFlags)0x0020080000020001, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UFractPlayerAttackComponent, CurrentRange), Z_Construct_UEnum_Alpha_EFractAttackRange, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentRange_MetaData), NewProp_CurrentRange_MetaData) }; // 3466953335
void Z_Construct_UClass_UFractPlayerAttackComponent_Statics::NewProp_bIsFlying_SetBit(void* Obj)
{
	((UFractPlayerAttackComponent*)Obj)->bIsFlying = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UFractPlayerAttackComponent_Statics::NewProp_bIsFlying = { "bIsFlying", nullptr, (EPropertyFlags)0x0020080000020001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UFractPlayerAttackComponent), &Z_Construct_UClass_UFractPlayerAttackComponent_Statics::NewProp_bIsFlying_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsFlying_MetaData), NewProp_bIsFlying_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UFractPlayerAttackComponent_Statics::NewProp_MeleeAttacks_Inner = { "MeleeAttacks", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FFractAttack, METADATA_PARAMS(0, nullptr) }; // 686256981
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UFractPlayerAttackComponent_Statics::NewProp_MeleeAttacks = { "MeleeAttacks", nullptr, (EPropertyFlags)0x0020080000010001, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UFractPlayerAttackComponent, MeleeAttacks), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MeleeAttacks_MetaData), NewProp_MeleeAttacks_MetaData) }; // 686256981
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UFractPlayerAttackComponent_Statics::NewProp_RangedAttacks_Inner = { "RangedAttacks", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FFractAttack, METADATA_PARAMS(0, nullptr) }; // 686256981
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UFractPlayerAttackComponent_Statics::NewProp_RangedAttacks = { "RangedAttacks", nullptr, (EPropertyFlags)0x0020080000010001, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UFractPlayerAttackComponent, RangedAttacks), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RangedAttacks_MetaData), NewProp_RangedAttacks_MetaData) }; // 686256981
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UFractPlayerAttackComponent_Statics::NewProp_GroundSkills_Inner = { "GroundSkills", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FFractSkill, METADATA_PARAMS(0, nullptr) }; // 3798258329
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UFractPlayerAttackComponent_Statics::NewProp_GroundSkills = { "GroundSkills", nullptr, (EPropertyFlags)0x0020080000010001, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UFractPlayerAttackComponent, GroundSkills), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GroundSkills_MetaData), NewProp_GroundSkills_MetaData) }; // 3798258329
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UFractPlayerAttackComponent_Statics::NewProp_AerialSkills_Inner = { "AerialSkills", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FFractSkill, METADATA_PARAMS(0, nullptr) }; // 3798258329
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UFractPlayerAttackComponent_Statics::NewProp_AerialSkills = { "AerialSkills", nullptr, (EPropertyFlags)0x0020080000010001, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UFractPlayerAttackComponent, AerialSkills), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AerialSkills_MetaData), NewProp_AerialSkills_MetaData) }; // 3798258329
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UFractPlayerAttackComponent_Statics::NewProp_ComboCount = { "ComboCount", nullptr, (EPropertyFlags)0x0020080000030001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UFractPlayerAttackComponent, ComboCount), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ComboCount_MetaData), NewProp_ComboCount_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UFractPlayerAttackComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFractPlayerAttackComponent_Statics::NewProp_Character,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFractPlayerAttackComponent_Statics::NewProp_CurrentRange_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFractPlayerAttackComponent_Statics::NewProp_CurrentRange,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFractPlayerAttackComponent_Statics::NewProp_bIsFlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFractPlayerAttackComponent_Statics::NewProp_MeleeAttacks_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFractPlayerAttackComponent_Statics::NewProp_MeleeAttacks,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFractPlayerAttackComponent_Statics::NewProp_RangedAttacks_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFractPlayerAttackComponent_Statics::NewProp_RangedAttacks,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFractPlayerAttackComponent_Statics::NewProp_GroundSkills_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFractPlayerAttackComponent_Statics::NewProp_GroundSkills,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFractPlayerAttackComponent_Statics::NewProp_AerialSkills_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFractPlayerAttackComponent_Statics::NewProp_AerialSkills,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFractPlayerAttackComponent_Statics::NewProp_ComboCount,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UFractPlayerAttackComponent_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UFractPlayerAttackComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UActorComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_Alpha,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UFractPlayerAttackComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UFractPlayerAttackComponent_Statics::ClassParams = {
	&UFractPlayerAttackComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UFractPlayerAttackComponent_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UFractPlayerAttackComponent_Statics::PropPointers),
	0,
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UFractPlayerAttackComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UFractPlayerAttackComponent_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UFractPlayerAttackComponent()
{
	if (!Z_Registration_Info_UClass_UFractPlayerAttackComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UFractPlayerAttackComponent.OuterSingleton, Z_Construct_UClass_UFractPlayerAttackComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UFractPlayerAttackComponent.OuterSingleton;
}
template<> ALPHA_API UClass* StaticClass<UFractPlayerAttackComponent>()
{
	return UFractPlayerAttackComponent::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UFractPlayerAttackComponent);
UFractPlayerAttackComponent::~UFractPlayerAttackComponent() {}
// End Class UFractPlayerAttackComponent

// Begin Registration
struct Z_CompiledInDeferFile_FID_Alpha_Source_Alpha_Public_Components_FractPlayerAttackComponent_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UFractPlayerAttackComponent, UFractPlayerAttackComponent::StaticClass, TEXT("UFractPlayerAttackComponent"), &Z_Registration_Info_UClass_UFractPlayerAttackComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UFractPlayerAttackComponent), 2936292142U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Alpha_Source_Alpha_Public_Components_FractPlayerAttackComponent_h_3272409433(TEXT("/Script/Alpha"),
	Z_CompiledInDeferFile_FID_Alpha_Source_Alpha_Public_Components_FractPlayerAttackComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Alpha_Source_Alpha_Public_Components_FractPlayerAttackComponent_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
