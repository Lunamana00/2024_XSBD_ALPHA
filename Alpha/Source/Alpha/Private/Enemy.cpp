#include "Enemy.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"

// 생성자
AEnemy::AEnemy()
{
	// Tick을 활성화
	PrimaryActorTick.bCanEverTick = true;

	// 기본값 초기화
	Health = 0.0f;
	MaxHealth = 0.0f;
	MovementSpeed = 0.0f;
	Damage = 0.0f;
	EnemyType = EEnemyType::None;

	// 이동 속도 초기화
	GetCharacterMovement()->MaxWalkSpeed = MovementSpeed;
}

// BeginPlay: 게임 시작 시 호출
void AEnemy::BeginPlay()
{
	Super::BeginPlay();

	// 시작 시 체력을 최대 체력으로 설정
	Health = MaxHealth;
}

// Tick: 매 프레임 호출
void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// 적의 AI 동작 또는 행동 추가 가능
}

// 데미지를 받았을 때 호출
void AEnemy::TakeDamage(float DMG)
{
	if (Damage <= 0.0f || Health <= 0.0f)
	{
		return; // 잘못된 데미지 값 또는 이미 사망한 경우 무시
	}

	// 체력 감소
	Health -= Damage;

	// 체력이 0 이하일 경우 사망 처리
	if (Health <= 0.0f)
	{
		Die();
	}
}

// 적 사망 처리
void AEnemy::Die()
{
	// 사망 이벤트 처리 (애니메이션, 효과 등)
	UE_LOG(LogTemp, Warning, TEXT("Enemy has died."));

	// 적 제거
	Destroy();
}