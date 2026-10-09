// Fill out your copyright notice in the Description page of Project Settings.


#include "OrbitalProcessor.h"

#include "MassCommonFragments.h"
#include "MassCommonTypes.h"
#include "MassExecutionContext.h"
#include "MassMovementFragments.h"
#include "MassTests/Core/Fragments/MyFragments.h"

UOrbitalProcessor::UOrbitalProcessor()
{
	bAutoRegisterWithProcessingPhases = false;
	ExecutionFlags = static_cast<int32>(EProcessorExecutionFlags::All);
	ExecutionOrder.ExecuteInGroup = UE::Mass::ProcessorGroupNames::Movement;
}

void UOrbitalProcessor::ConfigureQueries(const TSharedRef<FMassEntityManager>& EntityManager)
{
	EntityQuery.Initialize(EntityManager);
	EntityQuery.AddRequirement<FTransformFragment>(EMassFragmentAccess::ReadWrite);
	EntityQuery.AddRequirement<FOrbitFragment>(EMassFragmentAccess::ReadWrite);
	//EntityQuery.RegisterWithProcessor(*this);
}

void UOrbitalProcessor::Execute(FMassEntityManager& EntityManager, FMassExecutionContext& Context)
{
	EntityQuery.ForEachEntityChunk( Context, [this](FMassExecutionContext& Context)
	{
		const TArrayView<FTransformFragment> TransformList = Context.GetMutableFragmentView<FTransformFragment>();
		const TArrayView<FOrbitFragment> OrbitsList = Context.GetMutableFragmentView<FOrbitFragment>();
		const int32 NumEntities = Context.GetNumEntities();
		float DeltaTime = Context.GetDeltaTimeSeconds();
		for (int32 Index = 0; Index < NumEntities; ++Index)
		{
			FTransformFragment& TransformFragment = TransformList[Index];
			FOrbitFragment& Orbit = OrbitsList[Index];
			Orbit.Angle += Orbit.AngularSpeed * DeltaTime;

			const float CenterX = Orbit.Center.X + FMath::Cos(Orbit.Angle) * Orbit.Radius;
			const float CenterY = Orbit.Center.Y + FMath::Sin(Orbit.Angle) * Orbit.Radius;
			const float CenterZ = Orbit.Center.Z + FMath::Sin(Orbit.Angle * 2.f) * 100.f;
			const FVector NewLocation = FVector(CenterX,CenterY,TransformFragment.GetMutableTransform().GetLocation().Z);
			//TransformFragment.GetMutableTransform().SetLocation(NewLocation);
			const FVector Direction = (NewLocation - Orbit.Center).GetSafeNormal();
			TransformFragment.GetMutableTransform().SetRotation(Direction.Rotation().Quaternion());
		}
	});
}
