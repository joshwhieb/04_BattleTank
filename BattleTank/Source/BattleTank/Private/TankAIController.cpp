// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "TankAimingComponent.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	if (!ensure(AimingComponent)) {
		return;
	}
	TankAimingComponent = AimingComponent;
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto ControlledTank = GetPawn();

	if (!ensure(PlayerTank && ControlledTank)) { return; }

	// move towards player
	MoveToActor(PlayerTank, AcceptanceRadius); // TODO check radius is in centimeters

	// aim towards player
	TankAimingComponent->AimAt(PlayerTank->GetActorLocation());

	// fire if ready
	if (TankAimingComponent->GetFiringState() == EFiringState::Locked) {
		// UE_LOG(LogTemp, Warning, TEXT("AI Locked on!"));
		TankAimingComponent->Fire();
	}
}