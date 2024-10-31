// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Alpha/AlphaCharacter.h"
#include "Enums/FractTypes.h"
#include "FractTestCharacter.generated.h"

class UFractPlayerAttackComponent;
class AFractPlayerWeapon;
class UFractPlayerAttributeComponent;
/**
 * 
 */
UCLASS()
class ALPHA_API AFractTestCharacter : public AAlphaCharacter
{
	GENERATED_BODY()

public:
	AFractTestCharacter();

	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
	virtual void BeginPlay() override;
	
private:
	UPROPERTY(VisibleAnywhere, Category = Attribute)
	UFractPlayerAttributeComponent* Attribute;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Attack, meta = (AllowPrivateAccess = "true"))
	UFractPlayerAttackComponent* AttackComponent;

	UPROPERTY(EditDefaultsOnly, Category = Weapon)
	TSubclassOf<AFractPlayerWeapon> WeaponClass;

	UPROPERTY(VisibleDefaultsOnly, Category = Weapon)
	AFractPlayerWeapon* Weapon;

	UPROPERTY(EditDefaultsOnly, Category = Input)
	UInputAction* NormalAttackAction;

	void NormalAttack();

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = State, meta = (AllowPrivateAccess = "true"))
	EFractCharacterState CharacterState = EFractCharacterState::ECS_Idle;

public:
	FORCEINLINE UFractPlayerAttributeComponent* GetAttribute() const { return Attribute; }
	FORCEINLINE AFractPlayerWeapon* GetWeapon() const { return Weapon; }
	FORCEINLINE EFractCharacterState GetState() const { return CharacterState; }
	FORCEINLINE void SetState(const EFractCharacterState State) { CharacterState = State; }
	
	UFUNCTION(BluePrintCallable)
	void SetWeaponCollisionEnabled(ECollisionEnabled::Type CollisionEnabled);
};
