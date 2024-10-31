// Fill out your copyright notice in the Description page of Project Settings.


#include "Test/FractTestCharacter.h"

#include "EnhancedInputComponent.h"
#include "Components/FractPlayerAttackComponent.h"
#include "Components/FractPlayerAttributeComponent.h"
#include "Weapons/FractPlayerWeapon.h"

AFractTestCharacter::AFractTestCharacter()
{
	Attribute = CreateDefaultSubobject<UFractPlayerAttributeComponent>(TEXT("Player Attribute Component"));
	AttackComponent = CreateDefaultSubobject<UFractPlayerAttackComponent>(TEXT("Player Attack Component"));
}

void AFractTestCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		// Attacking
		EnhancedInputComponent->BindAction(NormalAttackAction, ETriggerEvent::Started, this, &AFractTestCharacter::NormalAttack);
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
			FAttachmentTransformRules::SnapToTargetIncludingScale,
			"WeaponSocket");
	}

	
}

void AFractTestCharacter::NormalAttack()
{
	AttackComponent->UseNormalAttack();
}

void AFractTestCharacter::SetWeaponCollisionEnabled(ECollisionEnabled::Type CollisionEnabled)
{
	if (Weapon && Weapon->GetWeaponBox())
	{
		Weapon->GetWeaponBox()->SetCollisionEnabled(CollisionEnabled);
		Weapon->IgnoreActors.Empty();
	}
}


