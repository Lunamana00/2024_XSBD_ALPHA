// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InputActionValue.h"
#include "TimerManager.h"
#include "CPP_FlightActorComponent.generated.h"


class UInputMappingContext;
class ASeunghwanTestCharacter;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ALPHA_API UCPP_FlightActorComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCPP_FlightActorComponent();

	void StartFlying();

	void EndFlying();

	bool FlyingState();

	void StartFlightMode();

	void EndFlightMode();

	void FlyUpDown(const FInputActionValue& Value);

	

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Flight")
	bool IsFlying;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Flight")
	float UpDownSpeed = 2.5f;

	UPROPERTY()
	ASeunghwanTestCharacter* SeunghwanTestCharacter;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputMappingContext* FlightMappingContext;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

};
