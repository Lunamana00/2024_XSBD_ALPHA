// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Test/FractTestEnemy.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef ALPHA_FractTestEnemy_generated_h
#error "FractTestEnemy.generated.h already included, missing '#pragma once' in FractTestEnemy.h"
#endif
#define ALPHA_FractTestEnemy_generated_h

#define FID_Alpha_Source_Alpha_Public_Test_FractTestEnemy_h_13_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAFractTestEnemy(); \
	friend struct Z_Construct_UClass_AFractTestEnemy_Statics; \
public: \
	DECLARE_CLASS(AFractTestEnemy, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Alpha"), NO_API) \
	DECLARE_SERIALIZER(AFractTestEnemy) \
	virtual UObject* _getUObject() const override { return const_cast<AFractTestEnemy*>(this); }


#define FID_Alpha_Source_Alpha_Public_Test_FractTestEnemy_h_13_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	AFractTestEnemy(AFractTestEnemy&&); \
	AFractTestEnemy(const AFractTestEnemy&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AFractTestEnemy); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AFractTestEnemy); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AFractTestEnemy) \
	NO_API virtual ~AFractTestEnemy();


#define FID_Alpha_Source_Alpha_Public_Test_FractTestEnemy_h_10_PROLOG
#define FID_Alpha_Source_Alpha_Public_Test_FractTestEnemy_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Alpha_Source_Alpha_Public_Test_FractTestEnemy_h_13_INCLASS_NO_PURE_DECLS \
	FID_Alpha_Source_Alpha_Public_Test_FractTestEnemy_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ALPHA_API UClass* StaticClass<class AFractTestEnemy>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Alpha_Source_Alpha_Public_Test_FractTestEnemy_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
