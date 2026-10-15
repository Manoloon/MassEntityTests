// Fill out your copyright notice in the Description page of Project Settings.


#include "MassSpawnerComponent.h"

#include "MassSpawner.h"

// Called when the game starts
void UMassSpawnerComponent::BeginPlay()
{
	Super::BeginPlay();
	
}

void UMassSpawnerComponent::Execute()
{
	if (IsValid(SpawnerActor))
	{
		SpawnerActor->SetActorLocation(GetOwner()->GetActorLocation());
		SpawnerActor->DoSpawning();
	}
	else
	{
		SpawnerActor = NewObject<AMassSpawner>(this, Spawner);
	}
}

