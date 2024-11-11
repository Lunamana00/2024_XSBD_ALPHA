// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Components/FractPlayerAttackComponent.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef ALPHA_FractPlayerAttackComponent_generated_h
#error "FractPlayerAttackComponent.generated.h already included, missing '#pragma once' in FractPlayerAttackComponent.h"
#endif
#define ALPHA_FractPlayerAttackComponent_generated_h

#define FID_Alpha_Source_Alpha_Public_Components_FractPlayerAttackComponent_h_20_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execResetCombo);


#define FID_Alpha_Source_Alpha_Public_Components_FractPlayerAttackComponent_h_20_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUFractPlayerAttackComponent(); \
	friend struct Z_Construct_UClass_UFractPlayerAttackComponent_Statics; \
public: \
	DECLARE_CLASS(UFractPlayerAttackComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Alpha"), NO_API) \
	DECLARE_SERIALIZER(UFractPlayerAttackComponent)


#define FID_Alpha_Source_Alpha_Public_Components_FractPlayerAttackComponent_h_20_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UFractPlayerAttackComponent(UFractPlayerAttackComponent&&); \
	UFractPlayerAttackComponent(const UFractPlayerAttackComponent&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UFractPlayerAttackComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UFractPlayerAttackComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UFractPlayerAttackComponent) \
	NO_API virtual ~UFractPlayerAttackComponent();


#define FID_Alpha_Source_Alpha_Public_Components_FractPlayerAttackComponent_h_17_PROLOG
#define FID_Alpha_Source_Alpha_Public_Components_FractPlayerAttackComponent_h_20_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Alpha_Source_Alpha_Public_Components_FractPlayerAttackComponent_h_20_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Alpha_Source_Alpha_Public_Components_FractPlayerAttackComponent_h_20_INCLASS_NO_PURE_DECLS \
	FID_Alpha_Source_Alpha_Public_Components_FractPlayerAttackComponent_h_20_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ALPHA_API UClass* StaticClass<class UFractPlayerAttackComponent>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Alpha_Source_Alpha_Public_Components_FractPlayerAttackComponent_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
