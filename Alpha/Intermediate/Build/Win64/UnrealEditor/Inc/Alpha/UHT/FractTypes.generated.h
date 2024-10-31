// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Enums/FractTypes.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef ALPHA_FractTypes_generated_h
#error "FractTypes.generated.h already included, missing '#pragma once' in FractTypes.h"
#endif
#define ALPHA_FractTypes_generated_h

#define FID_Alpha_Source_Alpha_Public_Enums_FractTypes_h_55_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FFractAttack_Statics; \
	ALPHA_API static class UScriptStruct* StaticStruct();


template<> ALPHA_API UScriptStruct* StaticStruct<struct FFractAttack>();

#define FID_Alpha_Source_Alpha_Public_Enums_FractTypes_h_82_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FFractSkill_Statics; \
	ALPHA_API static class UScriptStruct* StaticStruct();


template<> ALPHA_API UScriptStruct* StaticStruct<struct FFractSkill>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Alpha_Source_Alpha_Public_Enums_FractTypes_h


#define FOREACH_ENUM_EFRACTELEMENTTYPE(op) \
	op(EFractElementType::None) \
	op(EFractElementType::Fire) \
	op(EFractElementType::Water) \
	op(EFractElementType::Earth) \
	op(EFractElementType::Wind) \
	op(EFractElementType::Player) 

enum class EFractElementType : uint8;
template<> struct TIsUEnumClass<EFractElementType> { enum { Value = true }; };
template<> ALPHA_API UEnum* StaticEnum<EFractElementType>();

#define FOREACH_ENUM_EFRACTATTACKRANGE(op) \
	op(EFractAttackRange::Melee) \
	op(EFractAttackRange::Ranged) 

enum class EFractAttackRange : uint8;
template<> struct TIsUEnumClass<EFractAttackRange> { enum { Value = true }; };
template<> ALPHA_API UEnum* StaticEnum<EFractAttackRange>();

#define FOREACH_ENUM_EFRACTATTACKTYPE(op) \
	op(EFractAttackType::Normal) \
	op(EFractAttackType::Skill) 

enum class EFractAttackType : uint8;
template<> struct TIsUEnumClass<EFractAttackType> { enum { Value = true }; };
template<> ALPHA_API UEnum* StaticEnum<EFractAttackType>();

#define FOREACH_ENUM_EFRACTCHARACTERSTATE(op) \
	op(EFractCharacterState::ECS_Idle) \
	op(EFractCharacterState::ECS_Attacking) \
	op(EFractCharacterState::ECS_Dodging) \
	op(EFractCharacterState::ECS_Hit) \
	op(EFractCharacterState::ECS_UsingSkill) 

enum class EFractCharacterState : uint8;
template<> struct TIsUEnumClass<EFractCharacterState> { enum { Value = true }; };
template<> ALPHA_API UEnum* StaticEnum<EFractCharacterState>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
