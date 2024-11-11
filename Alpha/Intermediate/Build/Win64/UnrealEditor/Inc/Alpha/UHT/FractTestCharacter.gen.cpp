// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Alpha/Public/Test/FractTestCharacter.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFractTestCharacter() {}

// Begin Cross Module References
ALPHA_API UClass* Z_Construct_UClass_AAlphaCharacter();
ALPHA_API UClass* Z_Construct_UClass_AFractPlayerWeapon_NoRegister();
ALPHA_API UClass* Z_Construct_UClass_AFractTestCharacter();
ALPHA_API UClass* Z_Construct_UClass_AFractTestCharacter_NoRegister();
ALPHA_API UClass* Z_Construct_UClass_UFractPlayerAttackComponent_NoRegister();
ALPHA_API UClass* Z_Construct_UClass_UFractPlayerAttributeComponent_NoRegister();
ALPHA_API UEnum* Z_Construct_UEnum_Alpha_EFractCharacterState();
COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector2D();
ENGINE_API UEnum* Z_Construct_UEnum_Engine_ECollisionEnabled();
ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputAction_NoRegister();
MOTIONWARPING_API UClass* Z_Construct_UClass_UMotionWarpingComponent_NoRegister();
UPackage* Z_Construct_UPackage__Script_Alpha();
// End Cross Module References

// Begin Class AFractTestCharacter Function GetWeapon
struct Z_Construct_UFunction_AFractTestCharacter_GetWeapon_Statics
{
	struct FractTestCharacter_eventGetWeapon_Parms
	{
		AFractPlayerWeapon* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Test/FractTestCharacter.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AFractTestCharacter_GetWeapon_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FractTestCharacter_eventGetWeapon_Parms, ReturnValue), Z_Construct_UClass_AFractPlayerWeapon_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AFractTestCharacter_GetWeapon_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AFractTestCharacter_GetWeapon_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AFractTestCharacter_GetWeapon_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AFractTestCharacter_GetWeapon_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AFractTestCharacter, nullptr, "GetWeapon", nullptr, nullptr, Z_Construct_UFunction_AFractTestCharacter_GetWeapon_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AFractTestCharacter_GetWeapon_Statics::PropPointers), sizeof(Z_Construct_UFunction_AFractTestCharacter_GetWeapon_Statics::FractTestCharacter_eventGetWeapon_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AFractTestCharacter_GetWeapon_Statics::Function_MetaDataParams), Z_Construct_UFunction_AFractTestCharacter_GetWeapon_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AFractTestCharacter_GetWeapon_Statics::FractTestCharacter_eventGetWeapon_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AFractTestCharacter_GetWeapon()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AFractTestCharacter_GetWeapon_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AFractTestCharacter::execGetWeapon)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(AFractPlayerWeapon**)Z_Param__Result=P_THIS->GetWeapon();
	P_NATIVE_END;
}
// End Class AFractTestCharacter Function GetWeapon

// Begin Class AFractTestCharacter Function SetAllowPhysicsRotationDuringAnimRootMotion
struct Z_Construct_UFunction_AFractTestCharacter_SetAllowPhysicsRotationDuringAnimRootMotion_Statics
{
	struct FractTestCharacter_eventSetAllowPhysicsRotationDuringAnimRootMotion_Parms
	{
		bool bAllowRotation;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Test/FractTestCharacter.h" },
	};
#endif // WITH_METADATA
	static void NewProp_bAllowRotation_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bAllowRotation;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_AFractTestCharacter_SetAllowPhysicsRotationDuringAnimRootMotion_Statics::NewProp_bAllowRotation_SetBit(void* Obj)
{
	((FractTestCharacter_eventSetAllowPhysicsRotationDuringAnimRootMotion_Parms*)Obj)->bAllowRotation = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AFractTestCharacter_SetAllowPhysicsRotationDuringAnimRootMotion_Statics::NewProp_bAllowRotation = { "bAllowRotation", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FractTestCharacter_eventSetAllowPhysicsRotationDuringAnimRootMotion_Parms), &Z_Construct_UFunction_AFractTestCharacter_SetAllowPhysicsRotationDuringAnimRootMotion_Statics::NewProp_bAllowRotation_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AFractTestCharacter_SetAllowPhysicsRotationDuringAnimRootMotion_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AFractTestCharacter_SetAllowPhysicsRotationDuringAnimRootMotion_Statics::NewProp_bAllowRotation,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AFractTestCharacter_SetAllowPhysicsRotationDuringAnimRootMotion_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AFractTestCharacter_SetAllowPhysicsRotationDuringAnimRootMotion_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AFractTestCharacter, nullptr, "SetAllowPhysicsRotationDuringAnimRootMotion", nullptr, nullptr, Z_Construct_UFunction_AFractTestCharacter_SetAllowPhysicsRotationDuringAnimRootMotion_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AFractTestCharacter_SetAllowPhysicsRotationDuringAnimRootMotion_Statics::PropPointers), sizeof(Z_Construct_UFunction_AFractTestCharacter_SetAllowPhysicsRotationDuringAnimRootMotion_Statics::FractTestCharacter_eventSetAllowPhysicsRotationDuringAnimRootMotion_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AFractTestCharacter_SetAllowPhysicsRotationDuringAnimRootMotion_Statics::Function_MetaDataParams), Z_Construct_UFunction_AFractTestCharacter_SetAllowPhysicsRotationDuringAnimRootMotion_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AFractTestCharacter_SetAllowPhysicsRotationDuringAnimRootMotion_Statics::FractTestCharacter_eventSetAllowPhysicsRotationDuringAnimRootMotion_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AFractTestCharacter_SetAllowPhysicsRotationDuringAnimRootMotion()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AFractTestCharacter_SetAllowPhysicsRotationDuringAnimRootMotion_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AFractTestCharacter::execSetAllowPhysicsRotationDuringAnimRootMotion)
{
	P_GET_UBOOL(Z_Param_bAllowRotation);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetAllowPhysicsRotationDuringAnimRootMotion(Z_Param_bAllowRotation);
	P_NATIVE_END;
}
// End Class AFractTestCharacter Function SetAllowPhysicsRotationDuringAnimRootMotion

