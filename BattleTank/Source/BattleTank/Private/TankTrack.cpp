// Copyright 2017 David Flom

#include "TankTrack.h"



void UTankTrack::SetThrottle(float Throttle)
{
	//auto Time = GetWorld()->GetTimeSeconds();
	auto Name = GetName();
	UE_LOG(LogTemp, Warning, TEXT("%s throttle %f"), *Name, Throttle);

	//TODO clamp throttle variable
}
