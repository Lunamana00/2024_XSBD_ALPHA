// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Alpha/AIC_Enemy_1.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAIC_Enemy_1() {}

// Begin Cross Module References
AIMODULE_API UClass* Z_Construct_UClass_AAIController();
ALPHA_API UClass* Z_Construct_UClass_AAIC_Enemy_1();
ALPHA_API UClass* Z_Construct_UClass_AAIC_Enemy_1_NoRegister();
UPackage* Z_Construct_UPackage__Script_Alpha();
// End Cross Module References

// Begin Class AAIC_Enemy_1
void AAIC_Enemy_1::StaticRegisterNativesAAIC_Enemy_1()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AAIC_Enemy_1);
UClass* Z_Construct_UClass_AAIC_Enemy_1_NoRegister()
{
	return AAIC_Enemy_1::StaticClass();
}
struct Z_Construct_UClass_AAIC_Enemy_1_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Collision Rendering Transformation" },
		{ "IncludePath", "AIC_Enemy_1.h" },
		{ "ModuleRelativePath", "AIC_Enemy_1.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AAIC_Enemy_1>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_AAIC_Enemy_1_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AAIController,
	(UObject* (*)())Z_Construct_UPackage__Script_Alpha,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AAIC_Enemy_1_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AAIC_Enemy_1_Statics::ClassParams = {
	&AAIC_Enemy_1::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x009002A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AAIC_Enemy_1_Statics::Class_MetaDataParams), Z_Construct_UClass_AAIC_Enemy_1_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AAIC_Enemy_1()
{
	if (!Z_Registration_Info_UClass_AAIC_Enemy_1.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AAIC_Enemy_1.OuterSingleton, Z_Construct_UClass_AAIC_Enemy_1_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AAIC_Enemy_1.OuterSingleton;
}
template<> ALPHA_API UClass* StaticClass<AAIC_Enemy_1>()
{
	return AAIC_Enemy_1::StaticClass();
}
AAIC_Enemy_1::AAIC_Enemy_1(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(AAIC_Enemy_1);
AAIC_Enemy_1::~AAIC_Enemy_1() {}
// End Class AAIC_Enemy_1

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_kth00_Documents_GitHub_2024_XSBD_ALPHA_Alpha_Source_Alpha_AIC_Enemy_1_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AAIC_Enemy_1, AAIC_Enemy_1::StaticClass, TEXT("AAIC_Enemy_1"), &Z_Registration_Info_UClass_AAIC_Enemy_1, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AAIC_Enemy_1), 1079553343U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_kth00_Documents_GitHub_2024_XSBD_ALPHA_Alpha_Source_Alpha_AIC_Enemy_1_h_3869648809(TEXT("/Script/Alpha"),
	Z_CompiledInDeferFile_FID_Users_kth00_Documents_GitHub_2024_XSBD_ALPHA_Alpha_Source_Alpha_AIC_Enemy_1_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_kth00_Documents_GitHub_2024_XSBD_ALPHA_Alpha_Source_Alpha_AIC_Enemy_1_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
