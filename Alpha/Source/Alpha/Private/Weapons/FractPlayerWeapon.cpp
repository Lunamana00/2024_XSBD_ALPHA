// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapons/FractPlayerWeapon.h"

#include "Components/FractPlayerAttributeComponent.h"
#include "Interfaces/FractHitInterface.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Test/FractTestCharacter.h"

// Sets default values
AFractPlayerWeapon::AFractPlayerWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	WeaponMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WeaponMeshComponent"));
	WeaponMesh->SetupAttachment(RootComponent);
	WeaponBox = CreateDefaultSubobject<UBoxComponent>(TEXT("WeaponBoxComponent"));
	WeaponBox->SetupAttachment(WeaponMesh);
	WeaponBox->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	WeaponBox->SetCollisionResponseToAllChannels(ECR_Overlap);
	WeaponBox->SetCollisionResponseToChannel(ECC_Pawn, ECR_Ignore);

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
	this->SetOwner(Cast<AFractTestCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0)));
	this->SetInstigator(Cast<AFractTestCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0)));
	
}

void AFractPlayerWeapon::OnWeaponBoxOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	const FVector Start = BoxTraceStart->GetComponentLocation();
	const FVector End = BoxTraceEnd->GetComponentLocation();

	TArray<AActor*> ActorsToIgnore;
	ActorsToIgnore.Add(this);

	for (AActor* Actor : IgnoreActors)
	{
		ActorsToIgnore.AddUnique(Actor);
	}
	
	FHitResult WeaponHit;
	UKismetSystemLibrary::BoxTraceSingle(this, Start, End, FVector(5.f, 5.f, 5.f),
		BoxTraceStart->GetComponentRotation(), ETraceTypeQuery::TraceTypeQuery1, false, ActorsToIgnore,
		EDrawDebugTrace::ForDuration, WeaponHit, true);
	if (WeaponHit.GetActor())
	{
		UGameplayStatics::PlayWorldCameraShake(GetWorld(), CamShake, GetActorLocation(),
			0, 1000.f, 1.f, false);
		if (IFractHitInterface* HitInterface = Cast<IFractHitInterface>(WeaponHit.GetActor()))
		{
			HitInterface->GetHit(WeaponHit.ImpactPoint);
		}
		IgnoreActors.AddUnique(WeaponHit.GetActor());
		if (AFractTestCharacter* PlayerCharacter = Cast<AFractTestCharacter>(GetInstigator()))
		{
			UGameplayStatics::ApplyDamage(WeaponHit.GetActor(),
				PlayerCharacter->GetAttribute()->GetBaseDamage(),
				GetInstigator()->GetController(),
				this, UDamageType::StaticClass());
		}
		
	}
}

void AFractPlayerWeapon::OnWeaponBoxEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	
}

// Called every frame
void AFractPlayerWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}



