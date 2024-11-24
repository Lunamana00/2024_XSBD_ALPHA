#include "Boss.h"
#include "BossProjectile.h"
#include "Kismet/GameplayStatics.h"
#include "NiagaraFunctionLibrary.h"
#include "TimerManager.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/CapsuleComponent.h"

ABoss::ABoss()
{
    PrimaryActorTick.bCanEverTick = true;
}

void ABoss::BeginPlay()
{
    Super::BeginPlay();

    Player = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
    CurrentHP = MaxHP;
    CurrentPhase = 1;

    UE_LOG(LogTemp, Warning, TEXT("Boss BeginPlay: CurrentPhase = %d"), CurrentPhase);

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
    if (bIsTransitioning)
    {
        UE_LOG(LogTemp, Warning, TEXT("Currently transitioning, skipping CheckPhaseTransition"));
        return;
    }

    if (CurrentHP <= Phase3HP && CurrentPhase < 3)
    {
        UE_LOG(LogTemp, Warning, TEXT("Transitioning to Phase 3"));
        TransitionToPhase(3);
    }
    else if (CurrentHP <= Phase2HP && CurrentPhase < 2)
    {
        UE_LOG(LogTemp, Warning, TEXT("Transitioning to Phase 2"));
        TransitionToPhase(2);
    }
}

void ABoss::TransitionToPhase(int32 NewPhase)
{
    if (bIsTransitioning)
    {
        UE_LOG(LogTemp, Warning, TEXT("Already transitioning, skipping TransitionToPhase"));
        return;
    }

    bIsTransitioning = true;
    CurrentPhase = NewPhase;

    UE_LOG(LogTemp, Warning, TEXT("Transitioning to new phase: %d"), NewPhase);

    // 페이즈 전환 애니메이션 재생
    if (PhaseTransitionAnimation && GetMesh())
    {
        UE_LOG(LogTemp, Warning, TEXT("Playing phase transition animation"));
        GetMesh()->PlayAnimation(PhaseTransitionAnimation, false);

        float AnimationDuration = PhaseTransitionAnimation->GetPlayLength();
        GetWorld()->GetTimerManager().SetTimer(AnimationTimerHandle, this, &ABoss::OnPhaseTransitionEnd, AnimationDuration, false);
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("No phase transition animation, ending transition immediately"));
        OnPhaseTransitionEnd();
    }
}

void ABoss::OnPhaseTransitionEnd()
{
    bIsTransitioning = false;
    UE_LOG(LogTemp, Warning, TEXT("Phase transition ended"));
}

void ABoss::PlayPatternAnimation()
{
    if (bIsTransitioning)
    {
        UE_LOG(LogTemp, Warning, TEXT("Boss is transitioning, skipping PlayPatternAnimation"));
        return;
    }

    TArray<EBossPattern> AvailablePatterns;

    switch (CurrentPhase)
    {
    case 1:
        AvailablePatterns.Add(EBossPattern::Projectile);
        break;
    case 2:
        AvailablePatterns.Add(EBossPattern::Projectile);
        AvailablePatterns.Add(EBossPattern::Earthquake);
        break;
    case 3:
        AvailablePatterns.Add(EBossPattern::Projectile);
        AvailablePatterns.Add(EBossPattern::Earthquake);
        AvailablePatterns.Add(EBossPattern::AOE);
        break;
    default:
        break;
    }

    // 랜덤으로 패턴 선택
    if (AvailablePatterns.Num() > 0)
    {
        int32 RandomIndex = FMath::RandRange(0, AvailablePatterns.Num() - 1);
        EBossPattern SelectedPattern = AvailablePatterns[RandomIndex];

        UE_LOG(LogTemp, Warning, TEXT("Selected Pattern: %d"), (int32)SelectedPattern);

        // 선택된 패턴의 애니메이션 재생
        UAnimSequence* CurrentPatternAnimation = nullptr;
        switch (SelectedPattern)
        {
        case EBossPattern::Projectile:
            CurrentPatternAnimation = ProjectilePatternAnimation;
            break;
        case EBossPattern::Earthquake:
            CurrentPatternAnimation = EarthquakePatternAnimation;
            break;
        case EBossPattern::AOE:
            CurrentPatternAnimation = AOEPatternAnimation;
            break;
        default:
            break;
        }

        if (CurrentPatternAnimation && GetMesh())
        {
            UE_LOG(LogTemp, Warning, TEXT("Playing pattern animation"));
            GetMesh()->PlayAnimation(CurrentPatternAnimation, false);

            float AnimationDuration = CurrentPatternAnimation->GetPlayLength();
            UE_LOG(LogTemp, Warning, TEXT("Playing pattern animation"));
            GetWorld()->GetTimerManager().SetTimer(AnimationTimerHandle, [this, SelectedPattern]()
                {
                    UE_LOG(LogTemp, Warning, TEXT("Animation finished, executing pattern"));
                    ExecutePattern(SelectedPattern);
                }, AnimationDuration, false);
        }
        else
        {
            UE_LOG(LogTemp, Warning, TEXT("No animation or mesh, executing pattern immediately"));
            ExecutePattern(SelectedPattern);
        }
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("No available patterns to select"));
    }
}

void ABoss::ExecutePattern(EBossPattern Pattern)
{
    UE_LOG(LogTemp, Warning, TEXT("Executing Pattern: %d"), (int32)Pattern);
    switch (Pattern)
    {
    case EBossPattern::Projectile:
        SpawnProjectile();
        break;

    case EBossPattern::Earthquake:
        PerformEarthquake();
        break;

    case EBossPattern::AOE:
        PerformAOE();
        break;

    default:
        break;
    }
}

