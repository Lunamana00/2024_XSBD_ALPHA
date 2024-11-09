// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Alpha/AIController_Enemy_type1.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAIController_Enemy_type1() {}

// Begin Cross Module References
AIMODULE_API UClass* Z_Construct_UClass_AAIController();
ALPHA_API UClass* Z_Construct_UClass_AAIController_Enemy_type1();
ALPHA_API UClass* Z_Construct_UClass_AAIController_Enemy_type1_NoRegister();
UPackage* Z_Construct_UPackage__Script_Alpha();
// End Cross Module References

// Begin Class AAIController_Enemy_type1
void AAIController_Enemy_type1::StaticRegisterNativesAAIController_Enemy_type1()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AAIController_Enemy_type1);
UClass* Z_Construct_UClass_AAIController_Enemy_type1_NoRegister()
{
	return AAIController_Enemy_type1::StaticClass();
}
struct Z_Construct_UClass_AAIController_Enemy_type1_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Collision Rendering Transformation" },
		{ "IncludePath", "AIController_Enemy_type1.h" },
		{ "ModuleRelativePath", "AIController_Enemy_type1.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AAIController_Enemy_type1>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_AAIController_Enemy_type1_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AAIController,
	(UObject* (*)())Z_Construct_UPackage__Script_Alpha,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AAIController_Enemy_type1_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AAIController_Enemy_type1_Statics::ClassParams = {
	&AAIController_Enemy_type1::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AAIController_Enemy_type1_Statics::Class_MetaDataParams), Z_Construct_UClass_AAIController_Enemy_type1_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AAIController_Enemy_type1()
{
	if (!Z_Registration_Info_UClass_AAIController_Enemy_type1.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AAIController_Enemy_type1.OuterSingleton, Z_Construct_UClass_AAIController_Enemy_type1_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AAIController_Enemy_type1.OuterSingleton;
}
template<> ALPHA_API UClass* StaticClass<AAIController_Enemy_type1>()
{
	return AAIController_Enemy_type1::StaticClass();
}
AAIController_Enemy_type1::AAIController_Enemy_type1(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(AAIController_Enemy_type1);
AAIController_Enemy_type1::~AAIController_Enemy_type1() {}
// End Class AAIController_Enemy_type1

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_kth00_Documents_GitHub_2024_XSBD_ALPHA_Alpha_Source_Alpha_AIController_Enemy_type1_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AAIController_Enemy_type1, AAIController_Enemy_type1::StaticClass, TEXT("AAIController_Enemy_type1"), &Z_Registration_Info_UClass_AAIController_Enemy_type1, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AAIController_Enemy_type1), 2918030976U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_kth00_Documents_GitHub_2024_XSBD_ALPHA_Alpha_Source_Alpha_AIController_Enemy_type1_h_2454970009(TEXT("/Script/Alpha"),
	Z_CompiledInDeferFile_FID_Users_kth00_Documents_GitHub_2024_XSBD_ALPHA_Alpha_Source_Alpha_AIController_Enemy_type1_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_kth00_Documents_GitHub_2024_XSBD_ALPHA_Alpha_Source_Alpha_AIController_Enemy_type1_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
