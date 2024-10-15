// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Enums/FractElementType.h"
#include "Templates/IsUEnumClass.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ReflectedTypeAccessors.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef ALPHA_FractElementType_generated_h
#error "FractElementType.generated.h already included, missing '#pragma once' in FractElementType.h"
#endif
#define ALPHA_FractElementType_generated_h

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Alpha_Source_Alpha_Public_Enums_FractElementType_h


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

PRAGMA_ENABLE_DEPRECATION_WARNINGS
