// Fill out your copyright notice in the Description page of Project Settings.


#include "OverworldEnemyController.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "HeathansSalvation/HeathansSalvationCharacter.h"
#include "Perception/AISenseConfig_Sight.h"
#include "Perception/AIPerceptionStimuliSourceComponent.h"
#include "BBKeys.h"
#include "OverworldEnemy.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "GameFramework/Character.h"
#include "Perception/AIPerceptionComponent.h"

AOverworldEnemyController::AOverworldEnemyController(FObjectInitializer const& ObjectInitializer)
{
	static ConstructorHelpers::FObjectFinder<UBehaviorTree> obj(TEXT("BehaviorTree'/Game/TopDownCPP/Blueprints/Gameplay/AI/OverworldEnemy_BT.OverworldEnemy_BT'"));
	if (obj.Succeeded())
	{
		BehaviorTree = obj.Object;
	}
	BehaviorTreeComponent = ObjectInitializer.CreateDefaultSubobject<UBehaviorTreeComponent>(this, TEXT("BehaviorComponent"));
	Blackboard = ObjectInitializer.CreateDefaultSubobject<UBlackboardComponent>(this,TEXT("Blackboard"));
	this->SetupPerceptionSystem();
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

void AOverworldEnemyController::OnUpdate(TArray<AActor*> const& UpdatedActor)
{
}

void AOverworldEnemyController::SetupPerceptionSystem()
{
	SightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("Sight Config"));
	SetPerceptionComponent(*CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("Perception")));
	SightConfig->SightRadius = 500.0f;
	SightConfig->LoseSightRadius = SightConfig->SightRadius + 100.0f;
	SightConfig->PeripheralVisionAngleDegrees = 90.0f;
	SightConfig->SetMaxAge(5.0f);
	SightConfig->AutoSuccessRangeFromLastSeenLocation = 900.0f;
	SightConfig->DetectionByAffiliation.bDetectEnemies = true;
	SightConfig->DetectionByAffiliation.bDetectFriendlies = true;
	SightConfig->DetectionByAffiliation.bDetectNeutrals = true;


	GetPerceptionComponent()->SetDominantSense(*SightConfig->GetSenseImplementation());
	GetPerceptionComponent()->OnTargetPerceptionUpdated.AddDynamic(this,&AOverworldEnemyController::OnTargetDetected);
	GetPerceptionComponent()->ConfigureSense(*SightConfig);
}

void AOverworldEnemyController::OnTargetDetected(AActor* Actor, FAIStimulus const Stimulus)
{
	AOverworldEnemy* const CharacterForController = Cast<AOverworldEnemy>(Actor);
	if(CharacterForController)
	{
		GetBlackboard()->SetValueAsBool(bb_keys::CanFindPlayer,Stimulus.WasSuccessfullySensed());
	}
}


