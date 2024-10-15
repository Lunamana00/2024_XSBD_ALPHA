// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "AlphaGameMode.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef ALPHA_AlphaGameMode_generated_h
#error "AlphaGameMode.generated.h already included, missing '#pragma once' in AlphaGameMode.h"
#endif
#define ALPHA_AlphaGameMode_generated_h

#define FID_Alpha_Source_Alpha_AlphaGameMode_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAAlphaGameMode(); \
	friend struct Z_Construct_UClass_AAlphaGameMode_Statics; \
public: \
	DECLARE_CLASS(AAlphaGameMode, AGameModeBase, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/Alpha"), ALPHA_API) \
	DECLARE_SERIALIZER(AAlphaGameMode)


#define FID_Alpha_Source_Alpha_AlphaGameMode_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	AAlphaGameMode(AAlphaGameMode&&); \
	AAlphaGameMode(const AAlphaGameMode&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(ALPHA_API, AAlphaGameMode); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AAlphaGameMode); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AAlphaGameMode) \
	ALPHA_API virtual ~AAlphaGameMode();


#define FID_Alpha_Source_Alpha_AlphaGameMode_h_9_PROLOG
#define FID_Alpha_Source_Alpha_AlphaGameMode_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Alpha_Source_Alpha_AlphaGameMode_h_12_INCLASS_NO_PURE_DECLS \
	FID_Alpha_Source_Alpha_AlphaGameMode_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ALPHA_API UClass* StaticClass<class AAlphaGameMode>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Alpha_Source_Alpha_AlphaGameMode_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
