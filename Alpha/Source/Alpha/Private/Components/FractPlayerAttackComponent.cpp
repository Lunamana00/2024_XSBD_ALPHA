// Fill out your copyright notice in the Description page of Project Settings.

#include "Components/FractPlayerAttackComponent.h"

#include "MotionWarpingComponent.h"
#include "NiagaraComponent.h"
#include "NiagaraFunctionLibrary.h"
#include "NiagaraSystem.h"
#include "RootMotionModifier.h"
#include "Blueprint/UserWidget.h"
#include "Camera/CameraComponent.h"
#include "Components/FractPlayerAttributeComponent.h"
#include "Engine/OverlapResult.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "Test/FractTestCharacter.h"
#include "Test/FractTestEnemy.h"
#include "Test/SeunghwanTestCharacter.h"
#include "Weapons/FractPlayerWeapon.h"
#include "Weapons/FractProjectile.h"

#define TRACE_LENGTH 80000.f
#define ATTACK_DISTANCE 110.f



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

	
	if (UCameraComponent* Camera = Character->GetFollowCamera())
	{
		float TargetFOV = bIsAiming ? AimFOV : DefaultFOV;
		FVector CamTargetLocation = bIsAiming ? DefaultCameraLocation + FVector(0.f, 50.f, 80.f) : DefaultCameraLocation;
		float NewFOV = FMath::FInterpTo(Camera->FieldOfView, TargetFOV, DeltaTime, 15.f);
		FVector NewCamLocation = FMath::VInterpTo(Camera->GetRelativeLocation(), CamTargetLocation, DeltaTime, 15.f);
		Camera->SetRelativeLocation(NewCamLocation);
		Camera->SetFieldOfView(NewFOV);
	}
	if (Character->GetIsFlying())
	{
		
	}
	else // Character is not flying (grounded)
	{
		if (!bHasLockOnTarget)
		{
			if (AFractTestEnemy* FoundTarget = FindTarget())
			{
				CurrentTarget = FoundTarget;
				AddMotionWarpTarget(CurrentTarget);
				bHasTarget = true;
				bCanRotateToInputDirection = false;
			}
			else
			{
				if (bHasTarget)
				{
					RemoveMotionWarpTarget(FName("AttackTarget")); // Remove only if we previously had a target
					bHasTarget = false; // No target anymore
				}
				CurrentTarget = nullptr;
				if (bCanRotateToInputDirection)
				{
					RotateToInputDirection(DeltaTime);
				}
			}
		}
		else // If we have a lock on target
		{
			if (FVector::Distance(Character->GetActorLocation(), CurrentLockOnTargetActor->GetActorLocation()) < ATTACK_DISTANCE)
			{
				AddMotionWarpTarget(CurrentLockOnTargetActor);
			}
			else
			{
				RemoveMotionWarpTarget(FName(TEXT("AttackTarget")));
			}
		}
	}
	
	
	
	// DrawDebugLine(GetWorld(), Character->GetActorLocation(),
	// 	Character->GetActorLocation() + AttackDirection * 100.f,
	// 	FColor::Red, false, -1, 0, 1.f);

	
	if (IsValid(CurrentLockOnTargetActor))
	{
		FVector CurrentLocation = Character->GetActorLocation();
		FVector TargetLocation = CurrentLockOnTargetActor->GetActorLocation();
		double TargetDistance = FVector::Distance(CurrentLocation, TargetLocation);

		if (TargetDistance >= LockOnBreakDistance)
		{
			EndLockOn();
		}
		else if (IsValid(CurrentLockOnTargetActor))
		{
			TargetLocation.Z -= 50.f;
			FRotator NewRotation = UKismetMathLibrary::FindLookAtRotation(
				CurrentLocation, TargetLocation);
			GetWorld()->GetFirstPlayerController()->SetControlRotation(NewRotation);
		}
	}

	

	
	
}


void UFractPlayerAttackComponent::BeginPlay()
{
	Super::BeginPlay();

	
	Character = Cast<ASeunghwanTestCharacter>(GetOwner());
	DefaultCameraLocation = Character->GetFollowCamera()->GetRelativeLocation();
	
	
}

// 콤보 리셋용 함수
void UFractPlayerAttackComponent::ResetCombo()
{
	AttackState = EFractAttackState::EAS_Unoccupied;
	ComboCount = 0;
}

