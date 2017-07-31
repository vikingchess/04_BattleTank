// Copyright 2017 David Flom

#include "TankAIController.h"
#include "Tank.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank = Cast<ATank>(GetPawn());
	if (ensure(PlayerTank))
	{
		MoveToActor(
			PlayerTank,
			AcceptanceRadius
		);
		ControlledTank->AimAt(PlayerTank->GetActorLocation());
		ControlledTank->Fire();

	}
}
