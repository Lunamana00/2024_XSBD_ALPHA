#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NiagaraSystem.h"
#include "NiagaraComponent.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "BossProjectile.generated.h"

UCLASS(Blueprintable)
class ALPHA_API ABossProjectile : public AActor
{
    GENERATED_BODY()

public:
    ABossProjectile();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

    // 콜리전 컴포넌트
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Collision")
    USphereComponent* CollisionComponent;

    // 메쉬 컴포넌트
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Mesh")
    UStaticMeshComponent* MeshComponent;

    // 투사체 이동 컴포넌트
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Movement")
    UProjectileMovementComponent* ProjectileMovementComponent;

    // 이펙트
    UPROPERTY(EditAnywhere, Category = "Effects")
    UNiagaraSystem* TrailEffect;

    UPROPERTY(EditAnywhere, Category = "Effects")
    UNiagaraSystem* LaunchEffect;

private:
    UNiagaraComponent* TrailEffectComponent;
    UNiagaraComponent* LaunchEffectComponent;

    // 타이머 핸들
    FTimerHandle LaunchEffectTimerHandle;
    FTimerHandle HomingReductionTimerHandle;

    // 호밍 관련 변수
    float InitialHomingAcceleration;
    float ReductionDuration;
    float ElapsedTime;

    // 투사체 초기화
    void InitializeProjectile(AActor* Target);

    // 이펙트 및 호밍 처리 함수
    void StopLaunchEffect();
    void ReduceHoming();
};