void UFractPlayerAttackComponent::ResetAttackState()
{
	AttackState = EFractAttackState::EAS_Unoccupied;
}

// 인풋 타겟을 향해 모션 워핑을 하는 함수
void UFractPlayerAttackComponent::AddMotionWarpTarget(const AActor* Target) const
{
	if (!Character || !Target) return;

	UMotionWarpingComponent* MotionWarpingComponent = Character->GetMotionWarpingComponent();
	if (!MotionWarpingComponent) return;

	FVector CharacterLocation = Character->GetActorLocation();
	FVector TargetLocation = Target->GetActorLocation();
	FVector ToTarget = TargetLocation - CharacterLocation;
	ToTarget.Z = 0; 
	float DistanceToTarget = ToTarget.Size();
	
	const float AttackDistance = ATTACK_DISTANCE; 

	FRotator TargetRotation = ToTarget.Rotation();
	
	FMotionWarpingTarget WarpTarget;
	WarpTarget.Name = FName("AttackTarget");
	
	FVector WarpLocation = (DistanceToTarget > AttackDistance) 
		? TargetLocation - ToTarget.GetSafeNormal() * AttackDistance 
		: CharacterLocation;

	WarpTarget.Location = WarpLocation;
	WarpTarget.Rotation = TargetRotation;

	MotionWarpingComponent->AddOrUpdateWarpTarget(WarpTarget);
}

// 플레이어 주변의 적을 구체로 오버랩해서 범위 내의 적들 중 각도가 작은 적을 리턴함.
// return 값이 AFractTestEnemy* 이므로 추후 수정을 해야 함.
AFractTestEnemy* UFractPlayerAttackComponent::FindTarget()
{
	if (!Character) return nullptr;

	TArray<FOverlapResult> OverlapResults;
	FCollisionQueryParams QueryParams;
	QueryParams.AddIgnoredActor(Character); 

	FVector CharacterLocation = Character->GetActorLocation();
	GetWorld()->OverlapMultiByChannel(
		OverlapResults,
		CharacterLocation,
		FQuat::Identity,
		ECC_Pawn, 
		FCollisionShape::MakeSphere(AutoTargetRange),
		QueryParams
	);

	AFractTestEnemy* Target = nullptr;
	float SmallestAngle = FLT_MAX;
	
	for (const FOverlapResult& Result : OverlapResults)
	{
		if (AFractTestEnemy* Enemy = Cast<AFractTestEnemy>(Result.GetActor()))
		{
			FVector ToTarget = Enemy->GetActorLocation() - CharacterLocation;
			
			ToTarget.Z = 0; 
			float Angle = FMath::RadiansToDegrees(FMath::Acos(FVector::DotProduct(AttackDirection, ToTarget.GetSafeNormal())));
			// DrawDebugLine(GetWorld(), CharacterLocation, CharacterLocation + ToTarget * 100.f, FColor::Blue, false, -1, 0, 10.f);
			if (Angle <= AutoTargetAngle && Angle < SmallestAngle)
			{
				Target =  Enemy;
				SmallestAngle = Angle;
			}
		}
	}
	if (Target)
	{
		// DrawDebugSphere(GetWorld(), Target->GetActorLocation(), 100.f, 24, FColor::Red, false, -1, 0, 0.5f);
	}
	
	return Target;
}

// 플레이어 주변에 적이 탐지 되지 않았을 경우 모션 워핑 타겟을 제거해주는 함수
void UFractPlayerAttackComponent::RemoveMotionWarpTarget(FName WarpTargetName) const
{
	if (UMotionWarpingComponent* MotionWarpingComponent = Character->GetMotionWarpingComponent())
	{
		MotionWarpingComponent->RemoveWarpTarget(WarpTargetName); 
	}
}

// 인풋 방향을 향해 회전을 하는 함수
void UFractPlayerAttackComponent::RotateToInputDirection(float DeltaTime)
{
	FRotator InitialRotation = Character->GetActorRotation();
	FRotator TargetRotation = AttackDirection.Rotation();
	FRotator InterpRotation = FMath::RInterpTo(InitialRotation, TargetRotation, DeltaTime, 10.f);
	Character->SetActorRotation(InterpRotation);
}


