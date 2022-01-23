// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "GameFramework/Pawn.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "UObject/UObjectGlobals.h"
#include "FindPlayer_BTTask.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class HEATHANSSALVATION_API UFindPlayer_BTTask : public UBTTask_BlackboardBase
{
	GENERATED_BODY()

public:
	UFindPlayer_BTTask(FObjectInitializer const& ObjectInitializer);

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	
	
protected:
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category= "Search", meta= (AllowProtectedAccess = "true"))
	bool SearchRandom = false;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category= "Search", meta= (AllowPRotectedAccess = "true"))
	float SearchRadius = 150.0f;
};
