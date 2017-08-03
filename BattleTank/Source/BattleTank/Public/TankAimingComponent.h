// Copyright 2017 David Flom

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Projectile.h"
#include "TankAimingComponent.generated.h"

// Enum for aiming status

UENUM()
enum class EFiringState : uint8 
{
Reloading,
Aiming,
Locked
};

//Forward Declaration
class UTankBarrel;
class UTankTurrent;
class AProjectile;

// Holds barrel's properties
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UFUNCTION(BlueprintCallable, Category = "Fire")
	void Fire();


	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Initilize(UTankBarrel* BarrelToSet, UTankTurrent* TurrnetToSet);

	void AimAt(FVector OutHitLocation);

	EFiringState GetFiringState() const;

protected:
	UPROPERTY(BlueprintReadOnly, Category = "State")
	EFiringState FiringState = EFiringState::Reloading;
	
private:
	// Sets default values for this component's properties
	UTankAimingComponent();
	bool IsBarrelMoving();
	virtual void UTankAimingComponent::BeginPlay()override;
	virtual void TickComponent
	(
		float DeltaTime,
		enum ELevelTick TickType,
		FActorComponentTickFunction * ThisTickFunction
	)override;

	void MoveBarrelTowards(FVector AimDirection);

	UTankBarrel* Barrel = nullptr;
	UTankTurrent* Turret = nullptr;
	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float LaunchSpeed = 4000;
	
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
		TSubclassOf<AProjectile> ProjectileBlueprint;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
		float ReloadTimeInSeconds = 5;

	double LastFireTime = 0;

	FVector AimDirection;
};
