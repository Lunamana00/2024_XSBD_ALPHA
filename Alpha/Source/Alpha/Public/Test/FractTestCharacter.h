// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Alpha/AlphaCharacter.h"
#include "Enums/FractTypes.h"
#include "FractTestCharacter.generated.h"

class UMotionWarpingComponent;
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
	virtual void Move(const FInputActionValue& Value) override;

protected:

	virtual void Tick(float DeltaSeconds) override;
	
	
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
	UPROPERTY(EditDefaultsOnly, Category = Input)
	UInputAction* SwitchRangeAction;

	UPROPERTY(VisibleDefaultsOnly, Category = Input)
	FVector2D MovementInputVector;
	
	void NormalAttack();

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = State, meta = (AllowPrivateAccess = "true"))
	EFractCharacterState CharacterState = EFractCharacterState::ECS_Idle;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = Attack, meta = (AllowPrivateAccess = "true"))
	UMotionWarpingComponent* MotionWarpingComponent;

public:
	FORCEINLINE UFractPlayerAttributeComponent* GetAttribute() const { return Attribute; }
	UFUNCTION(BlueprintCallable)
	FORCEINLINE AFractPlayerWeapon* GetWeapon() const { return Weapon; }
	FORCEINLINE EFractCharacterState GetState() const { return CharacterState; }
	FORCEINLINE void SetState(const EFractCharacterState State) { CharacterState = State; }
	
	UFUNCTION(BluePrintCallable)
	void SetWeaponCollisionEnabled(ECollisionEnabled::Type CollisionEnabled);

	UFUNCTION(BlueprintCallable)
	void SwitchWeaponSocket(bool bIsRight);

	UFUNCTION(BluePrintCallable)
	void SetAllowPhysicsRotationDuringAnimRootMotion(bool bAllowRotation);
	FORCEINLINE UMotionWarpingComponent* GetMotionWarpingComponent() const { return MotionWarpingComponent; }
	FORCEINLINE FVector2D GetMovementInputVector() const { return MovementInputVector; }
};
