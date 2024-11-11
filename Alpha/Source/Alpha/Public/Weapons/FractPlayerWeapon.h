// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "FractPlayerWeapon.generated.h"


class AFractProjectile;
class UFractPlayerAttributeComponent;

UCLASS()
class ALPHA_API AFractPlayerWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFractPlayerWeapon();

	UPROPERTY()
	TArray<AActor*> IgnoreActors;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	void OnWeaponBoxOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

	UFUNCTION()
	void OnWeaponBoxEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

	

	UPROPERTY(VisibleAnywhere, Category = "Weapon")
	UBoxComponent* WeaponBox;

	UPROPERTY(VisibleAnywhere, Category = "Weapon")
	USceneComponent* BoxTraceStart;
	UPROPERTY(VisibleAnywhere, Category = "Weapon")
	USceneComponent* BoxTraceEnd;

	UPROPERTY(VisibleAnywhere, Category = "Weapon")
	USceneComponent* WeaponMuzzle;

	UPROPERTY(EditDefaultsOnly, Category = "Camera")
	TSubclassOf<UCameraShakeBase> CamShake;

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* WeaponMesh;
	FORCEINLINE USceneComponent* GetWeaponMuzzle() const { return WeaponMuzzle; }
	FORCEINLINE UBoxComponent* GetWeaponBox() const { return WeaponBox; }
	
};
