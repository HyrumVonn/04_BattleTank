// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Public/Tank.h"
#include "MahTankPlayerController.generated.h"


UCLASS()
class BATTLETANK_API AMahTankPlayerController : public APlayerController
{
	GENERATED_BODY()

private:
	//Move the barrel so that the shot hits where the crosshair is aimed
	void AimTowardsCrosshair();

public:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	ATank* ControlledTank;

	ATank* GetControlledTank() const;

};
