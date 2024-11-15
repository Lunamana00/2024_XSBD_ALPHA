#include "BossProjectile.h"
#include "Components/SphereComponent.h"
#include "Kismet/GameplayStatics.h"
#include "NiagaraFunctionLibrary.h"
#include "NiagaraComponent.h"
#include "GameFramework/Character.h"

ABossProjectile::ABossProjectile()
{
    PrimaryActorTick.bCanEverTick = true;

    // 충돌 컴포넌트 생성
    CollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionComponent"));
    CollisionComponent->InitSphereRadius(15.0f);
    CollisionComponent->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
    CollisionComponent->OnComponentBeginOverlap.AddDynamic(this, &ABossProjectile::OnProjectileHit);
    RootComponent = CollisionComponent;

    // 트레일 이펙트 컴포넌트 생성
    TrailEffectComponent = CreateDefaultSubobject<UNiagaraComponent>(TEXT("TrailEffectComponent"));
    TrailEffectComponent->SetupAttachment(RootComponent);
}

void ABossProjectile::BeginPlay()
{
    Super::BeginPlay();

    // 트레일 이펙트 시작
    if (TrailEffect && TrailEffectComponent)
    {
        TrailEffectComponent->SetAsset(TrailEffect);
        TrailEffectComponent->Activate();
    }

    // 유도 지속 시간 설정
    GetWorld()->GetTimerManager().SetTimer(HomingTimerHandle, [this]()
        {
            bIsHoming = false; // 유도 종료
        }, HomingDuration, false);
}

void ABossProjectile::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (bIsHoming && HomingTarget)
    {
        FVector TargetDirection = (HomingTarget->GetActorLocation() - GetActorLocation()).GetSafeNormal();
        MovementDirection = FMath::VInterpTo(MovementDirection, TargetDirection, DeltaTime, HomingTurnSpeed);
    }

    if (!MovementDirection.IsZero())
    {
        FVector NewLocation = GetActorLocation() + MovementDirection * Speed * DeltaTime;
        SetActorLocation(NewLocation);
        SetActorRotation(MovementDirection.Rotation());
    }
}

void ABossProjectile::StartMovement(const FVector& Direction, AActor* Target)
{
    MovementDirection = Direction.GetSafeNormal();
    HomingTarget = Target;
}

void ABossProjectile::OnProjectileHit(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
    UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    if (OtherActor && OtherActor != this && OtherComp)
    {
        if (OtherActor->IsA(ACharacter::StaticClass()))
        {
            // 플레이어 충돌: A 이펙트
            if (PlayerImpactEffect)
            {
                UNiagaraFunctionLibrary::SpawnSystemAtLocation(
                    GetWorld(),
                    PlayerImpactEffect,
                    GetActorLocation(),
                    FRotator::ZeroRotator
                );
            }
        }
        else if (OtherComp->IsA(UStaticMeshComponent::StaticClass()) || OtherComp->IsA(USkeletalMeshComponent::StaticClass()))
        {
            // 메시 충돌: B 이펙트
            if (MeshImpactEffect)
            {
                UNiagaraFunctionLibrary::SpawnSystemAtLocation(
                    GetWorld(),
                    MeshImpactEffect,
                    GetActorLocation(),
                    FRotator::ZeroRotator
                );
            }
        }

        // 트레일 제거
        if (TrailEffectComponent)
        {
            TrailEffectComponent->DestroyComponent();
        }

        // 발사체 파괴
        Destroy();
    }
}
