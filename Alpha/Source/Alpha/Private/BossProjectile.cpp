#include "BossProjectile.h"
#include "NiagaraFunctionLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"

ABossProjectile::ABossProjectile()
{
    PrimaryActorTick.bCanEverTick = true;

    // �ݸ��� ������Ʈ ����
    CollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionComponent"));
    CollisionComponent->InitSphereRadius(15.0f);
    CollisionComponent->SetCollisionProfileName(TEXT("Projectile"));
    CollisionComponent->SetNotifyRigidBodyCollision(true);
    CollisionComponent->SetGenerateOverlapEvents(true);
    RootComponent = CollisionComponent;

    // �޽� ������Ʈ ����
    MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
    MeshComponent->SetupAttachment(RootComponent);

    // ����ü �̵� ������Ʈ ����
    ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComponent"));
    ProjectileMovementComponent->SetUpdatedComponent(CollisionComponent);
    ProjectileMovementComponent->InitialSpeed = 400.0f;
    ProjectileMovementComponent->MaxSpeed = 700.0f;
    ProjectileMovementComponent->bRotationFollowsVelocity = true;
    ProjectileMovementComponent->bIsHomingProjectile = true;
    ProjectileMovementComponent->HomingAccelerationMagnitude = 10000.0f;

    // �ʱⰪ ����
    InitialHomingAcceleration = 10000.0f;
    ReductionDuration = 3.0f; // 5�� ���� ����
    ElapsedTime = 0.0f;
}

void ABossProjectile::BeginPlay()
{
    Super::BeginPlay();

    // �߻� ����Ʈ ���
    if (LaunchEffect)
    {
        LaunchEffectComponent = UNiagaraFunctionLibrary::SpawnSystemAtLocation(
            GetWorld(), LaunchEffect, GetActorLocation(), GetActorRotation());

        if (LaunchEffectComponent)
        {
            // �ݸ��� ���� ����
            LaunchEffectComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
        }
    }

    // �߻� ����Ʈ 1�� �� ����
    GetWorldTimerManager().SetTimer(LaunchEffectTimerHandle, this, &ABossProjectile::StopLaunchEffect, 1.0f, false);

    // Ʈ���� ����Ʈ ����
    if (TrailEffect)
    {
        TrailEffectComponent = UNiagaraFunctionLibrary::SpawnSystemAttached(
            TrailEffect, MeshComponent, NAME_None, FVector::ZeroVector, FRotator::ZeroRotator,
            EAttachLocation::KeepRelativeOffset, true);
    }

    // �÷��̾ Ÿ������ ����
    AActor* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
    if (PlayerPawn)
    {
        InitializeProjectile(PlayerPawn);
    }

    // ȣ�� ���� ����
    GetWorldTimerManager().SetTimer(HomingReductionTimerHandle, this, &ABossProjectile::ReduceHoming, 0.1f, true);
}

void ABossProjectile::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void ABossProjectile::InitializeProjectile(AActor* Target)
{
    if (ProjectileMovementComponent && Target)
    {
        USceneComponent* TargetRootComponent = Target->GetRootComponent();
        if (TargetRootComponent)
        {
            ProjectileMovementComponent->HomingTargetComponent = TargetRootComponent;
        }
    }
}

void ABossProjectile::StopLaunchEffect()
{
        // ����Ʈ ��Ȱ��ȭ �� ����
        LaunchEffectComponent->Deactivate();
        LaunchEffectComponent->DestroyComponent();
        LaunchEffectComponent = nullptr;

}


void ABossProjectile::ReduceHoming()
{
    ElapsedTime += 0.1f;

    // ���ο� ȣ�� ���ӵ� ���
    float NewHomingAcceleration = FMath::Lerp(InitialHomingAcceleration, 0.0f, ElapsedTime / ReductionDuration);
    ProjectileMovementComponent->HomingAccelerationMagnitude = FMath::Max(NewHomingAcceleration, 0.0f);

    // ȣ�� ���� �Ϸ� �� Ÿ�̸� ����
    if (ElapsedTime >= ReductionDuration)
    {
        GetWorldTimerManager().ClearTimer(HomingReductionTimerHandle);
    }
}
