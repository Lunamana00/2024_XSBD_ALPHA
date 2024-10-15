// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType)
enum class EFractElementType : uint8
{
	None UMETA(DisplayName = "None"),
	Fire UMETA(DisplayName = "Fire"),
	Water UMETA(DisplayName = "Water"),
	Earth UMETA(DisplayName = "Earth"),
	Wind UMETA(DisplayName = "Wind"),
	Player UMETA(DisplayName = "Player")
	
};
