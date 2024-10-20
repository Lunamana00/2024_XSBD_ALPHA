// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapons/FractPlayerWeapon.h"

#include "Kismet/KismetSystemLibrary.h"

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
	
}

void AFractPlayerWeapon::OnWeaponBoxOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	const FVector Start = BoxTraceStart->GetComponentLocation();
	const FVector End = BoxTraceEnd->GetComponentLocation();

	TArray<AActor*> ActorsToIgnore;
	ActorsToIgnore.Add(this);
	TArray<FHitResult> WeaponHits;
	// 하나의 적만 공격하게 할 거면 BoxTraceSingle로 바꿔야 함
	UKismetSystemLibrary::BoxTraceMulti(this, Start, End, FVector(5.f, 5.f, 5.f),
		BoxTraceStart->GetComponentRotation(), ETraceTypeQuery::TraceTypeQuery1, false, ActorsToIgnore,
		EDrawDebugTrace::ForDuration, WeaponHits, true);
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



