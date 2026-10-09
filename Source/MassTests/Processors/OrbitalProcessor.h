// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MassProcessor.h"
#include "OrbitalProcessor.generated.h"

UCLASS()
class MASSTESTS_API UOrbitalProcessor : public UMassProcessor
{
	GENERATED_BODY()
public:
	UOrbitalProcessor();
	
protected:
	virtual void ConfigureQueries(const TSharedRef<FMassEntityManager>& EntityManager) override;
	virtual void Execute(FMassEntityManager& EntityManager, FMassExecutionContext& Context) override;
private:
	FMassEntityQuery EntityQuery;
};
