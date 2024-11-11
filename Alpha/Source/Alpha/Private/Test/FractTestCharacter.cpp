// Fill out your copyright notice in the Description page of Project Settings.


#include "Test/FractTestCharacter.h"

#include "EnhancedInputComponent.h"
#include "MotionWarpingComponent.h"
#include "Components/FractPlayerAttackComponent.h"
#include "Components/FractPlayerAttributeComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Weapons/FractPlayerWeapon.h"

AFractTestCharacter::AFractTestCharacter()
{
	Attribute = CreateDefaultSubobject<UFractPlayerAttributeComponent>(TEXT("Player Attribute Component"));
	AttackComponent = CreateDefaultSubobject<UFractPlayerAttackComponent>(TEXT("Player Attack Component"));
	MotionWarpingComponent = CreateDefaultSubobject<UMotionWarpingComponent>(TEXT("Motion Warping Component"));
	
}

void AFractTestCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		// Attacking
		EnhancedInputComponent->BindAction(NormalAttackAction, ETriggerEvent::Started, this, &AFractTestCharacter::NormalAttack);
		EnhancedInputComponent->BindAction(SwitchRangeAction, ETriggerEvent::Started, AttackComponent, &UFractPlayerAttackComponent::SwitchRange);
	}
}

void AFractTestCharacter::BeginPlay()
{
	Super::BeginPlay();
	if (WeaponClass)
	{
		FActorSpawnParameters SpawnParams;
		SpawnParams.Owner = this;
		SpawnParams.Instigator = this;

		Weapon = GetWorld()->SpawnActor<AFractPlayerWeapon>(
			WeaponClass,
			GetActorLocation(),
			GetActorRotation(),
			SpawnParams
			);
	}

	if (Weapon)
	{
		Weapon->AttachToComponent(
			GetMesh(),
			FAttachmentTransformRules::SnapToTargetNotIncludingScale,
			"RightWeaponSocket");
	}

	
}



void AFractTestCharacter::Move(const FInputActionValue& Value)
{
	Super::Move(Value);
	MovementInputVector = Value.Get<FVector2D>();
}

void AFractTestCharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	
}


void AFractTestCharacter::NormalAttack()
{
	AttackComponent->UseNormalAttack();
}

void AFractTestCharacter::SetWeaponCollisionEnabled(ECollisionEnabled::Type CollisionEnabled)
{
	if (Weapon && Weapon->GetWeaponBox())
	{
		Weapon->IgnoreActors.Empty();
		Weapon->GetWeaponBox()->SetCollisionEnabled(CollisionEnabled);
	}
}

void AFractTestCharacter::SwitchWeaponSocket(bool bIsRight)
{
	if (Weapon && GetMesh())
	{
		if (bIsRight)
		{
			Weapon->AttachToComponent(GetMesh(),
				FAttachmentTransformRules::SnapToTargetNotIncludingScale, FName("RightWeaponSocket"));
		}
		else
		{
			Weapon->AttachToComponent(GetMesh(),
				FAttachmentTransformRules::SnapToTargetNotIncludingScale, FName("LeftWeaponSocket"));
		}
	}
	
}

void AFractTestCharacter::SetAllowPhysicsRotationDuringAnimRootMotion(bool bAllowRotation)
{
	if (AttackComponent->GetCurrentTarget())
		return;
	GetCharacterMovement()->bAllowPhysicsRotationDuringAnimRootMotion = bAllowRotation;
}


