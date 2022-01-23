// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "SlateBasics.h"
#include "SlateExtras.h"

/**
 * 
 */
class SBattleMenuWidget : public SCompoundWidget
{
public:
	//SBattleMenuWidget();
	//~SBattleMenuWidget();

	SLATE_BEGIN_ARGS(SBattleMenuWidget){}
	SLATE_ARGUMENT(TWeakObjectPtr<class AMenuHUD>, OwningHUD)
	SLATE_END_ARGS()

	/** Construction function */
	void Construct(const FArguments& InArgs);

	FReply OnAttackClicked() const;
	FReply OnTalkClicked() const;

	/** HUD that created this widget */
	TWeakObjectPtr<class AMenuHud> OwningHUD;

	virtual bool SupportsKeyboardFocus() const override { return true; };
};
