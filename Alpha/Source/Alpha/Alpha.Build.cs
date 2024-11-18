// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Alpha : ModuleRules
{
	public Alpha(ReadOnlyTargetRules Target) : base(Target)
	{
		PrivateDependencyModuleNames.AddRange(new string[] {  });
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput",
			"MotionWarping", "Niagara", "UMG"
		});
	}
}
