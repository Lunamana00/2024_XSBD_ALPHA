// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/CPP_FlightActorComponent.h"

#include "EnhancedInputSubsystems.h"
#include "Components/FractPlayerAttackComponent.h"
#include "GameFramework/Actor.h"
#include "GameFramework/Character.h"
#include "GameFramework/PlayerController.h"
#include "Math/Vector.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Test/SeunghwanTestCharacter.h"


// Sets default values for this component's properties
UCPP_FlightActorComponent::UCPP_FlightActorComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	IsFlying = false;
}

void UCPP_FlightActorComponent::StartFlying()
{
	if (SeunghwanTestCharacter->GetAttackComponent()->GetCurrentAttackState() == EFractAttackState::EAS_Unoccupied)
	{
		if (ACharacter* Character = Cast<ACharacter>(GetOwner()))
		{
			IsFlying = true;
			Character->GetCharacterMovement()->SetMovementMode(EMovementMode::MOVE_Flying);
		}
	}
		
	
	
}

void UCPP_FlightActorComponent::EndFlying()
{
	if (ACharacter* Character = Cast<ACharacter>(GetOwner()))
	{
		IsFlying = false;
		Character->GetCharacterMovement()->SetMovementMode(EMovementMode::MOVE_Walking);
	}
}




bool UCPP_FlightActorComponent::FlyingState()
{
	return IsFlying;
}

void UCPP_FlightActorComponent::StartFlightMode()
{
	StartFlying();
	if (APlayerController* PlayerController = Cast<APlayerController>(SeunghwanTestCharacter->GetController()))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(FlightMappingContext, 10);
		}
	}
	
}

void UCPP_FlightActorComponent::EndFlightMode()
{
	EndFlying();
	if (APlayerController* PlayerController = Cast<APlayerController>(SeunghwanTestCharacter->GetController()))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->RemoveMappingContext(FlightMappingContext);
		}
	}
	
}

void UCPP_FlightActorComponent::FlyUpDown(const FInputActionValue& Value)
{
	float InputValue = Value.Get<float>();
	if (IsFlying)
	{
		SeunghwanTestCharacter->AddMovementInput(FVector(0, 0, InputValue * UpDownSpeed));
	}
}


// Called when the game starts
void UCPP_FlightActorComponent::BeginPlay()
{
	Super::BeginPlay();
	SeunghwanTestCharacter = Cast<ASeunghwanTestCharacter>(GetOwner());
}


// Called every frame
void UCPP_FlightActorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}
