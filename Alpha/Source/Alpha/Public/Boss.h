#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Animation/AnimSequence.h"
#include "NiagaraSystem.h"
#include "NiagaraFunctionLibrary.h"
#include "Boss.generated.h"

UENUM(BlueprintType)
enum class EBossPattern : uint8
{
    Projectile UMETA(DisplayName = "Projectile"),
    Earthquake UMETA(DisplayName = "Earthquake"),
    AOE UMETA(DisplayName = "AOE")
};

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
    void PerformEarthquakeStep();
    void PerformAOE();
    void ExecuteAOE();
    void HandleDeath();

    // 체력 비율 반환 함수
    UFUNCTION(BlueprintCallable, Category = "Health")
    float GetHealthPercentage() const;

    // 패턴 및 애니메이션
    void ExecutePattern(EBossPattern Pattern);
    void PlayPatternAnimation();

    // 페이즈 관리 함수
    void CheckPhaseTransition();
    void TransitionToPhase(int32 NewPhase);
    void OnPhaseTransitionEnd();

private:
    ACharacter* Player;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Health", meta = (AllowPrivateAccess = "true"))
    float MaxHP = 100.0f;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Health", meta = (AllowPrivateAccess = "true"))
    float CurrentHP;

    UPROPERTY(EditAnywhere, Category = "Rotation")
    float RotationSpeed = 2.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Projectile", meta = (AllowPrivateAccess = "true"))
    TSubclassOf<class ABossProjectile> ProjectileClass;

    UPROPERTY(EditAnywhere, Category = "Projectile")
    float SpawnInterval = 2.0f; // 2초 간격 실행

    UPROPERTY(EditAnywhere, Category = "Projectile")
    float HomingAcceleration = 3000.0f;

    UPROPERTY(EditAnywhere, Category = "Effects")
    UNiagaraSystem* NiagaraSpawnEffect;

    UPROPERTY(EditAnywhere, Category = "Effects")
    UNiagaraSystem* EarthquakeEffect;

    UPROPERTY(EditAnywhere, Category = "Effects")
    UNiagaraSystem* AOEEffect;

    UPROPERTY(EditAnywhere, Category = "Effects")
    UNiagaraSystem* AOEWarningEffect;

    UPROPERTY(EditAnywhere, Category = "Damage")
    float EarthquakeDamage = 20.0f;

    UPROPERTY(EditAnywhere, Category = "Damage")
    float AOEDamage = 50.0f;

    UPROPERTY(EditAnywhere, Category = "Damage")
    float EarthquakeRadius = 200.0f;

    UPROPERTY(EditAnywhere, Category = "Damage")
    float AOERadius = 300.0f;

    // Earthquake 설정
    UPROPERTY(EditAnywhere, Category = "Earthquake")
    int32 EarthquakeSteps = 5;

    UPROPERTY(EditAnywhere, Category = "Earthquake")
    float EarthquakeStepInterval = 0.5f;

    UPROPERTY(EditAnywhere, Category = "Earthquake")
    float EarthquakeStepDistance = 200.0f;

    int32 CurrentEarthquakeStep;
    FTimerHandle EarthquakeTimerHandle;

    // AOE 설정
    UPROPERTY(EditAnywhere, Category = "AOE")
    float AOEDelay = 1.0f;

    FTimerHandle AOETimerHandle;

    // 페이즈 관련 변수
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Phase", meta = (AllowPrivateAccess = "true"))
    int32 CurrentPhase = 1;
    bool bIsTransitioning = false;

    UPROPERTY(EditAnywhere, Category = "Phase")
    float Phase2HP = 70.0f;

    UPROPERTY(EditAnywhere, Category = "Phase")
    float Phase3HP = 40.0f;

    // 애니메이션
    UPROPERTY(EditAnywhere, Category = "Animation")
    UAnimSequence* PhaseTransitionAnimation;

    UPROPERTY(EditAnywhere, Category = "Animation")
    UAnimSequence* ProjectilePatternAnimation;

    UPROPERTY(EditAnywhere, Category = "Animation")
    UAnimSequence* EarthquakePatternAnimation;

    UPROPERTY(EditAnywhere, Category = "Animation")
    UAnimSequence* AOEPatternAnimation;

    FTimerHandle PatternExecutionTimerHandle;
    FTimerHandle AnimationTimerHandle;
};
