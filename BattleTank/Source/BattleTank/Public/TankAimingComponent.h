// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Components/StaticMeshComponent.h"
#include "TankAimingComponent.generated.h"

// Enum for aiming state
UENUM()
enum class EFiringState : uint8 
{
	Locked,
	Reloading,
	Aiming
};

// Forward declarations
class UTankBarrel;
class UTankTurret;
class AProjectile;

// Holds barrel properties and elevate method
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	


	UFUNCTION(BlueprintCallable, Category = "Setup")
	void InitializeComponent(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet);

	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Fire();

	EFiringState GetFiringState() const;

protected:
	UPROPERTY(BlueprintReadOnly, Category = "State")
	EFiringState FiringState = EFiringState::Reloading;

private:
	// Sets default values for this component's properties
	UTankAimingComponent();

	virtual void BeginPlay() override;

	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret = nullptr;

	bool IsBarrelMoving();

	UPROPERTY(EditAnywhere, Category = "Firing")
	float LaunchSpeed = 4000; // TODO find sensible default.

	void MoveBarrelTowards(FVector AimDirection);


	UPROPERTY(EditDefaultsOnly, Category = "Firing")
		float ReloadTimeInSeconds = 3;

	UPROPERTY(EditAnywhere, Category = Setup)
		TSubclassOf<AProjectile> ProjectileBlueprint;

	double LastFireTime = 0;

	FVector AimDirection;
};
