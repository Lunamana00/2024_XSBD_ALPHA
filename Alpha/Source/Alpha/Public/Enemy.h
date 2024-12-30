#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Enemy.generated.h"

UCLASS()
class ALPHA_API AEnemy : public ACharacter
{
	GENERATED_BODY()

public:
	// 생성자
	AEnemy();

protected:
	// 게임 시작 또는 스폰 시 호출
	virtual void BeginPlay() override;

public:
	// 매 프레임 호출
	virtual void Tick(float DeltaTime) override;

	// 적의 체력
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy Stats")
	float Health;

	// 적의 최대 체력
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy Stats")
	float MaxHealth;

	// 적의 이동 속도
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy Stats")
	float MovementSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy Stats")
	float Damage;
	
	// 데미지를 받았을 때 호출
	UFUNCTION(BlueprintCallable, Category = "Enemy Event")
	void TakeDamage(float DMG);

	// 적의 사망 처리
	UFUNCTION(BlueprintCallable, Category = "Enemy Event")
	void Die();
};
