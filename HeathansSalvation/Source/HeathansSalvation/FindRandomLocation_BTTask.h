// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "GameFramework/Pawn.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "UObject/UObjectGlobals.h"
#include "FindRandomLocation_BTTask.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class HEATHANSSALVATION_API UFindRandomLocation_BTTask : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
public:
	UFindRandomLocation_BTTask(FObjectInitializer const& ObjectInitializer);

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

private:
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category= "Search", meta= (AllowPrivateAccess = "true"))
	float SearchRadius = 1500.0f;
};
