#pragma once

#include "CoreMinimal.h"
#include "AIController.h"

#include "AIC_Enemy_1.generated.h"


UCLASS()
class ALPHA_API AAIC_Enemy_1 : public AAIController
{
	GENERATED_BODY()
public:
	virtual void Tick(float DeltaSecondes) override;

protected:
	virtual void BeginPlay() override;

private:
	class UBehaviorTree* AIBehavior;

};
