// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/FractAttributeComponent.h"

// Sets default values for this component's properties
UFractAttributeComponent::UFractAttributeComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UFractAttributeComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UFractAttributeComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UFractAttributeComponent::ReceiveDamage(float DamageAmount)
{
	Health = FMath::Clamp(Health - DamageAmount, 0.f, MaxHealth);
}

float UFractAttributeComponent::GetHealth() const
{
	return Health;
}

float UFractAttributeComponent::GetAttackDamage() const
{
	return AttackDamage;
}

EFractElementType UFractAttributeComponent::GetElementType() const
{
	return ElementType;
}

bool UFractAttributeComponent::IsAlive() const
{
	return Health > 0.f;
}

