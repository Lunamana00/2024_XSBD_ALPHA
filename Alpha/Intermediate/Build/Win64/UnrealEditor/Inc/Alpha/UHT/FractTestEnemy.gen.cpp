// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Alpha/Public/Test/FractTestEnemy.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFractTestEnemy() {}

// Begin Cross Module References
ALPHA_API UClass* Z_Construct_UClass_AFractTestEnemy();
ALPHA_API UClass* Z_Construct_UClass_AFractTestEnemy_NoRegister();
ALPHA_API UClass* Z_Construct_UClass_UFractHitInterface_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_ACharacter();
UPackage* Z_Construct_UPackage__Script_Alpha();
// End Cross Module References

// Begin Class AFractTestEnemy
void AFractTestEnemy::StaticRegisterNativesAFractTestEnemy()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AFractTestEnemy);
UClass* Z_Construct_UClass_AFractTestEnemy_NoRegister()
{
	return AFractTestEnemy::StaticClass();
}
struct Z_Construct_UClass_AFractTestEnemy_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Test/FractTestEnemy.h" },
		{ "ModuleRelativePath", "Public/Test/FractTestEnemy.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static const UECodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AFractTestEnemy>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_AFractTestEnemy_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ACharacter,
	(UObject* (*)())Z_Construct_UPackage__Script_Alpha,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AFractTestEnemy_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_AFractTestEnemy_Statics::InterfaceParams[] = {
	{ Z_Construct_UClass_UFractHitInterface_NoRegister, (int32)VTABLE_OFFSET(AFractTestEnemy, IFractHitInterface), false },  // 2237144319
};
const UECodeGen_Private::FClassParams Z_Construct_UClass_AFractTestEnemy_Statics::ClassParams = {
	&AFractTestEnemy::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	InterfaceParams,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	UE_ARRAY_COUNT(InterfaceParams),
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AFractTestEnemy_Statics::Class_MetaDataParams), Z_Construct_UClass_AFractTestEnemy_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AFractTestEnemy()
{
	if (!Z_Registration_Info_UClass_AFractTestEnemy.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AFractTestEnemy.OuterSingleton, Z_Construct_UClass_AFractTestEnemy_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AFractTestEnemy.OuterSingleton;
}
template<> ALPHA_API UClass* StaticClass<AFractTestEnemy>()
{
	return AFractTestEnemy::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AFractTestEnemy);
AFractTestEnemy::~AFractTestEnemy() {}
// End Class AFractTestEnemy

// Begin Registration
struct Z_CompiledInDeferFile_FID_Alpha_Source_Alpha_Public_Test_FractTestEnemy_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AFractTestEnemy, AFractTestEnemy::StaticClass, TEXT("AFractTestEnemy"), &Z_Registration_Info_UClass_AFractTestEnemy, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AFractTestEnemy), 731575794U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Alpha_Source_Alpha_Public_Test_FractTestEnemy_h_4065009163(TEXT("/Script/Alpha"),
	Z_CompiledInDeferFile_FID_Alpha_Source_Alpha_Public_Test_FractTestEnemy_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Alpha_Source_Alpha_Public_Test_FractTestEnemy_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