// Begin Class AFractTestCharacter Function SetWeaponCollisionEnabled
struct Z_Construct_UFunction_AFractTestCharacter_SetWeaponCollisionEnabled_Statics
{
	struct FractTestCharacter_eventSetWeaponCollisionEnabled_Parms
	{
		TEnumAsByte<ECollisionEnabled::Type> CollisionEnabled;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Test/FractTestCharacter.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_CollisionEnabled;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_AFractTestCharacter_SetWeaponCollisionEnabled_Statics::NewProp_CollisionEnabled = { "CollisionEnabled", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FractTestCharacter_eventSetWeaponCollisionEnabled_Parms, CollisionEnabled), Z_Construct_UEnum_Engine_ECollisionEnabled, METADATA_PARAMS(0, nullptr) }; // 2362857466
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AFractTestCharacter_SetWeaponCollisionEnabled_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AFractTestCharacter_SetWeaponCollisionEnabled_Statics::NewProp_CollisionEnabled,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AFractTestCharacter_SetWeaponCollisionEnabled_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AFractTestCharacter_SetWeaponCollisionEnabled_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AFractTestCharacter, nullptr, "SetWeaponCollisionEnabled", nullptr, nullptr, Z_Construct_UFunction_AFractTestCharacter_SetWeaponCollisionEnabled_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AFractTestCharacter_SetWeaponCollisionEnabled_Statics::PropPointers), sizeof(Z_Construct_UFunction_AFractTestCharacter_SetWeaponCollisionEnabled_Statics::FractTestCharacter_eventSetWeaponCollisionEnabled_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AFractTestCharacter_SetWeaponCollisionEnabled_Statics::Function_MetaDataParams), Z_Construct_UFunction_AFractTestCharacter_SetWeaponCollisionEnabled_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AFractTestCharacter_SetWeaponCollisionEnabled_Statics::FractTestCharacter_eventSetWeaponCollisionEnabled_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AFractTestCharacter_SetWeaponCollisionEnabled()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AFractTestCharacter_SetWeaponCollisionEnabled_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AFractTestCharacter::execSetWeaponCollisionEnabled)
{
	P_GET_PROPERTY(FByteProperty,Z_Param_CollisionEnabled);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetWeaponCollisionEnabled(ECollisionEnabled::Type(Z_Param_CollisionEnabled));
	P_NATIVE_END;
}
// End Class AFractTestCharacter Function SetWeaponCollisionEnabled

