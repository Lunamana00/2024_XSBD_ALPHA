// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InputActionValue.h"
#include "TimerManager.h"
#include "CPP_FlightActorComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ALPHA_API UCPP_FlightActorComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCPP_FlightActorComponent();

	void StartFlying();

	void EndFlying();

	void MoveUp(const FInputActionValue& Value);

	void Move(const FInputActionValue& Value);

	void Look(const FInputActionValue& Value);

	void PressedSpace();

	void ResetSpace();

	bool FlyingState();



protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	bool IsFlying;

	bool IsPressedSpace;

	FTimerHandle SpacePressTimerHandle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Flight")
	float FlightSpeed = 600.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Flight")
	float RotationSpeed = 100.0f;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	FVector CurrentVelocity;

};
