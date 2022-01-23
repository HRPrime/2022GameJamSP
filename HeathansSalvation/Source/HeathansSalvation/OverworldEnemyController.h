// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "OverworldEnemyController.generated.h"

/**
 * 
 */
UCLASS()
class HEATHANSSALVATION_API AOverworldEnemyController : public AAIController
{
	GENERATED_BODY()

public:
	explicit AOverworldEnemyController(FObjectInitializer const& ObjectInitializer = FObjectInitializer::Get());

	virtual void BeginPlay() override;
	virtual void OnPossess(APawn* InPawn) override;
	class UBlackboardComponent* GetBlackboard() const;

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "AI", meta = (AllowPrivateAccess = "true"))
	class UBehaviorTreeComponent* BehaviorTreeComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "AI", meta = (AllowPrivateAccess = "true"))
	class UBehaviorTree* BehaviorTree;

	class UBlackboardComponent* Blackboard;

	
};