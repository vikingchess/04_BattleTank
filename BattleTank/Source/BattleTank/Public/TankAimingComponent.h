// Copyright 2017 David Flom

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

//Forward Declaration
class UTankBarrel;
class UTankTurrent;

// Holds barrel's properties
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();
	void setBarrelReference(UTankBarrel * BarrelToSet);
	void setTurrentReference(UTankTurrent * TurrnetToSet);

protected:

public:	

	void AimAt(FVector OutHitLocation, float LaunchSpeed);
	
private:
	UTankBarrel* Barrel = nullptr;
	UTankTurrent* Turrent = nullptr;
	void MoveBarrelTowards(FVector AimDirection);
};
