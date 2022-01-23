// Fill out your copyright notice in the Description page of Project Settings.


#include "FindPlayer_BTTask.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Runtime/NavigationSystem/Public/NavigationSystem.h"
#include "OverworldEnemyController.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Vector.h"
#include "GameFramework/Character.h"
#include "BBKeys.h"
#include "Kismet/GameplayStatics.h"

UFindPlayer_BTTask::UFindPlayer_BTTask(FObjectInitializer const& ObjectInitializer)
{
	NodeName = TEXT("FindPlayer");
}

EBTNodeResult::Type UFindPlayer_BTTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	ACharacter* const Player = UGameplayStatics::GetPlayerCharacter(GetWorld(),0);
	AOverworldEnemyController* const Controller = Cast<AOverworldEnemyController>(OwnerComp.GetAIOwner());

	FVector const PlayerLocation = Player->GetActorLocation();

	if( SearchRandom)
	{
		FNavLocation NavLocation;

		UNavigationSystemV1* const NavigationSystemV1 = UNavigationSystemV1::GetCurrent(GetWorld());
		if(NavigationSystemV1->GetRandomPointInNavigableRadius(PlayerLocation,SearchRadius,NavLocation,nullptr))
		{
			Controller->GetBlackboard()->SetValueAsVector(bb_keys::TargetLocation,NavLocation.Location);
		}
	}
	else
	{
		Controller->GetBlackboard()->SetValueAsVector(bb_keys::TargetLocation,PlayerLocation);
	}

	FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
	return EBTNodeResult::Succeeded;
}
