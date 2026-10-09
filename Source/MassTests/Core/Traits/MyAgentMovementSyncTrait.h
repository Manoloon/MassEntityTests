// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MassActors/Public/MassAgentTraits.h"
#include "MyAgentMovementSyncTrait.generated.h"

/**
 * 
 */
namespace FMassAgentTraitsHelper 
{
	template<typename T>
	T* AsComponent(UObject& Owner)
	{
		T* Component = nullptr;
		if (AActor* AsActor = Cast<AActor>(&Owner))
		{
			Component = AsActor->FindComponentByClass<T>();
		}
		else
		{
			Component = Cast<T>(&Owner);
		}

		UE_CVLOG_UELOG(Component == nullptr, &Owner, LogMass, Error, TEXT("Trying to extract %s from %s failed")
			, *T::StaticClass()->GetName(), *Owner.GetName());

		return Component;
	}
}

UCLASS(BlueprintType, EditInlineNew, CollapseCategories, meta = (DisplayName = "My Agent Movement Sync"))
class MASSTESTS_API UMyAgentMovementSyncTrait : public UMassAgentSyncTrait
{
	GENERATED_BODY()
protected:
	virtual void BuildTemplate(FMassEntityTemplateBuildContext& BuildContext, const UWorld& World) const override;
};
