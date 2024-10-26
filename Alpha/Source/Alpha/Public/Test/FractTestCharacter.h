// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Alpha/AlphaCharacter.h"
#include "FractTestCharacter.generated.h"

class UFractPlayerAttributeComponent;
/**
 * 
 */
UCLASS()
class ALPHA_API AFractTestCharacter : public AAlphaCharacter
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category = Attributes)
	UFractPlayerAttributeComponent* Attribute;

public:
	UFractPlayerAttributeComponent* GetAttribute() const { return Attribute; }
	
};
