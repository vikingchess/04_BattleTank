// Copyright 2017 David Flom


#include "TankMovementComponent.h"
#include "TankTrack.h"

void UTankMovementComponent::Initilize(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet)
{
	if (!LeftTrackToSet || !RightTrackToSet) { return; }
	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
}

void UTankMovementComponent::IntendMoveForward(float Throw) 
{
	//auto Time = GetWorld()->GetTimeSeconds();
	//auto Name = GetName();
	UE_LOG(LogTemp, Warning, TEXT("Intend to move forward %f"), Throw)

	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);
}

