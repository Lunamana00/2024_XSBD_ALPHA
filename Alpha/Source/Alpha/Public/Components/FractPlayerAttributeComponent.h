// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/FractAttributeComponent.h"
#include "FractPlayerAttributeComponent.generated.h"

/**
 * 
 */
UCLASS()
class ALPHA_API UFractPlayerAttributeComponent : public UFractAttributeComponent
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Attributes")
	float Stamina;
	UPROPERTY(EditAnywhere, Category="Attributes")
	float MaxStamina;

	UPROPERTY(EditAnywhere, Category="Attributes")
	float Mana;
	UPROPERTY(EditAnywhere, Category="Attributes")
	float MaxMana;

public:
	float GetStamina() const;
	float GetMana() const;
	
};
