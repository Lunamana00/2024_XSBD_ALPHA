// Fill out your copyright notice in the Description page of Project Settings.


#include "Test/FractTestEnemy.h"

#include "Components/CapsuleComponent.h"

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

}

// Called when the game starts or when spawned
void AFractTestEnemy::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFractTestEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFractTestEnemy::GetHit(const FVector& ImpactPoint)
{
}

// Called to bind functionality to input
void AFractTestEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

