// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Alpha/Public/Interfaces/FractHitInterface.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFractHitInterface() {}

// Begin Cross Module References
ALPHA_API UClass* Z_Construct_UClass_UFractHitInterface();
ALPHA_API UClass* Z_Construct_UClass_UFractHitInterface_NoRegister();
COREUOBJECT_API UClass* Z_Construct_UClass_UInterface();
UPackage* Z_Construct_UPackage__Script_Alpha();
// End Cross Module References

// Begin Interface UFractHitInterface
void UFractHitInterface::StaticRegisterNativesUFractHitInterface()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UFractHitInterface);
UClass* Z_Construct_UClass_UFractHitInterface_NoRegister()
{
	return UFractHitInterface::StaticClass();
}
struct Z_Construct_UClass_UFractHitInterface_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Interfaces/FractHitInterface.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<IFractHitInterface>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UFractHitInterface_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UInterface,
	(UObject* (*)())Z_Construct_UPackage__Script_Alpha,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UFractHitInterface_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UFractHitInterface_Statics::ClassParams = {
	&UFractHitInterface::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x000840A1u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UFractHitInterface_Statics::Class_MetaDataParams), Z_Construct_UClass_UFractHitInterface_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UFractHitInterface()
{
	if (!Z_Registration_Info_UClass_UFractHitInterface.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UFractHitInterface.OuterSingleton, Z_Construct_UClass_UFractHitInterface_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UFractHitInterface.OuterSingleton;
}
template<> ALPHA_API UClass* StaticClass<UFractHitInterface>()
{
	return UFractHitInterface::StaticClass();
}
UFractHitInterface::UFractHitInterface(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UFractHitInterface);
UFractHitInterface::~UFractHitInterface() {}
// End Interface UFractHitInterface

// Begin Registration
struct Z_CompiledInDeferFile_FID_Alpha_Source_Alpha_Public_Interfaces_FractHitInterface_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UFractHitInterface, UFractHitInterface::StaticClass, TEXT("UFractHitInterface"), &Z_Registration_Info_UClass_UFractHitInterface, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UFractHitInterface), 2237144319U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Alpha_Source_Alpha_Public_Interfaces_FractHitInterface_h_4240089782(TEXT("/Script/Alpha"),
	Z_CompiledInDeferFile_FID_Alpha_Source_Alpha_Public_Interfaces_FractHitInterface_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Alpha_Source_Alpha_Public_Interfaces_FractHitInterface_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
