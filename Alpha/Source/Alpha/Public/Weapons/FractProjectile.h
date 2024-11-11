// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FractProjectile.generated.h"

UCLASS()
class ALPHA_API AFractProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	AFractProjectile();
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere)
	class UBoxComponent* CollisionBox;

	UPROPERTY(VisibleAnywhere)
	class UProjectileMovementComponent* ProjectileMovementComponent;

	UPROPERTY(EditAnywhere)
	class UNiagaraSystem* TracerEffect;

	UPROPERTY(EditAnywhere)
	class UNiagaraComponent* NiagaraComponent;
	
};
