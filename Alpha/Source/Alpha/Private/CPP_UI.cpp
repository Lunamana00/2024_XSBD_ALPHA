// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "CPP_UI.h"

class ASeunghwanTestCharacter;

void UCPP_UI::NativeConstruct()
{
	Super::NativeConstruct();

	ASeunghwanTestCharacter* Character = Cast<ASeunghwanTestCharacter>(GetOwningPlayerPawn());
	if (Character)
	{
		OwningCharacter = Character;
	}
}

float UCPP_UI::GetDodgeCooldownPercent() const
{
	if(OwningCharacter)
	{
		float CurrentCooldown = OwningCharacter->GetCurrentDodgeCooldown();
		float MaxCooldown = OwningCharacter->GetDodgeMaxCooldown();

		return (MaxCooldown - CurrentCooldown) / MaxCooldown;
	}
	return 0.0f;
}

float UCPP_UI::GetHealthPercent() const
{
	if (OwningCharacter)
	{
		return OwningCharacter->FindComponentByClass<UFractAttributeComponent>()->GetHealthPercent();
	}
	return 0.0f;
}

float UCPP_UI::GetStaminaPercent() const
{
	if(OwningCharacter)
	{
		return OwningCharacter->FindComponentByClass<UFractPlayerAttributeComponent>()->GetCurrentStaminaPercent();
	}
	return 0.0f;
}

float UCPP_UI::GetSkillCooldownPercent() const
{
	if (OwningCharacter)
	{
		float MaxCooldown =5.0f;
		float CurrentCooldown = OwningCharacter->FindComponentByClass<UFractPlayerAttackComponent>()->GetCurrentSkillCooldown();
		return CurrentCooldown / MaxCooldown;
	}
	return 0.0f;
}
