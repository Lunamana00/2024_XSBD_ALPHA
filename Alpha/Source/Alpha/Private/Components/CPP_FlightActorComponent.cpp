	// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/CPP_FlightActorComponent.h"
#include "GameFramework/Actor.h"
#include "GameFramework/Character.h"
#include "GameFramework/PlayerController.h"
#include "Math/Vector.h"
#include "GameFramework/CharacterMovementComponent.h"



// Sets default values for this component's properties
UCPP_FlightActorComponent::UCPP_FlightActorComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	IsFlying = false;

	CurrentVelocity = FVector::ZeroVector;
}

void UCPP_FlightActorComponent::StartFlying()
{

	if (ACharacter* Character = Cast<ACharacter>(GetOwner()))
	{
		IsFlying = true;

		Character->GetCharacterMovement()->SetMovementMode(EMovementMode::MOVE_Flying);

		Character->GetCharacterMovement()->bOrientRotationToMovement = false;

		Character->GetCharacterMovement()->bUseControllerDesiredRotation = true;
	}
}

void UCPP_FlightActorComponent::EndFlying()
{
	if (ACharacter* Character = Cast<ACharacter>(GetOwner()))
	{

		IsFlying = false;

		Character->GetCharacterMovement()->SetMovementMode(EMovementMode::MOVE_Walking);

		Character->GetCharacterMovement()->bOrientRotationToMovement = true;

		Character->GetCharacterMovement()->bUseControllerDesiredRotation = false;

		CurrentVelocity = FVector::ZeroVector;
	}
}

void UCPP_FlightActorComponent::MoveUp(const FInputActionValue& Value)
{
	float Amount = Value.Get<float>();
	CurrentVelocity.Z = Amount * FlightSpeed;
}

void UCPP_FlightActorComponent::Move(const FInputActionValue& Value)
{
	FVector2D Movementvector = Value.Get<FVector2D>();
	ACharacter* Character = Cast<ACharacter>(GetOwner());

	if (GetOwner())
	{
		const FRotator Rotation =Character->Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
		const FRotator PitchRotation(Rotation.Pitch, 0, 0);

		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);

		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		const FVector UpwardDirection = FRotationMatrix(PitchRotation).GetUnitAxis(EAxis::X);

		Character->AddMovementInput(ForwardDirection, Movementvector.Y);
		Character->AddMovementInput(RightDirection,Movementvector.X);
		Character->AddMovementInput(UpwardDirection, Movementvector.Y*1.0f);
	
	}
}

void UCPP_FlightActorComponent::Look(const FInputActionValue& Value)
{
	FVector2D LookAxisVector = Value.Get<FVector2D>();
	ACharacter* Character = Cast<ACharacter>(GetOwner());
	FRotator ControlRotation = Character->Controller->GetControlRotation();

	// Apply yaw and pitch input to the controller based on the LookAxisVector
	Character->AddControllerYawInput(LookAxisVector.X);
	Character->AddControllerPitchInput(LookAxisVector.Y);

	// Adjust the player's forward vector to align with the camera's direction
	FVector ForwardDirection = FRotationMatrix(ControlRotation).GetUnitAxis(EAxis::X);
	FVector RightDirection = FRotationMatrix(ControlRotation).GetUnitAxis(EAxis::Y);
}

void UCPP_FlightActorComponent::PressedSpace()
{
	if (ACharacter* Character = Cast<ACharacter>(GetOwner()))
	{
		if (!IsPressedSpace)
		{
			IsPressedSpace = true;

			Character->Jump();

			GetWorld()->GetTimerManager().SetTimer(SpacePressTimerHandle, this, &UCPP_FlightActorComponent::ResetSpace, 0.3f, false);
		}
		else
		{
			IsPressedSpace = false;
			GetWorld()->GetTimerManager().ClearTimer(SpacePressTimerHandle);

			if (IsFlying)
			{
				EndFlying();
			}
			else
			{
				
				StartFlying();
				
			}
		}
	}
}

void UCPP_FlightActorComponent::ResetSpace()
{
	IsPressedSpace = false;
}

bool UCPP_FlightActorComponent::FlyingState()
{
	return IsFlying;
}


// Called when the game starts
void UCPP_FlightActorComponent::BeginPlay()
{
	Super::BeginPlay();
	
}


// Called every frame
void UCPP_FlightActorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if (IsFlying && GetOwner())
	{
		// 비행 중이라면 입력된 속도를 기준으로 이동 처리
		AActor* Owner = GetOwner();
		Owner->AddActorWorldOffset(CurrentVelocity * DeltaTime, true);
	}
}

