#include "Boss.h"
#include "BossProjectile.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h" // ACharacter�� ����ϱ� ���� �߰�
#include "Engine/World.h"
#include "NiagaraSystem.h"  // Niagara �ý��� ��� ���� �߰�
#include "NiagaraFunctionLibrary.h"  // Niagara ���� ��� ȣ��� ��� ����
#include "TimerManager.h" // Ÿ�̸� ����� ����ϱ� ���� ��� �߰�

ABoss::ABoss()
{
    PrimaryActorTick.bCanEverTick = true;
}

void ABoss::BeginPlay()
{
    Super::BeginPlay();

    // �÷��̾� ����
    Player = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);

    // �߻�ü ���� Ÿ�̸� ����
    GetWorld()->GetTimerManager().SetTimer(SpawnTimerHandle, this, &ABoss::SpawnProjectile, SpawnInterval, true);
}

void ABoss::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (Player)
    {
        // ������ �÷��̾� ��ġ ���
        FVector BossLocation = GetActorLocation();
        FVector PlayerLocation = Player->GetActorLocation();

        // ���� ���� ���
        FVector Direction = PlayerLocation - BossLocation;
        Direction.Z = 0; // Z�� ���� (2D ��� ȸ��)

        if (!Direction.IsNearlyZero())
        {
            // ��ǥ ȸ�� ���
            FRotator TargetRotation = Direction.Rotation();

            // �ε巴�� ȸ�� ����
            FRotator CurrentRotation = GetActorRotation();
            FRotator NewRotation = FMath::RInterpTo(CurrentRotation, TargetRotation, DeltaTime, RotationSpeed);

            // ȸ�� ����
            SetActorRotation(NewRotation);
        }
    }
}
void ABoss::SpawnProjectile()
{
    if (ProjectileClass && Player)
    {
        const int32 NumProjectiles = 5; // ������ �߻�ü ��
        const float AngleBetweenProjectiles = 30.0f; // �� �߻�ü ���� ���� (��: 30�� ����)

        // ������ ��ġ�� ����
        FVector BossLocation = GetActorLocation();
        FVector ForwardDirection = GetActorForwardVector(); // ������ �ٶ󺸴� ����
        FVector RightDirection = FVector::CrossProduct(FVector::UpVector, ForwardDirection); // ���� ���� ����� X�� ����
        FVector UpDirection = FVector::UpVector; // Z�� ����

        for (int32 i = 0; i < NumProjectiles; i++)
        {
            // ������ X, Z ��ġ ���
            float RandomXOffset = FMath::RandRange(-200.0f, 200.0f); // ��� X�� ������ ��
            float RandomZOffset = FMath::RandRange(300.0f, 600.0f); // ��� Z�� ������ ��

            // ���� ���� ��鿡�� ��ȯ ��ġ ���
            FVector SpawnLocation = BossLocation
                - ForwardDirection * 300.0f // ���� ���� 300 �Ÿ�
                + RightDirection * RandomXOffset // ��� X ���� ������
                + UpDirection * RandomZOffset; // Z�� ���� ������

            // ������ ���� �߻�ü ���� ���
            float OffsetAngle = (i - NumProjectiles / 2) * AngleBetweenProjectiles; // �߾� �������� ���� ������
            FVector DirectionToPlayer = Player->GetActorLocation() - SpawnLocation; // �÷��̾� ���� ����
            DirectionToPlayer = FRotator(0, OffsetAngle, 0).RotateVector(DirectionToPlayer).GetSafeNormal();
            FRotator SpawnRotation = DirectionToPlayer.Rotation();

            // ���̾ư��� ����Ʈ ����
            if (NiagaraSpawnEffect)
            {
                UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), NiagaraSpawnEffect, SpawnLocation, FRotator::ZeroRotator);
            }

            // �߻�ü ����
            FActorSpawnParameters SpawnParams;
            ABossProjectile* Projectile = GetWorld()->SpawnActor<ABossProjectile>(ProjectileClass, SpawnLocation, SpawnRotation, SpawnParams);

            // �߻�ü �ʱ�ȭ
            if (Projectile)
            {
                Projectile->StartMovement(DirectionToPlayer, Player);
            }
        }
    }
}
