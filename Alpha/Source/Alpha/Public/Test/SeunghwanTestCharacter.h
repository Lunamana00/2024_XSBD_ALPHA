// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Enums/FractTypes.h"
#include "Components/CPP_FlightActorComponent.h"
#include "SeunghwanTestCharacter.generated.h"

class UBoxComponent;
class USpringArmComponent;
class UCameraComponent;
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;
class UFractPlayerAttackComponent;
class AFractPlayerWeapon;
class UFractPlayerAttributeComponent;
class UMotionWarpingComponent;
class UCPP_UI;

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

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* DodgeAction;

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

	void Dodge();

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float RestoreHealthPerSecond = 1.5f;

	UPROPERTY(EditDefaultsOnly, Category = "Animation")
	UAnimMontage* ForwardDodgeMontage;
	UPROPERTY(EditDefaultsOnly, Category = "Animation")
	UAnimMontage* RightDodgeMontage;
	UPROPERTY(EditDefaultsOnly, Category = "Animation")
	UAnimMontage* LeftDodgeMontage;
	UPROPERTY(EditDefaultsOnly, Category = "Animation")
	UAnimMontage* BackwardDodgeMontage;

	FTimerHandle DodgeTimerHandle;
	bool bIsDodgeOnCooldown = false;
	UPROPERTY(EditDefaultsOnly, Category = "Dodge")
	float DodgeCooldown = 2.f;
	void OnDodgeCooldownEnd();
	void StopDodge();
	UPROPERTY(EditDefaultsOnly, Category = "Dodge")
	float DodgeSpeed = 1500.f;
	bool bCanMoveInput = true;


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
	UPROPERTY(EditDefaultsOnly, Category = Input)
	UInputAction* SkillAction;
	UPROPERTY(EditDefaultsOnly, Category = Input)
	UInputAction* StartFlightModeAction;
	UPROPERTY(EditDefaultsOnly, Category = Input)
	UInputAction* EndFlightModeAction;
	UPROPERTY(EditDefaultsOnly, Category = Input)
	UInputAction* FlightBoostModeAction;
	UPROPERTY(EditDefaultsOnly, Category = Input)
	UInputAction* FlightSpacebarOneShotAction;
	
	UPROPERTY(EditDefaultsOnly, Category = Input)
	UInputAction* FlyUpDownAction;

	UPROPERTY(VisibleDefaultsOnly, Category = Input)
	FVector2D MovementInputVector;
	
	void NormalAttack();

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = State, meta = (AllowPrivateAccess = "true"))
	EFractCharacterState CharacterState = EFractCharacterState::ECS_Idle;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = Attack, meta = (AllowPrivateAccess = "true"))
	UMotionWarpingComponent* MotionWarpingComponent;


public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Flight")
	bool bIsInFlyArea = true;

	UFUNCTION(BlueprintCallable, Category = Attribute)
	FORCEINLINE UFractPlayerAttributeComponent* GetAttribute() const { return Attribute; }

	UFUNCTION(BlueprintCallable)
	FORCEINLINE AFractPlayerWeapon* GetWeapon() const { return Weapon; }

	UFUNCTION(BlueprintCallable)
	FORCEINLINE EFractCharacterState GetState() const { return CharacterState; }

	UFUNCTION(BlueprintCallable)
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

	UFUNCTION(BlueprintCallable)
	FORCEINLINE class UFractPlayerAttackComponent* GetAttackComponent() const { return AttackComponent; }

	//Jong Add
	UFUNCTION(BlueprintCallable, Category = "Dodge")
	float GetCurrentDodgeCooldown() const;

	float GetDodgeMaxCooldown();

protected:
	//*** ���� �߰� �κ� ***//
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UCPP_FlightActorComponent* FlightComponent;

public:
	UFUNCTION(BlueprintCallable, Category = "Flight")
	bool GetIsFlying() const;

	UFUNCTION(BlueprintCallable, Category = "Flight")
	UCPP_FlightActorComponent* GetFlightComponent() const { return FlightComponent; };

	UPROPERTY(BlueprintReadOnly, Category = "UI")
	UCPP_UI* PlayerUI;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
	TSubclassOf<UUserWidget> PlayerUIClass;
};
