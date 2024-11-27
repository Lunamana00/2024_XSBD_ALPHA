// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enums/FractTypes.h"
#include "Components/ActorComponent.h"
#include "FractPlayerAttackComponent.generated.h"

class UNiagaraSystem;
class UNiagaraComponent;
DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_OneParam(
	FOnUpdatedTargetSignature,
	UFractPlayerAttackComponent, OnUpdatedTargetDelegate,
	AActor*, NewTargetActorRef
);

struct FInputActionValue;
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

	UPROPERTY(VisibleAnywhere, Category = "Combat")
	EFractAttackState AttackState = EFractAttackState::EAS_Unoccupied;

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

	UFUNCTION(BlueprintCallable, Category = "Combat")
	void ResetAttackState();

	UPROPERTY(EditAnywhere)
	TSubclassOf<AFractProjectile> ProjectileClass;

	FVector HitLocation;

	UPROPERTY(EditAnywhere, Category = "Combat")
	float AutoTargetRange = 150.f;

	UPROPERTY(EditAnywhere, Category = "Combat")
	float AutoTargetAngle = 90.f;

	UPROPERTY(VisibleDefaultsOnly, Category = "Combat")
	FVector AttackDirection;
	
	void AddMotionWarpTarget(const AActor* Target) const;

	UPROPERTY()
	ACharacter* CurrentTarget = nullptr;

	ACharacter* FindTarget();
	void RemoveMotionWarpTarget(FName WarpTargetName) const;
	void RotateToInputDirection(float DeltaTime);

	UPROPERTY(EditDefaultsOnly, Category = "Combat")
	bool bHasTarget = false;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Combat")
	bool bCanRotateToInputDirection = false;

	UFUNCTION(BlueprintCallable, Category = "Combat")
	void SpawnProjectile();

	

	bool bIsRangedAttacking = false;
	FVector CachedHitLocation;

	UPROPERTY(EditAnywhere)
	double LockOnBreakDistance = 1500.f;

	UPROPERTY(EditDefaultsOnly, Category = "Combat")
	float AimFOV = 65.f;
	UPROPERTY(EditDefaultsOnly, Category = "Combat")
	float DefaultFOV = 90.f;

	FVector DefaultCameraLocation;

	UFUNCTION(BlueprintCallable)
	void FireGroundSkillEnd();
	UFUNCTION(BlueprintCallable)
	void ActivateFireGroundSkill();
	UFUNCTION(BlueprintCallable)
	void DeactivateFireGroundSkill();
	void ApplyFireGroundSkillDamage();
	FTimerHandle FireGroundSkillDamageTimerHandle;
	
	UPROPERTY(EditDefaultsOnly, Category = "Combat")
	UParticleSystemComponent* FireGroundSkillParticleSystemComponent;

	UPROPERTY(EditDefaultsOnly, Category = "Combat|UI")
	UUserWidget* CrosshairWidget;


	FTimerHandle GroundSkillTimerHandle;
	FTimerHandle AerialSkillTimerHandle;

	UPROPERTY(EditDefaultsOnly, Category = "Combat")
	bool bIsGroundSkillOnCooldown = false;
	UPROPERTY(EditDefaultsOnly, Category = "Combat")
	bool bIsAerialSkillOnCooldown = false;

	UFUNCTION()
	void OnGroundSkillCooldownEnd();
	UFUNCTION()
	void OnAerialSkillCooldownEnd();
	
public:

	UPROPERTY(BlueprintAssignable)
	FOnUpdatedTargetSignature OnUpdatedTargetDelegate;

	void TraceUnderCrosshairs(FHitResult& TraceHitResult);
	void AimDownSight(const FInputActionValue& Value);
	FORCEINLINE FFractAttack* GetNormalAttack();
	FORCEINLINE FFractSkill* GetSkill();
	FORCEINLINE ACharacter* GetCurrentTarget() const { return CurrentTarget; }
	UFUNCTION(BlueprintCallable)
	FORCEINLINE EFractAttackState GetCurrentAttackState() const { return AttackState; }
	UFUNCTION(BlueprintCallable)
	void SetCurrentAttackState(const EFractAttackState& InAttackState) { AttackState = InAttackState; }
	void CancelFireGroundSkill();
	void UseNormalAttack();
	void UseSkill();
	void StartLockOn();
	void EndLockOn();
	void ToggleLockOn();
	UPROPERTY()
	AActor* CurrentLockOnTargetActor;
	UPROPERTY(BlueprintReadOnly, Category = "Combat")
	bool bHasLockOnTarget = false;
	UPROPERTY(BlueprintReadOnly, Category = "Combat")
	bool bIsAiming = false;
	UPROPERTY()
	bool bIsCancellingSkill = false;
	
	float GetCurrentSkillCooldown();
	UPROPERTY()
	UAudioComponent* FireGroundSkillAudioComponent;
	UPROPERTY(EditDefaultsOnly, Category = "Combat")
	USoundBase* FireGroundSkillSound;

	UFUNCTION(BlueprintCallable)
	void PlayFireGroundSkillSound();
	UFUNCTION(BlueprintCallable)
	void StopFireGroundSkillSound();
			
};
