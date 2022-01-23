// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "MenuHUD.generated.h"

/**
 * 
 */
UCLASS()
class HEATHANSSALVATION_API AMenuHUD : public AHUD
{
	GENERATED_BODY()

protected:
	TSharedPtr<class SBattleMenuWidget> MenuWidget;
	TSharedPtr<class SWidget> MenuWidgetContainer;
	virtual void BeginPlay() override;
	void ShowMenu();
	void RemoveMenu();
	bool isBattleMode = false;
};
