// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MassSpawnerComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class MASSTESTS_API UMassSpawnerComponent : public UActorComponent
{
	GENERATED_BODY()

	UPROPERTY()
	class AMassSpawner* SpawnerActor;
public:
	// Sets default values for this component's properties
	UMassSpawnerComponent()=default;

protected:
	UPROPERTY(EditAnywhere)
	TSubclassOf<AMassSpawner> Spawner =nullptr;
public:
	virtual void BeginPlay() override;
	UFUNCTION(BlueprintCallable)
	void Execute();
};