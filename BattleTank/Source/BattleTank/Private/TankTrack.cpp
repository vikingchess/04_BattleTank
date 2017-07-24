// Copyright 2017 David Flom

#include "TankTrack.h"



void UTankTrack::SetThrottle(float Throttle)
{


	//TODO clamp throttle variable

	auto ForceApplied = GetForwardVector() * Throttle  * TrackMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}
