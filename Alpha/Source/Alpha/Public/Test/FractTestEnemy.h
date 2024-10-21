// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Interfaces/FractHitInterface.h"
#include "FractTestEnemy.generated.h"

UCLASS()
class ALPHA_API AFractTestEnemy : public ACharacter, public IFractHitInterface
{
	GENERATED_BODY()

public:
	
	AFractTestEnemy();

protected:
	
	virtual void BeginPlay() override;

public:	
	
	virtual void Tick(float DeltaTime) override;

	// 공격 맞는 함수 오버라이드
	virtual void GetHit(const FVector& ImpactPoint) override;

	
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
