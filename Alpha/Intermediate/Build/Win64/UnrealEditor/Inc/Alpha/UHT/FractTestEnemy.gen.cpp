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
ALPHA_API UClass* Z_Construct_UClass_UFractAttributeComponent_NoRegister();
ALPHA_API UClass* Z_Construct_UClass_UFractHitInterface_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_ACharacter();
ENGINE_API UClass* Z_Construct_UClass_UAnimMontage_NoRegister();
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
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HitReactMontage_MetaData[] = {
		{ "Category", "Montages" },
		{ "ModuleRelativePath", "Public/Test/FractTestEnemy.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Attribute_MetaData[] = {
		{ "Category", "Attributes" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Test/FractTestEnemy.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_HitReactMontage;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Attribute;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static const UECodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AFractTestEnemy>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFractTestEnemy_Statics::NewProp_HitReactMontage = { "HitReactMontage", nullptr, (EPropertyFlags)0x0040000000010001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFractTestEnemy, HitReactMontage), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HitReactMontage_MetaData), NewProp_HitReactMontage_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFractTestEnemy_Statics::NewProp_Attribute = { "Attribute", nullptr, (EPropertyFlags)0x0040000000090009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFractTestEnemy, Attribute), Z_Construct_UClass_UFractAttributeComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Attribute_MetaData), NewProp_Attribute_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AFractTestEnemy_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFractTestEnemy_Statics::NewProp_HitReactMontage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFractTestEnemy_Statics::NewProp_Attribute,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AFractTestEnemy_Statics::PropPointers) < 2048);
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
	Z_Construct_UClass_AFractTestEnemy_Statics::PropPointers,
	InterfaceParams,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_AFractTestEnemy_Statics::PropPointers),
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
		{ Z_Construct_UClass_AFractTestEnemy, AFractTestEnemy::StaticClass, TEXT("AFractTestEnemy"), &Z_Registration_Info_UClass_AFractTestEnemy, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AFractTestEnemy), 3316432486U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Alpha_Source_Alpha_Public_Test_FractTestEnemy_h_884040442(TEXT("/Script/Alpha"),
	Z_CompiledInDeferFile_FID_Alpha_Source_Alpha_Public_Test_FractTestEnemy_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Alpha_Source_Alpha_Public_Test_FractTestEnemy_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
