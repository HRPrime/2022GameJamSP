// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuPlayerController.h"

#include "MenuHUD.h"

AMenuPlayerController::AMenuPlayerController()
{
	
}

void AMenuPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	if(InputComponent)
	{
		InputComponent->BindAction("OpenBattleMenu", IE_Pressed, this, &AMenuPlayerController::OpenBattleMenu);
	}
}