void UFractPlayerAttackComponent::SpawnProjectile()
{
	FVector MuzzleLocation = Character->GetWeapon()->GetWeaponMuzzle()->GetComponentLocation();
    
	FVector AimDirection = HitLocation - MuzzleLocation;
	AimDirection = AimDirection.GetSafeNormal();
	FRotator SpawnRotation = AimDirection.Rotation();
    
	if (ProjectileClass && GetWorld())
	{
		FActorSpawnParameters SpawnParams;
		SpawnParams.Owner = GetOwner();
		SpawnParams.Instigator = Cast<APawn>(GetOwner());
        
		GetWorld()->SpawnActor<AFractProjectile>(
			ProjectileClass,
			MuzzleLocation,
			SpawnRotation,
			SpawnParams
		);
	}
}


void UFractPlayerAttackComponent::FireGroundSkillEnd()
{
	AttackState = EFractAttackState::EAS_Unoccupied;
	bIsCancellingSkill = false;
	Character->GetCharacterMovement()->bOrientRotationToMovement = true;
	Character->GetCharacterMovement()->bUseControllerDesiredRotation = false;
}

void UFractPlayerAttackComponent::ActivateFireGroundSkill()
{
	
	FireGroundSkillParticleSystemComponent = UGameplayStatics::SpawnEmitterAttached(
		GetSkill()->CastEffectCascade,
		Character->GetWeapon()->GetWeaponMuzzle(),
		FName("Muzzle"),
		FVector::ZeroVector,
		FRotator(-80, -30, 10),
		FVector(1.0f),
		EAttachLocation::Type::SnapToTargetIncludingScale,
		true);

	GetWorld()->GetTimerManager().SetTimer(FireGroundSkillDamageTimerHandle, this,
		&UFractPlayerAttackComponent::ApplyFireGroundSkillDamage, 0.1f, true);
	
	
	
}

void UFractPlayerAttackComponent::DeactivateFireGroundSkill()
{
	if (FireGroundSkillParticleSystemComponent)
	{
		FireGroundSkillParticleSystemComponent->Deactivate();
	}
	GetWorld()->GetTimerManager().ClearTimer(FireGroundSkillDamageTimerHandle);
	
}

void UFractPlayerAttackComponent::ApplyFireGroundSkillDamage()
{
	FVector Start = Character->GetActorLocation() + Character->GetActorForwardVector() * 300.f;
	FVector End = Character->GetActorLocation() + Character->GetActorForwardVector() * 700.f;
	FCollisionQueryParams IgnoreParams;
	IgnoreParams.AddIgnoredActor(Character);
	TArray<FHitResult> HitResults;
	FCollisionShape FireGroundSkillBox = FCollisionShape::MakeBox(FVector(80.f, 45.f, 45.f));

	bool bHasFoundTargets = GetWorld()->SweepMultiByChannel(
		HitResults,
		Start,
		End,
		Character->GetActorQuat(),
		ECC_GameTraceChannel1,
		FireGroundSkillBox,
		IgnoreParams);

	for (const FHitResult HitResult : HitResults)
	{
		if (AFractTestEnemy* CastedActor = Cast<AFractTestEnemy>(HitResult.GetActor()))
		{
			UGameplayStatics::ApplyDamage(CastedActor, 5.f,
				Character->GetController(),
				Character,
				UDamageType::StaticClass());

			if (IFractHitInterface* HitInterface = Cast<IFractHitInterface>(HitResult.GetActor()))
			{
				HitInterface->GetHit(HitResult.ImpactPoint);
			}
		}
	}

	FVector CenterPoint = UKismetMathLibrary::VLerp(Start,
			End, 0.5f);
	// UKismetSystemLibrary::DrawDebugBox(
	// 	this,
	// 	CenterPoint,
	// 	FireGroundSkillBox.GetExtent(),
	// 	bHasFoundTargets ? FColor::Green : FColor::Red,
	// 	Character->GetActorRotation(),
	// 	1.f,
	// 	2.f
	// 	);
}

// 화면의 크로스헤어를 향해 Line Trace하는 함수
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
			// DrawDebugSphere(GetWorld(), TraceHitResult.ImpactPoint, 12.f, 12, FColor::Red);
		}
	}
}

