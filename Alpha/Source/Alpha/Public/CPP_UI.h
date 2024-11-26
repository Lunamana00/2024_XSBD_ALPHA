// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Test/SeunghwanTestCharacter.h"
#include "Components/FractAttributeComponent.h"
#include "Components/FractPlayerAttackComponent.h"
#include "Components/FractPlayerAttributeComponent.h"
#include "CPP_UI.generated.h"

/**
**/

class ASeunghwanTestCharacter;

UCLASS()
class ALPHA_API UCPP_UI : public UUserWidget
{
	GENERATED_BODY()

	virtual void NativeConstruct() override;

	UFUNCTION(BlueprintCallable, Category = "UI")
	float GetDodgeCooldownPercent() const;

	UFUNCTION(BlueprintCallable, Category = "UI")
	float GetHealthPercent() const;

	UFUNCTION(BlueprintCallable, Category = "UI")
	float GetStaminaPercent() const;

	UFUNCTION(BlueprintCallable, Category = "UI")
	float GetSkillCooldownPercent() const;

	UPROPERTY()
	ASeunghwanTestCharacter* OwningCharacter;
};
