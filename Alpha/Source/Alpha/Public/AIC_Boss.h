#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "AIC_Boss.generated.h"

// Forward Declaration
class UBlackboardComponent;
class UBehaviorTree;

UCLASS()
class ALPHA_API AAIC_Boss : public AAIController
{
    GENERATED_BODY()

public:
    AAIC_Boss();

    // Behavior Tree Asset
    UPROPERTY(EditDefaultsOnly, Category = "AI")
    UBehaviorTree* BehaviorTreeAsset;

protected:
    virtual void BeginPlay() override;

public:
    // Functions to Set Blackboard Values
    UFUNCTION(BlueprintCallable, Category = "AI")
    void SetBlackboardValueAsVector(FName KeyName, FVector Value);

    UFUNCTION(BlueprintCallable, Category = "AI")
    void SetBlackboardValueAsBool(FName KeyName, bool Value);

    UFUNCTION(BlueprintCallable, Category = "AI")
    void SetBlackboardValueAsInt(FName KeyName, int Value);

    UFUNCTION(BlueprintCallable, Category = "AI")
    void SetBlackboardValueAsObject(FName KeyName, UObject* Value);

private:
    UBlackboardComponent* BlackboardComponent;
};
