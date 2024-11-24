#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "NiagaraSystem.h"
#include "BTT_Phase1Pattern.generated.h"

UCLASS(Blueprintable)
class ALPHA_API UBTT_Phase1Pattern : public UBTTaskNode
{
    GENERATED_BODY()

public:
    UBTT_Phase1Pattern();

protected:
    virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Effects")
    UNiagaraSystem* SpawnEffect;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Effects")
    UNiagaraSystem* FireballEffect;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Effects")
    UNiagaraSystem* TrailEffect;

private:
    void SpawnEffectAtLocation(FVector Location);
    void SpawnFireball(FVector SpawnLocation, AActor* TargetActor);
};
