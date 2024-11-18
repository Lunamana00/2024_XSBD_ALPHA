#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Animation/AnimSequence.h"
#include "NiagaraSystem.h"
#include "NiagaraFunctionLibrary.h"
#include "Boss.generated.h"

UCLASS()
class ALPHA_API ABoss : public ACharacter
{
    GENERATED_BODY()

public:
    ABoss();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

    UFUNCTION(BlueprintCallable, Category = "Health")
    void TakeDamage(float DamageAmount);

    void SpawnProjectile();
    void PerformEarthquake();
    void PerformAOE();
    void CheckPhaseTransition();
    void TransitionToPhase(int32 NewPhase);
    void OnPhaseTransitionEnd();
    void HandleDeath();

    // ü�� ���� ��ȯ �Լ�
    UFUNCTION(BlueprintCallable, Category = "Health")
    float GetHealthPercentage() const;

    // ���� �� �ִϸ��̼�
    void ExecutePhasePattern();
    void PlayPatternAnimation();

private:
    ACharacter* Player;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Health", meta = (AllowPrivateAccess = "true"))
    float MaxHP = 100.0f;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Health", meta = (AllowPrivateAccess = "true"))
    float CurrentHP;

    UPROPERTY(EditAnywhere, Category = "Rotation")
    float RotationSpeed = 2.0f;

    UPROPERTY(EditAnywhere, Category = "Projectile")
    TSubclassOf<class ABossProjectile> ProjectileClass;

    UPROPERTY(EditAnywhere, Category = "Projectile")
    float SpawnInterval = 2.0f; // 2�� ���� ����

    UPROPERTY(EditAnywhere, Category = "Effects")
    UNiagaraSystem* NiagaraSpawnEffect;
    UPROPERTY(EditAnywhere, Category = "Effects")
    UNiagaraSystem* EarthquakeEffect;
    UPROPERTY(EditAnywhere, Category = "Effects")
    UNiagaraSystem* AOEEffect;

    UPROPERTY(EditAnywhere, Category = "Damage")
    float EarthquakeDamage = 20.0f;
    UPROPERTY(EditAnywhere, Category = "Damage")
    float AOEDamage = 50.0f;
    UPROPERTY(EditAnywhere, Category = "Damage")
    float EarthquakeRadius = 500.0f;
    UPROPERTY(EditAnywhere, Category = "Damage")
    float AOERadius = 300.0f;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Phase", meta = (AllowPrivateAccess = "true"))
    int32 CurrentPhase = 1;
    bool bIsTransitioning = false;

    UPROPERTY(EditAnywhere, Category = "Phase")
    float Phase2HP = 70.0f;
    UPROPERTY(EditAnywhere, Category = "Phase")
    float Phase3HP = 30.0f;

    // �ִϸ��̼�
    UPROPERTY(EditAnywhere, Category = "Animation")
    UAnimSequence* PhaseTransitionAnimation;
    UPROPERTY(EditAnywhere, Category = "Animation")
    UAnimSequence* PatternAnimation1; // 1������ ���� �ִϸ��̼�
    UPROPERTY(EditAnywhere, Category = "Animation")
    UAnimSequence* PatternAnimation2; // 2������ ���� �ִϸ��̼�
    UPROPERTY(EditAnywhere, Category = "Animation")
    UAnimSequence* PatternAnimation3; // 3������ ���� �ִϸ��̼�

    FTimerHandle PatternExecutionTimerHandle;
    FTimerHandle AnimationTimerHandle;

    UPROPERTY(EditAnywhere, Category = "Phase")
    float TransitionDuration = 3.0f;
};
