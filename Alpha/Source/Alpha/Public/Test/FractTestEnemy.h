// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Interfaces/FractEnemyInterface.h"
#include "Interfaces/FractHitInterface.h"
#include "FractTestEnemy.generated.h"

class UFractAttributeComponent;

UCLASS()
class ALPHA_API AFractTestEnemy : public ACharacter, public IFractHitInterface, public IFractEnemyInterface
{
	GENERATED_BODY()

public:
	
	AFractTestEnemy();
	UFUNCTION(BlueprintCallable)
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;
	virtual void Tick(float DeltaTime) override;
	void DirectionalHitReact(const FVector& ImpactPoint);

	// 공격 맞는 함수 오버라이드
	UFUNCTION(BlueprintCallable)
	virtual void GetHit(const FVector& ImpactPoint) override;

	
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	UPROPERTY(EditDefaultsOnly, Category = Montages)
	UAnimMontage* HitReactMontage;

	UPROPERTY(EditDefaultsOnly, Category = Attributes)
	UFractAttributeComponent* Attribute;

protected:
	
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void PlayHitReactMontage(const FName& SectionName);

public:	
	UFUNCTION(BlueprintCallable)
	UFractAttributeComponent* GetAttribute() const { return Attribute; }
	

};
