// Fill out your copyright notice in the Description page of Project Settings.


#include "OrbitSpawner.h"


// Sets default values
AOrbitSpawner::AOrbitSpawner()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void AOrbitSpawner::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AOrbitSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

