// Fill out your copyright notice in the Description page of Project Settings.


#include "MassGridSubsystem.h"

FVector UMassGridSubsystem::GetTargetLocation() const
{
	return TargetActor->GetActorLocation();
}

void UMassGridSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UMassGridSubsystem::OnWorldBeginPlay(UWorld& InWorld)
{
	Super::OnWorldBeginPlay(InWorld);
	if (GetWorld())
	{
		TargetActor = GetWorld()->GetFirstPlayerController()->GetPawn();
		UE_LOG(LogTemp,Warning,TEXT("Subsystem : TargetActor set : %s"),*TargetActor->GetName());
	}	
}

void UMassGridSubsystem::Deinitialize()
{
	Super::Deinitialize();
}
