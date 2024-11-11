// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Test/FractTestCharacter.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AFractPlayerWeapon;
#ifdef ALPHA_FractTestCharacter_generated_h
#error "FractTestCharacter.generated.h already included, missing '#pragma once' in FractTestCharacter.h"
#endif
#define ALPHA_FractTestCharacter_generated_h

#define FID_Alpha_Source_Alpha_Public_Test_FractTestCharacter_h_20_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execSetAllowPhysicsRotationDuringAnimRootMotion); \
	DECLARE_FUNCTION(execSwitchWeaponSocket); \
	DECLARE_FUNCTION(execSetWeaponCollisionEnabled); \
	DECLARE_FUNCTION(execGetWeapon);


#define FID_Alpha_Source_Alpha_Public_Test_FractTestCharacter_h_20_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAFractTestCharacter(); \
	friend struct Z_Construct_UClass_AFractTestCharacter_Statics; \
public: \
	DECLARE_CLASS(AFractTestCharacter, AAlphaCharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Alpha"), NO_API) \
	DECLARE_SERIALIZER(AFractTestCharacter)


#define FID_Alpha_Source_Alpha_Public_Test_FractTestCharacter_h_20_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	AFractTestCharacter(AFractTestCharacter&&); \
	AFractTestCharacter(const AFractTestCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AFractTestCharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AFractTestCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AFractTestCharacter) \
	NO_API virtual ~AFractTestCharacter();


#define FID_Alpha_Source_Alpha_Public_Test_FractTestCharacter_h_17_PROLOG
#define FID_Alpha_Source_Alpha_Public_Test_FractTestCharacter_h_20_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Alpha_Source_Alpha_Public_Test_FractTestCharacter_h_20_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Alpha_Source_Alpha_Public_Test_FractTestCharacter_h_20_INCLASS_NO_PURE_DECLS \
	FID_Alpha_Source_Alpha_Public_Test_FractTestCharacter_h_20_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ALPHA_API UClass* StaticClass<class AFractTestCharacter>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Alpha_Source_Alpha_Public_Test_FractTestCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
