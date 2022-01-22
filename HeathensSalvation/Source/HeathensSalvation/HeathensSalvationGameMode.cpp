// Copyright Epic Games, Inc. All Rights Reserved.

#include "HeathensSalvationGameMode.h"
#include "HeathensSalvationPlayerController.h"
#include "HeathensSalvationCharacter.h"
#include "UObject/ConstructorHelpers.h"

AHeathensSalvationGameMode::AHeathensSalvationGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AHeathensSalvationPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDownCPP/Blueprints/TopDownCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}