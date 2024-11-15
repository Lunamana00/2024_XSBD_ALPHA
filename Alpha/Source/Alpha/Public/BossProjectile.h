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

    // �߻�ü �̵� ����
    void StartMovement(const FVector& Direction, AActor* Target);

    // �浹 �̺�Ʈ
    UFUNCTION()
    void OnProjectileHit(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
        UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

private:
    // �浹 ������Ʈ
    UPROPERTY(VisibleAnywhere, Category = "Collision")
    USphereComponent* CollisionComponent;

    // �̵� �ӵ�
    UPROPERTY(EditAnywhere, Category = "Movement")
    float Speed = 1000.0f;

    // ���� ȸ�� �ӵ�
    UPROPERTY(EditAnywhere, Category = "Movement")
    float HomingTurnSpeed = 5.0f;

    // ���� ���� �ð�
    UPROPERTY(EditAnywhere, Category = "Movement")
    float HomingDuration = 2.0f;

    // �÷��̾� �浹 ȿ��
    UPROPERTY(EditAnywhere, Category = "Effects")
    UNiagaraSystem* PlayerImpactEffect;

    // �޽� �浹 ȿ��
    UPROPERTY(EditAnywhere, Category = "Effects")
    UNiagaraSystem* MeshImpactEffect;

    // Ʈ���� ȿ��
    UPROPERTY(EditAnywhere, Category = "Effects")
    UNiagaraSystem* TrailEffect;

    // Ʈ���� ������Ʈ
    UPROPERTY(VisibleAnywhere, Category = "Effects")
    UNiagaraComponent* TrailEffectComponent;

    // �̵� ����
    FVector MovementDirection;

    // ���� ���
    AActor* HomingTarget;

    // ���� ����
    bool bIsHoming;

    // ���� ���� Ÿ�̸�
    FTimerHandle HomingTimerHandle;
};