// Begin Class AFractTestCharacter Function SwitchWeaponSocket
struct Z_Construct_UFunction_AFractTestCharacter_SwitchWeaponSocket_Statics
{
	struct FractTestCharacter_eventSwitchWeaponSocket_Parms
	{
		bool bIsRight;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Test/FractTestCharacter.h" },
	};
#endif // WITH_METADATA
	static void NewProp_bIsRight_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsRight;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_AFractTestCharacter_SwitchWeaponSocket_Statics::NewProp_bIsRight_SetBit(void* Obj)
{
	((FractTestCharacter_eventSwitchWeaponSocket_Parms*)Obj)->bIsRight = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AFractTestCharacter_SwitchWeaponSocket_Statics::NewProp_bIsRight = { "bIsRight", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FractTestCharacter_eventSwitchWeaponSocket_Parms), &Z_Construct_UFunction_AFractTestCharacter_SwitchWeaponSocket_Statics::NewProp_bIsRight_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AFractTestCharacter_SwitchWeaponSocket_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AFractTestCharacter_SwitchWeaponSocket_Statics::NewProp_bIsRight,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AFractTestCharacter_SwitchWeaponSocket_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AFractTestCharacter_SwitchWeaponSocket_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AFractTestCharacter, nullptr, "SwitchWeaponSocket", nullptr, nullptr, Z_Construct_UFunction_AFractTestCharacter_SwitchWeaponSocket_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AFractTestCharacter_SwitchWeaponSocket_Statics::PropPointers), sizeof(Z_Construct_UFunction_AFractTestCharacter_SwitchWeaponSocket_Statics::FractTestCharacter_eventSwitchWeaponSocket_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AFractTestCharacter_SwitchWeaponSocket_Statics::Function_MetaDataParams), Z_Construct_UFunction_AFractTestCharacter_SwitchWeaponSocket_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AFractTestCharacter_SwitchWeaponSocket_Statics::FractTestCharacter_eventSwitchWeaponSocket_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AFractTestCharacter_SwitchWeaponSocket()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AFractTestCharacter_SwitchWeaponSocket_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AFractTestCharacter::execSwitchWeaponSocket)
{
	P_GET_UBOOL(Z_Param_bIsRight);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SwitchWeaponSocket(Z_Param_bIsRight);
	P_NATIVE_END;
}
// End Class AFractTestCharacter Function SwitchWeaponSocket

// Begin Class AFractTestCharacter
void AFractTestCharacter::StaticRegisterNativesAFractTestCharacter()
{
	UClass* Class = AFractTestCharacter::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "GetWeapon", &AFractTestCharacter::execGetWeapon },
		{ "SetAllowPhysicsRotationDuringAnimRootMotion", &AFractTestCharacter::execSetAllowPhysicsRotationDuringAnimRootMotion },
		{ "SetWeaponCollisionEnabled", &AFractTestCharacter::execSetWeaponCollisionEnabled },
		{ "SwitchWeaponSocket", &AFractTestCharacter::execSwitchWeaponSocket },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AFractTestCharacter);
