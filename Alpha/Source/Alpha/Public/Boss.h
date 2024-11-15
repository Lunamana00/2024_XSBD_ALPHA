#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "NiagaraSystem.h"  // Niagara 시스템 헤더 파일 추가
#include "NiagaraFunctionLibrary.h"  // Niagara 관련 기능 호출용 헤더 파일
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

    // 발사체 생성 함수
    void SpawnProjectile();

private:
    // 플레이어 참조
    ACharacter* Player;

    // 회전 속도
    UPROPERTY(EditAnywhere, Category = "Rotation")
    float RotationSpeed = 2.0f;

    // 발사체 클래스
    UPROPERTY(EditAnywhere, Category = "Projectile")
    TSubclassOf<class ABossProjectile> ProjectileClass;

    // 발사체 생성 간격
    UPROPERTY(EditAnywhere, Category = "Projectile")
    float SpawnInterval = 0.5f;

    // Boss 클래스 내에서:
    UPROPERTY(EditAnywhere, Category = "Effects")
    UNiagaraSystem* NiagaraSpawnEffect;  // 발사체 생성 시 사용할 나이아가라 이펙트

    // 발사체 생성 타이머
    FTimerHandle SpawnTimerHandle;
};
