// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Enums/FractTypes.h"
#include "FractAttributeComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ALPHA_API UFractAttributeComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UFractAttributeComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	// Health is current health
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Attributes")
	float CurrentHealth;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Attributes")
	float MaxHealth;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Attributes")
	float AttackDamage;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Attributes")
	EFractElementType ElementType;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void ReceiveDamage(const float DamageAmount);
	void HealHealth(const float HealAmount);
	FORCEINLINE float GetCurrentHealth() const;
	FORCEINLINE float GetAttackDamage() const;
	FORCEINLINE EFractElementType GetElementType() const;
	bool IsAlive() const;
	
		
};
