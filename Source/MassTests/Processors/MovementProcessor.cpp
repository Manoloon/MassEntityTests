// Fill out your copyright notice in the Description page of Project Settings.


#include "MovementProcessor.h"
#include "MassCommonFragments.h"
#include "MassCommonTypes.h"
#include "MassExecutionContext.h"
#include "../Core/Fragments/MyFragments.h"
#include "MassTests/Core/MassGridSubsystem.h"

// Chase processor
UChaseProcessor::UChaseProcessor()
{
	bAutoRegisterWithProcessingPhases = true;
	ProcessingPhase = EMassProcessingPhase::PrePhysics;
	ExecutionOrder.ExecuteInGroup = UE::Mass::ProcessorGroupNames::Movement;
	ExecutionFlags = static_cast<int32>(EProcessorExecutionFlags::All);
	//UE_LOG(LogTemp,Warning,TEXT("Chase Processor : Constructor"));
}

void UChaseProcessor::ConfigureQueries(const TSharedRef<FMassEntityManager>& EntityManager)
{
	EntityQuery.Initialize(EntityManager);
	EntityQuery.AddRequirement<FTransformFragment>(EMassFragmentAccess::ReadWrite,EMassFragmentPresence::All);
	EntityQuery.AddSubsystemRequirement<UMassGridSubsystem>(EMassFragmentAccess::ReadWrite);
	EntityQuery.AddSharedRequirement<FChaseSharedFragment>(EMassFragmentAccess::ReadWrite,EMassFragmentPresence::All);
	EntityQuery.AddConstSharedRequirement<FMassChaseMovementParameters>(EMassFragmentPresence::All);
	ProcessorRequirements.AddSubsystemRequirement<UMassGridSubsystem>(EMassFragmentAccess::ReadOnly);
	EntityQuery.RegisterWithProcessor(*this);
}

void UChaseProcessor::Execute(FMassEntityManager& EntityManager, FMassExecutionContext& Context)
{
	EntityQuery.ForEachEntityChunk(Context,[](FMassExecutionContext& ExecutionContext)
	{
		// Per chunk logic here.
		// so shared fragment access should be happen here.
		FChaseSharedFragment& ChaseFragment = ExecutionContext.GetMutableSharedFragment<FChaseSharedFragment>();

		const auto& Subsystem = ExecutionContext.GetSubsystemChecked<UMassGridSubsystem>();
		ChaseFragment.TargetLocation = Subsystem.GetTargetLocation();
		const TArrayView<FTransformFragment>& TransformList = ExecutionContext.GetMutableFragmentView<FTransformFragment>();
		const FVector TargetLocation = ChaseFragment.TargetLocation;
		const float DeltaTime = ExecutionContext.GetDeltaTimeSeconds();
		const int32 NumEntities = ExecutionContext.GetNumEntities();
		const FMassChaseMovementParameters& ChaseParams = ExecutionContext.GetConstSharedFragment<FMassChaseMovementParameters>();
		const float MaxChaseSpeed = ChaseParams.ChaseVelocity * DeltaTime;
		const float MinDistanceSquared = ChaseParams.ChaseMinDistance * ChaseParams.ChaseMinDistance;
		for (int32 Index = 0; Index < NumEntities;++Index)
		{
			// Per-entity logic here
			FTransform& Transform = TransformList[Index].GetMutableTransform();
			FVector CurrentLocation = Transform.GetLocation();
			FVector ToTarget = TargetLocation - CurrentLocation;
			const float DistanceSquared = ToTarget.SizeSquared();
			
			if (DistanceSquared <= MinDistanceSquared)
			{
				continue;
			}
			const float Distance = FMath::Sqrt(DistanceSquared);
			const float MoveDistance = FMath::Min(MaxChaseSpeed,Distance);
			Transform.SetLocation(CurrentLocation + (ToTarget / Distance) * MoveDistance);
		}
	});
}
