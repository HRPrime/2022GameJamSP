// Fill out your copyright notice in the Description page of Project Settings.


#include "OverworldEnemy.h"

#include "BehaviorTree/BehaviorTreeTypes.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "Components/SkeletalMeshComponent.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "GameFramework/PlayerController.h"

// Sets default values
AOverworldEnemy::AOverworldEnemy()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//this->GetMovementComponent()
}

// Called when the game starts or when spawned
void AOverworldEnemy::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AOverworldEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AOverworldEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

