// Fill out your copyright notice in the Description page of Project Settings.

#include "MahTankPlayerController.h"


void AMahTankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("PlayerController Begin Play"));

	ControlledTank = GetControlledTank();
	if (ControlledTank)
	{
		FString TankName = ControlledTank->GetName();
		UE_LOG(LogTemp, Warning, TEXT("Player possessing %s"), *TankName)
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Player not possesing tank"));
	}
}

void AMahTankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//UE_LOG(LogTemp, Warning, TEXT("Tick %f"), DeltaTime);
	AimTowardsCrosshair();
}

ATank* AMahTankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void AMahTankPlayerController::AimTowardsCrosshair()
{
	if (!ControlledTank)
	{
		return;
	}

	//Get world location the crosshair points at
	//if it hits landscape
		//turn turret
}



