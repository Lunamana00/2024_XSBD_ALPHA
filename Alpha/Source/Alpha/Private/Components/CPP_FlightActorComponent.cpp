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
		Character->GetCharacterMovement()->SetMovementMode(EMovementMode::MOVE_Flying);
		IsFlying = true;
	}
}

void UCPP_FlightActorComponent::EndFlying()
{
	if (ACharacter* Character = Cast<ACharacter>(GetOwner()))
	{
		Character->GetCharacterMovement()->SetMovementMode(EMovementMode::MOVE_Walking);
		IsFlying = false;
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
	FVector2D Input = Value.Get<FVector2D>();

	if (GetOwner())
	{
		// Forward 벡터와 Right 벡터 계산
		FVector Forward = GetOwner()->GetActorForwardVector();
		FVector Right = GetOwner()->GetActorRightVector();

		// Pitch를 고려한 위쪽 방향 이동 계산
		FRotator ActorRotation = GetOwner()->GetActorRotation();
		FRotator AdjustedRotation = FRotator(ActorRotation.Pitch, 0.0f, 0.0f); // Pitch만 고려
		FVector UpDirection = FRotationMatrix(AdjustedRotation).GetUnitAxis(EAxis::X);

		// 이동 속도 계산
		CurrentVelocity = (Input.X * Forward + Input.Y * Right + UpDirection * Input.X) * FlightSpeed;
	}
}

void UCPP_FlightActorComponent::Yaw(const FInputActionValue& Value)
{
	float Amount = Value.Get<float>();
	if (GetOwner()->GetInstigatorController())
	{
		Cast<APlayerController>(GetOwner()->GetInstigatorController())->AddYawInput(Amount * RotationSpeed * GetWorld()->GetDeltaSeconds());

	}
}

void UCPP_FlightActorComponent::Pitch(const FInputActionValue& Value)
{
	float Amount = Value.Get<float>();
	if (GetOwner())
	{
		FRotator CurrentRotation = GetOwner()->GetActorRotation();
		CurrentRotation.Pitch += Amount * RotationSpeed * GetWorld()->GetDeltaSeconds();
		GetOwner()->SetActorRotation(CurrentRotation);
	}
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

