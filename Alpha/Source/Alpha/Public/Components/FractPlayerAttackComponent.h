// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enums/FractTypes.h"
#include "Components/ActorComponent.h"
#include "FractPlayerAttackComponent.generated.h"

class AFractTestEnemy;
class AFractProjectile;
class ASeunghwanTestCharacter;
class AFractPlayerWeapon;
class UFractPlayerAttributeComponent;


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ALPHA_API UFractPlayerAttackComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UFractPlayerAttackComponent();
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, Category = "Player")
	ASeunghwanTestCharacter* Character;

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

	UPROPERTY(EditAnywhere)
	TSubclassOf<AFractProjectile> ProjectileClass;

	FVector HitLocation;

	UPROPERTY(EditAnywhere, Category = "Combat")
	float AutoTargetRange = 200.f;

	UPROPERTY(EditAnywhere, Category = "Combat")
	float AutoTargetAngle = 90.f;

	UPROPERTY(VisibleDefaultsOnly, Category = "Combat")
	FVector AttackDirection;
	
	void MotionWarpToTarget(const AActor* Target) const;

	UPROPERTY()
	AFractTestEnemy* CurrentTarget = nullptr;

	AFractTestEnemy* FindTarget();
	void RemoveMotionWarpTarget(FName WarpTargetName) const;
	void RotateToInputDirection(float DeltaTime);

	UPROPERTY(EditDefaultsOnly, Category = "Combat")
	bool bHasTarget = false;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Combat")
	bool bCanRotateToInputDirection = false;

public:	

	void TraceUnderCrosshairs(FHitResult& TraceHitResult);
	void SwitchRange();
	FORCEINLINE FFractAttack* GetNormalAttack();
	FORCEINLINE FFractSkill* GetSkill();
	FORCEINLINE AFractTestEnemy* GetCurrentTarget() const { return CurrentTarget; }
	void UseNormalAttack();
	void UseSkill();
	
		
};
