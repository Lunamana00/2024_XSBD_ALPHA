// Fill out your copyright notice in the Description page of Project Settings.


#include "Test/FractTestEnemy.h"

#include "Components/CapsuleComponent.h"
#include "Components/FractAttributeComponent.h"

// Sets default values
AFractTestEnemy::AFractTestEnemy()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	GetMesh()->SetCollisionObjectType(ECC_WorldDynamic);
	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);
	GetMesh()->SetCollisionResponseToChannel(ECC_Camera, ECR_Ignore);
	GetMesh()->SetGenerateOverlapEvents(true);
	GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_Camera, ECR_Ignore);

	Attribute = CreateDefaultSubobject<UFractAttributeComponent>(TEXT("Attribute Component"));
}

float AFractTestEnemy::TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent,
	class AController* EventInstigator, AActor* DamageCauser)
{
	if (Attribute)
	{
		Attribute->ReceiveDamage(DamageAmount);
	}
	return DamageAmount;
}

// Called when the game starts or when spawned
void AFractTestEnemy::BeginPlay()
{
	Super::BeginPlay();
	
}

void AFractTestEnemy::PlayHitReactMontage(const FName& SectionName)
{
	UAnimInstance* AnimInstance = GetMesh()->GetAnimInstance();
	if (AnimInstance && HitReactMontage)
	{
		AnimInstance->Montage_Play(HitReactMontage);
		AnimInstance->Montage_JumpToSection(SectionName, HitReactMontage);
	}
}

// Called every frame
void AFractTestEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFractTestEnemy::DirectionalHitReact(const FVector& ImpactPoint)
{
	// const FVector Forward = GetActorForwardVector();
	// const FVector ActorLocation = GetActorLocation();
	//
	// // Create a sphere around the actor's center
	// const float SphereRadius = 50.0f; // Adjust based on your character size
	// FVector AdjustedImpactPoint = ImpactPoint;
	//
	// // Project impact point onto sphere if it's too far from actor center
	// float DistanceSquared = (ImpactPoint - ActorLocation).SizeSquared();
	// if (DistanceSquared > SphereRadius * SphereRadius)
	// {
	// 	// Project point onto sphere surface
	// 	AdjustedImpactPoint = ActorLocation + 
	// 		(ImpactPoint - ActorLocation).GetSafeNormal() * SphereRadius;
	// }
	//
	// // Calculate horizontal vectors for consistent angle calculation
	// FVector ToHit = (AdjustedImpactPoint - ActorLocation).GetSafeNormal();
	// ToHit.Z = 0;
	// ToHit = ToHit.GetSafeNormal();
	//
	// FVector HorizontalForward = Forward;
	// HorizontalForward.Z = 0;
	// HorizontalForward = HorizontalForward.GetSafeNormal();
	//
	// // Calculate angle
	// const double CosTheta = FVector::DotProduct(HorizontalForward, ToHit);
	// double Theta = FMath::Acos(FMath::Clamp(CosTheta, -1.0, 1.0));
	// Theta = FMath::RadiansToDegrees(Theta);
	//
	// // Determine direction using cross product
	// const FVector CrossProduct = FVector::CrossProduct(HorizontalForward, ToHit);
	// if (CrossProduct.Z < 0)
	// {
	// 	Theta *= -1.f;
	// }
	// FName Section("FromBack"); 
	// if (Theta >= -45.f && Theta < 45.f)
	// {
	// 	Section = FName("FromFront");
	// }
	// else if (Theta >= -135.f && Theta < -45.f)
	// {
	// 	Section = FName("FromLeft");
	// }
	// else if (Theta >= 45.f && Theta < 135.f)
	// {
	// 	Section = FName("FromRight");
	// }
	PlayHitReactMontage("FromFront");
}

void AFractTestEnemy::GetHit(const FVector& ImpactPoint)
{
	DirectionalHitReact(ImpactPoint);
}

// Called to bind functionality to input
void AFractTestEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

