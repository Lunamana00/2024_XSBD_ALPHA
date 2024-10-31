// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Alpha/Public/Components/FractAttributeComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFractAttributeComponent() {}

// Begin Cross Module References
ALPHA_API UClass* Z_Construct_UClass_UFractAttributeComponent();
ALPHA_API UClass* Z_Construct_UClass_UFractAttributeComponent_NoRegister();
ALPHA_API UEnum* Z_Construct_UEnum_Alpha_EFractElementType();
ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
UPackage* Z_Construct_UPackage__Script_Alpha();
// End Cross Module References

// Begin Class UFractAttributeComponent
void UFractAttributeComponent::StaticRegisterNativesUFractAttributeComponent()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UFractAttributeComponent);
UClass* Z_Construct_UClass_UFractAttributeComponent_NoRegister()
{
	return UFractAttributeComponent::StaticClass();
}
struct Z_Construct_UClass_UFractAttributeComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
		{ "IncludePath", "Components/FractAttributeComponent.h" },
		{ "ModuleRelativePath", "Public/Components/FractAttributeComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentHealth_MetaData[] = {
		{ "Category", "Attributes" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Health is current health\n" },
#endif
		{ "ModuleRelativePath", "Public/Components/FractAttributeComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Health is current health" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxHealth_MetaData[] = {
		{ "Category", "Attributes" },
		{ "ModuleRelativePath", "Public/Components/FractAttributeComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BaseDamage_MetaData[] = {
		{ "Category", "Attributes" },
		{ "ModuleRelativePath", "Public/Components/FractAttributeComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ElementType_MetaData[] = {
		{ "Category", "Attributes" },
		{ "ModuleRelativePath", "Public/Components/FractAttributeComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CurrentHealth;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxHealth;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_BaseDamage;
	static const UECodeGen_Private::FBytePropertyParams NewProp_ElementType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ElementType;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UFractAttributeComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UFractAttributeComponent_Statics::NewProp_CurrentHealth = { "CurrentHealth", nullptr, (EPropertyFlags)0x0020080000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UFractAttributeComponent, CurrentHealth), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentHealth_MetaData), NewProp_CurrentHealth_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UFractAttributeComponent_Statics::NewProp_MaxHealth = { "MaxHealth", nullptr, (EPropertyFlags)0x0020080000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UFractAttributeComponent, MaxHealth), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxHealth_MetaData), NewProp_MaxHealth_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UFractAttributeComponent_Statics::NewProp_BaseDamage = { "BaseDamage", nullptr, (EPropertyFlags)0x0020080000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UFractAttributeComponent, BaseDamage), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BaseDamage_MetaData), NewProp_BaseDamage_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UFractAttributeComponent_Statics::NewProp_ElementType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UFractAttributeComponent_Statics::NewProp_ElementType = { "ElementType", nullptr, (EPropertyFlags)0x0020080000000015, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UFractAttributeComponent, ElementType), Z_Construct_UEnum_Alpha_EFractElementType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ElementType_MetaData), NewProp_ElementType_MetaData) }; // 1003798865
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UFractAttributeComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFractAttributeComponent_Statics::NewProp_CurrentHealth,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFractAttributeComponent_Statics::NewProp_MaxHealth,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFractAttributeComponent_Statics::NewProp_BaseDamage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFractAttributeComponent_Statics::NewProp_ElementType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFractAttributeComponent_Statics::NewProp_ElementType,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UFractAttributeComponent_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UFractAttributeComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UActorComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_Alpha,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UFractAttributeComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UFractAttributeComponent_Statics::ClassParams = {
	&UFractAttributeComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UFractAttributeComponent_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UFractAttributeComponent_Statics::PropPointers),
	0,
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UFractAttributeComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UFractAttributeComponent_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UFractAttributeComponent()
{
	if (!Z_Registration_Info_UClass_UFractAttributeComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UFractAttributeComponent.OuterSingleton, Z_Construct_UClass_UFractAttributeComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UFractAttributeComponent.OuterSingleton;
}
template<> ALPHA_API UClass* StaticClass<UFractAttributeComponent>()
{
	return UFractAttributeComponent::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UFractAttributeComponent);
UFractAttributeComponent::~UFractAttributeComponent() {}
// End Class UFractAttributeComponent

// Begin Registration
struct Z_CompiledInDeferFile_FID_Alpha_Source_Alpha_Public_Components_FractAttributeComponent_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UFractAttributeComponent, UFractAttributeComponent::StaticClass, TEXT("UFractAttributeComponent"), &Z_Registration_Info_UClass_UFractAttributeComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UFractAttributeComponent), 19469010U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Alpha_Source_Alpha_Public_Components_FractAttributeComponent_h_3833103533(TEXT("/Script/Alpha"),
	Z_CompiledInDeferFile_FID_Alpha_Source_Alpha_Public_Components_FractAttributeComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Alpha_Source_Alpha_Public_Components_FractAttributeComponent_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
