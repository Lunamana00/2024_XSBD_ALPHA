// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Weapons/FractProjectile.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef ALPHA_FractProjectile_generated_h
#error "FractProjectile.generated.h already included, missing '#pragma once' in FractProjectile.h"
#endif
#define ALPHA_FractProjectile_generated_h

#define FID_Alpha_Source_Alpha_Public_Weapons_FractProjectile_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAFractProjectile(); \
	friend struct Z_Construct_UClass_AFractProjectile_Statics; \
public: \
	DECLARE_CLASS(AFractProjectile, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Alpha"), NO_API) \
	DECLARE_SERIALIZER(AFractProjectile)


#define FID_Alpha_Source_Alpha_Public_Weapons_FractProjectile_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	AFractProjectile(AFractProjectile&&); \
	AFractProjectile(const AFractProjectile&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AFractProjectile); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AFractProjectile); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AFractProjectile) \
	NO_API virtual ~AFractProjectile();


#define FID_Alpha_Source_Alpha_Public_Weapons_FractProjectile_h_9_PROLOG
#define FID_Alpha_Source_Alpha_Public_Weapons_FractProjectile_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Alpha_Source_Alpha_Public_Weapons_FractProjectile_h_12_INCLASS_NO_PURE_DECLS \
	FID_Alpha_Source_Alpha_Public_Weapons_FractProjectile_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ALPHA_API UClass* StaticClass<class AFractProjectile>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Alpha_Source_Alpha_Public_Weapons_FractProjectile_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
