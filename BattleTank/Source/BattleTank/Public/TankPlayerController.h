// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	ATank* GetControlledTank() const;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime);
	

private:
	// start the tank moving the barrel towards the crosshair 
	// so shot hits the crosshair intersect.
	void AimTowardsCrosshair();


	// return out parameter, true if hit landscape
	bool GetSightRayHitLocation(FVector& HitLocation) const;
};
