// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class MassTests : ModuleRules
{
	public MassTests(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput", "MassEntity","MassSpawner","MassCommon" });

		PrivateDependencyModuleNames.AddRange(new string[] { "MassMovement", "MassNavigation", "MassActors" });
	}
}