// 플레이어의 원거리, 근거리 공격 상태 전환용 함수
void UFractPlayerAttackComponent::AimDownSight(const FInputActionValue& Value)
{
	if (AttackState != EFractAttackState::EAS_Unoccupied && AttackState != EFractAttackState::EAS_RangedAttacking) return;
	if (bHasLockOnTarget)
	{
		EndLockOn();
	}
	bIsAiming = Value.Get<bool>();
	if (bIsAiming)
	{
		if (CrosshairWidget)
		{
			CrosshairWidget->AddToViewport();
		}
		CurrentRange = EFractAttackRange::Ranged;
		Character->GetCharacterMovement()->bOrientRotationToMovement = false;
		Character->GetCharacterMovement()->bUseControllerDesiredRotation = true;
	}
	else
	{
		if (CrosshairWidget)
		{
			CrosshairWidget->RemoveFromParent();
		}
		CurrentRange = EFractAttackRange::Melee;
		ResetCombo();
		Character->GetCharacterMovement()->bOrientRotationToMovement = true;
		Character->GetCharacterMovement()->bUseControllerDesiredRotation = false;
	}
}

// 플레이어의 현재 상태에 따라 적절한 공격을 리턴하는 함수
FFractAttack* UFractPlayerAttackComponent::GetNormalAttack()
{
	if (CurrentRange == EFractAttackRange::Melee)
	{
		for (int32 i = 0; i < MeleeAttacks.Num(); i++)
		{
			if (MeleeAttacks[i].Element == Character->GetAttribute()->GetElementType() &&
				MeleeAttacks[i].bIsFlyingAttack == Character->GetIsFlying())
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
			if (RangedAttacks[i].Element == Character->GetAttribute()->GetElementType() &&
				RangedAttacks[i].bIsFlyingAttack == Character->GetIsFlying())
			{
				return &RangedAttacks[i];
			}
		}
		return nullptr;
	}
	return nullptr;
}

