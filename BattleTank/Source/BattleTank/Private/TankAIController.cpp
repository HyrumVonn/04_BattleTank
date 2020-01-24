// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "MahTankPlayerController.h"
#include "BattleTank.h"
#include "Engine/World.h"
#include "../Public/TankAIController.h"

ATank * ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank * ATankAIController::GetPlayerTank() const
{
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (PlayerTank)
	{
		return Cast<ATank>(PlayerTank);
	}
	else
	{
		return nullptr;

	}
}


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	FString ControllerName = GetName();
	UE_LOG(LogTemp, Warning, TEXT("%s Begin Play"), *ControllerName);

	PlayerTank = GetPlayerTank();
	if (PlayerTank)
	{
		FString TankName = PlayerTank->GetName();
		UE_LOG(LogTemp, Warning, TEXT("%s found %s"), *ControllerName, *TankName)
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("%s not possesing tank"), *ControllerName);
	}

}
