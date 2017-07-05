// Copyright 2017 David Flom

#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("Begin AI play started"));

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController no possesing a tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController possesing %s"), *(ControlledTank->GetName()));
	}
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

