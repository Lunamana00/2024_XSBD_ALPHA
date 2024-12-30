#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "AIC_Enemy.generated.h"

/**
 * Base Enemy AI Controller
 * - 공통 Blackboard Key와 로직 정의
 */
UCLASS()
class ALPHA_API AAIC_Enemy : public AAIController
{
	GENERATED_BODY()

public:
	AAIC_Enemy();

protected:
	virtual void BeginPlay() override;

	// 공통 Blackboard Key 초기화
	virtual void InitializeBlackboardKeys();

	// 플레이어 위치를 Blackboard에 설정
	void UpdatePlayerBlackboardKey();

	// 공격 범위 여부를 Blackboard에 업데이트
	void UpdateAttackRangeKey();

protected:
	// 공통 Behavior Tree
	UPROPERTY(EditAnywhere, Category = "AI")
	UBehaviorTree* BehaviorTree;

	// Blackboard Keys
	UPROPERTY(EditDefaultsOnly, Category = "Blackboard Keys")
	FName PlayerKey = "Player";

	UPROPERTY(EditDefaultsOnly, Category = "Blackboard Keys")
	FName IsInAttackRangeKey = "IsInAttackRange";

	UPROPERTY(EditDefaultsOnly, Category = "Blackboard Keys")
	FName CanAttackKey = "CanAttack";

	// 공격 범위
	UPROPERTY(EditAnywhere, Category = "AI")
	float AttackRange = 150.0f;
};
