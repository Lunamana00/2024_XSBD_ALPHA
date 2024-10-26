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
ALPHA_API UClass* Z_Construct_UClass_AFractTestCharacter();
ALPHA_API UClass* Z_Construct_UClass_AFractTestCharacter_NoRegister();
ALPHA_API UClass* Z_Construct_UClass_UFractPlayerAttributeComponent_NoRegister();
UPackage* Z_Construct_UPackage__Script_Alpha();
// End Cross Module References

// Begin Class AFractTestCharacter
void AFractTestCharacter::StaticRegisterNativesAFractTestCharacter()
{
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
		{ "Category", "Attributes" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Test/FractTestCharacter.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Attribute;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AFractTestCharacter>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFractTestCharacter_Statics::NewProp_Attribute = { "Attribute", nullptr, (EPropertyFlags)0x0040000000090009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFractTestCharacter, Attribute), Z_Construct_UClass_UFractPlayerAttributeComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Attribute_MetaData), NewProp_Attribute_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AFractTestCharacter_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFractTestCharacter_Statics::NewProp_Attribute,
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
	nullptr,
	Z_Construct_UClass_AFractTestCharacter_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
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
AFractTestCharacter::AFractTestCharacter() {}
DEFINE_VTABLE_PTR_HELPER_CTOR(AFractTestCharacter);
AFractTestCharacter::~AFractTestCharacter() {}
// End Class AFractTestCharacter

// Begin Registration
struct Z_CompiledInDeferFile_FID_Alpha_Source_Alpha_Public_Test_FractTestCharacter_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AFractTestCharacter, AFractTestCharacter::StaticClass, TEXT("AFractTestCharacter"), &Z_Registration_Info_UClass_AFractTestCharacter, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AFractTestCharacter), 3883855323U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Alpha_Source_Alpha_Public_Test_FractTestCharacter_h_1298815734(TEXT("/Script/Alpha"),
	Z_CompiledInDeferFile_FID_Alpha_Source_Alpha_Public_Test_FractTestCharacter_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Alpha_Source_Alpha_Public_Test_FractTestCharacter_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
