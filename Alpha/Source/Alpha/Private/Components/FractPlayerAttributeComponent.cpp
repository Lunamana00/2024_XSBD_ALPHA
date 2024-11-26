// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/FractPlayerAttributeComponent.h"

#include "Components/CPP_FlightActorComponent.h"
#include "Test/SeunghwanTestCharacter.h"

float UFractPlayerAttributeComponent::GetCurrentStamina() const
{
	return CurrentStamina;
}

float UFractPlayerAttributeComponent::GetCurrentMana() const
{
	return CurrentMana;
}

void UFractPlayerAttributeComponent::UseStamina(const float StaminaAmount)
{
	CurrentStamina = FMath::Clamp(CurrentStamina - StaminaAmount, 0.f, MaxStamina);
}

void UFractPlayerAttributeComponent::UseBoostStamina(const float BoostStaminaAmount)
{
	CurrentBoostStamina = FMath::Clamp(CurrentBoostStamina - BoostStaminaAmount, 0.f, MaxBoostStamina);
}

void UFractPlayerAttributeComponent::RestoreStamina(const float StaminaAmount)
{
	CurrentStamina = FMath::Clamp(CurrentStamina + StaminaAmount, 0.f, MaxStamina);
}

void UFractPlayerAttributeComponent::RestoreBoostStamina(const float BoostStaminaAmount)
{
	CurrentBoostStamina = FMath::Clamp(CurrentBoostStamina + BoostStaminaAmount, 0.f, MaxBoostStamina);
}


void UFractPlayerAttributeComponent::UseMana(const float ManaAmount)
{
	CurrentMana = FMath::Clamp(CurrentMana - ManaAmount, 0.f, MaxMana);
}


void UFractPlayerAttributeComponent::ChangeElementType(EFractElementType NewType)
{
	ElementType = NewType;
}

void UFractPlayerAttributeComponent::BeginPlay()
{
	Super::BeginPlay();
	CurrentStamina = MaxStamina;
	CurrentMana = MaxMana;
	CurrentBoostStamina = MaxBoostStamina;
	Character = Cast<ASeunghwanTestCharacter>(GetOwner());
}

void UFractPlayerAttributeComponent::TickComponent(float DeltaTime, enum ELevelTick TickType,
	FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if (Character && !Character->GetIsFlying())
	{
		RestoreStamina(StaminaRestorePerSecond * DeltaTime);
	}
	else if (Character && Character->GetIsFlying() && !Character->bIsInFlyArea)
	{
		UseStamina(FlightStaminaUsePerSecond * DeltaTime);
		
		if (CurrentStamina <= 0.f)
		{
			Character->GetFlightComponent()->EndFlightMode();
		}
	}
	else if (Character && Character->GetIsFlying() && Character->bIsInFlyArea)
	{
		if (Character->GetFlightComponent()->bIsBoostFlying)
		{
			UseBoostStamina(10 * DeltaTime); // 나중에 변수화하기

			if (CurrentBoostStamina <= 0.f)
			{
				Character->GetFlightComponent()->EndFlightBoostMode();
			}
		}
	}
}
