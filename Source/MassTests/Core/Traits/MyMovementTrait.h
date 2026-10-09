// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MassEntityTraitBase.h"
#include "MassTests/Core/Fragments/MyFragments.h"

#include "MyMovementTrait.generated.h"

UCLASS()
class MASSTESTS_API UChaseTrait : public UMassEntityTraitBase
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(EditAnywhere,Category = "Chase Offset",meta=(EditInline))
		FMassChaseMovementParameters ChaseParameters;
	
public:
	virtual void BuildTemplate(FMassEntityTemplateBuildContext& BuildContext, const UWorld& World) const override;
};