// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MassSpawner.h"
#include "OrbitSpawner.generated.h"

UCLASS()
class MASSTESTS_API AOrbitSpawner : public AMassSpawner
{
	GENERATED_BODY()

public:
	AOrbitSpawner();

protected:
	virtual void BeginPlay() override;
public:
	virtual void Tick(float DeltaTime) override;
};
