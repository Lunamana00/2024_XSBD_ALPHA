#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Enemy.generated.h"

/*
적 기본 클래스
 */

UENUM(BlueprintType)
enum class EEnemyType : uint8
{
	None UMETA(DisplayName = "None"),
	Flight UMETA(DisplayName = "Flight"),
	Melee UMETA(DisplayName = "Melee"),
	Ranged UMETA(DisplayName = "Ranged")
};

UCLASS()
class ALPHA_API AEnemy : public ACharacter
{
	GENERATED_BODY()

public:
	AEnemy();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	//체력
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy Info")
	float Health;

	//최대 체력
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy Info")
	float MaxHealth;

	//이동 속도
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy Info")
	float MovementSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy Info")
	float Damage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy Info")
	EEnemyType EnemyType;
	
	// 데미지를 받았을 때 호출
	UFUNCTION(BlueprintCallable, Category = "Enemy Event")
	void TakeDamage(float DMG);

	//사망 처리
	UFUNCTION(BlueprintCallable, Category = "Enemy Event")
	void Die();

};
