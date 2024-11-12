// Fill out your copyright notice in the Description page of Project Settings.


#include "Test/SeunghwanTestCharacter.h"
#include "EnhancedInputComponent.h"
#include "MotionWarpingComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/FractPlayerAttackComponent.h"
#include "Components/FractPlayerAttributeComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Weapons/FractPlayerWeapon.h"

// Sets default values
ASeunghwanTestCharacter::ASeunghwanTestCharacter()
{
	
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);
		
	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f); // ...at this rotation rate

	
	GetCharacterMovement()->JumpZVelocity = 700.f;
	GetCharacterMovement()->AirControl = 0.35f;
	GetCharacterMovement()->MaxWalkSpeed = 500.f;
	GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;
	GetCharacterMovement()->BrakingDecelerationFalling = 1500.0f;

	
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 400.0f; 	
	CameraBoom->bUsePawnControlRotation = true; 
	
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); 
	FollowCamera->bUsePawnControlRotation = false;

	Attribute = CreateDefaultSubobject<UFractPlayerAttributeComponent>(TEXT("Player Attribute Component"));
	AttackComponent = CreateDefaultSubobject<UFractPlayerAttackComponent>(TEXT("Player Attack Component"));
	MotionWarpingComponent = CreateDefaultSubobject<UMotionWarpingComponent>(TEXT("Motion Warping Component"));

	

}

// Called when the game starts or when spawned
void ASeunghwanTestCharacter::BeginPlay()
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

// Called every frame
void ASeunghwanTestCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASeunghwanTestCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		// Attacking
		EnhancedInputComponent->BindAction(NormalAttackAction, ETriggerEvent::Started, this, &ASeunghwanTestCharacter::NormalAttack);
		EnhancedInputComponent->BindAction(SwitchRangeAction, ETriggerEvent::Started, AttackComponent, &UFractPlayerAttackComponent::SwitchRange);
	}

}

void ASeunghwanTestCharacter::Move(const FInputActionValue& Value)
{
	FVector2D MovementVector = Value.Get<FVector2D>();
	MovementInput = MovementVector;

	if (Controller != nullptr)
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	
		// get right vector 
		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		// add movement 
		AddMovementInput(ForwardDirection, MovementVector.Y);
		AddMovementInput(RightDirection, MovementVector.X);
	}
	MovementInputVector = Value.Get<FVector2D>();
}

void ASeunghwanTestCharacter::Look(const FInputActionValue& Value)
{
	// input is a Vector2D
	const FVector2D LookAxisVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// add yaw and pitch input to controller
		AddControllerYawInput(LookAxisVector.X);
		AddControllerPitchInput(LookAxisVector.Y);
	}
}

void ASeunghwanTestCharacter::NormalAttack()
{
	AttackComponent->UseNormalAttack();
}

void ASeunghwanTestCharacter::SetWeaponCollisionEnabled(ECollisionEnabled::Type CollisionEnabled)
{
	if (Weapon && Weapon->GetWeaponBox())
	{
		Weapon->IgnoreActors.Empty();
		Weapon->GetWeaponBox()->SetCollisionEnabled(CollisionEnabled);
	}
}

void ASeunghwanTestCharacter::SwitchWeaponSocket(const bool bIsRight) const
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

void ASeunghwanTestCharacter::SetAllowPhysicsRotationDuringAnimRootMotion(bool bAllowRotation)
{
	if (AttackComponent->GetCurrentTarget())
		return;
	GetCharacterMovement()->bAllowPhysicsRotationDuringAnimRootMotion = bAllowRotation;
}