// 플레이어의 상태에 따라 적절한 스킬을 리턴하는 함수
FFractSkill* UFractPlayerAttackComponent::GetSkill()
{
	if (Character->GetIsFlying())
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

void UFractPlayerAttackComponent::CancelFireGroundSkill()
{
	if (bIsCancellingSkill) return;
	if (UAnimInstance* AnimInstance = Character->GetMesh()->GetAnimInstance())
	{
		bIsCancellingSkill = true;
		AnimInstance->Montage_JumpToSection(FName("End"));
	}
	
}

// 플레이어가 기본 공격을 하는 함수
void UFractPlayerAttackComponent::UseNormalAttack()
{
	if (AttackState == EFractAttackState::EAS_Unoccupied
		&& !Character->GetCharacterMovement()->IsFalling())
	{
		if (const FFractAttack* Attack = GetNormalAttack())
		{
			if (UAnimInstance* AnimInstance = Character->GetMesh()->GetAnimInstance())
			{
				const FVector2D InputVector = Character->GetMovementInputVector();
				FVector CameraForwardVector = Character->GetFollowCamera()->GetForwardVector();
				FVector CameraRightVector = Character->GetFollowCamera()->GetRightVector();
				CameraForwardVector.Z = 0;
				CameraRightVector.Z = 0;

				if (!InputVector.IsZero())
				{
					AttackDirection = (CameraForwardVector * InputVector.Y +
						CameraRightVector * InputVector.X).GetSafeNormal();
				}
				else
				{
					AttackDirection = Character->GetActorForwardVector();
				}
				
				if (Attack->Range == EFractAttackRange::Melee)
				{
					AttackState = EFractAttackState::EAS_MeleeAttacking;
					if (CurrentTarget)
					{
						AddMotionWarpTarget(CurrentTarget);
					}
				}
				else if (Attack->Range == EFractAttackRange::Ranged)
				{
					AttackState = EFractAttackState::EAS_RangedAttacking;
					FHitResult TraceResult;
					TraceUnderCrosshairs(TraceResult);
					CachedHitLocation = TraceResult.ImpactPoint;
					bIsRangedAttacking = true;
				}

				ComboCount = ComboCount % Attack->AttackMontages.Num();
				AnimInstance->Montage_Play(Attack->AttackMontages[ComboCount]);
				ComboCount++;
			}
			
		}
	}
}



// 플레이어가 스킬을 사용하는 함수
void UFractPlayerAttackComponent::UseSkill()
{
	if (AttackState != EFractAttackState::EAS_Unoccupied || bIsAiming)
		return;
	if (const FFractSkill* Skill = GetSkill())
	{
		if (Skill->bIsFlyingSkill)
		{
			//Handle Flying Skill
		}
		else // 비행 스킬이 아닐 경우
		{
			switch (Skill->Element)
			{
			case EFractElementType::None: // 임시로 None 추후 fire로 옮기기
				AttackState = EFractAttackState::EAS_UsingFireGroundSkill;
				Character->GetCharacterMovement()->bOrientRotationToMovement = false;
				Character->GetCharacterMovement()->bUseControllerDesiredRotation = true;
				break;
			default:
				break;
			}
		}
		if (UAnimInstance* AnimInstance = Character->GetMesh()->GetAnimInstance())
		{
			AnimInstance->Montage_Play(Skill->SkillMontage);
		}
	}
}

void UFractPlayerAttackComponent::StartLockOn()
{
	if (bIsAiming) return;
	TArray<FHitResult> OutResults;
	FVector CurrentLocation = Character->GetActorLocation();
	FCollisionShape Sphere = FCollisionShape::MakeSphere(1000.f);
	FCollisionQueryParams IgnoreParams {FName(TEXT("Ignore Collision Params")),
			false,
			Character};
	bool bHasFoundTarget = GetWorld()->SweepMultiByChannel(
		OutResults,
		CurrentLocation,
		CurrentLocation,
		FQuat::Identity,
		ECollisionChannel::ECC_Pawn,
		Sphere,
		IgnoreParams
		);

	if (!bHasFoundTarget) return;

	FVector2D ViewportSize;
	if (GEngine && GEngine->GameViewport)
	{
		GEngine->GameViewport->GetViewportSize(ViewportSize);
	}

	FVector2D CrosshairLocation(ViewportSize.X / 2, ViewportSize.Y / 2);
	FVector CrosshairWorldPosition;
	FVector CrosshairWorldDirection;

	float SmallestAngle = MAX_FLT;
	AFractTestEnemy* TargetEnemy = nullptr;
	

	for (const FHitResult& OutResult : OutResults)
	{
		AActor* PotentialTarget = OutResult.GetActor();
		
		UGameplayStatics::DeprojectScreenToWorld(
			UGameplayStatics::GetPlayerController(this, 0), CrosshairLocation,
			CrosshairWorldPosition, CrosshairWorldDirection);
		
		if (AFractTestEnemy* CastedTarget = Cast<AFractTestEnemy>(PotentialTarget))
		{
			FVector ToTarget = (CastedTarget->GetActorLocation() - CurrentLocation).GetSafeNormal();
			float Angle = FMath::RadiansToDegrees(FMath::Acos(FVector::DotProduct(
				CrosshairWorldDirection, ToTarget)));
			if (Angle < SmallestAngle && Angle <= 60)
			{
				SmallestAngle = Angle;
				TargetEnemy = CastedTarget;
			}
		}
	}

	if (!TargetEnemy) return;

	CurrentLockOnTargetActor = TargetEnemy;
	bHasLockOnTarget = true;
	
	GetWorld()->GetFirstPlayerController()->SetIgnoreLookInput(true);
	Character->GetCharacterMovement()->bOrientRotationToMovement = false;
	Character->GetCharacterMovement()->bUseControllerDesiredRotation = true;
	Character->GetCameraBoom()->TargetOffset = FVector(0.f, 0.f , 50.f);

	IFractEnemyInterface::Execute_OnSelect(CurrentLockOnTargetActor);

	OnUpdatedTargetDelegate.Broadcast(CurrentLockOnTargetActor);
}

void UFractPlayerAttackComponent::EndLockOn()
{
	IFractEnemyInterface::Execute_OnDeselect(CurrentLockOnTargetActor);
	RemoveMotionWarpTarget(FName(TEXT("AttackTarget")));
	CurrentLockOnTargetActor = nullptr;
	Character->GetCharacterMovement()->bOrientRotationToMovement = true;
	Character->GetCharacterMovement()->bUseControllerDesiredRotation = false;
	Character->GetCameraBoom()->TargetOffset = FVector::ZeroVector;
	GetWorld()->GetFirstPlayerController()->ResetIgnoreLookInput();
	bHasLockOnTarget = false;
	bCanRotateToInputDirection = false;
	OnUpdatedTargetDelegate.Broadcast(CurrentLockOnTargetActor);

}

void UFractPlayerAttackComponent::ToggleLockOn()
{
	if (IsValid(CurrentLockOnTargetActor))
	{
		EndLockOn();
	}
	else
	{
		StartLockOn();
	}
}









