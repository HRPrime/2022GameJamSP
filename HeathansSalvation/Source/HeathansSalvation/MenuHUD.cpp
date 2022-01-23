// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuHUD.h"
#include "SBattleMenuWidget.h"
#include "Widgets/SWeakWidget.h"
#include "Engine/Engine.h"
#include "GameFramework/PlayerController.h"

void AMenuHUD::BeginPlay()
{
	Super::BeginPlay();

	//ShowMenu();
	
}

void AMenuHUD::ShowMenu()
{
	if(GEngine && GEngine->GameViewport)
	{
		// Passes ourself into the widget, widget knows about the HUD now
		MenuWidget = SNew(SBattleMenuWidget).OwningHUD(this);
		GEngine->GameViewport->AddViewportWidgetContent(SAssignNew(MenuWidgetContainer, SWeakWidget)
			.PossiblyNullContent(MenuWidget.ToSharedRef()));
	}

	if(PlayerOwner)
	{
		PlayerOwner->bShowMouseCursor = true;
		PlayerOwner->SetInputMode(FInputModeUIOnly());
	}
}

void AMenuHUD::RemoveMenu()
{
	if(GEngine && GEngine->GameViewport && MenuWidget.IsValid() && MenuWidgetContainer.IsValid())
	{
		GEngine->GameViewport->RemoveViewportWidgetContent(MenuWidgetContainer.ToSharedRef());
		if(PlayerOwner)
		{
			PlayerOwner->bShowMouseCursor = false;
			PlayerOwner->SetInputMode(FInputModeGameOnly());
		}
	}
}



