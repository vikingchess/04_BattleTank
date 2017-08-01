// Copyright 2017 David Flom

#include "TankTrack.h"

UTankTrack::UTankTrack()
{
	PrimaryComponentTick.bCanEverTick = true;
}
void UTankTrack::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction * ThisTickFunction)
{
	//stop sideways slippage
	auto SlippageSpeed = FVector::DotProduct(GetRightVector(), GetComponentVelocity());
	auto CorrectionAcceleration = -SlippageSpeed / DeltaTime * GetRightVector();
	auto TankRoot = Cast <UStaticMeshComponent> (GetOwner()->GetRootComponent());
	auto CorrectionForce = (TankRoot->GetMass() * CorrectionAcceleration) / 2;
	TankRoot->AddForce(CorrectionAcceleration);
	//stop upwards movement when driving forwards Not sure if this is helping the problem?
	auto UpwardsSlippage = FVector::DotProduct(GetUpVector(), GetComponentVelocity());
	auto CorrectionUpwardsSlippage = -UpwardsSlippage / DeltaTime * GetUpVector();
	auto CorrectionUpwardForce = (TankRoot->GetMass() * CorrectionUpwardsSlippage);
	TankRoot->AddForce(CorrectionUpwardForce);
}
void UTankTrack::SetThrottle(float Throttle)
{

	auto ForceApplied = GetForwardVector() * Throttle  * TrackMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}