void ABoss::HandleDeath()
{
    UE_LOG(LogTemp, Warning, TEXT("Boss Defeated!"));
    GetWorld()->GetTimerManager().ClearTimer(PatternExecutionTimerHandle);
    Destroy();
}

void ABoss::SpawnProjectile()
{



    UE_LOG(LogTemp, Warning, TEXT("Spawning projectile"));
    if (!ProjectileClass)
    {
        UE_LOG(LogTemp, Error, TEXT("ProjectileClass is null"));
        return;
    }
    if (!Player)
    {
        UE_LOG(LogTemp, Error, TEXT("Player is null"));
        return;
    }
    if (ProjectileClass && Player)
    {
        FVector BossLocation = GetActorLocation();
        FVector BackwardDirection = -GetActorForwardVector();
        FVector SpawnLocation = BossLocation + BackwardDirection * 100.0f; // 보스 뒤쪽
        FRotator SpawnRotation = BackwardDirection.Rotation();

        if (NiagaraSpawnEffect)
        {
            UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), NiagaraSpawnEffect, SpawnLocation, SpawnRotation);
        }

        FActorSpawnParameters SpawnParams;
        ABossProjectile* Projectile = GetWorld()->SpawnActor<ABossProjectile>(ProjectileClass, SpawnLocation, SpawnRotation, SpawnParams);

        if (Projectile)
        {
            UE_LOG(LogTemp, Warning, TEXT("Projectile spawned, starting movement"));
            // 초기 이동 시작
        }
        else
        {
            UE_LOG(LogTemp, Error, TEXT("Failed to spawn projectile"));
        }
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("Cannot spawn projectile: ProjectileClass or Player is null"));
    }
}

void ABoss::PerformEarthquake()
{
    UE_LOG(LogTemp, Warning, TEXT("Performing earthquake"));
    CurrentEarthquakeStep = 0;
    GetWorld()->GetTimerManager().SetTimer(EarthquakeTimerHandle, this, &ABoss::PerformEarthquakeStep, EarthquakeStepInterval, true);
}

void ABoss::PerformEarthquakeStep()
{
    UE_LOG(LogTemp, Warning, TEXT("Earthquake step %d"), CurrentEarthquakeStep);
    if (CurrentEarthquakeStep >= EarthquakeSteps)
    {
        UE_LOG(LogTemp, Warning, TEXT("Earthquake finished"));
        GetWorld()->GetTimerManager().ClearTimer(EarthquakeTimerHandle);
        return;
    }

    FVector BossLocation = GetActorLocation();
    FVector ForwardDirection = GetActorForwardVector();
    FVector EffectLocation = BossLocation + ForwardDirection * EarthquakeStepDistance * (CurrentEarthquakeStep + 1);

    // 나이아가라 이펙트 생성
    if (EarthquakeEffect)
    {
        UE_LOG(LogTemp, Warning, TEXT("Spawning earthquake effect at location %s"), *EffectLocation.ToString());
        UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), EarthquakeEffect, EffectLocation, FRotator::ZeroRotator);
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("EarthquakeEffect is null"));
    }

    // 플레이어에게 데미지 적용
    if (Player)
    {
        float Distance = FVector::Dist(EffectLocation, Player->GetActorLocation());
        if (Distance <= EarthquakeRadius)
        {
            UGameplayStatics::ApplyDamage(Player, EarthquakeDamage, GetController(), this, nullptr);
            UE_LOG(LogTemp, Warning, TEXT("Applied earthquake damage to player"));
        }
    }

    CurrentEarthquakeStep++;
}

void ABoss::PerformAOE()
{
    UE_LOG(LogTemp, Warning, TEXT("Performing AOE"));
    FVector BossLocation = GetActorLocation();

    // 경고 이펙트 생성
    if (AOEWarningEffect)
    {
        UE_LOG(LogTemp, Warning, TEXT("Spawning AOE warning effect"));
        UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), AOEWarningEffect, BossLocation, FRotator::ZeroRotator);
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("AOEWarningEffect is null"));
    }

    // 딜레이 후 실제 공격 실행
    GetWorld()->GetTimerManager().SetTimer(AOETimerHandle, this, &ABoss::ExecuteAOE, AOEDelay, false);
}

void ABoss::ExecuteAOE()
{
    UE_LOG(LogTemp, Warning, TEXT("Executing AOE attack"));
    FVector BossLocation = GetActorLocation();

    // 실제 AOE 이펙트 생성
    if (AOEEffect)
    {
        UE_LOG(LogTemp, Warning, TEXT("Spawning AOE effect"));
        UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), AOEEffect, BossLocation, FRotator::ZeroRotator);
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("AOEEffect is null"));
    }

    // 플레이어에게 데미지 적용
    if (Player)
    {
        float Distance = FVector::Dist(BossLocation, Player->GetActorLocation());
        if (Distance <= AOERadius)
        {
            UGameplayStatics::ApplyDamage(Player, AOEDamage, GetController(), this, nullptr);
            UE_LOG(LogTemp, Warning, TEXT("Applied AOE damage to player"));
        }
    }
}

float ABoss::GetHealthPercentage() const
{
    return CurrentHP / MaxHP;
}

void ABoss::TakeDamage(float DamageAmount)
{
    CurrentHP -= DamageAmount;

    UE_LOG(LogTemp, Warning, TEXT("Boss took damage: CurrentHP = %f"), CurrentHP);

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
