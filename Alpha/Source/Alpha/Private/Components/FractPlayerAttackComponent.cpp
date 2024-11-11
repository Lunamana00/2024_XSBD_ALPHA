// Fill out your copyright notice in the Description page of Project Settings.

#include "Components/FractPlayerAttackComponent.h"

#include "Components/FractPlayerAttributeComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Test/FractTestCharacter.h"
#include "Weapons/FractPlayerWeapon.h"
#include "Weapons/FractProjectile.h"

#define TRACE_LENGTH 80000.f

UFractPlayerAttackComponent::UFractPlayerAttackComponent()
{
	
	PrimaryComponentTick.bCanEverTick = true;
	
}

void UFractPlayerAttackComponent::TickComponent(float DeltaTime, enum ELevelTick TickType,
	FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	FHitResult HitResult;
	TraceUnderCrosshairs(HitResult);
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

void UFractPlayerAttackComponent::TraceUnderCrosshairs(FHitResult& TraceHitResult)
{
	FVector2D ViewportSize;
	if (GEngine && GEngine->GameViewport)
	{
		GEngine->GameViewport->GetViewportSize(ViewportSize);
	}

	FVector2D CrosshairLocation(ViewportSize.X / 2, ViewportSize.Y / 2);
	FVector CrosshairWorldPosition;
	FVector CrosshairWorldDirection;
	bool bScreenToWorld = UGameplayStatics::DeprojectScreenToWorld(
		UGameplayStatics::GetPlayerController(this, 0), CrosshairLocation,
		CrosshairWorldPosition, CrosshairWorldDirection);
	if (bScreenToWorld)
	{
		FVector Start = CrosshairWorldPosition;
		FVector End = Start + CrosshairWorldDirection * TRACE_LENGTH;

		GetWorld()->LineTraceSingleByChannel(
			TraceHitResult, Start, End, ECC_Visibility);
		if (!TraceHitResult.bBlockingHit)
		{
			TraceHitResult.ImpactPoint = End;
			HitLocation = End;
		}
		else
		{
			HitLocation = TraceHitResult.ImpactPoint;
			DrawDebugSphere(GetWorld(), TraceHitResult.ImpactPoint, 12.f, 12, FColor::Red);
		}
	}
}

void UFractPlayerAttackComponent::SwitchRange()
{
	if (CurrentRange == EFractAttackRange::Melee)
	{
		CurrentRange = EFractAttackRange::Ranged;
	}
	else if (CurrentRange == EFractAttackRange::Ranged)
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
				const FRotator ControlRotation = Character->GetControlRotation();
				FVector InputDirection(Character->GetMovementInput().X, Character->GetMovementInput().Y, 0.f);
				FVector WorldInputDirection = ControlRotation.RotateVector(InputDirection);
				WorldInputDirection.Z = 0.0f;
				FRotator TargetRotation = WorldInputDirection.Rotation();
				FRotator NewRotation = FMath::RInterpTo(Character->GetActorRotation(), TargetRotation, GetWorld()->GetDeltaSeconds(), 5.0f);

				Character->SetActorRotation(NewRotation);
				ComboCount = ComboCount % Attack->AttackMontages.Num();
				AnimInstance->Montage_Play(Attack->AttackMontages[ComboCount]);
				ComboCount++;
			}
			if (Attack->Range == EFractAttackRange::Ranged)
			{
				APawn* InstigatorPawn = Cast<APawn>(GetOwner());
				if (ProjectileClass && InstigatorPawn)
				{
					FVector MuzzleLocation = Character->GetWeapon()->GetWeaponMuzzle()->GetComponentLocation();
					FVector ToTarget = HitLocation - MuzzleLocation;
					FRotator TargetRotation = ToTarget.Rotation();
					FActorSpawnParameters SpawnParams;
					SpawnParams.Owner = GetOwner();
					SpawnParams.Instigator = InstigatorPawn;
					if (UWorld* World = GetWorld())
					{
						World->SpawnActor<AFractProjectile>(
							ProjectileClass,
							MuzzleLocation,
							TargetRotation,
							SpawnParams);
					}
				}
				
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




