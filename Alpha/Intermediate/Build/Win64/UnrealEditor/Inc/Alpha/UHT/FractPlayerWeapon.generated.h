// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Weapons/FractPlayerWeapon.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
class UPrimitiveComponent;
struct FHitResult;
#ifdef ALPHA_FractPlayerWeapon_generated_h
#error "FractPlayerWeapon.generated.h already included, missing '#pragma once' in FractPlayerWeapon.h"
#endif
#define ALPHA_FractPlayerWeapon_generated_h

#define FID_Alpha_Source_Alpha_Public_Weapons_FractPlayerWeapon_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execOnWeaponBoxEndOverlap); \
	DECLARE_FUNCTION(execOnWeaponBoxOverlap);


#define FID_Alpha_Source_Alpha_Public_Weapons_FractPlayerWeapon_h_17_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAFractPlayerWeapon(); \
	friend struct Z_Construct_UClass_AFractPlayerWeapon_Statics; \
public: \
	DECLARE_CLASS(AFractPlayerWeapon, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Alpha"), NO_API) \
	DECLARE_SERIALIZER(AFractPlayerWeapon)


#define FID_Alpha_Source_Alpha_Public_Weapons_FractPlayerWeapon_h_17_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	AFractPlayerWeapon(AFractPlayerWeapon&&); \
	AFractPlayerWeapon(const AFractPlayerWeapon&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AFractPlayerWeapon); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AFractPlayerWeapon); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AFractPlayerWeapon) \
	NO_API virtual ~AFractPlayerWeapon();


#define FID_Alpha_Source_Alpha_Public_Weapons_FractPlayerWeapon_h_14_PROLOG
#define FID_Alpha_Source_Alpha_Public_Weapons_FractPlayerWeapon_h_17_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Alpha_Source_Alpha_Public_Weapons_FractPlayerWeapon_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Alpha_Source_Alpha_Public_Weapons_FractPlayerWeapon_h_17_INCLASS_NO_PURE_DECLS \
	FID_Alpha_Source_Alpha_Public_Weapons_FractPlayerWeapon_h_17_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ALPHA_API UClass* StaticClass<class AFractPlayerWeapon>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Alpha_Source_Alpha_Public_Weapons_FractPlayerWeapon_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
