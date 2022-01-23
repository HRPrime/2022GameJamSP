// Fill out your copyright notice in the Description page of Project Settings.


#include "OverworldEnemy.h"

// Sets default values
AOverworldEnemy::AOverworldEnemy()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

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

