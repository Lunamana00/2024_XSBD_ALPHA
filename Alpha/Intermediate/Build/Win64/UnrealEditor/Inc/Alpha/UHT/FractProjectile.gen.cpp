// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Alpha/Public/Weapons/FractProjectile.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFractProjectile() {}

// Begin Cross Module References
ALPHA_API UClass* Z_Construct_UClass_AFractProjectile();
ALPHA_API UClass* Z_Construct_UClass_AFractProjectile_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_AActor();
ENGINE_API UClass* Z_Construct_UClass_UBoxComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UProjectileMovementComponent_NoRegister();
NIAGARA_API UClass* Z_Construct_UClass_UNiagaraComponent_NoRegister();
NIAGARA_API UClass* Z_Construct_UClass_UNiagaraSystem_NoRegister();
UPackage* Z_Construct_UPackage__Script_Alpha();
// End Cross Module References

// Begin Class AFractProjectile
void AFractProjectile::StaticRegisterNativesAFractProjectile()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AFractProjectile);
UClass* Z_Construct_UClass_AFractProjectile_NoRegister()
{
	return AFractProjectile::StaticClass();
}
struct Z_Construct_UClass_AFractProjectile_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "Weapons/FractProjectile.h" },
		{ "ModuleRelativePath", "Public/Weapons/FractProjectile.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CollisionBox_MetaData[] = {
		{ "Category", "FractProjectile" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Weapons/FractProjectile.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ProjectileMovementComponent_MetaData[] = {
		{ "Category", "FractProjectile" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Weapons/FractProjectile.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TracerEffect_MetaData[] = {
		{ "Category", "FractProjectile" },
		{ "ModuleRelativePath", "Public/Weapons/FractProjectile.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NiagaraComponent_MetaData[] = {
		{ "Category", "FractProjectile" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Weapons/FractProjectile.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CollisionBox;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ProjectileMovementComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TracerEffect;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_NiagaraComponent;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AFractProjectile>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFractProjectile_Statics::NewProp_CollisionBox = { "CollisionBox", nullptr, (EPropertyFlags)0x0040000000080009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFractProjectile, CollisionBox), Z_Construct_UClass_UBoxComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CollisionBox_MetaData), NewProp_CollisionBox_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFractProjectile_Statics::NewProp_ProjectileMovementComponent = { "ProjectileMovementComponent", nullptr, (EPropertyFlags)0x00400000000a0009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFractProjectile, ProjectileMovementComponent), Z_Construct_UClass_UProjectileMovementComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ProjectileMovementComponent_MetaData), NewProp_ProjectileMovementComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFractProjectile_Statics::NewProp_TracerEffect = { "TracerEffect", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFractProjectile, TracerEffect), Z_Construct_UClass_UNiagaraSystem_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TracerEffect_MetaData), NewProp_TracerEffect_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFractProjectile_Statics::NewProp_NiagaraComponent = { "NiagaraComponent", nullptr, (EPropertyFlags)0x0040000000080009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFractProjectile, NiagaraComponent), Z_Construct_UClass_UNiagaraComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NiagaraComponent_MetaData), NewProp_NiagaraComponent_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AFractProjectile_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFractProjectile_Statics::NewProp_CollisionBox,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFractProjectile_Statics::NewProp_ProjectileMovementComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFractProjectile_Statics::NewProp_TracerEffect,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFractProjectile_Statics::NewProp_NiagaraComponent,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AFractProjectile_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AFractProjectile_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_Alpha,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AFractProjectile_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AFractProjectile_Statics::ClassParams = {
	&AFractProjectile::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_AFractProjectile_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_AFractProjectile_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AFractProjectile_Statics::Class_MetaDataParams), Z_Construct_UClass_AFractProjectile_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AFractProjectile()
{
	if (!Z_Registration_Info_UClass_AFractProjectile.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AFractProjectile.OuterSingleton, Z_Construct_UClass_AFractProjectile_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AFractProjectile.OuterSingleton;
}
template<> ALPHA_API UClass* StaticClass<AFractProjectile>()
{
	return AFractProjectile::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AFractProjectile);
AFractProjectile::~AFractProjectile() {}
// End Class AFractProjectile

// Begin Registration
struct Z_CompiledInDeferFile_FID_Alpha_Source_Alpha_Public_Weapons_FractProjectile_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AFractProjectile, AFractProjectile::StaticClass, TEXT("AFractProjectile"), &Z_Registration_Info_UClass_AFractProjectile, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AFractProjectile), 153200873U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Alpha_Source_Alpha_Public_Weapons_FractProjectile_h_507587772(TEXT("/Script/Alpha"),
	Z_CompiledInDeferFile_FID_Alpha_Source_Alpha_Public_Weapons_FractProjectile_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Alpha_Source_Alpha_Public_Weapons_FractProjectile_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
