#include "Fire_Slime.h"

// 기본 생성자
AFire_Slime::AFire_Slime()
{
	// 슬라임 고유 속성 초기화
	Health = 50.0f;
	MaxHealth = 50.0f;
	MovementSpeed = 200.0f;
	Damage = 15.0f;
	EnemyType = EEnemyType::Melee;
}

// BeginPlay
void AFire_Slime::BeginPlay()
{
	Super::BeginPlay();
}

// Tick
void AFire_Slime::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
