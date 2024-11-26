// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapons/FractPlayerWeapon.h"

#include "NiagaraFunctionLibrary.h"
#include "Sound/SoundCue.h"
#include "Components/FractPlayerAttributeComponent.h"
#include "Engine/DamageEvents.h"
#include "Interfaces/FractHitInterface.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/KismetSystemLibrary.h"
#include "PhysicsEngine/ShapeElem.h"
#include "Test/FractTestCharacter.h"
#include "Test/FractTestEnemy.h"
#include "Test/SeunghwanTestCharacter.h"

// Sets default values
AFractPlayerWeapon::AFractPlayerWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	WeaponMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WeaponMeshComponent"));
	WeaponMesh->SetupAttachment(RootComponent);
	WeaponBox = CreateDefaultSubobject<UBoxComponent>(TEXT("WeaponBoxComponent"));
	WeaponBox->SetupAttachment(WeaponMesh);
	// WeaponBox->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	// WeaponBox->SetCollisionResponseToAllChannels(ECR_Overlap);
	// WeaponBox->SetCollisionResponseToChannel(ECC_Pawn, ECR_Ignore);

	WeaponMuzzle = CreateDefaultSubobject<USceneComponent>(TEXT("MuzzleLocation"));
	WeaponMuzzle->SetupAttachment(WeaponMesh);

	BoxTraceStart = CreateDefaultSubobject<USceneComponent>(TEXT("BoxTraceStart"));
	BoxTraceStart->SetupAttachment(WeaponMesh);
	BoxTraceEnd = CreateDefaultSubobject<USceneComponent>(TEXT("BoxTraceEnd"));
	BoxTraceEnd->SetupAttachment(WeaponMesh);

}

// Called when the game starts or when spawned
void AFractPlayerWeapon::BeginPlay()
{
	Super::BeginPlay();
	WeaponBox->OnComponentBeginOverlap.AddDynamic(this, &AFractPlayerWeapon::OnWeaponBoxOverlap);
	WeaponBox->OnComponentEndOverlap.AddDynamic(this, &AFractPlayerWeapon::OnWeaponBoxEndOverlap);
	this->SetOwner(Cast<ASeunghwanTestCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0)));
	this->SetInstigator(Cast<ASeunghwanTestCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0)));
	
}

void AFractPlayerWeapon::OnWeaponBoxOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// const FVector Start = BoxTraceStart->GetComponentLocation();
	// const FVector End = BoxTraceEnd->GetComponentLocation();
	//
	// TArray<AActor*> ActorsToIgnore;
	// ActorsToIgnore.Add(this);
	//
	// for (AActor* Actor : IgnoreActors)
	// {
	// 	ActorsToIgnore.AddUnique(Actor);
	// }
	//
	// FHitResult WeaponHit;
	// UKismetSystemLibrary::BoxTraceSingle(this, Start, End, FVector(10.f, 10.f, 30.f),
	// 	BoxTraceStart->GetComponentRotation(), ETraceTypeQuery::TraceTypeQuery1, false, ActorsToIgnore,
	// 	EDrawDebugTrace::ForDuration, WeaponHit, true);
	//
	//
	//
	// if (WeaponHit.GetActor())
	// {
	// 	UGameplayStatics::PlayWorldCameraShake(GetWorld(), CamShake, GetActorLocation(),
	// 		0, 1000.f, 1.f, false);
	// 	if (IFractHitInterface* HitInterface = Cast<IFractHitInterface>(WeaponHit.GetActor()))
	// 	{
	// 		HitInterface->GetHit(WeaponHit.ImpactPoint);
	// 	}
	// 	IgnoreActors.AddUnique(WeaponHit.GetActor());
	// 	if (ASeunghwanTestCharacter* PlayerCharacter = Cast<ASeunghwanTestCharacter>(GetInstigator()))
	// 	{
	// 		UGameplayStatics::ApplyDamage(WeaponHit.GetActor(),
	// 			PlayerCharacter->GetAttribute()->GetBaseDamage(),
	// 			GetInstigator()->GetController(),
	// 			this, UDamageType::StaticClass());
	// 	}
	// 	
	// }
}

void AFractPlayerWeapon::OnWeaponBoxEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	
}

// Called every frame
void AFractPlayerWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!bIsAttacking) return;

	TArray<FHitResult> WeaponHits;
	FCollisionQueryParams IgnoreParams(
		FName(TEXT("Ignore Params")),
		false,
		GetOwner());
	
	FCollisionShape Box = FCollisionShape::MakeBox(FVector(45.f, 15.f, 15.f));
	
	bool bHasFoundTargets = GetWorld()->SweepMultiByChannel(
		WeaponHits,
		BoxTraceStart->GetComponentLocation(),
		BoxTraceEnd->GetComponentLocation(),
		BoxTraceStart->GetComponentQuat(),
		ECC_GameTraceChannel1,
		Box,
		IgnoreParams);
	
	if (bDebugMode)
	{
		FVector CenterPoint = UKismetMathLibrary::VLerp(BoxTraceStart->GetComponentLocation(),
			BoxTraceEnd->GetComponentLocation(), 0.5f);
		UKismetSystemLibrary::DrawDebugBox(
			this,
			CenterPoint,
			Box.GetExtent(),
			bHasFoundTargets ? FColor::Green : FColor::Red,
			BoxTraceStart->GetComponentRotation(),
			1.f,
			2.f
			);
	}
	
	FDamageEvent TargetAttackedEvent;
	
	for (const FHitResult& WeaponHit : WeaponHits)
	{
		if (AFractTestEnemy* TargetEnemy = Cast<AFractTestEnemy>(WeaponHit.GetActor()))
		{

			if (TargetsToIgnore.Contains(TargetEnemy)) continue;
			
			UGameplayStatics::PlayWorldCameraShake(GetWorld(), CamShake, GetActorLocation(),
	 		0, 1000.f, 1.f, false);

			UGameplayStatics::PlaySoundAtLocation(
				this,
				HitSoundCue,
				WeaponHit.ImpactPoint
			);
			if (FireHitNiagaraSystem)
			{
				UNiagaraFunctionLibrary::SpawnSystemAtLocation(
				this,
				FireHitNiagaraSystem,
				WeaponHit.ImpactPoint,
				FRotator(0, 0, 0),
				FVector(1.f),
				true
				);
			}
			

			if (IFractHitInterface* HitInterface = Cast<IFractHitInterface>(WeaponHit.GetActor()))
			{
				HitInterface->GetHit(WeaponHit.ImpactPoint);
			}
			
			if (ASeunghwanTestCharacter* PlayerCharacter = Cast<ASeunghwanTestCharacter>(GetInstigator()))
			{
				GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Red, "PlayerCharacter");
				float DamageAmount = PlayerCharacter->GetAttribute()->GetBaseDamage();
				TargetEnemy->TakeDamage(DamageAmount, TargetAttackedEvent,
					PlayerCharacter->GetController(), GetInstigator());
			}
			TargetsToIgnore.AddUnique(TargetEnemy);
		};
	
		
	}
	
}

void AFractPlayerWeapon::EmptyIgnoreActorsArray()
{
	TargetsToIgnore.Empty();
}



