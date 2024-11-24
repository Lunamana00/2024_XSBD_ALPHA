// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Logging/LogMacros.h"
#include "Components/CPP_FlightActorComponent.h"
#include "AlphaCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;

DECLARE_LOG_CATEGORY_EXTERN(LogTemplateCharacter, Log, All);

UCLASS(config=Game)
class AAlphaCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FollowCamera;
	
	/** MappingContext */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputMappingContext* DefaultMappingContext;

	/** Jump Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* JumpAction;

	/** Move Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* MoveAction;

	/** Look Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* LookAction;

public:
	AAlphaCharacter();

protected:

	FVector2D MovementInput;
	
	/** Called for movement input */
	void Move(const FInputActionValue& Value);

	/** Called for looking input */
	void Look(const FInputActionValue& Value);

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	// To add mapping context
	virtual void BeginPlay();

public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }

	FORCEINLINE FVector2D GetMovementInput() const { return MovementInput; }

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////**************Add Code**************///////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	bool IsSniping;

protected:
	void StartSnipe(const FInputActionValue& Value);

	void EndSnipe(const FInputActionValue& Value);

	//*** 구르기 추가부분 ***//
	void Shift(const FInputActionValue& Value);

	void StopRolling();

	bool IsRolling = false;

	FVector2D RollDirection;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Roll")
	float RollStrength = 800.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Roll")
	float RollDuration = 0.7f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation")
	UBlendSpace* RollBlendSpace;

private:
	//*** 우클릭 추가 부분 ***//
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* StartSnipeAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* EndSnipeAction;

	//*** 비행 추가 부분 ***//
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UCPP_FlightActorComponent* FlightComponent;

	UFUNCTION(BlueprintCallable, Category = "Flight")
	bool GetIsFlying() const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* ShiftAction;


	FTimerHandle RollTimerHandle;
};

