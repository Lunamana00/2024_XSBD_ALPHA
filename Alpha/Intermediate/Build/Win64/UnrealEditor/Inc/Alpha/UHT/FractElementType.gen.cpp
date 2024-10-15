// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Alpha/Public/Enums/FractElementType.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFractElementType() {}

// Begin Cross Module References
ALPHA_API UEnum* Z_Construct_UEnum_Alpha_EFractElementType();
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
		{ "Earth.DisplayName", "Earth" },
		{ "Earth.Name", "EFractElementType::Earth" },
		{ "Fire.DisplayName", "Fire" },
		{ "Fire.Name", "EFractElementType::Fire" },
		{ "ModuleRelativePath", "Public/Enums/FractElementType.h" },
		{ "None.DisplayName", "None" },
		{ "None.Name", "EFractElementType::None" },
		{ "Player.DisplayName", "Player" },
		{ "Player.Name", "EFractElementType::Player" },
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

// Begin Registration
struct Z_CompiledInDeferFile_FID_Alpha_Source_Alpha_Public_Enums_FractElementType_h_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EFractElementType_StaticEnum, TEXT("EFractElementType"), &Z_Registration_Info_UEnum_EFractElementType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3201866547U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Alpha_Source_Alpha_Public_Enums_FractElementType_h_2615144629(TEXT("/Script/Alpha"),
	nullptr, 0,
	nullptr, 0,
	Z_CompiledInDeferFile_FID_Alpha_Source_Alpha_Public_Enums_FractElementType_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Alpha_Source_Alpha_Public_Enums_FractElementType_h_Statics::EnumInfo));
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
