// Fill out your copyright notice in the Description page of Project Settings.


#include "OrbitTrait.h"

#include "MassEntityTemplateRegistry.h"
#include "MassTests/Core/Fragments/MyFragments.h"

void UOrbitTrait::BuildTemplate(FMassEntityTemplateBuildContext& BuildContext, const UWorld& World) const
{
	BuildContext.AddFragment<FOrbitFragment>();
}
