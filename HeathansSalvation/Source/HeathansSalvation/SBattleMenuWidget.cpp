// Fill out your copyright notice in the Description page of Project Settings.


#include "SBattleMenuWidget.h"
#include "MenuHUD.h"
#include "GameFramework/PlayerController.h"
#define LOCTEXT_NAMESPACE "BattleMenu"

// Where we build the UI
void SBattleMenuWidget::Construct(const FArguments& InArgs)
{
	bCanSupportFocus = true;
	OwningHUD = (const TWeakObjectPtr<AMenuHud>&)InArgs._OwningHUD;
	
	const FMargin ContentPadding = FMargin(550.0f, 350.0f);
	const FMargin ButtonPadding = FMargin(10.0f);
	const FText AttackText = LOCTEXT("Attack", "Attack");
	const FText TalkText = LOCTEXT("Talk", "Talk");

	FSlateFontInfo ButtonTextStyle = FCoreStyle::Get().GetFontStyle("EmbossedText");
	ButtonTextStyle.Size = 40.0f;

	// Where we put all of the UI
	ChildSlot
	[
		SNew(SOverlay)
		+ SOverlay::Slot().HAlign(HAlign_Left).VAlign(VAlign_Bottom).Padding(ContentPadding)
		[
			SNew(SVerticalBox)
			// Attack Button
			+ SVerticalBox::Slot().Padding(ButtonPadding)
			[
				SNew(SButton).OnClicked(this, &SBattleMenuWidget::OnAttackClicked)
				[
					SNew(STextBlock).Font(ButtonTextStyle).Text(AttackText).Justification(ETextJustify::Left)
				]
			]
			// Talk Button
			+ SVerticalBox::Slot().Padding(ButtonPadding)
			[
				SNew(SButton).OnClicked(this, &SBattleMenuWidget::OnTalkClicked)
				[
					SNew(STextBlock).Font(ButtonTextStyle).Text(TalkText).Justification(ETextJustify::Left)
				]
			]
		]
	];
}

FReply SBattleMenuWidget::OnAttackClicked() const
{
	return FReply::Handled();
}

FReply SBattleMenuWidget::OnTalkClicked() const
{
	return FReply::Handled();
}


#undef LOCTEXT_NAMESPACE