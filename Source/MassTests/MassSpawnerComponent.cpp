// Fill out your copyright notice in the Description page of Project Settings.


#include "MassSpawnerComponent.h"

#include "MassSpawner.h"

// Sets default values for this component's properties
UMassSpawnerComponent::UMassSpawnerComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UMassSpawnerComponent::BeginPlay()
{
	Super::BeginPlay();
	SpawnerActor = NewObject<AMassSpawner>(this, Spawner);
}

void UMassSpawnerComponent::PostInitProperties()
{
	Super::PostInitProperties();
}

// Called every frame
void UMassSpawnerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UMassSpawnerComponent::Execute()
{
	if (IsValid(SpawnerActor))
	{
		SpawnerActor->SetActorLocation(GetOwner()->GetActorLocation());
		SpawnerActor->DoSpawning();
	}
}

