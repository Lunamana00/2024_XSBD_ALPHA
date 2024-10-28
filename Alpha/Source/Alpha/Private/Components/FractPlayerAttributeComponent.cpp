// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/FractPlayerAttributeComponent.h"

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


void UFractPlayerAttributeComponent::UseMana(const float ManaAmount)
{
	CurrentMana = FMath::Clamp(CurrentMana - ManaAmount, 0.f, MaxMana);
}


void UFractPlayerAttributeComponent::ChangeElementType(EFractElementType NewType)
{
	ElementType = NewType;
}
