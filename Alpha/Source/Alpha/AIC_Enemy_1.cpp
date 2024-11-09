

#include "AIC_Enemy_1.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"

void AAIC_Enemy_1::BeginPlay() {

	Super::BeginPlay();
	APawn* PlayerPawn = UGameplayStatics::UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	GetBlackboardComponent()->SetValueAsObject(TEXT("Player"), PlayerPawn);





}

void AAIC_Enemy_1::Tick(float DeltaSeconds) {

	Super::Tick(DeltaSeconds);
	APawn* PlayerPawn = UGameplayStatics::UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

	GetBlackboardComponent()->SetValueAsVector(TEXT("PlayerLocation"), PlayerPawn->GetActorLocation());
	GetBlackboardComponent()->SetValueAsVector(TEXT("ActorLocation"), GetPawn()->GetActorLocation());


	float Distance = FVector::Dist(PlayerPawn->GetActorLocation(), GetPawn()->GetActorLocation());
	GetBlackboardComponent()->SetValueAsFloat(TEXT("Distance"), Distance);



}