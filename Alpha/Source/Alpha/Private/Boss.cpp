#include "Boss.h"
#include "BossProjectile.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h" // ACharacter를 사용하기 위해 추가
#include "Engine/World.h"
#include "NiagaraSystem.h"  // Niagara 시스템 헤더 파일 추가
#include "NiagaraFunctionLibrary.h"  // Niagara 관련 기능 호출용 헤더 파일
#include "TimerManager.h" // 타이머 기능을 사용하기 위한 헤더 추가

ABoss::ABoss()
{
    PrimaryActorTick.bCanEverTick = true;
}

void ABoss::BeginPlay()
{
    Super::BeginPlay();

    // 플레이어 참조
    Player = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);

    // 발사체 생성 타이머 시작
    GetWorld()->GetTimerManager().SetTimer(SpawnTimerHandle, this, &ABoss::SpawnProjectile, SpawnInterval, true);
}

void ABoss::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (Player)
    {
        // 보스와 플레이어 위치 계산
        FVector BossLocation = GetActorLocation();
        FVector PlayerLocation = Player->GetActorLocation();

        // 방향 벡터 계산
        FVector Direction = PlayerLocation - BossLocation;
        Direction.Z = 0; // Z축 무시 (2D 평면 회전)

        if (!Direction.IsNearlyZero())
        {
            // 목표 회전 계산
            FRotator TargetRotation = Direction.Rotation();

            // 부드럽게 회전 보간
            FRotator CurrentRotation = GetActorRotation();
            FRotator NewRotation = FMath::RInterpTo(CurrentRotation, TargetRotation, DeltaTime, RotationSpeed);

            // 회전 적용
            SetActorRotation(NewRotation);
        }
    }
}
void ABoss::SpawnProjectile()
{
    if (ProjectileClass && Player)
    {
        const int32 NumProjectiles = 5; // 생성할 발사체 수
        const float AngleBetweenProjectiles = 30.0f; // 각 발사체 간의 각도 (예: 30도 간격)

        // 보스의 위치와 방향
        FVector BossLocation = GetActorLocation();
        FVector ForwardDirection = GetActorForwardVector(); // 보스가 바라보는 방향
        FVector RightDirection = FVector::CrossProduct(FVector::UpVector, ForwardDirection); // 보스 기준 평면의 X축 방향
        FVector UpDirection = FVector::UpVector; // Z축 방향

        for (int32 i = 0; i < NumProjectiles; i++)
        {
            // 무작위 X, Z 위치 계산
            float RandomXOffset = FMath::RandRange(-200.0f, 200.0f); // 평면 X축 무작위 값
            float RandomZOffset = FMath::RandRange(300.0f, 600.0f); // 평면 Z축 무작위 값

            // 보스 뒤쪽 평면에서 소환 위치 계산
            FVector SpawnLocation = BossLocation
                - ForwardDirection * 300.0f // 보스 뒤쪽 300 거리
                + RightDirection * RandomXOffset // 평면 X 방향 오프셋
                + UpDirection * RandomZOffset; // Z축 방향 오프셋

            // 각도에 따른 발사체 방향 계산
            float OffsetAngle = (i - NumProjectiles / 2) * AngleBetweenProjectiles; // 중앙 기준으로 각도 오프셋
            FVector DirectionToPlayer = Player->GetActorLocation() - SpawnLocation; // 플레이어 방향 벡터
            DirectionToPlayer = FRotator(0, OffsetAngle, 0).RotateVector(DirectionToPlayer).GetSafeNormal();
            FRotator SpawnRotation = DirectionToPlayer.Rotation();

            // 나이아가라 이펙트 생성
            if (NiagaraSpawnEffect)
            {
                UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), NiagaraSpawnEffect, SpawnLocation, FRotator::ZeroRotator);
            }

            // 발사체 생성
            FActorSpawnParameters SpawnParams;
            ABossProjectile* Projectile = GetWorld()->SpawnActor<ABossProjectile>(ProjectileClass, SpawnLocation, SpawnRotation, SpawnParams);

            // 발사체 초기화
            if (Projectile)
            {
                Projectile->StartMovement(DirectionToPlayer, Player);
            }
        }
    }
}
