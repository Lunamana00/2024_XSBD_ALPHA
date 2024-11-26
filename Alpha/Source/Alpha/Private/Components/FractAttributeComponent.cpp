// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/FractAttributeComponent.h"

// Sets default values for this component's properties
UFractAttributeComponent::UFractAttributeComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	

	// ...
}


// Called when the game starts
void UFractAttributeComponent::BeginPlay()
{
	Super::BeginPlay();
	// ...
	CurrentHealth = MaxHealth;
}


// Called every frame
void UFractAttributeComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UFractAttributeComponent::ReceiveDamage(const float DamageAmount)
{
	GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Red, "Receive");
	CurrentHealth = FMath::Clamp(CurrentHealth - DamageAmount, 0.f, MaxHealth);
}

void UFractAttributeComponent::HealHealth(const float HealAmount)
{
	CurrentHealth = FMath::Clamp(CurrentHealth + HealAmount, 0.f, MaxHealth);
}

bool UFractAttributeComponent::IsAlive() const
{
	return CurrentHealth > 0.f;
}

