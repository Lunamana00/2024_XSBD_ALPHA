// Fill out your copyright notice in the Description page of Project Settings.


#include "Test/SeunghwanTestCharacter.h"

#include "AITypes.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "MotionWarpingComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/FractPlayerAttackComponent.h"
#include "Components/FractPlayerAttributeComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Weapons/FractPlayerWeapon.h"
#include "Components/BoxComponent.h"
#include "Components/CPP_FlightActorComponent.h"


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
	FlightComponent = CreateDefaultSubobject<UCPP_FlightActorComponent>(TEXT("FlightComponent"));


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
			FAttachmentTransformRules::SnapToTargetIncludingScale,
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

	if (APlayerController* PlayerController = Cast<APlayerController>(GetController()))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}
	
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		// Jumping
		//EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &ACharacter::Jump);
		//EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);
		// Moving
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ASeunghwanTestCharacter::Move);
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Completed, this, &ASeunghwanTestCharacter::StopMoving);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &ACharacter::Jump);
		EnhancedInputComponent->BindAction(DodgeAction, ETriggerEvent::Started, this, &ASeunghwanTestCharacter::Dodge);
		// Looking
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &ASeunghwanTestCharacter::Look);
		// Attacking
		EnhancedInputComponent->BindAction(NormalAttackAction, ETriggerEvent::Started, this, &ASeunghwanTestCharacter::NormalAttack);
		EnhancedInputComponent->BindAction(AimAction, ETriggerEvent::Triggered, AttackComponent, &UFractPlayerAttackComponent::AimDownSight);
		EnhancedInputComponent->BindAction(AimAction, ETriggerEvent::Completed, AttackComponent, &UFractPlayerAttackComponent::AimDownSight);
		EnhancedInputComponent->BindAction(LockOnAction, ETriggerEvent::Started, AttackComponent, &UFractPlayerAttackComponent::ToggleLockOn);
		EnhancedInputComponent->BindAction(SkillAction, ETriggerEvent::Started, AttackComponent, &UFractPlayerAttackComponent::UseSkill);
	
		// Flying
		EnhancedInputComponent->BindAction(StartFlightModeAction, ETriggerEvent::Triggered, FlightComponent, &UCPP_FlightActorComponent::StartFlightMode);
		EnhancedInputComponent->BindAction(EndFlightModeAction, ETriggerEvent::Triggered, FlightComponent, &UCPP_FlightActorComponent::EndFlightMode);
		EnhancedInputComponent->BindAction(FlyUpDownAction, ETriggerEvent::Triggered, FlightComponent, &UCPP_FlightActorComponent::FlyUpDown);
	}

}

void ASeunghwanTestCharacter::Move(const FInputActionValue& Value)
{
	if (!bCanMoveInput) return;
	FVector2D MovementVector = Value.Get<FVector2D>();
	MovementInputVector = MovementVector;

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
}

void ASeunghwanTestCharacter::StopMoving()
{
	MovementInputVector = FVector2D::ZeroVector;
}

void ASeunghwanTestCharacter::Dodge()
{
	if (bIsDodgeOnCooldown || GetIsFlying() || AttackComponent->bIsAiming || 
		AttackComponent->GetCurrentAttackState() != EFractAttackState::EAS_Unoccupied) return;
	AttackComponent->SetCurrentAttackState(EFractAttackState::EAS_Dodging);
	bCanMoveInput = false;
	bIsDodgeOnCooldown = true; 
	GetWorld()->GetTimerManager().SetTimer(
		DodgeTimerHandle,
		this,
		&ASeunghwanTestCharacter::OnDodgeCooldownEnd,
		DodgeCooldown,
		false);
	
	FVector BaseForwardVector;
	FVector BaseRightVector;
	if (AttackComponent->bHasLockOnTarget)
	{
		BaseForwardVector = GetActorForwardVector();
		BaseRightVector = GetActorRightVector();
	}
	else
	{
		BaseForwardVector = FollowCamera->GetForwardVector();
		BaseRightVector = FollowCamera->GetRightVector();
		BaseForwardVector.Z = 0;
		BaseRightVector.Z = 0;
		BaseForwardVector = BaseForwardVector.GetSafeNormal();
		BaseRightVector = BaseRightVector.GetSafeNormal();
	}
	FVector InputVector = (BaseForwardVector * MovementInputVector.Y + BaseRightVector * MovementInputVector.X).GetSafeNormal();
	float Angle = FMath::RadiansToDegrees(FMath::Acos(FVector::DotProduct(GetActorForwardVector(), InputVector)));
	FVector CrossProduct = FVector::CrossProduct(GetActorForwardVector(), InputVector).GetSafeNormal();
	if (CrossProduct.Z < 0) Angle *= -1;
	if (UAnimInstance* AnimInstance = GetMesh()->GetAnimInstance())
	{

		if (Angle >= 135 && Angle <= -135)
		{
			AnimInstance->Montage_Play(BackwardDodgeMontage);
		}
		else if (Angle > -135 && Angle < -45)
		{
			AnimInstance->Montage_Play(LeftDodgeMontage);
		}
		else if (Angle >= -45 && Angle <= 45)
		{
			AnimInstance->Montage_Play(ForwardDodgeMontage);
		}
		else if (Angle > 45 && Angle < 135)
		{
			AnimInstance->Montage_Play(RightDodgeMontage);
		}
		bCanMoveInput = false;
		GetCharacterMovement()->GroundFriction = 0.f;
		GetCharacterMovement()->Velocity = InputVector * DodgeSpeed + GetCharacterMovement()->Velocity.Z;
		FTimerHandle StopDodgeHandle;
		GetWorld()->GetTimerManager().SetTimer(
			StopDodgeHandle,
			this,
			&ASeunghwanTestCharacter::StopDodge,
			0.5f,
			false
		);
	}
	
	
}

void ASeunghwanTestCharacter::OnDodgeCooldownEnd()
{
	bIsDodgeOnCooldown = false;
}

void ASeunghwanTestCharacter::StopDodge()
{
	bCanMoveInput = true;
	AttackComponent->SetCurrentAttackState(EFractAttackState::EAS_Unoccupied);
	GetCharacterMovement()->GroundFriction = 8.f;
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
	EFractAttackState AttackState = AttackComponent->GetCurrentAttackState();
	if (AttackState == EFractAttackState::EAS_Unoccupied)
	{
		AttackComponent->UseNormalAttack();
	}
	else if (AttackState == EFractAttackState::EAS_UsingFireGroundSkill)
	{
		AttackComponent->CancelFireGroundSkill();
	}
		
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

//Flying

bool ASeunghwanTestCharacter::GetIsFlying() const
{
	return FlightComponent ? FlightComponent->FlyingState() : false;
}

