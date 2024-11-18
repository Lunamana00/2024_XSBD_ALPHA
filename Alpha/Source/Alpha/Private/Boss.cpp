#include "Boss.h"
#include "BossProjectile.h"
#include "Kismet/GameplayStatics.h"
#include "NiagaraFunctionLibrary.h"
#include "TimerManager.h"

ABoss::ABoss()
{
    PrimaryActorTick.bCanEverTick = true;
}

void ABoss::BeginPlay()
{
    Super::BeginPlay();

    Player = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
    CurrentHP = MaxHP;

    // 패턴 실행 타이머 시작
    GetWorld()->GetTimerManager().SetTimer(PatternExecutionTimerHandle, this, &ABoss::PlayPatternAnimation, SpawnInterval, true);
}

void ABoss::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (Player)
    {
        FVector Direction = Player->GetActorLocation() - GetActorLocation();
        Direction.Z = 0;

        if (!Direction.IsNearlyZero())
        {
            FRotator TargetRotation = Direction.Rotation();
            FRotator NewRotation = FMath::RInterpTo(GetActorRotation(), TargetRotation, DeltaTime, RotationSpeed);
            SetActorRotation(NewRotation);
        }

        CheckPhaseTransition();
    }
}

void ABoss::CheckPhaseTransition()
{
    if (bIsTransitioning) return;

    if (CurrentHP <= Phase3HP && CurrentPhase < 3)
    {
        TransitionToPhase(3);
    }
    else if (CurrentHP <= Phase2HP && CurrentPhase < 2)
    {
        TransitionToPhase(2);
    }
}

void ABoss::PlayPatternAnimation()
{
    UAnimSequence* CurrentPatternAnimation = nullptr;

    switch (CurrentPhase)
    {
    case 1:
        CurrentPatternAnimation = PatternAnimation1;
        break;
    case 2:
        CurrentPatternAnimation = PatternAnimation2;
        break;
    case 3:
        CurrentPatternAnimation = PatternAnimation3;
        break;
    default:
        break;
    }

    if (CurrentPatternAnimation && GetMesh())
    {
        GetMesh()->PlayAnimation(CurrentPatternAnimation, false);

        float AnimationDuration = CurrentPatternAnimation->GetPlayLength();
        GetWorld()->GetTimerManager().SetTimer(AnimationTimerHandle, this, &ABoss::ExecutePhasePattern, AnimationDuration, false);
    }
    else
    {
        ExecutePhasePattern();
    }
}

void ABoss::ExecutePhasePattern()
{
    switch (CurrentPhase)
    {
    case 1:
        SpawnProjectile();
        break;

    case 2:
        SpawnProjectile();
        if (FMath::FRand() < 0.5f) PerformEarthquake();
        break;

    case 3:
        SpawnProjectile();
        if (FMath::FRand() < 0.4f) PerformEarthquake();
        else if (FMath::FRand() < 0.8f) PerformAOE();
        break;

    default:
        break;
    }
}

void ABoss::TransitionToPhase(int32 NewPhase)
{
    if (bIsTransitioning) return;

    bIsTransitioning = true;
    CurrentPhase = NewPhase;

    if (PhaseTransitionAnimation && GetMesh())
    {
        GetMesh()->PlayAnimation(PhaseTransitionAnimation, false);

        float AnimationDuration = PhaseTransitionAnimation->GetPlayLength();
        GetWorld()->GetTimerManager().SetTimer(AnimationTimerHandle, this, &ABoss::OnPhaseTransitionEnd, AnimationDuration, false);
    }
    else
    {
        OnPhaseTransitionEnd();
    }
}

void ABoss::OnPhaseTransitionEnd()
{
    bIsTransitioning = false;
}

void ABoss::HandleDeath()
{
    UE_LOG(LogTemp, Warning, TEXT("Boss Defeated!"));
    GetWorld()->GetTimerManager().ClearTimer(PatternExecutionTimerHandle);
    Destroy();
}

void ABoss::SpawnProjectile()
{
    if (ProjectileClass && Player)
    {
        FVector BossLocation = GetActorLocation();
        FVector ForwardDirection = GetActorForwardVector();
        FVector SpawnLocation = BossLocation + ForwardDirection * 100.0f;
        FRotator SpawnRotation = ForwardDirection.Rotation();

        FActorSpawnParameters SpawnParams;
        GetWorld()->SpawnActor<ABossProjectile>(ProjectileClass, SpawnLocation, SpawnRotation, SpawnParams);
    }
}

void ABoss::PerformEarthquake()
{
    if (EarthquakeEffect)
    {
        FVector BossLocation = GetActorLocation();
        UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), EarthquakeEffect, BossLocation, FRotator::ZeroRotator);

        TArray<AActor*> IgnoredActors;
        UGameplayStatics::ApplyRadialDamage(GetWorld(), EarthquakeDamage, BossLocation, EarthquakeRadius, nullptr, IgnoredActors, this, GetController(), true);
    }
}

void ABoss::PerformAOE()
{
    if (AOEEffect && Player)
    {
        FVector PlayerLocation = Player->GetActorLocation();
        UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), AOEEffect, PlayerLocation, FRotator::ZeroRotator);

        TArray<AActor*> IgnoredActors;
        UGameplayStatics::ApplyRadialDamage(GetWorld(), AOEDamage, PlayerLocation, AOERadius, nullptr, IgnoredActors, this, GetController(), true);
    }
}

float ABoss::GetHealthPercentage() const
{
    return CurrentHP / MaxHP;
}

void ABoss::TakeDamage(float DamageAmount)
{
    CurrentHP -= DamageAmount;

    if (CurrentHP <= 0)
    {
        CurrentHP = 0;
        HandleDeath();
    }
    else
    {
        CheckPhaseTransition();
    }
}
