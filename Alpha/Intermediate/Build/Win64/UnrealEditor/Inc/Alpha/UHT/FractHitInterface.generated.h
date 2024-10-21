// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Interfaces/FractHitInterface.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef ALPHA_FractHitInterface_generated_h
#error "FractHitInterface.generated.h already included, missing '#pragma once' in FractHitInterface.h"
#endif
#define ALPHA_FractHitInterface_generated_h

#define FID_Alpha_Source_Alpha_Public_Interfaces_FractHitInterface_h_13_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	ALPHA_API UFractHitInterface(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UFractHitInterface(UFractHitInterface&&); \
	UFractHitInterface(const UFractHitInterface&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(ALPHA_API, UFractHitInterface); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UFractHitInterface); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UFractHitInterface) \
	ALPHA_API virtual ~UFractHitInterface();


#define FID_Alpha_Source_Alpha_Public_Interfaces_FractHitInterface_h_13_GENERATED_UINTERFACE_BODY() \
private: \
	static void StaticRegisterNativesUFractHitInterface(); \
	friend struct Z_Construct_UClass_UFractHitInterface_Statics; \
public: \
	DECLARE_CLASS(UFractHitInterface, UInterface, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Interface), CASTCLASS_None, TEXT("/Script/Alpha"), ALPHA_API) \
	DECLARE_SERIALIZER(UFractHitInterface)


#define FID_Alpha_Source_Alpha_Public_Interfaces_FractHitInterface_h_13_GENERATED_BODY \
	PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	FID_Alpha_Source_Alpha_Public_Interfaces_FractHitInterface_h_13_GENERATED_UINTERFACE_BODY() \
	FID_Alpha_Source_Alpha_Public_Interfaces_FractHitInterface_h_13_ENHANCED_CONSTRUCTORS \
private: \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_Alpha_Source_Alpha_Public_Interfaces_FractHitInterface_h_13_INCLASS_IINTERFACE_NO_PURE_DECLS \
protected: \
	virtual ~IFractHitInterface() {} \
public: \
	typedef UFractHitInterface UClassType; \
	typedef IFractHitInterface ThisClass; \
	virtual UObject* _getUObject() const { return nullptr; }


#define FID_Alpha_Source_Alpha_Public_Interfaces_FractHitInterface_h_10_PROLOG
#define FID_Alpha_Source_Alpha_Public_Interfaces_FractHitInterface_h_21_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Alpha_Source_Alpha_Public_Interfaces_FractHitInterface_h_13_INCLASS_IINTERFACE_NO_PURE_DECLS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ALPHA_API UClass* StaticClass<class UFractHitInterface>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Alpha_Source_Alpha_Public_Interfaces_FractHitInterface_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
