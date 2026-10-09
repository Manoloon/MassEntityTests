// Fill out your copyright notice in the Description page of Project Settings.


#include "MyMovementTrait.h"

#include "MassEntityTemplateRegistry.h"
#include "MassTests/Core/Fragments/MyFragments.h"

// Chase Trait
void UChaseTrait::BuildTemplate(FMassEntityTemplateBuildContext& BuildContext, const UWorld& World) const
{
	FMassEntityManager& MassEntityManager = UE::Mass::Utils::GetEntityManagerChecked(World);
	
	FChaseSharedFragment ChaseFragment;
	ChaseFragment.TargetLocation = FVector::ZeroVector;
	
	const FSharedStruct& SharedFragment = MassEntityManager.GetOrCreateSharedFragment(ChaseFragment);
	BuildContext.AddSharedFragment(SharedFragment);	
	const FConstSharedStruct& ChasePositionOffsetFragment = MassEntityManager.GetOrCreateConstSharedFragment(ChaseParameters);
	BuildContext.AddConstSharedFragment(ChasePositionOffsetFragment);
}
