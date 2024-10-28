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
	float CurrentStamina;
	UPROPERTY(EditAnywhere, Category="Attributes")
	float MaxStamina;

	UPROPERTY(EditAnywhere, Category="Attributes")
	float CurrentMana;
	UPROPERTY(EditAnywhere, Category="Attributes")
	float MaxMana;

public:
	FORCEINLINE float GetCurrentStamina() const;
	FORCEINLINE float GetCurrentMana() const;
	void UseStamina(const float StaminaAmount);
	void UseMana(const float ManaAmount);
	void ChangeElementType(EFractElementType NewType);
	
};
