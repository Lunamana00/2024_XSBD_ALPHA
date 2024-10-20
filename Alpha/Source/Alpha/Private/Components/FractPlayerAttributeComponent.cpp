// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/FractPlayerAttributeComponent.h"

float UFractPlayerAttributeComponent::GetStamina() const
{
	return Stamina;
}

float UFractPlayerAttributeComponent::GetMana() const
{
	return Mana;
}

void UFractPlayerAttributeComponent::UseStamina(const float StaminaAmount)
{
	Stamina = FMath::Clamp(Stamina - StaminaAmount, 0.f, MaxStamina);
}


void UFractPlayerAttributeComponent::UseMana(const float ManaAmount)
{
	Mana = FMath::Clamp(Mana - ManaAmount, 0.f, MaxMana);
}


void UFractPlayerAttributeComponent::ChangeElementType(EFractElementType NewType)
{
	ElementType = NewType;
}
