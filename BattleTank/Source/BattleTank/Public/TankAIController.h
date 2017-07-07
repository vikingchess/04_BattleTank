// Copyright 2017 David Flom

#pragma once

#include "Tank.h"
#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
private:

	ATank* GetControlledTank() const;
	ATank* GetPlayerTank() const;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;
	

	
	
};
