// Fill out your copyright notice in the Description page of Project Settings.


#include "TankTurret.h"

/*
	Rotates the turret static mesh component
*/
void UTankTurret::Rotate(float RelativeSpeed)
{
	// Move the turret the right amount this frame
	// given a max rotation speed, and the frame speed
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);
	auto RotationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewRotation = RelativeRotation.Yaw + RotationChange;
	SetRelativeRotation(FRotator(0, RawNewRotation, 0));
}