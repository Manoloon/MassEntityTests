// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAgentMovementSyncTrait.h"

#include "MassEntityTemplateRegistry.h"
#include "MassEntityView.h"
#include "MassMovementFragments.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Translators/MassCharacterMovementTranslators.h"

void UMyAgentMovementSyncTrait::BuildTemplate(FMassEntityTemplateBuildContext& BuildContext, const UWorld& World) const
{
	BuildContext.AddFragment<FCharacterMovementComponentWrapperFragment>();
	BuildContext.RequireFragment<FMassVelocityFragment>();
	
	BuildContext.GetMutableObjectFragmentInitializers().Add([=](UObject& Owner, FMassEntityView& EntityView, const EMassTranslationDirection CurrentDirection)
	{
		if (auto* MovementComp = FMassAgentTraitsHelper::AsComponent<UCharacterMovementComponent>(Owner))
		{
			auto& ComponentFragment = EntityView.GetFragmentData<FCharacterMovementComponentWrapperFragment>();
			ComponentFragment.Component = MovementComp;
			FMassVelocityFragment& VelocityFragment = EntityView.GetFragmentData<FMassVelocityFragment>();
			if (CurrentDirection == EMassTranslationDirection::MassToActor)
			{
				MovementComp->bRunPhysicsWithNoController = true;
				MovementComp->SetMovementMode(MOVE_Walking);
				MovementComp->Velocity = VelocityFragment.Value;
			}
			else
			{
				VelocityFragment.Value = MovementComp->GetLastUpdateVelocity();
			}
		}	
	});
	
	if (EnumHasAnyFlags(SyncDirection,EMassTranslationDirection::ActorToMass) || BuildContext.IsInspectingData())
	{
		BuildContext.AddTranslator<UMassCharacterMovementToMassTranslator>();
	}
	if (EnumHasAnyFlags(SyncDirection,EMassTranslationDirection::MassToActor) || BuildContext.IsInspectingData())
	{
		BuildContext.AddTranslator<UMassCharacterMovementToActorTranslator>();
	}
}
