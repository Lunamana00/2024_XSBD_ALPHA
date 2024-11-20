// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Enums/FractTypes.h"
#include "SeunghwanTestCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;
class UFractPlayerAttackComponent;
class AFractPlayerWeapon;
class UFractPlayerAttributeComponent;
class UMotionWarpingComponent;


UCLASS()
class ALPHA_API ASeunghwanTestCharacter : public ACharacter
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FollowCamera;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputMappingContext* DefaultMappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* JumpAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* MoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* LookAction;

public:
	ASeunghwanTestCharacter();
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	virtual void BeginPlay() override;

	/** Called for movement input */
	void Move(const FInputActionValue& Value);

	/** Called for looking input */
	void Look(const FInputActionValue& Value);

	void StopMoving();

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
	UInputAction* AimAction;
	UPROPERTY(EditDefaultsOnly, Category = Input)
	UInputAction* LockOnAction;

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
	void SwitchWeaponSocket(bool bIsRight) const;

	UFUNCTION(BluePrintCallable)
	void SetAllowPhysicsRotationDuringAnimRootMotion(bool bAllowRotation);
	
	FORCEINLINE UMotionWarpingComponent* GetMotionWarpingComponent() const { return MotionWarpingComponent; }
	
	FORCEINLINE FVector2D GetMovementInputVector() const { return MovementInputVector; }

	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }

};
