#include "BossProjectile.h"
#include "Components/SphereComponent.h"
#include "Kismet/GameplayStatics.h"
#include "NiagaraFunctionLibrary.h"
#include "NiagaraComponent.h"
#include "GameFramework/Character.h"

ABossProjectile::ABossProjectile()
{
    PrimaryActorTick.bCanEverTick = true;

    // �浹 ������Ʈ ����
    CollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionComponent"));
    CollisionComponent->InitSphereRadius(15.0f);
    CollisionComponent->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
    CollisionComponent->OnComponentBeginOverlap.AddDynamic(this, &ABossProjectile::OnProjectileHit);
    RootComponent = CollisionComponent;

    // Ʈ���� ����Ʈ ������Ʈ ����
    TrailEffectComponent = CreateDefaultSubobject<UNiagaraComponent>(TEXT("TrailEffectComponent"));
    TrailEffectComponent->SetupAttachment(RootComponent);
}

void ABossProjectile::BeginPlay()
{
    Super::BeginPlay();

    // Ʈ���� ����Ʈ ����
    if (TrailEffect && TrailEffectComponent)
    {
        TrailEffectComponent->SetAsset(TrailEffect);
        TrailEffectComponent->Activate();
    }

    // ���� ���� �ð� ����
    GetWorld()->GetTimerManager().SetTimer(HomingTimerHandle, [this]()
        {
            bIsHoming = false; // ���� ����
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
            // �÷��̾� �浹: A ����Ʈ
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
            // �޽� �浹: B ����Ʈ
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

        // Ʈ���� ����
        if (TrailEffectComponent)
        {
            TrailEffectComponent->DestroyComponent();
        }

        // �߻�ü �ı�
        Destroy();
    }
}
