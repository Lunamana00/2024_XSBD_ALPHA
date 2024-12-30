#pragma once

#include "CoreMinimal.h"
#include "Enemy.h"
#include "Fire_Slime.generated.h"

/*
Enemy_class 기반
불 지역 근접 Slime Class
 */

UCLASS()
class ALPHA_API AFire_Slime : public AEnemy
{
	GENERATED_BODY()

public:
	AFire_Slime();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
};
