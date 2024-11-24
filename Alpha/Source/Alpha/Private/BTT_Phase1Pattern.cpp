#include "BTT_Phase1Pattern.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "NiagaraSystem.h"
#include "NiagaraFunctionLibrary.h"
#include "GameFramework/Pawn.h"
#include "Kismet/GameplayStatics.h"
#include "AIController.h"
#include "NiagaraComponent.h"

UBTT_Phase1Pattern::UBTT_Phase1Pattern()
{
    NodeName = TEXT("Phase 1 Pattern");
}

EBTNodeResult::Type UBTT_Phase1Pattern::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    APawn* BossPawn = OwnerComp.GetAIOwner()->GetPawn();
    if (!BossPawn) return EBTNodeResult::Failed;

    FVector BossLocation = BossPawn->GetActorLocation();

    // 랜덤 위치에 이펙트 3개 생성
    for (int i = 0; i < 3; i++)
    {
        FVector Offset = FVector(-200.0f, FMath::RandRange(-100.0f, 100.0f), FMath::RandRange(-100.0f, 100.0f));
        FVector EffectLocation = BossLocation + Offset;

        SpawnEffectAtLocation(EffectLocation);
    }

    // 플레이어 추적 불덩이 생성
    AActor* PlayerActor = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
    if (PlayerActor)
    {
        FVector FireballSpawnLocation = BossLocation + FVector(0, 0, 100);
        SpawnFireball(FireballSpawnLocation, PlayerActor);
    }

    return EBTNodeResult::Succeeded;
}

void UBTT_Phase1Pattern::SpawnEffectAtLocation(FVector Location)
{
    if (SpawnEffect)
    {
        UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), SpawnEffect, Location, FRotator::ZeroRotator);
    }
}

void UBTT_Phase1Pattern::SpawnFireball(FVector SpawnLocation, AActor* TargetActor)
{
    if (FireballEffect)
    {
        UNiagaraComponent* Fireball = UNiagaraFunctionLibrary::SpawnSystemAtLocation(
            GetWorld(),
            FireballEffect,
            SpawnLocation,
            FRotator::ZeroRotator
        );

        if (Fireball && TrailEffect)
        {
            Fireball->SetNiagaraVariableObject("TrailEffect", TrailEffect);
        }

        // 유도 로직 추가
        FTimerHandle TimerHandle;
        GetWorld()->GetTimerManager().SetTimer(TimerHandle, [this, Fireball, TargetActor]()
            {
                FVector CurrentLocation = Fireball->GetComponentLocation();
                FVector Direction = (TargetActor->GetActorLocation() - CurrentLocation).GetSafeNormal();
                FVector NewLocation = CurrentLocation + Direction * 500 * GetWorld()->DeltaTimeSeconds; // 500: Speed
                Fireball->SetWorldLocation(NewLocation);
            }, 0.02f, true, 0.0f);
    }
}
