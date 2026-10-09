// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MassEntityElementTypes.h"
#include "MassNavigationFragments.h"
#include "MyFragments.generated.h"
struct FMassGridCellContent;
/*
 * Fragments are like member variables, avoid Monolithics fragments
 */

USTRUCT()
struct FOrbitFragment : public FMassFragment
{
	GENERATED_BODY()
	
	FVector Center = FVector::ZeroVector;
	float Angle = 0.f;
	float Radius = 500.f;
	float AngularSpeed = 1.0f; 
};

USTRUCT()
struct FChaseSharedFragment : public FMassSharedFragment
{
	GENERATED_BODY()
	FVector TargetLocation = FVector::ZeroVector;
};

USTRUCT()
struct FMassChaseMovementParameters : public FMassConstSharedFragment
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "Settings")
	float ChaseVelocity = 500.f;
	UPROPERTY(EditAnywhere, Category = "Settings")
	float ChaseMinDistance = 100.f;
};

USTRUCT()
struct FFriendTag : public FMassTag
{
	GENERATED_BODY()
};

// Signals
namespace MyMass::Signals
{
	static const FName OnGetHit = FName("MyMassOnGetHit");
}
