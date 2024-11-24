#include "AIC_Boss.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTree.h"

AAIC_Boss::AAIC_Boss()
{
    // Create the Blackboard Component
    BlackboardComponent = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackboardComponent"));
}

void AAIC_Boss::BeginPlay()
{
    Super::BeginPlay();

    // Ensure the Behavior Tree is Set
    if (BehaviorTreeAsset)
    {
        RunBehaviorTree(BehaviorTreeAsset);

        // Initialize Blackboard
        if (BlackboardComponent && BehaviorTreeAsset->BlackboardAsset)
        {
            BlackboardComponent->InitializeBlackboard(*BehaviorTreeAsset->BlackboardAsset);
        }
    }
}

void AAIC_Boss::SetBlackboardValueAsVector(FName KeyName, FVector Value)
{
    if (BlackboardComponent)
    {
        BlackboardComponent->SetValueAsVector(KeyName, Value);
    }
}

void AAIC_Boss::SetBlackboardValueAsBool(FName KeyName, bool Value)
{
    if (BlackboardComponent)
    {
        BlackboardComponent->SetValueAsBool(KeyName, Value);
    }
}

void AAIC_Boss::SetBlackboardValueAsInt(FName KeyName, int Value)
    {
        if (BlackboardComponent)
        {
            BlackboardComponent->SetValueAsInt(KeyName, Value);
        }
    }

void AAIC_Boss::SetBlackboardValueAsObject(FName KeyName, UObject* Value)
{
    if (BlackboardComponent)
    {
        BlackboardComponent->SetValueAsObject(KeyName, Value);
    }
}