// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/FractAttributeComponent.h"
#include "FractPlayerAttributeComponent.generated.h"

class ASeunghwanTestCharacter;
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
	float MaxStamina = 100.f;
	UPROPERTY(EditAnywhere, Category="Attributes")
	float CurrentBoostStamina;
	UPROPERTY(EditAnywhere, Category="Attributes")
	float MaxBoostStamina = 100.f;

	UPROPERTY(EditAnywhere, Category="Attributes")
	float CurrentMana;
	UPROPERTY(EditAnywhere, Category="Attributes")
	float MaxMana;

	UPROPERTY(EditAnywhere, Category="Attributes", meta = (AllowPrivateAccess = true))
	float StaminaRestorePerSecond = 2.5f;

	UPROPERTY(EditAnywhere, Category="Attributes", meta = (AllowPrivateAccess = true))
	float FlightStaminaUsePerSecond = 5.f;

	UPROPERTY()
	ASeunghwanTestCharacter* Character;

public:
	FORCEINLINE float GetCurrentStamina() const;
	FORCEINLINE float GetCurrentMana() const;
	FORCEINLINE float GetCurrentBoostStamina() const { return CurrentBoostStamina; };
	void UseStamina(const float StaminaAmount);
	void UseBoostStamina(const float BoostStaminaAmount);
	void RestoreStamina(const float StaminaAmount);
	void RestoreBoostStamina(const float BoostStaminaAmount);
	void UseMana(const float ManaAmount);
	void ChangeElementType(EFractElementType NewType);
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	float GetCurrentStaminaPercent() const { return CurrentStamina / MaxStamina; }


	
};
