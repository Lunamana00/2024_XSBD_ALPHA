#include "AIC_Enemy.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"

AAIC_Enemy::AAIC_Enemy()
{
	// Tick 활성화
	PrimaryActorTick.bCanEverTick = true;
}

void AAIC_Enemy::BeginPlay()
{
	Super::BeginPlay();

	// Behavior Tree 실행
	if (BehaviorTree)
	{
		RunBehaviorTree(BehaviorTree);

		// Blackboard Key 초기화
		InitializeBlackboardKeys();
	}
}

void AAIC_Enemy::InitializeBlackboardKeys()
{
	if (Blackboard)
	{
		// 플레이어 정보 설정
		UpdatePlayerBlackboardKey();
	}
}

void AAIC_Enemy::UpdatePlayerBlackboardKey()
{
	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	if (PlayerPawn)
	{
		Blackboard->SetValueAsObject(PlayerKey, PlayerPawn);
	}
}

void AAIC_Enemy::UpdateAttackRangeKey()
{
	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	if (PlayerPawn && Blackboard)
	{
		float Distance = FVector::Dist(PlayerPawn->GetActorLocation(), GetPawn()->GetActorLocation());
		bool IsInRange = Distance <= AttackRange;

		Blackboard->SetValueAsBool(IsInAttackRangeKey, IsInRange);
	}
}
