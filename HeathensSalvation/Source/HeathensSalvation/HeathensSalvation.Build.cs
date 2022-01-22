// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class HeathensSalvation : ModuleRules
{
	public HeathensSalvation(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "NavigationSystem", "AIModule" });
    }
}
