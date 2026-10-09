// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MassSubsystemBase.h"
#include "MassGridSubsystem.generated.h"

UCLASS()
class MASSTESTS_API UMassGridSubsystem : public UMassSubsystemBase
{
	GENERATED_BODY()
	
public:
	FVector GetTargetLocation() const;
protected:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void OnWorldBeginPlay(UWorld& InWorld) override;
	virtual void Deinitialize() override;
private:
	UPROPERTY()
	APawn* TargetActor=nullptr;
};
