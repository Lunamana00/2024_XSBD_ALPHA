#include "BossProjectile.h"
#include "NiagaraFunctionLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"

ABossProjectile::ABossProjectile()
{
    PrimaryActorTick.bCanEverTick = true;

    // 콜리전 컴포넌트 설정
    CollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionComponent"));
    CollisionComponent->InitSphereRadius(15.0f);
    CollisionComponent->SetCollisionProfileName(TEXT("Projectile"));
    CollisionComponent->SetNotifyRigidBodyCollision(true);
    CollisionComponent->SetGenerateOverlapEvents(true);
    RootComponent = CollisionComponent;

    // 메쉬 컴포넌트 설정
    MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
    MeshComponent->SetupAttachment(RootComponent);

    // 투사체 이동 컴포넌트 설정
    ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComponent"));
    ProjectileMovementComponent->SetUpdatedComponent(CollisionComponent);
    ProjectileMovementComponent->InitialSpeed = 400.0f;
    ProjectileMovementComponent->MaxSpeed = 700.0f;
    ProjectileMovementComponent->bRotationFollowsVelocity = true;
    ProjectileMovementComponent->bIsHomingProjectile = true;
    ProjectileMovementComponent->HomingAccelerationMagnitude = 10000.0f;

    // 초기값 설정
    InitialHomingAcceleration = 10000.0f;
    ReductionDuration = 3.0f; // 5초 동안 감소
    ElapsedTime = 0.0f;
}

void ABossProjectile::BeginPlay()
{
    Super::BeginPlay();

    // 발사 이펙트 재생
    if (LaunchEffect)
    {
        LaunchEffectComponent = UNiagaraFunctionLibrary::SpawnSystemAtLocation(
            GetWorld(), LaunchEffect, GetActorLocation(), GetActorRotation());

        if (LaunchEffectComponent)
        {
            // 콜리전 무시 설정
            LaunchEffectComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
        }
    }

    // 발사 이펙트 1초 후 꺼짐
    GetWorldTimerManager().SetTimer(LaunchEffectTimerHandle, this, &ABossProjectile::StopLaunchEffect, 1.0f, false);

    // 트레일 이펙트 생성
    if (TrailEffect)
    {
        TrailEffectComponent = UNiagaraFunctionLibrary::SpawnSystemAttached(
            TrailEffect, MeshComponent, NAME_None, FVector::ZeroVector, FRotator::ZeroRotator,
            EAttachLocation::KeepRelativeOffset, true);
    }

    // 플레이어를 타겟으로 설정
    AActor* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
    if (PlayerPawn)
    {
        InitializeProjectile(PlayerPawn);
    }

    // 호밍 감소 시작
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
        // 이펙트 비활성화 및 제거
        LaunchEffectComponent->Deactivate();
        LaunchEffectComponent->DestroyComponent();
        LaunchEffectComponent = nullptr;

}


void ABossProjectile::ReduceHoming()
{
    ElapsedTime += 0.1f;

    // 새로운 호밍 가속도 계산
    float NewHomingAcceleration = FMath::Lerp(InitialHomingAcceleration, 0.0f, ElapsedTime / ReductionDuration);
    ProjectileMovementComponent->HomingAccelerationMagnitude = FMath::Max(NewHomingAcceleration, 0.0f);

    // 호밍 감소 완료 후 타이머 정지
    if (ElapsedTime >= ReductionDuration)
    {
        GetWorldTimerManager().ClearTimer(HomingReductionTimerHandle);
    }
}
