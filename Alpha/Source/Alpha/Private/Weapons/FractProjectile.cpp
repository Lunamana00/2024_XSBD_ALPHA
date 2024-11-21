// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapons/FractProjectile.h"
#include "NiagaraComponent.h"
#include "NiagaraFunctionLibrary.h"
#include "NiagaraFunctionLibrary.h"
#include "Components/BoxComponent.h"
#include "Engine/DamageEvents.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Particles/ParticleSystem.h"
#include "Sound/SoundCue.h"
#include "Test/FractTestEnemy.h"

AFractProjectile::AFractProjectile()
{
	PrimaryActorTick.bCanEverTick = true;

	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionBox"));
	SetRootComponent(CollisionBox);
	// CollisionBox->SetCollisionObjectType(ECC_WorldDynamic);
	// CollisionBox->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	// CollisionBox->SetCollisionResponseToAllChannels(ECR_Ignore);
	// CollisionBox->SetCollisionResponseToChannel(ECC_Visibility, ECollisionResponse::ECR_Block);
	// CollisionBox->SetCollisionResponseToChannel(ECC_WorldStatic, ECR_Block);

	NiagaraComponent = CreateDefaultSubobject<UNiagaraComponent>(TEXT("NiagaraComponent"));

	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComponent"));
	ProjectileMovementComponent->bRotationFollowsVelocity = true;
	ProjectileMovementComponent->InitialSpeed = 2000.f;
	ProjectileMovementComponent->MaxSpeed = 2000.f;
	ProjectileMovementComponent->ProjectileGravityScale = 0.f;
}

void AFractProjectile::BeginPlay()
{
	Super::BeginPlay();
	
	if (TracerEffect)
	{
		UNiagaraFunctionLibrary::SpawnSystemAttached(
		TracerEffect,
		GetRootComponent(),          // Attach to the root component or any other component
		NAME_None,
		FVector::ZeroVector,         // Relative location
		FRotator::ZeroRotator,       // Relative rotation
		EAttachLocation::KeepRelativeOffset,
		true                         // Auto destroy
		);
	}

	CollisionBox->OnComponentHit.AddDynamic(this, &AFractProjectile::OnHit);
	
}

void AFractProjectile::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	FVector NormalImpulse, const FHitResult& Hit)
{
	if (AFractTestEnemy* TargetEnemy = Cast<AFractTestEnemy>(OtherActor))
	{
		FDamageEvent DamageEvent;
		TargetEnemy->TakeDamage(10.f, DamageEvent, GetWorld()->GetFirstPlayerController(), this);
	}
	if (IFractHitInterface* HitInterface = Cast<IFractHitInterface>(OtherActor))
	{
		HitInterface->GetHit(Hit.ImpactPoint);
	}
	Destroy();
}

void AFractProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFractProjectile::Destroyed()
{
	Super::Destroyed();
	if (ImpactEffect)
	{
		UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), ImpactEffect, GetActorLocation(),
			GetActorRotation());
	}
	if (ImpactSound)
	{
		UGameplayStatics::PlaySoundAtLocation(this, ImpactSound, GetActorLocation());
	}
}

