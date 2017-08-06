// Copyright 2017 David Flom

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "PhysicsEngine/RadialForceComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Projectile.generated.h"

UCLASS()
class BATTLETANK_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	

	void LaunchProjectile(float Speed);

	void OnTimerExpire();

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float DestroyDelay = 10.f;

private:
	UProjectileMovementComponent* ProjectileMovement = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float ProjectileDamage = 20.0;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* CollisionMesh = nullptr;


	UPROPERTY(VisibleAnywhere, Category = "Components")
	UParticleSystemComponent* LaunchBlast = nullptr;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UParticleSystemComponent* ImpactBlast = nullptr;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	URadialForceComponent* ExplosionForce = nullptr;

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);

	
};
