#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "NiagaraComponent.h"
#include "NiagaraSystem.h"
#include "BossProjectile.generated.h"

UCLASS()
class ALPHA_API ABossProjectile : public AActor
{
    GENERATED_BODY()

public:
    ABossProjectile();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

    // 발사체 이동 시작
    void StartMovement(const FVector& Direction, AActor* Target);

    // 충돌 이벤트
    UFUNCTION()
    void OnProjectileHit(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
        UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

private:
    // 충돌 컴포넌트
    UPROPERTY(VisibleAnywhere, Category = "Collision")
    USphereComponent* CollisionComponent;

    // 이동 속도
    UPROPERTY(EditAnywhere, Category = "Movement")
    float Speed = 1000.0f;

    // 유도 회전 속도
    UPROPERTY(EditAnywhere, Category = "Movement")
    float HomingTurnSpeed = 5.0f;

    // 유도 지속 시간
    UPROPERTY(EditAnywhere, Category = "Movement")
    float HomingDuration = 2.0f;

    // 플레이어 충돌 효과
    UPROPERTY(EditAnywhere, Category = "Effects")
    UNiagaraSystem* PlayerImpactEffect;

    // 메시 충돌 효과
    UPROPERTY(EditAnywhere, Category = "Effects")
    UNiagaraSystem* MeshImpactEffect;

    // 트레일 효과
    UPROPERTY(EditAnywhere, Category = "Effects")
    UNiagaraSystem* TrailEffect;

    // 트레일 컴포넌트
    UPROPERTY(VisibleAnywhere, Category = "Effects")
    UNiagaraComponent* TrailEffectComponent;

    // 이동 방향
    FVector MovementDirection;

    // 유도 대상
    AActor* HomingTarget;

    // 유도 여부
    bool bIsHoming;

    // 유도 종료 타이머
    FTimerHandle HomingTimerHandle;
};
