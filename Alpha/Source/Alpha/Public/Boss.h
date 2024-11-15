#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "NiagaraSystem.h"  // Niagara �ý��� ��� ���� �߰�
#include "NiagaraFunctionLibrary.h"  // Niagara ���� ��� ȣ��� ��� ����
#include "Boss.generated.h"

UCLASS()
class ALPHA_API ABoss : public AActor
{
    GENERATED_BODY()

public:
    ABoss();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

    // �߻�ü ���� �Լ�
    void SpawnProjectile();

private:
    // �÷��̾� ����
    ACharacter* Player;

    // ȸ�� �ӵ�
    UPROPERTY(EditAnywhere, Category = "Rotation")
    float RotationSpeed = 2.0f;

    // �߻�ü Ŭ����
    UPROPERTY(EditAnywhere, Category = "Projectile")
    TSubclassOf<class ABossProjectile> ProjectileClass;

    // �߻�ü ���� ����
    UPROPERTY(EditAnywhere, Category = "Projectile")
    float SpawnInterval = 0.5f;

    // Boss Ŭ���� ������:
    UPROPERTY(EditAnywhere, Category = "Effects")
    UNiagaraSystem* NiagaraSpawnEffect;  // �߻�ü ���� �� ����� ���̾ư��� ����Ʈ

    // �߻�ü ���� Ÿ�̸�
    FTimerHandle SpawnTimerHandle;
};
