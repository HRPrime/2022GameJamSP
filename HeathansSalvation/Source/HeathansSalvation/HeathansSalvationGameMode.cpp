// Copyright Epic Games, Inc. All Rights Reserved.

#include "HeathansSalvationGameMode.h"
#include "HeathansSalvationPlayerController.h"
#include "HeathansSalvationCharacter.h"
#include "MenuHUD.h"
#include "MenuPlayerController.h"
#include "UObject/ConstructorHelpers.h"

AHeathansSalvationGameMode::AHeathansSalvationGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AHeathansSalvationPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDownCPP/Blueprints/TopDownCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	PlayerControllerClass = AMenuPlayerController::StaticClass();
	HUDClass = AMenuHUD::StaticClass();
}