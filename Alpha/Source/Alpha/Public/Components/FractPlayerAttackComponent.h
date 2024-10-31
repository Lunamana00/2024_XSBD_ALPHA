// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enums/FractTypes.h"
#include "Components/ActorComponent.h"
#include "FractPlayerAttackComponent.generated.h"

class AFractTestCharacter;
class AFractPlayerWeapon;
class UFractPlayerAttributeComponent;


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ALPHA_API UFractPlayerAttackComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UFractPlayerAttackComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, Category = "Player")
	AFractTestCharacter* Character;

	UPROPERTY(VisibleAnywhere, Category = "Combat")
	EFractAttackRange CurrentRange = EFractAttackRange::Melee;

	UPROPERTY(VisibleAnywhere, Category = "Combat")
	bool bIsFlying = false;


	UPROPERTY(EditDefaultsOnly, Category = "Combat|Attacks")
	TArray<FFractAttack> MeleeAttacks;

	UPROPERTY(EditDefaultsOnly, Category = "Combat|Attacks")
	TArray<FFractAttack> RangedAttacks;

	UPROPERTY(EditDefaultsOnly, Category = "Combat|Skills")
	TArray<FFractSkill> GroundSkills;

	UPROPERTY(EditDefaultsOnly, Category = "Combat|Skills")
	TArray<FFractSkill> AerialSkills;

	UPROPERTY(VisibleDefaultsOnly, Category = "Combat")
	int32 ComboCount = 0;

	UFUNCTION(BlueprintCallable, Category = "Combat")
	void ResetCombo();


	

public:	

	void ToggleRange();
	FFractAttack* GetNormalAttack();
	FFractSkill* GetSkill();
	void UseNormalAttack();
	void UseSkill();
		
};