UClass* Z_Construct_UClass_AFractTestCharacter_NoRegister()
{
	return AFractTestCharacter::StaticClass();
}
struct Z_Construct_UClass_AFractTestCharacter_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Test/FractTestCharacter.h" },
		{ "ModuleRelativePath", "Public/Test/FractTestCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Attribute_MetaData[] = {
		{ "Category", "Attribute" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Test/FractTestCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AttackComponent_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Attack" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Test/FractTestCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WeaponClass_MetaData[] = {
		{ "Category", "Weapon" },
		{ "ModuleRelativePath", "Public/Test/FractTestCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Weapon_MetaData[] = {
		{ "Category", "Weapon" },
		{ "ModuleRelativePath", "Public/Test/FractTestCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NormalAttackAction_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Public/Test/FractTestCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SwitchRangeAction_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Public/Test/FractTestCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MovementInputVector_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Public/Test/FractTestCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CharacterState_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "State" },
		{ "ModuleRelativePath", "Public/Test/FractTestCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MotionWarpingComponent_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Attack" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Test/FractTestCharacter.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Attribute;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_AttackComponent;
	static const UECodeGen_Private::FClassPropertyParams NewProp_WeaponClass;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Weapon;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_NormalAttackAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SwitchRangeAction;
	static const UECodeGen_Private::FStructPropertyParams NewProp_MovementInputVector;
	static const UECodeGen_Private::FBytePropertyParams NewProp_CharacterState_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_CharacterState;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MotionWarpingComponent;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AFractTestCharacter_GetWeapon, "GetWeapon" }, // 2625864155
		{ &Z_Construct_UFunction_AFractTestCharacter_SetAllowPhysicsRotationDuringAnimRootMotion, "SetAllowPhysicsRotationDuringAnimRootMotion" }, // 3265561689
		{ &Z_Construct_UFunction_AFractTestCharacter_SetWeaponCollisionEnabled, "SetWeaponCollisionEnabled" }, // 3899947263
		{ &Z_Construct_UFunction_AFractTestCharacter_SwitchWeaponSocket, "SwitchWeaponSocket" }, // 3485043628
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AFractTestCharacter>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFractTestCharacter_Statics::NewProp_Attribute = { "Attribute", nullptr, (EPropertyFlags)0x00400000000a0009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFractTestCharacter, Attribute), Z_Construct_UClass_UFractPlayerAttributeComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Attribute_MetaData), NewProp_Attribute_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFractTestCharacter_Statics::NewProp_AttackComponent = { "AttackComponent", nullptr, (EPropertyFlags)0x004000000008001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFractTestCharacter, AttackComponent), Z_Construct_UClass_UFractPlayerAttackComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AttackComponent_MetaData), NewProp_AttackComponent_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AFractTestCharacter_Statics::NewProp_WeaponClass = { "WeaponClass", nullptr, (EPropertyFlags)0x0044000000010001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFractTestCharacter, WeaponClass), Z_Construct_UClass_UClass, Z_Construct_UClass_AFractPlayerWeapon_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WeaponClass_MetaData), NewProp_WeaponClass_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFractTestCharacter_Statics::NewProp_Weapon = { "Weapon", nullptr, (EPropertyFlags)0x0040000000030001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFractTestCharacter, Weapon), Z_Construct_UClass_AFractPlayerWeapon_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Weapon_MetaData), NewProp_Weapon_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFractTestCharacter_Statics::NewProp_NormalAttackAction = { "NormalAttackAction", nullptr, (EPropertyFlags)0x0040000000010001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFractTestCharacter, NormalAttackAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NormalAttackAction_MetaData), NewProp_NormalAttackAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFractTestCharacter_Statics::NewProp_SwitchRangeAction = { "SwitchRangeAction", nullptr, (EPropertyFlags)0x0040000000010001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFractTestCharacter, SwitchRangeAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SwitchRangeAction_MetaData), NewProp_SwitchRangeAction_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AFractTestCharacter_Statics::NewProp_MovementInputVector = { "MovementInputVector", nullptr, (EPropertyFlags)0x0040000000030001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFractTestCharacter, MovementInputVector), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MovementInputVector_MetaData), NewProp_MovementInputVector_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_AFractTestCharacter_Statics::NewProp_CharacterState_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_AFractTestCharacter_Statics::NewProp_CharacterState = { "CharacterState", nullptr, (EPropertyFlags)0x0040000000010005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFractTestCharacter, CharacterState), Z_Construct_UEnum_Alpha_EFractCharacterState, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CharacterState_MetaData), NewProp_CharacterState_MetaData) }; // 3248930071
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFractTestCharacter_Statics::NewProp_MotionWarpingComponent = { "MotionWarpingComponent", nullptr, (EPropertyFlags)0x00400000000b000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFractTestCharacter, MotionWarpingComponent), Z_Construct_UClass_UMotionWarpingComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MotionWarpingComponent_MetaData), NewProp_MotionWarpingComponent_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AFractTestCharacter_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFractTestCharacter_Statics::NewProp_Attribute,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFractTestCharacter_Statics::NewProp_AttackComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFractTestCharacter_Statics::NewProp_WeaponClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFractTestCharacter_Statics::NewProp_Weapon,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFractTestCharacter_Statics::NewProp_NormalAttackAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFractTestCharacter_Statics::NewProp_SwitchRangeAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFractTestCharacter_Statics::NewProp_MovementInputVector,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFractTestCharacter_Statics::NewProp_CharacterState_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFractTestCharacter_Statics::NewProp_CharacterState,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFractTestCharacter_Statics::NewProp_MotionWarpingComponent,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AFractTestCharacter_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AFractTestCharacter_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AAlphaCharacter,
	(UObject* (*)())Z_Construct_UPackage__Script_Alpha,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AFractTestCharacter_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AFractTestCharacter_Statics::ClassParams = {
	&AFractTestCharacter::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_AFractTestCharacter_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_AFractTestCharacter_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AFractTestCharacter_Statics::Class_MetaDataParams), Z_Construct_UClass_AFractTestCharacter_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AFractTestCharacter()
{
	if (!Z_Registration_Info_UClass_AFractTestCharacter.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AFractTestCharacter.OuterSingleton, Z_Construct_UClass_AFractTestCharacter_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AFractTestCharacter.OuterSingleton;
}
template<> ALPHA_API UClass* StaticClass<AFractTestCharacter>()
{
	return AFractTestCharacter::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AFractTestCharacter);
AFractTestCharacter::~AFractTestCharacter() {}
// End Class AFractTestCharacter

// Begin Registration
struct Z_CompiledInDeferFile_FID_Alpha_Source_Alpha_Public_Test_FractTestCharacter_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AFractTestCharacter, AFractTestCharacter::StaticClass, TEXT("AFractTestCharacter"), &Z_Registration_Info_UClass_AFractTestCharacter, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AFractTestCharacter), 444569168U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Alpha_Source_Alpha_Public_Test_FractTestCharacter_h_348463036(TEXT("/Script/Alpha"),
	Z_CompiledInDeferFile_FID_Alpha_Source_Alpha_Public_Test_FractTestCharacter_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Alpha_Source_Alpha_Public_Test_FractTestCharacter_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
