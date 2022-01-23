// Fill out your copyright notice in the Description page of Project Settings.


#include "FindRandomLocation_BTTask.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Runtime/NavigationSystem/Public/NavigationSystem.h"
#include "OverworldEnemyController.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Vector.h"
#include "BBKeys.h"

UFindRandomLocation_BTTask::UFindRandomLocation_BTTask(FObjectInitializer const& ObjectInitializer)
{
	NodeName = TEXT("Find Random Location");
}

EBTNodeResult::Type UFindRandomLocation_BTTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AOverworldEnemyController* const Controller = Cast<AOverworldEnemyController>(OwnerComp.GetAIOwner());
	APawn* const WorldEnemy = Controller->GetPawn();

	FVector const origin = WorldEnemy->GetActorLocation();
	FNavLocation Location;

	UNavigationSystemV1* const NavigationSystemV1 = UNavigationSystemV1::GetCurrent(GetWorld());

	if(NavigationSystemV1->GetRandomPointInNavigableRadius(origin,SearchRadius,Location,nullptr))
	{
		Controller->GetBlackboard()->SetValueAsVector(bb_keys::TargetLocation,Location.Location);
	}

	FinishLatentTask(OwnerComp,EBTNodeResult::Succeeded);
	
	return EBTNodeResult::Succeeded; 
}
