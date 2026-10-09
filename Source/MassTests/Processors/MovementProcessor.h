// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MassProcessor.h"
#include "MovementProcessor.generated.h"

/**
 * Parece ser un Singleton y debe ser un procesador para cada trait aparentemente
 */
UCLASS()
class MASSTESTS_API UChaseProcessor : public UMassProcessor
{
	GENERATED_BODY()
public:
	UChaseProcessor();
	
protected:
	virtual void ConfigureQueries(const TSharedRef<FMassEntityManager>& EntityManager) override;
	virtual void Execute(FMassEntityManager& EntityManager, FMassExecutionContext& Context) override;

	FMassEntityQuery EntityQuery;
};