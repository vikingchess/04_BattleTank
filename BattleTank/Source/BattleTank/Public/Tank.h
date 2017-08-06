// Copyright 2017 David Flom

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Components/ActorComponent.h"
#include "Tank.generated.h"


UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:

	virtual float TakeDamage
	(
		float DamageAmount,
		struct FDamageEvent const & DamageEvent,
		class AController * EventInstigator,
		AActor * DamageCauser
	) override;

	// Returns health percentage between 0 and 1
	UFUNCTION(BlueprintPure, Category = "Health")
	float GetHealthPercent() const;

private:
	ATank();

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	int32 StartingHealth = 100;

	UPROPERTY(VisibleAnywhere, Category = "Health")
	int32 CurrentHealth = StartingHealth;
};
