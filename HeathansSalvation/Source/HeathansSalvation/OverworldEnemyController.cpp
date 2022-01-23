// Fill out your copyright notice in the Description page of Project Settings.


#include "OverworldEnemyController.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "HeathansSalvation/HeathansSalvationCharacter.h"

AOverworldEnemyController::AOverworldEnemyController(FObjectInitializer const& ObjectInitializer)
{
	static ConstructorHelpers::FObjectFinder<UBehaviorTree> obj(TEXT("BehaviorTree'/Game/TopDownCPP/Gameplay/AI/OverworldEnemy_BT.OverworldEnemy_BT'"));
	if (obj.Succeeded())
	{
		BehaviorTree = obj.Object;
	}
	BehaviorTreeComponent = ObjectInitializer.CreateDefaultSubobject<UBehaviorTreeComponent>(this, TEXT("BehaviorComponent"));
	Blackboard = ObjectInitializer.CreateDefaultSubobject<UBlackboardComponent>(this,TEXT("Blackboard"));
}	

void AOverworldEnemyController::BeginPlay()
{
	Super::BeginPlay();
	RunBehaviorTree(BehaviorTree);
	BehaviorTreeComponent->StartTree(*BehaviorTree);
}

void AOverworldEnemyController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	if(Blackboard)
	{
		Blackboard->InitializeBlackboard(*BehaviorTree->BlackboardAsset);
	}
}

UBlackboardComponent* AOverworldEnemyController::GetBlackboard() const
{
	return Blackboard;
}


