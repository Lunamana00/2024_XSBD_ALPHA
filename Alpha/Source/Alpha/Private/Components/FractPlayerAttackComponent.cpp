// Fill out your copyright notice in the Description page of Project Settings.

#include "Components/FractPlayerAttackComponent.h"

#include "Components/FractPlayerAttributeComponent.h"
#include "Test/FractTestCharacter.h"

UFractPlayerAttackComponent::UFractPlayerAttackComponent()
{
	
	PrimaryComponentTick.bCanEverTick = false;
	
}


void UFractPlayerAttackComponent::BeginPlay()
{
	Super::BeginPlay();

	
	Character = Cast<AFractTestCharacter>(GetOwner());
	
}

void UFractPlayerAttackComponent::ResetCombo()
{
	Character->SetState(EFractCharacterState::ECS_Idle);
	ComboCount = 0;
}

void UFractPlayerAttackComponent::ToggleRange()
{
	if (CurrentRange == EFractAttackRange::Melee)
	{
		CurrentRange = EFractAttackRange::Ranged;
	}
	else
	{
		CurrentRange = EFractAttackRange::Melee;
	}
}

FFractAttack* UFractPlayerAttackComponent::GetNormalAttack()
{
	if (CurrentRange == EFractAttackRange::Melee)
	{
		for (int32 i = 0; i < MeleeAttacks.Num(); i++)
		{
			if (MeleeAttacks[i].Element == Character->GetAttribute()->GetElementType())
			{
				return &MeleeAttacks[i];
			}
		}
		return nullptr;
	}
	if (CurrentRange == EFractAttackRange::Ranged)
	{
		for (int32 i = 0; i < RangedAttacks.Num(); i++)
		{
			if (RangedAttacks[i].Element == Character->GetAttribute()->GetElementType())
			{
				return &RangedAttacks[i];
			}
		}
		return nullptr;
	}
	return nullptr;
}

FFractSkill* UFractPlayerAttackComponent::GetSkill()
{
	if (bIsFlying)
	{
		for (int32 i = 0; i < AerialSkills.Num(); i++)
		{
			if (AerialSkills[i].Element == Character->GetAttribute()->GetElementType())
			{
				return &AerialSkills[i];
			}
		}
		return nullptr;
	}
	for (int32 i = 0; i < GroundSkills.Num(); i++)
	{
		if (GroundSkills[i].Element == Character->GetAttribute()->GetElementType())
		{
			return &GroundSkills[i];
		}
	}
	return nullptr;
}

void UFractPlayerAttackComponent::UseNormalAttack()
{
	if (Character->GetState() == EFractCharacterState::ECS_Idle)
	{
		Character->SetState(EFractCharacterState::ECS_Attacking);
		if (const FFractAttack* Attack = GetNormalAttack())
		{
			if (UAnimInstance* AnimInstance = Character->GetMesh()->GetAnimInstance())
			{
				AnimInstance->Montage_Play(Attack->AttackMontages[ComboCount]);
				ComboCount = (ComboCount + 1) % Attack->AttackMontages.Num();
				
			}
		}
	}
	
	
	
}

void UFractPlayerAttackComponent::UseSkill()
{
	if (const FFractSkill* Skill = GetSkill())
	{
		if (UAnimInstance* AnimInstance = Character->GetMesh()->GetAnimInstance())
		{
			AnimInstance->Montage_Play(Skill->SkillMontage);
		}
	}
}




