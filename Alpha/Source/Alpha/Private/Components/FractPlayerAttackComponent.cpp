// Fill out your copyright notice in the Description page of Project Settings.

#include "Components/FractPlayerAttackComponent.h"

#include "MotionWarpingComponent.h"
#include "RootMotionModifier.h"
#include "Camera/CameraComponent.h"
#include "Components/FractPlayerAttributeComponent.h"
#include "Engine/OverlapResult.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Test/FractTestCharacter.h"
#include "Test/FractTestEnemy.h"
#include "Weapons/FractPlayerWeapon.h"
#include "Weapons/FractProjectile.h"

#define TRACE_LENGTH 80000.f
#define ATTACK_DISTANCE 100.f

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
	
	

	if (AFractTestEnemy* FoundTarget = FindTarget())
	{
		CurrentTarget = FoundTarget;
		MotionWarpToTarget(CurrentTarget);
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
	
	DrawDebugLine(GetWorld(), Character->GetActorLocation(),
		Character->GetActorLocation() + AttackDirection * 100.f,
		FColor::Red, false, -1, 0, 1.f);
}


void UFractPlayerAttackComponent::BeginPlay()
{
	Super::BeginPlay();

	
	Character = Cast<AFractTestCharacter>(GetOwner());
	
	
}

// 콤보 리셋용 함수
void UFractPlayerAttackComponent::ResetCombo()
{
	Character->SetState(EFractCharacterState::ECS_Idle);
	ComboCount = 0;
}

// 인풋 타겟을 향해 모션 워핑을 하는 함수
void UFractPlayerAttackComponent::MotionWarpToTarget(const AActor* Target) const
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
			DrawDebugLine(GetWorld(), CharacterLocation, CharacterLocation + ToTarget * 100.f, FColor::Blue, false, -1, 0, 10.f);
			if (Angle <= AutoTargetAngle && Angle < SmallestAngle)
			{
				Target =  Enemy;
				SmallestAngle = Angle;
			}
		}
	}
	if (Target)
	{
		DrawDebugSphere(GetWorld(), Target->GetActorLocation(), 100.f, 24, FColor::Red, false, -1, 0, 0.5f);
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

void UFractPlayerAttackComponent::RotateToInputDirection(float DeltaTime)
{
	FRotator InitialRotation = Character->GetActorRotation();
	FRotator TargetRotation = AttackDirection.Rotation();
	FRotator InterpRotation = FMath::RInterpTo(InitialRotation, TargetRotation, DeltaTime, 10.f);
	Character->SetActorRotation(InterpRotation);
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
			DrawDebugSphere(GetWorld(), TraceHitResult.ImpactPoint, 12.f, 12, FColor::Red);
		}
	}
}

// 플레이어의 원거리, 근거리 공격 상태 전환용 함수
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

// 플레이어의 현재 상태에 따라 적절한 공격을 리턴하는 함수
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

// 플레이어의 상태에 따라 적절한 스킬을 리턴하는 함수
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

// 플레이어가 기본 공격을 하는 함수
void UFractPlayerAttackComponent::UseNormalAttack()
{
	if (Character->GetState() == EFractCharacterState::ECS_Idle)
	{
		Character->SetState(EFractCharacterState::ECS_Attacking);
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
					if (CurrentTarget)
					{
						MotionWarpToTarget(CurrentTarget);
					}
					else
					{
						
					}
				}

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

// 플레이어가 스킬을 사용하는 함수
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





